%{
int yylex(void);
void yyerror (char const *s);
%}

/* Nomes: Lucas Brum e Arthur Oliveira */
%define parse.error verbose
%code requires {
#include "stack_management.h"
extern Stack* stack;
extern LISTA* lista;
extern int get_line_number();
extern void* arvore;
}

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
//%type<no> nomes_local
//%type<no> nomes_global
%type<no> lista_nomes_global
%type<no> lista_nomes_local
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
%type<valor_lexico> tipo
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_CHAR
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_CHAR
%token TK_ERRO
%start programa
%%
programa: lista {arvore = (void*)$$; $$ = $1;}
	| {arvore = (void*)$$; $$ = NULL;};
lista: funcao {$$ = $1;}
	| funcao lista {$$ = $1; add_child($1,$2);}
	| declaracao_global ';' {$$ = $1;}
	| declaracao_global ';' lista {$$ = $1; add_child($$,$3);};
funcao: tipo TK_IDENTIFICADOR '(' parametros ')' bloco { // adicionar na tabela o label da funcao funcao: header body
	char* leaf;
	leaf = create_leaf($2);
	$$ = create_node(AST_FUNC,leaf);
	add_child($$,$6);
	$2 = altera_natureza($2,NAT_FUNCTION);
	$2 = altera_tipo($2,$1);
	checkTableDec(stack,$2);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$2);
	push(stack,table);
	// vamos gerar codigo
	char* label_da_funcao;
	label_da_funcao = retorna_label(stack,$1.value.token);
	LISTA_ILOCS* l;
	ILOC inst;
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_da_funcao,inst);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,$6->code);
	$$->code = l;
	};
tipo: TK_PR_INT {lista = NULL;}
	| TK_PR_FLOAT {lista = NULL;}
	| TK_PR_BOOL {lista = NULL;}
	| TK_PR_CHAR {lista = NULL;};
declaracao_global: tipo lista_nomes_global {altera_tipo_na_lista(lista,$1); insere_lista_na_tabela(lista,stack); $$ = $2;};
declaracao_local: tipo lista_nomes_local {altera_tipo_na_lista(lista,$1); insere_lista_na_tabela(lista,stack); $$ = $2;};
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {
	node_t *new_node;
	$$ = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf($3);
	node_t* new_node2;
	new_node2 = create_node(AST_ID,leaf);
	add_child($$,new_node2);
	add_child($$,$1);
	add_child($$,$5);
	leaf = create_leaf($8);
	node_t* new_node3;
	new_node3 = create_node(AST_LIT_INT,leaf);
	add_child($$,new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,$5);
	add_child($$,new_node);
	$3 = altera_natureza($3,NAT_ARRAY);
	insere(lista,$3);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' TK_OC_LE TK_LIT_INT {
	node_t *new_node;
	$$ = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf($1);
	node_t* new_node2;
	new_node2 = create_node(AST_ID,leaf);
	add_child($$,new_node2);
	leaf = create_leaf($6);
	node_t* new_node3;
	new_node3 = create_node(AST_LIT_INT,leaf);
	add_child($$,new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,$3);
	add_child($$,new_node);
	$1 = altera_natureza($1,NAT_ARRAY);
	insere(lista,$1);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$3);
	HASH_TABLE *table;
	table = pop(stack);
	$1 = altera_natureza($1,NAT_ARRAY);
	insere(lista,$1);}
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
	insere(lista,$1);}
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
	$3 = altera_natureza($3,NAT_VARIABLE);
	insere(lista,$3);}
	| TK_IDENTIFICADOR {$1 = altera_natureza($1,NAT_VARIABLE);
	insere(lista,$1);}
	| lista_nomes_local ',' TK_IDENTIFICADOR {$$ = $1; $3 = altera_natureza($3,NAT_VARIABLE);
	insere(lista,$3);}
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
		insere(lista,$3);};
lista_nomes_global: lista_nomes_global ',' TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($3);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$5);
	add_child($$,$1);
	$3 = altera_natureza($3,NAT_ARRAY);
	insere(lista,$3);}
	| TK_IDENTIFICADOR '[' lista_inteiros ']' {
	$$ = create_node(AST_ARR,"[]");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node); 
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_ARRAY);
	insere(lista,$1);}
	| lista_nomes_global ',' TK_IDENTIFICADOR {$$ = $1;
	$3 = altera_natureza($3,NAT_VARIABLE);
	insere(lista,$3);}
	| TK_IDENTIFICADOR {$$ = NULL;
	$1 = altera_natureza($1,NAT_VARIABLE);
	insere(lista,$1);};
lista_inteiros: lista_inteiros '^' TK_LIT_INT {
	$$ = create_node(AST_CIRC, "^"); 
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($3);
	new_node = create_node(AST_LIT_INT,leaf);
	add_child($$,$1);
	add_child($$,new_node);
	$3 = altera_natureza($3,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$3);
	push(stack,table);}
	| TK_LIT_INT {
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_INT,leaf);
	$1 = altera_natureza($1,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$1);
	push(stack,table);};
expressao: expressao TK_OC_OR prec_six {$$ = create_node(AST_OR, "||");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_OR);
$$->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
inst = gera_inst(ILOC_OR,"or",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;
}
	| prec_six {$$ = $1;};
prec_six: prec_six TK_OC_AND prec_five {$$ = create_node(AST_AND, "&&");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_AND);
$$->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
inst = gera_inst(ILOC_AND,"and",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;
}
	| prec_five {$$ = $1;};
prec_five: prec_five TK_OC_EQ prec_four {$$ = create_node(AST_EQ, "==");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_EQ);
$$->temp = strdup(gera_temp());
char *label_true = strdup(gera_rotulo());
char *label_false = strdup(gera_rotulo());
char *next = strdup(gera_rotulo());
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_EQ",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;
}
	| prec_five TK_OC_NE prec_four {$$ = create_node(AST_NE, "!=");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_NE);
	$$->temp = gera_temp();
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	char *next = gera_rotulo();
	LISTA_ILOCS *l = NULL;
	ILOC inst = gera_inst(ILOC_LE,"cmp_NE",$1->temp,$3->temp,$$->temp);
	insere_lista_ilocs(&l,inst);
	ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
	insere_lista_ilocs(&l,inst2);
	ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
	inst3 = gera_inst_com_label(label_true,inst3);
	insere_lista_ilocs(&l,inst3);
	ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
	insere_lista_ilocs(&l,inst4);
	ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
	inst5 = gera_inst_com_label(label_false,inst5);
	insere_lista_ilocs(&l,inst5);
	ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst6 = gera_inst_com_label(next,inst6);
	insere_lista_ilocs(&l,inst6);
	LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
	code_1 = $1->code;
	code_3 = $3->code;
	code_1 = concat_lista_ilocs(code_1,code_3);
	code_1 = concat_lista_ilocs(code_1,l);
	$$->code = code_1;
	}
	| prec_four {$$ = $1;};
prec_four: prec_four '>' prec_three {$$ = create_node(AST_G, ">");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_G);
$$->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_GT",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;}
	| prec_four '<' prec_three {$$ = create_node(AST_L, "<");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_L);
	$$->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_LT",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;}
	| prec_four TK_OC_LE prec_three {$$ = create_node(AST_LE, "<=");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_LE);
	$$->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_LE",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;}
	| prec_four TK_OC_GE prec_three {$$ = create_node(AST_GE, ">=");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_GE);
	$$->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_GE",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",$$->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,$$->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,$$->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;}
	| prec_three {$$ = $1;};
prec_three: prec_three '+' prec_two {$$ = create_node(AST_ADD, "+");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_ADD);
$$->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if($3->type == INT_TYPE)
    inst = gera_inst(ILOC_ADDI,"addI",$1->temp,$3->temp,$$->temp);
else
    inst = gera_inst(ILOC_ADD,"add",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;
}
	| prec_three '-' prec_two {$$ = create_node(AST_SUB, "-");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_SUB);
	$$->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if($3->type == INT_TYPE)
    inst = gera_inst(ILOC_SUBI,"subI",$1->temp,$3->temp,$$->temp);
else
    inst = gera_inst(ILOC_SUB,"sub",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;}
	| prec_two {$$ = $1;};
prec_two: prec_two '*' prec_one {$$ = create_node(AST_MUL, "*");
add_child($$,$1);
add_child($$,$3);
$$ = inf_tipo($$,$1,$3,AST_MUL);
$$->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if($3->type == INT_TYPE)
    inst = gera_inst(ILOC_MULTI,"multI",$1->temp,$3->temp,$$->temp);
else
    inst = gera_inst(ILOC_MULT,"mult",$1->temp,$3->temp,$$->temp);
insere_lista_ilocs(&l,inst);
code_1 = $1->code;
code_3 = $3->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
$$->code = code_1;
}
	| prec_two '/' prec_one {$$ = create_node(AST_DIV, "/");
	add_child($$,$1);
	add_child($$,$3);
	$$ = inf_tipo($$,$1,$3,AST_DIV);
	$$->temp = gera_temp();
	LISTA_ILOCS *l = NULL, *code_1, *code_3;
	ILOC inst;
	if($3->type == INT_TYPE)
		inst = gera_inst(ILOC_ADDI,"divI",$1->temp,$3->temp,$$->temp);
	else
		inst = gera_inst(ILOC_ADDI,"div",$1->temp,$3->temp,$$->temp);
	insere_lista_ilocs(&l,inst);
	code_1 = $1->code;
	code_3 = $3->code;
	code_1 = concat_lista_ilocs(code_1,code_3);
	code_1 = concat_lista_ilocs(code_1,l);
	$$->code = code_1;}
	| prec_two '%' prec_one {$$ = create_node(AST_MOD, "%"); add_child($$,$1); add_child($$,$3); $$ = inf_tipo($$,$1,$3,AST_MOD);}
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
// falta gerar codigo aqui
chamada_funcao: TK_IDENTIFICADOR '(' args ')' {
	char label[100] = "call ", *nome_fun;
	nome_fun = strdup(create_leaf($1));
	strcat(label,nome_fun);
	$$ = create_node(AST_CALL,label);
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_FUNCTION);
	checkTableInUse(stack,$1);
};
//
operando: TK_IDENTIFICADOR '[' expressoes ']' {
$$ = create_node(AST_INDEX,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf); add_child($$,new_node); add_child($$,$3);
	checkTableInUse(stack,$1);
	int tipo = retorna_tipo_simbolo($1,stack);
	$$ = altera_tipo_no($$,tipo);}
	| TK_IDENTIFICADOR {
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_ID,leaf);
	$1 = altera_natureza($1,NAT_VARIABLE);
	checkTableInUse(stack,$1);
	int tipo = retorna_tipo_simbolo($1,stack);
	$$ = altera_tipo_no($$,tipo);
    // obter o endereço da tabela de simbolos
    // em qual tabela/escopo foi declarado
    // gera um temporario
    // if tabela global
    //   gera loadAI rbss, endereco_desloca => temporario
    // else
    //   gera loadAI rfp, endereco_desloca => temporario
    // coloca essa instrucao na AST em $$
    /*$$->temp = strdup(gera_temp());
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", retorna_end_desloc());
	if(escopo_global(stack,$1))
	   inst = gera_inst(ILOC_LOADAI,"loadAI","rbss",buf,$$->temp);
	else
	   inst = gera_inst(ILOC_LOADAI,"loadAI","rfp",buf,$$->temp);
	insere_lista_ilocs(&l,inst);
	$$->code = l;
	*/}
	| TK_LIT_INT {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_INT,leaf);
	$$ = altera_datatype($$);
	$1 = altera_natureza($1,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$1);
	push(stack,table);
	$$->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf,"%d",$1.value.int_value);
	inst = gera_inst(ILOC_LOADI,"loadI",buf,"null",$$->temp);
	insere_lista_ilocs(&l,inst);
	$$->code = l;
	}
	| TK_LIT_FLOAT {
	char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_FLOAT,leaf);
	$$ = altera_datatype($$);
	$1 = altera_natureza($1,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$1);
	push(stack,table);}
	| TK_LIT_FALSE {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_FALSE,leaf);
	$$ = altera_datatype($$);
	$1 = altera_natureza($1,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$1);
	push(stack,table);
	$$->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf,"%d",$1.value.int_value);
	inst = gera_inst(ILOC_LOADI,"loadI",buf,"null",$$->temp);
	insere_lista_ilocs(&l,inst);
	$$->code = l;
	}
	| TK_LIT_TRUE {char* leaf;
	leaf = create_leaf($1);
	$$ = create_node(AST_LIT_TRUE,leaf);
	$$ = altera_datatype($$);
	$1 = altera_natureza($1,NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$1);
	push(stack,table);
	$$->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", $1.value.int_value);
	inst = gera_inst(ILOC_LOADI,"loadI",buf,"null",$$->temp);
	insere_lista_ilocs(&l,inst);
	$$->code = l;}
	| chamada_funcao {$$ = $1;}; 
_empilha: {HASH_TABLE* table;
	table = create_table(HASH_SIZE);
	push(stack,table);}; // executada sempre que um novo escopo é criado
bloco: '{' _empilha comandos_simples '}' {$$ = $3;} 
	| '{' '}' {$$ = NULL;};
parametros: parametros ',' tipo TK_IDENTIFICADOR {$4 = altera_natureza($4,NAT_VARIABLE);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$4);
	push(stack,table);}
	| tipo TK_IDENTIFICADOR {$2 = altera_natureza($2,NAT_VARIABLE);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,$2);
	push(stack,table);}
	| ;
atribuicao: TK_IDENTIFICADOR '[' expressoes ']' '=' expressao {
node_t *new_node;
	$$ = create_node(AST_ATT,"=");
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$6);
	$1 = altera_natureza($1,NAT_ARRAY);
	checkTableInUse(stack,$1);
	int tipo = retorna_tipo_simbolo($1,stack);
	new_node = altera_tipo_no(new_node,tipo);
	$$ = inf_tipo($$,new_node,$6,AST_ATT);
	new_node = create_node(AST_ARR,"[]");
	add_child($$,$3);
	add_child($$,new_node);}
	| TK_IDENTIFICADOR '=' expressao {
	$$ = create_node(AST_ATT, "=");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf($1);
	new_node = create_node(AST_ID,leaf);
	add_child($$,new_node);
	add_child($$,$3);
	$1 = altera_natureza($1,NAT_VARIABLE);
	checkTableInUse(stack,$1);
	int tipo = retorna_tipo_simbolo($1,stack);
	new_node = altera_tipo_no(new_node,tipo);
	$$ = inf_tipo($$,new_node,$3,AST_ATT);
	$$->temp = strdup(gera_temp());
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", retorna_end_desloc(stack,$1));
	if(escopo_global(stack,$1))
	   inst = gera_inst(ILOC_ATT,"storeAI",$3->temp,"rbss",buf);
	else
	   inst = gera_inst(ILOC_ATT,"storeAI",$3->temp,"rfp",buf);
	insere_lista_ilocs(&l,inst);
	$$->code = l;
	};
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
// falta gerar codigo esses aqui tbm
retorno: TK_PR_RETURN expressao {
	$$ = create_node(AST_RET,"return");
	add_child($$,$2);
	$$->temp = gera_temp();
	LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_JUMP,"jump",NULL,NULL,$$->temp);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,$2->code);
	$$->code = l;
	};
if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco else {
	$$ = create_node(AST_IF,"if");
	add_child($$,$3);
	add_child($$,$6);
	add_child($$,$7);
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	char *next = gera_rotulo();
	$$->temp = gera_temp();
	char *opaco = gera_temp();
	LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_LOADI, "loadI","0","null",$$->temp);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_DIF,"cmp_NE",$3->temp,$$->temp,opaco);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_BR,"cbr",opaco,label_true,label_false);
	insere_lista_ilocs(&l,inst);
	/*organizar!!!!! inst2 = gera_inst_com_label(label_true,inst);
	inst = gera_inst(ILOC_LABEL,label_true,"nop");
	insere_lista_ilocs(&l,inst);
	*/
	inst = gera_inst(ILOC_JUMP,"jumpI","null","null",next);
	insere_lista_ilocs(&l,inst);
	// concatenar lista do else (reavaliar else!!!!)
	};
else: TK_PR_ELSE bloco {$$ = $2;}
	| {$$ = NULL;};
while: TK_PR_WHILE '(' expressao ')' bloco {
	$$ = create_node(AST_WHILE,"while");
	add_child($$,$3);
	add_child($$,$5);
	// tentar seguir a mesma logica da operacao relacional e do if pra traduzir
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	char *next = gera_rotulo();
	$$->temp = gera_temp();
	char *opaco = gera_temp();
    LISTA_ILOCS *l = NULL;
	ILOC inst;
	// gerar iloc com label label_verdade: nop (acho q pode ser label do proprio codigo)
	inst = gera_inst(ILOC_LOADI, "loadI","0",NULL,$$->temp);
	inst = gera_inst_com_label(label_true,inst);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_DIF,"cmp_NE",$3->temp,$$->temp,opaco);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_BR,"cbr",opaco,label_true,label_false);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,$5->code);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(next,inst);
	insere_lista_ilocs(&l,inst);
	
	};
%%
void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}

void initMe(){
	lista = NULL;
	stack = create_stack();
	HASH_TABLE *table = create_table(HASH_SIZE);
	push(stack,table); // tabela do escopo global
}
