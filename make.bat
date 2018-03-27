flex lex
bison -d parse
g++ parse.tab.c lex.yy.c