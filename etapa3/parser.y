%code requires{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
extern void* arvore;
}


/* Nomes: Lucas Brum e Arthur Oliveira */
%define parse.error verbose

%union{
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
%type<no> identificador
%type<no> declaracao_global
%type<no> declaracao_local
%type<no> lista_nomes_local
%type<no> lista_nomes_global
%type<no> lista_inteiros
%type<no> expressao
%type<no> prec_six
%type<no> prec_five
%type<no> prec_four
%type<no> prec_three
%type<no> argumentos
%type<no> chamada_funcao
%type<no> args
%type<no> operando
%type<no> comandos_simples
%type<no> atribuicao
%type<no> comando_simples
%type<no> retorno
%type<no> if
%type<no> else
%type<no> while
%type<no> prec_zero
%type<no> TK_LIT_INT
%type<no> TK_LIT_FLOAT
%type<no> TK_LIT_TRUE
%type<no> TK_LIT_FALSE
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
%token TK_LIT_CHAR
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_IDENTIFICADOR
%token TK_ERRO
%start programa
%%
programa: lista {arvore = (void*)$$; $$ = $1;}
	| {arvore = (void*)$$; $$ = NULL;};
lista: funcao {$$ = $1;}
	| declaracao_global {$$ = $1;}
	| funcao lista {$$ = $1; add_child($1,$2);}
	| declaracao_global lista {$$ = $1; add_child($$,$2);};
declaracao_global: tipo lista_nomes_global ';' {$$ = $2;};
declaracao_local: tipo lista_nomes_local {$$ = $2;};
identificador: TK_IDENTIFICADOR {char *id; id = strdup(yylval.valor_lexico.value.token); $$ = create_node(TK_IDENTIFICADOR,id,yylval.valor_lexico);};
lista_nomes_local: lista_nomes_local ',' identificador '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {node_t *new_node; new_node = calloc(1,sizeof(node_t)); $$ = create_node(AST_INIT,"<=",yylval.valor_lexico); add_child($$,$3); $8 = create_node(AST_LIT_INT,yylval.valor_lexico.value.token,yylval.valor_lexico); add_child($$,$8); new_node = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child(new_node,$3); add_child(new_node,$5);}
	| identificador '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {node_t *new_node; new_node = calloc(1,sizeof(node_t)); $$ = create_node(AST_INIT,"<=",yylval.valor_lexico); add_child($$,$1); add_child($$,$6); new_node = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child(new_node,$1); add_child(new_node,$3);}
	| identificador '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
        | lista_nomes_local ',' identificador '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child($$,$3); add_child($$,$5);};
lista_nomes_global: lista_nomes_global ',' identificador '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child($$,$3); add_child($$,$5);}
	| identificador '[' lista_inteiros ']' {$$ = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| lista_nomes_global ',' identificador {$$ = $3; add_child($$,$1);}
	| identificador {$$ = $1;};
lista_inteiros: lista_inteiros '^' TK_LIT_INT {$$ = create_node(AST_CIRC, "^",yylval.valor_lexico); $3 = create_node(AST_LIT_INT,yylval.valor_lexico.value.token,yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}| TK_LIT_INT {$$ = create_node(AST_LIT_INT,yylval.valor_lexico.value.token,yylval.valor_lexico);};
expressao: expressao TK_OC_OR prec_six {$$ = create_node(AST_OR, "||",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_six {$$ = $1;};
prec_six: prec_six TK_OC_AND prec_five {$$ = create_node(AST_AND, "&&",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_five {$$ = $1;};
prec_five: prec_five TK_OC_EQ prec_four {$$ = create_node(AST_EQ, "==",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_five TK_OC_NE prec_four {$$ = create_node(AST_NE, "!=",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_four {$$ = $1;};
prec_four: prec_four '>' prec_three {$$ = create_node(AST_G, ">",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_four '<' prec_three {$$ = create_node(AST_L, "<",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_LE prec_three {$$ = create_node(AST_LE, "<=",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_GE prec_three {$$ = create_node(AST_GE, ">=",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_three {$$ = $1;};
prec_three: prec_three '+' prec_two {$$ = create_node(AST_ADD, "+",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_three '-' prec_two {$$ = create_node(AST_SUB, "-",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_two {$$ = $1;};
prec_two: prec_two '*' prec_one {$$ = create_node(AST_MUL, "*",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_two '/' prec_one {$$ = create_node(AST_DIV, "/",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_two '%' prec_one {$$ = create_node(AST_MOD, "%",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| prec_one {$$ = $1;};
prec_one: '!' prec_one {$$ = create_node(AST_NOT, "!",yylval.valor_lexico); add_child($$,$2);}
	| '-' prec_one {$$ = create_node(AST_MINUS, "-",yylval.valor_lexico); add_child($$,$2);}
	| prec_zero {$$ = $1;};
prec_zero: '(' expressao ')' {$$ = $2;}
	| operando {$$ = $1;};
expressoes: expressoes '^' expressao {$$ = create_node(AST_CIRC,"^",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| expressao {$$ = $1;};
argumentos: argumentos ',' expressao {$$ = $3;}
	| expressao {$$ = $1;};
args: argumentos {$$ = $1;}
	| {$$ = NULL;};
chamada_funcao: identificador '(' args ')' {char label[100] = "call ", *nome_fun; nome_fun = strdup(yylval.valor_lexico.value.token); strcat(label,nome_fun); $$ = create_node(AST_CALL,label,yylval.valor_lexico); add_child($$,$3); };
operando: identificador '[' expressoes ']' {$$ = create_node(AST_INDEX,"[]",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);}
	| identificador {$$ = $1;}
	| TK_LIT_INT {$$ = create_node(AST_LIT_INT,yylval.valor_lexico.value.token,yylval.valor_lexico);}
	| TK_LIT_FLOAT {$$ = create_node(AST_LIT_FLOAT,yylval.valor_lexico.value.token,yylval.valor_lexico);}
	| TK_LIT_FALSE {$$ = create_node(AST_LIT_FALSE,yylval.valor_lexico.value.token,yylval.valor_lexico);}
	| TK_LIT_TRUE {$$ = create_node(AST_LIT_TRUE,yylval.valor_lexico.value.token,yylval.valor_lexico);}
	| chamada_funcao {$$ = $1;}; 
tipo: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR;
funcao: tipo identificador '(' parametros ')' bloco {$$ = create_node(AST_FUNC,yylval.valor_lexico.value.token,yylval.valor_lexico); add_child($$,$6);};
bloco: '{' comandos_simples '}' {$$ = $2;} 
	| '{' '}' {$$ = NULL;};
parametros: parametros ',' tipo identificador
	| tipo identificador;
atribuicao: identificador '[' expressoes ']' '=' expressao {node_t *new_node; new_node = calloc(1,sizeof(node_t)); $$ = create_node(AST_ATT,"=",yylval.valor_lexico); add_child($$,$1); add_child($$,$6); new_node = create_node(AST_ARR,"[]",yylval.valor_lexico); add_child(new_node,$3); add_child($$,new_node);}
	| identificador '=' expressao {$$ = create_node(AST_ATT, "=",yylval.valor_lexico); add_child($$,$1); add_child($$,$3);};
comandos_simples: comando_simples ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| comando_simples ';' {$$ = $1;};
comando_simples: declaracao_local {$$ = $1;}
	| bloco {$$ = NULL;}
	| chamada_funcao {$$ = $1;}
	| atribuicao {$$ = $1;}
	| retorno {$$ = $1;}
	| if {$$ = $1;}
	| while {$$ = $1;};
retorno: TK_PR_RETURN expressao {$$ = create_node(AST_RET,"return",yylval.valor_lexico); add_child($$,$2);};
if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco else {$$ = create_node(AST_IF,"if",yylval.valor_lexico); add_child($$,$3); add_child($$,$6); add_child($$,$7);};
else: TK_PR_ELSE bloco {$$ = $2;}
	| {$$ = NULL;};
while: TK_PR_WHILE '(' expressao ')' bloco {$$ = create_node(AST_WHILE,"while",yylval.valor_lexico); add_child($$,$3); add_child($$,$5);};
%%
void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}
