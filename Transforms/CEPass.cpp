//
//  CriticalEdge.cpp
//  EditLLvmPass
//
//  Created by Mengdi Wang on 14-1-14.
//  Copyright (c) 2014年 wmd. All rights reserved.
//

//#define __STDC_CONSTANT_MACROS
//#define __STDC_LIMIT_MACROS


#include "llvm/ADT/ArrayRef.h"
#include "llvm/BasicBlock.h"
#include "llvm/Constants.h"
#include "llvm/Function.h"
#include "llvm/GlobalVariable.h"
#include "llvm/Pass.h"
#include "llvm/Type.h"
#include "llvm/Instruction.h"
#include "llvm/Instructions.h"
#include "llvm/Module.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Analysis/DebugInfo.h"
#include "llvm/ADT/PostOrderIterator.h"
#include "llvm/Support/CFG.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Support/InstIterator.h"
#include <vector>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <queue>

using namespace llvm;

#include <boost/config.hpp>
#include <boost/utility.hpp>
#include <boost/graph/adjacency_list.hpp>
//#include <boost/graph/graphviz.hpp> //graphviz not compatitable with dijkstra
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

#define BLOCKSHORTEST 

namespace
{
	
    typedef std::map<std::string, std::vector<unsigned> > defectList;
    typedef adjacency_list<setS, vecS, bidirectionalS, no_property,
    property<edge_weight_t, int> > Graph;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef graph_traits<Graph>::edge_descriptor Edge;
    typedef color_traits<default_color_type> Color;
    typedef std::vector<default_color_type> ColorVec;
    
    struct TCeItem
    {
        TCeItem(std::string _funname, int _funId, Instruction *_criStmtStr, int _criStmtBranch, int _criLine):funName(_funname),funId(_funId),criStmtStr(_criStmtStr),criStmtBranch(_criStmtBranch),criLine(_criLine)
        {
        }
        
        std::string funName;
        int funId;
        //	int criStmtId;
        Instruction *criStmtStr;
        int criStmtBranch; // 0 is true choice , 1 is false choice
        int criLine;
    };//end of struct TCeItem
    
    bool CompareByLine(const TCeItem &a, const TCeItem &b)
    {
        return a.criLine < b.criLine;
    }
    
    typedef std::vector<TCeItem> TceList;
    typedef std::pair<std::string, int> TtargetPair;
    typedef std::map<TtargetPair, TceList> TceListMap;
    
    static cl::opt<std::string>
    DumpFile("ce-dump-file", cl::init("ce-block-dump.out"), cl::Optional,
             cl::value_desc("filename"), cl::desc("Block dump file from -cefinder"));
    
    class CEPass:public ModulePass
    {
    public:
        CEPass():ModulePass(ID){}
        
        virtual void getAnalysisUsage(AnalysisUsage &AU) const { //important
            AU.addRequired<CallGraph>();
            AU.setPreservesCFG();
            AU.setPreservesAll();
        }
        
        virtual bool runOnModule(Module &_M);

        static char ID;
        
        std::vector<std::vector<BasicBlock*> > *bbpaths;
        
        std::string defectFile;
        
        std::vector<TCeItem> *CeList;
        
        Module *M;
        
    private:
        typedef std::map<std::string, std::vector<unsigned> > defectList;
        typedef std::map<TtargetPair, TceList> TceListMap;
        
        defectList dl;
        TceListMap CEMap;
        
        void getDefectList(std::string docname, defectList *res);
        
        Function *getFunction(std::string srcFile, unsigned srcLine, BasicBlock **BB);
        Function *getFunction(Vertex v);
        BasicBlock *getBB(std::string srcFile, unsigned srcLine);
        BasicBlock *getBB(Vertex v);
        bool findLineInFunction(Function *F, BasicBlock **BB, std::string srcFile, unsigned srcLine);
        bool findLineInBB(BasicBlock *BB, std::string srcFile, unsigned srcLine);
        void findCEofSingleBB(BasicBlock *BB, TceList &ceList);
        void findCEofBBPathList(std::vector<BasicBlock *> &blist, BasicBlock *tBB, TceList &ceList);
        
        void OutputMap(raw_fd_ostream &file, TceListMap &map);
        std::pair<unsigned, StringRef> getInstInfo(Instruction *I);
        int getBlockTerminLineNo(BasicBlock *BB);
        void PrintDBG(Function *F);
        
        //--------------Function call map ---------------------
    private:
        Graph funcG, bbG;
        std::map<Function*, Vertex> funcMap;   // Map functions to vertices
        std::map<BasicBlock*, Vertex> bbMap;
        std::map<std::pair<Function*, Function*>, std::vector<BasicBlock*> > CallBlockMap; // caller bb map<pair<caller, callee> ,BasicBlock>
        std::set<BasicBlock *> isCallsite;
        
        void findSinglePath(std::vector<Vertex> *path, Vertex root, Vertex target, Graph &graph);

        void buildGraph(CallGraph *CG);
        void addBBEdges(BasicBlock *BB);
        std::string getName(Vertex v);
        std::string getBBName(Vertex v);
        void PrintDotGraph();
        
    private:
        struct my_func_label_writer
        {
            CEPass *CEP;
            my_func_label_writer(CEPass *_CEP):CEP(_CEP){}
            template<class VertexOrEdge>
            void operator()(std::ostream &out, const VertexOrEdge &v) const
            {
                out << "[label=\"" << CEP->getName(v) << "\"]";
            }
        };
        
        struct my_bb_label_writer
        {
            CEPass *CEP;
            my_bb_label_writer(CEPass *_CEP):CEP(_CEP){}
            template<class VertexOrEdge>
            void operator()(std::ostream &out, const VertexOrEdge &v) const
            {
                out << "[label=\"" << CEP->getBBName(v) << "\"]";
            }
        };
        
    };//end of Pass CEPass
    
    char CEPass::ID = 0;
    
    static RegisterPass<CEPass> X("cefinder", "Critical Edge finder psss", false, false);
    
    void CEPass::PrintDBG(Function *F)
    {
        //debug
        errs() << "---------------\nTest pred and suc: ";
        errs() << F->getName() << '\n';
        for (Function::iterator itr = F->begin();itr != F->end();++itr) {
            BasicBlock &bb = *itr;
            errs() << "Basic block :" << bb.getName () << "@" << getBlockTerminLineNo(&bb) << "\n";
            errs() << "successor : {";
            for (succ_iterator ssitr = succ_begin(&bb);ssitr != succ_end(&bb);++ssitr) {
                BasicBlock *ss = *ssitr;
                errs() << ss->getName() << "@" << getBlockTerminLineNo(ss) <<", ";
            }
            errs() << "}\n";
            errs() << "predecessors : {";
            for (pred_iterator ssitr = pred_begin(&bb);ssitr != pred_end(&bb);++ssitr) {
                BasicBlock *ss = *ssitr;
                errs() << ss->getName() << "@" << getBlockTerminLineNo(ss) <<", ";
            }
            errs() << "}\n";
            for (BasicBlock::iterator iitr = bb.begin();iitr != bb.end();++iitr) {
                Instruction &inst = *iitr;
                errs() << inst << '\n';
            }
        }
        errs() << "--------------\n";
        
        //~
    }
    
    //\brief main entry of the Module pass
    bool CEPass::runOnModule(Module &_M)
    {
        defectFile = "defectFile.txt";
        errs() << "CEFinder started\n";
        std::string ErrorInfo;
        raw_fd_ostream file(DumpFile.c_str(), ErrorInfo);
        if(!ErrorInfo.empty())
        {
            errs() << "Error opening file for writing\n";
            return false;
        }
        
        M = &_M;

        CallGraph *CG = &getAnalysis<CallGraph>();
        CallGraphNode *root = CG->getRoot();
        if(root == NULL) return false;
        Function *rootF = root->getFunction();
        if(rootF == NULL) return false;
        BasicBlock *rootBB = &rootF->getEntryBlock();
        if(rootBB == NULL) return false;
        //CG->print(errs(), M);
        
        getDefectList(defectFile, &dl);
        if(dl.size() == 0) return false;
        
        buildGraph(CG);
        
        
        TceList ceList;
        std::vector<Vertex> path;
        std::vector<BasicBlock *> bbpath;
        std::vector<Function *> funcpath;
        std::vector<unsigned> lines;
        std::vector<BasicBlock *> callsiteblocks;

        for(defectList::iterator dit=dl.begin(); dit!=dl.end(); dit++)
        {
            std::string file = dit->first;
            lines = dit->second;
            BasicBlock *tBB = NULL;
            ceList.clear();
            Function *F = NULL;
            unsigned line = 0;
            for(std::vector<unsigned>::iterator lit=lines.begin(); lit!=lines.end(); lit++)
            {
                errs() << "Looking for '" << file << "' (" << *lit << ")\n";
                if((F = getFunction(file, *lit, &tBB)) != NULL)
                {
                    line = *lit;
                    break;
                }
            }
            
            if(F==NULL || tBB==NULL || line==0)
                continue;
#ifdef BLOCKSHORTEST
            DEBUG(errs() << "inter-Blocks Dijkstra\n");
            //interprocedural
            Vertex rootv = bbMap[rootBB];
            Vertex targetv = bbMap[tBB];
            path.clear();
            bbpath.clear();
            
            findSinglePath(&path, rootv, targetv, bbG);
            
            //get all the blocks in the shortest path
            BasicBlock *tmpb = NULL;
            for(std::vector<Vertex>::iterator it=path.begin(); it!=path.end(); it++)
            {
                tmpb = getBB(*it);
                if(tmpb != NULL) bbpath.push_back(tmpb);
                DEBUG(errs() << "output path:");
                DEBUG(errs() << "\tblocks terminatal line at " << getBlockTerminLineNo(tmpb) << "\n");
            }
            //? 最短路上的branch block是否就是关键边？
            findCEofBBPathList(bbpath, tBB, ceList);
            CEMap.insert(std::make_pair(std::make_pair(file, line), ceList));
            
            //~
            //intraprocedural
            
//            findCEofSingleBB(tBB, ceList);
//            CEMap.insert(std::make_pair(std::make_pair(file, line), ceList));
//            CallGraphNode *fcgn = (*CG)[F];
            //~
#else
            DEBUG(errs() << "inter-Function Dijkstra\n");
            Vertex rootfv = funcMap[rootF];
            Vertex targetfv = funcMap[F];
            path.clear();
            bbpath.clear();
            funcpath.clear();
            
            findSinglePath(&path, rootfv, targetfv, funcG);
            
            callsiteblocks.clear();
            Function *tmpf = NULL;
            Function *tmpfn = NULL;
            BasicBlock *targetb = NULL;
            TceList tmpcelist;
            for(std::vector<Vertex>::iterator it=path.begin(); it!=path.end(); ++it)
            {
                tmpcelist.clear();
                tmpf = getFunction(*it);
                if(tmpf != NULL) funcpath.push_back(tmpf);
                if((it+1)!=path.end())
                {
                    tmpfn = getFunction(*(it+1));
                    callsiteblocks = CallBlockMap[std::make_pair(tmpf, tmpfn)];
                    targetb = callsiteblocks[0]; //TODO random the callsite
                    findCEofSingleBB(targetb, tmpcelist);
                }
                else
                {
                    findCEofSingleBB(tBB, tmpcelist);
                }
                ceList.insert(ceList.end(), tmpcelist.begin(), tmpcelist.end());
            }
            CEMap.insert(std::make_pair(std::make_pair(file, line), ceList));
#endif
        }
        
        OutputMap(file, CEMap);
        errs() << "CE Finder finished\n";
        
        return false;
    }
    
    std::string CEPass::getName(Vertex v)
    {
        std::string res = "<null>";
        
        for(std::map<Function *, Vertex>::iterator it=funcMap.begin(); it!=funcMap.end(); ++it)
        {
            if(v == it->second)
            {
                Function *F = it->first;
                if(F!=NULL)
                    res = it->first->getNameStr();
            }
        }
        return res;
    }
    
    std::string CEPass::getBBName(Vertex v)
    {
        std::string res = "<null>";
        std::stringstream ss;
        for(std::map<BasicBlock *, Vertex>::iterator it=bbMap.begin(); it!=bbMap.end(); ++it)
        {
            if(v == it->second)
            {
                BasicBlock *BB = it->first;
                if(BB!=NULL)
                {
                    ss << getBlockTerminLineNo(BB);
                    res = ss.str();
                }
            }
        }
        return res;
    }

    BasicBlock *CEPass::getBB(Vertex v)
    {
        for(std::map<BasicBlock *, Vertex>::iterator it=bbMap.begin(); it!=bbMap.end(); ++it)
        {
            if(v == it->second)
                return it->first;
        }
        return NULL;
    }
    
    Function *CEPass::getFunction(Vertex v)
    {
        for(std::map<Function *, Vertex>::iterator it=funcMap.begin(); it!=funcMap.end(); ++it)
        {
            if(v == it->second)
                return it->first;
        }
        return NULL;
    }
    
    // \brief get the line number and file of an instruction
    std::pair<unsigned, StringRef> CEPass::getInstInfo(Instruction *I)
    {

        if (MDNode *N = I->getMetadata("dbg"))
        {                                           // Here I is an LLVM instruction
            DILocation Loc(N);                      // DILocation is in DebugInfo.h
            unsigned bbline = Loc.getLineNumber();
            StringRef bbfile = Loc.getFilename();
            //errs() << "[getInstInfo]" << bbline << " " << bbfile << "\n";
            return std::make_pair(bbline, bbfile);
        }
        return std::make_pair(0, "");
    }
    
    void CEPass::OutputMap(raw_fd_ostream &file, TceListMap &map)
    {
        TceList celist;
        for(TceListMap::iterator mit=map.begin(); mit!=map.end(); ++mit)
        {
            std::string filename = mit->first.first;
            int lineno = mit->first.second;
            celist = mit->second;
            file << "[";
            file.write_escaped(StringRef(filename));
            file << "](" <<lineno <<"):\n";
            
            for(TceList::iterator tit=celist.begin(); tit!=celist.end(); ++tit)
            {
                file <<tit->funName << " " << tit->funId << " " << tit->criStmtStr << " " << tit->criStmtBranch << " " << tit->criLine << "\n";
            }
            
        }
    }
    
    int CEPass::getBlockTerminLineNo(BasicBlock *BB)
    {
        if (BB == NULL)
            return 0;
        
        Instruction *ins = dyn_cast<Instruction>(BB->getTerminator());
        if(ins == NULL)
            return 0;
        
        return getInstInfo(ins).first;
    }
    
    bool CEPass::findLineInBB(BasicBlock *BB, std::string srcFile, unsigned srcLine)
    {
        for(BasicBlock::iterator it=BB->begin(); it!=BB->end(); ++it)
        {
            std::pair<unsigned, StringRef> p = getInstInfo(it);
            
            if((p.first==srcLine) && (p.second.str()==srcFile))
            {
                DEBUG(errs() << "find the target\n");
                return true;
            }
        }
        return false;
    }
    
    bool CEPass::findLineInFunction(Function *F, BasicBlock **BB, std::string srcFile, unsigned srcLine)
    {
        for(Function::iterator bbit = F->begin(); bbit != F->end(); ++bbit)
        {
            *BB = bbit;
            if(findLineInBB(bbit, srcFile, srcLine))
            {
                return true;
            }
        }
        return false;
    }
    
    Function *CEPass::getFunction(std::string srcFile, unsigned srcLine, BasicBlock **BB )
    {
        for(Module::iterator fit=M->begin(); fit!=M->end(); ++fit)
        {
            if(findLineInFunction(fit, BB, srcFile, srcLine))
                return fit;
        }
        return NULL;
    }
    
    //read txt with fomat: Filename LineNumber
    void CEPass::getDefectList(std::string docname, defectList *res)
    {
        DEBUG(errs() << "Open defect file " << docname << "\n");
        std::ifstream fin(docname);
        std::string fname="";
        std::vector<unsigned> lineList;
        while(!fin.eof())
        {
            std::string filename;
            unsigned lineno;
            
            fin >> filename >> lineno;
            
            if(fname == "")
            {
                fname = filename;
            }
            
            if(fname != filename)
            {
                res->insert(std::make_pair(filename, lineList));
                lineList.clear();
                fname = filename;
            }
            
            lineList.push_back(lineno);
        }
        //tail add
        if(lineList.size()>0 && fname != "")
        {
            res->insert(std::make_pair(fname, lineList));
            lineList.clear();
        }
        
        fin.close();
    }
    
    void CEPass::findCEofBBPathList(std::vector<BasicBlock *> &blist, BasicBlock *tBB, TceList &ceList)
    {
        TceList list;
        std::set<Function *> fset;
        for(std::vector<BasicBlock *>::reverse_iterator vit=blist.rbegin(); vit!=blist.rend(); ++vit)//in the reverse order
        {
            /*
            BasicBlock *frontB = *vit;
            BranchInst *brInst = dyn_cast<BranchInst>(frontB->getTerminator());
            
            if(brInst == NULL)
                continue;
            
            if(brInst->isConditional())
            {
                BasicBlock *trueBB = brInst->getSuccessor(0);//true destionation
                BasicBlock *falseBB = brInst->getSuccessor(1);//false destination

                for(std::vector<BasicBlock *>::iterator vvit=blist.begin(); vvit!=blist.end(); ++vvit)
                {
                    if(*vvit == trueBB)
                    {
                        BasicBlock *tmpb = *vvit;
                        std::string funcName = tmpb->getParent()->getName().str();
                        int funcId = tmpb->getParent()->getIntrinsicID();
//                        std::string cristmtid = brInst->getName().str();
                        int cristmtLine = getInstInfo(brInst).first;
                        
                        TCeItem ceItem = TCeItem(funcName, funcId, brInst, 0, cristmtLine);//true choice
                        ceList.push_back(ceItem);//push into the Critical Edge List
                    }
                    else if(*vvit == falseBB)
                    {
                        BasicBlock *tmpb = *vvit;
                        std::string funcName = tmpb->getParent()->getName().str();
                        int funcId = tmpb->getParent()->getIntrinsicID();
//                        std::string cristmtid = brInst->getName().str();
                        int cristmtLine = getInstInfo(brInst).first;
                        
                        TCeItem ceItem = TCeItem(funcName, funcId, brInst, 1, cristmtLine);//false choice
                        ceList.push_back(ceItem);//push into the Critical Edge List
                    }
                }
            }
             */
            BasicBlock *frontB = *vit;
            
            if(*vit == tBB || isCallsite.count(frontB) > 0)
            {
                DEBUG(errs() << "search in callsite:" << getBlockTerminLineNo(frontB) << "\n");
                list.clear();
                if(!fset.count(frontB->getParent()))
                {
                    findCEofSingleBB(frontB, list);
                    ceList.insert(ceList.begin(), list.begin(), list.end());
                    
                    fset.insert(frontB->getParent());
                }
            }
        }
    }
    
    //find the CE list in a function with given target BasicBlock
    void CEPass::findCEofSingleBB(BasicBlock *targetB, TceList &ceList)
    {
        if(targetB == NULL)
            return;
        
        Function *F = targetB->getParent();
        DEBUG(errs() << "start finding CE in " << F->getName() << "\n");
        
        std::queue<BasicBlock *> bbque; //BFS queue
        std::set<BasicBlock *> bbset;  //a set to note down visited BasicBlocks
        bbset.insert(targetB);
        bbque.push(targetB);
        BasicBlock *frontB = NULL;
        int count = 0;
        //inverse BFS to get all successor chain of the target
        while(!bbque.empty())
        {
            frontB = bbque.front();
            bbque.pop();
            
            for(pred_iterator pi = pred_begin(frontB); pi != pred_end(frontB); ++pi)//get Predecessor list of basic blocks
            {
                BasicBlock *predB = *pi;
                DEBUG(errs() << "pred line:" << getBlockTerminLineNo(predB) << "\n");
                if(!bbset.count(predB))
                {
                    bbset.insert(predB);
                    bbque.push(predB);
                    count ++;
                }
                
            }
        }
		DEBUG(errs() << "Reverse list finished with size:" << count << "\n");
		
        if(frontB == NULL)
            return;
        
        //BFS from the head to gether the critical edges
        std::set<BasicBlock *> seqset;
        
        bbque.push(frontB);
        seqset.insert(/*getBlockTerminLineNo*/(frontB));
        while(!bbque.empty())
        {
            frontB = bbque.front();
			bbque.pop();
            DEBUG(errs() << "frontBname:" << frontB->getName() << " lineno:"<< getBlockTerminLineNo(frontB) << "\n");
            if(/*getBlockTerminLineNo*/(frontB) == /*getBlockTerminLineNo*/(targetB))//found the target, end the traverse
                continue;
            
            BranchInst *brInst = dyn_cast<BranchInst>(frontB->getTerminator());
            if(brInst == NULL)
                continue;
            
            if(brInst->isConditional())
            {
                //DEBUG(errs()<<"isbranch\n");
                
                BasicBlock *trueBB = brInst->getSuccessor(0);//true destionation
                BasicBlock *falseBB = brInst->getSuccessor(1);//false destination

                DEBUG(errs()<< "brInst:" <<brInst <<" " <<brInst->getNameStr() << " line:" << getInstInfo(brInst).first << "\n");
                
                if(bbset.count(trueBB) && !bbset.count(falseBB))//true choice is CE
                {
                    std::string funcName = trueBB->getParent()->getName().str();
                    int funcId = trueBB->getParent()->getIntrinsicID();
//                    std::string cristmtid = brInst->getName().str();
                    int cristmtLine = getInstInfo(brInst).first;
                    
                    TCeItem ceItem = TCeItem(funcName, funcId, brInst, 0, cristmtLine);
                    ceList.push_back(ceItem);//push into the Critical Edge List
                    
                    if(!seqset.count(/*getBlockTerminLineNo*/(trueBB)))
                    {
                        bbque.push(trueBB);
                        seqset.insert(/*getBlockTerminLineNo*/(trueBB));
                    }
                }
                else if(!bbset.count(trueBB) && bbset.count(falseBB))//false choice is CE
                {
                    std::string funcName = trueBB->getParent()->getName().str();
                    int funcId = trueBB->getParent()->getIntrinsicID();
//                    std::string cristmtid = brInst->getName().str();
                    int cristmtLine = getInstInfo(brInst).first;
                    
                    TCeItem ceItem = TCeItem(funcName, funcId, brInst, 1, cristmtLine);
                    ceList.push_back(ceItem);
                    
                    if(!seqset.count(/*getBlockTerminLineNo*/(falseBB)))
                    {
                        bbque.push(falseBB);
                        seqset.insert(/*getBlockTerminLineNo*/(falseBB));
                    }
                }
                else if(bbset.count(trueBB) && bbset.count(falseBB))//both true and false choice is visited
                {
                    //just input to the search queue
                    if(!seqset.count(/*getBlockTerminLineNo*/(trueBB)))
                    {
                        bbque.push(trueBB);
                        seqset.insert(/*getBlockTerminLineNo*/(trueBB));
                    }

                    if(!seqset.count(/*getBlockTerminLineNo*/(falseBB)))
                    {
                        bbque.push(falseBB);
                        seqset.insert(/*getBlockTerminLineNo*/(falseBB));
                    }
                    
                }
            }
        }
        
        std::sort(ceList.begin(), ceList.end(), CompareByLine);
    }//end of Func FindCEofSingleBB
    
    void CEPass::addBBEdges(BasicBlock *BB)
    {
        graph_traits<Graph>::edge_descriptor e;
        bool inserted;
        property_map<Graph, edge_weight_t>::type bbWeightmap = get(edge_weight, bbG);
        
        for(succ_iterator si = succ_begin(BB); si!=succ_end(BB); ++si)
        {
            boost::tie(e, inserted) = add_edge(bbMap[BB], bbMap[*si], bbG);
            if(inserted)
                addBBEdges(*si);
            bbWeightmap[e] = 1;
        }
    }
    
    void CEPass::buildGraph(CallGraph *CG)
    {
        DEBUG(errs() << "Building Vertices...\n");
        for(Module::iterator fit=M->begin(); fit!=M->end(); ++fit)
        {
            Function *F = fit;
            funcMap[F] = add_vertex(funcG);
            for(Function::iterator bbit = F->begin(), bb_ie=F->end(); bbit != bb_ie; ++bbit)
            {
                BasicBlock *BB = bbit;
                bbMap[BB] = add_vertex(bbG);
            }
        }
        DEBUG(errs() << "FuncMap:" << num_vertices(funcG) << " - bbMap:" << num_vertices(bbG) << "\n");
        
        property_map<Graph, edge_weight_t>::type funcWeightmap = get(edge_weight, funcG);
        property_map<Graph, edge_weight_t>::type bbWeightmap = get(edge_weight, bbG);
        
        for(Module::iterator fit = M->begin(); fit!=M->end(); ++fit)
        {
            Function *F = fit;
            DEBUG(errs() << "Enter caller:" << F->getNameStr() << "\n");
//            if(F->isDeclaration()) //wmd obmit the declaration part
//                continue;
            
            CallGraphNode *cgn = CG->getOrInsertFunction(F);
//            CallGraphNode *cgn = (*CG)[F];
            if(cgn == NULL)
                continue;
        
            graph_traits<Graph>::edge_descriptor e;bool inserted;
            
            if(!F->empty())
            {
                BasicBlock *BB = &F->getEntryBlock();
                addBBEdges(BB);
            }
        
            std::vector<BasicBlock> callerblocks;
            
            for(CallGraphNode::iterator cit=cgn->begin(); cit!=cgn->end(); ++cit)
            {
                CallGraphNode *tcgn = cit->second;
                Function *tF = tcgn->getFunction();
                //tcgn->print(errs());
                if(tF == NULL)
                    continue;
            
                boost::tie(e, inserted) = add_edge(funcMap[F], funcMap[tF], funcG);
                funcWeightmap[e] = 1;
                
                if(tF->empty())
                    continue;
                DEBUG(errs() << "Enter " << tF->getNameStr() << "\n");
                Instruction *myI = dyn_cast<Instruction>(cit->first);
                DEBUG(errs() << "Call Instruction at line " << getInstInfo(myI).first << "\n");
                BasicBlock *callerBB = myI->getParent();//caller block
                
                                //unused
//                for(inst_iterator I=inst_begin(F); I!=inst_end(F); I++)
//                {
//                    Instruction *Inst = &*I;
//                    errs() << "Instruction at line " << getInstInfo(Inst).first << "\n";
//                    if(I->getOpcode()==Instruction::Call || I->getOpcode()==Instruction::Invoke )
//                    {
//                        errs() << "Opcode Invoke Instruction at line " << getInstInfo(Inst).first << "\n";
//                        CallSite mycs(Inst);
//                        BasicBlock *myBB = I->getParent();
//                        
//                        
//                    }
//                }
                //~
                
                Function::iterator cBBit = tF->getEntryBlock();
                BasicBlock *calleeBB = cBBit;
                if(calleeBB == NULL)
                    continue;
                boost::tie(e, inserted) = add_edge(bbMap[callerBB], bbMap[calleeBB], bbG);
                bbWeightmap[e] = 1;
                
                CallBlockMap[std::make_pair(F, tF)].push_back(callerBB);//insert in to caller bb map
                if(!isCallsite.count(callerBB))
                    isCallsite.insert(callerBB);

            }
        }
        DEBUG(errs() << "FuncMap:" << num_edges(funcG) << " - bbMap:" << num_edges(bbG) << "\n");
        PrintDotGraph();
    }
    
    //find the path on the built graph
    void CEPass::findSinglePath(std::vector<Vertex> *path, Vertex root, Vertex target, Graph &graph)
    {
        std::vector<Vertex> p(num_vertices(graph));
        std::vector<int> d(num_vertices(graph));
        property_map<Graph, vertex_index_t>::type indexmap = get(vertex_index, graph);
        property_map<Graph, edge_weight_t>::type bbWeightmap = get(edge_weight, graph);
        
        dijkstra_shortest_paths(graph, root, &p[0], &d[0], bbWeightmap, indexmap,
                                std::less<int>(), closed_plus<int>(),
                                (std::numeric_limits<int>::max)(), 0,
                                default_dijkstra_visitor());

        //  std::cout << "shortest path:" << std::endl;
        while(p[target] != target)
        {
            path->insert(path->begin(), target);
            target = p[target];
        }
        // Put the root in the list aswell since the loop above misses that one
        if(!path->empty())
            path->insert(path->begin(), root);
        
    }
}//end of anonymous namespace


#include <boost/graph/graphviz.hpp> //graphviz not compatitable with dijkstra
namespace
{
void CEPass::PrintDotGraph()
{
    std::ofstream funcs_file("funcs.dot");
    boost::write_graphviz(funcs_file, funcG, my_func_label_writer(this));
        
    std::ofstream bbs_file("blocks.dot");
    boost::write_graphviz(bbs_file, bbG, my_bb_label_writer(this));
}
}
    
    



