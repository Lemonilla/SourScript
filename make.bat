flex lex
bison -d parse
g++ program.c parse.tab.c lex.yy.c table.c