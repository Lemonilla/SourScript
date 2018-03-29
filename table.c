#include <cstdio>
#include <iostream>
#include <map>
#include <list>
#include "tree_nodes.h"
#include "table.h"

using namespace std;

extern "C" program* prgm;
extern "C" map<string,tableEntry*>* table;
extern "C" void buildTable();

uint32_t label;
uint32_t location;
list<uint32_t>* reservedLocations;

uint32_t getNextLabel();
uint32_t getNextLocation();

void buildTable()
{
	label = 1; // 0 reserved for main!
	location = 0;
	reservedLocations = new list<uint32_t>();
	table = new map<string,tableEntry*>();
	list<def*>* programList = prgm->definitions;

	for (list<def*>::iterator it = programList->begin(); it != programList->end(); ++it;)
	{
		// it = ptr to a def object
		def* current = dynamic_cast<global*>(it);
		if (current == NULL) processFunc(it);
		else processGlobal(it);
	}
}


void processGlobal(global* g)
{
	
}

void processFunc(func* g)
{

}

uint32_t getNextLocation() 
{
	return location++;
}

uint32_t getNextLabel() 
{
	for( list<uint32_t>::iterator it = (*reservedLocations).begin(); it != (*reservedLocations).end(); ++it)
	{
		if (label == *it) {
			label++;
			return getNextLabel();
		}
	}
	return label++;
}

void claimLabel(uint32_t l)
{
	return;
}