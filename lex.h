#define ASSIGN					1							
#define PLUS					2							
#define MINUS					3							
#define DIV						4						
#define MUL						5						
#define MOD						6						
#define BIT_OR					7							
#define BIT_AND					8							
#define BIT_XOR					9							
#define RSL						10						
#define LSL						11						
#define AND						12						
#define OR						13						
#define GTR						14						
#define LSS						15						
#define GEQ						16						
#define LEQ						17						
#define EQU						18						
#define NEQ						19						
#define NOT						20						
#define IF						21						
#define ELSE					22							
#define SWITCH					23							
#define CASE					24						
#define WHILE					25							
#define BREAK					26							
#define RETURN					27							
#define BASE_TYPE				28								
#define OBJ_TYPE				29								
#define SUPER_TYPE				30								
#define OBJ						31																	
#define FLOAT					32							
#define DEC						33						
#define HEX						34						
#define NAME					35	
#define STRING					36						

union token {
    int ival;
    float fval;
    char* str;
    void* ptr;
};