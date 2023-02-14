etapa3: parser.y scanner.l
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c main.c ast.c parser.tab.c
	gcc -o etapa3 lex.yy.o parser.tab.o main.o ast.o -lfl
clean:
	rm -rf etapa3
