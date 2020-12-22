using namespace std;

#include "symbol.h"
#include <iostream>
#include <iomanip>


symbolEntry::symbolEntry(string lex)
{
	lexeme = lex;
	varType = NOT_SURE;
	arraySize = -1;
}

symbolEntry::symbolEntry()
{
	lexeme = "";
	varType = NOT_SURE;
	arraySize = -1;
}

string symbolTable::insert(string lexeme)
{
	symbolEntry temp(lexeme);
	hashTable[lexeme] = temp;
	return lexeme;
}

symbolEntry* symbolTable::lookup(string lexeme)
{
	if (hashTable.find(lexeme) != hashTable.end())
		return &hashTable[lexeme];
	else
		return NULL;
}

void symbolTable::deleteSymbol(string lexeme)
{
	if (lookup(lexeme) == NULL)
		return;
	else
	{
		hashTable.erase(lexeme);
		return;
	}
}
void setVarType(symbolTable& symTab, string lexeme, VarType type)
{
	if (symTab.lookup(lexeme) == NULL)
	{
			return;
	}
	if (symTab.hashTable[lexeme].varType == NOT_SURE)
		symTab.hashTable[lexeme].varType = type;

	return;
}

VarType getVarType(symbolTable& symTab, string lexeme)
{
	return symTab.hashTable[lexeme].varType;
}


void setArraySize(symbolTable& symTab,string lexeme, int size)
{
	if (symTab.lookup(lexeme) == NULL)
		return;
	if (symTab.hashTable[lexeme].arraySize = -1)
		symTab.hashTable[lexeme].arraySize = size;
	return;
}

int getArraySize(symbolTable& symTab,string lexeme)
{
	if (symTab.lookup(lexeme) == NULL)
		return -1;
	return symTab.hashTable[lexeme].arraySize;
}
void symbolTable::printTable()
{
	for(unordered_map<string, symbolEntry>::iterator iter=hashTable.begin();iter!=hashTable.end();iter++ )
	{
		string types[] = { "int","char","not sure" };
        cout<<"ID: "<< setw(15) << iter->first<<"type: "<< setw(15) << types[iter->second.varType]<<"array size: "<< setw(15) << iter->second.arraySize<<endl;
    }
}