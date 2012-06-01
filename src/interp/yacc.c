/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROC = 258,
     FUNC_TOK = 259,
     IDEN = 260,
     SCONS = 261,
     CHILDREN = 262,
     SPOUSES = 263,
     IF = 264,
     ELSE = 265,
     ELSIF = 266,
     FAMILIES = 267,
     ICONS = 268,
     WHILE = 269,
     CALL = 270,
     FORINDISET = 271,
     FORINDI = 272,
     FORNOTES = 273,
     TRAVERSE = 274,
     FORNODES = 275,
     FORLIST_TOK = 276,
     FORFAM = 277,
     FORSOUR = 278,
     FOREVEN = 279,
     FOROTHR = 280,
     BREAK = 281,
     CONTINUE = 282,
     RETURN = 283,
     FATHERS = 284,
     MOTHERS = 285,
     PARENTS = 286,
     FCONS = 287
   };
#endif
/* Tokens.  */
#define PROC 258
#define FUNC_TOK 259
#define IDEN 260
#define SCONS 261
#define CHILDREN 262
#define SPOUSES 263
#define IF 264
#define ELSE 265
#define ELSIF 266
#define FAMILIES 267
#define ICONS 268
#define WHILE 269
#define CALL 270
#define FORINDISET 271
#define FORINDI 272
#define FORNOTES 273
#define TRAVERSE 274
#define FORNODES 275
#define FORLIST_TOK 276
#define FORFAM 277
#define FORSOUR 278
#define FOREVEN 279
#define FOROTHR 280
#define BREAK 281
#define CONTINUE 282
#define RETURN 283
#define FATHERS 284
#define MOTHERS 285
#define PARENTS 286
#define FCONS 287




/* Copy the first part of user declarations.  */
#line 36 "../../../src/interp/yacc.y"

/*#define YACC_C */
#include "llstdlib.h"
#include "table.h"
#include "translat.h"
#include "gedcom.h"
#include "cache.h"
#include "indiseq.h"
#include "interpi.h"
#include "liflines.h"
#include "parse.h"
#include <stdlib.h>

static PNODE this, prev;
INT Yival;
FLOAT Yfval;

static void join (PNODE list, PNODE last);
#define yyerror(msg) parse_error(pactx, msg)



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "yacc.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   967

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  296

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    17,    22,    31,
      40,    41,    43,    45,    49,    51,    54,    67,    80,    95,
     110,   125,   140,   153,   168,   181,   192,   203,   214,   225,
     236,   247,   260,   271,   283,   293,   300,   305,   310,   316,
     318,   319,   321,   323,   326,   335,   336,   341,   343,   349,
     351,   353,   355,   356,   358,   360,   364,   365,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    39,    40,    -1,    41,    -1,
      42,    -1,     5,    33,     5,    34,    -1,     5,    33,     6,
      34,    -1,     3,     5,    33,    43,    34,    35,    45,    36,
      -1,     4,     5,    33,    43,    34,    35,    45,    36,    -1,
      -1,    44,    -1,     5,    -1,     5,    37,    44,    -1,    46,
      -1,    45,    46,    -1,     7,    55,    33,    51,    37,     5,
      37,     5,    34,    35,    45,    36,    -1,     8,    55,    33,
      51,    37,     5,    37,     5,    34,    35,    45,    36,    -1,
       8,    55,    33,    51,    37,     5,    37,     5,    37,     5,
      34,    35,    45,    36,    -1,    12,    55,    33,    51,    37,
       5,    37,     5,    37,     5,    34,    35,    45,    36,    -1,
      29,    55,    33,    51,    37,     5,    37,     5,    37,     5,
      34,    35,    45,    36,    -1,    30,    55,    33,    51,    37,
       5,    37,     5,    37,     5,    34,    35,    45,    36,    -1,
      31,    55,    33,    51,    37,     5,    37,     5,    34,    35,
      45,    36,    -1,    16,    55,    33,    51,    37,     5,    37,
       5,    37,     5,    34,    35,    45,    36,    -1,    21,    55,
      33,    51,    37,     5,    37,     5,    34,    35,    45,    36,
      -1,    17,    55,    33,     5,    37,     5,    34,    35,    45,
      36,    -1,    18,    55,    33,    51,    37,     5,    34,    35,
      45,    36,    -1,    22,    55,    33,     5,    37,     5,    34,
      35,    45,    36,    -1,    23,    55,    33,     5,    37,     5,
      34,    35,    45,    36,    -1,    24,    55,    33,     5,    37,
       5,    34,    35,    45,    36,    -1,    25,    55,    33,     5,
      37,     5,    34,    35,    45,    36,    -1,    19,    55,    33,
      51,    37,     5,    37,     5,    34,    35,    45,    36,    -1,
      20,    55,    33,    51,    37,     5,    34,    35,    45,    36,
      -1,     9,    55,    33,    51,    54,    34,    35,    45,    36,
      47,    50,    -1,    14,    55,    33,    51,    54,    34,    35,
      45,    36,    -1,    15,     5,    55,    33,    52,    34,    -1,
      26,    55,    33,    34,    -1,    27,    55,    33,    34,    -1,
      28,    55,    33,    52,    34,    -1,    51,    -1,    -1,    48,
      -1,    49,    -1,    49,    48,    -1,    11,    33,    51,    54,
      34,    35,    45,    36,    -1,    -1,    10,    35,    45,    36,
      -1,     5,    -1,     5,    55,    33,    52,    34,    -1,     6,
      -1,    13,    -1,    32,    -1,    -1,    53,    -1,    51,    -1,
      51,    37,    53,    -1,    -1,    37,    51,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    71,    72,    73,    79,    92,    98,
     103,   106,   110,   114,   120,   123,   128,   134,   140,   146,
     152,   158,   164,   170,   176,   182,   188,   194,   200,   206,
     212,   218,   223,   228,   244,   249,   254,   258,   262,   266,
     270,   273,   277,   280,   285,   290,   293,   297,   302,   307,
     310,   313,   317,   320,   324,   327,   332,   335,   339
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROC", "FUNC_TOK", "IDEN", "SCONS",
  "CHILDREN", "SPOUSES", "IF", "ELSE", "ELSIF", "FAMILIES", "ICONS",
  "WHILE", "CALL", "FORINDISET", "FORINDI", "FORNOTES", "TRAVERSE",
  "FORNODES", "FORLIST_TOK", "FORFAM", "FORSOUR", "FOREVEN", "FOROTHR",
  "BREAK", "CONTINUE", "RETURN", "FATHERS", "MOTHERS", "PARENTS", "FCONS",
  "'('", "')'", "'{'", "'}'", "','", "$accept", "rspec", "defn", "proc",
  "func", "idenso", "idens", "tmplts", "tmplt", "elsifso", "elsifs",
  "elsif", "elseo", "expr", "exprso", "exprs", "secondo", "m", 0
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
     285,   286,   287,    40,    41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    40,    40,    41,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     4,     8,     8,
       0,     1,     1,     3,     1,     2,    12,    12,    14,    14,
      14,    14,    12,    14,    12,    10,    10,    10,    10,    10,
      10,    12,    10,    11,     9,     6,     4,     4,     5,     1,
       0,     1,     1,     2,     8,     0,     4,     1,     5,     1,
       1,     1,     0,     1,     1,     3,     0,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     5,     0,     0,
       0,     1,     3,    10,    10,     0,     0,    12,     0,    11,
       0,     6,     7,     0,     0,     0,    13,     0,     0,    47,
      49,    58,    58,    58,    58,    50,    58,     0,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    51,     0,    14,    39,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,    15,     9,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,    54,     0,
      53,     0,     0,    56,     0,    56,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    55,     0,     0,    57,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    41,    42,     0,
       0,    25,    26,     0,    32,     0,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    43,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
      56,     0,     0,     0,    31,    24,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    46,    19,
      23,    20,    21,     0,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    18,    19,    55,    56,   236,
     237,   238,   258,    57,   109,   110,   138,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
      34,     7,    14,    -6,    17,  -115,  -115,  -115,     1,     9,
      35,  -115,  -115,    27,    27,    10,    11,     6,    12,  -115,
      13,  -115,  -115,    27,    15,    16,  -115,   935,   935,    20,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,    43,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    80,  -115,  -115,   112,    21,
      22,    28,    30,    47,    48,  -115,    49,    50,    51,    57,
      81,    82,    89,    90,   113,   114,   116,   117,   119,   121,
     122,   124,  -115,  -115,  -115,    -3,    -3,    -3,    -3,    -3,
      -3,   125,    -3,    44,    -3,    -3,    -3,    -3,   108,   140,
     154,   155,   127,   128,    -3,    -3,    -3,    -3,   126,   130,
    -115,   129,   131,   132,   134,   132,    -3,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   158,  -115,  -115,   133,
     160,   165,   166,    -3,  -115,   172,   186,    -3,   173,   187,
     174,   175,   201,   205,   206,   207,   208,   209,   211,   213,
     214,   215,  -115,   216,   217,   218,  -115,   188,   191,  -115,
     194,   193,   196,  -115,   195,   199,   200,   203,   204,   210,
     212,   219,   225,   226,   224,   227,   229,   232,   237,   935,
     245,   935,   246,   228,   238,   257,   239,   291,   262,   270,
     271,   293,   324,   325,   332,   264,    -1,   263,   301,   295,
     323,   935,   935,   328,   935,   335,   935,   935,   935,   935,
     333,   355,   360,   326,   358,   396,   413,   397,  -115,   420,
     327,   359,   398,   391,   399,   423,   455,   487,   519,   421,
     451,   422,   935,   935,   424,   432,   456,  -115,   413,   454,
     463,  -115,  -115,   935,  -115,   935,  -115,  -115,  -115,  -115,
     464,   486,   935,   551,   583,   494,    -3,   495,  -115,  -115,
     517,   518,   615,   647,   526,   527,   679,  -115,  -115,   935,
     132,   935,   935,   935,  -115,  -115,   935,   935,  -115,   711,
     488,   743,   775,   807,   839,   871,  -115,   549,  -115,  -115,
    -115,  -115,  -115,   935,   903,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   161,  -115,  -115,   475,   467,   -28,   -27,  -115,
     283,  -115,  -115,   -81,   -86,   452,  -114,    26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      58,   140,    29,    30,   108,   111,   112,   113,   114,   115,
      35,   117,     8,   119,   120,   121,   122,    11,   129,     9,
       1,     2,     3,   108,   130,   131,   132,    10,    83,    54,
     141,    83,    17,   214,    13,   108,   215,     1,     2,     3,
      15,    16,    14,    23,    21,    22,    24,    25,    65,   118,
      27,    28,   108,   -58,    85,    86,   159,    60,    61,    62,
      63,    87,    64,    88,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      89,    90,    92,    93,    94,    29,    30,    31,    32,    33,
      95,    91,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   123,    96,    97,    82,    29,    30,    31,
      32,    33,    98,    99,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   124,   100,   101,    84,   102,
     103,   197,   104,   199,   105,   106,   280,   107,   116,   125,
     126,   127,   128,   133,   134,    12,   135,   152,   136,   137,
      83,   139,    83,   220,   221,   270,   223,   157,   225,   226,
     227,   228,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   158,   161,    83,    83,   151,    83,   153,    83,    83,
      83,    83,   154,   155,   253,   254,   164,   160,   162,   163,
     165,   166,   167,   168,   169,   262,   170,   263,   171,   172,
     173,   174,   175,   176,   266,   177,    83,    83,   178,   179,
     180,   181,   182,   183,   184,    83,    83,   195,   186,    83,
     185,   279,   196,   281,   282,   283,   188,   187,   284,   285,
     198,   200,    83,   189,    83,    83,    83,    83,    83,   190,
     191,   192,   203,   201,   193,   294,   194,    83,    29,    30,
      31,    32,    33,   202,   204,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   205,   206,   213,   216,
      29,    30,    31,    32,    33,   207,   208,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   209,   210,
     211,   218,    29,    30,    31,    32,    33,   212,   217,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     219,   232,   222,   241,    29,    30,    31,    32,    33,   224,
     229,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   230,   233,   231,   242,    29,    30,    31,    32,
      33,   234,   239,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   235,   240,   250,   244,    29,    30,
      31,    32,    33,   243,   245,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   251,   252,   255,   246,
      29,    30,    31,    32,    33,   256,   257,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   260,    20,
      26,   247,    29,    30,    31,    32,    33,   261,   264,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     265,   259,   287,   248,    29,    30,    31,    32,    33,   269,
     271,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   272,   273,     0,   249,    29,    30,    31,    32,
      33,   276,   277,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   293,   156,     0,   267,    29,    30,
      31,    32,    33,     0,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,   268,
      29,    30,    31,    32,    33,     0,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
       0,   274,    29,    30,    31,    32,    33,     0,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,   275,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,   278,    29,    30,    31,    32,
      33,     0,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,     0,   286,    29,    30,
      31,    32,    33,     0,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,   288,
      29,    30,    31,    32,    33,     0,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
       0,   289,    29,    30,    31,    32,    33,     0,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,   290,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,   291,    29,    30,    31,    32,
      33,     0,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,     0,   292,    29,    30,
      31,    32,    33,     0,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,   295,
      29,    30,    31,    32,    33,     0,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
      28,   115,     5,     6,    85,    86,    87,    88,    89,    90,
      13,    92,     5,    94,    95,    96,    97,     0,   104,     5,
       3,     4,     5,   104,   105,   106,   107,    33,    55,    32,
     116,    58,     5,    34,    33,   116,    37,     3,     4,     5,
       5,     6,    33,    37,    34,    34,    34,    34,     5,     5,
      35,    35,   133,    33,    33,    33,   137,    31,    32,    33,
      34,    33,    36,    33,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      33,    33,    33,    33,    33,     5,     6,     7,     8,     9,
      33,    65,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     5,    33,    33,    36,     5,     6,     7,
       8,     9,    33,    33,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     5,    33,    33,    36,    33,
      33,   179,    33,   181,    33,    33,   270,    33,    33,     5,
       5,    34,    34,    37,    34,     4,    37,    34,    37,    37,
     197,    37,   199,   201,   202,   256,   204,     5,   206,   207,
     208,   209,    37,    37,    37,    37,    37,    37,    37,    37,
      37,     5,     5,   220,   221,    37,   223,    37,   225,   226,
     227,   228,    37,    37,   232,   233,     5,    34,    34,    34,
       5,     5,     5,     5,     5,   243,     5,   245,     5,     5,
       5,     5,     5,     5,   252,    37,   253,   254,    37,    35,
      37,    35,    37,    34,    34,   262,   263,     5,    34,   266,
      37,   269,     5,   271,   272,   273,    34,    37,   276,   277,
       5,     5,   279,    34,   281,   282,   283,   284,   285,    34,
      34,    37,     5,    35,    37,   293,    37,   294,     5,     6,
       7,     8,     9,    35,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     5,    35,    34,    36,
       5,     6,     7,     8,     9,    35,    35,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    35,     5,
       5,    36,     5,     6,     7,     8,     9,     5,    37,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      37,    35,    34,    36,     5,     6,     7,     8,     9,    34,
      37,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    37,    35,    34,    36,     5,     6,     7,     8,
       9,     5,     5,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    11,     5,     5,    36,     5,     6,
       7,     8,     9,    35,    35,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     5,    35,    34,    36,
       5,     6,     7,     8,     9,    33,    10,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    34,    14,
      23,    36,     5,     6,     7,     8,     9,    34,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      34,   238,    34,    36,     5,     6,     7,     8,     9,    35,
      35,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    35,    35,    -1,    36,     5,     6,     7,     8,
       9,    35,    35,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    35,   133,    -1,    36,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    39,    40,    41,    42,     5,     5,
      33,     0,    40,    33,    33,     5,     6,     5,    43,    44,
      43,    34,    34,    37,    34,    34,    44,    35,    35,     5,
       6,     7,     8,     9,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    45,    46,    51,    45,    55,
      55,    55,    55,    55,    55,     5,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    36,    46,    36,    33,    33,    33,    33,    33,
      33,    55,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    51,    52,
      53,    51,    51,    51,    51,    51,    33,    51,     5,    51,
      51,    51,    51,     5,     5,     5,     5,    34,    34,    52,
      51,    51,    51,    37,    34,    37,    37,    37,    54,    37,
      54,    52,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    34,    37,    37,    37,    53,     5,     5,    51,
      34,     5,    34,    34,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,    37,    37,    35,
      37,    35,    37,    34,    34,    37,    34,    37,    34,    34,
      34,    34,    37,    37,    37,     5,     5,    45,     5,    45,
       5,    35,    35,     5,    35,     5,    35,    35,    35,    35,
       5,     5,     5,    34,    34,    37,    36,    37,    36,    37,
      45,    45,    34,    45,    34,    45,    45,    45,    45,    37,
      37,    34,    35,    35,     5,    11,    47,    48,    49,     5,
       5,    36,    36,    35,    36,    35,    36,    36,    36,    36,
       5,     5,    35,    45,    45,    34,    33,    10,    50,    48,
      34,    34,    45,    45,    34,    34,    45,    36,    36,    35,
      51,    35,    35,    35,    36,    36,    35,    35,    36,    45,
      54,    45,    45,    45,    45,    45,    36,    34,    36,    36,
      36,    36,    36,    35,    45,    36
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 6:
#line 73 "../../../src/interp/yacc.y"
    {
			if (eqstr("global", (STRING) (yyvsp[(1) - (4)])))
				pa_handle_global((STRING) (yyvsp[(3) - (4)]));
				free_iden((yyvsp[(1) - (4)]));
				free_iden((yyvsp[(3) - (4)]));
		}
    break;

  case 7:
#line 79 "../../../src/interp/yacc.y"
    {
			if (eqstr("include", (STRING) (yyvsp[(1) - (4)])))
				pa_handle_include(pactx, (PNODE) (yyvsp[(3) - (4)]));
			if (eqstr("option", (STRING) (yyvsp[(1) - (4)])))
				pa_handle_option(ivalue((PNODE) (yyvsp[(3) - (4)])));
			if (eqstr("char_encoding", (STRING) (yyvsp[(1) - (4)])))
				pa_handle_char_encoding(pactx, (PNODE) (yyvsp[(3) - (4)]));
			if (eqstr("require", (STRING) (yyvsp[(1) - (4)])))
				pa_handle_require(pactx, (PNODE) (yyvsp[(3) - (4)]));
			free_iden((yyvsp[(1) - (4)]));
		}
    break;

  case 8:
#line 92 "../../../src/interp/yacc.y"
    {
			/* consumes $2 */
			pa_handle_proc(pactx, (STRING) (yyvsp[(2) - (8)]), (PNODE) (yyvsp[(4) - (8)]), (PNODE) (yyvsp[(7) - (8)]));
		}
    break;

  case 9:
#line 98 "../../../src/interp/yacc.y"
    {
			/* consumes $2 */
			pa_handle_func(pactx, (STRING) (yyvsp[(2) - (8)]), (PNODE) (yyvsp[(4) - (8)]), (PNODE) (yyvsp[(7) - (8)]));
		}
    break;

  case 10:
#line 103 "../../../src/interp/yacc.y"
    {
			(yyval) = 0;
		}
    break;

  case 11:
#line 106 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 12:
#line 110 "../../../src/interp/yacc.y"
    {
			/* consumes $1 */
			(yyval) = iden_node(pactx, (STRING)(yyvsp[(1) - (1)]));
		}
    break;

  case 13:
#line 114 "../../../src/interp/yacc.y"
    {
			/* consumes $1 */
			(yyval) = iden_node(pactx, (STRING)(yyvsp[(1) - (3)]));
			inext(((PNODE)(yyval))) = (PNODE) (yyvsp[(3) - (3)]);
		}
    break;

  case 14:
#line 120 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 15:
#line 123 "../../../src/interp/yacc.y"
    {
			join((PNODE) (yyvsp[(1) - (2)]), (PNODE) (yyvsp[(2) - (2)]));
			(yyval) = (yyvsp[(1) - (2)]);
		}
    break;

  case 16:
#line 129 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 */
			(yyval) = children_node(pactx, (PNODE)(yyvsp[(4) - (12)]), (STRING)(yyvsp[(6) - (12)]), (STRING)(yyvsp[(8) - (12)]), (PNODE)(yyvsp[(11) - (12)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (12)]);
		}
    break;

  case 17:
#line 135 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 */
			(yyval) = familyspouses_node(pactx, (PNODE)(yyvsp[(4) - (12)]), (STRING)(yyvsp[(6) - (12)]), (STRING)(yyvsp[(8) - (12)]), (PNODE)(yyvsp[(11) - (12)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (12)]);
		}
    break;

  case 18:
#line 141 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 and $10 */
			(yyval) = spouses_node(pactx, (PNODE)(yyvsp[(4) - (14)]), (STRING)(yyvsp[(6) - (14)]), (STRING)(yyvsp[(8) - (14)]), (STRING)(yyvsp[(10) - (14)]), (PNODE)(yyvsp[(13) - (14)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (14)]);
		}
    break;

  case 19:
#line 147 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 and $10 */
			(yyval) = families_node(pactx, (PNODE)(yyvsp[(4) - (14)]), (STRING)(yyvsp[(6) - (14)]), (STRING)(yyvsp[(8) - (14)]), (STRING)(yyvsp[(10) - (14)]), (PNODE)(yyvsp[(13) - (14)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (14)]);
		}
    break;

  case 20:
#line 153 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 and $10 */
			(yyval) = fathers_node(pactx, (PNODE)(yyvsp[(4) - (14)]), (STRING)(yyvsp[(6) - (14)]), (STRING)(yyvsp[(8) - (14)]), (STRING)(yyvsp[(10) - (14)]), (PNODE)(yyvsp[(13) - (14)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (14)]);
		}
    break;

  case 21:
#line 159 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 and $10 */
			(yyval) = mothers_node(pactx, (PNODE)(yyvsp[(4) - (14)]), (STRING)(yyvsp[(6) - (14)]), (STRING)(yyvsp[(8) - (14)]), (STRING)(yyvsp[(10) - (14)]), (PNODE)(yyvsp[(13) - (14)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (14)]);
		}
    break;

  case 22:
#line 165 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 */
			(yyval) = parents_node(pactx, (PNODE)(yyvsp[(4) - (12)]), (STRING)(yyvsp[(6) - (12)]), (STRING)(yyvsp[(8) - (12)]), (PNODE)(yyvsp[(11) - (12)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (12)]);
		}
    break;

  case 23:
#line 171 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 and $10 */
			(yyval) = forindiset_node(pactx, (PNODE)(yyvsp[(4) - (14)]), (STRING)(yyvsp[(6) - (14)]), (STRING)(yyvsp[(8) - (14)]), (STRING)(yyvsp[(10) - (14)]), (PNODE)(yyvsp[(13) - (14)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (14)]);
		}
    break;

  case 24:
#line 177 "../../../src/interp/yacc.y"
    {
			/* consumes $6 and $8 */
			(yyval) = forlist_node(pactx, (PNODE)(yyvsp[(4) - (12)]), (STRING)(yyvsp[(6) - (12)]), (STRING)(yyvsp[(8) - (12)]), (PNODE)(yyvsp[(11) - (12)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (12)]);
		}
    break;

  case 25:
#line 183 "../../../src/interp/yacc.y"
    {
			/* consumes $4 and $6 */
			(yyval) = forindi_node(pactx, (STRING)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 26:
#line 189 "../../../src/interp/yacc.y"
    {
			/* consumes $6 */
			(yyval) = fornotes_node(pactx, (PNODE)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 27:
#line 195 "../../../src/interp/yacc.y"
    {
			/* consumes $4 and $6 */
			(yyval) = forfam_node(pactx, (STRING)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 28:
#line 201 "../../../src/interp/yacc.y"
    {
			/* consumes $4 and $6 */
			(yyval) = forsour_node(pactx, (STRING)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 29:
#line 207 "../../../src/interp/yacc.y"
    {
			/* consumes $4 and $6 */
			(yyval) = foreven_node(pactx, (STRING)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 30:
#line 213 "../../../src/interp/yacc.y"
    {
			/* consumes $4 and $6 */
			(yyval) = forothr_node(pactx, (STRING)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 31:
#line 218 "../../../src/interp/yacc.y"
    {
			/* consumes $6 */
			(yyval) = traverse_node(pactx, (PNODE)(yyvsp[(4) - (12)]), (STRING)(yyvsp[(6) - (12)]), (STRING)(yyvsp[(8) - (12)]), (PNODE)(yyvsp[(11) - (12)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (12)]);
		}
    break;

  case 32:
#line 223 "../../../src/interp/yacc.y"
    {
			/* consumes $6 */
			(yyval) = fornodes_node(pactx, (PNODE)(yyvsp[(4) - (10)]), (STRING)(yyvsp[(6) - (10)]), (PNODE)(yyvsp[(9) - (10)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (10)]);
		}
    break;

  case 33:
#line 228 "../../../src/interp/yacc.y"
    {
			inext(((PNODE)(yyvsp[(4) - (11)]))) = (PNODE)(yyvsp[(5) - (11)]);
			prev = NULL;  this = (PNODE)(yyvsp[(10) - (11)]);
			while (this) {
				prev = this;
				this = (PNODE) ielse(this);
			}
			if (prev) {
				ielse(prev) = (VPTR)(yyvsp[(11) - (11)]);
				(yyval) = if_node(pactx, (PNODE)(yyvsp[(4) - (11)]), (PNODE)(yyvsp[(8) - (11)]),
				    (PNODE)(yyvsp[(10) - (11)]));
			} else
				(yyval) = if_node(pactx, (PNODE)(yyvsp[(4) - (11)]), (PNODE)(yyvsp[(8) - (11)]),
				    (PNODE)(yyvsp[(11) - (11)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (11)]);
		}
    break;

  case 34:
#line 244 "../../../src/interp/yacc.y"
    {
			inext(((PNODE)(yyvsp[(4) - (9)]))) = (PNODE)(yyvsp[(5) - (9)]);
			(yyval) = while_node(pactx, (PNODE)(yyvsp[(4) - (9)]), (PNODE)(yyvsp[(8) - (9)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (9)]);
		}
    break;

  case 35:
#line 249 "../../../src/interp/yacc.y"
    {
			/* consumes $2 */
			(yyval) = call_node(pactx, (STRING)(yyvsp[(2) - (6)]), (PNODE)(yyvsp[(5) - (6)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(3) - (6)]);
		}
    break;

  case 36:
#line 254 "../../../src/interp/yacc.y"
    {
			(yyval) = break_node(pactx);
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (4)]);
		}
    break;

  case 37:
#line 258 "../../../src/interp/yacc.y"
    {
			(yyval) = continue_node(pactx);
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (4)]);
		}
    break;

  case 38:
#line 262 "../../../src/interp/yacc.y"
    {
			(yyval) = return_node(pactx, (PNODE)(yyvsp[(4) - (5)]));
			((PNODE)(yyval))->i_line = (INT) (yyvsp[(2) - (5)]);
		}
    break;

  case 39:
#line 266 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 40:
#line 270 "../../../src/interp/yacc.y"
    {
			(yyval) = 0;
		}
    break;

  case 41:
#line 273 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 42:
#line 277 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 43:
#line 280 "../../../src/interp/yacc.y"
    {
			ielse((PNODE)(yyvsp[(1) - (2)])) = (VPTR)(yyvsp[(2) - (2)]);
			(yyval) = (yyvsp[(1) - (2)]);
		}
    break;

  case 44:
#line 285 "../../../src/interp/yacc.y"
    {
			inext(((PNODE)(yyvsp[(3) - (8)]))) = (PNODE)(yyvsp[(4) - (8)]);
			(yyval) = if_node(pactx, (PNODE)(yyvsp[(3) - (8)]), (PNODE)(yyvsp[(7) - (8)]), (PNODE)NULL);
		}
    break;

  case 45:
#line 290 "../../../src/interp/yacc.y"
    {
			(yyval) = 0;
		}
    break;

  case 46:
#line 293 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(3) - (4)]);
		}
    break;

  case 47:
#line 297 "../../../src/interp/yacc.y"
    {
			/* consumes $1 */
			(yyval) = iden_node(pactx, (STRING)(yyvsp[(1) - (1)]));
			iargs(((PNODE)(yyval))) = NULL;
		}
    break;

  case 48:
#line 302 "../../../src/interp/yacc.y"
    {
			/* consumes $1 */
			(yyval) = func_node(pactx, (STRING)(yyvsp[(1) - (5)]), (PNODE)(yyvsp[(4) - (5)]));
			((PNODE)(yyval))->i_line = (INT)(yyvsp[(2) - (5)]);
		}
    break;

  case 49:
#line 307 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 50:
#line 310 "../../../src/interp/yacc.y"
    {
			(yyval) = icons_node(pactx, Yival);
		}
    break;

  case 51:
#line 313 "../../../src/interp/yacc.y"
    {
			(yyval) = fcons_node(pactx, Yfval);
		}
    break;

  case 52:
#line 317 "../../../src/interp/yacc.y"
    {
			(yyval) = 0;
		}
    break;

  case 53:
#line 320 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 54:
#line 324 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 55:
#line 327 "../../../src/interp/yacc.y"
    {
			inext(((PNODE)(yyvsp[(1) - (3)]))) = (PNODE) (yyvsp[(3) - (3)]);
			(yyval) = (yyvsp[(1) - (3)]);
		}
    break;

  case 56:
#line 332 "../../../src/interp/yacc.y"
    {
			(yyval) = 0;
		}
    break;

  case 57:
#line 335 "../../../src/interp/yacc.y"
    {
			(yyval) = (yyvsp[(2) - (2)]);
		}
    break;

  case 58:
#line 339 "../../../src/interp/yacc.y"
    {
			(yyval) = (YYSTYPE)((PACTX)pactx)->lineno;
		}
    break;


/* Line 1267 of yacc.c.  */
#line 2169 "yacc.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 343 "../../../src/interp/yacc.y"


void
join (PNODE list,
      PNODE last)
{
	PNODE prev = NULL;
	while (list) {
		prev = list;
		list = inext(list);
	}
	ASSERT(prev);
	inext(prev) = last;
}


