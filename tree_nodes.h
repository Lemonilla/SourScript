#include <cstdint> // for uint32_t
#include <list>
#include <iostream>
#include "parse.tab.h"

extern "C" char* yytext;
extern YYSTYPE yylval;

/// Abstract Classes
class def {};
class stmt {};

union num 
{
	uint32_t integer;
	float real;
};

/// Normal Classes
class program 
{
	public:
		std::list<def*>* definitions;
		program()
		{
			definitions = new std::list<def*>();
		}
};


class value 
{
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

class param 
{
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

class global : public def 
{
	public:
		std::string super_type; // optional
		std::string sub_type;
		std::string name;
		uint32_t val; // optional
		global(char* t, char* n, uint32_t v, char* s){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
			val = v;
			std::string sup(s);
			super_type = sup;
		}
		global(char* t, char* n, uint32_t v){
			std::string ty(t);
			sub_type = ty;
			std::string nm(n);
			name = nm;
			val = v;
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

class expr 
{
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


class func : public def 
{
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

class stmt_assign : public stmt 
{
	public:
		std::string id;
		std::string obj; // optional (can be built in or id)
		expr* val;
		stmt_assign(char* n, expr* v)
		{
			std::string i(n);
			id = i;
			val = v;
		}
		stmt_assign(char* n, char* o, expr* v)
		{
			std::string i(n);
			id = i;
			std::string ob(o);
			obj = ob;
			val = v;
		}
};

class stmt_call : public stmt 
{
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

class stmt_var : public stmt 
{
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

class stmt_if : public stmt 
{
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

class stmt_while : public stmt 
{
	public:
		expr* check;
		std::list<stmt*>* body;
		stmt_while(void* e, void* b)
		{
			check = (expr*) e;
			body = (std::list<stmt*>*) b;
		}
};

class switch_case 
{
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

class stmt_return : public stmt 
{
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

class stmt_switch : public stmt 
{
	public:
		value* val; // optional
		std::list<switch_case*>* cases;
		stmt_switch(void* s, void* c)
		{
			val = (value*) s;
			cases = (std::list<switch_case*>*) c;
		}
};
