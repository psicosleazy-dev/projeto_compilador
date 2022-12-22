%{
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
%}

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

%%

programa: 
	| variaveis_globais funcoes_
	| funcoes variaveis_globais_;
funcoes_: funcoes
	| ;
variaveis_globais_: variaveis_globais
	| ;
variaveis_globais: tipo lista_nomes_global ';';
init_variavel_local: '<' '=' TK_LIT_INT | ;
variaveis_locais: tipo lista_nomes_local ';';
lista_nomes_local: lista_nomes_local ',' TK_IDENTIFICADOR indice init_variavel_local
	| TK_IDENTIFICADOR indice init_variavel_local;
lista_nomes: lista_nomes_global ',' TK_IDENTIFICADOR indice
	| TK_IDENTIFICADOR indice;
indice: ':' expressao
	| ;
expressao: expressao '^' expressao
	| expressao
	| operando;
argumentos: expressao ',' expressao | expressao;
chamada_funcao: TK_IDENTIFICADOR '(' argumentos ')';
operando: TK_IDENTIFICADOR indice
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
funcao: tipo corpo;
retorno: TK_PR_RETURN expressao;
%%
void yyerror (char const *s){
	fprintf(stderr, "%s\n in line %d",s,get_line_number());
}
