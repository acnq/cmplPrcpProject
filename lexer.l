%{
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "ASTNodes.hpp"
#include "parser.tab.h" 

static FILE* yyparse_file_ptr;
extern void yyerror(char* s);
%}

  /*定义状态,第一句有点意义不明*/
%option yylineno 
%x C_COMMENT 

 /*空白符*/
macro  #.*  
whitespace [ \t\r\n]+ 
linecomment \/\/.*

 /*关键字*/
int  [\-]?[0-9]+  
float [\-]?[0-9]+\.[0-9]*
identifier [a-zA-Z_][a-zA-Z0-9_]*
char  \'.\'
true  true|True|TRUE
false false|False|FALSE 

%%
 /*关键字*/
"if"        return IF;
"else"      return ELSE;
"return"    return RETURN;
"for"       return FOR;
"while"     return WHILE;


 /*类型名称*/
"int"  {
    strcpy(yylval.type_id, yytext);
    return INT_TYPE;
}
"double" {
    strcpy(yylval.type_id, yytext);
    return DOUBLE_TYPE;
}
"float" {
    strcpy(yylval.type_id, yytext);
    return FLOAT_TYPE;
}
"char" {
    strcpy(yylval.type_id, yytext);
    return CHAR_TYPE;
}
"bool" {
    strcpy(yylval.type_id, yytext);
    return BOOL_TYPE;
}
"void" {
    strcpy(yylval.type_id, yytext);
    return VOID_TYPE;
}
"extern" {
    strcpy(yylval.type_id, yytext);
    return EXTERN_TYPE;
}

 /*正则符号*/
{int} { 
    yylval.type_int = atoi(yytext);
    return INT;
}

{float} {
    yylval.type_float = atof(yytext);
    return FLOAT;
}

{true} {
    yylval.type_bool = 1;
    return TRUE;
}

{false} {
    yylval.type_bool = 0;
    return FALSE;

}
  /*不知为何这里参考代码写的是[1]*/
{char} {
    yylval.type_char = yytext[1]; 
    return CHAR;
}

{identifier} {
    strcpy(yylval.type_id, yytext);
    return ID;
}

 /*特殊符号(按优先级), B for bitwise L for Logic*/
"="     return ASSIGN;
"+="    return PLUSASSIGN;
"-="    return MINUSASSIGN;
"*="    return MULTASSIGN;
"/="    return DIVASSIGN;
"%="    return MODASSIGN;
"|="    return BORASSIGN;
"&="    return BANDASSIGN;
"^="    return BXORASSIGN;
">>="   return SRASSIGN;
"<<="   return SLASSIGN;

"||"    return LOR;
"&&"    return LAND;

"|"     return BOR;
"&"     return BAND;
"^"     return BXOR;

">"     return GT;
"<"     return LT;
">="    return GTE;
"<="    return LTE;
"=="    return EQ;
"!="    return NEQ;

"<<"    return SL;
">>"    return SR;

"+"     return PLUS;
"-"     return MINUS;
"*"     return MULT;
"/"     return DIV;
"%"     return MOD;

"!"     return LNOT;
"~"     return BNOT;

"++"    return INCR;
"--"    return DECR;

"("     return LP;
")"     return RP;
"{"     return LC;
"}"     return RC;
"["     return LB;
"]"     return RB;

","     return COMMA;
";"     return SEMICOLON;


 /*空白符*/
{linecomment} {}

{whitespace} {}

{macro} {}
 
 /*C语言注释处理*/
"/*" BEGIN(C_COMMENT);
<C_COMMENT>"*/" BEGIN(INITIAL);
<C_COMMENT>.  {}

 /*未知符号*/
. yyerror("invalid character\n");

%%

int yywrap(void) {
    return 1;
}

 