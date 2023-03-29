/* Nomes: Lucas Brum e Arthur Oliveira*/
%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
#include "errors.h"
extern void *arvore;
int count_line = 1;
int get_line_number(void){
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
\'([^\']?)\' {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = CHAR_TYPE; yylval.valor_lexico.linha = get_line_number(); return TK_LIT_CHAR;}
{integer} {yylval.valor_lexico.value.int_value = atoi(yytext); yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = INT_TYPE; yylval.valor_lexico.linha = get_line_number(); return TK_LIT_INT;}
{float} {yylval.valor_lexico.value.float_value = atof(yytext); yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = FLOAT_TYPE; yylval.valor_lexico.linha = get_line_number(); return TK_LIT_FLOAT;}
"int" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_INT; yylval.valor_lexico.linha = get_line_number(); return TK_PR_INT;}
"float" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_FLOAT; yylval.valor_lexico.linha = get_line_number(); return TK_PR_FLOAT;}
"bool" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_BOOL; yylval.valor_lexico.linha = get_line_number(); return TK_PR_BOOL;}
"char" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_CHAR; yylval.valor_lexico.linha = get_line_number(); return TK_PR_CHAR;}
"if" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_IF; yylval.valor_lexico.linha = get_line_number(); return TK_PR_IF;}
"then" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_THEN; yylval.valor_lexico.linha = get_line_number(); return TK_PR_THEN;}
"else" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_ELSE; yylval.valor_lexico.linha = get_line_number(); return TK_PR_ELSE;}
"while" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_WHILE; yylval.valor_lexico.linha = get_line_number(); return TK_PR_WHILE;}
"return" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_PR_RETURN; yylval.valor_lexico.linha = get_line_number(); return TK_PR_RETURN;}
"true" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.value.int_value = 1; yylval.valor_lexico.tipo = TK_LIT_TRUE; yylval.valor_lexico.linha = get_line_number(); return TK_LIT_TRUE;}
"false" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.value.int_value = 0; yylval.valor_lexico.tipo = TK_LIT_FALSE; yylval.valor_lexico.linha = get_line_number(); return TK_LIT_FALSE;}
"<=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_LE; yylval.valor_lexico.linha = get_line_number(); return TK_OC_LE;}
">=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_GE; yylval.valor_lexico.linha = get_line_number(); return TK_OC_GE;}
"==" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_EQ; yylval.valor_lexico.linha = get_line_number(); return TK_OC_EQ;}
"!=" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_NE; yylval.valor_lexico.linha = get_line_number(); return TK_OC_NE;}
"&&" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_AND; yylval.valor_lexico.linha = get_line_number(); return TK_OC_AND;}
"||" {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_OC_OR; yylval.valor_lexico.linha = get_line_number(); return TK_OC_OR;}
{id} {yylval.valor_lexico.value.token = strdup(yytext); yylval.valor_lexico.tipo = TK_IDENTIFICADOR; yylval.valor_lexico.linha = get_line_number(); return TK_IDENTIFICADOR;}
[\n] count_line++;
. return TK_ERRO;
%%

/* opcional para codigo */
/* yyleng (unsigned long int - lu) = tamanho do token lido no scanner */
/* yylineno - variavel que conta linhas do programa de entrada */
