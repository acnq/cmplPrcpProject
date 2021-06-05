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

vector<DeclarationNode*> *root;

extern int yylex(void);

void yyerror(std::string s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/

%}

%union{
    DeclarationNode      *declarationNode;
    VarDeclarationNode   *varDeclarationNode;
    FunDeclarationNode   *funDeclarationNode;
    ParamNode            *paramNode;
    CompoundStmtNode     *compoundStmtNode;
    StatementNode        *statementNode;
    SelectionStmtNode    *selectionStmtNode;
    IterationStmtNode    *iterationStmtNode;
    WhileStmtNode        *whileStmtNode;
    ForStmtNode          *forStmtNode;
    ReturnStmtNode       *returnStmtNode;
    ExpressionNode       *expressionNode;
    VarNode              *varNode;
    OperandNode          *operandNode;
    SingleNode           *singleNode;
    CallNode             *callNode;
    
    vector<int>* intVec;
    string*  stringNode;

    vector<DeclarationNode*>    *declarationNodeVec;
    vector<IdListNode*>         *idListNodeVec;
    vector<SingleNode*>         *singleNodeVec;
    vector<ParamNode*>          *paramVec;
    vector<VarDeclarationNode*> *varDeclarationNodeVec;
    vector<StatementNode*>      *statementNodeVec;
    vector<ExpressionNode*>     *expressionNodeVec;

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
%token <type_id> INT_TYPE VOID_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE BOOL_TYPE EXTERN_TYPE//type words

%token LP RP LC RC LB RB SEMICOLON COMMA //assoc chara
%token /* <char*> */  ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN //assign op
%token /* <char*> */  LOR LAND BOR BAND BXOR SR SL PLUS MINUS MULT DIV MOD LNOT BNOT INCR DECR //op
%token /* <char*> */  EQ NEQ LT GT LTE GTE //relop
            
%type<declarationNode>      declaration
%type<varDeclarationNode>   varDeclaration
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

program:            declarationList { root = $1; }
                    ;

declarationList:    declarationList declaration  {
                        $1->push_back($2);
                        $$ = $1;
                    }
                    | declaration   {
                        $$ = new vector<DeclarationNode*>();
                        $$->push_back($1);
                    }
                    ;

declaration:        varDeclaration { $$ = new DeclarationNode($1); }
                    | funDeclaration  { $$ = new DeclarationNode($1); }
                    ;

varDeclaration:     baseType idList SEMICOLON { 
                        $$ = new VarDeclarationNode($1, $2, nullptr, nullptr);
                    }
                    | baseType ID arrayPost SEMICOLON {
                        auto v = new vector<IdListNode*>();
                        v-> push_back( new IdListNode( new string($2), nullptr) );
                        $$ = new VarDeclarationNode($1, v, $3, nullptr);
                    }
	                | baseType ID arrayPost ASSIGN LC arrayConstList RC SEMICOLON {
                        auto v = new vector<IdListNode*>();
                        v-> push_back( new IdListNode( new string($2), nullptr) );
                        $$ = new VarDeclarationNode($1, v, $3, $6);
                    }
                    ;

idList:             idList COMMA ID { 
                        $1->push_back(new IdListNode(new string($3), nullptr));
                        $$ = $1;
                    }
                    | idList COMMA ID ASSIGN expression {
                        $1->push_back(new IdListNode(new string($3), $5));
                        $$ = $1;
                    }
                    | ID { 
                        $$ = new vector<IdListNode*>();
                        $$->push_back(new IdListNode(new string($1), nullptr)); 
                    }
                    | ID ASSIGN expression {
                        $$ = new vector<IdListNode*>();
                        $$->push_back(new IdListNode(new string($1), $3)); 
                    }
                    ;
                
arrayPost:          LB INT RB  {
                        $$ = new vector<int>();
                        $$->push_back($2);
                    }
                    | arrayPost LB INT RB {
                        $1->push_back($3);
                        $$ = $1;
                    }
                    ;

// arrayInitList:      arrayInitList COMMA arrayInit {
//                         $1->push_back($3);
//                         $$ = $1;
//                     }
//                     | arrayInit {
//                         $$ = new vector<ArrayInitListNode*>();
//                         $$->push_back($1);
//                     }
//                     | arrayConstList {
//                         $$ = new vector<ArrayInitListNode*>();
//                         $$->push_back(new ArrayInitListNode($1, true));
//                     }
//                     ;

// arrayInit:          LC arrayInitList RC { new ArrayInitListNode($2, false); };

arrayConstList:     arrayConstList COMMA single {
                        $1->push_back($3);
                        $$ = $1;
                    }
                    | single {
                        $$ = new vector<SingleNode*>();
                        $$->push_back($1);
                    }

baseType:           INT_TYPE { $$ = new string("INT_TYPE"); }
                    | DOUBLE_TYPE { $$ = new string("DOUBLE_TYPE"); }
                    | FLOAT_TYPE { $$ = new string("FLOAT_TYPE"); }
                    | CHAR_TYPE { $$ = new string("CHAR_TYPE"); }
                    | BOOL_TYPE { $$ = new string("BOOL_TYPE"); }
                    ;

funDeclaration:     baseType ID LP params RP compoundStmt { $$ = new FunDeclarationNode($1, new string($2), $4, $6, false); }
                    | VOID_TYPE ID LP params RP compoundStmt { $$ = new FunDeclarationNode(nullptr, new string($2), $4, $6, false); }
                    | EXTERN_TYPE baseType ID LP params RP SEMICOLON { $$ = new FunDeclarationNode($2, new string($3), $5, nullptr, true); }
                    | EXTERN_TYPE VOID_TYPE ID LP params RP SEMICOLON { $$ = new FunDeclarationNode(nullptr, new string($3), $5, nullptr, true); }
                    ;

params:             paramList { $$ = $1; }
                    | VOID_TYPE { $$ = nullptr; }
                    ;

paramList:          paramList COMMA param {
                        $1->push_back($3);
                        $$ = $1;
                    }
                    |  param {
                        $$ = new vector<ParamNode*>();
                        $$->push_back($1);
                    }
                    ;

param:              baseType ID { $$ = new ParamNode($1, new string($2), nullptr); }
                    | baseType ID arrayPostParam { $$ = new ParamNode($1, new string($2), $3); }
                    ;

arrayPostParam:     LB RB {
                        $$ = new vector<int>();
                    }
                    | LB INT RB  {
                        $$ = new vector<int>();
                    }
                    | arrayPostParam LB INT RB {
                        $1->push_back($3);
                        $$ = $1;
                    }
                    ;

compoundStmt:       LC localDeclarations statementList RC { $$ = new CompoundStmtNode($2, $3); }
                    | LC localDeclarations RC { $$ = new CompoundStmtNode($2, nullptr); }
                    | LC statementList RC { $$ = new CompoundStmtNode(nullptr, $2); }
                    | LC RC { $$ = new CompoundStmtNode(nullptr, nullptr); }
                    ;

localDeclarations:  varDeclaration {
                        $$ = new vector<VarDeclarationNode*>();
                        $$->push_back($1);
                    }
                    | localDeclarations varDeclaration { 
                        $1->push_back($2);
                        $$ = $1;
                    }
                    ;

statementList:      statement { 
                        $$ = new vector<StatementNode*>();
                        $$->push_back($1);
                    }
                    | statementList statement {
                        $1->push_back($2);
                        $$ = $1;
                    }
                    ;

statement:          expressionStmt { $$ = new StatementNode($1); }
                    | compoundStmt { $$ = new StatementNode($1); }
                    | selectionStmt { $$ = new StatementNode($1); }
                    | iterationStmt { $$ = new StatementNode($1); }
                    | returnStmt { $$ = new StatementNode($1); }
                    ;

expressionStmt:     expression SEMICOLON { $$ = $1; }
                    | SEMICOLON { $$ = nullptr; }
                    ;

selectionStmt:      IF LP expression RP statement { $$ = new SelectionStmtNode($3, $5, nullptr); }
                    | IF LP expression RP statement ELSE statement { $$ = new SelectionStmtNode($3, $5, $7); }
                    ;

iterationStmt:      whileStmt { $$ = new IterationStmtNode($1); }
                    | forStmt { $$ = new IterationStmtNode($1); }
                    ;

whileStmt:          WHILE LP expression RP statement {
                        $$ = new WhileStmtNode($3, $5);
                    }
                    ;

forStmt:            FOR LP expression SEMICOLON expression SEMICOLON expression RP statement {
                        $$ = new ForStmtNode($3, $5, $7, $9);
                    }
                    ;
 
returnStmt:         RETURN SEMICOLON { $$ = nullptr; }
                    | RETURN expression SEMICOLON { $$ = new ReturnStmtNode($2); }
                    ;

expression:         var assop expression { $$ = new ExpressionNode($2, $1, $3, nullptr); }
                    | operand { $$ = new ExpressionNode(nullptr, nullptr, nullptr, $1); }
                    ;

assop:              ASSIGN { $$ = new string("ASSIGN"); }
                    | PLUSASSIGN { $$ = new string("PLUSASSIGN"); } 
                    | MINUSASSIGN { $$ = new string("MINUSASSIGN"); } 
                    | MULTASSIGN { $$ = new string("MULTASSIGN"); } 
                    | DIVASSIGN { $$ = new string("DIVASSIGN"); } 
                    | MODASSIGN { $$ = new string("MODASSIGN"); } 
                    | BANDASSIGN { $$ = new string("BANDASSIGN"); } 
                    | BORASSIGN { $$ = new string("BORASSIGN"); } 
                    | BXORASSIGN { $$ = new string("BXORASSIGN"); } 
                    | SLASSIGN { $$ = new string("SLASSIGN"); } 
                    | SRASSIGN { $$ = new string("SRASSIGN"); } 
                    ;

var:                ID { $$ = new VarNode(new string($1), nullptr); }
                    | ID arrayPost { $$ = new VarNode(new string($1), $2); }
                    ;

operand:            operand LOR operand { $$ = new OperandNode(new string("LOR"), $1, $3, nullptr); }
                    | operand LAND operand { $$ = new OperandNode(new string("LAND"), $1, $3, nullptr); }
                    | operand BOR operand { $$ = new OperandNode(new string("BOR"), $1, $3, nullptr); }
                    | operand BXOR operand { $$ = new OperandNode(new string("BXOR"), $1, $3, nullptr); }
                    | operand BAND operand { $$ = new OperandNode(new string("BAND"), $1, $3, nullptr); }
                    | operand EQ operand { $$ = new OperandNode(new string("EQ"), $1, $3, nullptr); }
                    | operand NEQ operand { $$ = new OperandNode(new string("NEQ"), $1, $3, nullptr); }
                    | operand LT operand { $$ = new OperandNode(new string("LT"), $1, $3, nullptr); }
                    | operand GT operand { $$ = new OperandNode(new string("GT"), $1, $3, nullptr); }
                    | operand LTE operand { $$ = new OperandNode(new string("LTE"), $1, $3, nullptr); }
                    | operand GTE operand { $$ = new OperandNode(new string("GTE"), $1, $3, nullptr); }
                    | operand SL operand { $$ = new OperandNode(new string("SL"), $1, $3, nullptr); }
                    | operand SR operand { $$ = new OperandNode(new string("SR"), $1, $3, nullptr); }
                    | operand PLUS operand { $$ = new OperandNode(new string("PLUS"), $1, $3, nullptr); }
                    | operand MINUS operand { $$ = new OperandNode(new string("MINUS"), $1, $3, nullptr); }
                    | operand MULT operand { $$ = new OperandNode(new string("MULT"), $1, $3, nullptr); }
                    | operand DIV operand { $$ = new OperandNode(new string("DIV"), $1, $3, nullptr); }
                    | operand MOD operand { $$ = new OperandNode(new string("MOD"), $1, $3, nullptr); }
                    | prefix LP operand RP { $$ = new OperandNode($1, $3, nullptr, nullptr); }
                    | LP operand RP { $$ = new OperandNode(nullptr, $2, nullptr, nullptr); }
                    | prefix single {  $$ = new OperandNode($1, nullptr, nullptr, $2); }
                    | single { $$ = new OperandNode(nullptr, nullptr, nullptr, $1);  }
                    ;
                    

prefix:             BNOT { $$ = new string("BNOT"); }
                    | LNOT  { $$ = new string("LNOT"); }
                    | MINUS { $$ = new string("MINUS"); }
                    ;

single:             var { $$ = new SingleNode($1); }
                    | call { $$ = new SingleNode($1); }
                    | INT { $$ = new SingleNode(new IntNode($1)); }
                    | FLOAT { $$ = new SingleNode(new FloatNode($1)); }
                    | CHAR { $$ = new SingleNode(new CharNode($1)); }
                    | TRUE { $$ = new SingleNode(new BoolNode($1)); }
                    | FALSE { $$ = new SingleNode(new BoolNode($1)); }
                    // overload multiple initialization fun, with different type (enum)
                    ;

call:               ID LP args RP {
                        $$ = new CallNode(new string($1), $3);
                    };

args:               %empty { $$ = nullptr; }
                    | argList { $$ = $1; } 
                    ;

argList:            argList COMMA expression {
                        $1->push_back($3);
                        $$ = $1;
                    }
                    | expression {
                        $$ = new vector<ExpressionNode*>();
                        $$->push_back($1);
                    }
                    ;    

%%

int main() { 
    yyparse();
    cout << "Program" << endl;
    for(auto p : *root) {
        p->printNode(1);
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
