/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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

    unique_ptr<DeclarationNode>*     declarationNode;
    unique_ptr<VarDeclarationNode>  varDeclarationNode;
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
    unique_ptr<vector<unique_ptr<SingleNode>>>  singleNodeVec;
    unique_ptr<vector<unique_ptr<ParamNode>>>  paramVec;
    unique_ptr<vector<unique_ptr<VarDeclarationNode>>>  varDeclarationNodeVec;
    unique_ptr<vector<unique_ptr<StatementNode>>>  statementNodeVec;
    unique_ptr<vector<unique_ptr<ExpressionNode>>>  expressionNodeVec;

    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];


#line 163 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
