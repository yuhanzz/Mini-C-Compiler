#pragma once
#include <unordered_map>
#include <string>
#include "tree.h"
using namespace std;

#define MAXSCOPE 50

enum VarType
{
	INT_VAR = 0,
	CHAR_VAR,
	NOT_SURE
};

class symbolEntry
{
public:
	string lexeme;
	VarType varType;
	int arraySize;
	symbolEntry(string lex);
	symbolEntry();
};

class symbolTable
{
public:
	unordered_map<string, symbolEntry> hashTable;
public:
	int parentSeq;
	symbolTable() { parentSeq = -1; }
	string insert(string lexeme);
	symbolEntry* lookup(string lexeme);
	void deleteSymbol(string lexeme);
	friend void setVarType(symbolTable& symTab, string lexeme, VarType type);
	friend VarType getVarType(symbolTable& symTab, string lexeme);
	friend void setArraySize(symbolTable& symTab, string lexeme, int size);
	void printTable();
};
