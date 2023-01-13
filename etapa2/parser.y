%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
%}
/* Nomes: Lucas Brum e Arthur Oliveira */
%define parser.error detailed
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_FOR
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_IDENTIFICADOR
%token TK_ERRO
%start programa

%%

programa: 
	| lista;
lista: funcao
	| variaveis_globais
	| lista funcao
	| lista declaracao_global;
declaracao_global: tipo lista_nomes_global ';';
init_variavel_local: '<' '=' TK_LIT_INT | ;
declaracao_local: tipo lista_nomes_local ';';
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR arranjo init_variavel_local
	| TK_IDENTIFICADOR arranjo init_variavel_local;
lista_nomes_global: lista_nomes_global ',' TK_IDENTIFICADOR arranjo
	| TK_IDENTIFICADOR arranjo ';';
arranjo: '[' lista_inteiros ']'
	| ;
lista_inteiros: lista_inteiros '^' TK_LIT_INT | TK_LIT_INT;
indice: '[' expressao ']'
	| ;

expressao: expressao TK_OC_OR prec_six
	| prec_six;
prec_six: prec_six TK_OC_AND prec_five
	| prec_five;
prec_five: prec_five TK_OC_EQ prec_four
	| prec_five TK_OC_NE prec_four
	| prec_four;
prec_four: prec_four '>' prec_three
	| prec_four '<' prec_three
	| prec_four TK_OC_LE prec_three
	| prec_four TK_OC_GE prec_three
	| prec_three;
prec_three: prec_three '+' prec_two
	| prec_three '-' prec_two
	| prec_two;
prec_two: prec_two '*' prec_one
	| prec_two '/' prec_one
	| prec_two '%' prec_one
	| prec_one;
prec_one: '!' prec_zero
	| '-' prec_zero
	| operando
	| prec_zero;
prec_zero: '(' prec_zero ')'
	| expressao;
	
expressoes: expressao '^' expressoes
	| expressao;
argumentos: expressao ',' argumentos
	| expressao;
chamada_funcao: TK_IDENTIFICADOR '(' argumentos ')';
operando: TK_IDENTIFICADOR indice
	| TK_IDENTIFICADOR '[' expressoes ']'
	| TK_LIT_INT
	| TK_LIT_FLOAT
	| TK_LIT_FALSE
	| TK_LIT_TRUE
	| chamada_funcao;
tipo: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR;
funcoes: funcoes funcao
	| funcao;
funcao: tipo TK_IDENTIFICADOR '(' argumentos ')' bloco;
bloco: '{' comandos_simples '}';
comandos_simples: comandos_simples ';' comando_simples 
	| comando_simples;
comando_simples: declaracao_local
	| atribuicao
	| retorno
	| if
	| while;
retorno: TK_PR_RETURN expressao;
atribuicao: TK_IDENTIFICADOR indice '=' expressao;

%%
void yyerror (char const *s){
	fprintf(stderr, "Syntax error: %s\n in line %d",s,get_line_number());
}
