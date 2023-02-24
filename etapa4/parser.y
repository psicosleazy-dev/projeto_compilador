%code requires{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
#include "errors.h"
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
extern void* arvore;
HASH_TABLE* table;
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
%type<no> retorno
%type<no> if
%type<no> else
%type<no> while
%type<no> prec_zero
%type<valor_lexico> TK_LIT_INT
%type<valor_lexico> TK_LIT_FLOAT
%type<valor_lexico> TK_LIT_TRUE
%type<valor_lexico> TK_LIT_FALSE
%type<valor_lexico> TK_IDENTIFICADOR
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
programa: lista {arvore = (void*)$$; $$ = $1; table = create_table(HASH_SIZE); /*criar pilha aqui tbm*/}
	| {arvore = (void*)$$; $$ = NULL;};
lista: funcao {$$ = $1;}
	| funcao lista {$$ = $1; add_child($1,$2);}
	| declaracao_global {$$ = $1;}
	| declaracao_global lista {$$ = $1; add_child($$,$2);};
declaracao_global: tipo lista_nomes_global ';' {$$ = $2;};
declaracao_local: tipo lista_nomes_local {$$ = $2; /* criar uma tabela */};
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {
	node_t *new_node;
	$$ = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf($3);
	node_t* new_node2;
	add_child($$,new_node2);
	add_child($$,$1);
	leaf = create_leaf($8);
	node_t* new_node3;
	add_child($$,new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,$5);
	add_child($$,new_node);
	$3 = altera_natureza($3,NAT_VARIABLE);
	checkTableDec(table,$3);
	insert_item(table,$3);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {
	node_t *new_node;
	$$ = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf($1);
	node_t *new_node2;
	add_child($$,new_node2);
	node_t *new_node3;
	leaf = create_leaf($6);
	add_child($$,new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,$3);
	add_child($$,new_node);
	$1 = altera_natureza($1,NAT_ARRAY);
	checkTableDec(table,$1);
	insert_item(table,$1);
}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_ARRAY);
	checkTableDec(table,$1);
	insert_item(table,$1);}
	| TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT {
	$$ = create_node(AST_INIT,"<=");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	node_t* new_node2;
	leaf = create_leaf($3);
	new_node2 = create_node(AST_LIT_INT,leaf);
	add_child($$,new_node2);
	$1 = altera_natureza($1,NAT_VARIABLE);
	checkTableDec(table,$1);
	insert_item(table,$1);}
	| lista_nomes_local ',' TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT {
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($3);
	$$ = create_node(AST_INIT,"<=");
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$1);
	node_t* new_node2;
	leaf = create_leaf($5);
	new_node2 = create_node(AST_LIT_INT,leaf);
	add_child($$,new_node2);
	add_child($$,$1);
	$3 = altera_natureza($3,NAT_VARIABLE);
	checkTableDec(table,$3);
	insert_item(table,$3);}
	| TK_IDENTIFICADOR {$$ = NULL; $1 = altera_natureza($1,NAT_VARIABLE);
	checkTableDec(table,$1);
	insert_item(table,$1);}
	| lista_nomes_local ',' TK_IDENTIFICADOR {$$ = $1; $3 = altera_natureza($3,NAT_VARIABLE);
	checkTableDec(table,$3);
	insert_item(table,$3);}
    | lista_nomes_local ',' TK_IDENTIFICADOR '[' lista_inteiros ']' {
		$$ = create_node(AST_ARR,"[]");
		node_t* new_node;
		char* leaf;
		leaf = create_leaf($3);
		new_node = create_node(AST_ID,leaf);
		add_child($$,new_node);
		add_child($$,$5);
		add_child($$,$1);
		$3 = altera_natureza($3,NAT_ARRAY);
		checkTableDec(table,$3);
		insert_item(table,$3);};
lista_nomes_global: lista_nomes_global ',' TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($3);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$5);
	add_child($$,$1);
	$3 = altera_natureza($3,NAT_VARIABLE);
	checkTableDec(table,$3);
	insert_item(table,$3);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node); 
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_ARRAY);
	checkTableDec(table,$1);
	insert_item(table,$1);}
	| lista_nomes_global ',' TK_IDENTIFICADOR {$$ = NULL; $3 = altera_natureza($3,NAT_VARIABLE); checkTableDec(table,$3); insert_item(table,$3);}
	| TK_IDENTIFICADOR {$$ = NULL; $1 = altera_natureza($1,NAT_VARIABLE); checkTableDec(table,$1); insert_item(table,$1);};
lista_inteiros: lista_inteiros '^' TK_LIT_INT {
	$$ = create_node(AST_CIRC, "^"); 
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($3);
	new_node = create_node(AST_LIT_INT,leaf);
	add_child($$,$1);
	add_child($$,new_node);
	$3 = altera_natureza($3,NAT_LITERAL);
	insert_item(table,$3);}
	| TK_LIT_INT {
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_INT,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	insert_item(table,$1);};
expressao: expressao TK_OC_OR prec_six {$$ = create_node(AST_OR, "||"); add_child($$,$1); add_child($$,$3);}
	| prec_six {$$ = $1;};
prec_six: prec_six TK_OC_AND prec_five {$$ = create_node(AST_AND, "&&"); add_child($$,$1); add_child($$,$3);}
	| prec_five {$$ = $1;};
prec_five: prec_five TK_OC_EQ prec_four {$$ = create_node(AST_EQ, "=="); add_child($$,$1); add_child($$,$3);}
	| prec_five TK_OC_NE prec_four {$$ = create_node(AST_NE, "!="); add_child($$,$1); add_child($$,$3);}
	| prec_four {$$ = $1;};
prec_four: prec_four '>' prec_three {$$ = create_node(AST_G, ">"); add_child($$,$1); add_child($$,$3);}
	| prec_four '<' prec_three {$$ = create_node(AST_L, "<"); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_LE prec_three {$$ = create_node(AST_LE, "<="); add_child($$,$1); add_child($$,$3);}
	| prec_four TK_OC_GE prec_three {$$ = create_node(AST_GE, ">="); add_child($$,$1); add_child($$,$3);}
	| prec_three {$$ = $1;};
prec_three: prec_three '+' prec_two {$$ = create_node(AST_ADD, "+"); add_child($$,$1); add_child($$,$3);}
	| prec_three '-' prec_two {$$ = create_node(AST_SUB, "-"); add_child($$,$1); add_child($$,$3);}
	| prec_two {$$ = $1;};
prec_two: prec_two '*' prec_one {$$ = create_node(AST_MUL, "*"); add_child($$,$1); add_child($$,$3);}
	| prec_two '/' prec_one {$$ = create_node(AST_DIV, "/"); add_child($$,$1); add_child($$,$3);}
	| prec_two '%' prec_one {$$ = create_node(AST_MOD, "%"); add_child($$,$1); add_child($$,$3);}
	| prec_one {$$ = $1;};
prec_one: '!' prec_one {$$ = create_node(AST_NOT, "!"); add_child($$,$2);}
	| '-' prec_one {$$ = create_node(AST_MINUS, "-"); add_child($$,$2);}
	| prec_zero {$$ = $1;};
prec_zero: '(' expressao ')' {$$ = $2;}
	| operando {$$ = $1;};
expressoes: expressao '^' expressoes {$$ = create_node(AST_CIRC,"^"); add_child($$,$1); add_child($$,$3);}
	| expressao {$$ = $1;};
argumentos: expressao ',' argumentos {$$ = $1; add_child($$,$3);}
	| expressao {$$ = $1;};
args: argumentos {$$ = $1;}
	| {$$ = NULL;};
chamada_funcao: TK_IDENTIFICADOR '(' args ')' {
	char label[100] = "call ", *nome_fun;
	nome_fun = strdup(create_leaf($1));
	strcat(label,nome_fun);
	$$ = create_node(AST_CALL,label);
	add_child($$,$3);
	checkTableInUse(table,$1);
};
operando: TK_IDENTIFICADOR '[' expressoes ']' {
$$ = create_node(AST_INDEX,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf); add_child($$,new_node); add_child($$,$3);
	checkTableInUse(table,$1);}
	| TK_IDENTIFICADOR {
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_ID,leaf);
	$1 = altera_natureza($1,NAT_VARIABLE);
	checkTableInUse(table,$1);
	}
	| TK_LIT_INT {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_INT,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	//table = create_table(HASH_SIZE);
	print_table(table);
	insert_item(table,$1);}
	| TK_LIT_FLOAT {
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_FLOAT,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	insert_item(table,$1);}
	| TK_LIT_FALSE {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_FALSE,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	insert_item(table,$1);}
	| TK_LIT_TRUE {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_TRUE,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	insert_item(table,$1);}
	| chamada_funcao {$$ = $1;}; 
tipo: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR;
funcao: tipo TK_IDENTIFICADOR '(' parametros ')' bloco {
	char* leaf;
	leaf = create_leaf($2);
	$$ = create_node(AST_FUNC,leaf);
	add_child($$,$6);
	$2 = altera_natureza($2,NAT_FUNCTION);
	checkTableDec(table,$2);
	insert_item(table,$2);
	};
bloco: '{' comandos_simples '}' {$$ = $2;/*criar tabela talvez*/} 
	| '{' '}' {$$ = NULL;};
parametros: parametros ',' tipo TK_IDENTIFICADOR {$4 = altera_natureza($4,NAT_VARIABLE);
	checkTableDec(table,$4);
	insert_item(table,$4);}
	| tipo TK_IDENTIFICADOR {$2 = altera_natureza($2,NAT_VARIABLE);
	checkTableDec(table,$2);
	insert_item(table,$2);}
	| ;
atribuicao: TK_IDENTIFICADOR '[' expressoes ']' '=' expressao {
node_t *new_node, *new_node2;
	$$ = create_node(AST_ATT,"=");
	char* leaf;
	leaf = create_leaf($1);
	add_child($$,new_node2);
	add_child($$,$6);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,$3);
	add_child($$,new_node);
	$1 = altera_natureza($1,NAT_ARRAY);
	checkTableInUse(table,$1);}
	| TK_IDENTIFICADOR '=' expressao {
	$$ = create_node(AST_ATT, "=");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_VARIABLE);
	checkTableInUse(table,$1);};
comandos_simples: declaracao_local ';' comandos_simples {if($1 == NULL) {$$ = $3;} else {$$ = $1; add_child($$,$3);}}
	| declaracao_local ';' {$$ = $1;}
	| bloco ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| bloco ';' {$$ = $1;}
	| chamada_funcao ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| chamada_funcao ';' {$$ = $1;}
	| atribuicao ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| atribuicao ';' {$$ = $1;}
	| retorno ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| retorno ';' {$$ = $1;}
	| if ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| if ';' {$$ = $1;}
	| while ';' comandos_simples {$$ = $1; add_child($$,$3);}
	| while ';' {$$ = $1;};
retorno: TK_PR_RETURN expressao {$$ = create_node(AST_RET,"return"); add_child($$,$2);};
if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco else {$$ = create_node(AST_IF,"if"); add_child($$,$3); add_child($$,$6); add_child($$,$7);};
else: TK_PR_ELSE bloco {$$ = $2;}
	| {$$ = NULL;};
while: TK_PR_WHILE '(' expressao ')' bloco {$$ = create_node(AST_WHILE,"while"); add_child($$,$3); add_child($$,$5);};
%%
void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}
