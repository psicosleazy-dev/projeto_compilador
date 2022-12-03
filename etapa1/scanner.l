/* Nomes: Lucas Brum e Arthur */

%{ 
#include<"tokens.h">
#include<stdio.h>
int count_line = 1;
int get_line_number(){
     return count_line;
}
%}

white [ \t\r]+
digit [0-9]
id [a-zA-Z]+
integer {digit}+
exponent [eE][+-]?{integer}
float {integer}["."]?{integer}+{exponent}?
%option noyywrap
%option yylineno
%%
{white} {}
\/\*(\*(?!\/)|[^*])*\*\/ {	
	int i = 0;
	while(yytext[i] != '\0' {
	if(yytext[i] == '\n') 
		count_line++;
	}
}
[/][/]+.* {}
[,;:(){}+-*/%^<>=!] return yytext[0];
\'([^\']?)\' return TK_LIT_CHAR;
{float} return TK_LIT_FLOAT;
{integer} return TK_LIT_INT;
{id} return TK_IDENTIFICADOR;
"int" return TK_PR_INT;
"float" return TK_PR_FLOAT;
"bool" return TK_PR_BOOL;
"char" return TK_PR_CHAR;
"if" return TK_PR_IF;
"then" return TK_PR_THEN;
"else" return TK_PR_ELSE;
"while" return TK_PR_WHILE;
"input" return TK_PR_INPUT;
"output" return TK_PR_OUTPUT;
"return" return TK_PR_RETURN;
"for" return TK_PR_FOR;
"true" return TK_LIT_TRUE;
"false" return TK_LIT_FALSE;
[\n] count_line++;
. return TK_ERRO;
%%

/* opcional para codigo */
/* yyleng (unsigned long int - lu) = tamanho do token lido no scanner */
/* yylineno - variavel que conta linhas do programa de entrada */

