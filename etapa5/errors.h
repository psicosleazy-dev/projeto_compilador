#ifndef ERROR_H
#define ERROR_H
#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_ARRAY 21 //2.3
#define ERR_FUNCTION 22 //2.3
#define ERR_CHAR_TO_INT 31 //2.4
#define ERR_CHAR_TO_FLOAT 32 //2.4
#define ERR_CHAR_TO_BOOL 33 //2.4
#define ERR_CHAR_VECTOR 34 //2.4
#define ERR_X_TO_CHAR 35 //2.4
#define NAT_LITERAL 36
#define NAT_VARIABLE 37
#define NAT_ARRAY 38
#define NAT_FUNCTION 39
#define INT_TYPE         90
#define BOOL_TYPE        91
#define FLOAT_TYPE       92
#define STRING_TYPE	     93
#define CHAR_TYPE	     94

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
#include "parser.tab.h"
#endif

const char* showType(int);
void printError(int,char*,int);
int get_result_type(int,int,int);
void type_error(int,int,int);
valor_t altera_tipo(valor_t,valor_t); // para declaracoes simples
valor_t altera_natureza(valor_t,int);
node_t* altera_datatype(node_t*); // para literais
valor_t altera_tamanho(valor_t);
node_t* inf_tipo(node_t*,node_t*,node_t*,int);
node_t* altera_tipo_no(node_t*,int); // para regras tipo lista
int recupera_tipo_t(node_t*); // para operandos do tipo arvore - expressao
node_t* inf_tipo_lex(node_t*,valor_t,node_t*,int);
void altera_tipo_na_lista(LISTA*,valor_t);
#endif
