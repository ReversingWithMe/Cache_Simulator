/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 439 "../CPU/parser.y"

#include <stdio.h>

#include "spim.h"
#include "string-stream.h"
#include "spim-utils.h"
#include "inst.h"
#include "reg.h"
#include "mem.h"
#include "sym-tbl.h"
#include "data.h"
#include "scanner.h"
#include "parser.h"


/* return (0) */
#define LINE_PARSE_DONE YYACCEPT

/* return (1) */
#define FILE_PARSE_DONE YYABORT

typedef struct ll
{
  label *head;
  struct ll *tail;
} label_list;


/* Exported Variables: */

bool data_dir;                  /* => item in data segment */

bool text_dir;                  /* => item in text segment */

bool parse_error_occurred;      /* => parse resulted in error */


/* Local functions: */

static imm_expr *branch_offset (int n_inst);
static int cc_to_rt (int cc, int nd, int tf);
static void check_imm_range (imm_expr*, int32, int32);
static void check_uimm_range (imm_expr*, uint32, uint32);
static void clear_labels ();
static label_list *cons_label (label *head, label_list *tail);
static void div_inst (int op, int rd, int rs, int rt, int const_divisor);
static void mips32_r2_inst ();
static void mult_inst (int op, int rd, int rs, int rt);
static void nop_inst ();
static void set_eq_inst (int op, int rd, int rs, int rt);
static void set_ge_inst (int op, int rd, int rs, int rt);
static void set_gt_inst (int op, int rd, int rs, int rt);
static void set_le_inst (int op, int rd, int rs, int rt);
static void store_word_data (int value);
static void trap_inst ();
static void yywarn (char*);


/* Local variables: */

static bool null_term;		/* => string terminate by \0 */

static void (*store_op) (void*); /* Function to store items in an EXPR_LST */

static label_list *this_line_labels = NULL; /* List of label for curent line */

static bool noat_flag = 0;	/* => program can use $1 */

static char *input_file_name;	/* Name of file being parsed */



/* Line 268 of yacc.c  */
#line 144 "parser_yacc.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Y_EOF = 258,
     Y_NL = 259,
     Y_INT = 260,
     Y_ID = 261,
     Y_REG = 262,
     Y_FP_REG = 263,
     Y_STR = 264,
     Y_FP = 265,
     Y_ABS_D_OP = 266,
     Y_ABS_PS_OP = 267,
     Y_ABS_S_OP = 268,
     Y_ADD_D_OP = 269,
     Y_ADD_OP = 270,
     Y_ADD_PS_OP = 271,
     Y_ADD_S_OP = 272,
     Y_ADDI_OP = 273,
     Y_ADDIU_OP = 274,
     Y_ADDU_OP = 275,
     Y_ALNV_PS_OP = 276,
     Y_AND_OP = 277,
     Y_ANDI_OP = 278,
     Y_BC1F_OP = 279,
     Y_BC1FL_OP = 280,
     Y_BC1T_OP = 281,
     Y_BC1TL_OP = 282,
     Y_BC2F_OP = 283,
     Y_BC2FL_OP = 284,
     Y_BC2T_OP = 285,
     Y_BC2TL_OP = 286,
     Y_BEQ_OP = 287,
     Y_BEQL_OP = 288,
     Y_BGEZ_OP = 289,
     Y_BGEZAL_OP = 290,
     Y_BGEZALL_OP = 291,
     Y_BGEZL_OP = 292,
     Y_BGTZ_OP = 293,
     Y_BGTZL_OP = 294,
     Y_BLEZ_OP = 295,
     Y_BLEZL_OP = 296,
     Y_BLTZ_OP = 297,
     Y_BLTZAL_OP = 298,
     Y_BLTZALL_OP = 299,
     Y_BLTZL_OP = 300,
     Y_BNE_OP = 301,
     Y_BNEL_OP = 302,
     Y_BREAK_OP = 303,
     Y_C_EQ_D_OP = 304,
     Y_C_EQ_PS_OP = 305,
     Y_C_EQ_S_OP = 306,
     Y_C_F_D_OP = 307,
     Y_C_F_PS_OP = 308,
     Y_C_F_S_OP = 309,
     Y_C_LE_D_OP = 310,
     Y_C_LE_PS_OP = 311,
     Y_C_LE_S_OP = 312,
     Y_C_LT_D_OP = 313,
     Y_C_LT_PS_OP = 314,
     Y_C_LT_S_OP = 315,
     Y_C_NGE_D_OP = 316,
     Y_C_NGE_PS_OP = 317,
     Y_C_NGE_S_OP = 318,
     Y_C_NGL_D_OP = 319,
     Y_C_NGL_PS_OP = 320,
     Y_C_NGL_S_OP = 321,
     Y_C_NGLE_D_OP = 322,
     Y_C_NGLE_PS_OP = 323,
     Y_C_NGLE_S_OP = 324,
     Y_C_NGT_D_OP = 325,
     Y_C_NGT_PS_OP = 326,
     Y_C_NGT_S_OP = 327,
     Y_C_OLE_D_OP = 328,
     Y_C_OLE_PS_OP = 329,
     Y_C_OLE_S_OP = 330,
     Y_C_OLT_D_OP = 331,
     Y_C_OLT_PS_OP = 332,
     Y_C_OLT_S_OP = 333,
     Y_C_SEQ_D_OP = 334,
     Y_C_SEQ_PS_OP = 335,
     Y_C_SEQ_S_OP = 336,
     Y_C_SF_D_OP = 337,
     Y_C_SF_PS_OP = 338,
     Y_C_SF_S_OP = 339,
     Y_C_UEQ_D_OP = 340,
     Y_C_UEQ_PS_OP = 341,
     Y_C_UEQ_S_OP = 342,
     Y_C_ULE_D_OP = 343,
     Y_C_ULE_PS_OP = 344,
     Y_C_ULE_S_OP = 345,
     Y_C_ULT_D_OP = 346,
     Y_C_ULT_PS_OP = 347,
     Y_C_ULT_S_OP = 348,
     Y_C_UN_D_OP = 349,
     Y_C_UN_PS_OP = 350,
     Y_C_UN_S_OP = 351,
     Y_CACHE_OP = 352,
     Y_CEIL_L_D_OP = 353,
     Y_CEIL_L_S_OP = 354,
     Y_CEIL_W_D_OP = 355,
     Y_CEIL_W_S_OP = 356,
     Y_CFC0_OP = 357,
     Y_CFC1_OP = 358,
     Y_CFC2_OP = 359,
     Y_CLO_OP = 360,
     Y_CLZ_OP = 361,
     Y_COP2_OP = 362,
     Y_CTC0_OP = 363,
     Y_CTC1_OP = 364,
     Y_CTC2_OP = 365,
     Y_CVT_D_L_OP = 366,
     Y_CVT_D_S_OP = 367,
     Y_CVT_D_W_OP = 368,
     Y_CVT_L_D_OP = 369,
     Y_CVT_L_S_OP = 370,
     Y_CVT_PS_S_OP = 371,
     Y_CVT_S_D_OP = 372,
     Y_CVT_S_L_OP = 373,
     Y_CVT_S_PL_OP = 374,
     Y_CVT_S_PU_OP = 375,
     Y_CVT_S_W_OP = 376,
     Y_CVT_W_D_OP = 377,
     Y_CVT_W_S_OP = 378,
     Y_DERET_OP = 379,
     Y_DI_OP = 380,
     Y_DIV_D_OP = 381,
     Y_DIV_OP = 382,
     Y_DIV_S_OP = 383,
     Y_DIVU_OP = 384,
     Y_EHB_OP = 385,
     Y_EI_OP = 386,
     Y_ERET_OP = 387,
     Y_EXT_OP = 388,
     Y_FLOOR_L_D_OP = 389,
     Y_FLOOR_L_S_OP = 390,
     Y_FLOOR_W_D_OP = 391,
     Y_FLOOR_W_S_OP = 392,
     Y_INS_OP = 393,
     Y_J_OP = 394,
     Y_JAL_OP = 395,
     Y_JALR_HB_OP = 396,
     Y_JALR_OP = 397,
     Y_JR_HB_OP = 398,
     Y_JR_OP = 399,
     Y_LB_OP = 400,
     Y_LBU_OP = 401,
     Y_LDC1_OP = 402,
     Y_LDC2_OP = 403,
     Y_LDXC1_OP = 404,
     Y_LH_OP = 405,
     Y_LHU_OP = 406,
     Y_LL_OP = 407,
     Y_LUI_OP = 408,
     Y_LUXC1_OP = 409,
     Y_LW_OP = 410,
     Y_LWC1_OP = 411,
     Y_LWC2_OP = 412,
     Y_LWL_OP = 413,
     Y_LWR_OP = 414,
     Y_LWXC1_OP = 415,
     Y_MADD_D_OP = 416,
     Y_MADD_OP = 417,
     Y_MADD_PS_OP = 418,
     Y_MADD_S_OP = 419,
     Y_MADDU_OP = 420,
     Y_MFC0_OP = 421,
     Y_MFC1_OP = 422,
     Y_MFC2_OP = 423,
     Y_MFHC1_OP = 424,
     Y_MFHC2_OP = 425,
     Y_MFHI_OP = 426,
     Y_MFLO_OP = 427,
     Y_MOV_D_OP = 428,
     Y_MOV_PS_OP = 429,
     Y_MOV_S_OP = 430,
     Y_MOVF_D_OP = 431,
     Y_MOVF_OP = 432,
     Y_MOVF_PS_OP = 433,
     Y_MOVF_S_OP = 434,
     Y_MOVN_D_OP = 435,
     Y_MOVN_OP = 436,
     Y_MOVN_PS_OP = 437,
     Y_MOVN_S_OP = 438,
     Y_MOVT_D_OP = 439,
     Y_MOVT_OP = 440,
     Y_MOVT_PS_OP = 441,
     Y_MOVT_S_OP = 442,
     Y_MOVZ_D_OP = 443,
     Y_MOVZ_OP = 444,
     Y_MOVZ_PS_OP = 445,
     Y_MOVZ_S_OP = 446,
     Y_MSUB_D_OP = 447,
     Y_MSUB_OP = 448,
     Y_MSUB_PS_OP = 449,
     Y_MSUB_S_OP = 450,
     Y_MSUBU_OP = 451,
     Y_MTC0_OP = 452,
     Y_MTC1_OP = 453,
     Y_MTC2_OP = 454,
     Y_MTHC1_OP = 455,
     Y_MTHC2_OP = 456,
     Y_MTHI_OP = 457,
     Y_MTLO_OP = 458,
     Y_MUL_D_OP = 459,
     Y_MUL_PS_OP = 460,
     Y_MUL_S_OP = 461,
     Y_MUL_OP = 462,
     Y_MULT_OP = 463,
     Y_MULTU_OP = 464,
     Y_NEG_D_OP = 465,
     Y_NEG_PS_OP = 466,
     Y_NEG_S_OP = 467,
     Y_NMADD_D_OP = 468,
     Y_NMADD_PS_OP = 469,
     Y_NMADD_S_OP = 470,
     Y_NMSUB_D_OP = 471,
     Y_NMSUB_PS_OP = 472,
     Y_NMSUB_S_OP = 473,
     Y_NOR_OP = 474,
     Y_OR_OP = 475,
     Y_ORI_OP = 476,
     Y_PFW_OP = 477,
     Y_PLL_PS_OP = 478,
     Y_PLU_PS_OP = 479,
     Y_PREF_OP = 480,
     Y_PREFX_OP = 481,
     Y_PUL_PS_OP = 482,
     Y_PUU_PS_OP = 483,
     Y_RDHWR_OP = 484,
     Y_RDPGPR_OP = 485,
     Y_RECIP_D_OP = 486,
     Y_RECIP_S_OP = 487,
     Y_RFE_OP = 488,
     Y_ROTR_OP = 489,
     Y_ROTRV_OP = 490,
     Y_ROUND_L_D_OP = 491,
     Y_ROUND_L_S_OP = 492,
     Y_ROUND_W_D_OP = 493,
     Y_ROUND_W_S_OP = 494,
     Y_RSQRT_D_OP = 495,
     Y_RSQRT_S_OP = 496,
     Y_SB_OP = 497,
     Y_SC_OP = 498,
     Y_SDBBP_OP = 499,
     Y_SDC1_OP = 500,
     Y_SDC2_OP = 501,
     Y_SDXC1_OP = 502,
     Y_SEB_OP = 503,
     Y_SEH_OP = 504,
     Y_SH_OP = 505,
     Y_SLL_OP = 506,
     Y_SLLV_OP = 507,
     Y_SLT_OP = 508,
     Y_SLTI_OP = 509,
     Y_SLTIU_OP = 510,
     Y_SLTU_OP = 511,
     Y_SQRT_D_OP = 512,
     Y_SQRT_S_OP = 513,
     Y_SRA_OP = 514,
     Y_SRAV_OP = 515,
     Y_SRL_OP = 516,
     Y_SRLV_OP = 517,
     Y_SSNOP_OP = 518,
     Y_SUB_D_OP = 519,
     Y_SUB_OP = 520,
     Y_SUB_PS_OP = 521,
     Y_SUB_S_OP = 522,
     Y_SUBU_OP = 523,
     Y_SUXC1_OP = 524,
     Y_SW_OP = 525,
     Y_SWC1_OP = 526,
     Y_SWC2_OP = 527,
     Y_SWL_OP = 528,
     Y_SWR_OP = 529,
     Y_SWXC1_OP = 530,
     Y_SYNC_OP = 531,
     Y_SYNCI_OP = 532,
     Y_SYSCALL_OP = 533,
     Y_TEQ_OP = 534,
     Y_TEQI_OP = 535,
     Y_TGE_OP = 536,
     Y_TGEI_OP = 537,
     Y_TGEIU_OP = 538,
     Y_TGEU_OP = 539,
     Y_TLBP_OP = 540,
     Y_TLBR_OP = 541,
     Y_TLBWI_OP = 542,
     Y_TLBWR_OP = 543,
     Y_TLT_OP = 544,
     Y_TLTI_OP = 545,
     Y_TLTIU_OP = 546,
     Y_TLTU_OP = 547,
     Y_TNE_OP = 548,
     Y_TNEI_OP = 549,
     Y_TRUNC_L_D_OP = 550,
     Y_TRUNC_L_S_OP = 551,
     Y_TRUNC_W_D_OP = 552,
     Y_TRUNC_W_S_OP = 553,
     Y_WRPGPR_OP = 554,
     Y_WSBH_OP = 555,
     Y_XOR_OP = 556,
     Y_XORI_OP = 557,
     Y_ABS_POP = 558,
     Y_B_POP = 559,
     Y_BAL_POP = 560,
     Y_BEQZ_POP = 561,
     Y_BGE_POP = 562,
     Y_BGEU_POP = 563,
     Y_BGT_POP = 564,
     Y_BGTU_POP = 565,
     Y_BLE_POP = 566,
     Y_BLEU_POP = 567,
     Y_BLT_POP = 568,
     Y_BLTU_POP = 569,
     Y_BNEZ_POP = 570,
     Y_LA_POP = 571,
     Y_LD_POP = 572,
     Y_L_D_POP = 573,
     Y_L_S_POP = 574,
     Y_LI_D_POP = 575,
     Y_LI_POP = 576,
     Y_LI_S_POP = 577,
     Y_MFC1_D_POP = 578,
     Y_MOVE_POP = 579,
     Y_MTC1_D_POP = 580,
     Y_MULO_POP = 581,
     Y_MULOU_POP = 582,
     Y_NEG_POP = 583,
     Y_NEGU_POP = 584,
     Y_NOP_POP = 585,
     Y_NOT_POP = 586,
     Y_REM_POP = 587,
     Y_REMU_POP = 588,
     Y_ROL_POP = 589,
     Y_ROR_POP = 590,
     Y_S_D_POP = 591,
     Y_S_S_POP = 592,
     Y_SD_POP = 593,
     Y_SEQ_POP = 594,
     Y_SGE_POP = 595,
     Y_SGEU_POP = 596,
     Y_SGT_POP = 597,
     Y_SGTU_POP = 598,
     Y_SLE_POP = 599,
     Y_SLEU_POP = 600,
     Y_SNE_POP = 601,
     Y_ULH_POP = 602,
     Y_ULHU_POP = 603,
     Y_ULW_POP = 604,
     Y_USH_POP = 605,
     Y_USW_POP = 606,
     Y_ALIAS_DIR = 607,
     Y_ALIGN_DIR = 608,
     Y_ASCII_DIR = 609,
     Y_ASCIIZ_DIR = 610,
     Y_ASM0_DIR = 611,
     Y_BGNB_DIR = 612,
     Y_BYTE_DIR = 613,
     Y_COMM_DIR = 614,
     Y_DATA_DIR = 615,
     Y_DOUBLE_DIR = 616,
     Y_END_DIR = 617,
     Y_ENDB_DIR = 618,
     Y_ENDR_DIR = 619,
     Y_ENT_DIR = 620,
     Y_ERR_DIR = 621,
     Y_EXTERN_DIR = 622,
     Y_FILE_DIR = 623,
     Y_FLOAT_DIR = 624,
     Y_FMASK_DIR = 625,
     Y_FRAME_DIR = 626,
     Y_GLOBAL_DIR = 627,
     Y_HALF_DIR = 628,
     Y_K_DATA_DIR = 629,
     Y_K_TEXT_DIR = 630,
     Y_LABEL_DIR = 631,
     Y_LCOMM_DIR = 632,
     Y_LIVEREG_DIR = 633,
     Y_LOC_DIR = 634,
     Y_MASK_DIR = 635,
     Y_NOALIAS_DIR = 636,
     Y_OPTIONS_DIR = 637,
     Y_RDATA_DIR = 638,
     Y_REPEAT_DIR = 639,
     Y_SDATA_DIR = 640,
     Y_SET_DIR = 641,
     Y_SPACE_DIR = 642,
     Y_STRUCT_DIR = 643,
     Y_TEXT_DIR = 644,
     Y_VERSTAMP_DIR = 645,
     Y_VREG_DIR = 646,
     Y_WORD_DIR = 647
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 578 "parser_yacc.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  402
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  122
/* YYNRULES -- Number of rules.  */
#define YYNRULES  573
/* YYNRULES -- Number of states.  */
#define YYNSTATES  852

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   647

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     395,   396,   400,   397,     2,   398,     2,   401,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   393,     2,
       2,   394,   399,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    15,    19,    20,
      24,    25,    29,    31,    33,    35,    39,    43,    47,    51,
      55,    59,    63,    67,    71,    75,    79,    83,    87,    91,
      95,    99,   103,   105,   108,   112,   114,   116,   119,   122,
     124,   126,   130,   134,   138,   142,   146,   148,   150,   154,
     157,   162,   167,   171,   176,   181,   185,   190,   194,   199,
     203,   208,   213,   218,   223,   228,   233,   237,   241,   246,
     251,   255,   259,   264,   269,   274,   279,   283,   288,   293,
     298,   303,   308,   313,   319,   324,   329,   334,   339,   344,
     349,   354,   359,   362,   366,   370,   374,   379,   384,   389,
     394,   399,   404,   409,   414,   419,   424,   427,   430,   434,
     437,   441,   445,   449,   453,   458,   463,   468,   473,   477,
     482,   487,   490,   493,   497,   501,   505,   509,   513,   518,
     523,   529,   533,   538,   542,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     615,   617,   619,   621,   623,   625,   627,   629,   631,   633,
     635,   637,   639,   641,   643,   645,   647,   649,   651,   653,
     655,   657,   659,   661,   663,   665,   667,   669,   671,   673,
     675,   677,   679,   681,   683,   685,   687,   689,   691,   693,
     695,   697,   699,   701,   703,   705,   707,   709,   711,   713,
     715,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   749,   751,   753,
     755,   757,   759,   761,   763,   765,   767,   769,   771,   773,
     775,   777,   779,   781,   783,   785,   787,   789,   791,   793,
     795,   797,   799,   801,   803,   805,   807,   809,   811,   813,
     815,   817,   819,   821,   823,   825,   827,   829,   831,   833,
     835,   837,   839,   841,   843,   845,   847,   849,   851,   853,
     855,   857,   859,   861,   863,   865,   867,   869,   871,   873,
     875,   877,   879,   881,   883,   885,   887,   889,   891,   893,
     895,   897,   899,   901,   903,   905,   907,   909,   911,   913,
     915,   917,   919,   921,   923,   925,   927,   929,   931,   933,
     935,   937,   939,   941,   943,   945,   947,   949,   951,   953,
     955,   957,   959,   961,   963,   965,   967,   969,   971,   973,
     975,   977,   979,   981,   983,   985,   987,   989,   991,   993,
     995,   997,   999,  1001,  1003,  1005,  1007,  1009,  1011,  1013,
    1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,  1031,  1033,
    1035,  1037,  1039,  1041,  1043,  1045,  1047,  1049,  1051,  1053,
    1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,  1071,  1073,
    1075,  1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,
    1095,  1097,  1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,
    1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1131,  1133,
    1135,  1137,  1139,  1141,  1143,  1145,  1147,  1149,  1151,  1153,
    1155,  1157,  1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,
    1175,  1177,  1179,  1181,  1183,  1185,  1187,  1191,  1194,  1195,
    1199,  1200,  1204,  1206,  1209,  1210,  1214,  1218,  1220,  1223,
    1225,  1228,  1229,  1233,  1236,  1239,  1241,  1244,  1248,  1252,
    1254,  1258,  1259,  1263,  1267,  1272,  1275,  1276,  1280,  1283,
    1287,  1291,  1295,  1299,  1303,  1306,  1309,  1311,  1314,  1316,
    1319,  1322,  1325,  1328,  1330,  1333,  1335,  1338,  1342,  1347,
    1348,  1352,  1353,  1356,  1360,  1362,  1367,  1369,  1374,  1378,
    1382,  1386,  1393,  1400,  1401,  1404,  1406,  1408,  1410,  1417,
    1419,  1423,  1427,  1429,  1433,  1436,  1438,  1440,  1442,  1444,
    1446,  1448,  1450,  1452,  1454,  1456,  1458,  1460,  1462,  1465,
    1467,  1469,  1473,  1474,  1477,  1479,  1483,  1487,  1489,  1493,
    1497,  1499,  1503,  1505,  1508,  1510,  1514,  1517,  1519,  1520,
    1523,  1525,  1526,  1527
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     403,     0,    -1,    -1,   404,   405,    -1,   406,   407,    -1,
     407,    -1,   522,   393,    -1,   522,   394,   514,    -1,    -1,
     411,   408,   410,    -1,    -1,   481,   409,   410,    -1,   410,
      -1,     4,    -1,     3,    -1,   412,   500,   489,    -1,   415,
     508,   489,    -1,   416,   504,   489,    -1,   413,   500,   495,
      -1,   316,   500,   489,    -1,   321,   500,   496,    -1,   320,
     503,    10,    -1,   322,   503,    10,    -1,   349,   500,   489,
      -1,   414,   500,   489,    -1,   417,   503,   489,    -1,   418,
     498,   489,    -1,   419,   508,   489,    -1,   351,   498,   489,
      -1,   350,   498,   489,    -1,   420,   504,   489,    -1,   421,
     503,   489,    -1,   422,    -1,   423,   489,    -1,   424,     5,
     489,    -1,   425,    -1,   276,    -1,   276,     5,    -1,    48,
       5,    -1,   330,    -1,   263,    -1,   303,   500,   498,    -1,
     328,   500,   498,    -1,   329,   500,   498,    -1,   331,   500,
     498,    -1,   324,   500,   498,    -1,   426,    -1,   427,    -1,
     428,   500,   498,    -1,   429,   500,    -1,   430,   500,   498,
     499,    -1,   430,   500,   498,   496,    -1,   430,   500,   496,
      -1,   431,   500,   498,   499,    -1,   431,   500,   498,     5,
      -1,   431,   500,     5,    -1,   432,   500,   498,   494,    -1,
     432,   500,   494,    -1,   433,   500,   498,   495,    -1,   433,
     500,   495,    -1,   434,   500,   498,     5,    -1,   434,   500,
     498,   499,    -1,   435,   500,   498,     5,    -1,   436,   500,
     498,   499,    -1,   437,   500,   498,   499,    -1,   437,   500,
     498,   496,    -1,   437,   500,   496,    -1,   438,   500,   498,
      -1,   439,   500,   498,   499,    -1,   439,   500,   498,   496,
      -1,   439,   500,   496,    -1,   440,   500,   498,    -1,   440,
     500,   498,   499,    -1,   440,   500,   498,   496,    -1,   441,
     500,   498,   499,    -1,   441,   500,   498,   496,    -1,   446,
     498,   499,    -1,   447,   500,   498,   499,    -1,   447,   500,
     498,   496,    -1,   335,   500,   498,   499,    -1,   334,   500,
     498,   499,    -1,   335,   500,   498,   496,    -1,   334,   500,
     498,   496,    -1,   448,   503,   505,     5,     5,    -1,   442,
     500,   498,   499,    -1,   442,   500,   498,   496,    -1,   443,
     500,   498,   499,    -1,   443,   500,   498,   496,    -1,   444,
     500,   498,   499,    -1,   444,   500,   498,   496,    -1,   445,
     500,   498,   499,    -1,   445,   500,   498,   496,    -1,   449,
     509,    -1,   449,   507,   509,    -1,   450,   498,   509,    -1,
     451,   498,   509,    -1,   452,   498,   499,   509,    -1,   452,
     498,   492,   509,    -1,   453,   498,   499,   509,    -1,   453,
     498,   492,   509,    -1,   454,   498,   499,   509,    -1,   454,
     498,   492,   509,    -1,   455,   498,   499,   509,    -1,   455,
     498,   492,   509,    -1,   456,   498,   499,   509,    -1,   456,
     498,   492,   509,    -1,   457,   509,    -1,   457,   498,    -1,
     457,   500,   498,    -1,   458,   509,    -1,   459,   498,   494,
      -1,   460,   498,   499,    -1,   467,   503,   504,    -1,   468,
     503,   504,    -1,   463,   500,   498,   501,    -1,   469,   500,
     498,     5,    -1,   470,   503,   504,   501,    -1,   471,   503,
     504,   501,    -1,   472,   503,   504,    -1,   472,   503,   504,
     507,    -1,   473,   503,   504,   507,    -1,   461,   501,    -1,
     462,   501,    -1,   464,   501,   508,    -1,   465,   501,   508,
      -1,   466,   501,   508,    -1,   474,   503,   505,    -1,   475,
     503,   505,    -1,   476,   503,   504,   505,    -1,   477,   503,
     504,   505,    -1,   478,   503,   504,   505,   506,    -1,   479,
     504,   505,    -1,   479,   507,   504,   505,    -1,   480,   504,
     505,    -1,   107,   496,    -1,   145,    -1,   146,    -1,   150,
      -1,   151,    -1,   152,    -1,   155,    -1,   158,    -1,   159,
      -1,   222,    -1,   317,    -1,   153,    -1,   347,    -1,   348,
      -1,   148,    -1,   157,    -1,   147,    -1,   156,    -1,   318,
      -1,   319,    -1,   149,    -1,   154,    -1,   160,    -1,   242,
      -1,   243,    -1,   250,    -1,   270,    -1,   273,    -1,   274,
      -1,   338,    -1,   272,    -1,   246,    -1,   336,    -1,   337,
      -1,   271,    -1,   245,    -1,   247,    -1,   269,    -1,   275,
      -1,   233,    -1,   278,    -1,   226,    -1,   277,    -1,    97,
      -1,   225,    -1,   285,    -1,   286,    -1,   287,    -1,   288,
      -1,   132,    -1,   124,    -1,   130,    -1,   244,    -1,   105,
      -1,   106,    -1,   125,    -1,   131,    -1,    15,    -1,    20,
      -1,    22,    -1,   301,    -1,   220,    -1,   253,    -1,   256,
      -1,   252,    -1,   260,    -1,   262,    -1,    18,    -1,    19,
      -1,   254,    -1,   255,    -1,    23,    -1,   221,    -1,   302,
      -1,   251,    -1,   259,    -1,   261,    -1,   234,    -1,   235,
      -1,   219,    -1,   229,    -1,   230,    -1,   248,    -1,   249,
      -1,   299,    -1,   300,    -1,   265,    -1,   268,    -1,   127,
      -1,   129,    -1,   332,    -1,   333,    -1,   326,    -1,   327,
      -1,   344,    -1,   345,    -1,   342,    -1,   343,    -1,   340,
      -1,   341,    -1,   339,    -1,   346,    -1,   208,    -1,   209,
      -1,   162,    -1,   165,    -1,   193,    -1,   196,    -1,   207,
      -1,   133,    -1,   138,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    34,    -1,    37,    -1,    35,    -1,    36,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    45,
      -1,    43,    -1,    44,    -1,   306,    -1,   315,    -1,    32,
      -1,    33,    -1,    46,    -1,    47,    -1,   309,    -1,   310,
      -1,   307,    -1,   308,    -1,   313,    -1,   314,    -1,   311,
      -1,   312,    -1,   139,    -1,   144,    -1,   143,    -1,   140,
      -1,   142,    -1,   141,    -1,   304,    -1,   305,    -1,   280,
      -1,   282,    -1,   283,    -1,   290,    -1,   291,    -1,   294,
      -1,   279,    -1,   281,    -1,   284,    -1,   289,    -1,   292,
      -1,   293,    -1,   171,    -1,   172,    -1,   202,    -1,   203,
      -1,   181,    -1,   189,    -1,   166,    -1,   167,    -1,   323,
      -1,   168,    -1,   197,    -1,   198,    -1,   325,    -1,   199,
      -1,   169,    -1,   170,    -1,   200,    -1,   201,    -1,   102,
      -1,   103,    -1,   104,    -1,   108,    -1,   109,    -1,   110,
      -1,   175,    -1,   173,    -1,   174,    -1,   177,    -1,   185,
      -1,   180,    -1,   183,    -1,   188,    -1,   191,    -1,   182,
      -1,   190,    -1,   176,    -1,   179,    -1,   184,    -1,   187,
      -1,   178,    -1,   186,    -1,    13,    -1,    11,    -1,   100,
      -1,   101,    -1,   112,    -1,   113,    -1,   117,    -1,   121,
      -1,   122,    -1,   123,    -1,   136,    -1,   137,    -1,   212,
      -1,   210,    -1,   238,    -1,   239,    -1,   257,    -1,   258,
      -1,   297,    -1,   298,    -1,    12,    -1,    98,    -1,    99,
      -1,   111,    -1,   114,    -1,   115,    -1,   116,    -1,   118,
      -1,   119,    -1,   120,    -1,   134,    -1,   135,    -1,   211,
      -1,   231,    -1,   232,    -1,   236,    -1,   237,    -1,   240,
      -1,   241,    -1,   295,    -1,   296,    -1,    17,    -1,    14,
      -1,   128,    -1,   126,    -1,   206,    -1,   204,    -1,   267,
      -1,   264,    -1,    16,    -1,   205,    -1,   223,    -1,   224,
      -1,   227,    -1,   228,    -1,    21,    -1,   161,    -1,   163,
      -1,   164,    -1,   192,    -1,   194,    -1,   195,    -1,   213,
      -1,   214,    -1,   215,    -1,   216,    -1,   217,    -1,   218,
      -1,    54,    -1,    96,    -1,    51,    -1,    87,    -1,    78,
      -1,    75,    -1,    93,    -1,    90,    -1,    84,    -1,    69,
      -1,    81,    -1,    66,    -1,    60,    -1,    63,    -1,    57,
      -1,    72,    -1,    52,    -1,    94,    -1,    49,    -1,    85,
      -1,    76,    -1,    73,    -1,    91,    -1,    88,    -1,    82,
      -1,    67,    -1,    79,    -1,    64,    -1,    58,    -1,    61,
      -1,    55,    -1,    70,    -1,    50,    -1,    53,    -1,    59,
      -1,    56,    -1,    62,    -1,    65,    -1,    68,    -1,    71,
      -1,    74,    -1,    77,    -1,    80,    -1,    83,    -1,    86,
      -1,    89,    -1,    92,    -1,    95,    -1,   352,     7,     7,
      -1,   353,   514,    -1,    -1,   354,   482,   510,    -1,    -1,
     355,   483,   510,    -1,   356,    -1,   357,     5,    -1,    -1,
     358,   484,   517,    -1,   359,   522,   514,    -1,   360,    -1,
     360,     5,    -1,   374,    -1,   374,     5,    -1,    -1,   361,
     485,   518,    -1,   362,   519,    -1,   363,     5,    -1,   364,
      -1,   365,   522,    -1,   365,   522,     5,    -1,   367,   522,
     514,    -1,   366,    -1,   368,     5,     9,    -1,    -1,   369,
     486,   518,    -1,   370,     5,     5,    -1,   371,   502,     5,
     502,    -1,   372,   522,    -1,    -1,   373,   487,   517,    -1,
     376,   522,    -1,   377,   522,   514,    -1,   378,     5,     5,
      -1,   379,     5,     5,    -1,   380,     5,     5,    -1,   381,
       7,     7,    -1,   382,   522,    -1,   384,   514,    -1,   383,
      -1,   383,     5,    -1,   385,    -1,   385,     5,    -1,   386,
     522,    -1,   387,   514,    -1,   388,   514,    -1,   389,    -1,
     389,     5,    -1,   375,    -1,   375,     5,    -1,   390,     5,
       5,    -1,   391,   502,     5,     5,    -1,    -1,   392,   488,
     517,    -1,    -1,   490,   491,    -1,   395,   502,   396,    -1,
     497,    -1,   497,   395,   502,   396,    -1,     6,    -1,     6,
     395,   502,   396,    -1,     6,   397,   497,    -1,   497,   397,
     522,    -1,     6,   398,   497,    -1,     6,   397,   497,   395,
     502,   396,    -1,     6,   398,   497,   395,   502,   396,    -1,
      -1,   493,   496,    -1,   496,    -1,   496,    -1,   497,    -1,
     395,   497,   396,   399,   399,     5,    -1,   522,    -1,     6,
     397,   497,    -1,     6,   398,   497,    -1,     5,    -1,     5,
     397,     5,    -1,     5,     5,    -1,   502,    -1,   502,    -1,
     502,    -1,   502,    -1,     7,    -1,   506,    -1,   506,    -1,
     506,    -1,     8,    -1,     5,    -1,     7,    -1,     8,    -1,
     522,    -1,   510,   511,    -1,   511,    -1,     9,    -1,     9,
     393,     5,    -1,    -1,   513,   514,    -1,   515,    -1,   514,
     397,   515,    -1,   514,   398,   515,    -1,   516,    -1,   515,
     400,   516,    -1,   515,   401,   516,    -1,     5,    -1,   395,
     514,   396,    -1,   522,    -1,   517,   512,    -1,   512,    -1,
     512,   393,   514,    -1,   518,    10,    -1,    10,    -1,    -1,
     520,   521,    -1,   522,    -1,    -1,    -1,   523,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   515,   515,   515,   517,   518,   522,   531,   543,   542,
     549,   548,   554,   558,   563,   572,   588,   598,   608,   614,
     628,   634,   645,   655,   679,   707,   713,   729,   740,   764,
     789,   800,   806,   812,   818,   824,   830,   835,   841,   849,
     855,   861,   871,   877,   883,   889,   895,   901,   907,   914,
     920,   925,   931,   938,   943,   948,   954,   959,   965,   970,
     976,   983,   989,   994,  1000,  1005,  1022,  1041,  1047,  1052,
    1068,  1085,  1094,  1100,  1113,  1118,  1132,  1138,  1143,  1152,
    1161,  1170,  1182,  1194,  1200,  1205,  1216,  1221,  1233,  1238,
    1249,  1254,  1265,  1276,  1288,  1294,  1301,  1306,  1330,  1337,
    1360,  1367,  1376,  1383,  1392,  1399,  1422,  1431,  1439,  1448,
    1455,  1461,  1467,  1473,  1479,  1485,  1494,  1500,  1506,  1512,
    1518,  1524,  1530,  1537,  1554,  1560,  1566,  1572,  1578,  1584,
    1590,  1596,  1602,  1608,  1614,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1634,  1637,  1638,  1641,  1642,
    1645,  1646,  1647,  1648,  1651,  1652,  1653,  1656,  1657,  1658,
    1659,  1660,  1661,  1662,  1665,  1666,  1667,  1668,  1671,  1672,
    1675,  1676,  1677,  1680,  1686,  1689,  1690,  1693,  1694,  1697,
    1698,  1699,  1700,  1703,  1711,  1712,  1713,  1716,  1717,  1720,
    1721,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1735,  1736,
    1737,  1740,  1741,  1742,  1743,  1746,  1747,  1748,  1751,  1752,
    1753,  1756,  1759,  1765,  1768,  1769,  1770,  1771,  1772,  1773,
    1776,  1777,  1780,  1781,  1782,  1783,  1786,  1787,  1790,  1791,
    1794,  1795,  1798,  1799,  1802,  1803,  1806,  1807,  1808,  1809,
    1810,  1811,  1814,  1817,  1818,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1845,  1846,  1849,  1850,  1851,
    1852,  1855,  1856,  1858,  1859,  1861,  1862,  1864,  1865,  1868,
    1869,  1870,  1871,  1872,  1873,  1876,  1877,  1881,  1882,  1883,
    1884,  1885,  1886,  1889,  1890,  1891,  1892,  1893,  1894,  1898,
    1899,  1902,  1903,  1906,  1907,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1920,  1921,  1922,  1923,  1926,  1927,  1928,
    1929,  1930,  1931,  1936,  1937,  1940,  1944,  1945,  1949,  1950,
    1951,  1952,  1955,  1956,  1960,  1961,  1962,  1963,  1966,  1967,
    1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,  1979,
    1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,
    1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2012,  2015,  2016,  2017,  2018,  2019,  2020,  2021,  2022,  2025,
    2026,  2027,  2028,  2029,  2030,  2033,  2034,  2035,  2036,  2037,
    2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2048,  2049,
    2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,
    2060,  2061,  2062,  2063,  2064,  2065,  2066,  2067,  2068,  2069,
    2070,  2071,  2072,  2073,  2074,  2075,  2076,  2077,  2078,  2079,
    2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,
    2092,  2093,  2094,  2095,  2096,  2097,  2102,  2104,  2109,  2109,
    2115,  2115,  2122,  2124,  2128,  2127,  2136,  2148,  2154,  2163,
    2170,  2180,  2179,  2191,  2193,  2195,  2197,  2199,  2202,  2208,
    2214,  2218,  2217,  2229,  2231,  2234,  2242,  2241,  2253,  2262,
    2269,  2272,  2274,  2276,  2278,  2280,  2286,  2293,  2302,  2309,
    2318,  2327,  2336,  2342,  2349,  2358,  2365,  2374,  2376,  2380,
    2379,  2390,  2390,  2392,  2397,  2402,  2407,  2413,  2419,  2425,
    2430,  2436,  2442,  2450,  2450,  2452,  2458,  2465,  2470,  2475,
    2480,  2486,  2494,  2496,  2499,  2509,  2511,  2513,  2515,  2517,
    2526,  2528,  2530,  2532,  2540,  2548,  2550,  2555,  2561,  2562,
    2566,  2571,  2582,  2582,  2585,  2587,  2590,  2595,  2597,  2600,
    2604,  2606,  2609,  2622,  2626,  2630,  2640,  2644,  2651,  2651,
    2653,  2654,  2658,  2658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Y_EOF", "Y_NL", "Y_INT", "Y_ID",
  "Y_REG", "Y_FP_REG", "Y_STR", "Y_FP", "Y_ABS_D_OP", "Y_ABS_PS_OP",
  "Y_ABS_S_OP", "Y_ADD_D_OP", "Y_ADD_OP", "Y_ADD_PS_OP", "Y_ADD_S_OP",
  "Y_ADDI_OP", "Y_ADDIU_OP", "Y_ADDU_OP", "Y_ALNV_PS_OP", "Y_AND_OP",
  "Y_ANDI_OP", "Y_BC1F_OP", "Y_BC1FL_OP", "Y_BC1T_OP", "Y_BC1TL_OP",
  "Y_BC2F_OP", "Y_BC2FL_OP", "Y_BC2T_OP", "Y_BC2TL_OP", "Y_BEQ_OP",
  "Y_BEQL_OP", "Y_BGEZ_OP", "Y_BGEZAL_OP", "Y_BGEZALL_OP", "Y_BGEZL_OP",
  "Y_BGTZ_OP", "Y_BGTZL_OP", "Y_BLEZ_OP", "Y_BLEZL_OP", "Y_BLTZ_OP",
  "Y_BLTZAL_OP", "Y_BLTZALL_OP", "Y_BLTZL_OP", "Y_BNE_OP", "Y_BNEL_OP",
  "Y_BREAK_OP", "Y_C_EQ_D_OP", "Y_C_EQ_PS_OP", "Y_C_EQ_S_OP", "Y_C_F_D_OP",
  "Y_C_F_PS_OP", "Y_C_F_S_OP", "Y_C_LE_D_OP", "Y_C_LE_PS_OP",
  "Y_C_LE_S_OP", "Y_C_LT_D_OP", "Y_C_LT_PS_OP", "Y_C_LT_S_OP",
  "Y_C_NGE_D_OP", "Y_C_NGE_PS_OP", "Y_C_NGE_S_OP", "Y_C_NGL_D_OP",
  "Y_C_NGL_PS_OP", "Y_C_NGL_S_OP", "Y_C_NGLE_D_OP", "Y_C_NGLE_PS_OP",
  "Y_C_NGLE_S_OP", "Y_C_NGT_D_OP", "Y_C_NGT_PS_OP", "Y_C_NGT_S_OP",
  "Y_C_OLE_D_OP", "Y_C_OLE_PS_OP", "Y_C_OLE_S_OP", "Y_C_OLT_D_OP",
  "Y_C_OLT_PS_OP", "Y_C_OLT_S_OP", "Y_C_SEQ_D_OP", "Y_C_SEQ_PS_OP",
  "Y_C_SEQ_S_OP", "Y_C_SF_D_OP", "Y_C_SF_PS_OP", "Y_C_SF_S_OP",
  "Y_C_UEQ_D_OP", "Y_C_UEQ_PS_OP", "Y_C_UEQ_S_OP", "Y_C_ULE_D_OP",
  "Y_C_ULE_PS_OP", "Y_C_ULE_S_OP", "Y_C_ULT_D_OP", "Y_C_ULT_PS_OP",
  "Y_C_ULT_S_OP", "Y_C_UN_D_OP", "Y_C_UN_PS_OP", "Y_C_UN_S_OP",
  "Y_CACHE_OP", "Y_CEIL_L_D_OP", "Y_CEIL_L_S_OP", "Y_CEIL_W_D_OP",
  "Y_CEIL_W_S_OP", "Y_CFC0_OP", "Y_CFC1_OP", "Y_CFC2_OP", "Y_CLO_OP",
  "Y_CLZ_OP", "Y_COP2_OP", "Y_CTC0_OP", "Y_CTC1_OP", "Y_CTC2_OP",
  "Y_CVT_D_L_OP", "Y_CVT_D_S_OP", "Y_CVT_D_W_OP", "Y_CVT_L_D_OP",
  "Y_CVT_L_S_OP", "Y_CVT_PS_S_OP", "Y_CVT_S_D_OP", "Y_CVT_S_L_OP",
  "Y_CVT_S_PL_OP", "Y_CVT_S_PU_OP", "Y_CVT_S_W_OP", "Y_CVT_W_D_OP",
  "Y_CVT_W_S_OP", "Y_DERET_OP", "Y_DI_OP", "Y_DIV_D_OP", "Y_DIV_OP",
  "Y_DIV_S_OP", "Y_DIVU_OP", "Y_EHB_OP", "Y_EI_OP", "Y_ERET_OP",
  "Y_EXT_OP", "Y_FLOOR_L_D_OP", "Y_FLOOR_L_S_OP", "Y_FLOOR_W_D_OP",
  "Y_FLOOR_W_S_OP", "Y_INS_OP", "Y_J_OP", "Y_JAL_OP", "Y_JALR_HB_OP",
  "Y_JALR_OP", "Y_JR_HB_OP", "Y_JR_OP", "Y_LB_OP", "Y_LBU_OP", "Y_LDC1_OP",
  "Y_LDC2_OP", "Y_LDXC1_OP", "Y_LH_OP", "Y_LHU_OP", "Y_LL_OP", "Y_LUI_OP",
  "Y_LUXC1_OP", "Y_LW_OP", "Y_LWC1_OP", "Y_LWC2_OP", "Y_LWL_OP",
  "Y_LWR_OP", "Y_LWXC1_OP", "Y_MADD_D_OP", "Y_MADD_OP", "Y_MADD_PS_OP",
  "Y_MADD_S_OP", "Y_MADDU_OP", "Y_MFC0_OP", "Y_MFC1_OP", "Y_MFC2_OP",
  "Y_MFHC1_OP", "Y_MFHC2_OP", "Y_MFHI_OP", "Y_MFLO_OP", "Y_MOV_D_OP",
  "Y_MOV_PS_OP", "Y_MOV_S_OP", "Y_MOVF_D_OP", "Y_MOVF_OP", "Y_MOVF_PS_OP",
  "Y_MOVF_S_OP", "Y_MOVN_D_OP", "Y_MOVN_OP", "Y_MOVN_PS_OP", "Y_MOVN_S_OP",
  "Y_MOVT_D_OP", "Y_MOVT_OP", "Y_MOVT_PS_OP", "Y_MOVT_S_OP", "Y_MOVZ_D_OP",
  "Y_MOVZ_OP", "Y_MOVZ_PS_OP", "Y_MOVZ_S_OP", "Y_MSUB_D_OP", "Y_MSUB_OP",
  "Y_MSUB_PS_OP", "Y_MSUB_S_OP", "Y_MSUBU_OP", "Y_MTC0_OP", "Y_MTC1_OP",
  "Y_MTC2_OP", "Y_MTHC1_OP", "Y_MTHC2_OP", "Y_MTHI_OP", "Y_MTLO_OP",
  "Y_MUL_D_OP", "Y_MUL_PS_OP", "Y_MUL_S_OP", "Y_MUL_OP", "Y_MULT_OP",
  "Y_MULTU_OP", "Y_NEG_D_OP", "Y_NEG_PS_OP", "Y_NEG_S_OP", "Y_NMADD_D_OP",
  "Y_NMADD_PS_OP", "Y_NMADD_S_OP", "Y_NMSUB_D_OP", "Y_NMSUB_PS_OP",
  "Y_NMSUB_S_OP", "Y_NOR_OP", "Y_OR_OP", "Y_ORI_OP", "Y_PFW_OP",
  "Y_PLL_PS_OP", "Y_PLU_PS_OP", "Y_PREF_OP", "Y_PREFX_OP", "Y_PUL_PS_OP",
  "Y_PUU_PS_OP", "Y_RDHWR_OP", "Y_RDPGPR_OP", "Y_RECIP_D_OP",
  "Y_RECIP_S_OP", "Y_RFE_OP", "Y_ROTR_OP", "Y_ROTRV_OP", "Y_ROUND_L_D_OP",
  "Y_ROUND_L_S_OP", "Y_ROUND_W_D_OP", "Y_ROUND_W_S_OP", "Y_RSQRT_D_OP",
  "Y_RSQRT_S_OP", "Y_SB_OP", "Y_SC_OP", "Y_SDBBP_OP", "Y_SDC1_OP",
  "Y_SDC2_OP", "Y_SDXC1_OP", "Y_SEB_OP", "Y_SEH_OP", "Y_SH_OP", "Y_SLL_OP",
  "Y_SLLV_OP", "Y_SLT_OP", "Y_SLTI_OP", "Y_SLTIU_OP", "Y_SLTU_OP",
  "Y_SQRT_D_OP", "Y_SQRT_S_OP", "Y_SRA_OP", "Y_SRAV_OP", "Y_SRL_OP",
  "Y_SRLV_OP", "Y_SSNOP_OP", "Y_SUB_D_OP", "Y_SUB_OP", "Y_SUB_PS_OP",
  "Y_SUB_S_OP", "Y_SUBU_OP", "Y_SUXC1_OP", "Y_SW_OP", "Y_SWC1_OP",
  "Y_SWC2_OP", "Y_SWL_OP", "Y_SWR_OP", "Y_SWXC1_OP", "Y_SYNC_OP",
  "Y_SYNCI_OP", "Y_SYSCALL_OP", "Y_TEQ_OP", "Y_TEQI_OP", "Y_TGE_OP",
  "Y_TGEI_OP", "Y_TGEIU_OP", "Y_TGEU_OP", "Y_TLBP_OP", "Y_TLBR_OP",
  "Y_TLBWI_OP", "Y_TLBWR_OP", "Y_TLT_OP", "Y_TLTI_OP", "Y_TLTIU_OP",
  "Y_TLTU_OP", "Y_TNE_OP", "Y_TNEI_OP", "Y_TRUNC_L_D_OP", "Y_TRUNC_L_S_OP",
  "Y_TRUNC_W_D_OP", "Y_TRUNC_W_S_OP", "Y_WRPGPR_OP", "Y_WSBH_OP",
  "Y_XOR_OP", "Y_XORI_OP", "Y_ABS_POP", "Y_B_POP", "Y_BAL_POP",
  "Y_BEQZ_POP", "Y_BGE_POP", "Y_BGEU_POP", "Y_BGT_POP", "Y_BGTU_POP",
  "Y_BLE_POP", "Y_BLEU_POP", "Y_BLT_POP", "Y_BLTU_POP", "Y_BNEZ_POP",
  "Y_LA_POP", "Y_LD_POP", "Y_L_D_POP", "Y_L_S_POP", "Y_LI_D_POP",
  "Y_LI_POP", "Y_LI_S_POP", "Y_MFC1_D_POP", "Y_MOVE_POP", "Y_MTC1_D_POP",
  "Y_MULO_POP", "Y_MULOU_POP", "Y_NEG_POP", "Y_NEGU_POP", "Y_NOP_POP",
  "Y_NOT_POP", "Y_REM_POP", "Y_REMU_POP", "Y_ROL_POP", "Y_ROR_POP",
  "Y_S_D_POP", "Y_S_S_POP", "Y_SD_POP", "Y_SEQ_POP", "Y_SGE_POP",
  "Y_SGEU_POP", "Y_SGT_POP", "Y_SGTU_POP", "Y_SLE_POP", "Y_SLEU_POP",
  "Y_SNE_POP", "Y_ULH_POP", "Y_ULHU_POP", "Y_ULW_POP", "Y_USH_POP",
  "Y_USW_POP", "Y_ALIAS_DIR", "Y_ALIGN_DIR", "Y_ASCII_DIR", "Y_ASCIIZ_DIR",
  "Y_ASM0_DIR", "Y_BGNB_DIR", "Y_BYTE_DIR", "Y_COMM_DIR", "Y_DATA_DIR",
  "Y_DOUBLE_DIR", "Y_END_DIR", "Y_ENDB_DIR", "Y_ENDR_DIR", "Y_ENT_DIR",
  "Y_ERR_DIR", "Y_EXTERN_DIR", "Y_FILE_DIR", "Y_FLOAT_DIR", "Y_FMASK_DIR",
  "Y_FRAME_DIR", "Y_GLOBAL_DIR", "Y_HALF_DIR", "Y_K_DATA_DIR",
  "Y_K_TEXT_DIR", "Y_LABEL_DIR", "Y_LCOMM_DIR", "Y_LIVEREG_DIR",
  "Y_LOC_DIR", "Y_MASK_DIR", "Y_NOALIAS_DIR", "Y_OPTIONS_DIR",
  "Y_RDATA_DIR", "Y_REPEAT_DIR", "Y_SDATA_DIR", "Y_SET_DIR", "Y_SPACE_DIR",
  "Y_STRUCT_DIR", "Y_TEXT_DIR", "Y_VERSTAMP_DIR", "Y_VREG_DIR",
  "Y_WORD_DIR", "':'", "'='", "'('", "')'", "'+'", "'-'", "'>'", "'*'",
  "'/'", "$accept", "LINE", "$@1", "LBL_CMD", "OPT_LBL", "CMD", "$@2",
  "$@3", "TERM", "ASM_CODE", "LOAD_OPS", "LOADI_OPS", "ULOADH_POPS",
  "LOADC_OPS", "LOADFP_OPS", "LOADFP_INDEX_OPS", "STORE_OPS", "STOREC_OPS",
  "STOREFP_OPS", "STOREFP_INDEX_OPS", "SYS_OPS", "PREFETCH_OPS",
  "CACHE_OPS", "TLB_OPS", "NULLARY_OPS", "NULLARY_OPS_REV2",
  "COUNT_LEADING_OPS", "UNARY_OPS_REV2", "BINARYI_OPS", "BINARYIR_OPS",
  "BINARY_ARITHI_OPS", "BINARY_LOGICALI_OPS", "SHIFT_OPS",
  "SHIFT_OPS_REV2", "SHIFTV_OPS_REV2", "BINARY_OPS", "BINARY_OPS_REV2",
  "SUB_OPS", "DIV_POPS", "MUL_POPS", "SET_LE_POPS", "SET_GT_POPS",
  "SET_GE_POPS", "SET_EQ_POPS", "MULT_OPS", "MULT_OPS3", "BF_OPS_REV2",
  "BR_COP_OPS", "UNARY_BR_OPS", "UNARY_BR_POPS", "BINARY_BR_OPS",
  "BR_GT_POPS", "BR_GE_POPS", "BR_LT_POPS", "BR_LE_POPS", "J_OPS", "B_OPS",
  "BINARYI_TRAP_OPS", "BINARY_TRAP_OPS", "MOVE_FROM_HILO_OPS",
  "MOVE_TO_HILO_OPS", "MOVEC_OPS", "MOVE_COP_OPS", "MOVE_COP_OPS_REV2",
  "CTL_COP_OPS", "FP_MOVE_OPS", "FP_MOVE_OPS_REV2", "MOVECC_OPS",
  "FP_MOVEC_OPS", "FP_MOVEC_OPS_REV2", "FP_MOVECC_OPS",
  "FP_MOVECC_OPS_REV2", "FP_UNARY_OPS", "FP_UNARY_OPS_REV2",
  "FP_BINARY_OPS", "FP_BINARY_OPS_REV2", "FP_TERNARY_OPS_REV2",
  "FP_CMP_OPS", "FP_CMP_OPS_REV2", "ASM_DIRECTIVE", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "ADDRESS", "$@11", "ADDR", "BR_IMM32",
  "$@12", "IMM16", "UIMM16", "IMM32", "ABS_ADDR", "SRC1", "SRC2", "DEST",
  "REG", "REGISTER", "F_DEST", "F_SRC1", "F_SRC2", "FP_REGISTER", "CC_REG",
  "COP_REG", "LABEL", "STR_LST", "STR", "EXPRESSION", "$@13", "EXPR",
  "TRM", "FACTOR", "EXPR_LST", "FP_EXPR_LST", "OPTIONAL_ID", "$@14",
  "OPT_ID", "ID", "$@15", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,    58,    61,    40,    41,    43,    45,    62,
      42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   402,   404,   403,   405,   405,   406,   406,   408,   407,
     409,   407,   407,   410,   410,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   413,   414,   414,   415,   415,
     416,   416,   416,   416,   417,   417,   417,   418,   418,   418,
     418,   418,   418,   418,   419,   419,   419,   419,   420,   420,
     421,   421,   421,   422,   422,   423,   423,   424,   424,   425,
     425,   425,   425,   426,   427,   427,   427,   428,   428,   429,
     429,   430,   430,   430,   430,   430,   430,   430,   431,   431,
     431,   432,   432,   432,   432,   433,   433,   433,   434,   434,
     434,   435,   436,   437,   438,   438,   438,   438,   438,   438,
     439,   439,   440,   440,   440,   440,   441,   441,   442,   442,
     443,   443,   444,   444,   445,   445,   446,   446,   446,   446,
     446,   446,   447,   448,   448,   449,   449,   449,   449,   449,
     449,   449,   449,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   451,   451,   452,   452,   452,
     452,   453,   453,   454,   454,   455,   455,   456,   456,   457,
     457,   457,   457,   457,   457,   458,   458,   459,   459,   459,
     459,   459,   459,   460,   460,   460,   460,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   464,   464,   464,
     464,   464,   464,   465,   465,   465,   465,   466,   466,   466,
     466,   466,   466,   467,   467,   468,   469,   469,   470,   470,
     470,   470,   471,   471,   472,   472,   472,   472,   473,   473,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   476,   476,   476,   476,   476,   476,   476,   476,   477,
     477,   477,   477,   477,   477,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   481,   481,   482,   481,
     483,   481,   481,   481,   484,   481,   481,   481,   481,   481,
     481,   485,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   486,   481,   481,   481,   481,   487,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   488,
     481,   490,   489,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   493,   492,   494,   495,   496,   496,   496,
     496,   496,   497,   497,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   508,   509,   510,   510,
     511,   511,   513,   512,   514,   514,   514,   515,   515,   515,
     516,   516,   516,   517,   517,   517,   518,   518,   520,   519,
     521,   521,   523,   522
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     0,     3,
       0,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     3,     1,     1,     2,     2,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     3,     2,
       4,     4,     3,     4,     4,     3,     4,     3,     4,     3,
       4,     4,     4,     4,     4,     4,     3,     3,     4,     4,
       3,     3,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     2,     3,     2,
       3,     3,     3,     3,     4,     4,     4,     4,     3,     4,
       4,     2,     2,     3,     3,     3,     3,     3,     4,     4,
       5,     3,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     3,
       0,     3,     1,     2,     0,     3,     3,     1,     2,     1,
       2,     0,     3,     2,     2,     1,     2,     3,     3,     1,
       3,     0,     3,     3,     4,     2,     0,     3,     2,     3,
       3,     3,     3,     3,     2,     2,     1,     2,     1,     2,
       2,     2,     2,     1,     2,     1,     2,     3,     4,     0,
       3,     0,     2,     3,     1,     4,     1,     4,     3,     3,
       3,     6,     6,     0,     2,     1,     1,     1,     6,     1,
       3,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     0,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     1,     3,     2,     1,     0,     2,
       1,     0,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,   572,     1,    14,    13,   341,   360,   340,   382,
     191,   389,   381,   201,   202,   192,   395,   193,   205,   245,
     246,   247,   248,   249,   250,   251,   252,   267,   268,   253,
     255,   256,   254,   257,   258,   259,   260,   261,   263,   264,
     262,   269,   270,     0,   426,   440,   410,   424,   441,   408,
     438,   443,   422,   436,   442,   420,   437,   444,   421,   435,
     445,   419,   433,   446,   417,   439,   447,   423,   429,   448,
     413,   428,   449,   412,   434,   450,   418,   432,   451,   416,
     427,   452,   411,   431,   453,   415,   430,   454,   414,   425,
     455,   409,   177,   361,   362,   342,   343,   317,   318,   319,
     187,   188,     0,   320,   321,   322,   363,   344,   345,   364,
     365,   366,   346,   367,   368,   369,   347,   348,   349,   184,
     189,   384,   222,   383,   223,   185,   190,   183,   243,   370,
     371,   350,   351,   244,   279,   282,   284,   283,   281,   280,
     135,   136,   150,   148,   154,   137,   138,   139,   145,   155,
     140,   151,   149,   141,   142,   156,   396,   238,   397,   398,
     239,   305,   306,   308,   313,   314,   299,   300,   324,   325,
     323,   334,   326,   338,   335,   328,   303,   332,   329,   336,
     327,   339,   337,   330,   304,   333,   331,   399,   240,   400,
     401,   241,   309,   310,   312,   315,   316,   301,   302,   386,
     390,   385,   242,   236,   237,   353,   372,   352,   402,   403,
     404,   405,   406,   407,   213,   195,   206,   143,   391,   392,
     178,   175,   393,   394,   214,   215,   373,   374,   173,   211,
     212,   375,   376,   354,   355,   377,   378,   157,   158,   186,
     169,   165,   170,   216,   217,   159,   208,   198,   196,   203,
     204,   197,   356,   357,   209,   199,   210,   200,    40,   388,
     220,   387,   221,   171,   160,   168,   164,   161,   162,   172,
      36,   176,   174,   293,   287,   294,   288,   289,   295,   179,
     180,   181,   182,   296,   290,   291,   297,   298,   292,   379,
     380,   358,   359,   218,   219,   194,   207,     0,   285,   286,
     265,   273,   274,   271,   272,   277,   278,   275,   276,   266,
       0,   144,   152,   153,     0,     0,     0,   307,     0,   311,
     226,   227,     0,     0,    39,     0,   224,   225,     0,     0,
     166,   167,   163,   234,   232,   233,   230,   231,   228,   229,
     235,   146,   147,     0,     0,     0,     0,   572,   458,   460,
     462,     0,   464,   572,   467,   471,   568,     0,   475,   572,
     479,   572,     0,   481,     0,     0,   572,   486,   469,   505,
     572,   572,     0,     0,     0,     0,   572,   496,   572,   498,
     572,   572,   572,   503,     0,     0,   509,     3,     0,     5,
      12,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,   511,     0,    35,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   572,
       0,     0,     0,     0,     0,     0,     0,   572,   572,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,    38,   532,     0,     0,   134,   527,
     529,    37,   539,     0,   537,   511,   543,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,   511,   511,   535,
     511,     0,   560,   572,   457,   554,   557,   562,     0,     0,
     463,   552,   572,   468,     0,   473,   571,   474,   476,   572,
       0,     0,     0,     0,   485,   552,   470,   506,   488,   572,
       0,     0,     0,     0,   494,   497,   495,   499,   500,   501,
     502,   504,     0,     0,   552,     4,     0,   511,     0,   511,
     545,   546,   511,   511,   541,   511,   511,   511,   511,   511,
      33,     0,   511,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   544,   572,    92,   547,   572,   572,
     523,   523,   523,   523,   523,   107,     0,   535,   106,   109,
       0,     0,   121,   538,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,   572,   573,   534,     0,
       0,     0,     0,    41,    19,    21,    20,    22,    45,    42,
      43,    44,     0,     0,    23,    29,    28,   456,     0,   572,
     572,   572,   572,   550,   459,   549,   461,   564,   572,   552,
     466,   567,   472,   569,   570,   477,   478,   480,   482,   483,
       0,   552,   489,   490,   491,   492,   493,   507,     0,   552,
       9,    15,    18,   526,    24,    16,    17,    25,    26,    27,
      30,    31,   516,     0,   512,   514,    34,    48,    52,     0,
      55,     0,    57,   525,     0,    59,     0,     0,     0,     0,
      66,     0,    67,    70,     0,    71,     0,     0,     0,     0,
       0,    76,   536,     0,     0,   542,    93,    94,    95,   572,
       0,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     108,   110,   111,     0,   123,   124,   125,   112,   113,     0,
       0,     0,   118,     0,   126,   127,     0,     0,     0,   131,
       0,   133,    11,     7,   533,   530,   531,     0,    82,    80,
      81,    79,   561,   555,   556,   558,   559,     0,   548,   572,
     553,   563,   566,   484,   508,     0,     0,     0,     0,     0,
     572,    51,    50,    54,    53,    56,    58,    60,    61,    62,
      63,    65,    64,    69,    68,    73,    72,    75,    74,    85,
      84,    87,    86,    89,    88,    91,    90,    78,    77,     0,
      97,   524,    96,    99,    98,   101,   100,   103,   102,   105,
     104,   114,   115,   116,   117,   119,   120,   128,   129,     0,
     132,     0,   551,   565,     0,   518,   520,   513,     0,   519,
      83,   130,     0,   517,     0,     0,   515,   528,     0,     0,
     521,   522
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   387,   388,   389,   536,   614,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     498,   499,   501,   504,   511,   515,   534,   550,   551,   684,
     719,   720,   692,   672,   673,   469,   488,   711,   473,   592,
     489,   477,   543,   714,   478,   575,   542,   576,   644,   645,
     647,   648,   494,   495,   496,   649,   652,   505,   506,   653,
     470,   463
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -631
static const yytype_int16 yypact[] =
{
    -631,    18,   768,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,    21,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,     3,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
      33,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,    40,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
      40,  -631,  -631,  -631,    45,    40,    45,  -631,    40,  -631,
    -631,  -631,    40,    40,  -631,    40,  -631,  -631,    40,    40,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,    40,    40,    40,    55,     8,  -631,  -631,
    -631,    63,  -631,  -631,    78,  -631,  -631,    81,  -631,  -631,
    -631,  -631,    88,  -631,   107,    40,  -631,  -631,   126,   131,
    -631,  -631,   132,   133,   134,    70,  -631,   135,     8,   136,
    -631,     8,     8,   138,   139,    40,  -631,  -631,   768,  -631,
    -631,  -631,    40,    40,    40,    72,    45,    45,    40,    72,
      45,    45,  -631,  -631,   140,  -631,  -631,  -631,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    45,   148,
      40,    40,    40,    40,    40,    40,    40,    40,  -631,    40,
      40,    40,    40,    40,    40,    40,    40,    45,    45,    40,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    47,
      45,  -631,  -312,   152,  -631,    -4,  -309,   154,  -631,  -631,
    -631,  -631,  -631,    40,  -631,  -631,  -631,   150,  -631,     3,
     153,    40,    40,    40,    40,    40,    40,  -631,  -631,  -631,
    -631,   155,  -631,     8,  -306,  -305,  -631,  -631,   156,   156,
    -631,  -631,     8,  -631,   157,  -631,   158,  -631,   161,     8,
     160,   157,   165,   166,  -631,  -631,  -631,  -631,  -631,     8,
     167,   169,   170,   172,  -631,  -631,  -306,  -631,  -631,  -306,
    -306,  -631,   175,   176,  -631,  -631,    97,  -631,     3,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,     5,  -631,    40,  -631,     0,    17,     0,     0,    40,
      40,    40,     0,    40,     0,    40,    40,    40,    40,    40,
      40,    40,    40,    45,  -631,  -631,  -631,  -631,  -631,  -631,
      40,    40,    40,    40,    40,  -631,    40,   177,  -631,  -631,
       3,    40,  -631,  -631,  -631,    40,    72,    72,    72,    45,
      45,    40,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    97,  -631,     8,  -631,  -631,   178,
     154,   154,  -214,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,     0,     0,  -631,  -631,  -631,  -631,  -331,     8,
       8,     8,     8,  -208,   156,  -631,   156,  -207,     8,   101,
    -306,  -631,   184,  -631,  -631,  -631,  -306,  -631,   184,  -631,
      40,   103,  -306,  -631,  -631,  -631,  -631,  -631,   182,   105,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -334,    40,  -631,  -326,  -631,  -631,  -631,     0,
    -631,    67,  -631,  -631,     3,  -631,     3,    68,   183,    40,
    -631,     0,  -631,  -631,     0,     0,     0,     0,     0,     0,
       0,  -631,  -631,     0,   190,  -631,  -631,  -631,  -631,  -631,
       3,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,    40,  -631,  -631,  -631,  -631,  -631,   191,
      40,    40,   148,   148,  -631,  -631,    45,    45,    45,  -631,
      45,  -631,  -631,  -306,  -631,  -631,  -631,  -202,  -631,  -631,
    -631,  -631,  -631,  -305,  -305,  -631,  -631,   194,  -631,     8,
    -306,  -631,  -631,  -631,  -631,    40,   154,   154,  -196,    40,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,   196,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,    45,
    -631,  -197,  -631,  -306,  -193,  -189,  -187,  -631,  -184,  -631,
    -631,  -631,   208,  -631,    40,    40,  -631,  -631,  -182,  -181,
    -631,  -631
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -631,  -631,  -631,  -631,  -631,  -172,  -631,  -631,  -520,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -283,  -631,  -631,
    -524,  -631,  -561,  -541,   -98,  -464,   816,   625,   241,  -400,
    -295,    20,  -357,  -557,  -375,  -445,  -387,  -402,  -282,  -568,
    -630,  -631,  -341,  -529,  -507,  -483,  -293,  -631,  -631,  -631,
      -2,  -631
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -573
static const yytype_int16 yytable[] =
{
     462,   618,   474,   622,   468,   465,   466,   472,   465,   466,
     465,   682,   547,   492,   612,   474,   670,   695,     3,   771,
     474,   544,   690,   474,   472,   544,   464,   474,   474,   731,
     474,   771,   661,   474,   474,   588,   589,   526,   471,   771,
     529,   530,   594,   548,   596,   597,   598,   472,   474,   744,
     745,   669,   574,   476,   749,   476,   751,   722,   724,   726,
     728,   775,   491,   776,   777,   762,   639,   640,   500,   779,
     513,   780,   783,   787,   472,   472,   768,   523,   768,   540,
     541,   615,   616,   503,   544,   544,   507,   685,   620,   621,
     533,   639,   640,   510,   752,   641,   642,   474,   474,   474,
       4,     5,   611,   613,  -465,  -465,  -487,  -487,  -510,  -510,
     763,   764,   512,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   516,   474,   785,   765,   766,   517,   520,   521,   522,
     525,   527,   587,   531,   532,   552,   593,   593,   474,   593,
     593,   593,   638,   574,   474,   786,   755,   756,   617,   465,
     625,   650,   637,   627,  -572,   643,   655,   651,   656,   657,
     659,   660,   663,   716,   664,   665,   717,   718,   662,   666,
     667,   668,   757,   754,  -537,   767,   769,   774,   789,   827,
     828,   829,   624,   830,   772,   809,   822,   831,   715,   832,
     837,   840,   842,   843,   634,   635,   844,   636,   845,   734,
     735,   736,   846,   847,   850,   851,   535,   646,   658,     0,
       0,     0,     0,     0,   544,   544,     0,   544,   544,   544,
     544,   715,   715,   544,   544,   544,   715,   544,   715,     0,
       0,     0,   737,   738,     0,   740,   741,   742,   743,     0,
       0,   746,   747,   748,   671,   750,   674,     0,     0,   675,
     676,     0,   677,   678,   679,   680,   681,     0,     0,   686,
       0,     0,     0,     0,     0,   753,   712,     0,     0,     0,
       0,     0,     0,     0,     0,   712,   712,   712,   712,   712,
       0,     0,     0,     0,     0,     0,   712,   825,   826,     0,
       0,     0,     0,     0,     0,     0,     0,   770,     0,     0,
       0,     0,   835,   836,     0,     0,     0,   810,     0,   812,
     813,   814,   815,   816,   817,   818,   819,   820,     0,     0,
       0,     0,     0,   821,     0,     0,   480,   712,   712,     0,
     823,   824,     0,     0,     0,   497,     0,     0,     0,     0,
       0,   502,     0,     0,     0,     0,     0,   508,     0,   509,
       0,     0,     0,     0,   514,   773,     0,     0,   518,   519,
       0,   715,   715,   715,   524,   715,   497,     0,   528,   497,
     497,   626,     0,     0,     0,     0,     0,     0,   778,     0,
       0,     0,     0,   619,   712,   467,   712,     0,   467,     0,
     683,     0,   712,   493,   712,     0,   712,     0,     0,   712,
     712,   712,   712,   712,   712,   712,     0,   545,   712,     0,
       0,   549,     0,     0,     0,     0,     0,   577,   833,     0,
       0,     0,     0,     0,     0,   577,   577,     0,   593,     0,
       0,     0,     0,     0,     0,   593,   593,     0,   573,     0,
       0,     0,     0,     0,   841,     0,     0,   688,     0,   693,
       0,     0,     0,     0,   700,     0,   703,   599,   600,     0,
     602,   603,   604,   605,   606,   607,   608,   609,   610,     0,
     834,     0,     0,     0,   838,     0,     0,     0,     0,     0,
       0,   497,   693,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,     0,   654,     0,     0,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   758,   760,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   848,
     849,   475,     0,     0,     0,     0,   479,     0,     0,   481,
       0,     0,     0,   482,   483,     0,   484,     0,     0,   485,
     486,     0,     0,   577,     0,     0,   577,   577,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0,     0,     0,
       0,   781,     0,     0,     0,     0,   693,     0,     0,     0,
       0,     0,     0,   791,     0,     0,   793,   795,   797,   799,
     801,   803,   805,     0,   497,   807,     0,     0,     0,     0,
       0,     0,   811,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,   538,   539,     0,   497,   497,   497,
     497,     0,     0,     0,     0,     0,   497,     0,     0,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,     0,   572,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,     0,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,     0,   577,
     577,   577,   577,   577,   577,   577,   577,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,     0,     0,
       0,     4,     5,     0,     0,     0,     0,     0,   839,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     0,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   721,   723,   725,   727,   729,
       0,     0,     0,     0,   546,     0,   732,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   571,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,   590,   591,   759,   761,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   623,
       0,     0,     0,     0,     0,     0,     0,   628,   629,   630,
     631,   632,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   782,     0,   784,     0,     0,     0,
       0,     0,   788,     0,   790,     0,   792,     0,     0,   794,
     796,   798,   800,   802,   804,   806,     0,     0,   808,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   687,
       0,   689,   691,   694,   696,   697,   698,   699,   701,   702,
     704,   705,   706,   707,   708,   709,   710,     0,   713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   730,     0,     0,     0,     0,     0,     0,     0,
       0,   733,     0,     0,     0,     0,     0,   739
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-631))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,     5,   297,   467,   102,     5,     6,     7,     5,     6,
       5,     6,   399,     5,   459,   310,   536,   558,     0,   649,
     315,   396,     5,   318,     7,   400,     5,   322,   323,   590,
     325,   661,   515,   328,   329,   437,   438,   378,     5,   669,
     381,   382,   442,   400,   444,   445,   446,     7,   343,   606,
     607,   534,     5,     8,   611,     8,   613,   581,   582,   583,
     584,   395,     7,   397,   398,   396,   397,   398,     5,   395,
     365,   397,     5,     5,     7,     7,   644,     7,   646,     7,
       8,   393,   394,     5,   459,   460,     5,   551,   397,   398,
     385,   397,   398,     5,   614,   400,   401,   392,   393,   394,
       3,     4,   459,   460,     3,     4,     3,     4,     3,     4,
     639,   640,     5,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,     5,   427,   694,   641,   642,     5,     5,     5,     5,
       5,     5,   437,     5,     5,     5,   441,   442,   443,   444,
     445,   446,   493,     5,   449,   696,   620,   621,     6,     5,
      10,   502,     7,    10,     6,     9,     5,    10,   509,     9,
       5,     5,     5,   575,     5,     5,   578,   579,   519,     7,
       5,     5,   396,     5,     7,   393,   393,     5,     5,   746,
     747,   748,   475,   750,    10,     5,     5,   399,   573,     5,
     396,     5,   399,   396,   487,   488,   395,   490,   395,   596,
     597,   598,   396,     5,   396,   396,   388,   499,   511,    -1,
      -1,    -1,    -1,    -1,   599,   600,    -1,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,    -1,
      -1,    -1,   599,   600,    -1,   602,   603,   604,   605,    -1,
      -1,   608,   609,   610,   537,   612,   539,    -1,    -1,   542,
     543,    -1,   545,   546,   547,   548,   549,    -1,    -1,   552,
      -1,    -1,    -1,    -1,    -1,   616,   571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   581,   582,   583,   584,
      -1,    -1,    -1,    -1,    -1,    -1,   591,   742,   743,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,    -1,
      -1,    -1,   776,   777,    -1,    -1,    -1,   719,    -1,   721,
     722,   723,   724,   725,   726,   727,   728,   729,    -1,    -1,
      -1,    -1,    -1,   733,    -1,    -1,   316,   632,   633,    -1,
     740,   741,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,   353,    -1,    -1,    -1,    -1,    -1,   359,    -1,   361,
      -1,    -1,    -1,    -1,   366,   660,    -1,    -1,   370,   371,
      -1,   746,   747,   748,   376,   750,   378,    -1,   380,   381,
     382,   479,    -1,    -1,    -1,    -1,    -1,    -1,   683,    -1,
      -1,    -1,    -1,   397,   689,   395,   691,    -1,   395,    -1,
     395,    -1,   697,   395,   699,    -1,   701,    -1,    -1,   704,
     705,   706,   707,   708,   709,   710,    -1,   397,   713,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,   429,   769,    -1,
      -1,    -1,    -1,    -1,    -1,   437,   438,    -1,   733,    -1,
      -1,    -1,    -1,    -1,    -1,   740,   741,    -1,   428,    -1,
      -1,    -1,    -1,    -1,   829,    -1,    -1,   555,    -1,   557,
      -1,    -1,    -1,    -1,   562,    -1,   564,   447,   448,    -1,
     450,   451,   452,   453,   454,   455,   456,   457,   458,    -1,
     775,    -1,    -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,
      -1,   493,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     502,    -1,    -1,    -1,   506,    -1,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   632,   633,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   844,
     845,   310,    -1,    -1,    -1,    -1,   315,    -1,    -1,   318,
      -1,    -1,    -1,   322,   323,    -1,   325,    -1,    -1,   328,
     329,    -1,    -1,   575,    -1,    -1,   578,   579,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,
      -1,   689,    -1,    -1,    -1,    -1,   694,    -1,    -1,    -1,
      -1,    -1,    -1,   701,    -1,    -1,   704,   705,   706,   707,
     708,   709,   710,    -1,   616,   713,    -1,    -1,    -1,    -1,
      -1,    -1,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,   393,   394,    -1,   639,   640,   641,
     642,    -1,    -1,    -1,    -1,    -1,   648,    -1,    -1,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
     449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   719,    -1,   721,
     722,   723,   724,   725,   726,   727,   728,   729,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,   780,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   581,   582,   583,   584,
      -1,    -1,    -1,    -1,   398,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,    -1,    -1,    -1,   430,   431,   432,   433,
     434,   435,   436,   437,    -1,   439,   440,   632,   633,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,   482,   483,
     484,   485,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   689,    -1,   691,    -1,    -1,    -1,
      -1,    -1,   697,    -1,   699,    -1,   701,    -1,    -1,   704,
     705,   706,   707,   708,   709,   710,    -1,    -1,   713,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,
      -1,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,    -1,   572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   595,    -1,    -1,    -1,    -1,    -1,   601
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   403,   404,     0,     3,     4,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   405,   406,   407,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   522,   523,     5,     5,     6,   395,   496,   497,
     522,     5,     7,   500,   502,   500,     8,   503,   506,   500,
     503,   500,   500,   500,   500,   500,   500,   500,   498,   502,
     498,     7,     5,   395,   514,   515,   516,   522,   482,   483,
       5,   484,   522,     5,   485,   519,   520,     5,   522,   522,
       5,   486,     5,   502,   522,   487,     5,     5,   522,   522,
       5,     5,     5,     7,   522,     5,   514,     5,   522,   514,
     514,     5,     5,   502,   488,   407,   408,   500,   500,   500,
       7,     8,   508,   504,   506,   503,   498,   508,   504,   503,
     489,   490,     5,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   498,   500,   503,     5,   507,   509,   522,   498,   498,
     498,   498,   498,   498,   498,   498,   500,   502,   509,   509,
     498,   498,   501,   502,   501,   500,   501,   501,   501,   503,
     503,   500,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   504,   507,   504,   409,   393,   394,     6,     5,   397,
     397,   398,   497,   498,   489,    10,   496,    10,   498,   498,
     498,   498,   498,   498,   489,   489,   489,     7,   514,   397,
     398,   400,   401,     9,   510,   511,   510,   512,   513,   517,
     514,    10,   518,   521,   522,     5,   514,     9,   518,     5,
       5,   517,   514,     5,     5,     5,     7,     5,     5,   517,
     410,   489,   495,   496,   489,   489,   489,   489,   489,   489,
     489,   489,     6,   395,   491,   497,   489,   498,   496,   498,
       5,   498,   494,   496,   498,   495,   498,   498,   498,   498,
     496,   498,   498,   496,   498,   498,   498,   498,   498,   498,
     498,   499,   502,   498,   505,   506,   509,   509,   509,   492,
     493,   499,   492,   499,   492,   499,   492,   499,   492,   499,
     498,   494,   499,   498,   508,   508,   508,   504,   504,   498,
     504,   504,   504,   504,   505,   505,   504,   504,   504,   505,
     504,   505,   410,   514,     5,   497,   497,   396,   496,   499,
     496,   499,   396,   515,   515,   516,   516,   393,   511,   393,
     514,   512,    10,   502,     5,   395,   397,   398,   502,   395,
     397,   496,   499,     5,   499,   494,   495,     5,   499,     5,
     499,   496,   499,   496,   499,   496,   499,   496,   499,   496,
     499,   496,   499,   496,   499,   496,   499,   496,   499,     5,
     509,   496,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   501,     5,   501,   501,   507,   507,   505,   505,   505,
     505,   399,     5,   514,   502,   497,   497,   396,   502,   522,
       5,   506,   399,   396,   395,   395,   396,     5,   502,   502,
     396,   396
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 515 "../CPU/parser.y"
    {parse_error_occurred = false; scanner_start_line (); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 522 "../CPU/parser.y"
    {
		  /* Call outside of cons_label, since an error sets that variable to NULL. */
		  label* l = record_label ((char*)(yyvsp[(1) - (2)]).p,
					   text_dir ? current_text_pc () : current_data_pc (),
					   0);
		  this_line_labels = cons_label (l, this_line_labels);
		  free ((char*)(yyvsp[(1) - (2)]).p);
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 532 "../CPU/parser.y"
    {
		  label *l = record_label ((char*)(yyvsp[(1) - (3)]).p, (mem_addr)(yyvsp[(3) - (3)]).i, 1);
		  free ((char*)(yyvsp[(1) - (3)]).p);

		  l->const_flag = 1;
		  clear_labels ();
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 543 "../CPU/parser.y"
    {
		  clear_labels ();
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 549 "../CPU/parser.y"
    {
		  clear_labels ();
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 559 "../CPU/parser.y"
    {
			LINE_PARSE_DONE;
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 564 "../CPU/parser.y"
    {
		  clear_labels ();
		  FILE_PARSE_DONE;
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 573 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i == Y_LD_POP ? Y_LW_OP : (yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  if ((yyvsp[(1) - (3)]).i == Y_LD_POP)
		    i_type_inst_free (Y_LW_OP,
				      (yyvsp[(2) - (3)]).i + 1,
				      addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
							4));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 589 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 599 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 609 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, 0, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 615 "../CPU/parser.y"
    {
		  if (addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p))
		    i_type_inst (Y_ADDI_OP, (yyvsp[(2) - (3)]).i,
				 addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				 addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  else
		    i_type_inst (Y_ORI_OP, (yyvsp[(2) - (3)]).i, 0,
				 addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 629 "../CPU/parser.y"
    {
		  i_type_inst_free (Y_ORI_OP, (yyvsp[(2) - (3)]).i, 0, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 635 "../CPU/parser.y"
    {
		  int *x = (int *) (yyvsp[(3) - (3)]).p;

		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*x));
		  r_co_type_inst (Y_MTC1_OP, 0, (yyvsp[(2) - (3)]).i, 1);
		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*(x+1)));
		  r_co_type_inst (Y_MTC1_OP, 0, (yyvsp[(2) - (3)]).i + 1, 1);
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 646 "../CPU/parser.y"
    {
		  float x = (float) *((double *) (yyvsp[(3) - (3)]).p);
		  int *y = (int *) &x;

		  i_type_inst (Y_ORI_OP, 1, 0, const_imm_expr (*y));
		  r_co_type_inst (Y_MTC1_OP, 0, (yyvsp[(2) - (3)]).i, 1);
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 656 "../CPU/parser.y"
    {
#ifdef SPIM_BIGENDIAN
		  i_type_inst (Y_LWL_OP, (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  i_type_inst_free (Y_LWR_OP, (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      3));
#else
		  i_type_inst_free (Y_LWL_OP, (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      3));
		  i_type_inst (Y_LWR_OP, (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
#endif
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 680 "../CPU/parser.y"
    {
#ifdef SPIM_BIGENDIAN
		  i_type_inst (((yyvsp[(1) - (3)]).i == Y_ULH_POP ? Y_LB_OP : Y_LBU_OP),
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  i_type_inst_free (Y_LBU_OP, 1,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      1));
#else
		  i_type_inst_free (((yyvsp[(1) - (3)]).i == Y_ULH_POP ? Y_LB_OP : Y_LBU_OP),
				    (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      1));
		  i_type_inst (Y_LBU_OP, 1,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
#endif
		  r_sh_type_inst (Y_SLL_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 8);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 1);
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 708 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 714 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i == Y_SD_POP ? Y_SW_OP : (yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  if ((yyvsp[(1) - (3)]).i == Y_SD_POP)
		    i_type_inst_free (Y_SW_OP, (yyvsp[(2) - (3)]).i + 1,
				      addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				      incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
							4));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 730 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 741 "../CPU/parser.y"
    {
#ifdef SPIM_BIGENDIAN
		  i_type_inst (Y_SWL_OP, (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  i_type_inst_free (Y_SWR_OP, (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      3));
#else
		  i_type_inst_free (Y_SWL_OP, (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      3));
		  i_type_inst (Y_SWR_OP, (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
#endif
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 765 "../CPU/parser.y"
    {
		  i_type_inst (Y_SB_OP, (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));

		  /* ROL SRC, SRC, 8 */
		  r_sh_type_inst (Y_SLL_OP, 1, (yyvsp[(2) - (3)]).i, 24);
		  r_sh_type_inst (Y_SRL_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 8);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 1);

		  i_type_inst_free (Y_SB_OP, (yyvsp[(2) - (3)]).i,
				    addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
				    incr_expr_offset (addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p),
						      1));
		  /* ROR SRC, SRC, 8 */
		  r_sh_type_inst (Y_SRL_OP, 1, (yyvsp[(2) - (3)]).i, 24);
		  r_sh_type_inst (Y_SLL_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 8);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, 1);

		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 790 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (3)]).i,
			       (yyvsp[(2) - (3)]).i,
			       addr_expr_reg ((addr_expr *)(yyvsp[(3) - (3)]).p),
			       addr_expr_imm ((addr_expr *)(yyvsp[(3) - (3)]).p));
		  free (((addr_expr *)(yyvsp[(3) - (3)]).p)->imm);
		  free ((addr_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 801 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 807 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (1)]).i, 0, 0, 0);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 813 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 819 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, 0, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 825 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (1)]).i, 0, 0, 0);
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 831 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (1)]).i, 0, 0, 0);
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 836 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (2)]).i, (yyvsp[(2) - (2)]).i, 0, 0);
		}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 842 "../CPU/parser.y"
    {
		  if ((yyvsp[(2) - (2)]).i == 1)
		    yyerror ("Breakpoint 1 is reserved for debugger");
		  r_type_inst ((yyvsp[(1) - (2)]).i, (yyvsp[(2) - (2)]).i, 0, 0);
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 850 "../CPU/parser.y"
    {
		  nop_inst ();
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 856 "../CPU/parser.y"
    {
		  r_sh_type_inst (Y_SLL_OP, 0, 0, 1); /* SLL r0 r0 1 */
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 862 "../CPU/parser.y"
    {
		  if ((yyvsp[(2) - (3)]).i != (yyvsp[(3) - (3)]).i)
		    r_type_inst (Y_ADDU_OP, (yyvsp[(2) - (3)]).i, 0, (yyvsp[(3) - (3)]).i);

		  i_type_inst_free (Y_BGEZ_OP, 0, (yyvsp[(3) - (3)]).i, branch_offset (2));
		  r_type_inst (Y_SUB_OP, (yyvsp[(2) - (3)]).i, 0, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 872 "../CPU/parser.y"
    {
		  r_type_inst (Y_SUB_OP, (yyvsp[(2) - (3)]).i, 0, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 878 "../CPU/parser.y"
    {
		  r_type_inst (Y_SUBU_OP, (yyvsp[(2) - (3)]).i, 0, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 884 "../CPU/parser.y"
    {
		  r_type_inst (Y_NOR_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, 0);
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 890 "../CPU/parser.y"
    {
		  r_type_inst (Y_ADDU_OP, (yyvsp[(2) - (3)]).i, 0, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 896 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (1)]).i, 0, 0, 0);
		}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 902 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 908 "../CPU/parser.y"
    {
		  /* RT must be equal to RD */
		  r_type_inst ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, (yyvsp[(2) - (3)]).i);
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 915 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 921 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 926 "../CPU/parser.y"
    {
		  i_type_inst_free (op_to_imm_op ((yyvsp[(1) - (4)]).i), (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i,
				    (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 932 "../CPU/parser.y"
    {
		  i_type_inst_free (op_to_imm_op ((yyvsp[(1) - (3)]).i), (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i,
				    (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 939 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(4) - (4)]).i, (yyvsp[(3) - (4)]).i);
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 944 "../CPU/parser.y"
    {
		  r_sh_type_inst (op_to_imm_op ((yyvsp[(1) - (4)]).i), (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 949 "../CPU/parser.y"
    {
		  r_sh_type_inst (op_to_imm_op ((yyvsp[(1) - (3)]).i), (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 955 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 960 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 966 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 971 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(2) - (3)]).i, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 977 "../CPU/parser.y"
    {
		  if (((yyvsp[(4) - (4)]).i < 0) || (31 < (yyvsp[(4) - (4)]).i))
		    yywarn ("Shift distance can only be in the range 0..31");
		  r_sh_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 984 "../CPU/parser.y"
    {
		  r_type_inst (imm_op_to_op ((yyvsp[(1) - (4)]).i), (yyvsp[(2) - (4)]).i, (yyvsp[(4) - (4)]).i, (yyvsp[(3) - (4)]).i);
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 990 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 995 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1001 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 1006 "../CPU/parser.y"
    {
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (!is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
			/* Use $at */
			i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		      r_type_inst ((yyvsp[(1) - (4)]).i,
				   (yyvsp[(2) - (4)]).i,
				   (yyvsp[(3) - (4)]).i,
				   (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p) ? 0 : 1));
		    }
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1023 "../CPU/parser.y"
    {
		  check_uimm_range ((imm_expr *)(yyvsp[(3) - (3)]).p, UIMM_MIN, UIMM_MAX);
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (!is_zero_imm ((imm_expr *)(yyvsp[(3) - (3)]).p))
			/* Use $at */
			i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(3) - (3)]).p);
		      r_type_inst ((yyvsp[(1) - (3)]).i,
				   (yyvsp[(2) - (3)]).i,
				   (yyvsp[(2) - (3)]).i,
				   (is_zero_imm ((imm_expr *)(yyvsp[(3) - (3)]).p) ? 0 : 1));
		    }
		  free ((imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1042 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1048 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1053 "../CPU/parser.y"
    {
		  int val = eval_imm_expr ((imm_expr *)(yyvsp[(4) - (4)]).p);

		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    i_type_inst ((yyvsp[(1) - (4)]).i == Y_SUB_OP ? Y_ADDI_OP
				 : (yyvsp[(1) - (4)]).i == Y_SUBU_OP ? Y_ADDIU_OP
				 : (fatal_error ("Bad SUB_OP\n"), 0),
				 (yyvsp[(2) - (4)]).i,
				 (yyvsp[(3) - (4)]).i,
				 make_imm_expr (-val, NULL, false));
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1069 "../CPU/parser.y"
    {
		  int val = eval_imm_expr ((imm_expr *)(yyvsp[(3) - (3)]).p);

		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    i_type_inst ((yyvsp[(1) - (3)]).i == Y_SUB_OP ? Y_ADDI_OP
				 : (yyvsp[(1) - (3)]).i == Y_SUBU_OP ? Y_ADDIU_OP
				 : (fatal_error ("Bad SUB_OP\n"), 0),
				 (yyvsp[(2) - (3)]).i,
				 (yyvsp[(2) - (3)]).i,
				 make_imm_expr (-val, NULL, false));
		  free ((imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1086 "../CPU/parser.y"
    {
		  /* The hardware divide operation (ignore 1st arg) */
		  if ((yyvsp[(1) - (3)]).i != Y_DIV_OP && (yyvsp[(1) - (3)]).i != Y_DIVU_OP)
		    yyerror ("REM requires 3 arguments");
		  else
		    r_type_inst ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1095 "../CPU/parser.y"
    {
		  /* Pseudo divide operations */
		  div_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i, 0);
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1101 "../CPU/parser.y"
    {
		  if (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    yyerror ("Divide by zero");
		  else
		    {
		      /* Use $at */
		      i_type_inst_free (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		      div_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, 1, 1);
		    }
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1114 "../CPU/parser.y"
    {
		  mult_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1119 "../CPU/parser.y"
    {
		  if (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    /* Optimize: n * 0 == 0 */
		    i_type_inst_free (Y_ORI_OP, (yyvsp[(2) - (4)]).i, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  else
		    {
		      /* Use $at */
		      i_type_inst_free (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		      mult_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, 1);
		    }
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1133 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1139 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1144 "../CPU/parser.y"
    {
		  /* Special case, for backward compatibility with pseudo-op
		     MULT instruction */
		  i_type_inst_free (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p); /* Use $at */
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, 1);
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1153 "../CPU/parser.y"
    {
		  r_type_inst (Y_SUBU_OP, 1, 0, (yyvsp[(4) - (4)]).i);
		  r_type_inst (Y_SLLV_OP, 1, 1, (yyvsp[(3) - (4)]).i);
		  r_type_inst (Y_SRLV_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(4) - (4)]).i, (yyvsp[(3) - (4)]).i);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(2) - (4)]).i, 1);
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1162 "../CPU/parser.y"
    {
		  r_type_inst (Y_SUBU_OP, 1, 0, (yyvsp[(4) - (4)]).i);
		  r_type_inst (Y_SRLV_OP, 1, 1, (yyvsp[(3) - (4)]).i);
		  r_type_inst (Y_SLLV_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(4) - (4)]).i, (yyvsp[(3) - (4)]).i);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(2) - (4)]).i, 1);
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1171 "../CPU/parser.y"
    {
		  long dist = eval_imm_expr ((imm_expr *)(yyvsp[(4) - (4)]).p);

		  check_imm_range ((imm_expr *)(yyvsp[(4) - (4)]).p, 0, 31);
		  r_sh_type_inst (Y_SLL_OP, 1, (yyvsp[(3) - (4)]).i, -dist);
		  r_sh_type_inst (Y_SRL_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, dist);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(2) - (4)]).i, 1);
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1183 "../CPU/parser.y"
    {
		  long dist = eval_imm_expr ((imm_expr *)(yyvsp[(4) - (4)]).p);

		  check_imm_range ((imm_expr *)(yyvsp[(4) - (4)]).p, 0, 31);
		  r_sh_type_inst (Y_SRL_OP, 1, (yyvsp[(3) - (4)]).i, -dist);
		  r_sh_type_inst (Y_SLL_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, dist);
		  r_type_inst (Y_OR_OP, (yyvsp[(2) - (4)]).i, (yyvsp[(2) - (4)]).i, 1);
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1195 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1201 "../CPU/parser.y"
    {
		  set_le_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1206 "../CPU/parser.y"
    {
		  if (!is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  set_le_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i,
			       (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p) ? 0 : 1));
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1217 "../CPU/parser.y"
    {
		  set_gt_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1222 "../CPU/parser.y"
    {
		  if (!is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  set_gt_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i,
			       (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p) ? 0 : 1));
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1234 "../CPU/parser.y"
    {
		  set_ge_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1239 "../CPU/parser.y"
    {
		  if (!is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  set_ge_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i,
			       (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p) ? 0 : 1));
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1250 "../CPU/parser.y"
    {
		  set_eq_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1255 "../CPU/parser.y"
    {
		  if (!is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p))
		    /* Use $at */
		    i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  set_eq_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i,
			       (is_zero_imm ((imm_expr *)(yyvsp[(4) - (4)]).p) ? 0 : 1));
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1266 "../CPU/parser.y"
    {
		  /* RS and RT fields contain information on test */
                  int nd = opcode_is_nullified_branch ((yyvsp[(1) - (2)]).i) ? 1 : 0;
                  int tf = opcode_is_true_branch ((yyvsp[(1) - (2)]).i) ? 1 : 0;
		  i_type_inst_free ((yyvsp[(1) - (2)]).i,
				    cc_to_rt (0, nd, tf),
				    BIN_RS ((yyvsp[(1) - (2)]).i),
				    (imm_expr *)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1277 "../CPU/parser.y"
    {
		  /* RS and RT fields contain information on test */
                  int nd = opcode_is_nullified_branch ((yyvsp[(1) - (3)]).i) ? 1 : 0;
                  int tf = opcode_is_true_branch ((yyvsp[(1) - (3)]).i) ? 1 : 0;
		  i_type_inst_free ((yyvsp[(1) - (3)]).i,
				    cc_to_rt ((yyvsp[(2) - (3)]).i, nd, tf),
				    BIN_RS ((yyvsp[(1) - (3)]).i),
				    (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1289 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(2) - (3)]).i, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1295 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i == Y_BEQZ_POP ? Y_BEQ_OP : Y_BNE_OP,
			       0, (yyvsp[(2) - (3)]).i, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1302 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(2) - (4)]).i, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1307 "../CPU/parser.y"
    {
		  if (bare_machine && !accept_pseudo_insts)
		    yyerror ("Immediate form not allowed in bare machine");
		  else
		    {
		      if (is_zero_imm ((imm_expr *)(yyvsp[(3) - (4)]).p))
			i_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i,
				     (is_zero_imm ((imm_expr *)(yyvsp[(3) - (4)]).p) ? 0 : 1),
				     (imm_expr *)(yyvsp[(4) - (4)]).p);
		      else
			{
			  /* Use $at */
			  i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(3) - (4)]).p);
			  i_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i,
				       (is_zero_imm ((imm_expr *)(yyvsp[(3) - (4)]).p) ? 0 : 1),
				       (imm_expr *)(yyvsp[(4) - (4)]).p);
			}
		    }
		  free ((imm_expr *)(yyvsp[(3) - (4)]).p);
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1331 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i == Y_BGT_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, (yyvsp[(3) - (4)]).i, (yyvsp[(2) - (4)]).i); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1338 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (4)]).i == Y_BGT_POP)
		    {
		      /* Use $at */
		      i_type_inst_free (Y_SLTI_OP, 1, (yyvsp[(2) - (4)]).i,
					incr_expr_offset ((imm_expr *)(yyvsp[(3) - (4)]).p, 1));
		      i_type_inst (Y_BEQ_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		    }
		  else
		    {
		      /* Use $at */
		      /* Can't add 1 to immediate since 0xffffffff+1 = 0 < 1 */
		      i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(3) - (4)]).p);
		      i_type_inst_free (Y_BEQ_OP, (yyvsp[(2) - (4)]).i, 1, branch_offset (3));
		      r_type_inst (Y_SLTU_OP, 1, (yyvsp[(2) - (4)]).i, 1);
		      i_type_inst (Y_BEQ_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		    }
		  free ((imm_expr *)(yyvsp[(3) - (4)]).p);
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1361 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i == Y_BGE_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1368 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (4)]).i == Y_BGE_POP ? Y_SLTI_OP : Y_SLTIU_OP,
			       1, (yyvsp[(2) - (4)]).i, (imm_expr *)(yyvsp[(3) - (4)]).p); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  free ((imm_expr *)(yyvsp[(3) - (4)]).p);
		}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1377 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i == Y_BLT_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1384 "../CPU/parser.y"
    {
		  i_type_inst ((yyvsp[(1) - (4)]).i == Y_BLT_POP ? Y_SLTI_OP : Y_SLTIU_OP,
			       1, (yyvsp[(2) - (4)]).i, (imm_expr *)(yyvsp[(3) - (4)]).p); /* Use $at */
		  i_type_inst_free (Y_BNE_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		  free ((imm_expr *)(yyvsp[(3) - (4)]).p);
		}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1393 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i == Y_BLE_POP ? Y_SLT_OP : Y_SLTU_OP,
			       1, (yyvsp[(3) - (4)]).i, (yyvsp[(2) - (4)]).i); /* Use $at */
		  i_type_inst_free (Y_BEQ_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1400 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (4)]).i == Y_BLE_POP)
		    {
		      /* Use $at */
		      i_type_inst_free (Y_SLTI_OP, 1, (yyvsp[(2) - (4)]).i,
					incr_expr_offset ((imm_expr *)(yyvsp[(3) - (4)]).p, 1));
		      i_type_inst (Y_BNE_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		    }
		  else
		    {
		      /* Use $at */
		      /* Can't add 1 to immediate since 0xffffffff+1 = 0 < 1 */
		      i_type_inst (Y_ORI_OP, 1, 0, (imm_expr *)(yyvsp[(3) - (4)]).p);
		      i_type_inst (Y_BEQ_OP, (yyvsp[(2) - (4)]).i, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		      r_type_inst (Y_SLTU_OP, 1, (yyvsp[(2) - (4)]).i, 1);
		      i_type_inst (Y_BNE_OP, 0, 1, (imm_expr *)(yyvsp[(4) - (4)]).p);
		    }
		  free ((imm_expr *)(yyvsp[(3) - (4)]).p);
		  free ((imm_expr *)(yyvsp[(4) - (4)]).p);
		}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1423 "../CPU/parser.y"
    {
		  if (((yyvsp[(1) - (2)]).i == Y_J_OP) || ((yyvsp[(1) - (2)]).i == Y_JR_OP))
		    j_type_inst (Y_J_OP, (imm_expr *)(yyvsp[(2) - (2)]).p);
		  else if (((yyvsp[(1) - (2)]).i == Y_JAL_OP) || ((yyvsp[(1) - (2)]).i == Y_JALR_OP))
		    j_type_inst (Y_JAL_OP, (imm_expr *)(yyvsp[(2) - (2)]).p);
		  free ((imm_expr *)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1432 "../CPU/parser.y"
    {
		  if (((yyvsp[(1) - (2)]).i == Y_J_OP) || ((yyvsp[(1) - (2)]).i == Y_JR_OP))
		    r_type_inst (Y_JR_OP, 0, (yyvsp[(2) - (2)]).i, 0);
		  else if (((yyvsp[(1) - (2)]).i == Y_JAL_OP) || ((yyvsp[(1) - (2)]).i == Y_JALR_OP))
		    r_type_inst (Y_JALR_OP, 31, (yyvsp[(2) - (2)]).i, 0);
		}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1440 "../CPU/parser.y"
    {
		  if (((yyvsp[(1) - (3)]).i == Y_J_OP) || ((yyvsp[(1) - (3)]).i == Y_JR_OP))
		    r_type_inst (Y_JR_OP, 0, (yyvsp[(3) - (3)]).i, 0);
		  else if (((yyvsp[(1) - (3)]).i == Y_JAL_OP) || ((yyvsp[(1) - (3)]).i == Y_JALR_OP))
		    r_type_inst (Y_JALR_OP, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, 0);
		}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1449 "../CPU/parser.y"
    {
		  i_type_inst_free (((yyvsp[(1) - (2)]).i == Y_BAL_POP ? Y_BGEZAL_OP : Y_BGEZ_OP),
				    0, 0, (imm_expr *)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1456 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(2) - (3)]).i, (imm_expr *)(yyvsp[(3) - (3)]).p);
		}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1462 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1468 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, 0);
		}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1474 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1480 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1486 "../CPU/parser.y"
    {
                    r_type_inst ((yyvsp[(1) - (4)]).i,
                                 (yyvsp[(2) - (4)]).i,
                                 (yyvsp[(3) - (4)]).i,
                                 (((yyvsp[(4) - (4)]).i & 0x7) << 2));
		}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1495 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1501 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1507 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, cc_to_rt (0, 0, 0));
		}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1513 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, cc_to_rt ((yyvsp[(4) - (4)]).i, 0, 0));
		}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1519 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1525 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (2)]).i, (yyvsp[(2) - (2)]).i, 0, 0);
		}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1531 "../CPU/parser.y"
    {
		  r_type_inst ((yyvsp[(1) - (2)]).i, 0, (yyvsp[(2) - (2)]).i, 0);
		}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1538 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (3)]).i == Y_MFC1_D_POP)
		    {
		      r_co_type_inst (Y_MFC1_OP, 0, (yyvsp[(3) - (3)]).i, (yyvsp[(2) - (3)]).i);
		      r_co_type_inst (Y_MFC1_OP, 0, (yyvsp[(3) - (3)]).i + 1, (yyvsp[(2) - (3)]).i + 1);
		    }
		  else if ((yyvsp[(1) - (3)]).i == Y_MTC1_D_POP)
		    {
		      r_co_type_inst (Y_MTC1_OP, 0, (yyvsp[(3) - (3)]).i, (yyvsp[(2) - (3)]).i);
		      r_co_type_inst (Y_MTC1_OP, 0, (yyvsp[(3) - (3)]).i + 1, (yyvsp[(2) - (3)]).i + 1);
		    }
		  else
		    r_co_type_inst ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(3) - (3)]).i, (yyvsp[(2) - (3)]).i);
		}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1555 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1561 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (3)]).i, 0, (yyvsp[(3) - (3)]).i, (yyvsp[(2) - (3)]).i);
		}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1567 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, 0);
		}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1573 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1579 "../CPU/parser.y"
    {
		  r_co_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(2) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i);
		}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1585 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1591 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1597 "../CPU/parser.y"
    {
		  r_cond_type_inst ((yyvsp[(1) - (3)]).i, (yyvsp[(2) - (3)]).i, (yyvsp[(3) - (3)]).i, 0);
		}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1603 "../CPU/parser.y"
    {
		  r_cond_type_inst ((yyvsp[(1) - (4)]).i, (yyvsp[(3) - (4)]).i, (yyvsp[(4) - (4)]).i, (yyvsp[(2) - (4)]).i);
		}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1609 "../CPU/parser.y"
    {
		  mips32_r2_inst ();
		}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1615 "../CPU/parser.y"
    {
		  i_type_inst_free ((yyvsp[(1) - (2)]).i, 0, 0, (imm_expr *)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1647 "../CPU/parser.y"
    { (yyval).i = Y_LDC1_OP; }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1648 "../CPU/parser.y"
    { (yyval).i = Y_LWC1_OP; }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1667 "../CPU/parser.y"
    { (yyval).i = Y_SDC1_OP; }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1668 "../CPU/parser.y"
    { (yyval).i = Y_SWC1_OP; }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1681 "../CPU/parser.y"
    {
#ifdef MIPS1
			yywarn ("RFE should only be used when SPIM is compiled as a MIPS-I processor");
#endif
		}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1704 "../CPU/parser.y"
    {
#ifdef MIPS1
			yywarn ("ERET should only be used when SPIM is compiled as a MIPS32 processor");
#endif
		}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1870 "../CPU/parser.y"
    { yywarn ("Warning:IPS32 Rev 2 '.HB' extension is not implemented and is ignored"); }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1873 "../CPU/parser.y"
    { yywarn ("Warning:IPS32 Rev 2 '.HB' extension is not implemented and is ignored"); }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 2105 "../CPU/parser.y"
    {
		  align_data ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 2109 "../CPU/parser.y"
    {null_term = false;}
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 2110 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 2115 "../CPU/parser.y"
    {null_term = true;}
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 2116 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 2128 "../CPU/parser.y"
    {store_op = (void(*)(void*))store_byte;}
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 2130 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 2137 "../CPU/parser.y"
    {
		  align_data (2);
		  if (lookup_label ((char*)(yyvsp[(2) - (3)]).p)->addr == 0)
		  {
		    (void)record_label ((char*)(yyvsp[(2) - (3)]).p, current_data_pc (), 1);
		    free ((char*)(yyvsp[(2) - (3)]).p);
		  }
		  increment_data_pc ((yyvsp[(3) - (3)]).i);
		}
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 2149 "../CPU/parser.y"
    {user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		}
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 2155 "../CPU/parser.y"
    {
		  user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		  set_data_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 2164 "../CPU/parser.y"
    {
                    user_kernel_data_segment (true);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		}
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 2171 "../CPU/parser.y"
    {
                    user_kernel_data_segment (true);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		  set_data_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 2180 "../CPU/parser.y"
    {
		  store_op = (void(*)(void*))store_double;
		  if (data_dir) set_data_alignment (3);
		}
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 2185 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 2203 "../CPU/parser.y"
    {
		  extern_directive ((char*)(yyvsp[(2) - (3)]).p, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 2209 "../CPU/parser.y"
    {
		  fatal_error ("File contains an .err directive\n");
		}
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 2218 "../CPU/parser.y"
    {
		  store_op = (void(*)(void*))store_float;
		  if (data_dir) set_data_alignment (2);
		}
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 2223 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2235 "../CPU/parser.y"
    {
		  (void)make_label_global ((char*)(yyvsp[(2) - (2)]).p);
		  free ((char*)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2242 "../CPU/parser.y"
    {
		  store_op = (void(*)(void*))store_half;
		  if (data_dir) set_data_alignment (1);
		}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2247 "../CPU/parser.y"
    {
		  if (text_dir)
		    yyerror ("Can't put data in text segment");
		}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2254 "../CPU/parser.y"
    {
		  (void)record_label ((char*)(yyvsp[(2) - (2)]).p,
				      text_dir ? current_text_pc () : current_data_pc (),
				      1);
		  free ((char*)(yyvsp[(2) - (2)]).p);
		}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2263 "../CPU/parser.y"
    {
		  lcomm_directive ((char*)(yyvsp[(2) - (3)]).p, (yyvsp[(3) - (3)]).i);
		}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2281 "../CPU/parser.y"
    {
		  yyerror ("Warning: repeat directive ignored");
		}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2287 "../CPU/parser.y"
    {
		  user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2294 "../CPU/parser.y"
    {
		  user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		  set_data_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2303 "../CPU/parser.y"
    {
		  user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2310 "../CPU/parser.y"
    {
		  user_kernel_data_segment (false);
		  data_dir = true; text_dir = false;
		  enable_data_alignment ();
		  set_data_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2319 "../CPU/parser.y"
    {
		  if (streq ((char*)(yyvsp[(2) - (2)]).p, "noat"))
		    noat_flag = true;
		  else if (streq ((char*)(yyvsp[(2) - (2)]).p, "at"))
		    noat_flag = false;
		}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2328 "../CPU/parser.y"
    {
		  if (data_dir)
		    increment_data_pc ((yyvsp[(2) - (2)]).i);
		  else if (text_dir)
		    increment_text_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2337 "../CPU/parser.y"
    {
		  yyerror ("Warning: struct directive ignored");
		}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2343 "../CPU/parser.y"
    {
		  user_kernel_text_segment (false);
		  data_dir = false; text_dir = true;
		  enable_data_alignment ();
		}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2350 "../CPU/parser.y"
    {
		  user_kernel_text_segment (false);
		  data_dir = false; text_dir = true;
		  enable_data_alignment ();
		  set_text_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2359 "../CPU/parser.y"
    {
		  user_kernel_text_segment (true);
		  data_dir = false; text_dir = true;
		  enable_data_alignment ();
		}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2366 "../CPU/parser.y"
    {
		  user_kernel_text_segment (true);
		  data_dir = false; text_dir = true;
		  enable_data_alignment ();
		  set_text_pc ((yyvsp[(2) - (2)]).i);
		}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2380 "../CPU/parser.y"
    {
		  store_op = (void(*)(void*))store_word_data;
		  if (data_dir) set_data_alignment (2);
		}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2390 "../CPU/parser.y"
    {only_id = 1;}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2390 "../CPU/parser.y"
    {only_id = 0; (yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2393 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr (0, NULL, (yyvsp[(2) - (3)]).i);
		}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2398 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr ((yyvsp[(1) - (1)]).i, NULL, 0);
		}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2403 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr ((yyvsp[(1) - (4)]).i, NULL, (yyvsp[(3) - (4)]).i);
		}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2408 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr (0, (char*)(yyvsp[(1) - (1)]).p, 0);
		  free ((char*)(yyvsp[(1) - (1)]).p);
		}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2414 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr (0, (char*)(yyvsp[(1) - (4)]).p, (yyvsp[(3) - (4)]).i);
		  free ((char*)(yyvsp[(1) - (4)]).p);
		}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2420 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr ((yyvsp[(3) - (3)]).i, (char*)(yyvsp[(1) - (3)]).p, 0);
		  free ((char*)(yyvsp[(1) - (3)]).p);
		}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2426 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr ((yyvsp[(1) - (3)]).i, (char*)(yyvsp[(3) - (3)]).p, 0);
		}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2431 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr (- (yyvsp[(3) - (3)]).i, (char*)(yyvsp[(1) - (3)]).p, 0);
		  free ((char*)(yyvsp[(1) - (3)]).p);
		}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2437 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr ((yyvsp[(3) - (6)]).i, (char*)(yyvsp[(1) - (6)]).p, (yyvsp[(5) - (6)]).i);
		  free ((char*)(yyvsp[(1) - (6)]).p);
		}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2443 "../CPU/parser.y"
    {
		  (yyval).p = make_addr_expr (- (yyvsp[(3) - (6)]).i, (char*)(yyvsp[(1) - (6)]).p, (yyvsp[(5) - (6)]).i);
		  free ((char*)(yyvsp[(1) - (6)]).p);
		}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2450 "../CPU/parser.y"
    {only_id = 1;}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2450 "../CPU/parser.y"
    {only_id = 0; (yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2453 "../CPU/parser.y"
    {
                  check_imm_range ((imm_expr*)(yyvsp[(1) - (1)]).p, IMM_MIN, IMM_MAX);
		  (yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2459 "../CPU/parser.y"
    {
                  check_uimm_range ((imm_expr*)(yyvsp[(1) - (1)]).p, UIMM_MIN, UIMM_MAX);
		  (yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2466 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr ((yyvsp[(1) - (1)]).i, NULL, false);
		}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2471 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr ((yyvsp[(2) - (6)]).i >> (yyvsp[(6) - (6)]).i, NULL, false);
		}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2476 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr (0, (char*)(yyvsp[(1) - (1)]).p, false);
		}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2481 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr ((yyvsp[(3) - (3)]).i, (char*)(yyvsp[(1) - (3)]).p, false);
		  free ((char*)(yyvsp[(1) - (3)]).p);
		}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2487 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr (- (yyvsp[(3) - (3)]).i, (char*)(yyvsp[(1) - (3)]).p, false);
		  free ((char*)(yyvsp[(1) - (3)]).p);
		}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2497 "../CPU/parser.y"
    {(yyval).i = (yyvsp[(1) - (3)]).i + (yyvsp[(3) - (3)]).i;}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2500 "../CPU/parser.y"
    {
		  /* This is actually: Y_INT '-' Y_INT, since the binary
		     subtract operator gets scanned as a unary negation
		     operator. */
		  if ((yyvsp[(2) - (2)]).i >= 0) yyerror ("Syntax error");
		  (yyval).i = (yyvsp[(1) - (2)]).i - -(yyvsp[(2) - (2)]).i;
		}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2518 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (1)]).i < 0 || (yyvsp[(1) - (1)]).i > 31)
		    yyerror ("Register number out of range");
		  if ((yyvsp[(1) - (1)]).i == 1 && !bare_machine && !noat_flag)
		    yyerror ("Register 1 is reserved for assembler");
		  (yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2533 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (1)]).i < 0 || (yyvsp[(1) - (1)]).i > 31)
		    yyerror ("FP register number out of range");
		  (yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2541 "../CPU/parser.y"
    {
		  if ((yyvsp[(1) - (1)]).i < 0 || (yyvsp[(1) - (1)]).i > 7)
		    yyerror ("CC register number out of range");
		  (yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2556 "../CPU/parser.y"
    {
		  (yyval).p = make_imm_expr (-(int)current_text_pc (), (char*)(yyvsp[(1) - (1)]).p, true);
		}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2567 "../CPU/parser.y"
    {
		  store_string ((char*)(yyvsp[(1) - (1)]).p, strlen((char*)(yyvsp[(1) - (1)]).p), null_term);
		  free ((char*)(yyvsp[(1) - (1)]).p);
		}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2572 "../CPU/parser.y"
    {
		  int i;

		  for (i = 0; i < (yyvsp[(3) - (3)]).i; i ++)
		    store_string ((char*)(yyvsp[(1) - (3)]).p, strlen((char*)(yyvsp[(1) - (3)]).p), null_term);
		  free ((char*)(yyvsp[(1) - (3)]).p);
		}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2582 "../CPU/parser.y"
    {only_id = 1;}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2582 "../CPU/parser.y"
    {only_id = 0; (yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2588 "../CPU/parser.y"
    { (yyval).i =  (yyvsp[(1) - (3)]).i + (yyvsp[(3) - (3)]).i; }
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2591 "../CPU/parser.y"
    { (yyval).i =  (yyvsp[(1) - (3)]).i - (yyvsp[(3) - (3)]).i; }
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 2598 "../CPU/parser.y"
    { (yyval).i = (yyvsp[(1) - (3)]).i * (yyvsp[(3) - (3)]).i; }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 2601 "../CPU/parser.y"
    { (yyval).i = (yyvsp[(1) - (3)]).i / (yyvsp[(3) - (3)]).i; }
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2607 "../CPU/parser.y"
    { (yyval).i = (yyvsp[(2) - (3)]).i; }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2610 "../CPU/parser.y"
    {
		  label *l = lookup_label ((char*)(yyvsp[(1) - (1)]).p);
  		  if (l->addr == 0)
                    {
                      record_data_uses_symbol (current_data_pc (), l);
                      (yyval).p = NULL;
                    }
                  else
                    (yyval).i = l->addr;
		}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2623 "../CPU/parser.y"
    {
		  store_op ((yyvsp[(2) - (2)]).p);
		}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2627 "../CPU/parser.y"
    {
		  store_op ((yyvsp[(1) - (1)]).p);
		}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2631 "../CPU/parser.y"
    {
		  int i;

		  for (i = 0; i < (yyvsp[(3) - (3)]).i; i ++)
		    store_op ((yyvsp[(1) - (3)]).p);
		}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 2641 "../CPU/parser.y"
    {
		  store_op ((yyvsp[(2) - (2)]).p);
		}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 2645 "../CPU/parser.y"
    {
		  store_op ((yyvsp[(1) - (1)]).p);
		}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 2651 "../CPU/parser.y"
    {only_id = 1;}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 2651 "../CPU/parser.y"
    {only_id = 0; (yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 2654 "../CPU/parser.y"
    {(yyval).p = (void*)NULL;}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 2658 "../CPU/parser.y"
    {only_id = 1;}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 2658 "../CPU/parser.y"
    {only_id = 0; (yyval) = (yyvsp[(2) - (2)]);}
    break;



/* Line 1806 of yacc.c  */
#line 5285 "parser_yacc.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 2661 "../CPU/parser.y"


/* Maintain and update the address of labels for the current line. */

void
fix_current_label_address (mem_addr new_addr)
{
  label_list *l;

  for (l = this_line_labels; l != NULL; l = l->tail)
    {
      l->head->addr = new_addr;
    }
  clear_labels ();
}


static label_list *
cons_label (label *head, label_list *tail)
{
  label_list *c = (label_list *) malloc (sizeof (label_list));

  c->head = head;
  c->tail = tail;
  return (c);
}


static void
clear_labels ()
{
  label_list *n;

  for ( ; this_line_labels != NULL; this_line_labels = n)
    {
      resolve_label_uses (this_line_labels->head);
      n = this_line_labels->tail;
      free (this_line_labels);
    }
    this_line_labels = NULL;
}


/* Operations on op codes. */

int
op_to_imm_op (int opcode)
{
  switch (opcode)
    {
    case Y_ADD_OP: return (Y_ADDI_OP);
    case Y_ADDU_OP: return (Y_ADDIU_OP);
    case Y_AND_OP: return (Y_ANDI_OP);
    case Y_OR_OP: return (Y_ORI_OP);
    case Y_XOR_OP: return (Y_XORI_OP);
    case Y_SLT_OP: return (Y_SLTI_OP);
    case Y_SLTU_OP: return (Y_SLTIU_OP);
    case Y_SLLV_OP: return (Y_SLL_OP);
    case Y_SRAV_OP: return (Y_SRA_OP);
    case Y_SRLV_OP: return (Y_SRL_OP);
    default: fatal_error ("Can't convert op to immediate op\n"); return (0);
    }
}


int
imm_op_to_op (int opcode)
{
  switch (opcode)
    {
    case Y_ADDI_OP: return (Y_ADD_OP);
    case Y_ADDIU_OP: return (Y_ADDU_OP);
    case Y_ANDI_OP: return (Y_AND_OP);
    case Y_ORI_OP: return (Y_OR_OP);
    case Y_XORI_OP: return (Y_XOR_OP);
    case Y_SLTI_OP: return (Y_SLT_OP);
    case Y_SLTIU_OP: return (Y_SLTU_OP);
    case Y_J_OP: return (Y_JR_OP);
    case Y_LUI_OP: return (Y_ADDU_OP);
    case Y_SLL_OP: return (Y_SLLV_OP);
    case Y_SRA_OP: return (Y_SRAV_OP);
    case Y_SRL_OP: return (Y_SRLV_OP);
    default: fatal_error ("Can't convert immediate op to op\n"); return (0);
    }
}


static void
nop_inst ()
{
  r_type_inst (Y_SLL_OP, 0, 0, 0); /* = 0 */
}


static void
trap_inst ()
{
  r_type_inst (Y_BREAK_OP, 0, 0, 0);
}


static imm_expr *
branch_offset (int n_inst)
{
  return (const_imm_expr (n_inst << 2)); /* Later shifted right 2 places */
}


static void
div_inst (int op, int rd, int rs, int rt, int const_divisor)
{
  if (rd != 0 && !const_divisor)
    {
      i_type_inst_free (Y_BNE_OP, 0, rt, branch_offset (2));
      trap_inst ();
    }

  if (op == Y_DIV_OP || op == Y_REM_POP)
    r_type_inst (Y_DIV_OP, 0, rs, rt);
  else
    r_type_inst (Y_DIVU_OP, 0, rs, rt);

  if (rd != 0)
    {
      if (op == Y_DIV_OP || op == Y_DIVU_OP)
	/* Quotient */
	r_type_inst (Y_MFLO_OP, rd, 0, 0);
      else
	/* Remainder */
	r_type_inst (Y_MFHI_OP, rd, 0, 0);
    }
}


static void
mult_inst (int op, int rd, int rs, int rt)
{
  if (op == Y_MULOU_POP)
    r_type_inst (Y_MULTU_OP, 0, rs, rt);
  else
    r_type_inst (Y_MULT_OP, 0, rs, rt);
  if (op == Y_MULOU_POP && rd != 0)
    {
      r_type_inst (Y_MFHI_OP, 1, 0, 0);	/* Use $at */
      i_type_inst_free (Y_BEQ_OP, 0, 1, branch_offset (2));
      trap_inst ();
    }
  else if (op == Y_MULO_POP && rd != 0)
    {
      r_type_inst (Y_MFHI_OP, 1, 0, 0); /* use $at */
      r_type_inst (Y_MFLO_OP, rd, 0, 0);
      r_sh_type_inst (Y_SRA_OP, rd, rd, 31);
      i_type_inst_free (Y_BEQ_OP, rd, 1, branch_offset (2));
      trap_inst ();
    }
  if (rd != 0)
    r_type_inst (Y_MFLO_OP, rd, 0, 0);
}


static void
set_le_inst (int op, int rd, int rs, int rt)
{
  i_type_inst_free (Y_BNE_OP, rs, rt, branch_offset (3));
  i_type_inst_free (Y_ORI_OP, rd, 0, const_imm_expr (1));
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2));
  r_type_inst ((op == Y_SLE_POP ? Y_SLT_OP : Y_SLTU_OP), rd, rs, rt);
}


static void
set_gt_inst (int op, int rd, int rs, int rt)
{
  r_type_inst (op == Y_SGT_POP ? Y_SLT_OP : Y_SLTU_OP, rd, rt, rs);
}


static void
set_ge_inst (int op, int rd, int rs, int rt)
{
  i_type_inst_free (Y_BNE_OP, rs, rt, branch_offset (3));
  i_type_inst_free (Y_ORI_OP, rd, 0, const_imm_expr (1));
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2));
  r_type_inst (op == Y_SGE_POP ? Y_SLT_OP : Y_SLTU_OP, rd, rt, rs);
}


static void
set_eq_inst (int op, int rd, int rs, int rt)
{
  imm_expr *if_eq, *if_neq;

  if (op == Y_SEQ_POP)
    if_eq = const_imm_expr (1), if_neq = const_imm_expr (0);
  else
    if_eq = const_imm_expr (0), if_neq = const_imm_expr (1);

  i_type_inst_free (Y_BEQ_OP, rs, rt, branch_offset (3));
  /* RD <- 0 (if not equal) */
  i_type_inst_free (Y_ORI_OP, rd, 0, if_neq);
  i_type_inst_free (Y_BEQ_OP, 0, 0, branch_offset (2)); /* Branch always */
  /* RD <- 1 */
  i_type_inst_free (Y_ORI_OP, rd, 0, if_eq);
}


/* Store the value either as a datum or instruction. */

static void
store_word_data (int value)
{
  if (data_dir)
    store_word (value);
  else if (text_dir)
    store_instruction (inst_decode (value));
}



void
initialize_parser (char *file_name)
{
  input_file_name = file_name;
  only_id = 0;
  data_dir = false;
  text_dir = true;
}


static void
check_imm_range (imm_expr* expr, int32 min, int32 max)
{
  if (expr->symbol == NULL || SYMBOL_IS_DEFINED (expr->symbol))
    {
      /* If expression can be evaluated, compare its value against the limits
	 and complain if the value is out of bounds. */
      int32 value = eval_imm_expr (expr);

      if (value < min || max < value)
	{
	  char str[200];
	  sprintf (str, "immediate value (%d) out of range (%d .. %d)",
		   value, min, max);
	  yywarn (str);
	}
    }
}


static void
check_uimm_range (imm_expr* expr, uint32 min, uint32 max)
{
  if (expr->symbol == NULL || SYMBOL_IS_DEFINED (expr->symbol))
    {
      /* If expression can be evaluated, compare its value against the limits
	     and complain if the value is out of bounds. */
      uint32 value = (uint32)eval_imm_expr (expr);

      if (value < min || max < value)
	{
	  char str[200];
	  sprintf (str, "immediate value (%d) out of range (%d .. %d)",
		   (int32)value, (int32)min, (int32)max);
	  yywarn (str);
	}
    }
}

void
yyerror (char *s)
{
  parse_error_occurred = true;
  clear_labels ();
  yywarn (s);
}


void
yywarn (char *s)
{
  error ("spim: (parser) %s on line %d of file %s\n%s", s, line_no, input_file_name, erroneous_line ());
}


static void
mips32_r2_inst ()
{
	yyerror ("Warning: MIPS32 Rev 2 instruction is not implemented. Instruction ignored.");
}


static int
cc_to_rt (int cc, int nd, int tf)
{
  return (cc << 2) | (nd << 1) | tf;
}

