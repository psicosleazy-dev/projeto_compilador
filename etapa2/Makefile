etapa2: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c main.c parser.tab.c
	gcc -o etapa2 lex.yy.o parser.tab.o main.o -lfl
clean:
	rm -rf etapa2
