
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 8 "parse"

#define DEBUG

#include <cstdio>
#include <iostream>
#include "tree_nodes.h"
#include "parse.tab.h"
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" char* yytext;
extern "C" int yylineno;
extern "C" program* prgm;
extern "C" void buildTree(char* filename);

void yyerror(const char *s);
void mergeLists( list<void*>* a, list<void*>* b);


/* Line 189 of yacc.c  */
#line 96 "parse.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     ASSIGN = 1,
     PLUS = 2,
     MINUS = 3,
     DIV = 4,
     MUL = 5,
     MOD = 6,
     BIT_OR = 7,
     BIT_AND = 8,
     BIT_XOR = 9,
     RSL = 10,
     LSL = 11,
     AND = 12,
     OR = 13,
     GTR = 14,
     LSS = 15,
     GEQ = 16,
     LEQ = 17,
     EQU = 18,
     NEQ = 19,
     NOT = 20,
     IF = 21,
     ELSE = 22,
     SWITCH = 23,
     CASE = 24,
     WHILE = 25,
     BREAK = 26,
     RETURN = 27,
     BASE_TYPE = 28,
     OBJ_TYPE = 29,
     SUPER_TYPE = 30,
     OBJ = 31,
     FLOAT = 32,
     DEC = 33,
     HEX = 34,
     NAME = 35,
     STRING = 36
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "parse"

	int ival;
	float fval; // maybe double.  check size
	char* str;
	void* ptr;



/* Line 214 of yacc.c  */
#line 179 "parse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "parse.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     2,     2,     2,
      41,    42,     2,     2,    43,     2,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    16,    20,    23,    27,
      30,    33,    37,    40,    45,    51,    56,    61,    65,    69,
      76,    82,    88,    90,    92,    94,    99,   106,   113,   119,
     127,   135,   141,   148,   154,   158,   163,   167,   173,   181,
     187,   193,   197,   201,   203,   206,   210,   218,   219,   221,
     225,   229,   233,   236,   239,   241,   245,   250,   252,   256,
     258,   260,   264,   268,   270,   272,   274,   278,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     303,   305,   307,   309,   311,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    48,    49,    -1,    48,    53,    -1,    -1,
      30,    37,    51,    50,    56,    -1,    39,    54,    40,    -1,
      39,    40,    -1,    41,    52,    42,    -1,    41,    42,    -1,
      30,    37,    -1,    32,    30,    37,    -1,    31,    37,    -1,
      52,    43,    30,    37,    -1,    52,    43,    32,    30,    37,
      -1,    52,    43,    31,    37,    -1,    32,    30,    37,    44,
      -1,    30,    37,    44,    -1,    31,    37,    44,    -1,    32,
      30,    37,     3,    54,    44,    -1,    30,    37,     3,    54,
      44,    -1,    31,    37,     3,    54,    44,    -1,    36,    -1,
      35,    -1,    34,    -1,    37,     3,    61,    44,    -1,    33,
      45,    37,     3,    61,    44,    -1,    37,    45,    37,     3,
      61,    44,    -1,    37,    41,    65,    42,    44,    -1,    33,
      45,    37,    41,    65,    42,    44,    -1,    37,    45,    37,
      41,    65,    42,    44,    -1,    30,    37,     3,    61,    44,
      -1,    32,    30,    37,     3,    61,    44,    -1,    31,    37,
       3,    61,    44,    -1,    30,    37,    44,    -1,    32,    30,
      37,    44,    -1,    31,    37,    44,    -1,    23,    41,    61,
      42,    56,    -1,    23,    41,    61,    42,    56,    24,    56,
      -1,    27,    41,    61,    42,    56,    -1,    25,    41,    60,
      42,    58,    -1,    29,    64,    44,    -1,    39,    57,    40,
      -1,    55,    -1,    55,    57,    -1,    39,    59,    40,    -1,
      26,    64,    46,    57,    28,    44,    59,    -1,    -1,    37,
      -1,    33,    45,    37,    -1,    37,    45,    37,    -1,    63,
      66,    62,    -1,    22,    61,    -1,    10,    61,    -1,    62,
      -1,    41,    61,    42,    -1,    37,    41,    65,    42,    -1,
      64,    -1,    63,    66,    62,    -1,    62,    -1,    37,    -1,
      33,    45,    37,    -1,    37,    45,    37,    -1,    38,    -1,
      54,    -1,    64,    -1,    64,    43,    65,    -1,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   105,   111,   116,   127,   132,   139,   144,
     151,   159,   166,   173,   181,   189,   199,   205,   211,   217,
     223,   229,   237,   241,   245,   253,   259,   265,   271,   277,
     283,   289,   295,   301,   307,   313,   319,   325,   331,   337,
     343,   349,   357,   361,   363,   367,   373,   383,   390,   394,
     398,   404,   408,   412,   416,   422,   426,   430,   436,   440,
     446,   450,   454,   458,   462,   468,   474,   482,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "PLUS", "MINUS", "DIV", "MUL",
  "MOD", "BIT_OR", "BIT_AND", "BIT_XOR", "RSL", "LSL", "AND", "OR", "GTR",
  "LSS", "GEQ", "LEQ", "EQU", "NEQ", "NOT", "IF", "ELSE", "SWITCH", "CASE",
  "WHILE", "BREAK", "RETURN", "BASE_TYPE", "OBJ_TYPE", "SUPER_TYPE", "OBJ",
  "FLOAT", "DEC", "HEX", "NAME", "STRING", "'{'", "'}'", "'('", "')'",
  "','", "';'", "'.'", "':'", "$accept", "program", "func", "func_n",
  "params", "param_l", "global", "number", "stmt", "stmtb", "stmts",
  "caseb", "cases", "id", "expr", "expr_", "comp", "value", "values",
  "biop", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,   123,
     125,    40,    41,    44,    59,    46,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     5,     3,     2,     3,     2,
       2,     3,     2,     4,     5,     4,     4,     3,     3,     6,
       5,     5,     1,     1,     1,     4,     6,     6,     5,     7,
       7,     5,     6,     5,     3,     4,     3,     5,     7,     5,
       5,     3,     3,     1,     2,     3,     7,     0,     1,     3,
       3,     3,     2,     2,     1,     3,     4,     1,     3,     1,
       1,     3,     3,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,    17,     0,     0,    18,     0,    24,    23,
      22,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,    16,    20,    10,    12,     0,     8,     0,     7,     0,
       0,     5,    21,     0,    11,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
      19,    13,    15,     0,     0,     0,     0,     0,    60,    63,
      64,     0,     0,     0,     0,     0,     0,    67,     0,    44,
      42,    14,     0,     0,    60,     0,     0,    59,     0,    57,
       0,    48,     0,     0,     0,     0,    41,     0,    34,     0,
      36,     0,     0,     0,    65,     0,     0,    53,    52,    67,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,    61,    62,     0,     0,     0,
      35,     0,    67,    25,    67,     0,     0,    67,     0,    55,
      37,    58,    49,    50,    47,    40,    39,    31,    33,     0,
       0,     0,    66,    28,     0,     0,    56,     0,     0,     0,
      32,    26,     0,    27,     0,    38,     0,    45,    29,    30,
       0,     0,     0,    47,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,    28,    14,    26,     7,    70,    58,    41,
      59,   155,   169,    92,    86,    87,    88,    89,   105,   130
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
    -108,    34,  -108,   -26,   -15,     9,  -108,  -108,     2,     3,
      26,    20,    -2,  -108,    35,    20,  -108,     4,  -108,  -108,
    -108,    -7,    41,    43,    14,  -108,   -11,    36,    42,    46,
      20,  -108,  -108,  -108,  -108,    57,  -108,    37,  -108,    78,
      96,  -108,  -108,    53,  -108,    83,    87,   100,  -108,     1,
      90,    91,   110,   103,   104,   119,   105,     0,    96,   111,
    -108,  -108,  -108,   115,    51,   -20,    51,   108,   109,  -108,
    -108,   112,     5,     6,   118,   120,    51,   110,   121,  -108,
    -108,  -108,    51,    51,   -25,    51,   117,   -19,    95,  -108,
     116,   122,   123,   124,   125,   126,  -108,    51,  -108,    51,
    -108,     7,    11,   127,   129,   128,    12,  -108,  -108,   110,
     131,    42,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
     101,   132,   137,   136,    42,  -108,  -108,   133,   134,    51,
    -108,    51,   110,  -108,   110,   135,    51,   110,   138,  -108,
     140,    -6,  -108,  -108,   142,  -108,  -108,  -108,  -108,   139,
     141,   144,  -108,  -108,   143,   146,  -108,    42,   110,   149,
    -108,  -108,   147,  -108,   148,  -108,   114,  -108,  -108,  -108,
      96,   153,   150,   142,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,  -108,  -108,    68,  -108,  -107,
     -58,  -108,    -1,  -108,   -64,    54,  -108,   -51,   -85,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      79,    71,    93,    76,   150,    11,    15,    30,    97,    99,
     139,     8,   103,    90,   141,   146,   109,    91,   107,   108,
      95,   110,     9,   -54,   148,   -54,   104,   156,    22,    23,
      24,    36,    37,   137,     2,   138,   -51,    32,   -51,    10,
      25,    77,    64,    12,    35,    78,    13,    16,    31,    98,
     100,   140,   142,   147,    18,    19,    20,   161,   104,   162,
     175,    82,   165,    17,     3,     4,     5,    45,    46,    47,
      18,    19,    20,    83,    27,   159,    38,   160,    33,    21,
      34,    40,   164,    29,    67,    18,    19,    20,    84,    69,
      42,   104,    85,   104,    44,    39,   104,    60,    43,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   176,    48,    49,
      61,    50,   181,    51,    62,    52,    53,    54,    55,    56,
      63,    65,    66,    57,    67,    18,    19,    20,    84,    69,
      72,    73,    85,    67,    18,    19,    20,    68,    69,    74,
      75,    80,    81,    94,    95,   101,    96,   102,   106,   111,
     180,   131,   135,   136,   167,   133,   134,   132,   168,   152,
     145,   143,   144,   149,   153,   154,     0,   157,   158,   163,
     166,   182,   184,   170,   151,   171,   172,   173,   174,   177,
       0,   178,   179,     0,   183
};

static const yytype_int16 yycheck[] =
{
      58,    52,    66,     3,   111,     3,     3,     3,     3,     3,
       3,    37,    76,    33,     3,     3,    41,    37,    82,    83,
      45,    85,    37,    42,   109,    44,    77,   134,    30,    31,
      32,    42,    43,    97,     0,    99,    42,    44,    44,    30,
      42,    41,    41,    41,    30,    45,    44,    44,    44,    44,
      44,    44,    41,    41,    34,    35,    36,   142,   109,   144,
     167,    10,   147,    37,    30,    31,    32,    30,    31,    32,
      34,    35,    36,    22,    39,   139,    40,   141,    37,    11,
      37,    39,   146,    15,    33,    34,    35,    36,    37,    38,
      44,   142,    41,   144,    37,    27,   147,    44,    30,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   168,    40,    23,
      37,    25,   180,    27,    37,    29,    30,    31,    32,    33,
      30,    41,    41,    37,    33,    34,    35,    36,    37,    38,
      37,    37,    41,    33,    34,    35,    36,    37,    38,    30,
      45,    40,    37,    45,    45,    37,    44,    37,    37,    42,
      46,    45,    37,    37,    24,    42,    42,    45,    26,    37,
      42,    44,    43,    42,    37,    39,    -1,    44,    44,    44,
      42,    28,   183,    44,   130,    44,    42,    44,    42,    40,
      -1,    44,    44,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,     0,    30,    31,    32,    49,    53,    37,    37,
      30,     3,    41,    44,    51,     3,    44,    37,    34,    35,
      36,    54,    30,    31,    32,    42,    52,    39,    50,    54,
       3,    44,    44,    37,    37,    30,    42,    43,    40,    54,
      39,    56,    44,    54,    37,    30,    31,    32,    40,    23,
      25,    27,    29,    30,    31,    32,    33,    37,    55,    57,
      44,    37,    37,    30,    41,    41,    41,    33,    37,    38,
      54,    64,    37,    37,    30,    45,     3,    41,    45,    57,
      40,    37,    10,    22,    37,    41,    61,    62,    63,    64,
      33,    37,    60,    61,    45,    45,    44,     3,    44,     3,
      44,    37,    37,    61,    64,    65,    37,    61,    61,    41,
      61,    42,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      66,    45,    45,    42,    42,    37,    37,    61,    61,     3,
      44,     3,    41,    44,    43,    42,     3,    41,    65,    42,
      56,    62,    37,    37,    39,    58,    56,    44,    44,    61,
      61,    65,    65,    44,    61,    65,    42,    24,    26,    59,
      44,    44,    42,    44,    42,    56,    64,    40,    44,    44,
      46,    57,    28,    44,    59
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 101 "parse"
    { 
				DEBUG cout << "function added to program" << endl;
				prgm->definitions->push_back(((def*) (yyvsp[(1) - (2)].ptr))); 
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 106 "parse"
    { 
				DEBUG cout << "global thingy" << endl;
				prgm->definitions->push_back(((def*) (yyvsp[(1) - (2)].ptr)));
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 111 "parse"
    {
				/* do nothing */
			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 117 "parse"
    { 
				func* f = new func((yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(std::list<param*>*) (yyvsp[(3) - (5)].ptr), (yyvsp[(4) - (5)].ival), (std::list<stmt*>*) (yyvsp[(5) - (5)].ptr));
				DEBUG cout << "Found a function declaration: " << f->name << endl;
				DEBUG cout << "\tfunction number: " << f->func_number << endl;
				DEBUG cout << "\treturn type: " << f->return_type << endl;
				(yyval.ptr) = f;
				DEBUG cout << "finished" << endl;
			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 128 "parse"
    { 
				DEBUG cout << "func number" << endl;
				(yyval.ival) = (uint32_t) (yyvsp[(2) - (3)].ptr);
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 133 "parse"
    { 
				DEBUG cout << "func number" << endl;
				(yyval.ival) = -1; 
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 140 "parse"
    { 
				DEBUG cout << "func params" << endl;
				(yyval.ptr) = (yyvsp[(2) - (3)].ptr); 
			;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 145 "parse"
    { 
				DEBUG cout << "func params empty" << endl;
				(yyval.ptr) = (void*) new list<param*>(); 
			;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 152 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				param* p = new param((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
				t->push_back(p); 
				(yyval.ptr) = t;
			;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 160 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				t->push_back(new param((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),(yyvsp[(1) - (3)].str))); 
				(yyval.ptr) = t;
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 167 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				t->push_back(new param((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str))); 
				(yyval.ptr) = t;
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 174 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				t->push_back(new param((yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)));
				mergeLists((list<void*>*) (yyvsp[(1) - (4)].ptr),(list<void*>*) t);
				(yyval.ptr) = (yyvsp[(1) - (4)].ptr);
			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 182 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				t->push_back(new param((yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str))); 
				mergeLists((list<void*>*) (yyvsp[(1) - (5)].ptr),(list<void*>*) t);
				(yyval.ptr) = (yyvsp[(1) - (5)].ptr);
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 190 "parse"
    { 
				DEBUG cout << "param listing" << endl;
				list<param*>* t = new list<param*>();
				t->push_back(new param((yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str))); 
				mergeLists((list<void*>*) (yyvsp[(1) - (4)].ptr),(list<void*>*) t);
				(yyval.ptr) = (yyvsp[(1) - (4)].ptr);
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 200 "parse"
    { 
				global* g = new global((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), (yyvsp[(1) - (4)].str));
				(yyval.ptr) = g;
				DEBUG cout << "global supertyped delclaration" << endl; 
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 206 "parse"
    { 
				DEBUG cout << "global base type declaration" << endl; 
				global* g = new global((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				(yyval.ptr) = g;
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 212 "parse"
    { 
				DEBUG cout << "global obj type declaration" << endl; 
				global* g = new global((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				(yyval.ptr) = g;
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 218 "parse"
    { 
				DEBUG cout << "global supertyped delclaration with assignment" << endl; 
				global* g = new global((yyvsp[(2) - (6)].str), (yyvsp[(3) - (6)].str), (uint32_t) (yyvsp[(5) - (6)].ptr), (yyvsp[(1) - (6)].str));
				(yyval.ptr) = g;
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 224 "parse"
    { 
				DEBUG cout << "global base type declaration with assignment" << endl; 
				global* g = new global((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (uint32_t) (yyvsp[(4) - (5)].ptr));
				(yyval.ptr) = g;
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 230 "parse"
    { 
				DEBUG cout << "global obj type declaration with assignment" << endl; 
				global* g = new global((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (uint32_t) (yyvsp[(4) - (5)].ptr));
				(yyval.ptr) = g;
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 238 "parse"
    {
				(yyval.ptr) = (void*) (yyvsp[(1) - (1)].ival);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 242 "parse"
    {
				(yyval.ptr) = (void*) (yyvsp[(1) - (1)].ival);
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 246 "parse"
    {
				num n;
				n.real = (yyvsp[(1) - (1)].fval);
				(yyval.ptr) = (void*) n.integer;
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 254 "parse"
    { 
				DEBUG cout << "assignment statement" << endl;
				stmt* s = new stmt_assign((yyvsp[(1) - (4)].str),(expr*) (yyvsp[(3) - (4)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 260 "parse"
    { 
				DEBUG cout << "assignment statement" << endl;
				stmt* s = new stmt_assign((yyvsp[(3) - (6)].str), (yyvsp[(1) - (6)].str), (expr*) (yyvsp[(5) - (6)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 266 "parse"
    { 
				DEBUG cout << "assignment statement" << endl;
				stmt* s = new stmt_assign((yyvsp[(3) - (6)].str), (yyvsp[(1) - (6)].str), (expr*) (yyvsp[(5) - (6)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 272 "parse"
    { 
				DEBUG cout << "function call statement" << endl; 
				stmt* s = new stmt_call((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 278 "parse"
    { 
				DEBUG cout << "function call from object statement" << endl; 
				stmt* s = new stmt_call((yyvsp[(3) - (7)].str), (yyvsp[(1) - (7)].str), (yyvsp[(5) - (7)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 284 "parse"
    { 
				DEBUG cout << "function call from name statement" << endl; 
				stmt* s = new stmt_call((yyvsp[(3) - (7)].str), (yyvsp[(1) - (7)].str), (yyvsp[(5) - (7)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 290 "parse"
    { 
				DEBUG cout << "local var define and assignment" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 296 "parse"
    { 
				DEBUG cout << "local var define and assignment" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 302 "parse"
    { 
				DEBUG cout << "local var define and assignment" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 308 "parse"
    { 
				DEBUG cout << "local var define" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				(yyval.ptr) = s;
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 314 "parse"
    { 
				DEBUG cout << "local var define" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str));
				(yyval.ptr) = s;
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 320 "parse"
    { 
				DEBUG cout << "local var define" << endl; 
				stmt* s = new stmt_var((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				(yyval.ptr) = s;
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 326 "parse"
    { 
				DEBUG cout << "if statement" << endl;
				stmt* s = new stmt_if((yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 332 "parse"
    { 
				DEBUG cout << "if else statement" << endl;
				stmt* s = new stmt_if((yyvsp[(3) - (7)].ptr), (yyvsp[(5) - (7)].ptr), (yyvsp[(7) - (7)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 338 "parse"
    { 
				DEBUG cout << "while loop" << endl;
				stmt* s = new stmt_while((yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 344 "parse"
    { 
				DEBUG cout << "switch statement" << endl;
				stmt* s = new stmt_switch((yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 350 "parse"
    {
				DEBUG cout << "return statment" << endl;
				stmt* s = new stmt_return((yyvsp[(2) - (3)].ptr));
				(yyval.ptr) = s;
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 358 "parse"
    { DEBUG cout << "statement block" << endl; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 362 "parse"
    { DEBUG cout << "last statement" << endl; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 364 "parse"
    { DEBUG cout << "continue statement list" << endl; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 368 "parse"
    { 
				DEBUG cout << "cases block" << endl;
				(yyval.ptr) = (yyvsp[(2) - (3)].ptr);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 374 "parse"
    { 
				DEBUG cout << "case of value" << endl; 
				list<switch_case*>* l = new list<switch_case*>();
				switch_case* s = new switch_case((yyvsp[(2) - (7)].ptr), (yyvsp[(4) - (7)].ptr));
				l->push_back(s);
				mergeLists((list<void*>*) l,(list<void*>*) (yyvsp[(7) - (7)].ptr));
				(yyval.ptr) = l;
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 383 "parse"
    { 
				DEBUG cout << "end of cases" << endl;
				list<switch_case*>* l = new list<switch_case*>();
				(yyval.ptr) = l;
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 391 "parse"
    {
				(yyval.ptr) = new id_class((yyvsp[(1) - (1)].str));
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 395 "parse"
    {
				(yyval.ptr) = new id_class((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 399 "parse"
    {
				(yyval.ptr) = new id_class((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 405 "parse"
    {
				(yyval.ptr) = new expr((yyvsp[(3) - (3)].ptr), (yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].ptr));
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 409 "parse"
    {
				(yyval.ptr) = new expr((yyvsp[(2) - (2)].ptr), (yyvsp[(1) - (2)].str));
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 413 "parse"
    {
				(yyval.ptr) = new expr((yyvsp[(2) - (2)].ptr), (yyvsp[(1) - (2)].str));
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 417 "parse"
    {
				(yyval.ptr) = (yyvsp[(1) - (1)].ptr);
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 423 "parse"
    {
				(yyval.ptr) = (yyvsp[(2) - (3)].ptr);
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 427 "parse"
    {
				DEBUG cout << "DEAL WITH FUNCTION CALLS IN EXPRESSIONS LATER" << endl;
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 431 "parse"
    {
				(yyval.ptr) = new expr((yyvsp[(1) - (1)].ptr));
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 437 "parse"
    {
				(yyval.ptr) = new expr((yyvsp[(3) - (3)].ptr), (yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].ptr));
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 441 "parse"
    {
				(yyval.ptr) = (yyvsp[(1) - (1)].ptr);
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 447 "parse"
    {
				(yyval.ptr) = new value(4,(yyvsp[(1) - (1)].str));
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 451 "parse"
    {
				(yyval.ptr) = new value(3,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 455 "parse"
    {
				(yyval.ptr) = new value(3,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 459 "parse"
    {
				(yyval.ptr) = new value(0,(yyvsp[(1) - (1)].str));
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 463 "parse"
    {
				(yyval.ptr) = new value(1,(uint32_t) (yyvsp[(1) - (1)].ptr));
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 469 "parse"
    {
				list<value*>* l = new list<value*>();
				l->push_back((value*) (yyvsp[(1) - (1)].ptr));
				(yyval.ptr) = l;
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 475 "parse"
    {
				list<value*>* l = new list<value*>();
				l->push_back((value*) (yyvsp[(1) - (3)].ptr));
				mergeLists((list<void*>*) l,(list<void*>*) (yyvsp[(3) - (3)].ptr));
				(yyval.ptr) = l;
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 482 "parse"
    {
				(yyval.ptr) = new list<value*>();
			;}
    break;



/* Line 1455 of yacc.c  */
#line 2218 "parse.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 508 "parse"

void buildTree(char* filename) 
{
	// open a file handle to a particular file:
	FILE *myfile = fopen(filename, "r");
	prgm = new program();
	// make sure it is valid:
	if (!myfile) {
		DEBUG cout << "I can't open file: " << filename << endl;
		exit(-1);
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
}

void yyerror(const char *s) 
{
	fprintf(stderr,"At line %d: %s ",s,yylineno);
	// might as well halt now:
	exit(-1);
}

void mergeLists(list<void*>* a, list<void*>* b)
{
	while(!b->empty()) {
		a->push_back(b->front());
		b->pop_front();
	}
	delete b;
}
