#ifndef _ILOCS_H_
#define _ILOCS_H_
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
#define ILOC_NOP 364
#define ILOC_MULTI 365
#define ILOC_DIVI 366
#define ILOC_JUMPI 367
#define MAX_LEN 3

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_management.h"

struct iloc{
    int eh_label;
    int tipo_iloc;
    char* label;
    char* op;
    char* op1;
    char* op2;
    char* res;
};

typedef struct iloc ILOC;

typedef struct lista_ilocs{
    ILOC inst;
    struct lista_ilocs *next;
}LISTA_ILOCS;

void insere_lista_ilocs(LISTA_ILOCS**,ILOC);
ILOC gera_inst(int,char*,char*,char*,char*);
ILOC gera_inst_com_label(char*,ILOC);
void print_iloc(ILOC,FILE*);
void print_list_ilocs(LISTA_ILOCS*);
LISTA_ILOCS* concat_lista_ilocs(LISTA_ILOCS*,LISTA_ILOCS*);
void free_list(LISTA_ILOCS*);
int tam_lista_ilocs(LISTA_ILOCS*);
char* gera_temp(void);
char* gera_rotulo(void);
void generateAsm(Stack*,LISTA_ILOCS*);
#endif
