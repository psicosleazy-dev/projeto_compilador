#ifndef _TACS_H_
#define _TACS_H_
#define ILOC_SYMBOL 333
#define ILOC_MOVE 334
#define ILOC_ADD 335
#define ILOC_SUB 336
#define ILOC_MULT 337
#define ILOC_DIV 338
#define ILOC_GREAT 339
#define ILOC_LESS 340
#define ILOC_GE 341
#define ILOC_LE 342
#define ILOC_EQ 343
#define ILOC_DIF 344
#define ILOC_AND 345
#define ILOC_OR 346
#define ILOC_NOT 347
#define ILOC_LABEL 348
#define ILOC_IF 349
#define ILOC_JUMP 350
#define ILOC_CALL 351
#define ILOC_ARG 352
#define ILOC_RET 353
#define ILOC_PARAMPOP 354
#define ILOC_ATT 355
#define ILOC_LOADAI 356
#define ILOC_LOADI 357
#define ILOC_BR 358
#define ILOC_ADDI 359
#define ILOC_DEC 360
#define ILOC_SUBI 361
#define ILOC_NOP 362

/*#define ILOC_ADD 2
#define ILOC_SUB 3
#define ILOC_MUL 4
#define ILOC_DIV 5
#define ILOC_GREAT 6
#define ILOC_LESS 7
#define ILOC_GE 8
#define ILOC_LE 9
#define ILOC_EQ 10
#define ILOC_DIF 11
#define ILOC_AND 12
#define ILOC_OR 13
#define ILOC_LABEL 15
#define ILOC_BEGINFUN 16
#define ILOC_ENDFUN 18
#define ILOC_IF 19
#define ILOC_JUMP 20
#define ILOC_CALL 21
#define ILOC_RET 23
#define ILOC_READ 25*/



#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "stack_management.h"

struct iloc{
    int tipo_iloc;
    char* label;
    char* op;
    char* op1;
    char* op2;
    char* res;
};

typedef struct iloc ILOC;

struct lista_ilocs
{
    ILOC inst;
    struct lista_ilocs *next;
};

typedef struct lista_ilocs LISTA_ILOCS;

char* gera_rotulo(void);
char* gera_temp(void);
ILOC gera_inst(int,char*,char*,char*,char*);
ILOC gera_inst_com_label(char*,ILOC);
void insere_lista_ilocs(LISTA_ILOCS*,ILOC);
void print_iloc(ILOC);
void print_lista_ilocs(LISTA_ILOCS*);
void concat_lista_ilocs(LISTA_ILOCS*,LISTA_ILOCS*);
void free_list(LISTA_ILOCS*);
int retorna_end_desloc(Stack*,valor_t);
int escopo_global(Stack*,valor_t);
#endif
