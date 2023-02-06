%{
#include <stdio.h>
#include <string.h>
#include "ast.h"
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
extern void* arvore;
%}
/* Nomes: Lucas Brum e Arthur Oliveira */
%define parse.error verbose

%union{
 int int_value;
 float float_value;
 char c_value;
 node_t *no;
 valor_t valor_lexico;
}
%type<no> programa
%type<no> lista
%type<no> funcao
%type<no> prec_two
%type<no> prec_one
%type<no> expressoes
%type<no> bloco
%type<no> comma
%type<no> init_variavel_local
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
programa: lista {arvore = (void*)$$; $$ = $1}
	| {$$ = NULL;};
lista: funcao {$$ = $1}
	| declaracao_global {$$ = NULL;}
	| funcao lista {add_child($1,$2);}
	| lista declaracao_global {$$ = NULL;};
declaracao_global: tipo lista_nomes_global ';';
declaracao_local: tipo lista_nomes_local ';';
identificador: TK_IDENTIFICADOR {};
// arrumar
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR arranjo TK_OC_LE TK_LIT_INT {if($5 == NULL) {$$ = NULL;} else {$$ = create_node(AST_INIT,"<="); add_child($$,$3); add_child($$,$6)}}
	| TK_IDENTIFICADOR arranjo TK_OC_LE TK_LIT_INT {if($3 == NULL) {$$ = NULL;} else {/*$$ = create_leaf(AST_ID,$1);*/ $$ = create_node(AST_INIT,"<="); add_child($$,$1); add_child($$,$4)}}
	| TK_IDENTIFICADOR arranjo
        | lista_nomes_local ',' TK_IDENTIFICADOR arranjo;
/* */
// analisar melhor isso ??
lista_nomes_global: lista_nomes_global ',' TK_IDENTIFICADOR '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]"); add_child($$,$3); add_child($$,$5);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]"); add_child($$,$1); add_child($$,$3);}
	| lista_nomes_global ',' TK_IDENTIFICADOR 
	| TK_IDENTIFICADOR;
/* */
lista_inteiros: lista_inteiros '^' TK_LIT_INT | TK_LIT_INT;
expressao: expressao TK_OC_OR prec_six {$$ = create_node(AST_OR, "||"); add_child($$,$1); add_child($$,$3);}
	| prec_six {$$ = $1};
prec_six: prec_six TK_OC_AND prec_five {$$ = create_node(AST_AND, "&&"); add_child($$,$1); add_child($$,$3);}
	| prec_five {$$ = $1};
// DÚVIDA NO ITEM 2.3.5
prec_five: prec_five TK_OC_EQ prec_four {$$ = create_node(AST_EQ, "="); add_child($$,$1); add_child($$,$3);}
	| prec_five TK_OC_NE prec_four {$$ = create_node(AST_NE, "!="); add_child($$,$1); add_child($$,$3);}
	| prec_four {$$ = $1};
prec_four: prec_four '>' prec_three {$$ = create_node(AST_G, ">"); add_child($$,$1); add_child($$,$3);}
	| prec_four '<' prec_three {$$ = create_node(AST_L, "<"); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_LE prec_three {$$ = create_node(AST_LE, "<="); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_GE prec_three {$$ = create_node(AST_GE, ">="); add_child($$,$1); add_child($$,$3);}
	| prec_three {$$ = $1};
prec_three: prec_three '+' prec_two {$$ = create_node(AST_ADD, "+"); add_child($$,$1); add_child($$,$3);}
	| prec_three '-' prec_two {$$ = create_node(AST_SUB, "-"); add_child($$,$1); add_child($$,$3);}
	| prec_two {$$ = $2};
prec_two: prec_two '*' prec_one
	| prec_two '/' prec_one
	| prec_two '%' prec_one
	{$$ = create_node(AST_MOD, "%");
	add_child($$,$1);
	add_child($$,$3);}
	| prec_one;
prec_one: '!' prec_one {
	$$ = create_node(AST_NOT, "!");
	add_child($$,$2);}
	| '-' prec_one {
	$$ = create_node(AST_MINUS, "-");
	add_child($$,$2);}
	| prec_zero;
prec_zero: '(' expressao ')'
	| operando;
expressoes: expressoes '^' expressao {$$ = create_node(AST_CIRC,"^"); add_child($$,$1); add_child($$,$3);}
	| expressao {$$ = $1;};
argumentos: argumentos ',' expressao {$$ = $3;}
	| expressao {$$ = $1};
args: argumentos {$$ = $1;}
	| {$$ = NULL} ;
chamada_funcao: TK_IDENTIFICADOR '(' args ')' {char label[100] = "call "; strcat(label,create_leaf($1)); $$ = create_node(AST_CALL,label); add_child($$,$3); };
operando: TK_IDENTIFICADOR '[' expressoes ']' {
// modificar aqui O QUE E ESSE IF???
if ($2 == NULL){$$ = $1;}
else {$$ = create_node(AST_INDEX,"[]");
	add_child($$,$3); add_child($$,$5);}}
	| TK_LIT_INT
	| TK_LIT_FLOAT
	| TK_LIT_FALSE
	| TK_LIT_TRUE
	| chamada_funcao;
tipo: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR;
// arrumar aqui tambem
funcao: tipo TK_IDENTIFICADOR '(' params ')' bloco {$$ = create_node(AST_FUNC, nome funcao); add_child($$,$3);};
bloco: '{' comandos_simples '}' {$$ = $2} 
	| bloco_vazio {$$ = NULL};
bloco_vazio: '{''}';
parametros: parametros ',' tipo TK_IDENTIFICADOR 
	| tipo TK_IDENTIFICADOR;
params: parametros
	| ;
atribuicao: TK_IDENTIFICADOR indice '=' expressao {$$ = create_node(AST_ATT, "="); add_child($$,$1); add_child($$,$2); add_child($$,$4);};
comandos_simples: comando_simples ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| comando_simples {$$ = $1};
comando_simples: declaracao_local {$$ = $1}
	| bloco {$$ = NULL}
	| chamada_funcao {$$ = $1}
	| atribuicao {$$ = $1}
	| retorno {$$ = $1}
	| if {$$ = $1}
	| while {$$ = $1};
retorno: TK_PR_RETURN expressao {$$ = create_node(RETORNO, "return"); add_child($$,$2);};
if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco else {$$ = create_node(IF,"if"); add_child($$,$3); add_child($$,$6); add_child($$,$7);};
else: TK_PR_ELSE bloco {$$ = $2;}
	| {$$ = NULL};
while: TK_PR_WHILE '(' expressao ')' bloco {$$ = create_node(WHILE,"while"); add_child($$,$3); add_child($$,$5);};
%%
void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}
