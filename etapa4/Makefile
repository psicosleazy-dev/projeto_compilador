etapa4: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
	gcc -g -c lex.yy.c main.c ast.c errors.c stack_management.c hash.c parser.tab.c
	gcc -o etapa4 lex.yy.o parser.tab.o main.o ast.o errors.o hash.o stack_management.o -lfl
clean:
	rm -rf etapa4
