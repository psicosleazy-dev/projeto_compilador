#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
#include "hash.h"
#include "errors.h"

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
        return "string";
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
        printf("Erro: nome '%s' nao declarada.\n",nome);
        exit(ERR_UNDECLARED);
        break;
    case ERR_DECLARED:
        printf("Erro: nome '%s' ja declarada com tipo '%s'.\n",nome, showType(tipo_orig));
        exit(ERR_DECLARED); // ok
        break;
    case ERR_VARIABLE:
        printf("Erro: nome '%s' ja declarado como variavel.\n",nome);
        exit(ERR_VARIABLE); // ok
        break;
    case ERR_ARRAY:
        printf("Erro: nome '%s' ja declarado como vetor.\n",nome);
        exit(ERR_ARRAY); // ok
        break;
    case ERR_FUNCTION:
        printf("Erro: nome '%s' ja declarado como funcao.\n",nome);
        exit(ERR_FUNCTION); // ok
        break;
    default:
        printf("Erro semantico!"); // fiz por via das dúvidas
        exit(1);
        break;
    }

}

void checkTableDec(HASH_TABLE* table, valor_t novo_simbolo){
    HASH_ENT* tmp = ht_search(table, novo_simbolo.value.token);
    if(tmp){
        if(tmp->valor_lexico.tipo != novo_simbolo.tipo)
            printError(ERR_DECLARED, novo_simbolo.value.token, tmp->valor_lexico.tipo);
        if((tmp->valor_lexico.natureza == NAT_VARIABLE) && ((novo_simbolo.natureza == NAT_ARRAY) || (novo_simbolo.natureza == NAT_FUNCTION)))
            printError(ERR_VARIABLE, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.natureza == NAT_ARRAY) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_FUNCTION)))
            printError(ERR_ARRAY, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.natureza == NAT_FUNCTION) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_ARRAY)))
            printError(ERR_FUNCTION, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == INT_TYPE))
            printError(ERR_CHAR_TO_INT, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == FLOAT_TYPE))
            printError(ERR_CHAR_TO_FLOAT, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == BOOL_TYPE))
            printError(ERR_CHAR_TO_BOOL, novo_simbolo.value.token,0);
        if(((tmp->valor_lexico.tipo == INT_TYPE) || (tmp->valor_lexico.tipo == FLOAT_TYPE) || (tmp->valor_lexico.tipo == BOOL_TYPE)) && (novo_simbolo.tipo == CHAR_TYPE))
            printError(ERR_X_TO_CHAR, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.natureza == NAT_ARRAY))
            printError(ERR_CHAR_VECTOR, novo_simbolo.value.token,0);

    }
}


void checkTableInUse(HASH_TABLE *table, valor_t novo_simbolo){
    HASH_ENT* tmp = ht_search(table,novo_simbolo.value.token);

    if(!tmp)
        printError(ERR_UNDECLARED,novo_simbolo.value.token,0);
    else
	checkTableDec(table,novo_simbolo);
}

int get_result_type(int type_1, int type_2, int op_type)
{

    switch(op_type)
    {
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


int retorna_tipo(valor_t valor_lexico)
{
    switch(valor_lexico.tipo)
    {
    case TK_PR_INT:
        return INT_TYPE;
        break;
    case TK_PR_FLOAT:
        return FLOAT_TYPE;
        break;
    case TK_PR_BOOL:
        return BOOL_TYPE;
        break;
    case TK_PR_CHAR:
        return CHAR_TYPE;
        break;
    }
}

valor_t altera_natureza(valor_t valor_lexico,int nova_natureza){
	valor_lexico.natureza = nova_natureza;
	return valor_lexico;
}
