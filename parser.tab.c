/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */


/* Kevin Tai    krt752  kevin.r.tai@utexas.edu
 * Ziqiu Chen   zc3428  stevenchen@utexas.edu
 */

#include "parser-defs.h"

int yylex();
extern int yy_scan_string(const char* c);
int yyerror(const char* p)
{ 
  if(parser_error_fn != NULL) {
    parser_error_fn("At line " + int_to_string(curr_lineno) + ": " + string(p));
  }
  return 1;
};

/* Helper function that parses lambda expressions. */
Expression* parse_lambda(Expression* expr2, Expression* expr4) {
    if(expr2->get_type() == AST_IDENTIFIER_LIST) {
        AstIdentifierList* id_list = static_cast<AstIdentifierList*>(expr2);
        return AstLambda::make(id_list, expr4);
    } else if(expr2->get_type() == AST_IDENTIFIER) {
        AstIdentifier* id = static_cast<AstIdentifier*>(expr2);
        return AstLambda::make(id, expr4);
    } else {
        return 0;
    }
}

/* Helper function that parses let expression */
Expression* parse_let(Expression* expr2, Expression* expr4, Expression* expr6) {
    assert(expr2->get_type() == AST_IDENTIFIER);
    AstIdentifier* id = static_cast<AstIdentifier*>(expr2);
    return AstLet::make(id, expr4, expr6);
}


#line 106 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TOKEN_READSTRING = 258,
    TOKEN_READINT = 259,
    TOKEN_PRINT = 260,
    TOKEN_ISNIL = 261,
    TOKEN_HD = 262,
    TOKEN_TL = 263,
    TOKEN_CONS = 264,
    TOKEN_NIL = 265,
    TOKEN_DOT = 266,
    TOKEN_WITH = 267,
    TOKEN_LET = 268,
    TOKEN_PLUS = 269,
    TOKEN_MINUS = 270,
    TOKEN_IDENTIFIER = 271,
    TOKEN_TIMES = 272,
    TOKEN_DIVIDE = 273,
    TOKEN_INT = 274,
    TOKEN_LPAREN = 275,
    TOKEN_RPAREN = 276,
    TOKEN_LBRACKET = 277,
    TOKEN_RBRACKET = 278,
    TOKEN_LCURLY = 279,
    TOKEN_RCURLY = 280,
    TOKEN_AND = 281,
    TOKEN_OR = 282,
    TOKEN_EQ = 283,
    TOKEN_NEQ = 284,
    TOKEN_GT = 285,
    TOKEN_GEQ = 286,
    TOKEN_LT = 287,
    TOKEN_LEQ = 288,
    TOKEN_IF = 289,
    TOKEN_THEN = 290,
    TOKEN_ELSE = 291,
    TOKEN_LAMBDA = 292,
    TOKEN_FUN = 293,
    TOKEN_COMMA = 294,
    TOKEN_STRING = 295,
    TOKEN_ERROR = 296,
    TOKEN_IN = 297,
    TOKEN_FLOAT = 298,
    TOKEN_LEN = 299,
    TOKEN_DEL = 300,
    TOKEN_COLON = 301,
    TOKEN_LIBCALL = 302,
    EXPR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
<<<<<<< HEAD
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   468
=======
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236
>>>>>>> works?

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
<<<<<<< HEAD
#define YYNSTATES  106
=======
#define YYNSTATES  83
>>>>>>> works?

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   107,   114,   121,   127,   131,   135,   139,
     150,   160,   164,   168,   172,   176,   180,   184,   188,   192,
     196,   200,   204,   208,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   248,   252,   256,   260,   264,   268,   278,
     285,   291,   303,   315,   324,   333,   343,   351,   366,   373,
     378,   400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_READSTRING", "TOKEN_READINT",
  "TOKEN_PRINT", "TOKEN_ISNIL", "TOKEN_HD", "TOKEN_TL", "TOKEN_CONS",
  "TOKEN_NIL", "TOKEN_DOT", "TOKEN_WITH", "TOKEN_LET", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_IDENTIFIER", "TOKEN_TIMES", "TOKEN_DIVIDE",
  "TOKEN_INT", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACKET",
  "TOKEN_RBRACKET", "TOKEN_LCURLY", "TOKEN_RCURLY", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_EQ", "TOKEN_NEQ", "TOKEN_GT", "TOKEN_GEQ", "TOKEN_LT",
  "TOKEN_LEQ", "TOKEN_IF", "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_LAMBDA",
  "TOKEN_FUN", "TOKEN_COMMA", "TOKEN_STRING", "TOKEN_ERROR", "TOKEN_IN",
  "TOKEN_FLOAT", "TOKEN_LEN", "TOKEN_DEL", "TOKEN_COLON", "TOKEN_LIBCALL",
  "EXPR", "$accept", "program", "expression", "libcall", "identifier",
  "dict_list", "array_list", "expression_list", "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

<<<<<<< HEAD
#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))
=======
#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))
>>>>>>> works?

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
     186,   -61,   -61,   186,   186,   186,   186,   -61,   -15,   -61,
     -61,   186,   144,   186,   186,   -15,   -15,   -61,   -61,   -61,
     186,     8,   423,   -61,    -9,   423,     6,   -61,   -61,    -2,
     101,     9,   -61,   269,    -4,   219,    16,   295,   -12,    31,
      45,   423,   -61,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   -15,   186,   101,
     -61,   -61,   186,   -61,   186,   -61,   186,   -15,   186,   -15,
       6,    61,    61,     6,     6,    14,    14,    58,    58,    58,
      58,    58,    58,     7,   -61,   320,   269,   -61,   346,   372,
     -61,   423,    32,   186,   186,   186,   186,   423,   244,   -61,
     423,   397,   186,   186,   346,   423
=======
     114,   -48,   -48,   114,   114,   114,   114,   -48,   -15,    -9,
     -48,   114,   114,   -15,   -15,   -48,   -48,     8,    45,   -48,
     -48,    45,     5,   -48,   -48,   -48,    -7,   -15,    79,    -1,
     205,   -12,    13,    20,   -48,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   -48,
      79,   -48,   -48,   114,   -15,   114,   -15,     5,    48,    48,
       5,     5,    16,    16,     4,     4,     4,     4,     4,     4,
     140,   184,   -48,    45,    25,   114,   114,   114,    45,    45,
     162,   114,    45
>>>>>>> works?
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       0,    14,    13,     0,     0,     0,     0,    12,     0,    40,
       3,     0,     0,     0,     0,     0,     0,     5,    38,     4,
       0,     0,     2,     6,     7,    15,    30,    32,    33,     0,
      49,     0,    34,    46,     0,     0,     0,     0,    51,     0,
       0,    16,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      47,    35,     0,    36,     0,    37,     0,     0,     0,     0,
      31,    26,    27,    28,    29,    25,    24,    18,    19,    21,
      22,    20,    23,    17,    39,     0,    45,    44,    43,     0,
      50,     9,     0,     0,     0,     0,     0,     8,     0,    41,
      11,     0,     0,     0,    42,    10
=======
       0,    13,    12,     0,     0,     0,     0,    11,     0,    34,
       3,     0,     0,     0,     0,     4,    32,     0,     2,     5,
       6,    14,    27,    29,    30,    34,     0,     0,    37,     0,
       0,    39,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      36,    35,    31,     0,     0,     0,     0,    28,    23,    24,
      25,    26,    22,    21,    15,    16,    18,    19,    17,    20,
       0,     0,    38,     8,     0,     0,     0,     0,     7,    10,
       0,     0,     9
>>>>>>> works?
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -61,   -61,     0,   -61,     2,   -33,     1,    54,   -60
=======
     -48,   -48,     0,   -48,     2,    17,   -47
>>>>>>> works?
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD
      -1,    21,    59,    23,    24,    36,    34,    60,    39
=======
      -1,    17,    50,    19,    20,    51,    32
>>>>>>> works?
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      22,     9,    57,    25,    26,    27,    28,    90,    42,    92,
      29,    30,    33,    35,    37,    43,    43,    38,    40,    63,
      41,    44,    45,    43,    46,    47,    58,    67,    44,    45,
      61,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    65,    68,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    69,    85,    84,
      96,    99,    86,    87,    88,    31,    89,    43,    91,    38,
      43,    38,    44,    45,     0,    46,    47,     0,    46,    47,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,    97,    98,   100,   101,     0,     0,     0,
       0,     0,   104,   105,     1,     2,     3,     4,     5,     6,
      43,     7,     0,     0,     8,    44,    45,     9,    46,    47,
      10,    11,     0,    12,     0,    13,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    14,     0,     0,    15,    16,
       0,    17,    18,     0,    19,    20,    56,     1,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     8,     0,     0,
       9,     0,     0,    10,    11,     0,    12,    32,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,    17,    18,     0,    19,    20,     1,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     8,
       0,     0,     9,     0,     0,    10,    11,     0,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,    17,    18,    43,    19,
      20,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    43,     0,     0,     0,     0,    44,    45,
       0,    46,    47,     0,    56,    64,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    43,     0,
       0,     0,     0,    44,    45,     0,    46,    47,     0,    56,
     102,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,    55,     0,    43,     0,     0,     0,    62,    44,
      45,     0,    46,    47,    56,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    43,
      66,     0,     0,     0,    44,    45,     0,    46,    47,     0,
      56,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,     0,    43,     0,     0,     0,     0,
      44,    45,    93,    46,    47,    56,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    43,     0,     0,     0,    94,    44,    45,     0,    46,
      47,    56,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    43,     0,    95,     0,
       0,    44,    45,     0,    46,    47,     0,    56,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    43,     0,     0,     0,     0,    44,    45,   103,
      46,    47,    56,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56
=======
      18,    25,    27,    21,    22,    23,    24,    72,    34,    74,
      26,    28,    30,    35,    35,    31,    33,    48,    36,    37,
      52,    38,    39,    54,    55,    35,    40,    41,    29,    49,
      36,    37,    56,    38,    39,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    77,
       0,     0,     0,    71,    35,    73,    31,    35,    31,    36,
      37,     0,    38,    39,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    78,    79,    80,     0,     0,
       0,    82,     1,     2,     3,     4,     5,     6,    35,     7,
       0,     0,     8,    36,    37,     9,    38,    39,    10,    11,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    12,
       0,     0,    13,    14,     0,    15,    16,     1,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     8,     0,     0,
       9,     0,     0,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,    13,    14,    35,
      15,    16,     0,     0,    36,    37,     0,    38,    39,     0,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    35,     0,     0,     0,     0,    36,    37,    75,    38,
      39,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    35,     0,     0,     0,     0,    36,    37,
      81,    38,    39,     0,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    35,     0,    76,     0,     0,    36,
      37,     0,    38,    39,     0,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    53
>>>>>>> works?
};

static const yytype_int8 yycheck[] =
{
<<<<<<< HEAD
       0,    16,    11,     3,     4,     5,     6,    67,     0,    69,
       8,    11,    12,    13,    14,     9,     9,    15,    16,    23,
      20,    14,    15,     9,    17,    18,    28,    39,    14,    15,
      21,    17,    18,    26,    27,    28,    29,    30,    31,    32,
      33,    25,    11,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    12,    58,    57,
      28,    94,    62,    62,    64,    11,    66,     9,    68,    67,
       9,    69,    14,    15,    -1,    17,    18,    -1,    17,    18,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,   102,   103,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    43,    44,    45,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    -1,
      16,    -1,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    37,    38,    -1,    40,    41,    -1,    43,    44,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    20,    -1,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    38,    -1,    40,    41,     9,    43,
      44,    -1,    -1,    14,    15,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,     9,    -1,    -1,    -1,    -1,    14,    15,
      -1,    17,    18,    -1,    45,    46,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,     9,    -1,
      -1,    -1,    -1,    14,    15,    -1,    17,    18,    -1,    45,
      46,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,     9,    -1,    -1,    -1,    39,    14,
      15,    -1,    17,    18,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     9,
      35,    -1,    -1,    -1,    14,    15,    -1,    17,    18,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    42,    17,    18,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,     9,    -1,    -1,    -1,    39,    14,    15,    -1,    17,
      18,    45,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,     9,    -1,    36,    -1,
      -1,    14,    15,    -1,    17,    18,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,    42,
      17,    18,    45,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45
=======
       0,    16,    11,     3,     4,     5,     6,    54,     0,    56,
       8,    11,    12,     9,     9,    13,    14,    24,    14,    15,
      21,    17,    18,    35,    11,     9,    22,    23,    11,    27,
      14,    15,    12,    17,    18,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    24,
      -1,    -1,    -1,    53,     9,    55,    54,     9,    56,    14,
      15,    -1,    17,    18,    -1,    17,    18,    22,    23,    24,
      25,    26,    27,    28,    29,    75,    76,    77,    -1,    -1,
      -1,    81,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    33,    34,    -1,    36,    37,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    -1,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,     9,
      36,    37,    -1,    -1,    14,    15,    -1,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,     9,    -1,    -1,    -1,    -1,    14,    15,    38,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,
      38,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,     9,    -1,    32,    -1,    -1,    14,
      15,    -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31
>>>>>>> works?
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    13,    16,
<<<<<<< HEAD
      19,    20,    22,    24,    34,    37,    38,    40,    41,    43,
      44,    50,    51,    52,    53,    51,    51,    51,    51,    53,
      51,    56,    23,    51,    55,    51,    54,    51,    53,    57,
      53,    51,     0,     9,    14,    15,    17,    18,    26,    27,
      28,    29,    30,    31,    32,    33,    45,    11,    28,    51,
      56,    21,    39,    23,    46,    25,    35,    39,    11,    12,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    53,    51,    51,    55,    51,    51,
      57,    51,    57,    42,    39,    36,    28,    51,    51,    54,
      51,    51,    46,    42,    51,    51
=======
      19,    20,    30,    33,    34,    36,    37,    42,    43,    44,
      45,    43,    43,    43,    43,    16,    45,    11,    43,    46,
      43,    45,    47,    45,     0,     9,    14,    15,    17,    18,
      22,    23,    24,    25,    26,    27,    28,    29,    24,    45,
      43,    46,    21,    31,    35,    11,    12,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    47,    43,    47,    38,    32,    24,    43,    43,
      43,    38,    43
>>>>>>> works?
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     6,     4,
       8,     6,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     2,     2,     3,     3,     3,     1,     3,
       1,     5,     7,     3,     3,     3,     1,     2,     2,     1,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 103 "parser.y" /* yacc.c:1646  */
    {
	res_expr = (yyval);
}
#line 1429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "parser.y" /* yacc.c:1646  */
    {
  	string lexeme = GET_LEXEME((yyvsp[0]));
  	long int val = string_to_int(lexeme);
  	Expression* e = AstInt::make(val);
  	(yyval) = e;
}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "parser.y" /* yacc.c:1646  */
    {
    string lexeme = GET_LEXEME((yyvsp[0]));
    double val = string_to_float(lexeme);
    Expression* e = AstFloat::make(val);
    (yyval) = e;
}
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "parser.y" /* yacc.c:1646  */
    {
	string lexeme = GET_LEXEME((yyvsp[0]));
  	Expression* e = AstString::make(lexeme);
  	(yyval) = e;
}
#line 1461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 128 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = (yyvsp[0]);
}
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "parser.y" /* yacc.c:1646  */
    {
  	(yyval) = (yyvsp[0]); 
}
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = parse_let((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
}
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "parser.y" /* yacc.c:1646  */
    {
    Expression* lambda = parse_lambda((yyvsp[-2]), (yyvsp[0]));
    if(lambda != 0) {
        (yyval) = lambda; 
    } else {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR;
    }
}
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 151 "parser.y" /* yacc.c:1646  */
    {
    Expression* lambda = parse_lambda((yyvsp[-4]), (yyvsp[-2]));
    if (lambda == 0) {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR;
    }
    (yyval) = parse_let((yyvsp[-6]), lambda, (yyvsp[0]));
}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBranch::make((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstNil::make();
}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 169 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstRead::make(true);
}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstRead::make(false);
}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstUnOp::make(PRINT, (yyvsp[0]));
}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 181 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstUnOp::make(LEN, (yyvsp[0]));
}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBinOp::make(DEL, (yyvsp[-2]), (yyvsp[0]));
}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(EQ, (yyvsp[-2]), (yyvsp[0]));
}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(NEQ, (yyvsp[-2]), (yyvsp[0]));
}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(LT, (yyvsp[-2]), (yyvsp[0]));
}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(GT, (yyvsp[-2]), (yyvsp[0]));
}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(GEQ, (yyvsp[-2]), (yyvsp[0]));
}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(LEQ, (yyvsp[-2]), (yyvsp[0]));
}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 213 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(OR, (yyvsp[-2]), (yyvsp[0]));
}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 217 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(AND, (yyvsp[-2]), (yyvsp[0]));
}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = AstBinOp::make(PLUS, (yyvsp[-2]), (yyvsp[0]));
}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBinOp::make(MINUS, (yyvsp[-2]), (yyvsp[0]));
}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 229 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBinOp::make(TIMES, (yyvsp[-2]), (yyvsp[0]));
}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 233 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBinOp::make(DIVIDE, (yyvsp[-2]), (yyvsp[0]));
}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 237 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstUnOp::make(ISNIL, (yyvsp[0]));
}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 241 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstBinOp::make(CONS, (yyvsp[-2]), (yyvsp[0]));
}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 245 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstUnOp::make(HD, (yyvsp[0]));
}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 249 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstUnOp::make(TL, (yyvsp[0]));
}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 253 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = AstArray::make();
}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-1]);
}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 269 "parser.y" /* yacc.c:1646  */
    {
   // do not change the error rule
   string lexeme = GET_LEXEME((yyvsp[0]));
   string error = "Lexing error: ";
   if(lexeme != "") error += lexeme;
   yyerror(error.c_str());
   YYERROR;
}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 279 "parser.y" /* yacc.c:1646  */
    {
  string lib = GET_LEXEME((yyvsp[-2]));
  AstIdentifier* func = static_cast<AstIdentifier*>((yyvsp[0]));
  (yyval) = AstLibCall::make(lib, func);
}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 286 "parser.y" /* yacc.c:1646  */
    {
	string lexeme = GET_LEXEME((yyvsp[0]));
  (yyval) = AstIdentifier::make(lexeme);
}
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 292 "parser.y" /* yacc.c:1646  */
    {
    Expression* expr1 = (yyvsp[-4]);
    Expression* expr3 = (yyvsp[-2]);
    Expression* expr5 = (yyvsp[0]);
    AstDict* ast_dict = static_cast<AstDict*>(expr5);
    vector<pair<Expression*, Expression*> > vec = ast_dict->get_vec();
    vec.insert(vec.begin(), make_pair(expr1, expr3));
    AstDict* new_dict = AstDict::make(vec);
    vector<pair<Expression*, Expression*> > final_vec = new_dict->get_vec();
    (yyval) = new_dict;
}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 304 "parser.y" /* yacc.c:1646  */
    {
    // for nested dicts
    Expression* expr1 = (yyvsp[-6]);
    Expression* expr3 = (yyvsp[-4]);
    Expression* expr5 = (yyvsp[-2]);
    Expression* expr7 = (yyvsp[0]);
    vector<pair<Expression*, Expression*> > vec;
    vec.push_back(make_pair(expr1, expr3));
    vec.push_back(make_pair(expr5, expr7));
    (yyval) = AstDict::make(vec);
}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "parser.y" /* yacc.c:1646  */
    {
    Expression* expr1 = (yyvsp[-2]);
    Expression* expr3 = (yyvsp[0]);
    vector<pair<Expression*, Expression*> > vec;
    vec.push_back(make_pair(expr1, expr3));
    (yyval) = AstDict::make(vec);
}
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 325 "parser.y" /* yacc.c:1646  */
    {
  Expression* expr1 = (yyvsp[-2]);
  Expression* expr2 = (yyvsp[0]);
  AstArray* arr_list = static_cast<AstArray*>(expr2);
  vector<Expression*> vec = arr_list->get_expressions();
  vec.insert(vec.begin(), expr1);
  (yyval) = AstArray::make(vec);
}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 334 "parser.y" /* yacc.c:1646  */
    {
  // for nested arrays
  Expression* expr1 = (yyvsp[-2]);
  Expression* expr2 = (yyvsp[0]);
  vector<Expression*> vec;
  vec.push_back(expr1);
  vec.push_back(expr2);
  (yyval) = AstArray::make(vec);
}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 344 "parser.y" /* yacc.c:1646  */
    {
  Expression* expr1 = (yyvsp[0]);
  vector<Expression*> vec;
  vec.push_back(expr1);
  (yyval) = AstArray::make(vec);
}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 352 "parser.y" /* yacc.c:1646  */
    {
	Expression* expr1 = (yyvsp[-1]);
    Expression* expr2 = (yyvsp[0]);
    /* We have to handle the case where we have an expression list and just a single expression */
	 if (expr2->get_type() == AST_EXPRESSION_LIST) {
	     AstExpressionList* expr_list = static_cast<AstExpressionList*>(expr2);
         vector<Expression*> vec = expr_list->get_expressions();
         vec.insert(vec.begin(), expr1);
         (yyval) = AstExpressionList::make(vec);
     } else {
        AstExpressionList* expr_list = AstExpressionList::make(expr1);
        (yyval) = expr_list->append_exp(expr2);
     }
}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 367 "parser.y" /* yacc.c:1646  */
    {
    Expression* expr1 = (yyvsp[-1]);
    Expression* expr2 = (yyvsp[0]);
    AstExpressionList* expr_list = AstExpressionList::make(expr1);
    (yyval) = expr_list->append_exp(expr2);
}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 374 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 379 "parser.y" /* yacc.c:1646  */
    {
    Expression* expr1 = (yyvsp[-2]);
    Expression* expr3 = (yyvsp[0]);
    assert(expr1->get_type() == AST_IDENTIFIER);
    AstIdentifier* id1 = static_cast<AstIdentifier*>(expr1);
    /* We must handle the case where we have an identifier list and just a single identifier */
	if (expr3->get_type() == AST_IDENTIFIER_LIST) {
	    AstIdentifierList* expr_list = static_cast<AstIdentifierList*>(expr3);
        vector<AstIdentifier*> vec = expr_list->get_ids();
        vec.insert(vec.begin(), id1);
        (yyval) = AstIdentifierList::make(vec);
    } else if(expr3->get_type() == AST_IDENTIFIER) {
        AstIdentifier* id2 = static_cast<AstIdentifier*>(expr3);
        AstIdentifierList* expr_list = AstIdentifierList::make(id1);
        (yyval) = expr_list->append_id(id2);
    } else {
        string error = "Lexing error: ";
        yyerror(error.c_str());
        YYERROR; 
    }
}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 401 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1920 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
  return yyresult;
}
