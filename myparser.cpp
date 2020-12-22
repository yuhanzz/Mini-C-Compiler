/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 69 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 01/07/18
* Time: 10:32:53
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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

#line 60 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 35 ".\\myparser.y"

    // place any extra initialisation code here

#line 84 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 40 ".\\myparser.y"

    // place any extra cleanup code here

#line 98 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 81 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);
                    
#line 210 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 87 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(COMPOUND_STMT,yyattribute(2 - 3));
                    
#line 225 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 91 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(COMPOUND_STMT);
                    
#line 240 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 97 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 255 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 101 ".\\myparser.y"

                        Node* t=yyattribute(1 - 2);
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=yyattribute(2 - 2);
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
                    
#line 274 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 110 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
                    
#line 289 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 116 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
                    
#line 304 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 120 ".\\myparser.y"

                        Node* t=yyattribute(1 - 2);
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=yyattribute(2 - 2);
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
                    
#line 323 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 130 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(INPUT_STMT,yyattribute(1 - 2));
                    
#line 338 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 136 ".\\myparser.y"

                        parseTree.mkLeaf(STRINGCONST_LEAF);
                        parseTree.root->nodeAttr.stringValue=yyattribute(2 - 2)->nodeAttr.stringValue.substr(1,yyattribute(2 - 2)->nodeAttr.stringValue.length()-2);
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.root;                        
                    
#line 355 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 142 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
                    
#line 370 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 148 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
                    
#line 385 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 152 ".\\myparser.y"

                        Node* t=yyattribute(1 - 2);
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=yyattribute(2 - 2);
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
                    
#line 404 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 161 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(OUTPUT_STMT,yyattribute(1 - 2)); 
                    
#line 419 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 167 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 434 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 171 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 449 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 175 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 464 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 479 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 183 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 494 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 187 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 509 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 191 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 524 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 195 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 539 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 199 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 554 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 203 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 569 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 207 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 584 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\myparser.y"

                        parseTree.mkLeaf(ID_LEAF);
                        parseTree.root->nodeAttr.idEntry=yyattribute(1 - 1)->nodeAttr.idEntry;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.root;
                    
#line 601 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 230 ".\\myparser.y"

                        //新添代码：检查是否已经插入符号表
                        int checkSymtab=currentSymtab;
                        
                        while(true)
                        {

                            if(symTab[checkSymtab].lookup(yyattribute(1 - 1)->nodeAttr.idEntry)!=NULL)
                            {
                                //设置符号表编号
                                yyattribute(1 - 1)->symtabSeq=checkSymtab;
                                break;
                            }
                            if(checkSymtab==0&&symTab[checkSymtab].lookup(yyattribute(1 - 1)->nodeAttr.idEntry)==NULL)
                            {
								cerr<<"未声明就使用的变量！"<<endl;
								break;
							}
                            checkSymtab=symTab[checkSymtab].parentSeq;
                        }

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 636 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 272 ".\\myparser.y"

                        parseTree.mkLeaf(CHARCONST_LEAF);
                        parseTree.root->nodeAttr.charValue=yyattribute(1 - 1)->nodeAttr.charValue;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.root;
                    
#line 653 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 279 ".\\myparser.y"

                        parseTree.mkLeaf(INTCONST_LEAF);
                        parseTree.root->nodeAttr.intValue=yyattribute(1 - 1)->nodeAttr.intValue;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.root;
                    
#line 670 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 287 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 685 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 291 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 700 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 297 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(LEFTVALUE_EXPR,NO_OP,yyattribute(1 - 1));
                    
#line 715 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 301 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(RIGHTVALUE_EXPR,NO_OP,yyattribute(1 - 1));
                    
#line 730 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 305 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,BOR_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 745 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 309 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,BXOR_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 760 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 313 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,BAND_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 775 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 317 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,NE_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 790 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 321 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,EQ_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 805 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 325 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,LT_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 820 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 329 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,LE_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 835 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 333 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,GT_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 850 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 337 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,GE_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 865 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 341 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,LSHIFT_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 880 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 345 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,RSHIFT_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 895 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 349 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,ADD_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 910 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 353 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,SUB_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 925 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 357 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,MUL_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 940 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 361 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,DIV_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 955 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 365 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,MOD_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 970 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 369 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,BNOT_OP,yyattribute(1 - 2),yyattribute(3 - 2));
                    
#line 985 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 373 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,POST_PLUSPLUS_OP,yyattribute(1 - 2));
                    
#line 1000 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 377 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,POST_MINUSMINUS_OP,yyattribute(1 - 2));
                    
#line 1015 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 381 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,PRE_PLUSPLUS_OP,yyattribute(2 - 2));
                    
#line 1030 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 385 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,PRE_MINUSMINUS_OP,yyattribute(2 - 2));
                    
#line 1045 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 389 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,NEGATIVE_OP,yyattribute(2 - 2));
                    
#line 1060 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 393 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,AND_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 1075 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 397 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(MATH_EXPR,OR_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 1090 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 401 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
                    
#line 1105 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 407 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 1120 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 412 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,yyattribute(1 - 3),yyattribute(3 - 3));
                    
#line 1135 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 418 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(EXPR_STMT,yyattribute(1 - 2));
                    
#line 1150 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 424 ".\\myparser.y"

                        //新添代码：插入符号表
                        //只需要当前作用域没有该符号即可
                        if(symTab[currentSymtab].lookup(yyattribute(1 - 1)->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert(yyattribute(1 - 1)->nodeAttr.idEntry);
                        else
                            cerr<<yyattribute(1 - 1)->nodeAttr.idEntry<<"变量重定义！"<<endl;
                            
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1172 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 435 ".\\myparser.y"

					    //插入

                        if(symTab[currentSymtab].lookup(yyattribute(1 - 3)->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert(yyattribute(1 - 3)->nodeAttr.idEntry);
                        else
							cerr<<"重定义"<<endl;
                            
						(*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,yyattribute(1 - 3),yyattribute(3 - 3));
					
					
#line 1195 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 447 ".\\myparser.y"

						//插入
						
						if(symTab[currentSymtab].lookup(yyattribute(1 - 3)->nodeAttr.idEntry)==NULL)
                            symTab[currentSymtab].insert(yyattribute(1 - 3)->nodeAttr.idEntry);
                         else
							cerr<<"重定义"<<endl;
                            
						 (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkExprNode(ASSIGN_EXPR,ASSIGN_OP,yyattribute(1 - 3),yyattribute(3 - 3));
					
#line 1217 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 501 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1232 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 505 ".\\myparser.y"

                        Node* t=yyattribute(1 - 3);
                        while(t->sibling!=NULL)
                            t=t->sibling;
                        t->sibling=yyattribute(3 - 3);
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);
                    
#line 1251 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 515 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkLeaf(INT_LEAF);
                    
#line 1266 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 519 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkLeaf(CHAR_LEAF);
                    
#line 1281 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 525 ".\\myparser.y"

                        Node* t=yyattribute(2 - 3);
                        while(t!=NULL)
                        {
                            if(t->specType.exprType==ASSIGN_EXPR)
                            {
                                switch(yyattribute(1 - 3)->specType.leafType)
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
                                switch(yyattribute(1 - 3)->specType.leafType)
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
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(DECLARE_STMT,yyattribute(1 - 3),yyattribute(2 - 3));
                    
#line 1325 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 560 ".\\myparser.y"

                        currentSymtab=symTab[currentSymtab].parentSeq;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(IF_STMT,yyattribute(3 - 5),yyattribute(5 - 5));
                    
#line 1341 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 567 ".\\myparser.y"

                        currentSymtab=symTab[currentSymtab].parentSeq;
                        yyattribute(1 - 3)->children[2]=yyattribute(3 - 3);
                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);
                    
#line 1358 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 575 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1373 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 579 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1388 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 585 ".\\myparser.y"

                        currentSymtab=symTab[currentSymtab].parentSeq;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(WHILE_STMT,yyattribute(3 - 5),yyattribute(5 - 5));
                    
#line 1404 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 592 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1419 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 596 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1434 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 600 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1449 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 606 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
                    
#line 1464 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 610 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
                    
#line 1479 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 617 ".\\myparser.y"

                        currentSymtab=symTab[currentSymtab].parentSeq;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(FOR_STMT,yyattribute(3 - 7),yyattribute(4 - 7),yyattribute(5 - 7),yyattribute(7 - 7));
                    
#line 1495 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 622 ".\\myparser.y"

                        currentSymtab=symTab[currentSymtab].parentSeq;
                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(FOR_STMT,yyattribute(3 - 6),yyattribute(4 - 6),yyattribute(6 - 6));
                    
#line 1511 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 629 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(VOID_STMT);
                    
#line 1526 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 634 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(BREAK_STMT);
                    
#line 1541 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 639 ".\\myparser.y"

                        (*(YYSTYPE YYFAR*)yyvalptr)=parseTree.mkStmtNode(CONTINUE_STMT);
                    
#line 1556 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "CHAR", 258 },
		{ "INTCONST", 259 },
		{ "CHARCONST", 260 },
		{ "STRINGCONST", 261 },
		{ "ID", 262 },
		{ "IF", 263 },
		{ "ELSE", 264 },
		{ "WHILE", 265 },
		{ "FOR", 266 },
		{ "INPUT", 267 },
		{ "OUTPUT", 268 },
		{ "BREAK", 269 },
		{ "CONTINUE", 270 },
		{ "MAIN", 271 },
		{ "COMMA", 272 },
		{ "SEMIC", 273 },
		{ "ASSIGN", 274 },
		{ "OR", 275 },
		{ "AND", 276 },
		{ "BOR", 277 },
		{ "BXOR", 278 },
		{ "BAND", 279 },
		{ "NE", 280 },
		{ "EQ", 281 },
		{ "LT", 282 },
		{ "LE", 283 },
		{ "GT", 284 },
		{ "GE", 285 },
		{ "LSHIFT", 286 },
		{ "RSHIFT", 287 },
		{ "ADD", 288 },
		{ "SUB", 289 },
		{ "MUL", 290 },
		{ "DIV", 291 },
		{ "MOD", 292 },
		{ "BNOT", 293 },
		{ "PLUSPLUS", 294 },
		{ "MINUSMINUS", 295 },
		{ "LPAREN", 296 },
		{ "RPAREN", 297 },
		{ "LBRACE", 298 },
		{ "RBRACE", 299 },
		{ "UMINUS", 302 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: main_function",
		"main_function: MAIN LPAREN RPAREN compound_stmt",
		"compound_stmt: LBRACE stmt_list RBRACE",
		"compound_stmt: LBRACE RBRACE",
		"stmt_list: stmt",
		"stmt_list: stmt_list stmt",
		"input_operand: RSHIFT left_value",
		"input_list: INPUT input_operand",
		"input_list: input_list input_operand",
		"input_stmt: input_list SEMIC",
		"output_operand: LSHIFT STRINGCONST",
		"output_operand: LSHIFT math_expr",
		"output_list: OUTPUT output_operand",
		"output_list: output_list output_operand",
		"output_stmt: output_list SEMIC",
		"stmt: declare_stmt",
		"stmt: compound_stmt",
		"stmt: expr_stmt",
		"stmt: if_stmt",
		"stmt: while_stmt",
		"stmt: for_stmt",
		"stmt: void_stmt",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"stmt: break_stmt",
		"stmt: continue_stmt",
		"id: ID",
		"left_value: id",
		"right_value: CHARCONST",
		"right_value: INTCONST",
		"expr: math_expr",
		"expr: assign_expr",
		"math_expr: left_value",
		"math_expr: right_value",
		"math_expr: math_expr BOR math_expr",
		"math_expr: math_expr BXOR math_expr",
		"math_expr: math_expr BAND math_expr",
		"math_expr: math_expr NE math_expr",
		"math_expr: math_expr EQ math_expr",
		"math_expr: math_expr LT math_expr",
		"math_expr: math_expr LE math_expr",
		"math_expr: math_expr GT math_expr",
		"math_expr: math_expr GE math_expr",
		"math_expr: math_expr LSHIFT math_expr",
		"math_expr: math_expr RSHIFT math_expr",
		"math_expr: math_expr ADD math_expr",
		"math_expr: math_expr SUB math_expr",
		"math_expr: math_expr MUL math_expr",
		"math_expr: math_expr DIV math_expr",
		"math_expr: math_expr MOD math_expr",
		"math_expr: BNOT math_expr",
		"math_expr: left_value PLUSPLUS",
		"math_expr: left_value MINUSMINUS",
		"math_expr: PLUSPLUS left_value",
		"math_expr: MINUSMINUS left_value",
		"math_expr: SUB math_expr",
		"math_expr: math_expr AND math_expr",
		"math_expr: math_expr OR math_expr",
		"math_expr: LPAREN math_expr RPAREN",
		"assign_expr: left_value ASSIGN math_expr",
		"assign_expr: left_value ASSIGN assign_expr",
		"expr_stmt: expr SEMIC",
		"declare: id",
		"declare: id ASSIGN assign_expr",
		"declare: id ASSIGN math_expr",
		"declare_list: declare",
		"declare_list: declare_list COMMA declare",
		"type_specifier: INT",
		"type_specifier: CHAR",
		"declare_stmt: type_specifier declare_list SEMIC",
		"onlyif_stmt: IF LPAREN math_expr RPAREN stmt",
		"ifelse_stmt: onlyif_stmt ELSE stmt",
		"if_stmt: onlyif_stmt",
		"if_stmt: ifelse_stmt",
		"while_stmt: WHILE LPAREN math_expr RPAREN stmt",
		"for_initializer: declare_stmt",
		"for_initializer: expr_stmt",
		"for_initializer: void_stmt",
		"for_condition: math_expr SEMIC",
		"for_condition: void_stmt",
		"for_stmt: FOR LPAREN for_initializer for_condition expr RPAREN stmt",
		"for_stmt: FOR LPAREN for_initializer for_condition RPAREN stmt",
		"void_stmt: SEMIC",
		"break_stmt: BREAK SEMIC",
		"continue_stmt: CONTINUE SEMIC"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 2, 2, 2 },
		{ 3, 1, 3 },
		{ 3, 2, 4 },
		{ 4, 2, 5 },
		{ 5, 2, 6 },
		{ 5, 2, 7 },
		{ 6, 2, 8 },
		{ 7, 2, 9 },
		{ 7, 2, 10 },
		{ 8, 2, 11 },
		{ 8, 2, 12 },
		{ 9, 2, 13 },
		{ 10, 1, 14 },
		{ 10, 1, 15 },
		{ 10, 1, 16 },
		{ 10, 1, 17 },
		{ 10, 1, 18 },
		{ 10, 1, 19 },
		{ 10, 1, 20 },
		{ 10, 1, 21 },
		{ 10, 1, 22 },
		{ 10, 1, 23 },
		{ 10, 1, 24 },
		{ 11, 1, 25 },
		{ 12, 1, 26 },
		{ 13, 1, 27 },
		{ 13, 1, 28 },
		{ 14, 1, 29 },
		{ 14, 1, 30 },
		{ 15, 1, 31 },
		{ 15, 1, 32 },
		{ 15, 3, 33 },
		{ 15, 3, 34 },
		{ 15, 3, 35 },
		{ 15, 3, 36 },
		{ 15, 3, 37 },
		{ 15, 3, 38 },
		{ 15, 3, 39 },
		{ 15, 3, 40 },
		{ 15, 3, 41 },
		{ 15, 3, 42 },
		{ 15, 3, 43 },
		{ 15, 3, 44 },
		{ 15, 3, 45 },
		{ 15, 3, 46 },
		{ 15, 3, 47 },
		{ 15, 3, 48 },
		{ 15, 2, 49 },
		{ 15, 2, 50 },
		{ 15, 2, 51 },
		{ 15, 2, 52 },
		{ 15, 2, 53 },
		{ 15, 2, 54 },
		{ 15, 3, 55 },
		{ 15, 3, 56 },
		{ 15, 3, 57 },
		{ 16, 3, 58 },
		{ 16, 3, 59 },
		{ 17, 2, 60 },
		{ 18, 1, 61 },
		{ 18, 3, 62 },
		{ 18, 3, 63 },
		{ 19, 1, 64 },
		{ 19, 3, 65 },
		{ 20, 1, 66 },
		{ 20, 1, 67 },
		{ 21, 3, 68 },
		{ 22, 5, 69 },
		{ 23, 3, 70 },
		{ 24, 1, 71 },
		{ 24, 1, 72 },
		{ 25, 5, 73 },
		{ 26, 1, 74 },
		{ 26, 1, 75 },
		{ 26, 1, 76 },
		{ 27, 2, 77 },
		{ 27, 1, 78 },
		{ 28, 7, 79 },
		{ 28, 6, 80 },
		{ 29, 1, 81 },
		{ 30, 2, 82 },
		{ 31, 2, 83 }
	};
	yyreduction = reduction;

	yytokenaction_size = 284;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 134, YYAT_SHIFT, 143 },
		{ 142, YYAT_SHIFT, 145 },
		{ 134, YYAT_SHIFT, 77 },
		{ 134, YYAT_SHIFT, 78 },
		{ 134, YYAT_SHIFT, 79 },
		{ 134, YYAT_SHIFT, 80 },
		{ 134, YYAT_SHIFT, 81 },
		{ 134, YYAT_SHIFT, 82 },
		{ 134, YYAT_SHIFT, 83 },
		{ 134, YYAT_SHIFT, 84 },
		{ 134, YYAT_SHIFT, 85 },
		{ 134, YYAT_SHIFT, 86 },
		{ 134, YYAT_SHIFT, 87 },
		{ 134, YYAT_SHIFT, 88 },
		{ 134, YYAT_SHIFT, 89 },
		{ 134, YYAT_SHIFT, 90 },
		{ 134, YYAT_SHIFT, 91 },
		{ 134, YYAT_SHIFT, 92 },
		{ 134, YYAT_SHIFT, 93 },
		{ 134, YYAT_SHIFT, 94 },
		{ 138, YYAT_SHIFT, 77 },
		{ 138, YYAT_SHIFT, 78 },
		{ 138, YYAT_SHIFT, 79 },
		{ 138, YYAT_SHIFT, 80 },
		{ 138, YYAT_SHIFT, 81 },
		{ 138, YYAT_SHIFT, 82 },
		{ 138, YYAT_SHIFT, 83 },
		{ 138, YYAT_SHIFT, 84 },
		{ 138, YYAT_SHIFT, 85 },
		{ 138, YYAT_SHIFT, 86 },
		{ 138, YYAT_SHIFT, 87 },
		{ 138, YYAT_SHIFT, 88 },
		{ 138, YYAT_SHIFT, 89 },
		{ 138, YYAT_SHIFT, 90 },
		{ 138, YYAT_SHIFT, 91 },
		{ 138, YYAT_SHIFT, 92 },
		{ 138, YYAT_SHIFT, 93 },
		{ 138, YYAT_SHIFT, 94 },
		{ 108, YYAT_SHIFT, 77 },
		{ 108, YYAT_SHIFT, 78 },
		{ 108, YYAT_SHIFT, 79 },
		{ 108, YYAT_SHIFT, 80 },
		{ 108, YYAT_SHIFT, 81 },
		{ 108, YYAT_SHIFT, 82 },
		{ 108, YYAT_SHIFT, 83 },
		{ 108, YYAT_SHIFT, 84 },
		{ 108, YYAT_SHIFT, 85 },
		{ 108, YYAT_SHIFT, 86 },
		{ 108, YYAT_SHIFT, 87 },
		{ 108, YYAT_SHIFT, 88 },
		{ 108, YYAT_SHIFT, 89 },
		{ 108, YYAT_SHIFT, 90 },
		{ 108, YYAT_SHIFT, 91 },
		{ 108, YYAT_SHIFT, 92 },
		{ 108, YYAT_SHIFT, 93 },
		{ 108, YYAT_SHIFT, 94 },
		{ 39, YYAT_SHIFT, 77 },
		{ 39, YYAT_SHIFT, 78 },
		{ 39, YYAT_SHIFT, 79 },
		{ 39, YYAT_SHIFT, 80 },
		{ 39, YYAT_SHIFT, 81 },
		{ 39, YYAT_SHIFT, 82 },
		{ 39, YYAT_SHIFT, 83 },
		{ 39, YYAT_SHIFT, 84 },
		{ 39, YYAT_SHIFT, 85 },
		{ 39, YYAT_SHIFT, 86 },
		{ 39, YYAT_SHIFT, 87 },
		{ 39, YYAT_SHIFT, 88 },
		{ 39, YYAT_SHIFT, 89 },
		{ 39, YYAT_SHIFT, 90 },
		{ 39, YYAT_SHIFT, 91 },
		{ 39, YYAT_SHIFT, 92 },
		{ 39, YYAT_SHIFT, 93 },
		{ 39, YYAT_SHIFT, 94 },
		{ 105, YYAT_SHIFT, 77 },
		{ 105, YYAT_SHIFT, 78 },
		{ 105, YYAT_SHIFT, 79 },
		{ 105, YYAT_SHIFT, 80 },
		{ 105, YYAT_SHIFT, 81 },
		{ 105, YYAT_SHIFT, 82 },
		{ 105, YYAT_SHIFT, 83 },
		{ 105, YYAT_SHIFT, 84 },
		{ 105, YYAT_SHIFT, 85 },
		{ 105, YYAT_SHIFT, 86 },
		{ 105, YYAT_SHIFT, 87 },
		{ 111, YYAT_ERROR, 0 },
		{ 105, YYAT_SHIFT, 89 },
		{ 105, YYAT_SHIFT, 90 },
		{ 105, YYAT_SHIFT, 91 },
		{ 105, YYAT_SHIFT, 92 },
		{ 105, YYAT_SHIFT, 93 },
		{ 105, YYAT_SHIFT, 94 },
		{ 113, YYAT_SHIFT, 78 },
		{ 113, YYAT_SHIFT, 79 },
		{ 113, YYAT_SHIFT, 80 },
		{ 113, YYAT_SHIFT, 81 },
		{ 113, YYAT_SHIFT, 82 },
		{ 113, YYAT_SHIFT, 83 },
		{ 113, YYAT_SHIFT, 84 },
		{ 113, YYAT_SHIFT, 85 },
		{ 113, YYAT_SHIFT, 86 },
		{ 113, YYAT_SHIFT, 87 },
		{ 113, YYAT_SHIFT, 88 },
		{ 113, YYAT_SHIFT, 89 },
		{ 113, YYAT_SHIFT, 90 },
		{ 113, YYAT_SHIFT, 91 },
		{ 113, YYAT_SHIFT, 92 },
		{ 113, YYAT_SHIFT, 93 },
		{ 113, YYAT_SHIFT, 94 },
		{ 114, YYAT_SHIFT, 79 },
		{ 114, YYAT_SHIFT, 80 },
		{ 114, YYAT_SHIFT, 81 },
		{ 114, YYAT_SHIFT, 82 },
		{ 114, YYAT_SHIFT, 83 },
		{ 114, YYAT_SHIFT, 84 },
		{ 114, YYAT_SHIFT, 85 },
		{ 114, YYAT_SHIFT, 86 },
		{ 114, YYAT_SHIFT, 87 },
		{ 114, YYAT_SHIFT, 88 },
		{ 114, YYAT_SHIFT, 89 },
		{ 114, YYAT_SHIFT, 90 },
		{ 114, YYAT_SHIFT, 91 },
		{ 114, YYAT_SHIFT, 92 },
		{ 114, YYAT_SHIFT, 93 },
		{ 114, YYAT_SHIFT, 94 },
		{ 115, YYAT_SHIFT, 80 },
		{ 115, YYAT_SHIFT, 81 },
		{ 115, YYAT_SHIFT, 82 },
		{ 115, YYAT_SHIFT, 83 },
		{ 115, YYAT_SHIFT, 84 },
		{ 115, YYAT_SHIFT, 85 },
		{ 115, YYAT_SHIFT, 86 },
		{ 115, YYAT_SHIFT, 87 },
		{ 115, YYAT_SHIFT, 88 },
		{ 115, YYAT_SHIFT, 89 },
		{ 115, YYAT_SHIFT, 90 },
		{ 115, YYAT_SHIFT, 91 },
		{ 115, YYAT_SHIFT, 92 },
		{ 115, YYAT_SHIFT, 93 },
		{ 115, YYAT_SHIFT, 94 },
		{ 116, YYAT_SHIFT, 81 },
		{ 116, YYAT_SHIFT, 82 },
		{ 116, YYAT_SHIFT, 83 },
		{ 116, YYAT_SHIFT, 84 },
		{ 116, YYAT_SHIFT, 85 },
		{ 116, YYAT_SHIFT, 86 },
		{ 116, YYAT_SHIFT, 87 },
		{ 116, YYAT_SHIFT, 88 },
		{ 116, YYAT_SHIFT, 89 },
		{ 116, YYAT_SHIFT, 90 },
		{ 116, YYAT_SHIFT, 91 },
		{ 116, YYAT_SHIFT, 92 },
		{ 116, YYAT_SHIFT, 93 },
		{ 116, YYAT_SHIFT, 94 },
		{ 117, YYAT_SHIFT, 82 },
		{ 117, YYAT_SHIFT, 83 },
		{ 117, YYAT_SHIFT, 84 },
		{ 117, YYAT_SHIFT, 85 },
		{ 117, YYAT_SHIFT, 86 },
		{ 117, YYAT_SHIFT, 87 },
		{ 117, YYAT_SHIFT, 88 },
		{ 117, YYAT_SHIFT, 89 },
		{ 117, YYAT_SHIFT, 90 },
		{ 117, YYAT_SHIFT, 91 },
		{ 117, YYAT_SHIFT, 92 },
		{ 117, YYAT_SHIFT, 93 },
		{ 117, YYAT_SHIFT, 94 },
		{ 119, YYAT_SHIFT, 84 },
		{ 119, YYAT_SHIFT, 85 },
		{ 119, YYAT_SHIFT, 86 },
		{ 119, YYAT_SHIFT, 87 },
		{ 119, YYAT_SHIFT, 88 },
		{ 119, YYAT_SHIFT, 89 },
		{ 119, YYAT_SHIFT, 90 },
		{ 119, YYAT_SHIFT, 91 },
		{ 119, YYAT_SHIFT, 92 },
		{ 119, YYAT_SHIFT, 93 },
		{ 119, YYAT_SHIFT, 94 },
		{ 118, YYAT_SHIFT, 84 },
		{ 118, YYAT_SHIFT, 85 },
		{ 118, YYAT_SHIFT, 86 },
		{ 118, YYAT_SHIFT, 87 },
		{ 118, YYAT_SHIFT, 88 },
		{ 118, YYAT_SHIFT, 89 },
		{ 118, YYAT_SHIFT, 90 },
		{ 118, YYAT_SHIFT, 91 },
		{ 118, YYAT_SHIFT, 92 },
		{ 118, YYAT_SHIFT, 93 },
		{ 118, YYAT_SHIFT, 94 },
		{ 133, YYAT_SHIFT, 9 },
		{ 133, YYAT_SHIFT, 10 },
		{ 98, YYAT_ERROR, 0 },
		{ 109, YYAT_SHIFT, 11 },
		{ 145, YYAT_SHIFT, 12 },
		{ 99, YYAT_SHIFT, 19 },
		{ 145, YYAT_SHIFT, 13 },
		{ 145, YYAT_SHIFT, 14 },
		{ 145, YYAT_SHIFT, 15 },
		{ 145, YYAT_SHIFT, 16 },
		{ 145, YYAT_SHIFT, 17 },
		{ 145, YYAT_SHIFT, 18 },
		{ 123, YYAT_SHIFT, 88 },
		{ 123, YYAT_SHIFT, 89 },
		{ 123, YYAT_SHIFT, 90 },
		{ 123, YYAT_SHIFT, 91 },
		{ 123, YYAT_SHIFT, 92 },
		{ 123, YYAT_SHIFT, 93 },
		{ 123, YYAT_SHIFT, 94 },
		{ 122, YYAT_SHIFT, 88 },
		{ 122, YYAT_SHIFT, 89 },
		{ 122, YYAT_SHIFT, 90 },
		{ 122, YYAT_SHIFT, 91 },
		{ 122, YYAT_SHIFT, 92 },
		{ 122, YYAT_SHIFT, 93 },
		{ 122, YYAT_SHIFT, 94 },
		{ 98, YYAT_SHIFT, 132 },
		{ 127, YYAT_SHIFT, 92 },
		{ 127, YYAT_SHIFT, 93 },
		{ 127, YYAT_SHIFT, 94 },
		{ 133, YYAT_SHIFT, 20 },
		{ 126, YYAT_SHIFT, 92 },
		{ 126, YYAT_SHIFT, 93 },
		{ 126, YYAT_SHIFT, 94 },
		{ 133, YYAT_SHIFT, 21 },
		{ 133, YYAT_SHIFT, 22 },
		{ 133, YYAT_SHIFT, 23 },
		{ 133, YYAT_SHIFT, 24 },
		{ 133, YYAT_SHIFT, 141 },
		{ 145, YYAT_SHIFT, 5 },
		{ 121, YYAT_SHIFT, 88 },
		{ 121, YYAT_SHIFT, 89 },
		{ 121, YYAT_SHIFT, 90 },
		{ 121, YYAT_SHIFT, 91 },
		{ 121, YYAT_SHIFT, 92 },
		{ 121, YYAT_SHIFT, 93 },
		{ 121, YYAT_SHIFT, 94 },
		{ 120, YYAT_SHIFT, 88 },
		{ 120, YYAT_SHIFT, 89 },
		{ 120, YYAT_SHIFT, 90 },
		{ 120, YYAT_SHIFT, 91 },
		{ 120, YYAT_SHIFT, 92 },
		{ 120, YYAT_SHIFT, 93 },
		{ 120, YYAT_SHIFT, 94 },
		{ 31, YYAT_SHIFT, 69 },
		{ 125, YYAT_SHIFT, 90 },
		{ 125, YYAT_SHIFT, 91 },
		{ 125, YYAT_SHIFT, 92 },
		{ 125, YYAT_SHIFT, 93 },
		{ 125, YYAT_SHIFT, 94 },
		{ 124, YYAT_SHIFT, 90 },
		{ 124, YYAT_SHIFT, 91 },
		{ 124, YYAT_SHIFT, 92 },
		{ 124, YYAT_SHIFT, 93 },
		{ 124, YYAT_SHIFT, 94 },
		{ 72, YYAT_SHIFT, 109 },
		{ 72, YYAT_SHIFT, 110 },
		{ 59, YYAT_SHIFT, 70 },
		{ 59, YYAT_SHIFT, 71 },
		{ 52, YYAT_SHIFT, 7 },
		{ 52, YYAT_SHIFT, 8 },
		{ 97, YYAT_SHIFT, 131 },
		{ 74, YYAT_SHIFT, 111 },
		{ 64, YYAT_SHIFT, 106 },
		{ 31, YYAT_SHIFT, 70 },
		{ 31, YYAT_SHIFT, 71 },
		{ 55, YYAT_SHIFT, 104 },
		{ 40, YYAT_SHIFT, 95 },
		{ 37, YYAT_SHIFT, 76 },
		{ 36, YYAT_SHIFT, 75 },
		{ 29, YYAT_SHIFT, 67 },
		{ 26, YYAT_SHIFT, 65 },
		{ 18, YYAT_SHIFT, 58 },
		{ 17, YYAT_SHIFT, 57 },
		{ 16, YYAT_SHIFT, 55 },
		{ 15, YYAT_SHIFT, 53 },
		{ 14, YYAT_SHIFT, 52 },
		{ 13, YYAT_SHIFT, 51 },
		{ 12, YYAT_SHIFT, 50 },
		{ 5, YYAT_SHIFT, 25 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 12, 1, YYAT_ERROR, 0 },
		{ -14, 1, YYAT_ERROR, 0 },
		{ 281, 1, YYAT_ERROR, 0 },
		{ -17, 1, YYAT_ERROR, 0 },
		{ -19, 1, YYAT_ERROR, 0 },
		{ -21, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ -19, 1, YYAT_ERROR, 0 },
		{ -20, 1, YYAT_ERROR, 0 },
		{ -21, 1, YYAT_ERROR, 0 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ -1, 1, YYAT_ERROR, 0 },
		{ -2, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -3, 1, YYAT_DEFAULT, 15 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -30, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -31, 1, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ -5, 1, YYAT_ERROR, 0 },
		{ 3, 1, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ -219, 1, YYAT_REDUCE, 30 },
		{ -7, 1, YYAT_DEFAULT, 16 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 1, 1, YYAT_DEFAULT, 99 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 4, 1, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ -38, 1, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -35, 1, YYAT_DEFAULT, 98 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -18, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ -13, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -37, 1, YYAT_DEFAULT, 98 },
		{ -82, 1, YYAT_DEFAULT, 134 },
		{ -79, 1, YYAT_DEFAULT, 111 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -201, 1, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ -237, 1, YYAT_REDUCE, 59 },
		{ -70, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ -212, 1, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ -184, 1, YYAT_REDUCE, 57 },
		{ -168, 1, YYAT_REDUCE, 56 },
		{ -153, 1, YYAT_REDUCE, 34 },
		{ -139, 1, YYAT_REDUCE, 35 },
		{ -126, 1, YYAT_REDUCE, 36 },
		{ -104, 1, YYAT_REDUCE, 37 },
		{ -115, 1, YYAT_REDUCE, 38 },
		{ -50, 1, YYAT_REDUCE, 39 },
		{ -57, 1, YYAT_REDUCE, 40 },
		{ -78, 1, YYAT_REDUCE, 41 },
		{ -85, 1, YYAT_REDUCE, 42 },
		{ -39, 1, YYAT_REDUCE, 43 },
		{ -44, 1, YYAT_REDUCE, 44 },
		{ -70, 1, YYAT_REDUCE, 45 },
		{ -74, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -70, 1, YYAT_DEFAULT, 109 },
		{ -273, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -255, 1, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -296, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -70, 1, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_REDUCE, 80 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 83;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 145, 28 },
		{ 141, 144 },
		{ 99, 134 },
		{ 145, 26 },
		{ 145, 27 },
		{ 132, 140 },
		{ 145, 40 },
		{ 145, 43 },
		{ 145, 146 },
		{ 133, 31 },
		{ 133, 34 },
		{ 133, 142 },
		{ 133, 39 },
		{ 133, 33 },
		{ 99, 133 },
		{ 145, 45 },
		{ 99, 135 },
		{ 131, 139 },
		{ 109, 74 },
		{ 145, 49 },
		{ 145, 37 },
		{ 145, 32 },
		{ 145, 46 },
		{ 145, 38 },
		{ 145, -1 },
		{ 109, 136 },
		{ 145, 48 },
		{ 145, 44 },
		{ 145, 47 },
		{ 145, 41 },
		{ 52, 36 },
		{ 5, 29 },
		{ 93, 129 },
		{ 52, 101 },
		{ 69, 108 },
		{ 69, 107 },
		{ 52, 35 },
		{ 52, 102 },
		{ 5, 30 },
		{ 92, 128 },
		{ 94, 59 },
		{ 91, 127 },
		{ 52, 99 },
		{ 94, 130 },
		{ 94, -1 },
		{ 52, 100 },
		{ 111, -1 },
		{ 111, 138 },
		{ 111, 137 },
		{ 53, 42 },
		{ 53, 103 },
		{ 35, 73 },
		{ 35, 72 },
		{ 90, 126 },
		{ 89, 125 },
		{ 88, 124 },
		{ 87, 123 },
		{ 86, 122 },
		{ 85, 121 },
		{ 84, 120 },
		{ 83, 119 },
		{ 82, 118 },
		{ 81, 117 },
		{ 80, 116 },
		{ 79, 115 },
		{ 78, 114 },
		{ 77, 113 },
		{ 76, 112 },
		{ 55, 105 },
		{ 51, 98 },
		{ 50, 97 },
		{ 40, 96 },
		{ 29, 68 },
		{ 26, 66 },
		{ 24, 64 },
		{ 23, 63 },
		{ 22, 62 },
		{ 21, 61 },
		{ 20, 60 },
		{ 16, 56 },
		{ 15, 54 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 81, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 79, -1 },
		{ 28, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 76, -1 },
		{ 72, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, 94 },
		{ 62, 94 },
		{ 64, 53 },
		{ 63, 53 },
		{ 59, 94 },
		{ 0, -1 },
		{ 69, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 109 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 64, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 55, 94 },
		{ 54, 94 },
		{ 16, 133 },
		{ 38, -1 },
		{ 0, -1 },
		{ 53, 94 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 19, 111 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 145 },
		{ 51, 94 },
		{ 50, 94 },
		{ 49, 94 },
		{ 48, 94 },
		{ 47, 94 },
		{ 46, 94 },
		{ 45, 94 },
		{ 44, 94 },
		{ 43, 94 },
		{ 42, 94 },
		{ 41, 94 },
		{ 40, 94 },
		{ 39, 94 },
		{ 38, 94 },
		{ 26, 94 },
		{ 24, 94 },
		{ 17, 94 },
		{ 28, 111 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -13, 94 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, -1 },
		{ 0, -1 },
		{ 32, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 145 },
		{ -5, 145 },
		{ -3, 53 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -9, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 52 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 645 ".\\myparser.y"


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

