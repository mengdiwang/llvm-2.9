//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Target Instruction Descriptors
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

namespace llvm {

static const unsigned ImplicitList1[] = { XCore::SP, 0 };
static const unsigned ImplicitList2[] = { XCore::R0, XCore::R1, XCore::R2, XCore::R3, XCore::R11, XCore::LR, 0 };
static const unsigned ImplicitList3[] = { XCore::R11, 0 };

static const TargetOperandInfo OperandInfo2[] = { { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo3[] = { { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo4[] = { { -1, 0, 0 }, { -1, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo5[] = { { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo6[] = { { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo7[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo8[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo9[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo10[] = { { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo11[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo12[] = { { XCore::GRRegsRegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo13[] = { { -1, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo14[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, };
static const TargetOperandInfo OperandInfo15[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo16[] = { { XCore::GRRegsRegClassID, 0, 0 }, { -1, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo17[] = { { XCore::RRegsRegClassID, 0, 0 }, { -1, 0, 0 }, };
static const TargetOperandInfo OperandInfo18[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo19[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, ((1 << 16) | (1 << TOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo20[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, 0 }, };
static const TargetOperandInfo OperandInfo21[] = { { XCore::GRRegsRegClassID, 0, 0 }, { XCore::GRRegsRegClassID, 0, ((0 << 16) | (1 << TOI::TIED_TO)) }, { -1, 0, 0 }, };

static const TargetInstrDesc XCoreInsts[] = {
  { 0,	0,	0,	0,	"PHI", 0|(1<<TID::Variadic)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #0 = PHI
  { 1,	0,	0,	0,	"INLINEASM", 0|(1<<TID::Variadic), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #1 = INLINEASM
  { 2,	1,	0,	0,	"PROLOG_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #2 = PROLOG_LABEL
  { 3,	1,	0,	0,	"EH_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #3 = EH_LABEL
  { 4,	1,	0,	0,	"GC_LABEL", 0|(1<<TID::NotDuplicable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #4 = GC_LABEL
  { 5,	0,	0,	0,	"KILL", 0|(1<<TID::Variadic), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #5 = KILL
  { 6,	3,	1,	0,	"EXTRACT_SUBREG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo3 },  // Inst #6 = EXTRACT_SUBREG
  { 7,	4,	1,	0,	"INSERT_SUBREG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo4 },  // Inst #7 = INSERT_SUBREG
  { 8,	1,	1,	0,	"IMPLICIT_DEF", 0|(1<<TID::Rematerializable)|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #8 = IMPLICIT_DEF
  { 9,	4,	1,	0,	"SUBREG_TO_REG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo5 },  // Inst #9 = SUBREG_TO_REG
  { 10,	3,	1,	0,	"COPY_TO_REGCLASS", 0|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo3 },  // Inst #10 = COPY_TO_REGCLASS
  { 11,	0,	0,	0,	"DBG_VALUE", 0|(1<<TID::Variadic), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #11 = DBG_VALUE
  { 12,	1,	1,	0,	"REG_SEQUENCE", 0|(1<<TID::Variadic)|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #12 = REG_SEQUENCE
  { 13,	2,	1,	0,	"COPY", 0|(1<<TID::CheapAsAMove), 0x0ULL, NULL, NULL, NULL, OperandInfo6 },  // Inst #13 = COPY
  { 14,	3,	1,	0,	"ADD_2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #14 = ADD_2rus
  { 15,	3,	1,	0,	"ADD_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #15 = ADD_3r
  { 16,	1,	0,	0,	"ADJCALLSTACKDOWN", 0, 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #16 = ADJCALLSTACKDOWN
  { 17,	2,	0,	0,	"ADJCALLSTACKUP", 0, 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo6 },  // Inst #17 = ADJCALLSTACKUP
  { 18,	3,	1,	0,	"ANDNOT_2r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo9 },  // Inst #18 = ANDNOT_2r
  { 19,	3,	1,	0,	"AND_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #19 = AND_3r
  { 20,	3,	1,	0,	"ASHR_l2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #20 = ASHR_l2rus
  { 21,	3,	1,	0,	"ASHR_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #21 = ASHR_l3r
  { 22,	1,	0,	0,	"BAU_1r", 0|(1<<TID::Branch)|(1<<TID::IndirectBranch)|(1<<TID::Barrier)|(1<<TID::Terminator), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #22 = BAU_1r
  { 23,	2,	1,	0,	"BITREV_l2r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #23 = BITREV_l2r
  { 24,	1,	0,	0,	"BLA_1r", 0|(1<<TID::Call)|(1<<TID::Variadic), 0x0ULL, NULL, ImplicitList2, NULL, OperandInfo10 },  // Inst #24 = BLA_1r
  { 25,	1,	0,	0,	"BL_lu10", 0|(1<<TID::Call)|(1<<TID::Variadic), 0x0ULL, NULL, ImplicitList2, NULL, OperandInfo2 },  // Inst #25 = BL_lu10
  { 26,	1,	0,	0,	"BL_u10", 0|(1<<TID::Call)|(1<<TID::Variadic), 0x0ULL, NULL, ImplicitList2, NULL, OperandInfo2 },  // Inst #26 = BL_u10
  { 27,	2,	0,	0,	"BRBF_lru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #27 = BRBF_lru6
  { 28,	2,	0,	0,	"BRBF_ru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #28 = BRBF_ru6
  { 29,	2,	0,	0,	"BRBT_lru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #29 = BRBT_lru6
  { 30,	2,	0,	0,	"BRBT_ru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #30 = BRBT_ru6
  { 31,	1,	0,	0,	"BRBU_lu6", 0|(1<<TID::Branch)|(1<<TID::Barrier)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #31 = BRBU_lu6
  { 32,	1,	0,	0,	"BRBU_u6", 0|(1<<TID::Branch)|(1<<TID::Barrier)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #32 = BRBU_u6
  { 33,	2,	0,	0,	"BRFF_lru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #33 = BRFF_lru6
  { 34,	2,	0,	0,	"BRFF_ru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #34 = BRFF_ru6
  { 35,	2,	0,	0,	"BRFT_lru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #35 = BRFT_lru6
  { 36,	2,	0,	0,	"BRFT_ru6", 0|(1<<TID::Branch)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #36 = BRFT_ru6
  { 37,	1,	0,	0,	"BRFU_lu6", 0|(1<<TID::Branch)|(1<<TID::Barrier)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #37 = BRFU_lu6
  { 38,	1,	0,	0,	"BRFU_u6", 0|(1<<TID::Branch)|(1<<TID::Barrier)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo2 },  // Inst #38 = BRFU_u6
  { 39,	2,	0,	0,	"BR_JT", 0|(1<<TID::Branch)|(1<<TID::IndirectBranch)|(1<<TID::Barrier)|(1<<TID::Terminator), 0x0ULL, NULL, NULL, NULL, OperandInfo13 },  // Inst #39 = BR_JT
  { 40,	2,	0,	0,	"BR_JT32", 0|(1<<TID::Branch)|(1<<TID::IndirectBranch)|(1<<TID::Barrier)|(1<<TID::Terminator), 0x0ULL, NULL, NULL, NULL, OperandInfo13 },  // Inst #40 = BR_JT32
  { 41,	2,	1,	0,	"BYTEREV_l2r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #41 = BYTEREV_l2r
  { 42,	2,	0,	0,	"CHKCT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #42 = CHKCT_2r
  { 43,	2,	0,	0,	"CHKCT_rus", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #43 = CHKCT_rus
  { 44,	0,	0,	0,	"CLRE_0R", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #44 = CLRE_0R
  { 45,	2,	1,	0,	"CLZ_l2r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #45 = CLZ_l2r
  { 46,	3,	1,	0,	"DIVS_l3r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #46 = DIVS_l3r
  { 47,	3,	1,	0,	"DIVU_l3r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #47 = DIVU_l3r
  { 48,	1,	0,	0,	"ECALLF_1r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #48 = ECALLF_1r
  { 49,	1,	0,	0,	"ECALLT_1r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #49 = ECALLT_1r
  { 50,	1,	0,	0,	"EEU_1r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #50 = EEU_1r
  { 51,	1,	0,	0,	"ENTSP_lu6", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #51 = ENTSP_lu6
  { 52,	1,	0,	0,	"ENTSP_u6", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #52 = ENTSP_u6
  { 53,	3,	1,	0,	"EQ_2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #53 = EQ_2rus
  { 54,	3,	1,	0,	"EQ_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #54 = EQ_3r
  { 55,	1,	0,	0,	"EXTSP_lu6", 0, 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #55 = EXTSP_lu6
  { 56,	1,	0,	0,	"EXTSP_u6", 0, 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #56 = EXTSP_u6
  { 57,	1,	0,	0,	"FREER_1r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #57 = FREER_1r
  { 58,	0,	0,	0,	"GETID_0R", 0, 0x0ULL, NULL, ImplicitList3, NULL, 0 },  // Inst #58 = GETID_0R
  { 59,	2,	1,	0,	"GETR_rus", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #59 = GETR_rus
  { 60,	2,	1,	0,	"GETTS_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #60 = GETTS_2r
  { 61,	2,	1,	0,	"INCT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #61 = INCT_2r
  { 62,	3,	1,	0,	"INSHR_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo14 },  // Inst #62 = INSHR_2r
  { 63,	2,	1,	0,	"INT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #63 = INT_2r
  { 64,	2,	1,	0,	"IN_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #64 = IN_2r
  { 65,	5,	2,	0,	"LADD_l5r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo15 },  // Inst #65 = LADD_l5r
  { 66,	3,	1,	0,	"LD16S_3r", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #66 = LD16S_3r
  { 67,	3,	1,	0,	"LD8U_3r", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #67 = LD8U_3r
  { 68,	3,	1,	0,	"LDA16B_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #68 = LDA16B_l3r
  { 69,	3,	1,	0,	"LDA16F_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #69 = LDA16F_l3r
  { 70,	1,	0,	0,	"LDAP_lu10", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, ImplicitList3, NULL, OperandInfo2 },  // Inst #70 = LDAP_lu10
  { 71,	1,	0,	0,	"LDAP_lu10_ba", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, ImplicitList3, NULL, OperandInfo2 },  // Inst #71 = LDAP_lu10_ba
  { 72,	1,	0,	0,	"LDAP_u10", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, ImplicitList3, NULL, OperandInfo2 },  // Inst #72 = LDAP_u10
  { 73,	3,	1,	0,	"LDAWB_l2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #73 = LDAWB_l2rus
  { 74,	3,	1,	0,	"LDAWB_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #74 = LDAWB_l3r
  { 75,	2,	0,	0,	"LDAWCP_lu6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, ImplicitList3, NULL, OperandInfo6 },  // Inst #75 = LDAWCP_lu6
  { 76,	2,	0,	0,	"LDAWCP_u6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, ImplicitList3, NULL, OperandInfo6 },  // Inst #76 = LDAWCP_u6
  { 77,	3,	1,	0,	"LDAWDP_lru6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #77 = LDAWDP_lru6
  { 78,	3,	1,	0,	"LDAWDP_ru6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #78 = LDAWDP_ru6
  { 79,	3,	1,	0,	"LDAWFI", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #79 = LDAWFI
  { 80,	3,	1,	0,	"LDAWF_l2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #80 = LDAWF_l2rus
  { 81,	3,	1,	0,	"LDAWF_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #81 = LDAWF_l3r
  { 82,	2,	1,	0,	"LDAWSP_lru6", 0, 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #82 = LDAWSP_lru6
  { 83,	2,	1,	0,	"LDAWSP_lru6_RRegs", 0, 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo17 },  // Inst #83 = LDAWSP_lru6_RRegs
  { 84,	2,	1,	0,	"LDAWSP_ru6", 0, 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #84 = LDAWSP_ru6
  { 85,	2,	1,	0,	"LDAWSP_ru6_RRegs", 0, 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo17 },  // Inst #85 = LDAWSP_ru6_RRegs
  { 86,	2,	1,	0,	"LDC_lru6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #86 = LDC_lru6
  { 87,	2,	1,	0,	"LDC_ru6", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #87 = LDC_ru6
  { 88,	5,	2,	0,	"LDIV_l5r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo15 },  // Inst #88 = LDIV_l5r
  { 89,	2,	1,	0,	"LDWCP_lru6", 0|(1<<TID::MayLoad)|(1<<TID::Rematerializable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #89 = LDWCP_lru6
  { 90,	2,	1,	0,	"LDWCP_ru6", 0|(1<<TID::MayLoad)|(1<<TID::Rematerializable)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #90 = LDWCP_ru6
  { 91,	3,	1,	0,	"LDWDP_lru6", 0|(1<<TID::MayLoad), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #91 = LDWDP_lru6
  { 92,	3,	1,	0,	"LDWDP_ru6", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #92 = LDWDP_ru6
  { 93,	3,	1,	0,	"LDWFI", 0|(1<<TID::MayLoad), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #93 = LDWFI
  { 94,	2,	1,	0,	"LDWSP_lru6", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #94 = LDWSP_lru6
  { 95,	2,	1,	0,	"LDWSP_ru6", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #95 = LDWSP_ru6
  { 96,	3,	1,	0,	"LDW_2rus", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #96 = LDW_2rus
  { 97,	3,	1,	0,	"LDW_3r", 0|(1<<TID::MayLoad)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #97 = LDW_3r
  { 98,	6,	2,	0,	"LMUL_l6r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo18 },  // Inst #98 = LMUL_l6r
  { 99,	3,	1,	0,	"LSS_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #99 = LSS_3r
  { 100,	5,	2,	0,	"LSUB_l5r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo15 },  // Inst #100 = LSUB_l5r
  { 101,	3,	1,	0,	"LSU_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #101 = LSU_3r
  { 102,	6,	2,	0,	"MACCS_l4r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #102 = MACCS_l4r
  { 103,	6,	2,	0,	"MACCU_l4r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo19 },  // Inst #103 = MACCU_l4r
  { 104,	2,	1,	0,	"MKMSK_2r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #104 = MKMSK_2r
  { 105,	2,	1,	0,	"MKMSK_rus", 0|(1<<TID::Rematerializable), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #105 = MKMSK_rus
  { 106,	3,	1,	0,	"MUL_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #106 = MUL_l3r
  { 107,	2,	1,	0,	"NEG", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #107 = NEG
  { 108,	2,	1,	0,	"NOT", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #108 = NOT
  { 109,	3,	1,	0,	"OR_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #109 = OR_3r
  { 110,	2,	0,	0,	"OUTCT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #110 = OUTCT_2r
  { 111,	2,	0,	0,	"OUTCT_rus", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #111 = OUTCT_rus
  { 112,	3,	1,	0,	"OUTSHR_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo14 },  // Inst #112 = OUTSHR_2r
  { 113,	2,	0,	0,	"OUTT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #113 = OUTT_2r
  { 114,	2,	0,	0,	"OUT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #114 = OUT_2r
  { 115,	3,	1,	0,	"REMS_l3r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #115 = REMS_l3r
  { 116,	3,	1,	0,	"REMU_l3r", 0|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #116 = REMU_l3r
  { 117,	1,	0,	0,	"RETSP_lu6", 0|(1<<TID::Return)|(1<<TID::Barrier)|(1<<TID::MayLoad)|(1<<TID::Terminator), 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #117 = RETSP_lu6
  { 118,	1,	0,	0,	"RETSP_u6", 0|(1<<TID::Return)|(1<<TID::Barrier)|(1<<TID::MayLoad)|(1<<TID::Terminator), 0x0ULL, ImplicitList1, ImplicitList1, NULL, OperandInfo2 },  // Inst #118 = RETSP_u6
  { 119,	4,	1,	0,	"SELECT_CC", 0|(1<<TID::UsesCustomInserter), 0x0ULL, NULL, NULL, NULL, OperandInfo20 },  // Inst #119 = SELECT_CC
  { 120,	2,	0,	0,	"SETC_l2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #120 = SETC_l2r
  { 121,	2,	0,	0,	"SETC_lru6", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #121 = SETC_lru6
  { 122,	2,	0,	0,	"SETC_ru6", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo12 },  // Inst #122 = SETC_ru6
  { 123,	2,	0,	0,	"SETD_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #123 = SETD_2r
  { 124,	2,	0,	0,	"SETPT_2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #124 = SETPT_2r
  { 125,	1,	0,	0,	"SETSP_1r", 0, 0x0ULL, NULL, ImplicitList1, NULL, OperandInfo10 },  // Inst #125 = SETSP_1r
  { 126,	2,	0,	0,	"SETTW_l2r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo11 },  // Inst #126 = SETTW_l2r
  { 127,	1,	0,	0,	"SETV_1r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, NULL, OperandInfo10 },  // Inst #127 = SETV_1r
  { 128,	3,	1,	0,	"SEXT_rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo21 },  // Inst #128 = SEXT_rus
  { 129,	3,	1,	0,	"SHL_2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #129 = SHL_2rus
  { 130,	3,	1,	0,	"SHL_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #130 = SHL_3r
  { 131,	3,	1,	0,	"SHR_2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #131 = SHR_2rus
  { 132,	3,	1,	0,	"SHR_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #132 = SHR_3r
  { 133,	3,	0,	0,	"ST16_l3r", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #133 = ST16_l3r
  { 134,	3,	0,	0,	"ST8_l3r", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #134 = ST8_l3r
  { 135,	3,	0,	0,	"STWDP_lru6", 0|(1<<TID::MayStore), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #135 = STWDP_lru6
  { 136,	3,	0,	0,	"STWDP_ru6", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #136 = STWDP_ru6
  { 137,	3,	0,	0,	"STWFI", 0|(1<<TID::MayStore), 0x0ULL, NULL, NULL, NULL, OperandInfo16 },  // Inst #137 = STWFI
  { 138,	2,	0,	0,	"STWSP_lru6", 0|(1<<TID::MayStore), 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #138 = STWSP_lru6
  { 139,	2,	0,	0,	"STWSP_ru6", 0|(1<<TID::MayStore), 0x0ULL, ImplicitList1, NULL, NULL, OperandInfo12 },  // Inst #139 = STWSP_ru6
  { 140,	3,	0,	0,	"STW_2rus", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #140 = STW_2rus
  { 141,	3,	0,	0,	"STW_3r", 0|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #141 = STW_3r
  { 142,	3,	1,	0,	"SUB_2rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo7 },  // Inst #142 = SUB_2rus
  { 143,	3,	1,	0,	"SUB_3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #143 = SUB_3r
  { 144,	1,	0,	0,	"SYNCR_1r", 0|(1<<TID::MayLoad)|(1<<TID::MayStore)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, OperandInfo10 },  // Inst #144 = SYNCR_1r
  { 145,	0,	0,	0,	"WAITEU_0R", 0|(1<<TID::Branch)|(1<<TID::IndirectBranch)|(1<<TID::Barrier)|(1<<TID::MayLoad)|(1<<TID::Terminator)|(1<<TID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, NULL, 0 },  // Inst #145 = WAITEU_0R
  { 146,	3,	1,	0,	"XOR_l3r", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo8 },  // Inst #146 = XOR_l3r
  { 147,	3,	1,	0,	"ZEXT_rus", 0, 0x0ULL, NULL, NULL, NULL, OperandInfo21 },  // Inst #147 = ZEXT_rus
};
} // End llvm namespace 
