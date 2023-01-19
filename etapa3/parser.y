%{
#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
extern void* arvore;
%}
/* Nomes: Lucas Brum e Arthur Oliveira */
%define parse.error verbose

%union{
 node_t *no;
 valor_t valor_lexico;
}
%type<no> indices
%type<no> prec_two
%type<no> prec_one
%type<no> expressoes
%type<no> bloco
%type<no> comma
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
%token<valor_lexico> TK_IDENTIFICADOR
%token TK_ERRO
%start programa

%%

programa: lista {arvore = (void*)$$; $$ = $1};
	| {$$ = NULL;};
lista: funcao
	| declaracao_global
	| lista funcao {$$ = create_node(FUNCAO,call yylval.valor_lexico.value); add_child($$,$1);}
	| lista declaracao_global;
declaracao_global: tipo lista_nomes_global ';';
init_variavel_local: TK_OC_LE TK_LIT_INT {$$ = $3; $3 = create_node(LITERAL, yylval.valor_lexico.value);}
	| {$$ = NULL; };
declaracao_local: tipo lista_nomes_local ';';
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR arranjo init_variavel_local {$$ = create_node(INICIALIZACAO,"<="); add_child($$,$3); add_child($$,$5)};
	| TK_IDENTIFICADOR arranjo init_variavel_local {$$ = create_leaf(IDENTIFICADOR,$1); {$$ = create_node(INICIALIZACAO,"<="); add_child($$,$1); add_child($$,$3)}};
lista_nomes_global: lista_nomes_global ',' TK_IDENTIFICADOR arranjo
	| TK_IDENTIFICADOR arranjo;
arranjo: '[' lista_inteiros ']'
	| ;
lista_inteiros: lista_inteiros '^' TK_LIT_INT | TK_LIT_INT;
indice: '[' expressoes ']' {$$ = create_node(INDEXADOR,"[]");
	add_child($$,$2);}
	| {$$ = NULL; };
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
	{$$ = create_node(RESTO, "%");
	add_child($$,$1);
	add_child($$,$3);}
	| prec_one;
prec_one: '!' prec_one {
	$$ = create_node(NEGACAO, "!");
	add_child($$,$2);}
	| '-' prec_one {
	$$ = create_node(MENOS_UNARIO, "-");
	add_child($$,$2);}
	| prec_zero;
prec_zero: '(' expressao ')'
	| operando;
expressoes: expressoes '^' expressao
	| expressao {$$ = $1;}
argumentos: argumentos ',' expressao
	| expressao;
args: argumentos
	| ;
chamada_funcao: TK_IDENTIFICADOR '(' args ')';
operando: TK_IDENTIFICADOR indice {
if ($2 == NULL){$$ = $1;}
else {$$ = $2
	add_child($$,$1);}}
	| TK_LIT_INT
	| TK_LIT_FLOAT
	| TK_LIT_FALSE
	| TK_LIT_TRUE
	| chamada_funcao;
tipo: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR;
funcao: tipo TK_IDENTIFICADOR '(' params ')' bloco;
bloco: '{' comma '}'{$$ = $2};
comma: comandos_simples
	| {$$ = NULL;};
parametros: parametros ',' tipo TK_IDENTIFICADOR 
	| tipo TK_IDENTIFICADOR;
params: parametros
	| ;
atribuicao: TK_IDENTIFICADOR indice '=' expressao;
comandos_simples: comandos_simples ';' comando_simples {$$ = $3; add_child($$,$1);}
	| comando_simples {$$ = $1};
comando_simples: declaracao_local
	| bloco
	| chamada_funcao
	| atribuicao
	| retorno
	| if {$$ = create_node(IF,"if");}
	| while {$$ = create_node(WHILE,"while");};
retorno: TK_PR_RETURN expressao;
if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco else;
else: TK_PR_ELSE bloco
	| ;
while: TK_PR_WHILE '(' expressao ')' bloco;
%%
void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}
