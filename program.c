#include <cstdio>
#include <iostream>
#include <map>
#include "tree_nodes.h"
#include "parse.tab.h"
#include "table.h" // defines tableEntry
extern "C" void buildTree(char* filename);
extern "C" void buildTable();
extern "C" program* prgm;
extern "C" std::map<std::string,tableEntry*>* table;

using namespace std;

program* prgm;
map<string,tableEntry*>* table;


int main(int argc, char *argv[]) 
{
	// init
	// interpret arguments
	buildTree(argv[1]);
	buildTable();
	// decorate tree
	// code generation	
}

