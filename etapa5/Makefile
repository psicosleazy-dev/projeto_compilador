etapa5: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
<<<<<<< HEAD
	gcc -g -c lex.yy.c main.c ast.c errors.c stack_management.c hash.c list.c ilocs.c parser.tab.c
	gcc -o etapa5 lex.yy.o parser.tab.o main.o ast.o errors.o hash.o stack_management.o list.o ilocs.o -lfl
=======
	gcc -g -c lex.yy.c main.c ast.c errors.c stack_management.c hash.c list.c parser.tab.c
	gcc -o etapa5 lex.yy.o parser.tab.o main.o ast.o errors.o hash.o stack_management.o list.o -lfl
>>>>>>> 9bba38d311647a4d8d9b26cdc09fa68dbc12776d
clean:
	rm -rf etapa5
