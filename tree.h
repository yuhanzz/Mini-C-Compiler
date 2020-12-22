#pragma once
#include <string>
#include "symbol.h"
using namespace std;
#define MAXCHILDREN 5

enum GenType
{

	EXPR_NODE = 0,
	STMT_NODE,
	LEAF_NODE

};

enum ExprType
{
	LEFTVALUE_EXPR = 0,
	RIGHTVALUE_EXPR,
	MATH_EXPR,
	ASSIGN_EXPR,
};

enum StmtType
{
	DECLARE_STMT = 0,
	COMPOUND_STMT,
	EXPR_STMT,
	IF_STMT,
	WHILE_STMT,
	FOR_STMT,
	VOID_STMT,
	OUTPUT_STMT,
	INPUT_STMT,
	BREAK_STMT,
	CONTINUE_STMT
};

enum LeafType
{
	ID_LEAF = 0,
	ARRAY_LEAF,
	INTCONST_LEAF,
	CHARCONST_LEAF,
	STRINGCONST_LEAF,
	INT_LEAF,
	CHAR_LEAF
};

struct SpecType
{

	ExprType exprType;
	StmtType stmtType;
	LeafType leafType;

};

enum Operator
{
	ASSIGN_OP = 0,
	BOR_OP,
	BXOR_OP,
	BAND_OP,
	LSHIFT_OP,
	RSHIFT_OP,
	ADD_OP,
	SUB_OP,
	MUL_OP,
	DIV_OP,
	MOD_OP,
	BNOT_OP,
	PRE_PLUSPLUS_OP,
	PRE_MINUSMINUS_OP,
	POST_PLUSPLUS_OP,
	POST_MINUSMINUS_OP,
	NEGATIVE_OP,

	NE_OP,
	EQ_OP,
	LT_OP,
	LE_OP,
	GT_OP,
	GE_OP,

	AND_OP,
	OR_OP,

	NO_OP

};

struct NodeAttr
{
	string idEntry;
	int arrayIndex;
	int intValue;
	char charValue;
	string stringValue;
	Operator operatorType;

};


class Node
{
public:
	int seq;
	int symtabSeq;

	NodeAttr nodeAttr;
	int lineNumber;

	GenType genType;
	SpecType specType;

	Node* children[MAXCHILDREN];
	Node* sibling;

	int temp_seq;

	string begin_label;
	string after_label;
	string true_label;
	string false_label;
	void gen_math_code(ostream& out);
	void printTree();
};

class tree
{
public:
	Node* root;
	void printTree();
	Node* mkStmtNode(StmtType type, Node* child1 = NULL, Node* child2 = NULL, Node* child3 = NULL, Node* child4 = NULL, Node* child5 = NULL);
	Node* mkExprNode(ExprType type, Operator operatorType, Node* child1 = NULL, Node* child2 = NULL, Node* child3 = NULL, Node* child4 = NULL, Node* child5 = NULL);
	Node* mkLeaf(LeafType type);

	void type_check(Node* t);
	void get_temp_var(Node * t);
	void generate_assembly(Node* t,ostream& out);
	void generate_code(Node* t, ostream& out);
	void generate_label(Node* t);
};