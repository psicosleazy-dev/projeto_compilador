main: main.c
      gcc main.c -c

scanner: scanner.l
         flex scanner.l
         gcc lex.yy.c -c

all: main scanner
       gcc lex.yy.o main.o -o etapa1
