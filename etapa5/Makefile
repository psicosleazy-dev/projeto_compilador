etapa5: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
	gcc -g -c lex.yy.c parser.tab.c main.c ast.c errors.c hash.c stack_management.c list.c ilocs.c
	gcc -o etapa5 lex.yy.o parser.tab.o main.o ast.o errors.o hash.o stack_management.o list.o ilocs.o -lfl
clean:
	rm -rf etapa5
