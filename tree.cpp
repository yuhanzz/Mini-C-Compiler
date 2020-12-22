#include <string>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "symbol.h"
#include "tree.h"
using namespace std;

extern symbolTable* symTab;
extern int currentSymtab;
extern int lineNumber;
int nodeSeq = 0;
tree parseTree;

int global_temp_seq=0;
int max_temp_seq=0;
int label_seq=0;
int temp_label_seq=0;


queue<string> post_minus_unhandled;
queue<string> post_plus_unhandled;

string new_temp_label()
{
	ostringstream oss;
	oss << temp_label_seq;
	string new_label = "@tmp" + oss.str();
	temp_label_seq++;
	return new_label;
}

string new_label()
{
	ostringstream oss;
	oss << label_seq;
	string new_label = "@lab" + oss.str();
	label_seq++;
	return new_label;
}

void post_handler(ostream& out)
{
	while (!post_minus_unhandled.empty())
	{
		string operand = post_minus_unhandled.front();

		out << "\tMOV eax, " << operand << endl;
		out << "\tDEC eax" << endl;
		out << "\tMOV " << operand << ", eax" << endl;

		post_minus_unhandled.pop();
	}
	while (!post_plus_unhandled.empty())
	{
		string operand = post_plus_unhandled.front();

		out << "\tMOV eax, " << operand << endl;
		out << "\tINC eax" << endl;
		out << "\tMOV " << operand << ", eax" << endl;

		post_plus_unhandled.pop();
	}
}

void tree::type_check(Node* t)
{
	switch (t->genType)
	{
	case EXPR_NODE:
	{
		switch (t->specType.exprType)
		{
		case ASSIGN_EXPR:
		{
			VarType rightVarType;
			switch (t->children[1]->specType.exprType)
			{
			case LEFTVALUE_EXPR:
			{
				rightVarType = getVarType(symTab[t->children[1]->children[0]->symtabSeq], t->children[1]->children[0]->nodeAttr.idEntry);
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				if (t->children[1]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					rightVarType = INT_VAR;
				}
				else if (t->children[1]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					rightVarType = CHAR_VAR;
				}
				break;
			}
			case MATH_EXPR:
			{
				rightVarType = INT_VAR;
				break;
			}
			case ASSIGN_EXPR:
			{
				rightVarType = getVarType(symTab[t->children[1]->children[0]->symtabSeq], t->children[1]->children[0]->nodeAttr.idEntry);
				break;
			}
			}
			//还未赋类型的说明处在声明语句里，先不检查
			if (getVarType(symTab[t->children[0]->symtabSeq], t->children[0]->nodeAttr.idEntry) != NOT_SURE)
			{
				if (getVarType(symTab[t->children[0]->symtabSeq], t->children[0]->nodeAttr.idEntry) != rightVarType)
					cerr << "unmatched assign!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1" << endl;
			}
			break;
		}
		case MATH_EXPR:
		{
			VarType operandType[2];
			int i = 0;
			while(t->children[i]!=NULL)
			{
				//先单独处理增量的type，因为它们的孩子节点是LEAF类型
				if (t->children[i]->genType == LEAF_NODE)
				{
					operandType[0]= getVarType(symTab[t->children[0]->symtabSeq], t->children[0]->nodeAttr.idEntry);
				}
				else
					switch (t->children[i]->specType.exprType)
					{
					case LEFTVALUE_EXPR:
					{
						operandType[i] = getVarType(symTab[t->children[i]->children[0]->symtabSeq], t->children[i]->children[0]->nodeAttr.idEntry);
						break;
					}
					case RIGHTVALUE_EXPR:
					{
						if (t->children[i]->children[0]->specType.leafType == INTCONST_LEAF)
						{
							operandType[i] = INT_VAR;
						}
						else if (t->children[i]->children[0]->specType.leafType == CHARCONST_LEAF)
						{
							operandType[i] = CHAR_VAR;
						}
						break;
					}
					case MATH_EXPR:
					{
						operandType[i] = INT_VAR;
						break;
					}
					}
					i++;
				}
			//不让它做二元的算术运算
			if (t->nodeAttr.operatorType <= NEGATIVE_OP)
			{
				i = 0;
				while(t->children[i]!=NULL)
				{
					if (operandType[i] == CHAR_VAR)
						cerr << "char as operator!!!!!!!!!!!!!!!!!!!!!!!!!!!!1" << endl;
					i++;
				}
			}
			//逻辑运算左右要匹配
			if (t->nodeAttr.operatorType >= NE_OP&&t->nodeAttr.operatorType <= GE_OP)
			{
				if (operandType[0] != operandType[1])
					cerr << "left type and right type unmatched!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}
		}
		break;
		}
		break;
	}
	case STMT_NODE:
	{
		//赋值之后类型已经设置好，可以类型检查了
		if (this->root->specType.stmtType == DECLARE_STMT)
		{
			Node* b = this->root->children[1];
			while (b != NULL)
			{
				this->type_check(b);
				b = b->sibling;
			}
		}
		break;
	}
	}
}

Node* tree::mkLeaf(LeafType type)
{
	Node *node = new Node;
	node->genType = LEAF_NODE;
	node->specType.leafType = type;

	for (int i = 0; i<MAXCHILDREN; i++)
		node->children[i] = NULL;
	node->sibling = NULL;
	node->lineNumber = lineNumber;

	node->seq = nodeSeq;
	nodeSeq++;
	//似乎可以去掉
	node->symtabSeq=currentSymtab;

	node->begin_label = "";
	node->after_label = "";
	node->true_label = "";
	node->false_label = "";

	root = node;

	get_temp_var(root);

	return node;
}

/*Node* mkArrayLeaf(Node* child1)
{
	Node *node = new Node;
	node->genType = LEAF_NODE;
	node->specType.leafType = ARRAY_LEAF;

	node->children[0]=child1;

	for (int i = 1; i<MAXCHILDREN; i++)
		node->children[i] = NULL;
	node->sibling = NULL;
	node->lineNumber = lineNumber;

	node->seq = nodeSeq;
	nodeSeq++;

	node->symtabSeq=currentSymtab;

	root = node;

	return node;
}*/

Node* tree::mkStmtNode(StmtType type, Node* child1, Node* child2, Node* child3, Node* child4, Node* child5)
{
	Node* node = new Node;
	node->genType = STMT_NODE;
	node->specType.stmtType = type;

	node->children[0] = child1;
	node->children[1] = child2;
	node->children[2] = child3;
	node->children[3] = child4;
	node->children[4] = child5;

	node->sibling = NULL;
	node->lineNumber = lineNumber;

	node->seq = nodeSeq;
	nodeSeq++;

	node->symtabSeq=currentSymtab;

	node->begin_label = "";
	node->after_label = "";
	node->true_label = "";
	node->false_label = "";


	root = node;

	this->type_check(this->root);



	get_temp_var(root);

	return node;
}

Node* tree::mkExprNode(ExprType type, Operator operatorType, Node* child1, Node* child2, Node* child3, Node* child4, Node* child5)
{
	Node* node = new Node;
	node->genType = EXPR_NODE;
	node->specType.exprType = type;

	node->children[0] = child1;
	node->children[1] = child2;
	node->children[2] = child3;
	node->children[3] = child4;
	node->children[4] = child5;

	node->sibling = NULL;
	node->lineNumber = lineNumber;

	node->nodeAttr.operatorType = operatorType;
	node->seq = nodeSeq;
	nodeSeq++;

	node->symtabSeq=currentSymtab;

	node->begin_label = "";
	node->after_label = "";
	node->true_label = "";
	node->false_label = "";

	root = node;

	get_temp_var(root);


	this->type_check(this->root);

	return node;
}

void tree::printTree()
{
	root->printTree();
}

void Node::printTree()
{
	for (int i = 0; children[i] != NULL; i++)
	{
		children[i]->printTree();
		Node* t = children[i]->sibling;
		while (t != NULL)
		{
			t->printTree();
			t = t->sibling;
		}
	}
	cout.setf(ios_base::left);
	cout <<setw(3)<< seq << ": ";
	switch (genType)
	{
	case STMT_NODE:
	{
		string names[] = { "Var Declaration","Compound Statement", "Expression Statement","If Statement","While Statement","For Statement","Void Statement","Output Statement","Input Statement","Break Statement","Continue Statement"};
		cout <<setw(25)<<names[specType.stmtType];
		break;
	}
	case EXPR_NODE:
	{
		cout <<setw(25)<<"Expr"<<setw(2)<<"op:";
		string names[] = { "=","|","^","&","<<",">>","+","-","*","/","%","~","++","--","++","--","-" ,"!=","==","<","<=",">",">=","&&","||","no operator" };
		cout <<setw(18)<<names[nodeAttr.operatorType];
		break;
	}
	case LEAF_NODE:
	{
		switch (specType.leafType)
		{
		case ID_LEAF:
			cout <<setw(25)<< "ID Declaration"<<"symbol:" << setw(13)<< nodeAttr.idEntry;
			break;
		case ARRAY_LEAF:
			cout <<setw(25)<< "Array Declaration"<<"symbol:" <<setw(13)<< nodeAttr.idEntry<<endl; //<<"index:"<<setw(14)<<nodeAttr.arrayIndex;
			break;
		case INTCONST_LEAF:
			cout <<setw(25)<< "Const Declaration:" <<  "value:" << setw(14) << nodeAttr.intValue;
			break;
		case CHARCONST_LEAF:
			cout <<setw(25)<< "Const Declaration:" << "value:"<< setw(14) <<nodeAttr.charValue;
			break;
		case STRINGCONST_LEAF:
			cout <<setw(25)<< "Const Declaration:" << "value:" << setw(14) << nodeAttr.stringValue;
			break;
		case INT_LEAF:
			cout <<setw(25)<< "Type Specifier" <<setw(20) << "integer";
			break;
		case CHAR_LEAF:
			cout <<setw(25)<< "Type Specifier" <<setw(20) << "char";
			break;
		}
	}
	}

	cout << "children: ";
	for (int i = 0; children[i] != NULL; i++)
	{
		cout << children[i]->seq << " ";
		Node* t = children[i]->sibling;
		while (t != NULL)
		{
			cout << t->seq << " ";
			t = t->sibling;
		}
	}
	cout << endl;
}

void tree::get_temp_var(Node* t)
{
	if (t->genType == STMT_NODE)
	{
		t->temp_seq = -1;
		switch (t->specType.stmtType)
		{
		case IF_STMT:
		{
			if (t->children[0]->temp_seq !=-1)
				global_temp_seq--;
			break;
		}
		case WHILE_STMT:
		{
			if (t->children[0]->temp_seq != -1)
				global_temp_seq--;
			break;
		}
		case FOR_STMT:
		{
			if (t->children[1]->temp_seq!=-1)
				global_temp_seq--;
			if (t->children[3] != NULL)
			{
				if (t->children[2]->temp_seq != -1)
				{
					global_temp_seq--;
					break;
				}
			}
			break;
		}
		case EXPR_STMT:
		{
			if (t->children[0]->temp_seq != -1)
				global_temp_seq--;
			break;
		}
		case OUTPUT_STMT:
		{
			Node* b = t->children[0];
			while(b!=NULL)
			{
				if (b->temp_seq != -1)
					global_temp_seq--;
				b = b->sibling;
			}
			break;
		}
		}
	}
	if (t->genType == EXPR_NODE)
	{
		if (t->specType.exprType == MATH_EXPR || t->specType.exprType == ASSIGN_EXPR)
		{
			for (int i = 0; t->children[i] != NULL; i++)
			{
				if (t->children[i]->temp_seq != -1)
				{
					global_temp_seq--;
				}
			}
		}
	}
	if (!(t->genType == EXPR_NODE&&t->specType.exprType == MATH_EXPR))
	{
		t->temp_seq = -1;
		return;
	}
	else
	{
		t->temp_seq = global_temp_seq;
		global_temp_seq++;
		if (global_temp_seq >max_temp_seq)
			max_temp_seq = global_temp_seq;
	}
}

void tree::generate_assembly(Node* t,ostream& out)
{
	//头部代码
	out<<"\t.586"<<endl;
	out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap : none" << endl;

	out << "\tinclude \\masm32\\macros\\macros.asm" << endl<<endl;

	out << "\tinclude    \\masm32\\include\\msvcrt.inc" << endl;
	out << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;

	out << endl << endl << "\t.data" << endl;
	//先遍历符号表生成所有的变量
    for(int i=0;symTab[i].parentSeq!=-1&&i<50;i++)
    {
		for(unordered_map<string, symbolEntry>::iterator iter=symTab[i].hashTable.begin();iter!=symTab[i].hashTable.end();iter++ )
		{
			switch(iter->second.varType)
			{
				case INT_VAR:
				{
					if(iter->second.arraySize==-1)
					{
						out<<"\t\t_"<<iter->first<<"$"<<i<<" DWORD 0"<<endl;
					}
					else
					{
						out<<"\t\t_"<<iter->first<<"$"<<i<<" DWORD 0"<<" DUP("<<iter->second.arraySize<<")"<<endl;
					}
					break;
				}
				case CHAR_VAR:
				{
					if(iter->second.arraySize==-1)
					{
						out<<"\t\t_"<<iter->first<<"$"<<i<<" BYTE 0"<<endl;
					}
					else
					{
						out<<"\t\t_"<<iter->first<<"$"<<i<<" BYTE 0"<<" DUP("<<iter->second.arraySize<<")"<<endl;
					}
					break;
				}
			}
   		 }
    }
	//再生成所有的临时变量
	for(int i=0;i<max_temp_seq;i++)
		out<<"\t\tt"<<i<<" DWORD 0"<<endl;

	 //输入输出，buffer！！！！！！！！！！！？？？？？？？？？？？？？？？

    out << endl << endl << "\t.code" << endl;
	out << "_start:" << endl;

	this->generate_code(t,out);

	//尾部代码
	out << "@end:"<< endl;
	out << "\tinvoke crt__exit, 0" << endl;
	out << "END _start" << endl;
}

void tree::generate_code(Node* t, ostream& out)
{
	switch (t->genType)
	{
	case EXPR_NODE:
	{
		switch (t->specType.exprType)
		{
		case MATH_EXPR:
		{
			t->gen_math_code(out);
			break;
		}
		case ASSIGN_EXPR:
		{
			this->generate_code(t->children[1], out);
			//等号右边可能是，左值，数学表达式，右值，赋值表达式
			ostringstream oss;
			string assign_operand = "";
			string assign_destination = "";
			switch (t->children[1]->specType.exprType)
			{
			case LEFTVALUE_EXPR:
			{
				if (t->children[1]->children[0]->specType.leafType == ID_LEAF)
				{
					oss << t->children[1]->children[0]->symtabSeq;
					assign_operand = "_" + t->children[1]->children[0]->nodeAttr.idEntry + "$" + oss.str();
				}
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				if (t->children[1]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					oss << t->children[1]->children[0]->nodeAttr.intValue;
					assign_operand = oss.str();
				}
				if (t->children[1]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					oss << (int)t->children[1]->children[0]->nodeAttr.charValue;
					assign_operand = oss.str();
				}
				break;
			}
			case MATH_EXPR:
			{
				oss.str("");
				oss << t->children[1]->temp_seq;
				assign_operand = "t" + oss.str();
				break;
			}
			case ASSIGN_EXPR:
			{
				if (t->children[1]->children[0]->specType.leafType == ID_LEAF)
				{
					oss << t->children[1]->children[0]->symtabSeq;
					assign_operand = "_" + t->children[1]->children[0]->nodeAttr.idEntry + "$" + oss.str();
				}
				break;
			}
			}

			VarType operandType;
			if (t->children[0]->specType.leafType == ID_LEAF)
			{
				oss.str("");
				oss << t->children[0]->symtabSeq;
				assign_destination = "_" + t->children[0]->nodeAttr.idEntry + "$" + oss.str();

				operandType=getVarType(symTab[t->children[0]->symtabSeq], t->children[0]->nodeAttr.idEntry);
			}

			if (operandType==CHAR_VAR)
			{
				out << "\tMOV al, " << assign_operand << endl;
				out << "\tMOV " << assign_destination << ", al" << endl << endl;
			}
			else
			{
				out << "\tMOV eax, " << assign_operand << endl;
				out << "\tMOV " << assign_destination << ", eax" << endl << endl;
			}


			break;
		}
		break;
		}
		break;
	}
	case STMT_NODE:
	{

		switch (t->specType.stmtType)
		{
		case FOR_STMT:
		{
			//可能是declare_STMT,expr_STMT,void_STMT
			this->generate_code(t->children[0], out);

			out << t->begin_label << ":" << endl;
			this->generate_code(t->children[1], out);
			
			string condition = "";
			VarType conditionType;
			if(t->children[1]->genType==EXPR_NODE)
				switch (t->children[1]->specType.exprType)
				{
				case MATH_EXPR:
				{
					ostringstream oss;
					oss.str("");
					oss << t->children[1]->temp_seq;
					condition = "t" + oss.str();
					break;
				}
				case LEFTVALUE_EXPR:
				{
					ostringstream oss;
					oss << t->children[1]->children[0]->symtabSeq;
					condition = "_" + t->children[1]->children[0]->nodeAttr.idEntry + "$" + oss.str();

					//char
					conditionType = getVarType(symTab[t->children[1]->children[0]->symtabSeq], t->children[1]->children[0]->nodeAttr.idEntry);
					break;
				}
				case RIGHTVALUE_EXPR:
				{
					ostringstream oss;
					if (t->children[1]->children[0]->specType.leafType == INTCONST_LEAF)
					{
						oss.str("");
						oss << t->children[1]->children[0]->nodeAttr.intValue;
						condition = oss.str();
						conditionType = INT_VAR;
					}
					else if (t->children[1]->children[0]->specType.leafType == CHARCONST_LEAF)
					{
						oss.str("");
						oss << (int)t->children[1]->children[0]->nodeAttr.charValue;
						condition = oss.str();
						conditionType = CHAR_VAR;
					}
					break;
				}
				}

			//处理后增量
			post_handler(out);

			//跳不出来的那种for
			if (t->children[1]->genType == STMT_NODE&&t->children[1]->specType.stmtType == VOID_STMT)
			{
				//可以不跳，自动就是到true的部分了
				//out << "\tjmp" << t->true_label << endl;
			}
			else
			{
				if (conditionType == CHAR_VAR)
				{
					out << "\tMOV al, " << condition << endl;
					out << "\tCMP al" << " ,0" << endl;
				}
				else
				{
					out << "\tMOV eax, " << condition << endl;
					out << "\tCMP eax" << " ,0" << endl;
				}
				out << "\tjne " << t->true_label << endl;
				out << "\tjmp " << t->after_label << endl;
			}

			out << t->true_label << ":" << endl;
			Node* forContent;
			//for有两种语法，一种是for(xx;xx;)的
			if (t->children[3] == NULL)
			{
				forContent = t->children[2];
				this->generate_code(forContent, out);
				if ((t->children[2]->specType.stmtType != COMPOUND_STMT) && (t->children[2]->specType.stmtType != FOR_STMT) && (t->children[2]->specType.stmtType != IF_STMT) && (t->children[2]->specType.stmtType != WHILE_STMT))
				{
					out << "\tjmp " << t->children[2]->after_label << endl;
				}
			}
			else
			{
				forContent = t->children[3];
				this->generate_code(forContent, out);
				out << forContent->after_label << ":" << endl;

				this->generate_code(t->children[2], out);

				//处理后增量
				post_handler(out);

				out << "\tjmp " << t->begin_label << endl;
			}
			out << endl;
			break;
		}
		case IF_STMT:
		{
			this->generate_code(t->children[0], out);

			string condition = "";
			VarType conditionType;
			switch (t->children[0]->specType.exprType)
			{
			case MATH_EXPR:
			{
				ostringstream oss;
				oss.str("");
				oss << t->children[0]->temp_seq;
				condition = "t" + oss.str();
				break;
			}
			case LEFTVALUE_EXPR:
			{
				ostringstream oss;
				oss << t->children[0]->children[0]->symtabSeq;
				condition = "_" + t->children[0]->children[0]->nodeAttr.idEntry + "$" + oss.str();

				//char
				conditionType = getVarType(symTab[t->children[0]->children[0]->symtabSeq], t->children[0]->children[0]->nodeAttr.idEntry);
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				ostringstream oss;
				if (t->children[0]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					oss.str("");
					oss << t->children[0]->children[0]->nodeAttr.intValue;
					condition = oss.str();
					conditionType = INT_VAR;
				}
				else if (t->children[0]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					oss.str("");
					oss << (int)t->children[0]->children[0]->nodeAttr.charValue;
					condition = oss.str();
					conditionType = CHAR_VAR;
				}
				break;
			}
			}

			post_handler(out);
			if (conditionType == CHAR_VAR)
			{
				out << "\tMOV al, " << condition << endl;
				out << "\tCMP al" << " ,0" << endl;
			}
			else
			{
				out << "\tMOV eax, " << condition << endl;
				out << "\tCMP eax" << " ,0" << endl;
			}
			out << "\tjne " << t->true_label << endl;
			if (t->children[2] == NULL)
			{
				out << "\tjmp " << t->after_label << endl;
			}
			else
			{
				out << "\tjmp " << t->false_label << endl;
			}

			out << t->true_label << ":" << endl;

			this->generate_code(t->children[1], out);

			if ((t->children[1]->specType.stmtType != COMPOUND_STMT) && (t->children[1]->specType.stmtType != FOR_STMT) && (t->children[1]->specType.stmtType != IF_STMT) && (t->children[1]->specType.stmtType != WHILE_STMT))
			{
				out << "\tjmp " << t->after_label << endl;
			}

			if (t->children[2] != NULL)
			{
				out << t->false_label << ":" << endl;

				this->generate_code(t->children[2], out);

				if ((t->children[2]->specType.stmtType != COMPOUND_STMT) && (t->children[2]->specType.stmtType != FOR_STMT) && (t->children[2]->specType.stmtType != IF_STMT) && (t->children[2]->specType.stmtType != WHILE_STMT))
				{
					out << "\tjmp " << t->after_label << endl;
				}
			}
			break;
		}
		case WHILE_STMT:
		{
			out << t->begin_label << ":" << endl;
			this->generate_code(t->children[0], out);

			string condition = "";
			VarType conditionType;
			switch (t->children[0]->specType.exprType)
			{
			case MATH_EXPR:
			{
				ostringstream oss;
				oss.str("");
				oss << t->children[0]->temp_seq;
				condition = "t" + oss.str();
				break;
			}
			case LEFTVALUE_EXPR:
			{
				ostringstream oss;
				oss << t->children[0]->children[0]->symtabSeq;
				condition = "_" + t->children[0]->children[0]->nodeAttr.idEntry + "$" + oss.str();

				//char
				conditionType = getVarType(symTab[t->children[0]->children[0]->symtabSeq], t->children[0]->children[0]->nodeAttr.idEntry);
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				ostringstream oss;
				if (t->children[0]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					oss.str("");
					oss << t->children[0]->children[0]->nodeAttr.intValue;
					condition = oss.str();
					conditionType = INT_VAR;
				}
				else if (t->children[0]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					oss.str("");
					oss << (int)t->children[0]->children[0]->nodeAttr.charValue;
					condition = oss.str();
					conditionType = CHAR_VAR;
				}
				break;
			}
			}

			//处理后增量
			post_handler(out);

			if (conditionType == CHAR_VAR)
			{
				out << "\tMOV al, " << condition << endl;
				out << "\tCMP al" << " ,0" << endl;
			}
			else
			{
				out << "\tMOV eax, " << condition << endl;
				out << "\tCMP eax" << " ,0" << endl;
			}
			out << "\tje " << t->after_label << endl;

			this->generate_code(t->children[1], out);
			if ((t->children[1]->specType.stmtType != COMPOUND_STMT) && (t->children[1]->specType.stmtType != FOR_STMT) && (t->children[1]->specType.stmtType != IF_STMT) && (t->children[1]->specType.stmtType != WHILE_STMT))
			{
				out << "\tjmp " << t->begin_label << endl;
			}
			break;
		}
		case COMPOUND_STMT:
		{
			Node* b = t->children[0];
			if (b == NULL)
			{
				out << "\tjmp " << t->after_label << endl;
			}
			while (b != NULL)
			{
				this->generate_code(b, out);

				//如果不是最后一个节点
				if (b->sibling != NULL)
				{
					if (b->specType.stmtType == COMPOUND_STMT || b->specType.stmtType == FOR_STMT || b->specType.stmtType == IF_STMT || b->specType.stmtType == WHILE_STMT)
					{
						out << b->after_label << ":" << endl;
					}
				}
				//对于最后一个节点
				else
				{
					if (!(b->specType.stmtType == COMPOUND_STMT || b->specType.stmtType == FOR_STMT || b->specType.stmtType == IF_STMT || b->specType.stmtType == WHILE_STMT))
					{
						out << "\tjmp " << t->after_label << endl;
					}
				}
				b = b->sibling;
			}
			break;
		}
		case EXPR_STMT:
		{
			this->generate_code(t->children[0], out);

			post_handler(out);

			break;
		}
		case DECLARE_STMT:
		{
			Node* b = t->children[1];
			while (b != NULL)
			{
				//赋值表达式
				if (b->genType == EXPR_NODE)
					this->generate_code(b, out);
				b = b->sibling;
			}
			break;
		}
		case OUTPUT_STMT:
		{

			//注意，这可能要每输出一个兄弟都handle一次
			Node* b = t->children[0];
			while (b != NULL)
			{
				this->generate_code(b,out);

				switch (b->genType)
				{
				case LEAF_NODE:
				{
					if (b->specType.leafType == STRINGCONST_LEAF)
					{
						out << "\tinvoke crt_printf, SADD(\"";
						out << b->nodeAttr.stringValue;
						out<<"\", 13, 10)" << endl;
					}
					break;
				}
				case EXPR_NODE:
				{
					switch (b->specType.exprType)
					{
					case MATH_EXPR:
					{
						ostringstream oss;
						oss.str("");
						oss << b->temp_seq;
						out << "\tinvoke crt_printf, SADD(\"%d\", 13, 10), " << "t" << oss.str() << endl;
						break;
					}
					case LEFTVALUE_EXPR:
					{
						switch (getVarType(symTab[b->children[0]->symtabSeq], b->children[0]->nodeAttr.idEntry))
						{
						case INT_VAR:
						{
							ostringstream oss;
							oss.str("");
							oss << b->children[0]->symtabSeq;
							out << "\tinvoke crt_printf, SADD(\"%d\", 13, 10), _" << b->children[0]->nodeAttr.idEntry << "$" + oss.str() << endl;
							break;
						}
						case CHAR_VAR:
						{
							ostringstream oss;
							oss.str("");
							oss << b->children[0]->symtabSeq;
							out << "\tinvoke crt_printf, SADD(\"%c\", 13, 10), _" << b->children[0]->nodeAttr.idEntry << "$" + oss.str() << endl;
							break;
						}
						}
						break;
					}
					case RIGHTVALUE_EXPR:
					{
						switch (b->children[0]->specType.leafType)
						{
						case CHARCONST_LEAF:
						{
							out << "\tinvoke crt_printf, SADD(\"";
							out << b->children[0]->nodeAttr.charValue;
							out << "\", 13, 10)" << endl;
							break;
						}
						case INTCONST_LEAF:
						{
							out << "\tinvoke crt_printf, SADD(\"";
							out << b->children[0]->nodeAttr.intValue;
							out << "\", 13, 10)" << endl;
							break;
						}
						}
						break;
					}
					}
					break;
				}
				}
				post_handler(out);
				b = b->sibling;
			}


			post_handler(out);
			break;
		}
		case INPUT_STMT:
		{
			//chidren[0]是一串穿起来的ID_LEAF
			Node* b = t->children[0];
			while (b != NULL)
			{
				switch (getVarType(symTab[b->symtabSeq], b->nodeAttr.idEntry))
				{
				case INT_VAR:
				{
					ostringstream oss;
					oss.str("");
					oss << b->symtabSeq;
					out << "\tinvoke crt_scanf, SADD(\"%d\", 0), addr _"<<b->nodeAttr.idEntry << "$" + oss.str()<< endl;
					break;
				}
				case CHAR_VAR:
				{
					ostringstream oss;
					oss.str("");
					oss << b->symtabSeq;
					out << "\tinvoke crt_scanf, SADD(\"%c\", 0), addr _" << b->nodeAttr.idEntry << "$" + oss.str() << endl;
					break;
				}
				}
				b = b->sibling;
			}
			break;
		}
		}
		break;
	}
	}
}

void Node::gen_math_code(ostream& out)
{
	if (specType.exprType == LEFTVALUE_EXPR || specType.exprType == RIGHTVALUE_EXPR)
		return;

	for (int i = 0; children[i] != NULL; i++)
	{
		children[i]->gen_math_code(out);
	}
	//先获取出操作数的名字，以及表达式结果要存储的变量
	string operand[2]={"",""};
	string result;
	ostringstream oss;
	for (int i = 0; children[i] != NULL; i++)
	{
		//专门解决++--因为增量的孩子直接是左值
		if (children[i]->genType == LEAF_NODE)
		{
			if (nodeAttr.operatorType == PRE_MINUSMINUS_OP || nodeAttr.operatorType == PRE_PLUSPLUS_OP || nodeAttr.operatorType == POST_MINUSMINUS_OP || nodeAttr.operatorType == POST_PLUSPLUS_OP)
			{
				oss.str("");
				oss << children[i]->symtabSeq;
				operand[i] = "_" + children[i]->nodeAttr.idEntry + "$" + oss.str();
			}
		}
		else
			switch (children[i]->specType.exprType)
			{
			case LEFTVALUE_EXPR:
			{
				if (children[i]->children[0]->specType.leafType == ID_LEAF)
				{
					oss.str("");
					oss << children[i]->children[0]->symtabSeq;
					operand[i] = "_" + children[i]->children[0]->nodeAttr.idEntry + "$" + oss.str();
				}
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				if (children[i]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					oss.str("");
					oss << children[i]->children[0]->nodeAttr.intValue;
					operand[i] = oss.str();
				}
				else if (children[i]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					oss.str("");
					oss << (int)children[i]->children[0]->nodeAttr.charValue;
					operand[i] = oss.str();
				}
				break;
			}
			case MATH_EXPR:
			{
				oss.str("");
				oss << children[i]->temp_seq;
				operand[i] = "t" + oss.str();
				break;
			}
			//注意：赋值表达式不会出现在math_expr这边
			}
	}

	int operandType[2];
	//判断一下是不是char型的
	for (int i = 0; children[i]!=NULL; i++)
	{
		if (nodeAttr.operatorType >= NE_OP&&nodeAttr.operatorType <= OR_OP)
		{
			switch (children[i]->specType.exprType)
			{
			case LEFTVALUE_EXPR:
			{
				operandType[i] = getVarType(symTab[children[i]->children[0]->symtabSeq], children[i]->children[0]->nodeAttr.idEntry);
				break;
			}
			case RIGHTVALUE_EXPR:
			{
				if (children[i]->children[0]->specType.leafType == INTCONST_LEAF)
				{
					operandType[i] = INT_VAR;
				}
				else if (children[i]->children[0]->specType.leafType == CHARCONST_LEAF)
				{
					operandType[i] = CHAR_VAR;
				}
				break;
			}
			case MATH_EXPR:
			{
				operandType[i] = INT_VAR;
				break;
			}
			}
		}
	}

	oss.str("");
	oss<<temp_seq;
	result="t"+oss.str();

	switch(nodeAttr.operatorType)
	{
		case BOR_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tOR eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case BXOR_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tXOR eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case BAND_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tAND eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case LSHIFT_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tSHL eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case RSHIFT_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tSHR eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case ADD_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tADD eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case SUB_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tSUB eax, "<<operand[1]<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case MUL_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tMOV ebx, "<<operand[1]<<endl;
			out<<"\tMUL ebx"<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case DIV_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tMOV ebx, "<<operand[1]<<endl;
			out<<"\tDIV ebx"<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case MOD_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tMOV ebx, "<<operand[1]<<endl;
			out<<"\tMOD ebx"<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case BNOT_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tNOT eax"<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}
		case PRE_PLUSPLUS_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tINC eax"<<endl;
			out<<"\tMOV "<<operand[0]<<", eax"<<endl;

			out << "\tMOV eax" << operand[0] << endl;
			out << "\tMOV " << result << ", eax" << endl;
			break;
		}
		case PRE_MINUSMINUS_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tDEC eax"<<endl;
			out << "\tMOV " << operand[0] << ", eax" << endl;

			out << "\tMOV eax" << operand[0] << endl;
			out << "\tMOV " << result << ", eax" << endl;
			break;
		}
		case POST_PLUSPLUS_OP:
		{
			out << "\tMOV eax, " << operand[0] << endl;
			out << "\tMOV " << result << " ,eax" << endl;
			post_plus_unhandled.push(operand[0]);
			break;
		}
		case POST_MINUSMINUS_OP:
		{
			out << "\tMOV eax, " << operand[0] << endl;
			out << "\tMOV " << result << " ,eax" << endl;
			post_minus_unhandled.push(operand[0]);
			break;
		}
		case NEGATIVE_OP:
		{
			out<<"\tMOV eax, "<<operand[0]<<endl;
			out<<"\tNEG eax"<<endl;
			out<<"\tMOV "<<result<<", eax"<<endl;
			break;
		}

		case NE_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label = new_temp_label();
			string logic_false_label = new_temp_label();
			out << "\tjne " << logic_true_label << endl;

			out << "\tMOV " << result << ", 0" << endl;
			out << "\tjmp " << logic_false_label << endl;
			out << logic_true_label << ":" << endl;
			out << "\tMOV " << result << ", 1" << endl;
			out << logic_false_label << ":" << endl;

			break;
		}
		case EQ_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label = new_temp_label();
			string logic_false_label = new_temp_label();
			out << "\tje " << logic_true_label << endl;

			out << "\tMOV " << result << ", 0" << endl;
			out << "\tjmp " << logic_false_label << endl;
			out << logic_true_label << ":" << endl;
			out << "\tMOV " << result << ", 1" << endl;
			out << logic_false_label << ":" << endl;

			break;
		}
		case LT_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label = new_temp_label();
			string logic_false_label = new_temp_label();
			out << "\tjl " << logic_true_label << endl;

			out << "\tMOV " << result << ", 0" << endl;
			out << "\tjmp " << logic_false_label << endl;
			out << logic_true_label << ":" << endl;
			out << "\tMOV " << result << ", 1" << endl;
			out << logic_false_label << ":" << endl;

			break;
		}
		case LE_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label = new_temp_label();
			string logic_false_label = new_temp_label();
			out << "\tjle " << logic_true_label << endl;

			out << "\tMOV " << result << ", 0" << endl;
			out << "\tjmp " << logic_false_label << endl;
			out << logic_true_label << ":" << endl;
			out << "\tMOV " << result << ", 1" << endl;
			out << logic_false_label << ":" << endl;

			break;
		}
		case GT_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label = new_temp_label();
			string logic_false_label = new_temp_label();
			out << "\tjg " << logic_true_label << endl;

			out << "\tMOV " << result << ", 0" << endl;
			out << "\tjmp " << logic_false_label << endl;
			out << logic_true_label << ":" << endl;
			out << "\tMOV " << result << ", 1" << endl;
			out << logic_false_label << ":" << endl;

			break;
		}
		case GE_OP:
		{
			if (operandType[0] == CHAR_VAR)
			{
				out << "\tMOV al, " << operand[0] << endl;
				out << "\tCMP al, " << operand[1] << endl;
			}
			else
			{
				out << "\tMOV eax, " << operand[0] << endl;
				out << "\tCMP eax, " << operand[1] << endl;
			}

			string logic_true_label=new_temp_label();
			string logic_false_label=new_temp_label();
			out<<"\tjge "<<logic_true_label<<endl;

			out<<"\tMOV "<<result<<", 0"<<endl; 
			out<<"\tjmp "<<logic_false_label<<endl;
			out << logic_true_label << ":" << endl;
			out<<"\tMOV "<<result<<", 1"<<endl;
			out<<logic_false_label<<":"<<endl;

			break;
		}
		case AND_OP:
		{
			string logic_true_label=new_temp_label();
			string logic_false_label=new_temp_label();

			string reg[2];
			for (int i = 0; i < 2; i++)
			{
				if (operandType[i] == CHAR_VAR)
					reg[i] = "al";
				else
					reg[i] = "eax";
			}

			out<<"\tMOV "<<reg[0]<<", "<<operand[0]<<endl;
			out<<"\tCMP "<<reg[0]<<", 0"<<endl;
			out<<"\tje "<<logic_false_label<<endl;
			out<<"\tMOV "<<reg[1]<<", "<<operand[1]<<endl;
			out<<"\tCMP "<<reg[1]<<", 0"<<endl;
			out<<"\tje "<<logic_false_label<<endl;

			out<<"\tMOV "<<result<<", 1"<<endl; 
			out<<"\tjmp "<<logic_true_label<<endl;

			out << logic_false_label <<":"<< endl;
			out<<"\tMOV "<<result<<", 0"<<endl;
			out << logic_true_label << ":" << endl;

			break;
		}
		case OR_OP:
		{
			string logic_true_label=new_temp_label();
			string logic_false_label=new_temp_label();

			string reg[2];
			for (int i = 0; i < 2; i++)
			{
				if (operandType[i] == CHAR_VAR)
					reg[i] = "al";
				else
					reg[i] = "eax";
			}

			out << "\tMOV " << reg[0] << ", " <<operand[0]<<endl;
			out << "\tCMP " << reg[0] << ", 0" << endl;
			out<<"\tjne "<<logic_true_label<<endl;
			out << "\tMOV " << reg[1] << ", " << operand[1] << endl;
			out << "\tCMP " << reg[1] << ", 0" << endl;
			out<<"\tjne "<<logic_true_label<<endl;

			out<<"\tMOV "<<result<<", 0"<<endl; 
			out<<"\tjmp "<<logic_false_label<<endl;

			out<<logic_true_label<<":"<<endl<<"\tMOV "<<result<<", 1"<<endl;
			out<<logic_false_label<<":"<<endl;
			break;
		}
	}
}




void tree::generate_label(Node* t)
{
	//main的复合语句的after
	if (t == parseTree.root)
		t->after_label = "@end";


	if (t->genType != STMT_NODE)
		return;
	switch (t->specType.stmtType)
	{
	case FOR_STMT:
	{
		t->begin_label = new_label();
		t->true_label = new_label();
		Node* forContent;

		//for有两种语法，一种是for(xx;xx;)的
		if (t->children[3] == NULL)
		{
			forContent = t->children[2];
			forContent->after_label = t->begin_label;
		}
		else
		{
			forContent = t->children[3];
			forContent->after_label = new_label();
		}
		this->generate_label(t->children[0]);
		this->generate_label(t->children[1]);
		this->generate_label(t->children[2]);
		if (t->children[3] != NULL)
			this->generate_label(t->children[3]);

		break;
	}
	case IF_STMT:
	{
		t->true_label = new_label();
		t->children[1]->after_label = t->after_label;

		if (t->children[2] != NULL)
		{
			t->false_label = new_label();
			t->children[2]->after_label = t->after_label;
		}

		this->generate_label(t->children[0]);
		this->generate_label(t->children[1]);
		if(t->children[2]!=NULL)
			this->generate_label(t->children[2]);
		break;
	}
	case WHILE_STMT:
	{
		t->begin_label = new_label();
		t->children[1]->after_label = t->begin_label;
		this->generate_label(t->children[0]);
		this->generate_label(t->children[1]);
		break;
	}
	case COMPOUND_STMT:
	{
		Node* b = t->children[0];
		while (b != NULL)
		{
			//如果不是最后一个节点
			if (b->sibling != NULL)
			{
				if (b->specType.stmtType == COMPOUND_STMT || b->specType.stmtType == FOR_STMT || b->specType.stmtType == IF_STMT || b->specType.stmtType == WHILE_STMT)
				{
					b->after_label = new_label();
				}
			}
			//对于最后一个节点
			else
			{
				if (b->specType.stmtType == COMPOUND_STMT || b->specType.stmtType == FOR_STMT || b->specType.stmtType == IF_STMT || b->specType.stmtType == WHILE_STMT)
				{
					b->after_label = t->after_label;
				}
			}

			this->generate_label(b);
			b = b->sibling;
		}
		break;
	}
	}
}

