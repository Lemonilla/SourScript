
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN = 1,
     PLUS = 2,
     MINUS = 3,
     DIV = 4,
     MUL = 5,
     MOD = 6,
     BIT_OR = 7,
     BIT_AND = 8,
     BIT_XOR = 9,
     RSL = 10,
     LSL = 11,
     AND = 12,
     OR = 13,
     GTR = 14,
     LSS = 15,
     GEQ = 16,
     LEQ = 17,
     EQU = 18,
     NEQ = 19,
     NOT = 20,
     IF = 21,
     ELSE = 22,
     SWITCH = 23,
     CASE = 24,
     WHILE = 25,
     BREAK = 26,
     RETURN = 27,
     BASE_TYPE = 28,
     OBJ_TYPE = 29,
     SUPER_TYPE = 30,
     OBJ = 31,
     FLOAT = 32,
     DEC = 33,
     HEX = 34,
     NAME = 35,
     STRING = 36
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 31 "parse"

	int ival;
	float fval; // maybe double.  check size
	char* str;
	void* ptr;



/* Line 1676 of yacc.c  */
#line 99 "parse.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


