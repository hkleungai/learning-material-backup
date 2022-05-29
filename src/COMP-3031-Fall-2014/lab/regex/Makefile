regex: regex.yy.c regex.tab.c
	gcc -o $@ $^
regex.yy.c: regex.lex regex.tab.h
	flex -o$@ $<
regex.tab.h: regex.y
	bison -d $<
regex.tab.c: regex.y
	bison -d $<

clean:
	rm -f regex regex.yy.c regex.tab.*
