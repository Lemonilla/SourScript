/* TODO:
    use yylval when passing value

*/
%option noyywrap
%option yylineno

%{

#define DEBUG //
#define YY_DECL extern "C" int yylex()
#include <string.h>
#include <iostream>
#include "parse.tab.h"

using namespace std;

extern char* yytext;
extern YYSTYPE yylval;
extern void yyerror(const char *s);

char string_buf[0xFFFF];
char *string_buf_ptr;

%}

%s COMMENT_S
%s STRING_S
%%

\/\/.*						/* skip comments */
<INITIAL>"/*"				BEGIN(COMMENT_S);
<COMMENT_S>[^*\n]*			/* eat anything that's not a '*' */
<COMMENT_S>"*"+[^*/\n]*		/* eat up '*'s not followed by '/'s */
<COMMENT_S>\n 				/* add to line count later once that's implemented */
<COMMENT_S>"*"+"/"			BEGIN(0);

<INITIAL>\"          {
        string_buf_ptr = string_buf; BEGIN(STRING_S);
    }
<STRING_S>\"            {   /* saw closing quote - all done */
        BEGIN(0);
        *string_buf_ptr = '\0';
        /* return string constant token type and
         * value to parser
         */
        yylval.str = strdup(string_buf);
        return STRING; 
    }

<STRING_S>\n            {
        /* error - unterminated string constant */
        /* generate error message */
       }

<STRING_S>\\[0-7]{1,3}     {
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
        /* octal escape sequence */
        int result;

        (void) sscanf( yytext + 1, "%o", &result );

        if ( result > 0xff )
                /* error, constant is out-of-bounds */

        *string_buf_ptr++ = result;
    }

<STRING_S>\\[0-9]+     {
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
        /* generate error - bad escape sequence; something
         * like '\48' or '\0777777'
         */
         yyerror("Bad escape sequence");
         //char* ptr = &yytext;
         //while (*ptr != NULL)
         //   *string_buf_ptr++ = *ptr++;
    }

<STRING_S>\\n      { 
        *string_buf_ptr++ = '\n'; 
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }
<STRING_S>\\t      {
        *string_buf_ptr++ = '\t';
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }
<STRING_S>\\r      {
        *string_buf_ptr++ = '\r';
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }
<STRING_S>\\b      {
        *string_buf_ptr++ = '\b';
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }
<STRING_S>\\f      {
        *string_buf_ptr++ = '\f';
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }
<STRING_S>\\(.|\n)      {
        *string_buf_ptr++ = yytext[1];
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
    }

<STRING_S>[^\\\n\"]+            {
        DEBUG cout << "\t\tADDING TO STRING: " << yytext << endl; 
        char *yptr = yytext;
        while ( *yptr )
                *string_buf_ptr++ = *yptr++;
    }
"="                             { 
        DEBUG cout << "\tFound ASSIGN: " << yytext << endl;
        return ASSIGN; 
    }
"+"                             { 
        DEBUG cout << "\tFound PLUS: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return PLUS;  
    }
"-"                             { 
        DEBUG cout << "\tFound MINUS: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return MINUS; 
    }
"/"                             { 
        DEBUG cout << "\tFound DIV: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return DIV; 
    }
"*"                             { 
        DEBUG cout << "\tFound MUL: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return MUL; 
    }
"%"                             { 
        DEBUG cout << "\tFound MOD: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return MOD; 
    }
"|"                             { 
        DEBUG cout << "\tFound BIT_OR: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BIT_OR; 
    }
"&"                             { 
        DEBUG cout << "\tFound BIT_AND: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BIT_AND; 
    }
"$"                             { 
        DEBUG cout << "\tFound BIT_XOR: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BIT_XOR; 
    }
">>"                            { 
        DEBUG cout << "\tFound RSL: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return RSL; 
    }
"<<"                            { 
        DEBUG cout << "\tFound LSL: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return LSL; 
    }
"&&"                            { 
        DEBUG cout << "\tFound AND: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return AND; 
    }
"||"                            { 
        DEBUG cout << "\tFound OR: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OR; 
    }
">"                             { 
        DEBUG cout << "\tFound GTR: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return GTR; 
    }
"<"                             { 
        DEBUG cout << "\tFound LSS: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return LSS; 
    }
">="                            { 
        DEBUG cout << "\tFound GEQ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return GEQ; 
    }
"<="                            { 
        DEBUG cout << "\tFound LEQ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return LEQ; 
    }
"=="                            { 
        DEBUG cout << "\tFound EQU: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return EQU; 
    }
"!="                            { 
        DEBUG cout << "\tFound NEQ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return NEQ; 
    }
"!"                             { 
        DEBUG cout << "\tFound NOT: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return NOT; 
    }
"if"                            { 
        DEBUG cout << "\tFound IF: " << yytext << endl; 
        return IF; 
    }
"else"                          { 
        DEBUG cout << "\tFound ELSE: " << yytext << endl; 
        return ELSE; 
    }
"switch"                        { 
        DEBUG cout << "\tFound SWITCH: " << yytext << endl; 
        return SWITCH; 
    }
"case"                          { 
        DEBUG cout << "\tFound CASE: " << yytext << endl; 
        return CASE; 
    }
"while"                         { 
        DEBUG cout << "\tFound WHILE: " << yytext << endl; 
        return WHILE; 
    }
"break"                         { 
        DEBUG cout << "\tFound BREAK: " << yytext << endl; 
        return BREAK; 
    }
"return"                     { 
        DEBUG cout << "\tFound RETURN: " << yytext << endl; 
        return RETURN; 
    }
"void"                          { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"single"                        { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"dword"                         { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"word"                          { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"byte"                          { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"nibble"                        { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"bit"                           { 
        DEBUG cout << "\tFound BASE_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return BASE_TYPE; 
    }
"string"                        { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"npc"                           { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"qb"                            { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"timer"                         { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"floor"                         { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"monster"                       { 
        DEBUG cout << "\tFound OBJ_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ_TYPE; 
    }
"sync"                          { 
        DEBUG cout << "\tFound SUPER_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return SUPER_TYPE; 
    }
"temp"                          { 
        DEBUG cout << "\tFound SUPER_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return SUPER_TYPE; 
    }
"reserved"                      { 
        DEBUG cout << "\tFound SUPER_TYPE: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return SUPER_TYPE; 
    }
"GAME"                          { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"QUEST"                         { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"PLAYER_1"                      { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"PLAYER_2"                      { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"PLAYER_3"                      { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"PLAYER_4"                      { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"SELF"                          { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"CAMERA"                        { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
"PALETTEX"                      { 
        DEBUG cout << "\tFound OBJ: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return OBJ; 
    }
[0-9]+\.[0-9]+                  { 
        DEBUG cout << "\tFound FLOAT: " << yytext << endl; 
        yylval.fval = atof(yytext);
        return FLOAT; 
    }
[0-9]+                          { 
        DEBUG cout << "\tFound DEC: " << yytext << endl; 
        yylval.ival = atoi(yytext);
        return DEC;  
    }
0x[0-9|a-f|A-F]+                { 
        DEBUG cout << "\tFound HEX: " << yytext << endl; 
        yylval.ival = atoi(yytext);
        return HEX; 
    }
[a-z|A-Z][a-z|A-Z|0-9|_]* 	    {            
        DEBUG cout << "\tFound NAME: " << yytext << endl; 
        yylval.str = strdup(yytext);
        return NAME; 
    }
[ \t\n]+					/* blank, tab, new line: eat up whitespace */
.							    { 
        yylval.str = strdup(&yytext[0]);
        return yytext[0]; 
    }
%%

