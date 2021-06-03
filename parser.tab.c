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

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

extern int yylex(void);

void yyerror(std::string s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/


#line 94 "parser.tab.c"

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
    DOUBLE = 260,                  /* DOUBLE  */
    TRUE = 261,                    /* TRUE  */
    FALSE = 262,                   /* FALSE  */
    CHAR = 263,                    /* CHAR  */
    ID = 264,                      /* ID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    RETURN = 268,                  /* RETURN  */
    FOR = 269,                     /* FOR  */
    INT_TYPE = 270,                /* INT_TYPE  */
    VOID_TYPE = 271,               /* VOID_TYPE  */
    DOUBLE_TYPE = 272,             /* DOUBLE_TYPE  */
    FLOAT_TYPE = 273,              /* FLOAT_TYPE  */
    CHAR_TYPE = 274,               /* CHAR_TYPE  */
    BOOL_TYPE = 275,               /* BOOL_TYPE  */
    EXTERN_TYPE = 276,             /* EXTERN_TYPE  */
    LP = 277,                      /* LP  */
    RP = 278,                      /* RP  */
    LC = 279,                      /* LC  */
    RC = 280,                      /* RC  */
    LB = 281,                      /* LB  */
    RB = 282,                      /* RB  */
    SEMICOLON = 283,               /* SEMICOLON  */
    COMMA = 284,                   /* COMMA  */
    ASSIGN = 285,                  /* ASSIGN  */
    PLUSASSIGN = 286,              /* PLUSASSIGN  */
    MINUSASSIGN = 287,             /* MINUSASSIGN  */
    MULTASSIGN = 288,              /* MULTASSIGN  */
    DIVASSIGN = 289,               /* DIVASSIGN  */
    MODASSIGN = 290,               /* MODASSIGN  */
    BORASSIGN = 291,               /* BORASSIGN  */
    BXORASSIGN = 292,              /* BXORASSIGN  */
    BANDASSIGN = 293,              /* BANDASSIGN  */
    SRASSIGN = 294,                /* SRASSIGN  */
    SLASSIGN = 295,                /* SLASSIGN  */
    LOR = 296,                     /* LOR  */
    LAND = 297,                    /* LAND  */
    BOR = 298,                     /* BOR  */
    BAND = 299,                    /* BAND  */
    BXOR = 300,                    /* BXOR  */
    SR = 301,                      /* SR  */
    SL = 302,                      /* SL  */
    PLUS = 303,                    /* PLUS  */
    MINUS = 304,                   /* MINUS  */
    MULT = 305,                    /* MULT  */
    DIV = 306,                     /* DIV  */
    MOD = 307,                     /* MOD  */
    LNOT = 308,                    /* LNOT  */
    BNOT = 309,                    /* BNOT  */
    INCR = 310,                    /* INCR  */
    DECR = 311,                    /* DECR  */
    EQ = 312,                      /* EQ  */
    NEQ = 313,                     /* NEQ  */
    LT = 314,                      /* LT  */
    GT = 315,                      /* GT  */
    LTE = 316,                     /* LTE  */
    GTE = 317                      /* GTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    /*treeNode member needed here*/
    /*...*/
    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];


#line 215 "parser.tab.c"

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
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_TRUE = 6,                       /* TRUE  */
  YYSYMBOL_FALSE = 7,                      /* FALSE  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_INT_TYPE = 15,                  /* INT_TYPE  */
  YYSYMBOL_VOID_TYPE = 16,                 /* VOID_TYPE  */
  YYSYMBOL_DOUBLE_TYPE = 17,               /* DOUBLE_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 18,                /* FLOAT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 19,                 /* CHAR_TYPE  */
  YYSYMBOL_BOOL_TYPE = 20,                 /* BOOL_TYPE  */
  YYSYMBOL_EXTERN_TYPE = 21,               /* EXTERN_TYPE  */
  YYSYMBOL_LP = 22,                        /* LP  */
  YYSYMBOL_RP = 23,                        /* RP  */
  YYSYMBOL_LC = 24,                        /* LC  */
  YYSYMBOL_RC = 25,                        /* RC  */
  YYSYMBOL_LB = 26,                        /* LB  */
  YYSYMBOL_RB = 27,                        /* RB  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 31,                /* PLUSASSIGN  */
  YYSYMBOL_MINUSASSIGN = 32,               /* MINUSASSIGN  */
  YYSYMBOL_MULTASSIGN = 33,                /* MULTASSIGN  */
  YYSYMBOL_DIVASSIGN = 34,                 /* DIVASSIGN  */
  YYSYMBOL_MODASSIGN = 35,                 /* MODASSIGN  */
  YYSYMBOL_BORASSIGN = 36,                 /* BORASSIGN  */
  YYSYMBOL_BXORASSIGN = 37,                /* BXORASSIGN  */
  YYSYMBOL_BANDASSIGN = 38,                /* BANDASSIGN  */
  YYSYMBOL_SRASSIGN = 39,                  /* SRASSIGN  */
  YYSYMBOL_SLASSIGN = 40,                  /* SLASSIGN  */
  YYSYMBOL_LOR = 41,                       /* LOR  */
  YYSYMBOL_LAND = 42,                      /* LAND  */
  YYSYMBOL_BOR = 43,                       /* BOR  */
  YYSYMBOL_BAND = 44,                      /* BAND  */
  YYSYMBOL_BXOR = 45,                      /* BXOR  */
  YYSYMBOL_SR = 46,                        /* SR  */
  YYSYMBOL_SL = 47,                        /* SL  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_MULT = 50,                      /* MULT  */
  YYSYMBOL_DIV = 51,                       /* DIV  */
  YYSYMBOL_MOD = 52,                       /* MOD  */
  YYSYMBOL_LNOT = 53,                      /* LNOT  */
  YYSYMBOL_BNOT = 54,                      /* BNOT  */
  YYSYMBOL_INCR = 55,                      /* INCR  */
  YYSYMBOL_DECR = 56,                      /* DECR  */
  YYSYMBOL_EQ = 57,                        /* EQ  */
  YYSYMBOL_NEQ = 58,                       /* NEQ  */
  YYSYMBOL_LT = 59,                        /* LT  */
  YYSYMBOL_GT = 60,                        /* GT  */
  YYSYMBOL_LTE = 61,                       /* LTE  */
  YYSYMBOL_GTE = 62,                       /* GTE  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_declarationList = 65,           /* declarationList  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_varDeclaration = 67,            /* varDeclaration  */
  YYSYMBOL_typeSpecifier = 68,             /* typeSpecifier  */
  YYSYMBOL_arrayType = 69,                 /* arrayType  */
  YYSYMBOL_arrayInitList = 70,             /* arrayInitList  */
  YYSYMBOL_arrayInit = 71,                 /* arrayInit  */
  YYSYMBOL_baseType = 72,                  /* baseType  */
  YYSYMBOL_funDeclaration = 73,            /* funDeclaration  */
  YYSYMBOL_params = 74,                    /* params  */
  YYSYMBOL_paramList = 75,                 /* paramList  */
  YYSYMBOL_param = 76,                     /* param  */
  YYSYMBOL_compoundStmt = 77,              /* compoundStmt  */
  YYSYMBOL_localDeclarations = 78,         /* localDeclarations  */
  YYSYMBOL_statementList = 79,             /* statementList  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_expressionStmt = 81,            /* expressionStmt  */
  YYSYMBOL_selectionStmt = 82,             /* selectionStmt  */
  YYSYMBOL_iterationStmt = 83,             /* iterationStmt  */
  YYSYMBOL_whileStmt = 84,                 /* whileStmt  */
  YYSYMBOL_forStmt = 85,                   /* forStmt  */
  YYSYMBOL_returnStmt = 86,                /* returnStmt  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_assop = 88,                     /* assop  */
  YYSYMBOL_var = 89,                       /* var  */
  YYSYMBOL_simpleExpression = 90,          /* simpleExpression  */
  YYSYMBOL_logop = 91,                     /* logop  */
  YYSYMBOL_logicExpression = 92,           /* logicExpression  */
  YYSYMBOL_bitop = 93,                     /* bitop  */
  YYSYMBOL_bitExpression = 94,             /* bitExpression  */
  YYSYMBOL_relop = 95,                     /* relop  */
  YYSYMBOL_shiftExpression = 96,           /* shiftExpression  */
  YYSYMBOL_shiop = 97,                     /* shiop  */
  YYSYMBOL_additiveExpression = 98,        /* additiveExpression  */
  YYSYMBOL_addop = 99,                     /* addop  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_mulop = 101,                    /* mulop  */
  YYSYMBOL_factor = 102,                   /* factor  */
  YYSYMBOL_incre = 103,                    /* incre  */
  YYSYMBOL_terminal = 104,                 /* terminal  */
  YYSYMBOL_call = 105,                     /* call  */
  YYSYMBOL_args = 106,                     /* args  */
  YYSYMBOL_argList = 107                   /* argList  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    75,    76,    77,
      80,    81,    84,    85,    87,    88,    91,    92,    95,    96,
      97,    98,    99,   100,   103,   104,   107,   108,   111,   112,
     115,   116,   119,   121,   122,   125,   126,   129,   130,   131,
     132,   133,   136,   137,   140,   141,   144,   145,   148,   151,
     154,   155,   158,   159,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   175,   176,   179,   180,   183,
     184,   186,   187,   190,   190,   190,   192,   193,   196,   196,
     196,   196,   196,   196,   198,   199,   202,   202,   204,   205,
     208,   208,   210,   211,   214,   214,   214,   216,   217,   218,
     219,   222,   223,   224,   227,   228,   229,   230,   230,   230,
     230,   230,   233,   235,   236,   239,   240
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT",
  "DOUBLE", "TRUE", "FALSE", "CHAR", "ID", "IF", "ELSE", "WHILE", "RETURN",
  "FOR", "INT_TYPE", "VOID_TYPE", "DOUBLE_TYPE", "FLOAT_TYPE", "CHAR_TYPE",
  "BOOL_TYPE", "EXTERN_TYPE", "LP", "RP", "LC", "RC", "LB", "RB",
  "SEMICOLON", "COMMA", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN",
  "MULTASSIGN", "DIVASSIGN", "MODASSIGN", "BORASSIGN", "BXORASSIGN",
  "BANDASSIGN", "SRASSIGN", "SLASSIGN", "LOR", "LAND", "BOR", "BAND",
  "BXOR", "SR", "SL", "PLUS", "MINUS", "MULT", "DIV", "MOD", "LNOT",
  "BNOT", "INCR", "DECR", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "$accept",
  "program", "declarationList", "declaration", "varDeclaration",
  "typeSpecifier", "arrayType", "arrayInitList", "arrayInit", "baseType",
  "funDeclaration", "params", "paramList", "param", "compoundStmt",
  "localDeclarations", "statementList", "statement", "expressionStmt",
  "selectionStmt", "iterationStmt", "whileStmt", "forStmt", "returnStmt",
  "expression", "assop", "var", "simpleExpression", "logop",
  "logicExpression", "bitop", "bitExpression", "relop", "shiftExpression",
  "shiop", "additiveExpression", "addop", "term", "mulop", "factor",
  "incre", "terminal", "call", "args", "argList", YY_NULLPTR
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
     315,   316,   317
};
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,  -130,  -130,  -130,  -130,  -130,  -130,    76,     7,    89,
    -130,  -130,    23,     0,    10,  -130,    28,    -3,    33,  -130,
    -130,    30,     9,    53,    42,    70,    54,   167,  -130,    62,
      50,   108,    63,   167,    98,   114,   102,    69,  -130,    14,
    -130,  -130,  -130,  -130,  -130,  -130,    -4,   108,   108,   108,
     108,    99,   141,   -21,    57,   140,    16,    17,    68,  -130,
      13,  -130,  -130,  -130,   103,   105,   109,    76,  -130,    14,
      15,  -130,   108,   108,   111,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,   108,  -130,  -130,   108,  -130,  -130,  -130,   108,  -130,
    -130,  -130,  -130,  -130,  -130,   108,  -130,  -130,   108,  -130,
    -130,   108,  -130,  -130,  -130,   108,  -130,  -130,  -130,   110,
    -130,  -130,  -130,    26,   104,    14,  -130,   115,   124,   116,
    -130,  -130,    57,   140,    16,    17,    68,  -130,  -130,    76,
    -130,  -130,  -130,  -130,   108,  -130,  -130,   135,    21,  -130,
     126,   133,   134,   142,   136,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   131,   108,   108,  -130,   132,
     108,  -130,   143,   144,  -130,   137,    75,    75,   108,   152,
    -130,   160,    75,   108,  -130,   145,    75,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,    21,    22,    23,     0,     0,     2,
       4,     5,     0,     0,     0,     6,     0,    11,    10,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,    19,     0,     0,    26,    29,     0,
      13,   107,   108,   110,   111,   109,    65,     0,     0,     0,
       0,     0,   105,    53,    68,    72,    77,    85,    89,    93,
     100,   103,   106,    12,     0,    30,     0,     0,    17,     0,
       0,    15,   113,     0,     0,   105,    99,    97,    98,     8,
      54,    55,    56,    57,    58,    59,    61,    62,    60,    64,
      63,     0,    69,    70,     0,    73,    74,    75,     0,    78,
      79,    80,    81,    82,    83,     0,    87,    86,     0,    90,
      91,     0,    94,    95,    96,     0,   101,   102,    25,     0,
      33,    24,    28,     0,     0,     0,   116,     0,   114,     0,
     104,    52,    67,    71,    76,    84,    88,    92,    31,    35,
      16,     9,    14,   112,     0,    66,    34,     0,     0,   115,
       0,     0,     0,     0,     0,    32,    43,    38,    36,    37,
      39,    40,    46,    47,    41,     0,     0,     0,    50,     0,
       0,    42,     0,     0,    51,     0,     0,     0,     0,    44,
      48,     0,     0,     0,    45,     0,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,   180,    51,     1,     2,   100,    67,     3,
    -130,   161,  -130,   138,   127,  -130,  -130,  -129,  -130,  -130,
    -130,  -130,  -130,  -130,   -31,  -130,   -44,  -130,  -130,   112,
    -130,   106,  -130,   107,  -130,    95,  -130,    96,  -130,   -35,
    -130,  -130,  -130,  -130,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    35,    17,    70,    71,    18,
      15,    36,    37,    38,   157,   139,   148,   158,   159,   160,
     161,   162,   163,   164,   165,    91,    52,    53,    94,    54,
      98,    55,   105,    56,   108,    57,   111,    58,   115,    59,
      60,    61,    62,   127,   128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    12,    13,    14,    75,    75,    75,    19,    16,    22,
      12,    13,    14,    76,    77,    78,    74,    68,    72,    24,
      92,    93,    73,    23,    41,    42,    23,    43,    44,    45,
      46,   151,    21,   152,   153,   154,    25,    26,    69,    29,
     124,   126,   129,    47,   125,   120,   155,   179,   180,   156,
      75,   140,    27,   184,    75,   125,    30,   187,    28,    25,
     131,    75,   106,   107,    75,   109,   110,    75,   116,   117,
      48,    75,    31,    32,    49,    50,    33,    40,    41,    42,
     137,    43,    44,    45,    46,   151,    39,   152,   153,   154,
      63,     1,     2,     3,     4,     5,     6,    47,    67,   120,
      95,    96,    97,   156,     1,     2,     3,     4,     5,     6,
       7,    41,    42,   149,    43,    44,    45,    46,   112,   113,
     114,   -27,   169,    65,    48,    66,   118,    79,    49,    50,
      47,   119,   141,   120,   130,   172,   173,   138,   143,   175,
     147,    13,    14,   145,   150,    41,    42,   181,    43,    44,
      45,    46,   185,   144,    28,   166,   167,    48,   170,   171,
     174,    49,    50,   182,    47,   178,   176,   177,   186,   123,
     168,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     1,    34,     3,     4,     5,     6,   183,    20,
     146,    48,   142,   121,    64,    49,    50,    99,   100,   101,
     102,   103,   104,   135,   133,   122,   132,   136,     0,     0,
       0,     0,   134
};

static const yytype_int16 yycheck[] =
{
      31,     0,     0,     0,    48,    49,    50,     0,     7,     9,
       9,     9,     9,    48,    49,    50,    47,     3,    22,     9,
      41,    42,    26,    26,     3,     4,    26,     6,     7,     8,
       9,    10,     9,    12,    13,    14,    26,     9,    24,    30,
      25,    72,    73,    22,    29,    24,    25,   176,   177,    28,
      94,    25,    22,   182,    98,    29,     3,   186,    28,    26,
      91,   105,    46,    47,   108,    48,    49,   111,    55,    56,
      49,   115,    30,     3,    53,    54,    22,    27,     3,     4,
     115,     6,     7,     8,     9,    10,    24,    12,    13,    14,
      27,    15,    16,    17,    18,    19,    20,    22,    29,    24,
      43,    44,    45,    28,    15,    16,    17,    18,    19,    20,
      21,     3,     4,   144,     6,     7,     8,     9,    50,    51,
      52,    23,   153,     9,    49,    23,    23,    28,    53,    54,
      22,    26,    28,    24,    23,   166,   167,    27,    23,   170,
     139,   139,   139,    27,     9,     3,     4,   178,     6,     7,
       8,     9,   183,    29,    28,    22,    22,    49,    22,    28,
      28,    53,    54,    11,    22,    28,    23,    23,    23,    69,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    15,    16,    17,    18,    19,    20,    28,     9,
     139,    49,   125,    66,    33,    53,    54,    57,    58,    59,
      60,    61,    62,   108,    98,    67,    94,   111,    -1,    -1,
      -1,    -1,   105
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    64,    65,
      66,    67,    68,    69,    72,    73,    68,    69,    72,     0,
      66,     9,     9,    26,     9,    26,     9,    22,    28,    30,
       3,    30,     3,    22,    16,    68,    74,    75,    76,    24,
      27,     3,     4,     6,     7,     8,     9,    22,    49,    53,
      54,    87,    89,    90,    92,    94,    96,    98,   100,   102,
     103,   104,   105,    27,    74,     9,    23,    29,     3,    24,
      70,    71,    22,    26,    87,    89,   102,   102,   102,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    88,    41,    42,    91,    43,    44,    45,    93,    57,
      58,    59,    60,    61,    62,    95,    46,    47,    97,    48,
      49,    99,    50,    51,    52,   101,    55,    56,    23,    26,
      24,    77,    76,    70,    25,    29,    87,   106,   107,    87,
      23,    87,    92,    94,    96,    98,   100,   102,    27,    78,
      25,    28,    71,    23,    29,    27,    67,    68,    79,    87,
       9,    10,    12,    13,    14,    25,    28,    77,    80,    81,
      82,    83,    84,    85,    86,    87,    22,    22,    28,    87,
      22,    28,    87,    87,    28,    87,    23,    23,    28,    80,
      80,    87,    11,    28,    80,    87,    23,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   106,   106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     7,
       1,     1,     4,     4,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     6,     6,     1,     1,     3,     1,
       2,     4,     4,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     2,     1,     5,     7,     1,     1,     5,     9,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     3,     1
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
#line 64 "parser.y"
                                    {}
#line 1457 "parser.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 67 "parser.y"
                                                 {}
#line 1463 "parser.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 68 "parser.y"
                                    {}
#line 1469 "parser.tab.c"
    break;

  case 5: /* declaration: varDeclaration  */
#line 71 "parser.y"
                                     {}
#line 1475 "parser.tab.c"
    break;

  case 6: /* declaration: funDeclaration  */
#line 72 "parser.y"
                                      {}
#line 1481 "parser.tab.c"
    break;

  case 7: /* varDeclaration: typeSpecifier ID SEMICOLON  */
#line 75 "parser.y"
                                               {}
#line 1487 "parser.tab.c"
    break;

  case 8: /* varDeclaration: baseType ID ASSIGN expression SEMICOLON  */
#line 76 "parser.y"
                                                              {}
#line 1493 "parser.tab.c"
    break;

  case 9: /* varDeclaration: arrayType ID ASSIGN LC arrayInitList RC SEMICOLON  */
#line 77 "parser.y"
                                                                {}
#line 1499 "parser.tab.c"
    break;

  case 10: /* typeSpecifier: baseType  */
#line 80 "parser.y"
                             {}
#line 1505 "parser.tab.c"
    break;

  case 11: /* typeSpecifier: arrayType  */
#line 81 "parser.y"
                                {}
#line 1511 "parser.tab.c"
    break;

  case 12: /* arrayType: baseType LB INT RB  */
#line 84 "parser.y"
                                        {}
#line 1517 "parser.tab.c"
    break;

  case 13: /* arrayType: arrayType LB INT RB  */
#line 85 "parser.y"
                                          {}
#line 1523 "parser.tab.c"
    break;

  case 14: /* arrayInitList: arrayInitList COMMA arrayInit  */
#line 87 "parser.y"
                                                  {}
#line 1529 "parser.tab.c"
    break;

  case 15: /* arrayInitList: arrayInit  */
#line 88 "parser.y"
                                {}
#line 1535 "parser.tab.c"
    break;

  case 16: /* arrayInit: LC arrayInitList RC  */
#line 91 "parser.y"
                                        {}
#line 1541 "parser.tab.c"
    break;

  case 17: /* arrayInit: INT  */
#line 92 "parser.y"
                          {}
#line 1547 "parser.tab.c"
    break;

  case 18: /* baseType: INT_TYPE  */
#line 95 "parser.y"
                             {}
#line 1553 "parser.tab.c"
    break;

  case 19: /* baseType: VOID_TYPE  */
#line 96 "parser.y"
                                {}
#line 1559 "parser.tab.c"
    break;

  case 20: /* baseType: DOUBLE_TYPE  */
#line 97 "parser.y"
                                  {}
#line 1565 "parser.tab.c"
    break;

  case 21: /* baseType: FLOAT_TYPE  */
#line 98 "parser.y"
                                 {}
#line 1571 "parser.tab.c"
    break;

  case 22: /* baseType: CHAR_TYPE  */
#line 99 "parser.y"
                                {}
#line 1577 "parser.tab.c"
    break;

  case 23: /* baseType: BOOL_TYPE  */
#line 100 "parser.y"
                                {}
#line 1583 "parser.tab.c"
    break;

  case 24: /* funDeclaration: typeSpecifier ID LP params RP compoundStmt  */
#line 103 "parser.y"
                                                               {}
#line 1589 "parser.tab.c"
    break;

  case 25: /* funDeclaration: EXTERN_TYPE typeSpecifier ID LP params RP  */
#line 104 "parser.y"
                                                                {}
#line 1595 "parser.tab.c"
    break;

  case 26: /* params: paramList  */
#line 107 "parser.y"
                              {}
#line 1601 "parser.tab.c"
    break;

  case 27: /* params: VOID_TYPE  */
#line 108 "parser.y"
                                {}
#line 1607 "parser.tab.c"
    break;

  case 28: /* paramList: paramList COMMA param  */
#line 111 "parser.y"
                                          {}
#line 1613 "parser.tab.c"
    break;

  case 29: /* paramList: param  */
#line 112 "parser.y"
                             {}
#line 1619 "parser.tab.c"
    break;

  case 30: /* param: typeSpecifier ID  */
#line 115 "parser.y"
                                     {}
#line 1625 "parser.tab.c"
    break;

  case 31: /* param: typeSpecifier ID LB RB  */
#line 116 "parser.y"
                                              {}
#line 1631 "parser.tab.c"
    break;

  case 32: /* compoundStmt: LC localDeclarations statementList RC  */
#line 119 "parser.y"
                                                           {}
#line 1637 "parser.tab.c"
    break;

  case 33: /* localDeclarations: %empty  */
#line 121 "parser.y"
                             {}
#line 1643 "parser.tab.c"
    break;

  case 34: /* localDeclarations: localDeclarations varDeclaration  */
#line 122 "parser.y"
                                                       {}
#line 1649 "parser.tab.c"
    break;

  case 35: /* statementList: %empty  */
#line 125 "parser.y"
                              {}
#line 1655 "parser.tab.c"
    break;

  case 36: /* statementList: statementList statement  */
#line 126 "parser.y"
                                              {}
#line 1661 "parser.tab.c"
    break;

  case 37: /* statement: expressionStmt  */
#line 129 "parser.y"
                                   {}
#line 1667 "parser.tab.c"
    break;

  case 38: /* statement: compoundStmt  */
#line 130 "parser.y"
                                   {}
#line 1673 "parser.tab.c"
    break;

  case 39: /* statement: selectionStmt  */
#line 131 "parser.y"
                                    {}
#line 1679 "parser.tab.c"
    break;

  case 40: /* statement: iterationStmt  */
#line 132 "parser.y"
                                    {}
#line 1685 "parser.tab.c"
    break;

  case 41: /* statement: returnStmt  */
#line 133 "parser.y"
                                 {}
#line 1691 "parser.tab.c"
    break;

  case 42: /* expressionStmt: expression SEMICOLON  */
#line 136 "parser.y"
                                         {}
#line 1697 "parser.tab.c"
    break;

  case 43: /* expressionStmt: SEMICOLON  */
#line 137 "parser.y"
                                {}
#line 1703 "parser.tab.c"
    break;

  case 44: /* selectionStmt: IF LP expression RP statement  */
#line 140 "parser.y"
                                                    {}
#line 1709 "parser.tab.c"
    break;

  case 45: /* selectionStmt: IF LP expression RP statement ELSE statement  */
#line 141 "parser.y"
                                                                   {}
#line 1715 "parser.tab.c"
    break;

  case 46: /* iterationStmt: whileStmt  */
#line 144 "parser.y"
                              {}
#line 1721 "parser.tab.c"
    break;

  case 47: /* iterationStmt: forStmt  */
#line 145 "parser.y"
                               {}
#line 1727 "parser.tab.c"
    break;

  case 48: /* whileStmt: WHILE LP expression RP statement  */
#line 148 "parser.y"
                                                     {}
#line 1733 "parser.tab.c"
    break;

  case 49: /* forStmt: FOR LP expression SEMICOLON expression SEMICOLON expression RP statement  */
#line 151 "parser.y"
                                                                                             {}
#line 1739 "parser.tab.c"
    break;

  case 50: /* returnStmt: RETURN SEMICOLON  */
#line 154 "parser.y"
                                     {}
#line 1745 "parser.tab.c"
    break;

  case 51: /* returnStmt: RETURN expression SEMICOLON  */
#line 155 "parser.y"
                                                     {}
#line 1751 "parser.tab.c"
    break;

  case 52: /* expression: var assop expression  */
#line 158 "parser.y"
                                         {}
#line 1757 "parser.tab.c"
    break;

  case 53: /* expression: simpleExpression  */
#line 159 "parser.y"
                                       {}
#line 1763 "parser.tab.c"
    break;

  case 54: /* assop: ASSIGN  */
#line 162 "parser.y"
                           {}
#line 1769 "parser.tab.c"
    break;

  case 55: /* assop: PLUSASSIGN  */
#line 163 "parser.y"
                                 {}
#line 1775 "parser.tab.c"
    break;

  case 56: /* assop: MINUSASSIGN  */
#line 164 "parser.y"
                                  {}
#line 1781 "parser.tab.c"
    break;

  case 57: /* assop: MULTASSIGN  */
#line 165 "parser.y"
                                 {}
#line 1787 "parser.tab.c"
    break;

  case 58: /* assop: DIVASSIGN  */
#line 166 "parser.y"
                                {}
#line 1793 "parser.tab.c"
    break;

  case 59: /* assop: MODASSIGN  */
#line 167 "parser.y"
                                {}
#line 1799 "parser.tab.c"
    break;

  case 60: /* assop: BANDASSIGN  */
#line 168 "parser.y"
                                 {}
#line 1805 "parser.tab.c"
    break;

  case 61: /* assop: BORASSIGN  */
#line 169 "parser.y"
                                {}
#line 1811 "parser.tab.c"
    break;

  case 62: /* assop: BXORASSIGN  */
#line 170 "parser.y"
                                 {}
#line 1817 "parser.tab.c"
    break;

  case 63: /* assop: SLASSIGN  */
#line 171 "parser.y"
                               {}
#line 1823 "parser.tab.c"
    break;

  case 64: /* assop: SRASSIGN  */
#line 172 "parser.y"
                               {}
#line 1829 "parser.tab.c"
    break;

  case 65: /* var: ID  */
#line 175 "parser.y"
                       {}
#line 1835 "parser.tab.c"
    break;

  case 66: /* var: ID LB expression RB  */
#line 176 "parser.y"
                                          {}
#line 1841 "parser.tab.c"
    break;

  case 67: /* simpleExpression: simpleExpression logop logicExpression  */
#line 179 "parser.y"
                                                           {}
#line 1847 "parser.tab.c"
    break;

  case 68: /* simpleExpression: logicExpression  */
#line 180 "parser.y"
                                      {}
#line 1853 "parser.tab.c"
    break;

  case 69: /* logop: LOR  */
#line 183 "parser.y"
                        {}
#line 1859 "parser.tab.c"
    break;

  case 70: /* logop: LAND  */
#line 184 "parser.y"
                           {}
#line 1865 "parser.tab.c"
    break;

  case 71: /* logicExpression: logicExpression bitop bitExpression  */
#line 186 "parser.y"
                                                         {}
#line 1871 "parser.tab.c"
    break;

  case 72: /* logicExpression: bitExpression  */
#line 187 "parser.y"
                                    {}
#line 1877 "parser.tab.c"
    break;

  case 76: /* bitExpression: bitExpression relop shiftExpression  */
#line 192 "parser.y"
                                                        {}
#line 1883 "parser.tab.c"
    break;

  case 77: /* bitExpression: shiftExpression  */
#line 193 "parser.y"
                                      {}
#line 1889 "parser.tab.c"
    break;

  case 84: /* shiftExpression: shiftExpression shiop additiveExpression  */
#line 198 "parser.y"
                                                             {}
#line 1895 "parser.tab.c"
    break;

  case 85: /* shiftExpression: additiveExpression  */
#line 199 "parser.y"
                                         {}
#line 1901 "parser.tab.c"
    break;

  case 88: /* additiveExpression: additiveExpression addop term  */
#line 204 "parser.y"
                                                  {}
#line 1907 "parser.tab.c"
    break;

  case 89: /* additiveExpression: term  */
#line 205 "parser.y"
                           {}
#line 1913 "parser.tab.c"
    break;

  case 92: /* term: term mulop factor  */
#line 210 "parser.y"
                                      {}
#line 1919 "parser.tab.c"
    break;

  case 93: /* term: factor  */
#line 211 "parser.y"
                             {}
#line 1925 "parser.tab.c"
    break;

  case 97: /* factor: LNOT factor  */
#line 216 "parser.y"
                                {}
#line 1931 "parser.tab.c"
    break;

  case 98: /* factor: BNOT factor  */
#line 217 "parser.y"
                                  {}
#line 1937 "parser.tab.c"
    break;

  case 99: /* factor: MINUS factor  */
#line 218 "parser.y"
                                   {}
#line 1943 "parser.tab.c"
    break;

  case 100: /* factor: incre  */
#line 219 "parser.y"
                            {}
#line 1949 "parser.tab.c"
    break;

  case 101: /* incre: incre INCR  */
#line 222 "parser.y"
                               {}
#line 1955 "parser.tab.c"
    break;

  case 102: /* incre: incre DECR  */
#line 223 "parser.y"
                                 {}
#line 1961 "parser.tab.c"
    break;

  case 103: /* incre: terminal  */
#line 224 "parser.y"
                               {}
#line 1967 "parser.tab.c"
    break;

  case 104: /* terminal: LP expression RP  */
#line 227 "parser.y"
                                     {}
#line 1973 "parser.tab.c"
    break;

  case 105: /* terminal: var  */
#line 228 "parser.y"
                          {}
#line 1979 "parser.tab.c"
    break;

  case 106: /* terminal: call  */
#line 229 "parser.y"
                           {}
#line 1985 "parser.tab.c"
    break;

  case 112: /* call: ID LP args RP  */
#line 233 "parser.y"
                                 {}
#line 1991 "parser.tab.c"
    break;

  case 113: /* args: %empty  */
#line 235 "parser.y"
                             {}
#line 1997 "parser.tab.c"
    break;

  case 114: /* args: argList  */
#line 236 "parser.y"
                              {}
#line 2003 "parser.tab.c"
    break;

  case 115: /* argList: argList COMMA expression  */
#line 239 "parser.y"
                                             {}
#line 2009 "parser.tab.c"
    break;

  case 116: /* argList: expression  */
#line 240 "parser.y"
                                 {}
#line 2015 "parser.tab.c"
    break;


#line 2019 "parser.tab.c"

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

#line 243 "parser.y"


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
