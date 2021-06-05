/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <iostream>
#include "ASTNodes.hpp"

using namespace std;

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

vector<DeclarationNode*> *root;

extern int yylex(void);

void yyerror(std::string s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/


#line 98 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_TRUE = 5,                       /* TRUE  */
  YYSYMBOL_FALSE = 6,                      /* FALSE  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_INT_TYPE = 14,                  /* INT_TYPE  */
  YYSYMBOL_VOID_TYPE = 15,                 /* VOID_TYPE  */
  YYSYMBOL_DOUBLE_TYPE = 16,               /* DOUBLE_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 17,                /* FLOAT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 18,                 /* CHAR_TYPE  */
  YYSYMBOL_BOOL_TYPE = 19,                 /* BOOL_TYPE  */
  YYSYMBOL_EXTERN_TYPE = 20,               /* EXTERN_TYPE  */
  YYSYMBOL_LP = 21,                        /* LP  */
  YYSYMBOL_RP = 22,                        /* RP  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_LB = 25,                        /* LB  */
  YYSYMBOL_RB = 26,                        /* RB  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 29,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 30,                /* PLUSASSIGN  */
  YYSYMBOL_MINUSASSIGN = 31,               /* MINUSASSIGN  */
  YYSYMBOL_MULTASSIGN = 32,                /* MULTASSIGN  */
  YYSYMBOL_DIVASSIGN = 33,                 /* DIVASSIGN  */
  YYSYMBOL_MODASSIGN = 34,                 /* MODASSIGN  */
  YYSYMBOL_BORASSIGN = 35,                 /* BORASSIGN  */
  YYSYMBOL_BXORASSIGN = 36,                /* BXORASSIGN  */
  YYSYMBOL_BANDASSIGN = 37,                /* BANDASSIGN  */
  YYSYMBOL_SRASSIGN = 38,                  /* SRASSIGN  */
  YYSYMBOL_SLASSIGN = 39,                  /* SLASSIGN  */
  YYSYMBOL_LOR = 40,                       /* LOR  */
  YYSYMBOL_LAND = 41,                      /* LAND  */
  YYSYMBOL_BOR = 42,                       /* BOR  */
  YYSYMBOL_BAND = 43,                      /* BAND  */
  YYSYMBOL_BXOR = 44,                      /* BXOR  */
  YYSYMBOL_SR = 45,                        /* SR  */
  YYSYMBOL_SL = 46,                        /* SL  */
  YYSYMBOL_PLUS = 47,                      /* PLUS  */
  YYSYMBOL_MINUS = 48,                     /* MINUS  */
  YYSYMBOL_MULT = 49,                      /* MULT  */
  YYSYMBOL_DIV = 50,                       /* DIV  */
  YYSYMBOL_MOD = 51,                       /* MOD  */
  YYSYMBOL_LNOT = 52,                      /* LNOT  */
  YYSYMBOL_BNOT = 53,                      /* BNOT  */
  YYSYMBOL_INCR = 54,                      /* INCR  */
  YYSYMBOL_DECR = 55,                      /* DECR  */
  YYSYMBOL_EQ = 56,                        /* EQ  */
  YYSYMBOL_NEQ = 57,                       /* NEQ  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_GT = 59,                        /* GT  */
  YYSYMBOL_LTE = 60,                       /* LTE  */
  YYSYMBOL_GTE = 61,                       /* GTE  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_declarationList = 64,           /* declarationList  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_varDeclaration = 66,            /* varDeclaration  */
  YYSYMBOL_idList = 67,                    /* idList  */
  YYSYMBOL_arrayPost = 68,                 /* arrayPost  */
  YYSYMBOL_arrayConstList = 69,            /* arrayConstList  */
  YYSYMBOL_baseType = 70,                  /* baseType  */
  YYSYMBOL_funDeclaration = 71,            /* funDeclaration  */
  YYSYMBOL_params = 72,                    /* params  */
  YYSYMBOL_paramList = 73,                 /* paramList  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_arrayPostParam = 75,            /* arrayPostParam  */
  YYSYMBOL_compoundStmt = 76,              /* compoundStmt  */
  YYSYMBOL_localDeclarations = 77,         /* localDeclarations  */
  YYSYMBOL_statementList = 78,             /* statementList  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_expressionStmt = 80,            /* expressionStmt  */
  YYSYMBOL_selectionStmt = 81,             /* selectionStmt  */
  YYSYMBOL_iterationStmt = 82,             /* iterationStmt  */
  YYSYMBOL_whileStmt = 83,                 /* whileStmt  */
  YYSYMBOL_forStmt = 84,                   /* forStmt  */
  YYSYMBOL_returnStmt = 85,                /* returnStmt  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_assop = 87,                     /* assop  */
  YYSYMBOL_var = 88,                       /* var  */
  YYSYMBOL_operand = 89,                   /* operand  */
  YYSYMBOL_prefix = 90,                    /* prefix  */
  YYSYMBOL_single = 91,                    /* single  */
  YYSYMBOL_call = 92,                      /* call  */
  YYSYMBOL_args = 93,                      /* args  */
  YYSYMBOL_argList = 94                    /* argList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   507

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   135,   139,   145,   146,   149,   152,   157,
     164,   168,   172,   176,   182,   186,   208,   212,   217,   218,
     219,   220,   221,   224,   225,   226,   227,   230,   231,   234,
     238,   244,   245,   248,   251,   254,   260,   261,   262,   263,
     266,   270,   276,   280,   286,   287,   288,   289,   290,   293,
     294,   297,   298,   301,   302,   305,   310,   315,   316,   319,
     320,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   336,   337,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   365,   366,   367,   370,
     371,   372,   373,   374,   375,   376,   380,   384,   385,   388,
     392
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "TRUE",
  "FALSE", "CHAR", "ID", "IF", "ELSE", "WHILE", "RETURN", "FOR",
  "INT_TYPE", "VOID_TYPE", "DOUBLE_TYPE", "FLOAT_TYPE", "CHAR_TYPE",
  "BOOL_TYPE", "EXTERN_TYPE", "LP", "RP", "LC", "RC", "LB", "RB",
  "SEMICOLON", "COMMA", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN",
  "MULTASSIGN", "DIVASSIGN", "MODASSIGN", "BORASSIGN", "BXORASSIGN",
  "BANDASSIGN", "SRASSIGN", "SLASSIGN", "LOR", "LAND", "BOR", "BAND",
  "BXOR", "SR", "SL", "PLUS", "MINUS", "MULT", "DIV", "MOD", "LNOT",
  "BNOT", "INCR", "DECR", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "$accept",
  "program", "declarationList", "declaration", "varDeclaration", "idList",
  "arrayPost", "arrayConstList", "baseType", "funDeclaration", "params",
  "paramList", "param", "arrayPostParam", "compoundStmt",
  "localDeclarations", "statementList", "statement", "expressionStmt",
  "selectionStmt", "iterationStmt", "whileStmt", "forStmt", "returnStmt",
  "expression", "assop", "var", "operand", "prefix", "single", "call",
  "args", "argList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
#endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,  -151,    15,  -151,  -151,  -151,  -151,   342,    38,   189,
    -151,  -151,    31,  -151,    35,    74,    83,  -151,  -151,    82,
     -21,   478,    75,    80,   478,   103,   280,   110,  -151,   101,
    -151,   111,   116,   104,  -151,   478,   478,   119,   105,  -151,
    -151,  -151,  -151,  -151,    20,   280,  -151,  -151,  -151,  -151,
     273,   346,    29,  -151,  -151,   140,  -151,   121,   124,   120,
     135,   107,   137,   138,   135,  -151,   280,   139,  -151,   294,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,  -151,   144,   499,   280,     5,   141,    81,  -151,  -151,
     136,   145,  -151,  -151,   143,   147,  -151,  -151,   367,   387,
     406,   423,   -32,   276,   276,    -3,    -3,  -151,  -151,  -151,
     440,   440,   191,   191,   191,   191,   324,  -151,    30,  -151,
    -151,   159,  -151,   187,   174,   176,   109,   179,  -151,  -151,
    -151,   193,  -151,   175,   208,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,   183,  -151,  -151,  -151,   280,  -151,   195,   499,
    -151,   192,   280,   280,  -151,   197,   280,    54,  -151,  -151,
     241,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   203,   204,
    -151,   206,  -151,   269,   269,   280,   220,  -151,   207,   269,
     280,  -151,   221,   269,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,     0,    19,    20,    21,    22,     0,     0,     2,
       4,     5,     0,     6,     0,     0,     0,     1,     3,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
      28,     0,     0,    27,    30,     0,     0,     0,     0,   101,
     102,   104,   105,   103,    72,     0,    98,    97,    96,    13,
      99,    60,     0,    95,   100,     0,     8,     0,    10,    31,
       0,     0,     0,     0,     0,    14,   107,    73,    99,     0,
      61,    62,    63,    64,    65,    66,    68,    69,    67,    71,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,    32,     0,    24,    29,
       0,     0,    23,   110,     0,   108,    93,    59,    74,    75,
      76,    78,    77,    86,    85,    87,    88,    89,    90,    91,
      79,    80,    81,    82,    83,    84,     0,    15,     0,    17,
      11,     0,    33,     0,     0,     0,     0,     0,    39,    50,
      40,     0,    45,     0,     0,    42,    44,    46,    47,    53,
      54,    48,     0,    26,    25,   106,     0,    92,     0,     0,
      34,     0,     0,     0,    57,     0,     0,    12,    37,    41,
       0,    38,    43,    49,   109,     9,    16,    35,     0,     0,
      58,     0,    36,     0,     0,     0,    51,    55,     0,     0,
       0,    52,     0,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,   242,  -102,  -151,   211,  -151,     3,  -151,
     -15,  -151,   196,  -151,    91,  -151,   106,  -150,  -151,  -151,
    -151,  -151,  -151,  -151,   -24,  -151,   -26,   -23,  -151,   -51,
    -151,  -151,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    20,    27,   138,    31,    13,
      32,    33,    34,   106,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    81,    68,    51,    52,    53,
      54,   114,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,   101,    49,    12,   182,   150,    28,    29,   141,    37,
      16,    85,    12,    87,    88,    89,    90,    91,    92,    93,
      62,    63,    69,    14,    94,    95,    96,    97,    98,    99,
     182,   142,    39,    40,    41,    42,    43,    44,    17,    19,
      50,    66,   113,   196,   197,    25,    91,    92,    93,   201,
     100,   179,   139,   204,   168,    50,    21,   117,   169,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,    50,    25,
     140,    50,    22,    26,    39,    40,    41,    42,    43,    44,
     144,    23,   145,   146,   147,     1,    35,     3,     4,     5,
       6,    36,    45,    24,   107,   148,    38,    25,   149,    58,
     151,    26,    39,    40,    41,    42,    43,    44,   186,    59,
      50,     1,   175,     3,     4,     5,     6,    50,    50,    46,
      45,    65,    61,    47,    48,    55,   174,    56,    60,    57,
      50,    64,   184,   102,   103,   105,    50,    50,   188,   189,
      50,   108,   191,   104,    50,   112,   151,    46,   107,   110,
     111,    47,    48,   163,    55,   165,   143,    50,    50,    50,
     137,   198,   164,    50,    50,   166,   202,    50,    39,    40,
      41,    42,    43,    44,   144,   170,   145,   146,   147,     1,
     171,     3,     4,     5,     6,   172,    45,   173,   107,   178,
     176,   177,   149,     1,     2,     3,     4,     5,     6,     7,
     183,    39,    40,    41,    42,    43,    44,   144,   187,   145,
     146,   147,   185,    46,   190,   193,   194,    47,    48,    45,
     199,   107,   181,   195,   200,   149,    87,    88,    89,    90,
      91,    92,    93,   203,    39,    40,    41,    42,    43,    44,
     144,    18,   145,   146,   147,    67,    46,   109,     0,   180,
      47,    48,    45,     0,   107,   192,     0,     0,   149,     0,
       0,     0,    39,    40,    41,    42,    43,    44,   144,     0,
     145,   146,   147,    39,    40,    41,    42,    43,    44,    46,
      45,     0,   107,    47,    48,     0,   149,     0,     0,     0,
       0,    45,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     0,     0,     0,   116,    46,     0,     0,
       0,    47,    48,    89,    90,    91,    92,    93,    46,     0,
       0,     0,    47,    48,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   167,     0,     0,     0,
      94,    95,    96,    97,    98,    99,     1,    15,     3,     4,
       5,     6,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    87,    88,
      89,    90,    91,    92,    93,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,    87,    88,    89,    90,    91,
      92,    93,     1,    30,     3,     4,     5,     6,    96,    97,
      98,    99,    39,    40,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      26,    52,    26,     0,   154,   107,    27,    28,     3,    24,
       7,    43,     9,    45,    46,    47,    48,    49,    50,    51,
      35,    36,    45,     8,    56,    57,    58,    59,    60,    61,
     180,    26,     3,     4,     5,     6,     7,     8,     0,     8,
      66,    21,    66,   193,   194,    25,    49,    50,    51,   199,
      21,   153,   103,   203,    24,    81,    21,    81,    28,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   104,    25,
     104,   107,     8,    29,     3,     4,     5,     6,     7,     8,
       9,     8,    11,    12,    13,    14,    21,    16,    17,    18,
      19,    21,    21,    21,    23,    24,     3,    25,    27,     8,
     107,    29,     3,     4,     5,     6,     7,     8,   169,     8,
     146,    14,   146,    16,    17,    18,    19,   153,   154,    48,
      21,    26,    28,    52,    53,    25,    27,    27,    22,    29,
     166,    22,   166,     3,    23,    25,   172,   173,   172,   173,
     176,    60,   176,    29,   180,    64,   153,    48,    23,    22,
      22,    52,    53,    27,    25,    22,    25,   193,   194,   195,
      26,   195,    27,   199,   200,    28,   200,   203,     3,     4,
       5,     6,     7,     8,     9,    26,    11,    12,    13,    14,
       3,    16,    17,    18,    19,    21,    21,    21,    23,    24,
      21,     8,    27,    14,    15,    16,    17,    18,    19,    20,
      27,     3,     4,     5,     6,     7,     8,     9,    26,    11,
      12,    13,    27,    48,    27,    22,    22,    52,    53,    21,
      10,    23,    24,    27,    27,    27,    45,    46,    47,    48,
      49,    50,    51,    22,     3,     4,     5,     6,     7,     8,
       9,     9,    11,    12,    13,    44,    48,    61,    -1,   153,
      52,    53,    21,    -1,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,     3,     4,     5,     6,     7,     8,    48,
      21,    -1,    23,    52,    53,    -1,    27,    -1,    -1,    -1,
      -1,    21,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    22,    48,    -1,    -1,
      -1,    52,    53,    47,    48,    49,    50,    51,    48,    -1,
      -1,    -1,    52,    53,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    22,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    14,    15,    16,    17,
      18,    19,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    61,    45,    46,    47,    48,    49,
      50,    51,    14,    15,    16,    17,    18,    19,    58,    59,
      60,    61,     3,     4,     5,     6,     7,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    16,    17,    18,    19,    20,    63,    64,
      65,    66,    70,    71,     8,    15,    70,     0,    65,     8,
      67,    21,     8,     8,    21,    25,    29,    68,    27,    28,
      15,    70,    72,    73,    74,    21,    21,    72,     3,     3,
       4,     5,     6,     7,     8,    21,    48,    52,    53,    86,
      88,    89,    90,    91,    92,    25,    27,    29,     8,     8,
      22,    28,    72,    72,    22,    26,    21,    68,    88,    89,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    87,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    56,    57,    58,    59,    60,    61,
      21,    91,     3,    23,    29,    25,    75,    23,    76,    74,
      22,    22,    76,    86,    93,    94,    22,    86,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    26,    69,    91,
      86,     3,    26,    25,     9,    11,    12,    13,    24,    27,
      66,    70,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    27,    27,    22,    28,    22,    24,    28,
      26,     3,    21,    21,    27,    86,    21,     8,    24,    66,
      78,    24,    79,    27,    86,    27,    91,    26,    86,    86,
      27,    86,    24,    22,    22,    27,    79,    79,    86,    10,
      27,    79,    86,    22,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    92,    93,    93,    94,
      94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     8,
       3,     5,     1,     3,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     6,     6,     7,     7,     1,     1,     3,
       1,     2,     3,     2,     3,     4,     4,     3,     3,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     1,     1,     5,     9,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     1,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: declarationList  */
#line 132 "parser.y"
                                    { root = (yyvsp[0].declarationNodeVec); }
#line 1397 "parser.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 135 "parser.y"
                                                 {
                        (yyvsp[-1].declarationNodeVec)->push_back((yyvsp[0].declarationNode));
                        (yyval.declarationNodeVec) = (yyvsp[-1].declarationNodeVec);
                    }
#line 1406 "parser.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 139 "parser.y"
                                    {
                        (yyval.declarationNodeVec) = new vector<DeclarationNode*>();
                        (yyval.declarationNodeVec)->push_back((yyvsp[0].declarationNode));
                    }
#line 1415 "parser.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 145 "parser.y"
                                   { (yyval.declarationNode) = new DeclarationNode((yyvsp[0].varDeclarationNode)); }
#line 1421 "parser.tab.c"
    break;

  case 6: /* declaration: funDeclaration  */
#line 146 "parser.y"
                                      { (yyval.declarationNode) = new DeclarationNode((yyvsp[0].funDeclarationNode)); }
#line 1427 "parser.tab.c"
    break;

  case 7: /* varDeclaration: baseType idList SEMICOLON  */
#line 149 "parser.y"
                                              { 
                        (yyval.varDeclarationNode) = new VarDeclarationNode((yyvsp[-2].stringNode), (yyvsp[-1].idListNodeVec), nullptr, nullptr);
                    }
#line 1435 "parser.tab.c"
    break;

  case 8: /* varDeclaration: baseType ID arrayPost SEMICOLON  */
#line 152 "parser.y"
                                                      {
                        auto v = new vector<IdListNode*>();
                        v-> push_back( new IdListNode( new string((yyvsp[-2].type_id)), nullptr) );
                        (yyval.varDeclarationNode) = new VarDeclarationNode((yyvsp[-3].stringNode), v, (yyvsp[-1].intVec), nullptr);
                    }
#line 1445 "parser.tab.c"
    break;

  case 9: /* varDeclaration: baseType ID arrayPost ASSIGN LC arrayConstList RC SEMICOLON  */
#line 157 "parser.y"
                                                                                      {
                        auto v = new vector<IdListNode*>();
                        v-> push_back( new IdListNode( new string((yyvsp[-6].type_id)), nullptr) );
                        (yyval.varDeclarationNode) = new VarDeclarationNode((yyvsp[-7].stringNode), v, (yyvsp[-5].intVec), (yyvsp[-2].singleNodeVec));
                    }
#line 1455 "parser.tab.c"
    break;

  case 10: /* idList: idList COMMA ID  */
#line 164 "parser.y"
                                    { 
                        (yyvsp[-2].idListNodeVec)->push_back(new IdListNode(new string((yyvsp[0].type_id)), nullptr));
                        (yyval.idListNodeVec) = (yyvsp[-2].idListNodeVec);
                    }
#line 1464 "parser.tab.c"
    break;

  case 11: /* idList: idList COMMA ID ASSIGN expression  */
#line 168 "parser.y"
                                                        {
                        (yyvsp[-4].idListNodeVec)->push_back(new IdListNode(new string((yyvsp[-2].type_id)), (yyvsp[0].expressionNode)));
                        (yyval.idListNodeVec) = (yyvsp[-4].idListNodeVec);
                    }
#line 1473 "parser.tab.c"
    break;

  case 12: /* idList: ID  */
#line 172 "parser.y"
                         { 
                        (yyval.idListNodeVec) = new vector<IdListNode*>();
                        (yyval.idListNodeVec)->push_back(new IdListNode(new string((yyvsp[0].type_id)), nullptr)); 
                    }
#line 1482 "parser.tab.c"
    break;

  case 13: /* idList: ID ASSIGN expression  */
#line 176 "parser.y"
                                           {
                        (yyval.idListNodeVec) = new vector<IdListNode*>();
                        (yyval.idListNodeVec)->push_back(new IdListNode(new string((yyvsp[-2].type_id)), (yyvsp[0].expressionNode))); 
                    }
#line 1491 "parser.tab.c"
    break;

  case 14: /* arrayPost: LB INT RB  */
#line 182 "parser.y"
                               {
                        (yyval.intVec) = new vector<int>();
                        (yyval.intVec)->push_back((yyvsp[-1].type_int));
                    }
#line 1500 "parser.tab.c"
    break;

  case 15: /* arrayPost: arrayPost LB INT RB  */
#line 186 "parser.y"
                                          {
                        (yyvsp[-3].intVec)->push_back((yyvsp[-1].type_int));
                        (yyval.intVec) = (yyvsp[-3].intVec);
                    }
#line 1509 "parser.tab.c"
    break;

  case 16: /* arrayConstList: arrayConstList COMMA single  */
#line 208 "parser.y"
                                                {
                        (yyvsp[-2].singleNodeVec)->push_back((yyvsp[0].singleNode));
                        (yyval.singleNodeVec) = (yyvsp[-2].singleNodeVec);
                    }
#line 1518 "parser.tab.c"
    break;

  case 17: /* arrayConstList: single  */
#line 212 "parser.y"
                             {
                        (yyval.singleNodeVec) = new vector<SingleNode*>();
                        (yyval.singleNodeVec)->push_back((yyvsp[0].singleNode));
                    }
#line 1527 "parser.tab.c"
    break;

  case 18: /* baseType: INT_TYPE  */
#line 217 "parser.y"
                             { (yyval.stringNode) = new string("INT_TYPE"); }
#line 1533 "parser.tab.c"
    break;

  case 19: /* baseType: DOUBLE_TYPE  */
#line 218 "parser.y"
                                  { (yyval.stringNode) = new string("DOUBLE_TYPE"); }
#line 1539 "parser.tab.c"
    break;

  case 20: /* baseType: FLOAT_TYPE  */
#line 219 "parser.y"
                                 { (yyval.stringNode) = new string("FLOAT_TYPE"); }
#line 1545 "parser.tab.c"
    break;

  case 21: /* baseType: CHAR_TYPE  */
#line 220 "parser.y"
                                { (yyval.stringNode) = new string("CHAR_TYPE"); }
#line 1551 "parser.tab.c"
    break;

  case 22: /* baseType: BOOL_TYPE  */
#line 221 "parser.y"
                                { (yyval.stringNode) = new string("BOOL_TYPE"); }
#line 1557 "parser.tab.c"
    break;

  case 23: /* funDeclaration: baseType ID LP params RP compoundStmt  */
#line 224 "parser.y"
                                                          { (yyval.funDeclarationNode) = new FunDeclarationNode((yyvsp[-5].stringNode), new string((yyvsp[-4].type_id)), (yyvsp[-2].paramVec), (yyvsp[0].compoundStmtNode), false); }
#line 1563 "parser.tab.c"
    break;

  case 24: /* funDeclaration: VOID_TYPE ID LP params RP compoundStmt  */
#line 225 "parser.y"
                                                             { (yyval.funDeclarationNode) = new FunDeclarationNode(nullptr, new string((yyvsp[-4].type_id)), (yyvsp[-2].paramVec), (yyvsp[0].compoundStmtNode), false); }
#line 1569 "parser.tab.c"
    break;

  case 25: /* funDeclaration: EXTERN_TYPE baseType ID LP params RP SEMICOLON  */
#line 226 "parser.y"
                                                                     { (yyval.funDeclarationNode) = new FunDeclarationNode((yyvsp[-5].stringNode), new string((yyvsp[-4].type_id)), (yyvsp[-2].paramVec), nullptr, true); }
#line 1575 "parser.tab.c"
    break;

  case 26: /* funDeclaration: EXTERN_TYPE VOID_TYPE ID LP params RP SEMICOLON  */
#line 227 "parser.y"
                                                                      { (yyval.funDeclarationNode) = new FunDeclarationNode(nullptr, new string((yyvsp[-4].type_id)), (yyvsp[-2].paramVec), nullptr, true); }
#line 1581 "parser.tab.c"
    break;

  case 27: /* params: paramList  */
#line 230 "parser.y"
                              { (yyval.paramVec) = (yyvsp[0].paramVec); }
#line 1587 "parser.tab.c"
    break;

  case 28: /* params: VOID_TYPE  */
#line 231 "parser.y"
                                { (yyval.paramVec) = nullptr; }
#line 1593 "parser.tab.c"
    break;

  case 29: /* paramList: paramList COMMA param  */
#line 234 "parser.y"
                                          {
                        (yyvsp[-2].paramVec)->push_back((yyvsp[0].paramNode));
                        (yyval.paramVec) = (yyvsp[-2].paramVec);
                    }
#line 1602 "parser.tab.c"
    break;

  case 30: /* paramList: param  */
#line 238 "parser.y"
                             {
                        (yyval.paramVec) = new vector<ParamNode*>();
                        (yyval.paramVec)->push_back((yyvsp[0].paramNode));
                    }
#line 1611 "parser.tab.c"
    break;

  case 31: /* param: baseType ID  */
#line 244 "parser.y"
                                { (yyval.paramNode) = new ParamNode((yyvsp[-1].stringNode), new string((yyvsp[0].type_id)), nullptr); }
#line 1617 "parser.tab.c"
    break;

  case 32: /* param: baseType ID arrayPostParam  */
#line 245 "parser.y"
                                                 { (yyval.paramNode) = new ParamNode((yyvsp[-2].stringNode), new string((yyvsp[-1].type_id)), (yyvsp[0].intVec)); }
#line 1623 "parser.tab.c"
    break;

  case 33: /* arrayPostParam: LB RB  */
#line 248 "parser.y"
                          {
                        (yyval.intVec) = new vector<int>();
                    }
#line 1631 "parser.tab.c"
    break;

  case 34: /* arrayPostParam: LB INT RB  */
#line 251 "parser.y"
                                 {
                        (yyval.intVec) = new vector<int>();
                    }
#line 1639 "parser.tab.c"
    break;

  case 35: /* arrayPostParam: arrayPostParam LB INT RB  */
#line 254 "parser.y"
                                               {
                        (yyvsp[-3].intVec)->push_back((yyvsp[-1].type_int));
                        (yyval.intVec) = (yyvsp[-3].intVec);
                    }
#line 1648 "parser.tab.c"
    break;

  case 36: /* compoundStmt: LC localDeclarations statementList RC  */
#line 260 "parser.y"
                                                          { (yyval.compoundStmtNode) = new CompoundStmtNode((yyvsp[-2].varDeclarationNodeVec), (yyvsp[-1].statementNodeVec)); }
#line 1654 "parser.tab.c"
    break;

  case 37: /* compoundStmt: LC localDeclarations RC  */
#line 261 "parser.y"
                                              { (yyval.compoundStmtNode) = new CompoundStmtNode((yyvsp[-1].varDeclarationNodeVec), nullptr); }
#line 1660 "parser.tab.c"
    break;

  case 38: /* compoundStmt: LC statementList RC  */
#line 262 "parser.y"
                                          { (yyval.compoundStmtNode) = new CompoundStmtNode(nullptr, (yyvsp[-1].statementNodeVec)); }
#line 1666 "parser.tab.c"
    break;

  case 39: /* compoundStmt: LC RC  */
#line 263 "parser.y"
                            { (yyval.compoundStmtNode) = new CompoundStmtNode(nullptr, nullptr); }
#line 1672 "parser.tab.c"
    break;

  case 40: /* localDeclarations: varDeclaration  */
#line 266 "parser.y"
                                   {
                        (yyval.varDeclarationNodeVec) = new vector<VarDeclarationNode*>();
                        (yyval.varDeclarationNodeVec)->push_back((yyvsp[0].varDeclarationNode));
                    }
#line 1681 "parser.tab.c"
    break;

  case 41: /* localDeclarations: localDeclarations varDeclaration  */
#line 270 "parser.y"
                                                       { 
                        (yyvsp[-1].varDeclarationNodeVec)->push_back((yyvsp[0].varDeclarationNode));
                        (yyval.varDeclarationNodeVec) = (yyvsp[-1].varDeclarationNodeVec);
                    }
#line 1690 "parser.tab.c"
    break;

  case 42: /* statementList: statement  */
#line 276 "parser.y"
                              { 
                        (yyval.statementNodeVec) = new vector<StatementNode*>();
                        (yyval.statementNodeVec)->push_back((yyvsp[0].statementNode));
                    }
#line 1699 "parser.tab.c"
    break;

  case 43: /* statementList: statementList statement  */
#line 280 "parser.y"
                                              {
                        (yyvsp[-1].statementNodeVec)->push_back((yyvsp[0].statementNode));
                        (yyval.statementNodeVec) = (yyvsp[-1].statementNodeVec);
                    }
#line 1708 "parser.tab.c"
    break;

  case 44: /* statement: expressionStmt  */
#line 286 "parser.y"
                                   { (yyval.statementNode) = new StatementNode((yyvsp[0].expressionNode)); }
#line 1714 "parser.tab.c"
    break;

  case 45: /* statement: compoundStmt  */
#line 287 "parser.y"
                                   { (yyval.statementNode) = new StatementNode((yyvsp[0].compoundStmtNode)); }
#line 1720 "parser.tab.c"
    break;

  case 46: /* statement: selectionStmt  */
#line 288 "parser.y"
                                    { (yyval.statementNode) = new StatementNode((yyvsp[0].selectionStmtNode)); }
#line 1726 "parser.tab.c"
    break;

  case 47: /* statement: iterationStmt  */
#line 289 "parser.y"
                                    { (yyval.statementNode) = new StatementNode((yyvsp[0].iterationStmtNode)); }
#line 1732 "parser.tab.c"
    break;

  case 48: /* statement: returnStmt  */
#line 290 "parser.y"
                                 { (yyval.statementNode) = new StatementNode((yyvsp[0].returnStmtNode)); }
#line 1738 "parser.tab.c"
    break;

  case 49: /* expressionStmt: expression SEMICOLON  */
#line 293 "parser.y"
                                         { (yyval.expressionNode) = (yyvsp[-1].expressionNode); }
#line 1744 "parser.tab.c"
    break;

  case 50: /* expressionStmt: SEMICOLON  */
#line 294 "parser.y"
                                { (yyval.expressionNode) = nullptr; }
#line 1750 "parser.tab.c"
    break;

  case 51: /* selectionStmt: IF LP expression RP statement  */
#line 297 "parser.y"
                                                  { (yyval.selectionStmtNode) = new SelectionStmtNode((yyvsp[-2].expressionNode), (yyvsp[0].statementNode), nullptr); }
#line 1756 "parser.tab.c"
    break;

  case 52: /* selectionStmt: IF LP expression RP statement ELSE statement  */
#line 298 "parser.y"
                                                                   { (yyval.selectionStmtNode) = new SelectionStmtNode((yyvsp[-4].expressionNode), (yyvsp[-2].statementNode), (yyvsp[0].statementNode)); }
#line 1762 "parser.tab.c"
    break;

  case 53: /* iterationStmt: whileStmt  */
#line 301 "parser.y"
                              { (yyval.iterationStmtNode) = new IterationStmtNode((yyvsp[0].whileStmtNode)); }
#line 1768 "parser.tab.c"
    break;

  case 54: /* iterationStmt: forStmt  */
#line 302 "parser.y"
                              { (yyval.iterationStmtNode) = new IterationStmtNode((yyvsp[0].forStmtNode)); }
#line 1774 "parser.tab.c"
    break;

  case 55: /* whileStmt: WHILE LP expression RP statement  */
#line 305 "parser.y"
                                                     {
                        (yyval.whileStmtNode) = new WhileStmtNode((yyvsp[-2].expressionNode), (yyvsp[0].statementNode));
                    }
#line 1782 "parser.tab.c"
    break;

  case 56: /* forStmt: FOR LP expression SEMICOLON expression SEMICOLON expression RP statement  */
#line 310 "parser.y"
                                                                                             {
                        (yyval.forStmtNode) = new ForStmtNode((yyvsp[-6].expressionNode), (yyvsp[-4].expressionNode), (yyvsp[-2].expressionNode), (yyvsp[0].statementNode));
                    }
#line 1790 "parser.tab.c"
    break;

  case 57: /* returnStmt: RETURN SEMICOLON  */
#line 315 "parser.y"
                                     { (yyval.returnStmtNode) = nullptr; }
#line 1796 "parser.tab.c"
    break;

  case 58: /* returnStmt: RETURN expression SEMICOLON  */
#line 316 "parser.y"
                                                  { (yyval.returnStmtNode) = new ReturnStmtNode((yyvsp[-1].expressionNode)); }
#line 1802 "parser.tab.c"
    break;

  case 59: /* expression: var assop expression  */
#line 319 "parser.y"
                                         { (yyval.expressionNode) = new ExpressionNode((yyvsp[-1].stringNode), (yyvsp[-2].varNode), (yyvsp[0].expressionNode), nullptr); }
#line 1808 "parser.tab.c"
    break;

  case 60: /* expression: operand  */
#line 320 "parser.y"
                              { (yyval.expressionNode) = new ExpressionNode(nullptr, nullptr, nullptr, (yyvsp[0].operandNode)); }
#line 1814 "parser.tab.c"
    break;

  case 61: /* assop: ASSIGN  */
#line 323 "parser.y"
                           { (yyval.stringNode) = new string("ASSIGN"); }
#line 1820 "parser.tab.c"
    break;

  case 62: /* assop: PLUSASSIGN  */
#line 324 "parser.y"
                                 { (yyval.stringNode) = new string("PLUSASSIGN"); }
#line 1826 "parser.tab.c"
    break;

  case 63: /* assop: MINUSASSIGN  */
#line 325 "parser.y"
                                  { (yyval.stringNode) = new string("MINUSASSIGN"); }
#line 1832 "parser.tab.c"
    break;

  case 64: /* assop: MULTASSIGN  */
#line 326 "parser.y"
                                 { (yyval.stringNode) = new string("MULTASSIGN"); }
#line 1838 "parser.tab.c"
    break;

  case 65: /* assop: DIVASSIGN  */
#line 327 "parser.y"
                                { (yyval.stringNode) = new string("DIVASSIGN"); }
#line 1844 "parser.tab.c"
    break;

  case 66: /* assop: MODASSIGN  */
#line 328 "parser.y"
                                { (yyval.stringNode) = new string("MODASSIGN"); }
#line 1850 "parser.tab.c"
    break;

  case 67: /* assop: BANDASSIGN  */
#line 329 "parser.y"
                                 { (yyval.stringNode) = new string("BANDASSIGN"); }
#line 1856 "parser.tab.c"
    break;

  case 68: /* assop: BORASSIGN  */
#line 330 "parser.y"
                                { (yyval.stringNode) = new string("BORASSIGN"); }
#line 1862 "parser.tab.c"
    break;

  case 69: /* assop: BXORASSIGN  */
#line 331 "parser.y"
                                 { (yyval.stringNode) = new string("BXORASSIGN"); }
#line 1868 "parser.tab.c"
    break;

  case 70: /* assop: SLASSIGN  */
#line 332 "parser.y"
                               { (yyval.stringNode) = new string("SLASSIGN"); }
#line 1874 "parser.tab.c"
    break;

  case 71: /* assop: SRASSIGN  */
#line 333 "parser.y"
                               { (yyval.stringNode) = new string("SRASSIGN"); }
#line 1880 "parser.tab.c"
    break;

  case 72: /* var: ID  */
#line 336 "parser.y"
                       { (yyval.varNode) = new VarNode(new string((yyvsp[0].type_id)), nullptr); }
#line 1886 "parser.tab.c"
    break;

  case 73: /* var: ID arrayPost  */
#line 337 "parser.y"
                                   { (yyval.varNode) = new VarNode(new string((yyvsp[-1].type_id)), (yyvsp[0].intVec)); }
#line 1892 "parser.tab.c"
    break;

  case 74: /* operand: operand LOR operand  */
#line 340 "parser.y"
                                        { (yyval.operandNode) = new OperandNode(new string("LOR"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1898 "parser.tab.c"
    break;

  case 75: /* operand: operand LAND operand  */
#line 341 "parser.y"
                                           { (yyval.operandNode) = new OperandNode(new string("LAND"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1904 "parser.tab.c"
    break;

  case 76: /* operand: operand BOR operand  */
#line 342 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("BOR"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1910 "parser.tab.c"
    break;

  case 77: /* operand: operand BXOR operand  */
#line 343 "parser.y"
                                           { (yyval.operandNode) = new OperandNode(new string("BXOR"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1916 "parser.tab.c"
    break;

  case 78: /* operand: operand BAND operand  */
#line 344 "parser.y"
                                           { (yyval.operandNode) = new OperandNode(new string("BAND"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1922 "parser.tab.c"
    break;

  case 79: /* operand: operand EQ operand  */
#line 345 "parser.y"
                                         { (yyval.operandNode) = new OperandNode(new string("EQ"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1928 "parser.tab.c"
    break;

  case 80: /* operand: operand NEQ operand  */
#line 346 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("NEQ"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1934 "parser.tab.c"
    break;

  case 81: /* operand: operand LT operand  */
#line 347 "parser.y"
                                         { (yyval.operandNode) = new OperandNode(new string("LT"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1940 "parser.tab.c"
    break;

  case 82: /* operand: operand GT operand  */
#line 348 "parser.y"
                                         { (yyval.operandNode) = new OperandNode(new string("GT"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1946 "parser.tab.c"
    break;

  case 83: /* operand: operand LTE operand  */
#line 349 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("LTE"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1952 "parser.tab.c"
    break;

  case 84: /* operand: operand GTE operand  */
#line 350 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("GTE"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1958 "parser.tab.c"
    break;

  case 85: /* operand: operand SL operand  */
#line 351 "parser.y"
                                         { (yyval.operandNode) = new OperandNode(new string("SL"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1964 "parser.tab.c"
    break;

  case 86: /* operand: operand SR operand  */
#line 352 "parser.y"
                                         { (yyval.operandNode) = new OperandNode(new string("SR"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1970 "parser.tab.c"
    break;

  case 87: /* operand: operand PLUS operand  */
#line 353 "parser.y"
                                           { (yyval.operandNode) = new OperandNode(new string("PLUS"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1976 "parser.tab.c"
    break;

  case 88: /* operand: operand MINUS operand  */
#line 354 "parser.y"
                                            { (yyval.operandNode) = new OperandNode(new string("MINUS"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1982 "parser.tab.c"
    break;

  case 89: /* operand: operand MULT operand  */
#line 355 "parser.y"
                                           { (yyval.operandNode) = new OperandNode(new string("MULT"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1988 "parser.tab.c"
    break;

  case 90: /* operand: operand DIV operand  */
#line 356 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("DIV"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 1994 "parser.tab.c"
    break;

  case 91: /* operand: operand MOD operand  */
#line 357 "parser.y"
                                          { (yyval.operandNode) = new OperandNode(new string("MOD"), (yyvsp[-2].operandNode), (yyvsp[0].operandNode), nullptr); }
#line 2000 "parser.tab.c"
    break;

  case 92: /* operand: prefix LP operand RP  */
#line 358 "parser.y"
                                           { (yyval.operandNode) = new OperandNode((yyvsp[-3].stringNode), (yyvsp[-1].operandNode), nullptr, nullptr); }
#line 2006 "parser.tab.c"
    break;

  case 93: /* operand: LP operand RP  */
#line 359 "parser.y"
                                    { (yyval.operandNode) = new OperandNode(nullptr, (yyvsp[-1].operandNode), nullptr, nullptr); }
#line 2012 "parser.tab.c"
    break;

  case 94: /* operand: prefix single  */
#line 360 "parser.y"
                                    {  (yyval.operandNode) = new OperandNode((yyvsp[-1].stringNode), nullptr, nullptr, (yyvsp[0].singleNode)); }
#line 2018 "parser.tab.c"
    break;

  case 95: /* operand: single  */
#line 361 "parser.y"
                             { (yyval.operandNode) = new OperandNode(nullptr, nullptr, nullptr, (yyvsp[0].singleNode));  }
#line 2024 "parser.tab.c"
    break;

  case 96: /* prefix: BNOT  */
#line 365 "parser.y"
                         { (yyval.stringNode) = new string("BNOT"); }
#line 2030 "parser.tab.c"
    break;

  case 97: /* prefix: LNOT  */
#line 366 "parser.y"
                            { (yyval.stringNode) = new string("LNOT"); }
#line 2036 "parser.tab.c"
    break;

  case 98: /* prefix: MINUS  */
#line 367 "parser.y"
                            { (yyval.stringNode) = new string("MINUS"); }
#line 2042 "parser.tab.c"
    break;

  case 99: /* single: var  */
#line 370 "parser.y"
                        { (yyval.singleNode) = new SingleNode((yyvsp[0].varNode)); }
#line 2048 "parser.tab.c"
    break;

  case 100: /* single: call  */
#line 371 "parser.y"
                           { (yyval.singleNode) = new SingleNode((yyvsp[0].callNode)); }
#line 2054 "parser.tab.c"
    break;

  case 101: /* single: INT  */
#line 372 "parser.y"
                          { (yyval.singleNode) = new SingleNode(new IntNode((yyvsp[0].type_int))); }
#line 2060 "parser.tab.c"
    break;

  case 102: /* single: FLOAT  */
#line 373 "parser.y"
                            { (yyval.singleNode) = new SingleNode(new FloatNode((yyvsp[0].type_float))); }
#line 2066 "parser.tab.c"
    break;

  case 103: /* single: CHAR  */
#line 374 "parser.y"
                           { (yyval.singleNode) = new SingleNode(new CharNode((yyvsp[0].type_char))); }
#line 2072 "parser.tab.c"
    break;

  case 104: /* single: TRUE  */
#line 375 "parser.y"
                           { (yyval.singleNode) = new SingleNode(new BoolNode((yyvsp[0].type_bool))); }
#line 2078 "parser.tab.c"
    break;

  case 105: /* single: FALSE  */
#line 376 "parser.y"
                            { (yyval.singleNode) = new SingleNode(new BoolNode((yyvsp[0].type_bool))); }
#line 2084 "parser.tab.c"
    break;

  case 106: /* call: ID LP args RP  */
#line 380 "parser.y"
                                  {
                        (yyval.callNode) = new CallNode(new string((yyvsp[-3].type_id)), (yyvsp[-1].expressionNodeVec));
                    }
#line 2092 "parser.tab.c"
    break;

  case 107: /* args: %empty  */
#line 384 "parser.y"
                           { (yyval.expressionNodeVec) = nullptr; }
#line 2098 "parser.tab.c"
    break;

  case 108: /* args: argList  */
#line 385 "parser.y"
                              { (yyval.expressionNodeVec) = (yyvsp[0].expressionNodeVec); }
#line 2104 "parser.tab.c"
    break;

  case 109: /* argList: argList COMMA expression  */
#line 388 "parser.y"
                                             {
                        (yyvsp[-2].expressionNodeVec)->push_back((yyvsp[0].expressionNode));
                        (yyval.expressionNodeVec) = (yyvsp[-2].expressionNodeVec);
                    }
#line 2113 "parser.tab.c"
    break;

  case 110: /* argList: expression  */
#line 392 "parser.y"
                                 {
                        (yyval.expressionNodeVec) = new vector<ExpressionNode*>();
                        (yyval.expressionNodeVec)->push_back((yyvsp[0].expressionNode));
                    }
#line 2122 "parser.tab.c"
    break;


#line 2126 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 398 "parser.y"


int main() { 
    yyparse();
    for(auto p : *root) {
        p->printNode();
    }
    return 0;
}

void yyerror(std::string s) {
    fprintf(stderr, "%s\n", s.c_str());
    return ;
}

/*maybe use the following？：*/
int TypeCheck(char* type)
{
    if (!strcmp(type,"int"))
	{
		return INT;
	}
	if (!strcmp(type,"float"))
	{
		return FLOAT;
	}
	if (!strcmp(type,"char"))
	{
		return CHAR;
	}
}

// #include<stdarg.h>
// void yyerror(const char* fmt, ...)
// {
//     va_list ap;
//     va_start(ap, fmt);
//     fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
//     vfprintf(stderr, fmt, ap);
//     fprintf(stderr, ".\n");
// }
