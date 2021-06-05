%{
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

unique_ptr<vector<unique_ptr<declarationNode>>> root;

extern int yylex(void);

void yyerror(std::string s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/

%}

%union{
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

};

%token <type_int> INT   //指定INT的语义值是type_int，有词法分析得到的数值
%token <type_float> FLOAT
// %token <type_double> DOUBLE //needed?
%token <type_bool> TRUE  FALSE 
%token <type_char> CHAR 

%token <type_id> ID

%token IF ELSE WHILE RETURN FOR //keywords
%token <string> INT_TYPE VOID_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE BOOL_TYPE EXTERN_TYPE//type words

%token LP RP LC RC LB RB SEMICOLON COMMA //assoc chara
%token <string> ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN //assign op
%token <string> LOR LAND BOR BAND BXOR SR SL PLUS MINUS MULT DIV MOD LNOT BNOT INCR DECR //op
%token <string> EQ NEQ LT GT LTE GTE //relop
            
%type<declarationNode>      declaration
%type<varDeclarationNode>   varDeclaration
// %type<arrayInitListNode>    arrayInit
%type<funDeclarationNode>   funDeclaration
%type<paramNode>            param
%type<compoundStmtNode>     compoundStmt
%type<statementNode>        statement
%type<selectionStmtNode>    selectionStmt
%type<iterationStmtNode>    iterationStmt
%type<whileStmtNode>        whileStmt
%type<forStmtNode>          forStmt
%type<returnStmtNode>       returnStmt
%type<expressionNode>       expressionStmt expression
%type<varNode>              var
%type<operandNode>          operand
%type<singleNode>           single
%type<callNode>             call

%type<intVec>               arrayPost arrayPostParam
%type<stringNode>           baseType assop prefix

%type<declarationNodeVec>       declarationList
%type<idListNodeVec>            idList
// %type<arrayInitListNodeVec>     arrayInitList
%type<singleNodeVec>            arrayConstList
%type<paramVec>                 params paramList
%type<varDeclarationNodeVec>    localDeclarations
%type<statementNodeVec>         statementList
%type<expressionNodeVec>        argList args


%right ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN
%left LOR
%left LAND
%left BOR
%left BXOR
%left BAND
%left EQ NEQ
%left LT GT LTE GTE
%left SL SR
%left PLUS MINUS
%left MULT DIV MOD
%right LNOT BNOT

%nonassoc ELSE

%start program


%%

program:            declarationList { root = move($1); }
                    ;

declarationList:    declarationList declaration  {
                        $1->push_back(move($2));
                        $$ = move($1);
                    }
                    | declaration   {
                        $$ = make_unique<vector<unique_ptr<DeclarationNode>>>();
                        $$->push_back(move($1));
                    }
                    ;

declaration:        varDeclaration { $$ = make_unique<DeclarationNode>(move($1)); }
                    | funDeclaration  { $$ = make_unique<DeclarationNode>(move($1)); }
                    ;

varDeclaration:     baseType idList SEMICOLON { 
                        $$ = make_unique<VarDeclarationNode>(move($1), move($2), nullptr, nullptr);
                    }
                    | baseType ID arrayPost SEMICOLON {
                        $$ = make_unique<vector<unique_ptr<IdListNode>>>();
                        $$-> push_back( make_unique<IdListNode>(make_unique<string>($2), nullptr) );
                        $$ = make_unique<VarDeclarationNode>(move($1), move($$), move($3), nullptr);
                    }
	                | baseType ID arrayPost ASSIGN LC arrayConstList RC SEMICOLON {
                        $$ = make_unique<vector<unique_ptr<IdListNode>>>();
                        $$-> push_back( make_unique<IdListNode>(make_unique<string>($2), nullptr) );
                        $$ = make_unique<VarDeclarationNode>(move($1), move($$), move($3), move($6));
                    }
                    ;

idList:             idList COMMA ID { 
                        $1->push_back(make_unique<IdListNode>(make_unique<string>($3), nullptr));
                        $$ = move($1);
                    }
                    | idList COMMA ID ASSIGN expression {
                        $1->push_back(make_unique<IdListNode>(make_unique<string>($3), move($5)));
                        $$ = move($1);
                    }
                    | ID { 
                        $$ = make_unique<vector<unique_ptr<IdListNode>>>();
                        $$->push_back(make_unique<IdListNode>(make_unique<string>($1), nullptr)); 
                    }
                    | ID ASSIGN expression {
                        $$ = make_unique<vector<unique_ptr<IdListNode>>>();
                        $$->push_back(make_unique<IdListNode>(make_unique<string>($1), move($3))); 
                    }
                    ;
                
arrayPost:          LB INT RB  {
                        $$ = make_unique<vector<int>>();
                        $$->push_back($2);
                    }
                    | arrayPost LB INT RB {
                        $1->push_back($3);
                        $$ = move($1);
                    }
                    ;

// arrayInitList:      arrayInitList COMMA arrayInit {
//                         $1->push_back($3);
//                         $$ = move($1);
//                     }
//                     | arrayInit {
//                         $$ = make_unique<vector<unique_ptr<ArrayInitListNode>>>();
//                         $$->push_back($1);
//                     }
//                     | arrayConstList {
//                         $$ = make_unique<vector<unique_ptr<ArrayInitListNode>>>();
//                         $$->push_back(make_unique<ArrayInitListNode>(move($1), true));
//                     }
//                     ;

// arrayInit:          LC arrayInitList RC { make_unique<ArrayInitListNode>(move($2), false); };

arrayConstList:     arrayConstList COMMA single {
                        $1->push_back(move($3));
                        $$ = move($1);
                    }
                    | single {
                        $$ = make_unique<vector<unique_ptr<SingleNode>>>();
                        $$->push_back(move($1));
                    }

baseType:           INT_TYPE { $$ = make_unique<string>($1); }
                    | DOUBLE_TYPE { $$ = make_unique<string>($1); }
                    | FLOAT_TYPE { $$ = make_unique<string>($1); }
                    | CHAR_TYPE { $$ = make_unique<string>($1); }
                    | BOOL_TYPE { $$ = make_unique<string>($1); }
                    ;

funDeclaration:     baseType ID LP params RP compoundStmt { $$ = make_unique<FunDeclarationNode>(make_unique<string>($1), move($4), move($6), false) }
                    | VOID_TYPE ID LP params RP compoundStmt { $$ = make_unique<FunDeclarationNode>(nullptr, move($4), move($6), false) }
                    | EXTERN_TYPE baseType ID LP params RP SEMICOLON { $$ = make_unique<FunDeclarationNode>(make_unique<string>($2), move($5), nullptr, true) }
                    | EXTERN_TYPE VOID_TYPE ID LP params RP SEMICOLON { $$ = make_unique<FunDeclarationNode>(nullptr, move($5), nullptr, true) }
                    ;

params:             paramList { $$ = move($1) }
                    | VOID_TYPE { $$ = nullptr; }
                    ;

paramList:          paramList COMMA param {
                        $1->push_back(move($3));
                        $$ = move($1);
                    }
                    |  param {
                        $$ = make_unique<vector<unique_ptr<ParamNode>>>();
                        $$->push_back(move($1));
                    }
                    ;

param:              baseType ID { $$ = make_unique<ParamNode>(move($1), move($2), nullptr) }
                    | baseType ID arrayPostParam { $$ = make_unique<ParamNode>(move($1), move($2), move($3)) }
                    ;

arrayPostParam:     LB RB {
                        $$ = make_unique<vector<int>>();
                    }
                    | LB INT RB  {
                        $$ = make_unique<vector<int>>();
                    }
                    | arrayPostParam LB INT RB {
                        $1->push_back($3);
                        $$ = move($1);
                    }
                    ;

compoundStmt:       LC localDeclarations statementList RC { $$ = make_unique<CompoundStmtNode>(move($2), move($3)); }
                    | LC localDeclarations RC { $$ = make_unique<CompoundStmtNode>(move($2), nullptr); }
                    | LC statementList RC { $$ = make_unique<CompoundStmtNode>(nullptr, move($2)); }
                    | LC RC { $$ = make_unique<CompoundStmtNode>(nullptr, nullptr); }
                    ;

localDeclarations:  varDeclaration {
                        $$ = make_unique<vector<unique_ptr<VarDeclarationNode>>>();
                        $$->push_back(move($1));
                    }
                    | localDeclarations varDeclaration { 
                        $1->push_back(move($2));
                        $$ = move($1);
                    }
                    ;

statementList:      statement { 
                        $$ = make_unique<vector<unique_ptr<StatementNode>>>();
                        $$->push_back(move($1));
                    }
                    | statementList statement {
                        $1->push_back(move($2));
                        $$ = move($1);
                    }
                    ;

statement:          expressionStmt { $$ = make_unique<StatementNode>(move($1)); }
                    | compoundStmt { $$ = make_unique<StatementNode>(move($1)); }
                    | selectionStmt { $$ = make_unique<StatementNode>(move($1)); }
                    | iterationStmt { $$ = make_unique<StatementNode>(move($1)); }
                    | returnStmt { $$ = make_unique<StatementNode>(move($1)); }
                    ;

expressionStmt:     expression SEMICOLON { $$ = move($1); }
                    | SEMICOLON { $$ = nullptr; }
                    ;

selectionStmt:      IF LP expression RP statement { $$ = make_unique<SelectionStmtNode>(move($3), move($5), nullptr); }
                    | IF LP expression RP statement ELSE statement { $$ = make_unique<selectionStmtNode>(move($3), move($5), move($7)); }
                    ;

iterationStmt:      whileStmt { $$ = make_unique<IterationStmtNode>(move($1)); }
                    | forStmt { $$ = make_unique<IterationStmtNode>(move($1)); }
                    ;

whileStmt:          WHILE LP expression RP statement {
                        $$ = make_unique<WhileStmtNode>(move($3), move($5));
                    }
                    ;

forStmt:            FOR LP expression SEMICOLON expression SEMICOLON expression RP statement {
                        $$ = make_unique<ForStmtNode>(move($3), move($5), move($7), move($9));
                    }
                    ;
 
returnStmt:         RETURN SEMICOLON { $$ = nullptr; }
                    | RETURN expression SEMICOLON { $$ = make_unique<ReturnStmtNode>(move($2)); }
                    ;

expression:         var assop expression { $$ = make_unique<ExpressionNode>(move($2), move($1), move($3)); }
                    | operand { $$ = make_unique<ExpressionNode>(nullptr, nullptr, move($1)); }
                    ;

assop:              ASSIGN { $$ = make_unique<string>($1); }
                    | PLUSASSIGN { $$ = make_unique<string>($1); } 
                    | MINUSASSIGN { $$ = make_unique<string>($1); } 
                    | MULTASSIGN { $$ = make_unique<string>($1); } 
                    | DIVASSIGN { $$ = make_unique<string>($1); } 
                    | MODASSIGN { $$ = make_unique<string>($1); } 
                    | BANDASSIGN { $$ = make_unique<string>($1); } 
                    | BORASSIGN { $$ = make_unique<string>($1); } 
                    | BXORASSIGN { $$ = make_unique<string>($1); } 
                    | SLASSIGN { $$ = make_unique<string>($1); } 
                    | SRASSIGN { $$ = make_unique<string>($1); } 
                    ;

var:                ID { $$ = make_unique<VarNode>(make_unique<string>($1), nullptr); }
                    | ID arrayPost { $$ = make_unique<VarNode>(make_unique<string>($1), move($2)); }
                    ;

operand:            operand LOR operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LAND operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BOR operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BXOR operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BAND operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand EQ operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand NEQ operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LT operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand GT operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LTE operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand GTE operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand SL operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand SR operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand PLUS operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MINUS operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MULT operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand DIV operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MOD operand { $$ = make_unique<OperandNode>(make_unique<string>($2), move($1), move($3)); }
                    | prefix LP operand RP { $$ = make_unique<OperandNode>(move($1), move($3), nullptr); }
                    | LP operand RP { $$ = make_unique<OperandNode>(nullptr, move($2), nullptr); }
                    | prefix single {  $$ = make_unique<OperandNode>(move($1), move($2), nullptr); }
                    | single { $$ = make_unique<OperandNode>(nullptr, move($1), nullptr);  }
                    ;
                    

prefix:             BNOT { $$ = make_unique<string>($1); }
                    | LNOT  { $$ = make_unique<string>($1); }
                    | MINUS { $$ = make_unique<string>($1); }
                    ;

single:             var { $$ = make_unique<SingleNode>( make_unique<string>($1) ); }
                    | call { $$ = make_unique<SingleNode>($1); }
                    | INT { $$ = make_unique<SingleNode>($1); }
                    | FLOAT { $$ = make_unique<SingleNode>($1); }
                    | CHAR { $$ = make_unique<SingleNode>($1); }
                    | TRUE { $$ = make_unique<SingleNode>($1); }
                    | FALSE { $$ = make_unique<SingleNode>($1); }
                    // overload multiple initialization fun, with different type (enum)
                    ;

call:               ID LP args RP {
                        $$ = make_unique<CallNode>(make_unique<string>($1), move($3)));
                    };

args:               %empty { $$ = nullptr; }
                    | argList { $$ = move($1); } 
                    ;

argList:            argList COMMA expression {
                        $1->push_back(move($3));
                        $$ = move($1);
                    }
                    | expression {
                        $$ = make_unique<vector<unique_ptr<ExpressionNode>>>();
                        $$->push_back(move($1));
                    }
                    ;    

%%

int main() { 
    yyparse();
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
