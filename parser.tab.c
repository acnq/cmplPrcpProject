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

unique_ptr<Node> root;

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    TRUE = 260,                    /* TRUE  */
    FALSE = 261,                   /* FALSE  */
    CHAR = 262,                    /* CHAR  */
    ID = 263,                      /* ID  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    RETURN = 267,                  /* RETURN  */
    FOR = 268,                     /* FOR  */
    INT_TYPE = 269,                /* INT_TYPE  */
    VOID_TYPE = 270,               /* VOID_TYPE  */
    DOUBLE_TYPE = 271,             /* DOUBLE_TYPE  */
    FLOAT_TYPE = 272,              /* FLOAT_TYPE  */
    CHAR_TYPE = 273,               /* CHAR_TYPE  */
    BOOL_TYPE = 274,               /* BOOL_TYPE  */
    EXTERN_TYPE = 275,             /* EXTERN_TYPE  */
    LP = 276,                      /* LP  */
    RP = 277,                      /* RP  */
    LC = 278,                      /* LC  */
    RC = 279,                      /* RC  */
    LB = 280,                      /* LB  */
    RB = 281,                      /* RB  */
    SEMICOLON = 282,               /* SEMICOLON  */
    COMMA = 283,                   /* COMMA  */
    ASSIGN = 284,                  /* ASSIGN  */
    PLUSASSIGN = 285,              /* PLUSASSIGN  */
    MINUSASSIGN = 286,             /* MINUSASSIGN  */
    MULTASSIGN = 287,              /* MULTASSIGN  */
    DIVASSIGN = 288,               /* DIVASSIGN  */
    MODASSIGN = 289,               /* MODASSIGN  */
    BORASSIGN = 290,               /* BORASSIGN  */
    BXORASSIGN = 291,              /* BXORASSIGN  */
    BANDASSIGN = 292,              /* BANDASSIGN  */
    SRASSIGN = 293,                /* SRASSIGN  */
    SLASSIGN = 294,                /* SLASSIGN  */
    LOR = 295,                     /* LOR  */
    LAND = 296,                    /* LAND  */
    BOR = 297,                     /* BOR  */
    BAND = 298,                    /* BAND  */
    BXOR = 299,                    /* BXOR  */
    SR = 300,                      /* SR  */
    SL = 301,                      /* SL  */
    PLUS = 302,                    /* PLUS  */
    MINUS = 303,                   /* MINUS  */
    MULT = 304,                    /* MULT  */
    DIV = 305,                     /* DIV  */
    MOD = 306,                     /* MOD  */
    LNOT = 307,                    /* LNOT  */
    BNOT = 308,                    /* BNOT  */
    INCR = 309,                    /* INCR  */
    DECR = 310,                    /* DECR  */
    EQ = 311,                      /* EQ  */
    NEQ = 312,                     /* NEQ  */
    LT = 313,                      /* LT  */
    GT = 314,                      /* GT  */
    LTE = 315,                     /* LTE  */
    GTE = 316                      /* GTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    unique_ptr<DeclarationNode>     declarationNode;
    unique_ptr<VarDeclarationNode>  varDeclarationNode;
    unique_ptr<ArrayInitListNode>   arrayInitListNode;
    unique_ptr<FunDeclarationNode>  funDeclarationNode;
    unique_ptr<ParamNode>           paramNode;
    unique_ptr<CompoundStmtNode>    compoundStmtNode;
    unique_ptr<StatementNode>       statementNode;
    unique_ptr<SelectionStmtNode>   selectionStmtNode;
    unique_ptr<IterationStmtNode>   iterationStmtNode;
    unique_ptr<WhileStmtNode>       whileStmtNode;
    unique_ptr<ForStmtNode>         forStmtNode;
    unique_ptr<ReturnStmtNode>      returnStmtNode;
    unique_ptr<ExpressionNode>      expressionNode;
    unique_ptr<VarNode>             varNode;
    unique_ptr<OperandNode>         operandNode;
    unique_ptr<SingleNode>          singleNode;
    unique_ptr<CallNode>            callNode;
    
    unique_ptr<vector<int>> intVec;
    unique_ptr<string>  stringNode;

    unique_ptr<vector<unique_ptr<DeclarationNode>>>  declarationNodeVec;
    unique_ptr<vector<unique_ptr<IdListNode>>>  idListNodeVec;
    unique_ptr<vector<unique_ptr<ArrayInitListNode>>>  arrayInitListNodeVec;
    unique_ptr<vector<unique_ptr<SingleNode>>>  singleNodeVec;
    unique_ptr<vector<unique_ptr<Param>>>  paramVec;
    unique_ptr<vector<unique_ptr<VarDeclarationNode>>>  varDeclarationNodeVec;
    unique_ptr<vector<unique_ptr<StatementNode>>>  statementNodeVec;
    unique_ptr<vector<unique_ptr<ExpressionNode>>>  expressionNodeVec;

    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];


#line 246 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


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
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,   135,   135,   138,   142,   148,   149,   152,   153,   158,
     165,   169,   173,   177,   183,   187,   209,   213,   218,   219,
     220,   221,   222,   225,   226,   227,   228,   231,   232,   235,
     239,   245,   246,   249,   252,   255,   261,   262,   263,   264,
     267,   271,   277,   281,   287,   288,   289,   290,   291,   294,
     295,   298,   299,   302,   303,   306,   311,   316,   317,   320,
     321,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   337,   338,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   366,   367,   368,   371,
     372,   373,   374,   375,   376,   377,   381,   385,   386,   389,
     393
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

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     191,  -150,    15,  -150,  -150,  -150,  -150,    20,     9,   191,
    -150,  -150,    24,  -150,    32,    37,    50,  -150,  -150,    -4,
      22,   149,    58,    68,   149,    91,   282,    80,  -150,    93,
    -150,    96,    77,    82,  -150,   149,   149,    89,    98,  -150,
    -150,  -150,  -150,  -150,    -1,   282,  -150,  -150,  -150,  -150,
     275,   348,     8,  -150,  -150,   122,  -150,   103,   104,   117,
     111,   121,   123,   124,   111,  -150,   282,   282,  -150,   296,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,  -150,   118,   355,   282,     2,   128,    79,  -150,  -150,
     120,   131,  -150,  -150,   137,   132,   146,  -150,  -150,   369,
     389,   408,   444,   427,   278,   278,    69,    69,  -150,  -150,
    -150,   461,   461,   193,   193,   193,   193,   326,  -150,     3,
    -150,  -150,   148,  -150,   174,   166,   171,   109,   176,  -150,
    -150,  -150,   194,  -150,   177,   210,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,   172,  -150,  -150,  -150,   282,  -150,  -150,
     185,   355,  -150,   198,   282,   282,  -150,   199,   282,    19,
    -150,  -150,   243,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     181,   205,  -150,   201,  -150,   271,   271,   282,   222,  -150,
     208,   271,   282,  -150,   214,   271,  -150
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
       0,     0,     0,     0,     0,    14,   107,     0,    99,     0,
      61,    62,    63,    64,    65,    66,    68,    69,    67,    71,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,    32,     0,    24,    29,
       0,     0,    23,   110,     0,   108,     0,    93,    59,    74,
      75,    76,    78,    77,    86,    85,    87,    88,    89,    90,
      91,    79,    80,    81,    82,    83,    84,     0,    15,     0,
      17,    11,     0,    33,     0,     0,     0,     0,     0,    39,
      50,    40,     0,    45,     0,     0,    42,    44,    46,    47,
      53,    54,    48,     0,    26,    25,   106,     0,    73,    92,
       0,     0,    34,     0,     0,     0,    57,     0,     0,    12,
      37,    41,     0,    38,    43,    49,   109,     9,    16,    35,
       0,     0,    58,     0,    36,     0,     0,     0,    51,    55,
       0,     0,     0,    52,     0,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   211,  -103,  -150,  -150,  -150,     1,  -150,
     -17,  -150,   184,  -150,   -34,  -150,    99,  -149,  -150,  -150,
    -150,  -150,  -150,  -150,   -24,  -150,   -26,   -23,  -150,   -49,
    -150,  -150,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    20,    27,   139,    31,    13,
      32,    33,    34,   106,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    81,    68,    51,    52,    53,
      54,   114,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    12,    49,   101,   151,   142,   184,    37,    16,    17,
      12,    39,    40,    41,    42,    43,    44,    24,    62,    63,
      66,    25,    69,    14,    67,    26,   108,   170,   143,   100,
     112,   171,    19,   184,     1,    15,     3,     4,     5,     6,
      50,    50,   113,   116,    25,    22,   198,   199,    26,    28,
      29,   181,   203,    21,   140,    50,   206,   118,    23,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    50,    35,
     141,    50,    39,    40,    41,    42,    43,    44,   145,    36,
     146,   147,   148,     1,    38,     3,     4,     5,     6,    60,
      45,    58,   107,   149,    59,    55,   150,    56,   152,    57,
      61,    64,    39,    40,    41,    42,    43,    44,    91,    92,
      93,    50,   188,   177,    65,   102,   103,    46,    50,    50,
      45,    47,    48,   104,   107,     1,   176,     3,     4,     5,
       6,    50,   105,   186,   138,   110,   111,   164,    50,    50,
     190,   191,    50,   144,   193,   152,    50,    46,   165,   166,
     167,    47,    48,     1,    30,     3,     4,     5,     6,    50,
      50,    50,   168,   200,   172,    50,    50,   173,   204,    50,
      39,    40,    41,    42,    43,    44,   145,   174,   146,   147,
     148,     1,   175,     3,     4,     5,     6,   178,    45,   185,
     107,   180,   179,   195,   150,     1,     2,     3,     4,     5,
       6,     7,   187,    39,    40,    41,    42,    43,    44,   145,
      18,   146,   147,   148,   189,    46,   192,   196,   197,    47,
      48,    45,   201,   107,   183,   202,   205,   150,    87,    88,
      89,    90,    91,    92,    93,   109,    39,    40,    41,    42,
      43,    44,   145,   182,   146,   147,   148,     0,    46,     0,
       0,     0,    47,    48,    45,     0,   107,   194,     0,     0,
     150,     0,     0,     0,    39,    40,    41,    42,    43,    44,
     145,     0,   146,   147,   148,    39,    40,    41,    42,    43,
      44,    46,    45,     0,   107,    47,    48,     0,   150,     0,
       0,     0,     0,    45,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,   117,    46,
       0,     0,     0,    47,    48,    89,    90,    91,    92,    93,
      46,     0,     0,     0,    47,    48,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   169,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    39,    40,
      41,    42,    43,    44,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
      85,     0,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99
};

static const yytype_int16 yycheck[] =
{
      26,     0,    26,    52,   107,     3,   155,    24,     7,     0,
       9,     3,     4,     5,     6,     7,     8,    21,    35,    36,
      21,    25,    45,     8,    25,    29,    60,    24,    26,    21,
      64,    28,     8,   182,    14,    15,    16,    17,    18,    19,
      66,    67,    66,    67,    25,     8,   195,   196,    29,    27,
      28,   154,   201,    21,   103,    81,   205,    81,     8,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   104,    21,
     104,   107,     3,     4,     5,     6,     7,     8,     9,    21,
      11,    12,    13,    14,     3,    16,    17,    18,    19,    22,
      21,     8,    23,    24,     8,    25,    27,    27,   107,    29,
      28,    22,     3,     4,     5,     6,     7,     8,    49,    50,
      51,   147,   171,   147,    26,     3,    23,    48,   154,   155,
      21,    52,    53,    29,    23,    14,    27,    16,    17,    18,
      19,   167,    25,   167,    26,    22,    22,    27,   174,   175,
     174,   175,   178,    25,   178,   154,   182,    48,    27,    22,
      28,    52,    53,    14,    15,    16,    17,    18,    19,   195,
     196,   197,    26,   197,    26,   201,   202,     3,   202,   205,
       3,     4,     5,     6,     7,     8,     9,    21,    11,    12,
      13,    14,    21,    16,    17,    18,    19,    21,    21,    27,
      23,    24,     8,    22,    27,    14,    15,    16,    17,    18,
      19,    20,    27,     3,     4,     5,     6,     7,     8,     9,
       9,    11,    12,    13,    26,    48,    27,    22,    27,    52,
      53,    21,    10,    23,    24,    27,    22,    27,    45,    46,
      47,    48,    49,    50,    51,    61,     3,     4,     5,     6,
       7,     8,     9,   154,    11,    12,    13,    -1,    48,    -1,
      -1,    -1,    52,    53,    21,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,     3,     4,     5,     6,     7,
       8,    48,    21,    -1,    23,    52,    53,    -1,    27,    -1,
      -1,    -1,    -1,    21,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    22,    48,
      -1,    -1,    -1,    52,    53,    47,    48,    49,    50,    51,
      48,    -1,    -1,    -1,    52,    53,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    22,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,     3,     4,
       5,     6,     7,     8,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61
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
      22,    28,    72,    72,    22,    26,    21,    25,    88,    89,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    87,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    56,    57,    58,    59,    60,    61,
      21,    91,     3,    23,    29,    25,    75,    23,    76,    74,
      22,    22,    76,    86,    93,    94,    86,    22,    86,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    26,    69,
      91,    86,     3,    26,    25,     9,    11,    12,    13,    24,
      27,    66,    70,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    27,    27,    22,    28,    26,    22,
      24,    28,    26,     3,    21,    21,    27,    86,    21,     8,
      24,    66,    78,    24,    79,    27,    86,    27,    91,    26,
      86,    86,    27,    86,    24,    22,    22,    27,    79,    79,
      86,    10,    27,    79,    86,    22,    79
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
       1,     1,     1,     4,     3,     3,     3,     3,     3,     3,
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
#line 135 "parser.y"
                                    { root = move((yyvsp[0].declarationNodeVec)); }
#line 1539 "parser.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 138 "parser.y"
                                                 {
                        (yyvsp[-1].declarationNodeVec)->push_back(move((yyvsp[0].declarationNode)));
                        (yyval.declarationNodeVec) = move((yyvsp[-1].declarationNodeVec));
                    }
#line 1548 "parser.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 142 "parser.y"
                                    {
                        (yyval.declarationNodeVec) = make_unique<vector<unique_ptr<declarationNode>>>();
                        (yyval.declarationNodeVec)->push_back(move((yyvsp[0].declarationNode)));
                    }
#line 1557 "parser.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 148 "parser.y"
                                   { (yyval.declarationNode) = make_unique<declarationNode>(move((yyvsp[0].varDeclarationNode))); }
#line 1563 "parser.tab.c"
    break;

  case 6: /* declaration: funDeclaration  */
#line 149 "parser.y"
                                      { (yyval.declarationNode) = make_unique<declarationNode>(move((yyvsp[0].funDeclarationNode))); }
#line 1569 "parser.tab.c"
    break;

  case 7: /* varDeclaration: baseType idList SEMICOLON  */
#line 152 "parser.y"
                                              { (yyval.varDeclarationNode) = make_unique<varDeclarationNode>(move((yyvsp[-2].stringNode)), move((yyvsp[-1].idListNodeVec)), nullptr, nullptr); }
#line 1575 "parser.tab.c"
    break;

  case 8: /* varDeclaration: baseType ID arrayPost SEMICOLON  */
#line 153 "parser.y"
                                                      {
                        (yyval.varDeclarationNode) = make_unique<vector<unique_ptr<idListNode>>>();
                        (yyval.varDeclarationNode)-> push_back(move((yyvsp[-2].type_id)));
                        (yyval.varDeclarationNode) = make_unique<varDeclarationNode>(move((yyvsp[-3].stringNode)), move((yyval.varDeclarationNode)), move((yyvsp[-1].intVec)), nullptr);
                    }
#line 1585 "parser.tab.c"
    break;

  case 9: /* varDeclaration: baseType ID arrayPost ASSIGN LC arrayConstList RC SEMICOLON  */
#line 158 "parser.y"
                                                                                      {
                        (yyval.varDeclarationNode) = make_unique<vector<unique_ptr<idListNode>>>();
                        (yyval.varDeclarationNode)-> push_back(move((yyvsp[-6].type_id)));
                        (yyval.varDeclarationNode) = make_unique<varDeclarationNode>(move((yyvsp[-7].stringNode)), move((yyval.varDeclarationNode)), move((yyvsp[-5].intVec)), move((yyvsp[-2].singleNodeVec)));
                    }
#line 1595 "parser.tab.c"
    break;

  case 10: /* idList: idList COMMA ID  */
#line 165 "parser.y"
                                    { 
                        (yyvsp[-2].idListNodeVec)->push_back(make_unique<idListNode>(make_unique<string>((yyvsp[0].type_id)), nullptr));
                        (yyval.idListNodeVec) = move((yyvsp[-2].idListNodeVec));
                    }
#line 1604 "parser.tab.c"
    break;

  case 11: /* idList: idList COMMA ID ASSIGN expression  */
#line 169 "parser.y"
                                                        {
                        (yyvsp[-4].idListNodeVec)->push_back(make_unique<idListNode>(make_unique<string>((yyvsp[-2].type_id)), move((yyvsp[0].expressionNode))));
                        (yyval.idListNodeVec) = move((yyvsp[-4].idListNodeVec));
                    }
#line 1613 "parser.tab.c"
    break;

  case 12: /* idList: ID  */
#line 173 "parser.y"
                         { 
                        (yyval.idListNodeVec) = make_unique<vector<unique_ptr<idListNode>>>();
                        (yyval.idListNodeVec)->push_back(make_unique<idListNode>(make_unique<string>((yyvsp[0].type_id)), nullptr)); 
                    }
#line 1622 "parser.tab.c"
    break;

  case 13: /* idList: ID ASSIGN expression  */
#line 177 "parser.y"
                                           {
                        (yyval.idListNodeVec) = make_unique<vector<unique_ptr<idListNode>>>();
                        (yyval.idListNodeVec)->push_back(make_unique<idListNode>(make_unique<string>((yyvsp[-2].type_id)), move((yyvsp[0].expressionNode)))); 
                    }
#line 1631 "parser.tab.c"
    break;

  case 14: /* arrayPost: LB INT RB  */
#line 183 "parser.y"
                               {
                        (yyval.intVec) = make_unique<vector<int>>();
                        (yyval.intVec)->push_back((yyvsp[-1].type_int));
                    }
#line 1640 "parser.tab.c"
    break;

  case 15: /* arrayPost: arrayPost LB INT RB  */
#line 187 "parser.y"
                                          {
                        (yyvsp[-3].intVec)->push_back((yyvsp[-1].type_int));
                        (yyval.intVec) = move((yyvsp[-3].intVec));
                    }
#line 1649 "parser.tab.c"
    break;

  case 16: /* arrayConstList: arrayConstList COMMA single  */
#line 209 "parser.y"
                                                {
                        (yyvsp[-2].singleNodeVec)->push_back(move((yyvsp[0].singleNode)));
                        (yyval.singleNodeVec) = move((yyvsp[-2].singleNodeVec));
                    }
#line 1658 "parser.tab.c"
    break;

  case 17: /* arrayConstList: single  */
#line 213 "parser.y"
                             {
                        (yyval.singleNodeVec) = make_unique<vector<unique_ptr<singleNode>>>();
                        (yyval.singleNodeVec)->push_back(move((yyvsp[0].singleNode)));
                    }
#line 1667 "parser.tab.c"
    break;

  case 18: /* baseType: INT_TYPE  */
#line 218 "parser.y"
                             { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1673 "parser.tab.c"
    break;

  case 19: /* baseType: DOUBLE_TYPE  */
#line 219 "parser.y"
                                  { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1679 "parser.tab.c"
    break;

  case 20: /* baseType: FLOAT_TYPE  */
#line 220 "parser.y"
                                 { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1685 "parser.tab.c"
    break;

  case 21: /* baseType: CHAR_TYPE  */
#line 221 "parser.y"
                                { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1691 "parser.tab.c"
    break;

  case 22: /* baseType: BOOL_TYPE  */
#line 222 "parser.y"
                                { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1697 "parser.tab.c"
    break;

  case 23: /* funDeclaration: baseType ID LP params RP compoundStmt  */
#line 225 "parser.y"
                                                          { (yyval.funDeclarationNode) = make_unique<funDeclarationNode>(make_unique<string>((yyvsp[-5].stringNode)), move((yyvsp[-2].paramVec)), false) }
#line 1703 "parser.tab.c"
    break;

  case 24: /* funDeclaration: VOID_TYPE ID LP params RP compoundStmt  */
#line 226 "parser.y"
                                                             { (yyval.funDeclarationNode) = make_unique<funDeclarationNode>(nullptr, move((yyvsp[-2].paramVec)), false) }
#line 1709 "parser.tab.c"
    break;

  case 25: /* funDeclaration: EXTERN_TYPE baseType ID LP params RP SEMICOLON  */
#line 227 "parser.y"
                                                                     { (yyval.funDeclarationNode) = make_unique<funDeclarationNode>(make_unique<string>((yyvsp[-5].stringNode)), move((yyvsp[-2].paramVec)), true) }
#line 1715 "parser.tab.c"
    break;

  case 26: /* funDeclaration: EXTERN_TYPE VOID_TYPE ID LP params RP SEMICOLON  */
#line 228 "parser.y"
                                                                      { (yyval.funDeclarationNode) = make_unique<funDeclarationNode>(nullptr, move((yyvsp[-2].paramVec)), true) }
#line 1721 "parser.tab.c"
    break;

  case 27: /* params: paramList  */
#line 231 "parser.y"
                              { (yyval.paramVec) = move((yyvsp[0].paramVec)) }
#line 1727 "parser.tab.c"
    break;

  case 28: /* params: VOID_TYPE  */
#line 232 "parser.y"
                                { (yyval.paramVec) = nullptr; }
#line 1733 "parser.tab.c"
    break;

  case 29: /* paramList: paramList COMMA param  */
#line 235 "parser.y"
                                          {
                        (yyvsp[-2].paramVec)->push_back(move((yyvsp[0].paramNode)));
                        (yyval.paramVec) = move((yyvsp[-2].paramVec));
                    }
#line 1742 "parser.tab.c"
    break;

  case 30: /* paramList: param  */
#line 239 "parser.y"
                             {
                        (yyval.paramVec) = make_unique<vector<unique_ptr<paramNode>>>();
                        (yyval.paramVec)->push_back(move((yyvsp[0].paramNode)));
                    }
#line 1751 "parser.tab.c"
    break;

  case 31: /* param: baseType ID  */
#line 245 "parser.y"
                                { (yyval.paramNode) = make_unique<paramNode>(move((yyvsp[-1].stringNode)), move((yyvsp[0].type_id)), nullptr) }
#line 1757 "parser.tab.c"
    break;

  case 32: /* param: baseType ID arrayPostParam  */
#line 246 "parser.y"
                                                 { (yyval.paramNode) = make_unique<paramNode>(move((yyvsp[-2].stringNode)), move((yyvsp[-1].type_id)), move((yyvsp[0].intVec))) }
#line 1763 "parser.tab.c"
    break;

  case 33: /* arrayPostParam: LB RB  */
#line 249 "parser.y"
                          {
                        (yyval.intVec) = make_unique<vector<int>>();
                    }
#line 1771 "parser.tab.c"
    break;

  case 34: /* arrayPostParam: LB INT RB  */
#line 252 "parser.y"
                                 {
                        (yyval.intVec) = make_unique<vector<int>>();
                    }
#line 1779 "parser.tab.c"
    break;

  case 35: /* arrayPostParam: arrayPostParam LB INT RB  */
#line 255 "parser.y"
                                               {
                        (yyvsp[-3].intVec)->push_back((yyvsp[-1].type_int));
                        (yyval.intVec) = move((yyvsp[-3].intVec));
                    }
#line 1788 "parser.tab.c"
    break;

  case 36: /* compoundStmt: LC localDeclarations statementList RC  */
#line 261 "parser.y"
                                                          { (yyval.compoundStmtNode) = make_unique<compoundStmtNode>(move((yyvsp[-2].varDeclarationNodeVec)), move((yyvsp[-1].statementNodeVec))); }
#line 1794 "parser.tab.c"
    break;

  case 37: /* compoundStmt: LC localDeclarations RC  */
#line 262 "parser.y"
                                              { (yyval.compoundStmtNode) = make_unique<compoundStmtNode>(move((yyvsp[-1].varDeclarationNodeVec)), nullptr); }
#line 1800 "parser.tab.c"
    break;

  case 38: /* compoundStmt: LC statementList RC  */
#line 263 "parser.y"
                                          { (yyval.compoundStmtNode) = make_unique<compoundStmtNode>(nullptr, move((yyvsp[-1].statementNodeVec))); }
#line 1806 "parser.tab.c"
    break;

  case 39: /* compoundStmt: LC RC  */
#line 264 "parser.y"
                            { (yyval.compoundStmtNode) = make_unique<compoundStmtNode>(nullptr, nullptr); }
#line 1812 "parser.tab.c"
    break;

  case 40: /* localDeclarations: varDeclaration  */
#line 267 "parser.y"
                                   {
                        (yyval.varDeclarationNodeVec) = make_unique<vector<unique_ptr<varDeclarationNode>>>();
                        (yyval.varDeclarationNodeVec)->push_back(move((yyvsp[0].varDeclarationNode)));
                    }
#line 1821 "parser.tab.c"
    break;

  case 41: /* localDeclarations: localDeclarations varDeclaration  */
#line 271 "parser.y"
                                                       { 
                        (yyvsp[-1].varDeclarationNodeVec)->push_back(move((yyvsp[0].varDeclarationNode)));
                        (yyval.varDeclarationNodeVec) = move((yyvsp[-1].varDeclarationNodeVec));
                    }
#line 1830 "parser.tab.c"
    break;

  case 42: /* statementList: statement  */
#line 277 "parser.y"
                              { 
                        (yyval.statementNodeVec) = make_unique<vector<unique_ptr<statementNode>>>();
                        (yyval.statementNodeVec)->push_back(move((yyvsp[0].statementNode)));
                    }
#line 1839 "parser.tab.c"
    break;

  case 43: /* statementList: statementList statement  */
#line 281 "parser.y"
                                              {
                        (yyvsp[-1].statementNodeVec)->push_back(move((yyvsp[0].statementNode)));
                        (yyval.statementNodeVec) = move((yyvsp[-1].statementNodeVec));
                    }
#line 1848 "parser.tab.c"
    break;

  case 44: /* statement: expressionStmt  */
#line 287 "parser.y"
                                   { (yyval.statementNode) = make_unique<statementNode>(move((yyvsp[0].expressionNode))); }
#line 1854 "parser.tab.c"
    break;

  case 45: /* statement: compoundStmt  */
#line 288 "parser.y"
                                   { (yyval.statementNode) = make_unique<statementNode>(move((yyvsp[0].compoundStmtNode))); }
#line 1860 "parser.tab.c"
    break;

  case 46: /* statement: selectionStmt  */
#line 289 "parser.y"
                                    { (yyval.statementNode) = make_unique<statementNode>(move((yyvsp[0].selectionStmtNode))); }
#line 1866 "parser.tab.c"
    break;

  case 47: /* statement: iterationStmt  */
#line 290 "parser.y"
                                    { (yyval.statementNode) = make_unique<statementNode>(move((yyvsp[0].iterationStmtNode))); }
#line 1872 "parser.tab.c"
    break;

  case 48: /* statement: returnStmt  */
#line 291 "parser.y"
                                 { (yyval.statementNode) = make_unique<statementNode>(move((yyvsp[0].returnStmtNode))); }
#line 1878 "parser.tab.c"
    break;

  case 49: /* expressionStmt: expression SEMICOLON  */
#line 294 "parser.y"
                                         { (yyval.expressionNode) = move((yyvsp[-1].expressionNode)); }
#line 1884 "parser.tab.c"
    break;

  case 50: /* expressionStmt: SEMICOLON  */
#line 295 "parser.y"
                                { (yyval.expressionNode) = nullptr; }
#line 1890 "parser.tab.c"
    break;

  case 51: /* selectionStmt: IF LP expression RP statement  */
#line 298 "parser.y"
                                                  { (yyval.selectionStmtNode) = make_unique<selectionStmtNode>(move((yyvsp[-2].expressionNode)), move((yyvsp[0].statementNode)), nullptr); }
#line 1896 "parser.tab.c"
    break;

  case 52: /* selectionStmt: IF LP expression RP statement ELSE statement  */
#line 299 "parser.y"
                                                                   { (yyval.selectionStmtNode) = make_unique<selectionStmtNode>(move((yyvsp[-4].expressionNode)), move((yyvsp[-2].statementNode)), move((yyvsp[0].statementNode))); }
#line 1902 "parser.tab.c"
    break;

  case 53: /* iterationStmt: whileStmt  */
#line 302 "parser.y"
                              { (yyval.iterationStmtNode) = make_unique<iterationStmtNode>(move((yyvsp[0].whileStmtNode))); }
#line 1908 "parser.tab.c"
    break;

  case 54: /* iterationStmt: forStmt  */
#line 303 "parser.y"
                              { (yyval.iterationStmtNode) = make_unique<iterationStmtNode>(move((yyvsp[0].forStmtNode))); }
#line 1914 "parser.tab.c"
    break;

  case 55: /* whileStmt: WHILE LP expression RP statement  */
#line 306 "parser.y"
                                                     {
                        (yyval.whileStmtNode) = make_unique<whileStmtNode>(move((yyvsp[-2].expressionNode)), move((yyvsp[0].statementNode)));
                    }
#line 1922 "parser.tab.c"
    break;

  case 56: /* forStmt: FOR LP expression SEMICOLON expression SEMICOLON expression RP statement  */
#line 311 "parser.y"
                                                                                             {
                        (yyval.forStmtNode) = make_unique<forStmtNode>(move((yyvsp[-6].expressionNode)), move((yyvsp[-4].expressionNode)), move((yyvsp[-2].expressionNode)), move((yyvsp[0].statementNode)));
                    }
#line 1930 "parser.tab.c"
    break;

  case 57: /* returnStmt: RETURN SEMICOLON  */
#line 316 "parser.y"
                                     { (yyval.returnStmtNode) = nullptr; }
#line 1936 "parser.tab.c"
    break;

  case 58: /* returnStmt: RETURN expression SEMICOLON  */
#line 317 "parser.y"
                                                  { (yyval.returnStmtNode) = make_unique<returnStmtNode>(move((yyvsp[-1].expressionNode))); }
#line 1942 "parser.tab.c"
    break;

  case 59: /* expression: var assop expression  */
#line 320 "parser.y"
                                         { (yyval.expressionNode) = make_unique<expressionNode>(move((yyvsp[-1].stringNode)), move((yyvsp[-2].varNode)), move((yyvsp[0].expressionNode))); }
#line 1948 "parser.tab.c"
    break;

  case 60: /* expression: operand  */
#line 321 "parser.y"
                              { (yyval.expressionNode) = make_unique<expressionNode>(nullptr, nullptr, move((yyvsp[0].operandNode))); }
#line 1954 "parser.tab.c"
    break;

  case 61: /* assop: ASSIGN  */
#line 324 "parser.y"
                           { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1960 "parser.tab.c"
    break;

  case 62: /* assop: PLUSASSIGN  */
#line 325 "parser.y"
                                 { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1966 "parser.tab.c"
    break;

  case 63: /* assop: MINUSASSIGN  */
#line 326 "parser.y"
                                  { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1972 "parser.tab.c"
    break;

  case 64: /* assop: MULTASSIGN  */
#line 327 "parser.y"
                                 { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1978 "parser.tab.c"
    break;

  case 65: /* assop: DIVASSIGN  */
#line 328 "parser.y"
                                { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1984 "parser.tab.c"
    break;

  case 66: /* assop: MODASSIGN  */
#line 329 "parser.y"
                                { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1990 "parser.tab.c"
    break;

  case 67: /* assop: BANDASSIGN  */
#line 330 "parser.y"
                                 { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 1996 "parser.tab.c"
    break;

  case 68: /* assop: BORASSIGN  */
#line 331 "parser.y"
                                { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2002 "parser.tab.c"
    break;

  case 69: /* assop: BXORASSIGN  */
#line 332 "parser.y"
                                 { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2008 "parser.tab.c"
    break;

  case 70: /* assop: SLASSIGN  */
#line 333 "parser.y"
                               { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2014 "parser.tab.c"
    break;

  case 71: /* assop: SRASSIGN  */
#line 334 "parser.y"
                               { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2020 "parser.tab.c"
    break;

  case 72: /* var: ID  */
#line 337 "parser.y"
                       { (yyval.varNode) = make_unique<varNode>(make_unique<string>((yyvsp[0].type_id)), nullptr); }
#line 2026 "parser.tab.c"
    break;

  case 73: /* var: ID LB expression RB  */
#line 338 "parser.y"
                                          { (yyval.varNode) = make_unique<varNode>(make_unique<string>((yyvsp[-3].type_id)), move((yyvsp[-1].expressionNode))); }
#line 2032 "parser.tab.c"
    break;

  case 74: /* operand: operand LOR operand  */
#line 341 "parser.y"
                                        { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2038 "parser.tab.c"
    break;

  case 75: /* operand: operand LAND operand  */
#line 342 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2044 "parser.tab.c"
    break;

  case 76: /* operand: operand BOR operand  */
#line 343 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2050 "parser.tab.c"
    break;

  case 77: /* operand: operand BXOR operand  */
#line 344 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2056 "parser.tab.c"
    break;

  case 78: /* operand: operand BAND operand  */
#line 345 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2062 "parser.tab.c"
    break;

  case 79: /* operand: operand EQ operand  */
#line 346 "parser.y"
                                         { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2068 "parser.tab.c"
    break;

  case 80: /* operand: operand NEQ operand  */
#line 347 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2074 "parser.tab.c"
    break;

  case 81: /* operand: operand LT operand  */
#line 348 "parser.y"
                                         { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2080 "parser.tab.c"
    break;

  case 82: /* operand: operand GT operand  */
#line 349 "parser.y"
                                         { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2086 "parser.tab.c"
    break;

  case 83: /* operand: operand LTE operand  */
#line 350 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2092 "parser.tab.c"
    break;

  case 84: /* operand: operand GTE operand  */
#line 351 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2098 "parser.tab.c"
    break;

  case 85: /* operand: operand SL operand  */
#line 352 "parser.y"
                                         { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2104 "parser.tab.c"
    break;

  case 86: /* operand: operand SR operand  */
#line 353 "parser.y"
                                         { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2110 "parser.tab.c"
    break;

  case 87: /* operand: operand PLUS operand  */
#line 354 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2116 "parser.tab.c"
    break;

  case 88: /* operand: operand MINUS operand  */
#line 355 "parser.y"
                                            { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2122 "parser.tab.c"
    break;

  case 89: /* operand: operand MULT operand  */
#line 356 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2128 "parser.tab.c"
    break;

  case 90: /* operand: operand DIV operand  */
#line 357 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2134 "parser.tab.c"
    break;

  case 91: /* operand: operand MOD operand  */
#line 358 "parser.y"
                                          { (yyval.operandNode) = make_unique<operandNode>(make_unique<string>((yyvsp[-1].string)), move((yyvsp[-2].operandNode)), move((yyvsp[0].operandNode))); }
#line 2140 "parser.tab.c"
    break;

  case 92: /* operand: prefix LP operand RP  */
#line 359 "parser.y"
                                           { (yyval.operandNode) = make_unique<operandNode>(move((yyvsp[-3].stringNode)), move((yyvsp[-1].operandNode)), nullptr); }
#line 2146 "parser.tab.c"
    break;

  case 93: /* operand: LP operand RP  */
#line 360 "parser.y"
                                    { (yyval.operandNode) = make_unique<operandNode>(nullptr, move((yyvsp[-1].operandNode)), nullptr); }
#line 2152 "parser.tab.c"
    break;

  case 94: /* operand: prefix single  */
#line 361 "parser.y"
                                    {  (yyval.operandNode) = make_unique<operandNode>(move((yyvsp[-1].stringNode)), move((yyvsp[0].singleNode)), nullptr); }
#line 2158 "parser.tab.c"
    break;

  case 95: /* operand: single  */
#line 362 "parser.y"
                             { (yyval.operandNode) = make_unique<operandNode>(nullptr, move((yyvsp[0].singleNode)), nullptr);  }
#line 2164 "parser.tab.c"
    break;

  case 96: /* prefix: BNOT  */
#line 366 "parser.y"
                         { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2170 "parser.tab.c"
    break;

  case 97: /* prefix: LNOT  */
#line 367 "parser.y"
                            { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2176 "parser.tab.c"
    break;

  case 98: /* prefix: MINUS  */
#line 368 "parser.y"
                            { (yyval.stringNode) = make_unique<string>((yyvsp[0].string)); }
#line 2182 "parser.tab.c"
    break;

  case 99: /* single: var  */
#line 371 "parser.y"
                        { (yyval.singleNode) = make_unique<singleNode>( make_unique<string>((yyvsp[0].varNode)) ); }
#line 2188 "parser.tab.c"
    break;

  case 100: /* single: call  */
#line 372 "parser.y"
                           { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].callNode)); }
#line 2194 "parser.tab.c"
    break;

  case 101: /* single: INT  */
#line 373 "parser.y"
                          { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].type_int)); }
#line 2200 "parser.tab.c"
    break;

  case 102: /* single: FLOAT  */
#line 374 "parser.y"
                            { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].type_float)); }
#line 2206 "parser.tab.c"
    break;

  case 103: /* single: CHAR  */
#line 375 "parser.y"
                           { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].type_char)); }
#line 2212 "parser.tab.c"
    break;

  case 104: /* single: TRUE  */
#line 376 "parser.y"
                           { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].type_bool)); }
#line 2218 "parser.tab.c"
    break;

  case 105: /* single: FALSE  */
#line 377 "parser.y"
                            { (yyval.singleNode) = make_unique<singleNode>((yyvsp[0].type_bool)); }
#line 2224 "parser.tab.c"
    break;

  case 106: /* call: ID LP args RP  */
#line 381 "parser.y"
                                  {
                        (yyval.callNode) = make_unique<callNode>(make_unique<string>((yyvsp[-3].type_id)), move((yyvsp[-1].expressionNodeVec))));
                    }
#line 2232 "parser.tab.c"
    break;

  case 107: /* args: %empty  */
#line 385 "parser.y"
                           { (yyval.expressionNodeVec) = nullptr; }
#line 2238 "parser.tab.c"
    break;

  case 108: /* args: argList  */
#line 386 "parser.y"
                              { (yyval.expressionNodeVec) = move((yyvsp[0].expressionNodeVec)); }
#line 2244 "parser.tab.c"
    break;

  case 109: /* argList: argList COMMA expression  */
#line 389 "parser.y"
                                             {
                        (yyvsp[-2].expressionNodeVec)->push_back(move((yyvsp[0].expressionNode)));
                        (yyval.expressionNodeVec) = move((yyvsp[-2].expressionNodeVec));
                    }
#line 2253 "parser.tab.c"
    break;

  case 110: /* argList: expression  */
#line 393 "parser.y"
                                 {
                        (yyval.expressionNodeVec) = make_unique<vector<unique_ptr<expressionNode>>>();
                        (yyval.expressionNodeVec)->push_back(move((yyvsp[0].expressionNode)));
                    }
#line 2262 "parser.tab.c"
    break;


#line 2266 "parser.tab.c"

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

#line 399 "parser.y"


int main() { 
    return yyparse();
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
