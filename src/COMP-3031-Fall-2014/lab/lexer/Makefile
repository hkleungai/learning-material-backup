lexer: lexer.yy.c
	gcc -o $@ $<
lexer.yy.c: lexer.lex
	flex -o$@ $<

clean:
	rm -f lexer lexer.yy.c
