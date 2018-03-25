%option noyywrap
%{
#include "lex.h"
#include <string.h>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
int stringEscape = 0;
char string_buf[0xFFFF];
char *string_buf_ptr;
%}

%s COMMENT_S
%s STRING_S
%%

\/\/.*						/* skip comments */
"/*"						BEGIN(COMMENT_S);
<COMMENT_S>[^*\n]*			/* eat anything that's not a '*' */
<COMMENT_S>"*"+[^*/\n]*		/* eat up '*'s not followed by '/'s */
<COMMENT_S>\n 				/* add to line count later once that's implemented */
<COMMENT_S>"*"+"/"			BEGIN(0);

<INITIAL>\"      string_buf_ptr = string_buf; BEGIN(STRING_S);


<STRING_S>\"        { /* saw closing quote - all done */
        BEGIN(0);
        *string_buf_ptr = '\0';
        /* return string constant token type and
         * value to parser
         */
        }

<STRING_S>\n        {
        /* error - unterminated string constant */
        /* generate error message */
        }

<STRING_S>\\[0-7]{1,3} {
 cout << "\t\tADDING TO STRING: " << yytext << endl; 
        /* octal escape sequence */
        int result;

        (void) sscanf( yytext + 1, "%o", &result );

        if ( result > 0xff )
                /* error, constant is out-of-bounds */

        *string_buf_ptr++ = result;
        }

<STRING_S>\\[0-9]+ {
 cout << "\t\tADDING TO STRING: " << yytext << endl; 
        /* generate error - bad escape sequence; something
         * like '\48' or '\0777777'
         */
        }

<STRING_S>\\n  { *string_buf_ptr++ = '\n'; 
 cout << "\t\tADDING TO STRING: " << yytext << endl; }
<STRING_S>\\t  {*string_buf_ptr++ = '\t';
 cout << "\t\tADDING TO STRING: " << yytext << endl; }
<STRING_S>\\r  {*string_buf_ptr++ = '\r';
 cout << "\t\tADDING TO STRING: " << yytext << endl; }
<STRING_S>\\b  {*string_buf_ptr++ = '\b';
 cout << "\t\tADDING TO STRING: " << yytext << endl; }
<STRING_S>\\f  {*string_buf_ptr++ = '\f';
 cout << "\t\tADDING TO STRING: " << yytext << endl; }

<STRING_S>\\(.|\n)  {*string_buf_ptr++ = yytext[1];
 cout << "\t\tADDING TO STRING: " << yytext << endl; }

<STRING_S>[^\\\n\"]+        {
 cout << "\t\tADDING TO STRING: " << yytext << endl; 
        char *yptr = yytext;

        while ( *yptr )
                *string_buf_ptr++ = *yptr++;
        }

"=" 						{ cout << "\tFound ASSIGN: " << yytext << endl; return ASSIGN; }
"+" 						{ cout << "\tFound PLUS: " << yytext << endl; return PLUS;  }
"-" 						{ cout << "\tFound MINUS: " << yytext << endl; return MINUS; }
"/" 						{ cout << "\tFound DIV: " << yytext << endl; return DIV; }
"*" 						{ cout << "\tFound MUL: " << yytext << endl; return MUL; }
"%" 						{ cout << "\tFound MOD: " << yytext << endl; return MOD; }
"|" 						{ cout << "\tFound BIT_OR: " << yytext << endl; return BIT_OR; }
"&" 						{ cout << "\tFound BIT_AND: " << yytext << endl; return BIT_AND; }
"$" 						{ cout << "\tFound BIT_XOR: " << yytext << endl; return BIT_XOR; }
">>" 						{ cout << "\tFound RSL: " << yytext << endl; return RSL; }
"<<" 						{ cout << "\tFound LSL: " << yytext << endl; return LSL; }
"&&" 						{ cout << "\tFound AND: " << yytext << endl; return AND; }
"||" 						{ cout << "\tFound OR: " << yytext << endl; return OR; }
">" 						{ cout << "\tFound GTR: " << yytext << endl; return GTR; }
"<"  						{ cout << "\tFound LSS: " << yytext << endl; return LSS; }
">=" 						{ cout << "\tFound GEQ: " << yytext << endl; return GEQ; }
"<=" 						{ cout << "\tFound LEQ: " << yytext << endl; return LEQ; }
"==" 						{ cout << "\tFound EQU: " << yytext << endl; return EQU; }
"!="  						{ cout << "\tFound NEQ: " << yytext << endl; return NEQ; }
"!" 						{ cout << "\tFound NOT: " << yytext << endl; return NOT; }
"if"						{ cout << "\tFound IF: " << yytext << endl; return IF; }
"else"						{ cout << "\tFound ELSE: " << yytext << endl; return ELSE; }
"switch"					{ cout << "\tFound SWITCH: " << yytext << endl; return SWITCH; }
"case"						{ cout << "\tFound CASE: " << yytext << endl; return CASE; }
"while"						{ cout << "\tFound WHILE: " << yytext << endl; return WHILE; }
"break"						{ cout << "\tFound BREAK: " << yytext << endl; return BREAK; }
"return"					{ cout << "\tFound RETURN: " << yytext << endl; return RETURN; }
"void"						{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"single"					{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"dword"						{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"word"						{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"byte"						{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"nibble"					{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"bit"						{ cout << "\tFound BASE_TYPE: " << yytext << endl; return BASE_TYPE; }
"string"					{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"npc"						{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"qb"						{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"timer"						{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"floor"						{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"monster"					{ cout << "\tFound OBJ_TYPE: " << yytext << endl; return OBJ_TYPE; }
"sync"						{ cout << "\tFound SUPER_TYPE: " << yytext << endl; return SUPER_TYPE; }
"temp"						{ cout << "\tFound SUPER_TYPE: " << yytext << endl; return SUPER_TYPE; }
"reserved"					{ cout << "\tFound SUPER_TYPE: " << yytext << endl; return SUPER_TYPE; }
"GAME"						{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"QUEST"						{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"PLAYER_1"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"PLAYER_2"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"PLAYER_3"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"PLAYER_4"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"SELF"						{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"CAMERA"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
"PALETTEX"					{ cout << "\tFound OBJ: " << yytext << endl; return OBJ; }
[0-9]+\.[0-9]+				{ cout << "\tFound FLOAT: " << yytext << endl; return FLOAT; }
[0-9]+ 						{ cout << "\tFound DEC: " << yytext << endl; return DEC;  } 
0x[0-9|a-f|A-F]+ 			{ cout << "\tFound HEX: " << yytext << endl; return HEX; }
[a-z|A-Z][a-z|A-Z|0-9|_]* 	{ cout << "\tFound NAME: " << yytext << endl; return NAME; }
[ \t\n]+					/* blank, tab, new line: eat up whitespace */
.							{ cout << "\tFound yytext[0]: " << yytext << endl; return yytext[0]; }
%%
