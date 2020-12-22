%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2017??§o12??8?§?§?
****************************************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
#include "mylexer.h"
#include "C:\Users\zhouyuhan\source\repos\ConsoleApplication8\ConsoleApplication8\symbol.h"
#include "C:\Users\zhouyuhan\source\repos\ConsoleApplication8\ConsoleApplication8\tree.h"

using namespace std;
extern symbolTable* symTab;
extern int currentSymtab;
extern tree parseTree;
extern int nodeSeq;
extern int lineNumber;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
    // place any extra class members here
}

// constructor
{
    // place any extra initialisation code here
}

// destructor
{
    // place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE Node*
#endif
}

// place any declarations here

%token INT CHAR INTCONST CHARCONST STRINGCONST ID
%token IF ELSE WHILE FOR INPUT OUTPUT BREAK CONTINUE MAIN
%token COMMA SEMIC ASSIGN OR AND BOR BXOR BAND NE EQ LT LE GT GE LSHIFT RSHIFT ADD SUB MUL DIV MOD BNOT PLUSPLUS MINUSMINUS
%token LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK

%right ASSIGN
%left OR
%left AND
%left BOR
%left BXOR
%left BAND
%left NE EQ
%left LT LE GT GE
%left LSHIFT RSHIFT
%left ADD SUB
%left MUL DIV MOD
%right UMINUS
%right BNOT
%right PLUSPLUS MINUSMINUS

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

main_function   :   MAIN LPAREN RPAREN compound_stmt
                    {
                        $$=$4;
                    }
                ;

compound_stmt   :   LBRACE stmt_list RBRACE
                    {
                        $$=parseTree.mkStmtNode(COMPOUND_STMT,$2);
                    }
                |   LBRACE RBRACE
                    {
                        $$=parseTree.mkStmtNode(COMPOUND_STMT);
                    }
                ;

stmt_list       :   stmt
                    {
                        $$=$1;
                    }
                |    stmt_list stmt
                    {
                        Node* t=$1;
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=$2;
                        $$=$1;
                    }
                ;
input_operand   :   RSHIFT left_value
                    {
                        $$=$2;
                    }
                ;

input_list      :   INPUT input_operand
                    {
                        $$=$2;
                    }
                |   input_list input_operand
                    {
                        Node* t=$1;
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=$2;
                        $$=$1;
                    }
                ;

input_stmt      :   input_list SEMIC
                    {
                        $$=parseTree.mkStmtNode(INPUT_STMT,$1);
                    }
                ;

output_operand  :   LSHIFT STRINGCONST
                    {
                        parseTree.mkLeaf(STRINGCONST_LEAF);
                        parseTree.root->nodeAttr.stringValue=$2->nodeAttr.stringValue.substr(1,$2->nodeAttr.stringValue.length()-2);
                        $$=parseTree.root;                        
                    }
                |   LSHIFT math_expr
                    {
                        $$=$2;
                    }
                ;

output_list     :   OUTPUT output_operand
                    {
                        $$=$2;
                    }
                |   output_list output_operand
                    {
                        Node* t=$1;
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=$2;
                        $$=$1;
                    }
                ;
output_stmt     :   output_list SEMIC
                    {
                        $$=parseTree.mkStmtNode(OUTPUT_STMT,$1); 
                    }
                ;

stmt            :   declare_stmt
                    {
                        $$=$1;
                    }
                |   compound_stmt
                    {
                        $$=$1;
                    }
                |   expr_stmt
                    {
                        $$=$1;
                    }
                |   if_stmt
                    {
                        $$=$1;
                    }
                |   while_stmt
                    {
                        $$=$1;
                    }
                |   for_stmt
                    {
                        $$=$1;
                    }
                |   void_stmt
                    {
                        $$=$1;
                    }
                |   input_stmt
                    {
                        $$=$1;
                    }
                |   output_stmt
                    {
                        $$=$1;
                    }
                |   break_stmt
                    {
                        $$=$1;
                    }
                |   continue_stmt
                    {
                        $$=$1;
                    }
                ;

id              :   ID
                    {
                        parseTree.mkLeaf(ID_LEAF);
                        parseTree.root->nodeAttr.idEntry=$1->nodeAttr.idEntry;
                        $$=parseTree.root;
                    }
                ;

/*array_element   :   ID LBRACK math_expr RBRACK
                    {
  
                        parseTree.mkArrayLeaf($3);
                        parseTree.root->nodeAttr.idEntry=$1->nodeAttr.idEntry;
                        $$=parseTree.root;                        
                    }
                ;     */

left_value      :   id
                    {
                        //新添代码：检查是否已经插入符号表
                        int checkSymtab=currentSymtab;
                        
                        while(true)
                        {

                            if(symTab[checkSymtab].lookup($1->nodeAttr.idEntry)!=NULL)
                            {
                                //设置符号表编号
                                $1->symtabSeq=checkSymtab;
                                break;
                            }
                            if(checkSymtab==0&&symTab[checkSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            {
								cerr<<"未声明就使用的变量！"<<endl;
								break;
							}
                            checkSymtab=symTab[checkSymtab].parentSeq;
                        }

                        $$=$1;
                    }

               /* |   array_element
                    {
                        //新添代码：检查是否已经插入符号表
                        int checkSymtab=currentSymtab;
                        while(checkSymtab!=-1)
                        {
                            if(symTab[checkSymtab].lookup($1->nodeAttr.idEntry)!=NULL)
                                break;
                            else
                                checkSymtab=symTab[checkSymtab].parentSeq;
                        }
                        if(checkSymtab==-1)
                            cerr<<"未声明就使用的变量！";
                        $$=$1;                     
                    }*/
                ;

right_value     :   CHARCONST
                    {
                        parseTree.mkLeaf(CHARCONST_LEAF);
                        parseTree.root->nodeAttr.charValue=$1->nodeAttr.charValue;
                        $$=parseTree.root;
                    }

                |   INTCONST
                    {
                        parseTree.mkLeaf(INTCONST_LEAF);
                        parseTree.root->nodeAttr.intValue=$1->nodeAttr.intValue;
                        $$=parseTree.root;
                    }
                ;

expr            :   math_expr
                    {
                        $$=$1;
                    }
                |   assign_expr
                    {
                        $$=$1;
                    }
                ;

math_expr       :   left_value
                    {
                        $$=parseTree.mkExprNode(LEFTVALUE_EXPR,NO_OP,$1);
                    }
                |   right_value
                    {
                        $$=parseTree.mkExprNode(RIGHTVALUE_EXPR,NO_OP,$1);
                    }
                |   math_expr BOR math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,BOR_OP,$1,$3);
                    }
                |   math_expr BXOR math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,BXOR_OP,$1,$3);
                    }         
                |   math_expr BAND math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,BAND_OP,$1,$3);
                    } 
                |   math_expr NE math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,NE_OP,$1,$3);
                    }
                |   math_expr EQ math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,EQ_OP,$1,$3);
                    }
                |   math_expr LT math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,LT_OP,$1,$3);
                    }
                |   math_expr LE math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,LE_OP,$1,$3);
                    }
                |   math_expr GT math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,GT_OP,$1,$3);
                    }
                |   math_expr GE math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,GE_OP,$1,$3);
                    }
                |   math_expr LSHIFT math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,LSHIFT_OP,$1,$3);
                    } 
                |   math_expr RSHIFT math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,RSHIFT_OP,$1,$3);
                    } 
                |   math_expr ADD math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,ADD_OP,$1,$3);
                    } 
                |   math_expr SUB math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,SUB_OP,$1,$3);
                    } 
                |   math_expr MUL math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,MUL_OP,$1,$3);
                    } 
                |   math_expr DIV math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,DIV_OP,$1,$3);
                    } 
                |   math_expr MOD math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,MOD_OP,$1,$3);
                    }
                |   BNOT math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,BNOT_OP,$1,$3);
                    }
                |   left_value PLUSPLUS
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,POST_PLUSPLUS_OP,$1);
                    }
                |   left_value MINUSMINUS
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,POST_MINUSMINUS_OP,$1);
                    }
                |   PLUSPLUS left_value
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,PRE_PLUSPLUS_OP,$2);
                    }
                |   MINUSMINUS left_value
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,PRE_MINUSMINUS_OP,$2);
                    }
                |   SUB math_expr %prec UMINUS
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,NEGATIVE_OP,$2);
                    }
                |   math_expr AND math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,AND_OP,$1,$3);
                    }
                |   math_expr OR math_expr
                    {
                        $$=parseTree.mkExprNode(MATH_EXPR,OR_OP,$1,$3);
                    }
                |   LPAREN math_expr RPAREN
                    {
                        $$=$2;
                    }
                ;

assign_expr     :   left_value ASSIGN math_expr
                    {
                        $$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
                    }

                |   left_value ASSIGN assign_expr
                    {
                        $$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
                    }
                ;

expr_stmt       :   expr SEMIC
                    {
                        $$=parseTree.mkStmtNode(EXPR_STMT,$1);
                    }
                ;

declare         :   id
                    {
                        //新添代码：插入符号表
                        //只需要当前作用域没有该符号即可
                        if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                        else
                            cerr<<$1->nodeAttr.idEntry<<"变量重定义！"<<endl;
                            
                        $$=$1;
                    }
				|	id ASSIGN assign_expr
					{
					    //插入

                        if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                        else
							cerr<<"重定义"<<endl;
                            
						$$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
					
					}
				|	id ASSIGN math_expr
					{
						//插入
						
						if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                         else
							cerr<<"重定义"<<endl;
                            
						 $$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
					}

              /*  |   ID LBRACK INTCONST RBRACK
                    {
                        // 数组的声明

                        //新添代码：插入符号表

                        //只需要当前作用域没有该符号即可
                        if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                        else
                            cerr<<"变量重定义！";

                        setArraySize(symTab[currentSymtab],$1->nodeAttr.idEntry,$3->intValue);
                        $$=$1;
                    }*/

               /* 
               因为去除了数组的影响，所以这里可以 不用分开写了
               |   id ASSIGN math_expr
                    {
                        //新添代码：插入符号表
                        //只需要当前作用域没有该符号即可
                        if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                        else
                            cerr<<"变量重定义！";

                        $$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
                    }
                |   id ASSIGN assign_expr
                    {
                        //新添代码：插入符号表
                        //只需要当前作用域没有该符号即可
                        if(symTab[currentSymtab].lookup($1->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert($1->nodeAttr.idEntry);
                        else
                            cerr<<"变量重定义！";

                        $$=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,$1,$3);
                    }*/
                ;

declare_list    :   declare
                    {
                        $$=$1;
                    }
                |   declare_list COMMA declare
                    {
                        Node* t=$1;
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=$3;
                        $$=$1;
                    }
                ;

type_specifier  :   INT
                    {
                        $$=parseTree.mkLeaf(INT_LEAF);
                    }
                |   CHAR
                    {
                        $$=parseTree.mkLeaf(CHAR_LEAF);
                    }
                ;

declare_stmt    :   type_specifier declare_list SEMIC
                    {
                        Node* t=$2;
                        while(t!=NULL)
                        {
                            if(t->specType.exprType==ASSIGN_EXPR)
                            {
                                switch($1->specType.leafType)
                                {
                                    case INT_LEAF:
                                    setVarType(symTab[currentSymtab],t->children[0]->nodeAttr.idEntry,INT_VAR);
                                    break;
                                    case CHAR_LEAF:
                                    setVarType(symTab[currentSymtab],t->children[0]->nodeAttr.idEntry,CHAR_VAR);
                                    break;
                                }
                            }
                            else
                            {
                                switch($1->specType.leafType)
                                {
                                    case INT_LEAF:
                                    setVarType(symTab[currentSymtab],t->nodeAttr.idEntry,INT_VAR);
                                    break;
                                    case CHAR_LEAF:
                                    setVarType(symTab[currentSymtab],t->nodeAttr.idEntry,CHAR_VAR);
                                    break;
                                }
                            }
                            t=t->sibling;
                        }
                        $$=parseTree.mkStmtNode(DECLARE_STMT,$1,$2);
                    }
                ;

onlyif_stmt     :   IF LPAREN math_expr RPAREN stmt
                    {
                        currentSymtab=symTab[currentSymtab].parentSeq;
                        $$=parseTree.mkStmtNode(IF_STMT,$3,$5);
                    }
                ;

ifelse_stmt     :   onlyif_stmt ELSE stmt
                    {
                        currentSymtab=symTab[currentSymtab].parentSeq;
                        $1->children[2]=$3;
                        $$=$1;
                    }
                ;

if_stmt         :   onlyif_stmt
                    {
                        $$=$1;
                    }
                |   ifelse_stmt
                    {
                        $$=$1;
                    }
                ;

while_stmt      :   WHILE LPAREN math_expr RPAREN stmt 
                    {
                        currentSymtab=symTab[currentSymtab].parentSeq;
                        $$=parseTree.mkStmtNode(WHILE_STMT,$3,$5);
                    }
                ;

for_initializer :   declare_stmt
                    {
                        $$=$1;
                    }
                |   expr_stmt
                    {
                        $$=$1;
                    }
                |   void_stmt
                    {
                        $$=$1;
                    }
                ;

for_condition   :   math_expr SEMIC
                    {
                        $$=$1;
                    }
                |   void_stmt
                    {
                        $$=$1;
                    }
                ;


for_stmt        :   FOR LPAREN for_initializer for_condition expr RPAREN stmt
                    {
                        currentSymtab=symTab[currentSymtab].parentSeq;
                        $$=parseTree.mkStmtNode(FOR_STMT,$3,$4,$5,$7);
                    }
                |   FOR LPAREN for_initializer for_condition RPAREN stmt
                    {
                        currentSymtab=symTab[currentSymtab].parentSeq;
                        $$=parseTree.mkStmtNode(FOR_STMT,$3,$4,$6);
                    }
                ;

void_stmt       :   SEMIC
                    {
                        $$=parseTree.mkStmtNode(VOID_STMT);
                    }
                ;
break_stmt      :   BREAK SEMIC
                    {
                        $$=parseTree.mkStmtNode(BREAK_STMT);
                    }
                ;
continue_stmt   :   CONTINUE SEMIC
                    {
                        $$=parseTree.mkStmtNode(CONTINUE_STMT);
                    }
                ;            


%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(int argc, char *argv[])
{
    int n = 1;
    mylexer lexer;
    myparser parser;
    if (parser.yycreate(&lexer)) {
        if (lexer.yycreate(&parser)) {
            if(argc>2)
            {
                lexer.yyin=new ifstream(argv[1]);
                lexer.yyout=new ofstream(argv[2]);
            }
            else
            {
                lexer.yyin=new ifstream("Text.txt");
                lexer.yyout=new ofstream("Result.txt");
            }
            if((!lexer.yyin->fail())&&(!lexer.yyout->fail()))
            {
                 n = parser.yyparse();
                parseTree.printTree();
                 parseTree.generate_label(parseTree.root);
                 parseTree.generate_assembly(parseTree.root,*lexer.yyout);
                 for(int i=0;symTab[i].parentSeq!=-1&&i<50;i++)
                 {
                     cout<<"-----------------------------------------\n";
                     cout<<"table"<<i<<"    parent table:"<<symTab[i].parentSeq<<endl;;
                     symTab[i].printTable();
                 }
            }
            else
                cout<<"invalid file!";
        
        }
    }
    return n;
}
