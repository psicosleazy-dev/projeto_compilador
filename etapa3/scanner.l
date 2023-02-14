/* Nomes: Lucas Brum e Arthur Oliveira*/
%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
extern void *arvore;
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
%option nounput
%option noinput
%%
{white} {}
[/\*[\s\S]*?\*/] {	
	int i = 0;
	while(yytext[i] != '\0')
		if(yytext[i] == '\n') 
			count_line++;
	i++;
}
[/][/]+.* {}
[,;:(){}+\-*/%<>=!] return yytext[0];
\[ return yytext[0];
\] return yytext[0];
\^ return yytext[0];
\'([^\']?)\' return TK_LIT_CHAR;
{integer} {yylval.valor_lexico.value.int_value = atoi(yytext); yylval.valor_lexico.type = strdup("literal int"); yylval.valor_lexico.line = get_line_number(); return TK_LIT_INT;}
{float} {yylval.valor_lexico.value.float_value = atof(yytext); yylval.valor_lexico.type = strdup("literal float"); yylval.valor_lexico.line = get_line_number(); return TK_LIT_FLOAT;}
"int" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_INT;}
"float" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_FLOAT;}
"bool" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_BOOL;}
"char" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_CHAR;}
"if" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_IF;}
"then" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_THEN;}
"else" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_ELSE;}
"while" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_WHILE;}
"input" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_INPUT;}
"output" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_OUTPUT;}
"return" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_RETURN;}
"for" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_PR_FOR;}
"true" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_LIT_TRUE;}
"false" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("palavra reservada"); yylval.valor_lexico.line = get_line_number(); return TK_LIT_FALSE;}
"<=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_LE;}
">=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_GE;}
"==" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_EQ;}
"!=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_NE;}
"&&" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_AND;}
"||" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("operador composto"); yylval.valor_lexico.line = get_line_number(); return TK_OC_OR;}
{id} {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.type = strdup("id"); yylval.valor_lexico.line = get_line_number(); return TK_IDENTIFICADOR;}
[\n] count_line++;
. return TK_ERRO;
%%

/* opcional para codigo */
/* yyleng (unsigned long int - lu) = tamanho do token lido no scanner */
/* yylineno - variavel que conta linhas do programa de entrada */
