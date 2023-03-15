#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
#include "hash.h"
#include "errors.h"
#include "list.h"
#include "stack_management.h"
extern int get_line_number(void);

// perfumaria minha pra imprimir o erro bonitinho na tela
const char* showType(int type)
{
    switch(type)
    {
    case INT_TYPE:
        return "int";
        break;
    case FLOAT_TYPE:
        return "float";
        break;
    case STRING_TYPE:
    case CHAR_TYPE:
        return "char";
        break;
    case BOOL_TYPE:
        return "bool";
        break;
    }
}

void printError(int error, char *nome, int tipo_orig)
{
    switch(error)
    {
    case ERR_UNDECLARED:
        printf("Erro: na linha %d, nome '%s' nao declarada.\n",get_line_number(),nome);
        exit(ERR_UNDECLARED);
        break;
    case ERR_DECLARED:
        printf("Erro: na linha %d, nome '%s' ja declarada com tipo '%s'.\n",get_line_number(),nome, showType(tipo_orig));
        exit(ERR_DECLARED); // ok
        break;
    case ERR_VARIABLE:
        printf("Erro: na linha %d, nome '%s' ja declarado como variavel.\n",get_line_number(),nome);
        exit(ERR_VARIABLE); // ok
        break;
    case ERR_ARRAY:
        printf("Erro: na linha %d, nome '%s' ja declarado como vetor.\n",get_line_number(),nome);
        exit(ERR_ARRAY); // ok
        break;
    case ERR_FUNCTION:
        printf("Erro: na linha %d, nome '%s' ja declarado como funcao.\n",get_line_number(),nome);
        exit(ERR_FUNCTION); // ok
        break;
    default:
        printf("Erro semantico!"); // fiz por via das dúvidas
        exit(1);
        break;
    }

}

void checkTableListDec(Stack* stack, LISTA_DEC* dec, valor_t novo_simbolo){
    HASH_ENT* tmp = search_stack(stack,novo_simbolo.value.token);
    LISTA_DEC* lista = busca_dec(dec,novo_simbolo);
    valor_t find;

    if(lista){
        LISTA* achou = busca(lista->lista,novo_simbolo);
        find = achou->valor_lexico;
        if(tmp || lista){
            if(tmp->valor_lexico.tipo != novo_simbolo.tipo || lista->tipo != novo_simbolo.tipo)
                printError(ERR_DECLARED, novo_simbolo.value.token, tmp->valor_lexico.tipo);
            if((tmp->valor_lexico.natureza == NAT_VARIABLE || find.natureza == NAT_VARIABLE) && ((novo_simbolo.natureza == NAT_ARRAY) || (novo_simbolo.natureza == NAT_FUNCTION)))
                printError(ERR_VARIABLE, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.natureza == NAT_ARRAY || find.natureza == NAT_ARRAY) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_FUNCTION)))
                printError(ERR_ARRAY, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.natureza == NAT_FUNCTION || find.natureza == NAT_FUNCTION) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_ARRAY)))
                printError(ERR_FUNCTION, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.tipo == CHAR_TYPE || lista->tipo == CHAR_TYPE) && (novo_simbolo.tipo == INT_TYPE))
                printError(ERR_CHAR_TO_INT, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.tipo == CHAR_TYPE || lista->tipo == CHAR_TYPE) && (novo_simbolo.tipo == FLOAT_TYPE))
                printError(ERR_CHAR_TO_FLOAT, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.tipo == CHAR_TYPE || lista->tipo == CHAR_TYPE) && (novo_simbolo.tipo == BOOL_TYPE))
                printError(ERR_CHAR_TO_BOOL, novo_simbolo.value.token,0);
            if(((tmp->valor_lexico.tipo == INT_TYPE || lista->tipo == INT_TYPE) || (tmp->valor_lexico.tipo == FLOAT_TYPE || lista->tipo == FLOAT_TYPE) || (tmp->valor_lexico.tipo == BOOL_TYPE || lista->tipo == BOOL_TYPE)) && (novo_simbolo.tipo == CHAR_TYPE))
                printError(ERR_X_TO_CHAR, novo_simbolo.value.token,0);
            if((tmp->valor_lexico.tipo == CHAR_TYPE || lista->tipo == CHAR_TYPE) && (novo_simbolo.natureza == NAT_ARRAY))
                printError(ERR_CHAR_VECTOR, novo_simbolo.value.token,0);
        }
    }
}

void checkTableListInUse(Stack* stack, LISTA_DEC* dec, valor_t novo_simbolo){
    HASH_ENT* tmp = search_stack(stack,novo_simbolo.value.token);
    LISTA_DEC* tmp_dec = busca_dec(dec,novo_simbolo);

    if(!tmp || !tmp_dec)
        printError(ERR_UNDECLARED,novo_simbolo.value.token,0);
    else
        checkTableListDec(stack,dec,novo_simbolo);
}

int get_result_type(int type_1, int type_2, int op_type)
{

    switch(op_type)
    {
    case AST_ATT:
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV: /* arithmetic operator */
        // primeiro tipo INT
        if(type_1 == INT_TYPE)
        {
            // segundo tipo INT
            if(type_2 == INT_TYPE || type_2 == BOOL_TYPE)
            {
                return INT_TYPE;
            }
            // second type REAL
            else if(type_2 == FLOAT_TYPE)
            {
                return FLOAT_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        // first type REAL
        else if(type_1 == FLOAT_TYPE)
        {
            // second type INT, REAL or CHAR
            if(type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == BOOL_TYPE)
            {
                return FLOAT_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else if(type_1 == BOOL_TYPE)
        {
            // second type INT ou REAL ou  BOOL
            if(type_2 == INT_TYPE)
            {
                return INT_TYPE;
            }
            else if(type_2 == FLOAT_TYPE)
            {
                return FLOAT_TYPE;
            }
            else if(type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else
        {
            type_error(type_1, type_2, op_type);
        }
        break;

    case AST_AND:
    case AST_OR:
        /* Boolean operator */
        // first type INT
        if(type_1 == INT_TYPE)
        {
            // second type INT or CHAR
            if(type_2 == INT_TYPE || type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
       /* // first type CHAR
        else if(type_1 == CHAR_TYPE)
        {
            // second type CHAR
            if(type_2 == CHAR_TYPE)
            {
                return CHAR_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }*/
        else if(type_1 == BOOL_TYPE)
        {
            // second type INT ou REAL ou  BOOL
            if(type_2 == INT_TYPE)
            {
                return INT_TYPE;
            }
            else if(type_2 == FLOAT_TYPE)
            {
                return FLOAT_TYPE;
            }
            else if(type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else
        {
            type_error(type_1, type_2, op_type);
        }
        break;

    /* Relational operator */
    case AST_L:
    case AST_G:
    case AST_EQ:
    case AST_GE:
    case AST_LE:
        // first type INT
        if(type_1 == INT_TYPE)
        {
            // second type INT, REAL or CHAR
            if(type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else if(type_1 == FLOAT_TYPE)
        {
            // second type INT, REAL or CHAR
            if(type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        // first type CHAR
        else if(type_1 == CHAR_TYPE)
        {
            // second type INT, REAL or CHAR
            if(type_2 == CHAR_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else if(type_1 == BOOL_TYPE)
        {
            // second type INT ou REAL ou  BOOL
            if(type_2 == INT_TYPE)
            {
                return BOOL_TYPE;
            }
            else if(type_2 == FLOAT_TYPE)
            {
                return BOOL_TYPE;
            }
            else if(type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else
        {
            type_error(type_1, type_2, op_type);
        }
        break;

    /* Equality operator */
    case AST_NOT:
        // first type INT
        if(type_1 == INT_TYPE)
        {
            // second type INT or CHAR
            if(type_2 == INT_TYPE )
            {
                return INT_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else if(type_1 == FLOAT_TYPE)
        {
            // second type REAL
            if(type_2 == FLOAT_TYPE)
            {
                return FLOAT_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        // first type CHAR
        else if(type_1 == CHAR_TYPE)
        {
            // second type INT or CHAR
            if(type_2 == CHAR_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else if(type_1 == BOOL_TYPE)
        {
            // second type INT ou REAL ou  BOOL
            if(type_2 == INT_TYPE)
            {
                return BOOL_TYPE;
            }
            else if(type_2 == FLOAT_TYPE)
            {
                return BOOL_TYPE;
            }
            else if(type_2 == BOOL_TYPE)
            {
                return BOOL_TYPE;
            }
            else
            {
                type_error(type_1, type_2, op_type);
            }
        }
        else
        {
            type_error(type_1, type_2, op_type);

        }
        break;
    /* ---------------------------------------------------------- */
    default: /* wrong choice case */
        fprintf(stderr, "Error in operator selection!\n");
        exit(1);
    }
}

void type_error(int type_1, int type_2, int op_type)  /* print type error */
{
    fprintf(stderr, "Type conflict between %s and %s using op type %s\n", showType(type_1), showType(type_2), showType(op_type));
    exit(1);
}

valor_t altera_natureza(valor_t valor_lexico,int nova_natureza){
	valor_lexico.natureza = nova_natureza;
	return valor_lexico;
}

valor_t altera_tamanho(valor_t valor_lexico, int tam)
{
    switch(valor_lexico.tipo)
    {
    case STRING_TYPE:
    case CHAR_TYPE:
    case BOOL_TYPE:
        valor_lexico.tamanho = 1*tam;
        break;
    case FLOAT_TYPE:
        valor_lexico.tamanho = 8*tam;
        break;
    case INT_TYPE:
        valor_lexico.tamanho = 4*tam;
    }

    return valor_lexico;
}

node_t* altera_datatype(node_t* no){
    switch(no->type)
    {
    case AST_LIT_INT:
        no->datatype = INT_TYPE;
        return no;
        break;
    case AST_LIT_FLOAT:
        no->datatype = FLOAT_TYPE;
        return no;
        break;
    case TK_PR_BOOL:
        no->datatype = BOOL_TYPE;
        return no;
        break;
    case TK_PR_CHAR:
        no->datatype = CHAR_TYPE;
        return no;
        break;
    }
}

node_t* _altera_tipo(node_t* no, valor_t tipo){

    switch(tipo.tipo)
    {
    case TK_PR_INT:
        printf("altera");
        no->datatype = INT_TYPE;
        break;
    case TK_PR_FLOAT:
        printf("altera");
        no->datatype = FLOAT_TYPE;
        break;
    case TK_PR_BOOL:
        //printf("altera");
        no->datatype = BOOL_TYPE;
        break;
    case TK_PR_CHAR:
        //printf("altera");
        no->datatype = CHAR_TYPE;
        break;
    }
    return no;
}

node_t* inf_tipo(node_t *no, node_t* op1, node_t* op2, int tipo_op){
    no->datatype = get_result_type(op1->datatype,op2->datatype,tipo_op);
    return no;
}

node_t* inf_tipo_lex(node_t *no, valor_t op1, node_t *op2, int tipo_op){
    no->datatype = get_result_type(op1.tipo,op2->datatype,tipo_op);
    return no;
}

valor_t altera_tipo(valor_t simbolo, valor_t tipo){
    switch(tipo.tipo){
    case TK_PR_INT:
        simbolo.tipo = INT_TYPE;
        break;
    case TK_PR_FLOAT:
        simbolo.tipo = FLOAT_TYPE;
        break;
    case TK_PR_BOOL:
        simbolo.tipo = BOOL_TYPE;
        break;
    case TK_PR_CHAR:
        simbolo.tipo = CHAR_TYPE;
        break;
    }

    return simbolo;
}

int recupera_tipo(valor_t s, Stack* stack, LISTA_DEC* listadec)
{
    HASH_ENT* achou_pilha = search_stack(stack,s.value.token);
    LISTA_DEC* lista_d = busca_dec(listadec,s);
    LISTA* achou_lista = busca(lista_d->lista,s);

    if(achou_pilha)
        return achou_pilha->valor_lexico.tipo;
    else if(lista_d)
    {
        if(achou_lista)
            return achou_lista->valor_lexico.tipo;
        else
            return 0;
    }
}
int recupera_tipo_t(node_t* no){
    return no->datatype;
}

LISTA_DEC* altera_tipo_dec(LISTA_DEC* dec, valor_t tipo)
{
    switch(tipo.tipo)
    {
    case TK_PR_INT:
        dec->tipo = INT_TYPE;
        break;
    case TK_PR_FLOAT:
        dec->tipo = FLOAT_TYPE;
        break;
    case TK_PR_BOOL:
        dec->tipo = BOOL_TYPE;
        break;
    case TK_PR_CHAR:
        dec->tipo = CHAR_TYPE;
        break;
    }
    dec->tipo = tipo.tipo;
    printf("alterou tipo");
    return dec;
}
