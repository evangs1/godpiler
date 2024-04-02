/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"

#define YYDEBUG 0
#include <stdio.h>
#include <string.h>
#include "../Parsing/node.h"
void yyerror(char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;
extern struct ScopeNode * main_scope;
void set_exp_node_type(struct ASTNode* node, enum NodeType exp_node_type);
int recurse_symbol_table(struct ScopeNode *scope, int starting_offset);

struct ASTNode* root;

#line 90 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED
# define YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_BOOLEAN = 258,
    KW_CLASS = 259,
    KW_FALSE = 260,
    KW_INT = 261,
    MAIN = 262,
    KW_PUBLIC = 263,
    KW_PRIVATE = 264,
    KW_TRUE = 265,
    KW_VOID = 266,
    KW_STATIC = 267,
    KW_STRING = 268,
    SYSTEM_OUT_PRINT = 269,
    SYSTEM_OUT_PRINTLN = 270,
    INTEGER_PARSEINT = 271,
    KW_IF = 272,
    KW_ELSE = 273,
    KW_WHILE = 274,
    KW_RETURN = 275,
    KW_LENGTH = 276,
    KW_NEW = 277,
    KW_SHORTCIRCUITOR = 278,
    KW_SHORTCIRCUITAND = 279,
    KW_COMPARISONEQUALS = 280,
    KW_GREATERTHANEQUALS = 281,
    KW_LESSTHANEQUALS = 282,
    KW_NOTEQUALS = 283,
    KW_OPEN_BRACE = 284,
    KW_OPEN_PAREN = 285,
    KW_SEMICOLON = 286,
    KW_EQUALS = 287,
    INTEGER_LITERAL = 288,
    STRING_LITERAL = 289,
    ID = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"

    struct ASTNode* node;
    int integer;
    char * string;

#line 184 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_EVAN_CLIONPROJECTS_GODPILER_CMAKE_BUILD_DEBUG_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,     2,     2,     2,
      38,    41,    49,    47,    44,    48,    52,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      45,    43,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    71,    82,    92,   103,   113,   116,   122,
     129,   134,   141,   146,   153,   158,   171,   177,   182,   191,
     201,   206,   211,   216,   223,   228,   236,   239,   244,   251,
     257,   262,   267,   273,   278,   284,   291,   296,   301,   309,
     316,   328,   333,   340,   345,   352,   357,   364,   371,   376,
     383,   390,   397,   404,   409,   416,   423,   428,   435,   442,
     447,   453,   459,   465,   468,   472,   478,   483,   488,   493,
     498,   502,   510,   519,   526,   532,   537
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_BOOLEAN", "KW_CLASS", "KW_FALSE",
  "KW_INT", "MAIN", "KW_PUBLIC", "KW_PRIVATE", "KW_TRUE", "KW_VOID",
  "KW_STATIC", "KW_STRING", "SYSTEM_OUT_PRINT", "SYSTEM_OUT_PRINTLN",
  "INTEGER_PARSEINT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN",
  "KW_LENGTH", "KW_NEW", "KW_SHORTCIRCUITOR", "KW_SHORTCIRCUITAND",
  "KW_COMPARISONEQUALS", "KW_GREATERTHANEQUALS", "KW_LESSTHANEQUALS",
  "KW_NOTEQUALS", "KW_OPEN_BRACE", "KW_OPEN_PAREN", "KW_SEMICOLON",
  "KW_EQUALS", "INTEGER_LITERAL", "STRING_LITERAL", "ID", "'{'", "'}'",
  "'('", "'['", "']'", "')'", "';'", "'='", "','", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'!'", "'.'", "$accept", "Program", "MainClass",
  "MainMethod", "VarDecl", "StaticVarDecl", "OptionalExp",
  "MoreStaticVarDecl", "MoreVarDecl", "StaticVarDeclStar",
  "StaticMethodDecl", "StaticMethodDeclStar", "FormalList",
  "FormalListTail", "PrimeType", "Type", "Statement", "Statements",
  "LeftValue", "MethodCall", "Exp", "ExpOr", "ExpAnd", "ExpEq",
  "ExpLessMore", "ExpAdd", "ExpMult", "Factor", "ExpList", "ExpListStar",
  "Index", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   123,   125,    40,    91,
      93,    41,    59,    61,    44,    60,    62,    43,    45,    42,
      47,    33,    46
};
# endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    -4,    44,  -135,    41,  -135,  -135,    46,    67,  -135,
      73,     8,    76,    57,  -135,  -135,  -135,  -135,  -135,    -6,
      -1,  -135,    56,    60,    98,     3,    18,  -135,  -135,    68,
      74,  -135,  -135,    75,     8,  -135,  -135,    77,    18,    18,
      18,    18,   -35,  -135,  -135,    88,    90,   -12,    37,    28,
      40,  -135,   -20,   103,     8,    18,    83,    18,    84,  -135,
    -135,  -135,    18,   105,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18,  -135,    92,    89,    93,
      19,    95,    18,    91,  -135,    96,  -135,   107,  -135,    90,
     -12,    37,    37,    28,    28,    28,    28,    40,    40,  -135,
    -135,    56,   110,    97,  -135,  -135,   111,    18,    85,  -135,
    -135,  -135,   117,  -135,    87,  -135,   113,    18,   114,   104,
       8,  -135,  -135,   102,   116,   118,   120,   121,    18,  -135,
    -135,  -135,    32,  -135,    29,   119,    39,  -135,    18,    18,
      18,    18,   130,   129,    56,    18,  -135,  -135,   154,   122,
     134,   135,   136,  -135,  -135,  -135,   137,  -135,   138,   139,
     179,   179,    -3,  -135,  -135,  -135,   144,  -135,  -135,   143,
     179,    56,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    14,    17,     0,    13,
       0,     0,     0,     0,    16,    22,    21,    23,    24,     0,
       0,     3,     8,     0,     0,     0,     0,    10,    25,     0,
       0,    69,    68,     0,     0,    66,    67,    37,     0,     0,
       0,     0,    64,    70,     7,    41,    43,    45,    48,    53,
      56,    59,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,    71,    74,     0,    63,     0,    65,    42,
      44,    46,    47,    49,    50,    51,    52,    54,    55,    57,
      58,     8,     0,     0,    20,    40,     0,     0,    72,    39,
      38,     9,     0,    36,    18,    75,     0,     0,     0,     0,
       0,    76,    73,     0,     0,     0,     0,     0,     0,    36,
      15,    26,     0,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     8,     0,    34,    19,     0,     0,
       0,     0,     0,    33,    27,    12,     0,     4,     0,     0,
       0,     0,     0,    32,    31,    30,     0,    29,     5,     0,
       0,     8,    28,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,  -135,   -98,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,   149,   -11,  -134,  -122,  -113,  -111,
     -37,  -135,   123,   132,    26,    16,    25,    21,  -135,  -135,
    -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    13,   131,     9,    27,    52,   162,     7,
      14,    10,    79,   114,    18,   132,   133,   119,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    85,   108,
      83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    58,    15,   111,    62,    16,   134,   143,   135,    25,
      24,    15,    17,    66,    16,   148,    67,    63,    81,     1,
      84,    17,    76,    31,    77,    87,   166,   167,    32,    22,
     134,     4,   135,    23,    33,   134,   172,   135,    30,   168,
      34,   169,    23,    80,     5,   106,   155,   134,   134,   135,
     135,    35,    36,    37,   104,     8,    38,   134,    23,   135,
      59,    60,    61,    68,    69,    39,    40,   144,    62,    41,
     116,    23,   145,   173,   147,    72,    73,     6,    23,    11,
     122,    12,    70,    71,    93,    94,    95,    96,    20,    74,
      75,   142,    91,    92,    21,    99,   100,    97,    98,    26,
      28,   149,   150,   151,   152,    29,    53,    15,   156,   136,
      16,    64,    54,    55,    65,    57,    78,    17,   124,   125,
      33,   126,    82,   127,   128,    86,    88,   101,   102,   117,
     107,   120,    15,   113,   103,    16,   105,   109,   137,    37,
     129,   130,    17,   124,   125,    33,   126,   110,   127,   128,
     112,   115,   118,   121,   138,   123,   139,    15,   140,   141,
      16,   146,   170,   158,    37,   129,   154,    17,   124,   125,
      33,   126,   153,   127,   128,   159,   160,   161,   171,   163,
     164,   165,    15,    56,     0,    16,     0,    89,     0,    37,
     129,   157,    17,   124,   125,    33,   126,    90,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   129
};

static const yytype_int16 yycheck[] =
{
      11,    38,     3,   101,    39,     6,   119,   129,   119,    20,
      11,     3,    13,    25,     6,   137,    28,    52,    55,     4,
      57,    13,    42,     5,    44,    62,   160,   161,    10,    35,
     143,    35,   143,    39,    16,   148,   170,   148,    35,    42,
      22,    44,    39,    54,     0,    82,   144,   160,   161,   160,
     161,    33,    34,    35,    35,     9,    38,   170,    39,   170,
      39,    40,    41,    26,    27,    47,    48,    35,    39,    51,
     107,    39,    43,   171,    35,    47,    48,    36,    39,    12,
     117,     8,    45,    46,    68,    69,    70,    71,    12,    49,
      50,   128,    66,    67,    37,    74,    75,    72,    73,    43,
      40,   138,   139,   140,   141,     7,    38,     3,   145,   120,
       6,    23,    38,    38,    24,    38,    13,    13,    14,    15,
      16,    17,    39,    19,    20,    41,    21,    35,    39,    44,
      39,    44,     3,    36,    41,     6,    41,    41,    36,    35,
      36,    37,    13,    14,    15,    16,    17,    40,    19,    20,
      40,    40,    35,    40,    38,    41,    38,     3,    38,    38,
       6,    42,    18,    41,    35,    36,    37,    13,    14,    15,
      16,    17,    42,    19,    20,    41,    41,    41,    35,    42,
      42,    42,     3,    34,    -1,     6,    -1,    64,    -1,    35,
      36,    37,    13,    14,    15,    16,    17,    65,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    54,    55,    35,     0,    36,    62,     9,    58,
      64,    12,     8,    56,    63,     3,     6,    13,    67,    68,
      12,    37,    35,    39,    11,    68,    43,    59,    40,     7,
      35,     5,    10,    16,    22,    33,    34,    35,    38,    47,
      48,    51,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    60,    38,    38,    38,    67,    38,    73,    80,
      80,    80,    39,    52,    23,    24,    25,    28,    26,    27,
      45,    46,    47,    48,    49,    50,    42,    44,    13,    65,
      68,    73,    39,    83,    73,    81,    41,    73,    21,    75,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    35,    39,    41,    35,    41,    73,    39,    82,    41,
      40,    59,    40,    36,    66,    40,    73,    44,    35,    70,
      44,    40,    73,    41,    14,    15,    17,    19,    20,    36,
      37,    57,    68,    69,    71,    72,    68,    36,    38,    38,
      38,    38,    73,    70,    35,    43,    42,    35,    70,    73,
      73,    73,    73,    42,    37,    59,    73,    37,    41,    41,
      41,    41,    61,    42,    42,    42,    69,    69,    42,    44,
      18,    35,    69,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     7,    13,     5,     7,     2,     0,     4,
       0,     4,     0,     2,     0,    10,     2,     0,     3,     4,
       0,     1,     1,     1,     1,     3,     1,     3,     7,     5,
       5,     5,     4,     3,     2,     2,     0,     1,     4,     4,
       4,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     2,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     2,     3,     0,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 63 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
              {   
        (yyval.node) = new_node(NODETYPE_PROGRAM);
        (yyval.node)->line_number = yylineno;
        root = (yyval.node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1495 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 3:
#line 72 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
    {
        (yyval.node) = new_node(NODETYPE_MAINCLASS);
        set_string_value((yyval.node), (yyvsp[-5].string));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1508 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 4:
#line 82 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                                         {
		(yyval.node) = new_node(NODETYPE_MAINMETHOD);
		(yyval.node)->line_number = yylineno;
		set_string_value((yyval.node), (yyvsp[-4].string));
		add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1520 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 5:
#line 92 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
        (yyval.node) = new_node(NODETYPE_VARDECL);
        set_string_value((yyval.node), (yyvsp[-3].string));
        //printf("********VARDECL STRING VALUE: %s", $$->data.value.string_value);
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1534 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 6:
#line 103 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                       {
		(yyval.node) = new_node(NODETYPE_STATIC_VARDECL);
		set_string_value((yyval.node), (yyvsp[-3].string));
		add_child((yyval.node), (yyvsp[-4].node));
		add_child((yyval.node), (yyvsp[-2].node));
		add_child((yyval.node), (yyvsp[-1].node));
		(yyval.node)->line_number = yylineno;
    }
#line 1547 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 7:
#line 113 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1555 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 8:
#line 116 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1563 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 9:
#line 122 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                             {
		(yyval.node) = new_node(NODETYPE_MORE_STATIC_VARDECL);
        set_string_value((yyval.node), (yyvsp[-1].string));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1575 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 10:
#line 129 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1583 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 11:
#line 134 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
		(yyval.node) = new_node(NODETYPE_MORE_VARDECL);
        set_string_value((yyval.node), (yyvsp[-1].string));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1595 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 12:
#line 141 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1603 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 13:
#line 146 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
		(yyval.node) = new_node(NODETYPE_STATIC_VAR_DECL_LIST);
		add_child((yyval.node), (yyvsp[-1].node));
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
		//????????? MAYBE THIS IS ALL WRONG??!?!?
	}
#line 1615 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 14:
#line 153 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1623 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 15:
#line 158 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                                          {
		(yyval.node) = new_node(NODETYPE_STATIC_METHOD_DECL);
		set_string_value((yyval.node), (yyvsp[-6].string));
		//Type
		add_child((yyval.node), (yyvsp[-7].node));
		//FormalList
		add_child((yyval.node), (yyvsp[-4].node));
		//Statements
		add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1639 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 16:
#line 171 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                          {
        (yyval.node) = new_node(NODETYPE_STATIC_METHOD_DECL_LIST);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1650 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 17:
#line 177 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1658 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 18:
#line 182 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                               {
		(yyval.node) = new_node(NODETYPE_FORMAL_LIST);
		set_string_value((yyval.node), (yyvsp[-1].string));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1670 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 19:
#line 191 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                   {
		(yyval.node) = new_node(NODETYPE_FORMAL_LIST);
        set_string_value((yyval.node), (yyvsp[0].string));
        //reversed these so they correspond with FormalList
        //Type is first child
        add_child((yyval.node), (yyvsp[-1].node));
        //FormalListTail is second child
        add_child((yyval.node), (yyvsp[-3].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1685 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 20:
#line 201 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1693 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 21:
#line 206 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
           {
        (yyval.node) = new_node(NODETYPE_PRIME_TYPE);
        (yyval.node) -> data.type = DATATYPE_INT;
        (yyval.node)->line_number = yylineno;
    }
#line 1703 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 22:
#line 211 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_PRIME_TYPE);
        (yyval.node) -> data.type = DATATYPE_BOOLEAN;
        (yyval.node)->line_number = yylineno;
    }
#line 1713 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 23:
#line 216 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {
        (yyval.node) = new_node(NODETYPE_PRIME_TYPE);
        (yyval.node) -> data.type = DATATYPE_STR;
        (yyval.node)->line_number = yylineno;
    }
#line 1723 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 24:
#line 223 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {
		(yyval.node) = new_node(NODETYPE_TYPE);
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1733 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 25:
#line 228 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                       {
		(yyval.node) = new_node(NODETYPE_TYPE);
		add_child((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1743 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 26:
#line 236 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1751 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 27:
#line 239 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                         {
        (yyval.node) = new_node(NODETYPE_STATEMENT_BLOCK);
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1761 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 28:
#line 244 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                    {
        (yyval.node) = new_node(NODETYPE_IF_ELSE);
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1773 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 29:
#line 251 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                     {
        (yyval.node) = new_node(NODETYPE_WHILE);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1784 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 30:
#line 257 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                         {
        (yyval.node) = new_node(NODETYPE_PRINTLN);
        add_child((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1794 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 31:
#line 262 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
        (yyval.node) = new_node(NODETYPE_PRINT);
        add_child((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1804 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 32:
#line 267 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_ASSIGNMENT);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1815 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 33:
#line 273 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_RETURN);
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
    }
#line 1825 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 34:
#line 278 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1833 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 35:
#line 284 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {
		(yyval.node) = new_node(NODETYPE_STATEMENTS);
		//should maybe switch these to make the tree right leaning???
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1845 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 36:
#line 291 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 1853 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 37:
#line 296 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
           {
		(yyval.node) = new_node(NODETYPE_LEFTVALUE);
        set_string_value((yyval.node), (yyvsp[0].string));
        (yyval.node)->line_number = yylineno;
	}
#line 1863 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 38:
#line 301 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                {
		(yyval.node) = new_node(NODETYPE_LEFTVALUE);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1874 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 39:
#line 309 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		(yyval.node) = new_node(NODETYPE_METHOD_CALL);
	    set_string_value((yyval.node), (yyvsp[-3].string));
	    add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1885 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 40:
#line 316 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
		(yyval.node) = new_node(NODETYPE_METHOD_CALL_PARSEINT);
		//??? manually add string or make new nodetype???
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1896 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 41:
#line 328 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
              {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1904 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 42:
#line 333 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                       {
		(yyval.node) = new_node(NODETYPE_EXP_2_BOOL);
		set_exp_node_type((yyval.node), NODETYPE_EXP_OR);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1916 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 43:
#line 340 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1924 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 44:
#line 345 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                        {
		(yyval.node) = new_node(NODETYPE_EXP_2_BOOL);
		set_exp_node_type((yyval.node), NODETYPE_EXP_AND);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1936 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 45:
#line 352 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1944 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 46:
#line 357 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                              {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL);
        set_exp_node_type((yyval.node), NODETYPE_COMPARISON_EQUALS);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1956 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 47:
#line 364 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                         {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT_OR_STRING_OR_BOOL);
		set_exp_node_type((yyval.node), NODETYPE_NOT_EQUALS);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1968 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 48:
#line 371 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                      {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1976 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 49:
#line 376 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                                {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_GREATER_THAN_EQUALS);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 1988 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 50:
#line 383 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                               {
        (yyval.node) = new_node(NODETYPE_EXP_2_INT);
        set_exp_node_type((yyval.node), NODETYPE_LESS_THAN_EQUALS);
		add_child((yyval.node), (yyvsp[-2].node));
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
    }
#line 2000 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 51:
#line 390 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                 {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_LESS_THAN);
		add_child((yyval.node), (yyvsp[-2].node));
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
    }
#line 2012 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 52:
#line 397 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                 {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_GREATER_THAN);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2024 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 53:
#line 404 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2032 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 54:
#line 409 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT_OR_STRING);
		set_exp_node_type((yyval.node), NODETYPE_PLUS);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2044 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 55:
#line 416 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_MINUS);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2056 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 56:
#line 423 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2064 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 57:
#line 428 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                           {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_MULTIPLY);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2076 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 58:
#line 435 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                             {
		(yyval.node) = new_node(NODETYPE_EXP_2_INT);
		set_exp_node_type((yyval.node), NODETYPE_DIVIDE);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2088 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 59:
#line 442 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                 {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2096 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 60:
#line 447 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                   {
		(yyval.node) = new_node(NODETYPE_EXP_1_BOOL);
		set_exp_node_type((yyval.node), NODETYPE_FACTOR_NOT);
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2107 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 61:
#line 453 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
		(yyval.node) = new_node(NODETYPE_EXP_1_INT_OR_STRING);
		set_exp_node_type((yyval.node), NODETYPE_FACTOR_PLUS);
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2118 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 62:
#line 459 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
		(yyval.node) = new_node(NODETYPE_EXP_1_INT);
		set_exp_node_type((yyval.node), NODETYPE_FACTOR_MINUS);
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2129 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 63:
#line 465 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                      {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 2137 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 64:
#line 468 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                    {
		//pass up leftvalue????
		(yyval.node) = (yyvsp[0].node);
	}
#line 2146 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 65:
#line 472 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                  {
		(yyval.node) = new_node(NODETYPE_LENGTH);
		set_exp_node_type((yyval.node), NODETYPE_FACTOR_LENGTH);
		add_child((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2157 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 66:
#line 478 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                          {
		(yyval.node) = new_node(NODETYPE_INTEGER_LITERAL);
	    set_int_value((yyval.node), (yyvsp[0].integer));
        (yyval.node)->line_number = yylineno;
	}
#line 2167 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 67:
#line 483 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                         {
		(yyval.node) = new_node(NODETYPE_STRING_LITERAL);
	    set_string_value((yyval.node), (yyvsp[0].string));
        (yyval.node)->line_number = yylineno;
	}
#line 2177 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 68:
#line 488 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                  {
		(yyval.node) = new_node(NODETYPE_BOOL_LITERAL);
	    set_boolean_value((yyval.node), true);
        (yyval.node)->line_number = yylineno;
	}
#line 2187 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 69:
#line 493 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                   {
		(yyval.node) = new_node(NODETYPE_BOOL_LITERAL);
	    set_boolean_value((yyval.node), false);
        (yyval.node)->line_number = yylineno;
	}
#line 2197 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 70:
#line 498 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                     {
		(yyval.node) = (yyvsp[0].node);

	}
#line 2206 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 71:
#line 502 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                                 {
		(yyval.node) = new_node(NODETYPE_NEW);
		add_child((yyval.node), (yyvsp[-1].node));
		add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2217 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 72:
#line 510 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                         {
	(yyval.node) = new_node(NODETYPE_EXPLIST);
    add_child((yyval.node), (yyvsp[-1].node));
    add_child((yyval.node), (yyvsp[0].node));
        (yyval.node)->line_number = yylineno;
}
#line 2228 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 73:
#line 519 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                            {
		(yyval.node) = new_node(NODETYPE_EXPLIST);
		//reversed because conforms to ExpList ^^^ layout, (the Exp first, the Other ExpList last)
		add_child((yyval.node), (yyvsp[0].node));
		add_child((yyval.node), (yyvsp[-2].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2240 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 74:
#line 526 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
          {
		(yyval.node) = NULL;
	}
#line 2248 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 75:
#line 532 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                    {
		(yyval.node) = new_node(NODETYPE_INDEX);
		add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2258 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;

  case 76:
#line 537 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"
                            {
		(yyval.node) = new_node(NODETYPE_INDEX);
		add_child((yyval.node), (yyvsp[-3].node));
		add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->line_number = yylineno;
	}
#line 2269 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"
    break;


#line 2273 "/home/evan/CLionProjects/godpiler/cmake-build-debug/parser.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 544 "/home/evan/CLionProjects/godpiler/Parsing/parser.y"


void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

//int main(int argc, char* argv[] )
//{
//
//	#if YYDEBUG
//        yydebug = 1;
//    #endif
//
//    yyin = fopen( argv[1], "r" );
//
//    // Checks for syntax errors and constructs AST
//    if (yyparse() != 0)
//        return 1;
//
//	printf("DONE!\n\n\n");
//    // Traverse the AST to check for semantic errors if no syntac errors
//    //checkProgram(root);
//
//	//printf("Typechecking:\n\n\n");
//    //Traverse AST a second time to make sure that types match up
//    //type_check_program(root);
//	//printf("DONE!\n\n\n");
//
//	//printf("outer number of ints: %d\n\n", recurse_symbol_table(main_scope, 0));
//	//asm_program(root);
//
//
//	//struct Instruction * final_instruction_list = reg_asn_program(root);
//
//	//printinf symbol table should be done after asm_program because it sets the offsets in the symbol table for local vars
//  //printf("\n\nPrinting Symbol Table:\n\n");
//  //print_tree_of_tables(main_scope, 0);
//
//  //printf("\n\n\n");
//
//	//char buf[200];
//	//strcpy(buf, argv[1]);
//	//char * p = strchr(buf, '.');
//	//strcpy(p, ".s\0");
//
//
//	//freopen(buf, "w", stdout);
//	//print_linked_list(final_instruction_list);
//
//
//
//    return 0;
//}
