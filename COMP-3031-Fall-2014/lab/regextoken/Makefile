regextokenizer: regextokenizer.yy.c
	gcc -o $@ $<
regextokenizer.yy.c: regextokenizer.lex
	flex -o$@ $<

clean:
	rm -f regextokenizer regextokenizer.yy.c
