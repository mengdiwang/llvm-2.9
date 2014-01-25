#ifndef LLVM_ANALYSIS_CEPASS_H
#define LLVM_ANALYSIS_CEPASS_H

#include <vector>
#include "llvm/Pass.h"
#include "llvm/BasicBlock.h"
#include "llvm/Function.h"
#include "llvm/Analysis/CallGraph.h"

#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

#include <boost/config.hpp>
#include <boost/utility.hpp>
#include <boost/graph/adjacency_list.hpp>
//#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/depth_first_search.hpp>

using namespace boost;

namespace llvm {
    
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
    
    typedef std::map<std::string, std::vector<unsigned> > defectList;
    typedef adjacency_list<setS, vecS, bidirectionalS, no_property,
    property<edge_weight_t, int> > Graph;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    typedef graph_traits<Graph>::edge_descriptor Edge;
    typedef color_traits<default_color_type> Color;
    typedef std::vector<default_color_type> ColorVec;
    
	ModulePass *createCEPass(std::vector<std::vector<TCeItem> > *_bbpaths, std::string _filename);
	
    
    typedef std::vector<TCeItem> TceList;
    typedef std::pair<std::string, int> TtargetPair;
    typedef std::map<TtargetPair, TceList> TceListMap;
    

    class CEPass:public ModulePass
    {
    public:
        CEPass():ModulePass(ID),bbpaths(NULL){}
        
        virtual void getAnalysisUsage(AnalysisUsage &AU) const { //important
            AU.addRequired<CallGraph>();
            AU.setPreservesCFG();
            AU.setPreservesAll();
        }
        
        virtual bool runOnModule(Module &_M);

        static char ID;
        
//        std::vector<std::vector<BasicBlock*> > *bbpaths;
        std::vector<std::vector<TCeItem> > *bbpaths;
        
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
	


}

#endif
