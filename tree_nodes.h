#include <cstdint> // for uint32_t
#include <list>

/// Abstract Classes
class def {};
class stmt {};

union number {
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

class param {
	public:
		uint32_t super_type; // optional
		uint32_t sub_type;
		std::string name;
		param(uint32_t t, char* n, uint32_t s){
			super_type = s;
			sub_type = t;
			std::string str(n);
			name = str;
		}
		param(uint32_t t, char* n){
			sub_type = t;
			std::string str(n);
			name = str;
		}
};

class global : def {
	public:
		uint32_t super_type; // optional
		uint32_t sub_type;
		std::string name;
		number value; // optional
		global(uint32_t t, std::string n, number v, uint32_t s){
			sub_type = t;
			name = n;
			value = v;
			super_type = s;
		}
		global(uint32_t t, std::string n, number v){
			sub_type = t;
			name = n;
			value = v;
		}
		global(uint32_t t, std::string n){
			sub_type = t;
			name = n;
		}
		global(uint32_t t, std::string n, uint32_t s){
			sub_type = t;
			name = n;
			super_type = s;
		}
};

class expr {
	public:
		std::string lhs;
		uint32_t operation;
		expr* rhs; // if NULL then is a leaf node
};


class func : def {
	public:
		uint32_t return_type; // a base_type
		std::string name;
		std::list<param*>* params;
		uint32_t func_number; // -1 if auto assignable
		std::list<stmt*>* body;
		func(uint32_t t, char* n, std::list<param*>* p, uint32_t num, std::list<stmt*>* b){
			return_type = t;
			params = p;
			func_number = num;
			body = b;
			std::string str(n);
			name = str;
		}
};

class stmt_assign : stmt {
	public:
		std::string id;
		std::string obj; // optional (can be built in or id)
		expr* value;
};

class stmt_call : stmt {
	public:
		std::string id;
		std::string obj; // optional
		std::list<param> params;
};

class stmt_var : stmt {
	public:
		uint32_t super_type; // optional
		uint32_t sub_type;
		std::string id;
		expr* value; // optional
};

class stmt_if : stmt {
	public:
		expr* check;
		std::list<stmt> body;
		std::list<stmt> else_body; // optional
};

class stmt_while : stmt {
	public:
		expr* check;
		std::list<stmt> body;
};

class switch_case {
	public:
		std::string value;
		std::list<stmt> body;
};

class stmt_switch : stmt {
	public:
		std::list<switch_case> cases;
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