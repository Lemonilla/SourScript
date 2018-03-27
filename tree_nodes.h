#include <cstdint> // for uint32_t
#include <list>
#include <iostream>
#include "parse.tab.h"

extern "C" char* yytext;
extern YYSTYPE yylval;

/// Abstract Classes
class def {};
class stmt {};

union num {
	uint32_t integer;
	float real;
};

/// Normal Classes
class program {
	public:
		std::list<def>* definitions;
		program()
		{
			definitions = new std::list<def>();
		}
};


class value {
	public:
		uint32_t value_type;
			// 0 : string
			// 1 : number
			// 3 : var w/ obj
			// 4 : var w/o obj
		std::string str;
		uint32_t num;
		std::string obj;
		std::string name;
		value(uint32_t type, char* s)
		{
			value_type = type;
			std::string val(s);
			if (type == 0)  // string
				str = s;
			if (type == 4)  // var w/o obj
				name = s;
		}
		value(uint32_t type, uint32_t n)
		{
			value_type = 1;
			num = n;
		}
		value(uint32_t type, char* o, char* n)
		{
			value_type = 3;
			std::string sup(o);
			obj = sup;
			std::string sub(n);
			name = sub;
		}
};

class param {
	public:
		std::string super_type; // optional
		std::string sub_type;
		std::string name;
		param(char* t, char* n, char* s){
			super_type = s;
			sub_type = t;
			std::string str(n);
			name = str;
		}
		param(char* t, char* n){
			std::string ty(t);
			sub_type = ty;
			std::string str(n);
			name = str;
		}
};

class global : public def {
	public:
		std::string super_type; // optional
		std::string sub_type;
		std::string name;
		uint32_t value; // optional
		global(char* t, char* n, uint32_t v, char* s){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
			value = v;
			std::string sup(s);
			super_type = sup;
		}
		global(char* t, char* n, uint32_t v){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
			value = v;
		}
		global(char* t, char* n){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
		}
		global(char* t, char* n, char* s){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
			std::string sup(s);
			super_type = sup;
		}
};

class expr {
	public:
		value* lhs;
		std::string operation;
		expr* rhs; // if NULL then is a leaf node
		expr(void* l, char* o, void* r)
		{
			lhs = (value*) l;
			std::string op(o);
			operation = op;
			rhs = (expr*) r;
		}
		expr(void* l, char* o)
		{
			lhs = (value*) l;
			std::string op(o);
			operation = op;
		}
		expr(void* l)
		{
			lhs = (value*) l;
		}
};


class func : public def {
	public:
		std::string return_type; // a base_type
		std::string name;
		std::list<param*>* params;
		uint32_t func_number; // -1 if auto assignable
		std::list<stmt*>* body;
		func(char* t, char* n, std::list<param*>* p, uint32_t num, std::list<stmt*>* b){
			std::string ty(t);
			return_type = ty;
			params = p;
			func_number = num;
			body = b;
			std::string str(n);
			name = str;
		}
};

class stmt_assign : public stmt {
	public:
		std::string id;
		std::string obj; // optional (can be built in or id)
		expr* value;
		stmt_assign(char* n, expr* v)
		{
			std::string i(n);
			id = i;
			value = v;
		}
		stmt_assign(char* n, char* o, expr* v)
		{
			std::string i(n);
			id = i;
			std::string ob(o);
			obj = ob;
			value = v;
		}
};

class stmt_call : public stmt {
	public:
		std::string id;
		std::string obj; // optional
		std::list<param*>* params;
		stmt_call(char* n, void* p)
		{
			std::string i(n);
			id = i;
			params = (std::list<param*>*) p;
		}
		stmt_call(char* n, char* o, void* p)
		{
			std::string i(n);
			id = i;
			params = (std::list<param*>*) p;
		}
};

class stmt_var : public stmt {
	public:
		std::string super_type; // optional
		std::string sub_type;
		std::string id;
		expr* value; // optional
		stmt_var(char* t, char* n)
		{
			std::string ty(t);
			sub_type = ty;
			std::string i(n);
			id = i;
		}
		stmt_var(char* s, char* t, char* n)
		{
			std::string sp(s);
			super_type = sp;
			std::string ty(t);
			sub_type = ty;
			std::string i(n);
			id = i;
		}
		stmt_var(char* t, char* n, void* e)
		{
			std::string ty(t);
			sub_type = ty;
			std::string i(n);
			id = i;
			value = (expr*) e;
		}
		stmt_var(char* s, char* t, char* n, void* e)
		{
			std::string sup(s);
			super_type = sup;
			std::string ty(t);
			sub_type = ty;
			std::string i(n);
			id = i;
			value = (expr*) e;
		}
};

class stmt_if : public stmt {
	public:
		expr* check;
		std::list<stmt*>* body;
		std::list<stmt*>* else_body; // optional
		stmt_if(void* e, void* bd)
		{
			check = (expr*) e;
			body = (std::list<stmt*>*) bd;
		}
		stmt_if(void* e, void* bd, void* el)
		{
			check = (expr*) e;
			body = (std::list<stmt*>*) bd;
			else_body = (std::list<stmt*>*) el;
		}
		
};

class stmt_while : public stmt {
	public:
		expr* check;
		std::list<stmt*>* body;
		stmt_while(void* e, void* b)
		{
			check = (expr*) e;
			body = (std::list<stmt*>*) b;
		}
};

class switch_case {
	public:
		std::string val;
		std::list<stmt*>* body;
		switch_case(void* v, void* stmts)
		{
			std::string va((char*) v);
			val = va;
			body = (std::list<stmt*>*) stmts;
		}

};

class stmt_return : public stmt {
	public:
		std::string val;
		stmt_return(void* v){
			std::string ret( (char*) v);
			val = ret;
		}
};

class id_class 
{
	public:
		std::string obj; //optional
		std::string name;
		id_class (char* n, char* o)
		{
			std::string nm(n);
			name = nm;
			std::string ob(o);
			obj = ob;
		}
		id_class (char* n)
		{
			std::string nm(n);
			name = nm;
		}
};

class stmt_switch : public stmt {
	public:
		value* val; // optional
		std::list<switch_case*>* cases;
		stmt_switch(void* s, void* c)
		{
			val = (value*) s;
			cases = (std::list<switch_case*>*) c;
		}
};





/// Token Defines
#ifndef TOKENDEF
	#define TOKENDEF

	//super_type
	#define _SYNC            1
	#define _TEMP            2
	#define _RESERVED        3

	//sub_type
	#define _VOID            1
	#define _SINGLE          2
	#define _DWORD           3
	#define _WORD            4
	#define _BYTE            5
	#define _NIBBLE          6
	#define _BIT             7
	#define _STRING          8 // obj_type
	#define _NPC             9 // obj_type
	#define _QB             10 // obj_type
	#define _TIMER          11 // obj_type
	#define _FLOOR          12 // obj_type
	#define _MONSTER        13 // obj_type

	//operation
	#define _PLUS            1
	#define _MINUS           2 
	#define _DIV             3
	#define _MUL             4
	#define _MOD             5 
	#define _BIT_OR          6  
	#define _BIT_AND         7   
	#define _BIT_XOR         8   
	#define _RSL             9
	#define _LSL            10
	#define _AND            11
	#define _OR             12
	#define _GTR            13
	#define _LSS            14
	#define _GEQ            15
	#define _LEQ            16
	#define _EQU            17
	#define _NEQ            18
	#define _NOT            19
	#define _ADDR           20
#endif