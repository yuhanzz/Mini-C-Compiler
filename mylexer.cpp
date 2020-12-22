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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 01/07/18
* Time: 10:32:52
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2017?и║12??8ии?
****************************************************************************/

#include "myparser.h"
#include "C:\Users\zhouyuhan\source\repos\ConsoleApplication8\ConsoleApplication8\symbol.h"
#include "C:\Users\zhouyuhan\source\repos\ConsoleApplication8\ConsoleApplication8\tree.h"
using namespace std;

symbolTable* symTab=new symbolTable[MAXSCOPE];

int currentSymtab=0;
int nextUnusedSymtab=1;

int lineNumber=1;
Node node;

#line 60 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 35 ".\\mylexer.l"

	// place any extra initialisation code here

#line 84 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 40 ".\\mylexer.l"

	// place any extra cleanup code here

#line 96 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 60 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 167 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 67 ".\\mylexer.l"

#line 174 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 68 ".\\mylexer.l"
lineNumber++;
#line 181 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 70 ".\\mylexer.l"
return INT;
#line 188 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 71 ".\\mylexer.l"
return CHAR;
#line 195 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 72 ".\\mylexer.l"

	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return IF;
	                  
#line 207 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 79 ".\\mylexer.l"

	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return ELSE;
	                  
#line 219 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 85 ".\\mylexer.l"

	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return WHILE;
	                  
#line 231 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 92 ".\\mylexer.l"

	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return FOR;
	                  
#line 243 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 98 ".\\mylexer.l"
return INPUT;
#line 250 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 99 ".\\mylexer.l"
return OUTPUT;
#line 257 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 100 ".\\mylexer.l"
return BREAK;
#line 264 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 101 ".\\mylexer.l"
return CONTINUE;
#line 271 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 102 ".\\mylexer.l"
   
                          symTab[currentSymtab].parentSeq=0;
                          return MAIN;
                      
#line 281 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 108 ".\\mylexer.l"

                        for(int i=0;i<yyleng;i++)
                        {
                            if(yytext[i]=='\n')
                            	lineNumber++;
                        }
                    
#line 294 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 116 ".\\mylexer.l"


                    
#line 303 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 120 ".\\mylexer.l"

	                    yylval=&node;
	                    yylval->nodeAttr.intValue=atoi(yytext);
                        return INTCONST;
                    
#line 314 "mylexer.cpp"
		}
		break;
#line 125 ".\\mylexer.l"
                    
#line 319 "mylexer.cpp"
	case 17:
		{
#line 126 ".\\mylexer.l"

                        yylval=&node;
	                    yylval->nodeAttr.charValue=yytext[1];
	                    return CHARCONST;
	                
#line 328 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 133 ".\\mylexer.l"

	                    yylval=&node;
	                    yylval->nodeAttr.stringValue=yytext;
                        return STRINGCONST;
                    
#line 339 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 139 ".\\mylexer.l"

	                  /* if(symTab[currentSymtab].lookup(yytext)==NULL)
	                       symTab[currentSymtab].insert(yytext);
	                    yylval=&node;
	                    yylval->nodeAttr.idEntry=yytext;
	                    return ID;*/
	                    yylval=&node;
	                    yylval->nodeAttr.idEntry=yytext;
	                    return ID;
	                
#line 355 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 151 ".\\mylexer.l"
return COMMA;
#line 362 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 152 ".\\mylexer.l"
return SEMIC;
#line 369 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 153 ".\\mylexer.l"
return OR;
#line 376 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 154 ".\\mylexer.l"
return AND;
#line 383 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 155 ".\\mylexer.l"
return BOR;
#line 390 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 156 ".\\mylexer.l"
return BXOR;
#line 397 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 157 ".\\mylexer.l"
return BAND;
#line 404 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 158 ".\\mylexer.l"
return BNOT;
#line 411 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 159 ".\\mylexer.l"
return NE;
#line 418 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 160 ".\\mylexer.l"
return EQ;
#line 425 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 161 ".\\mylexer.l"
return LT;
#line 432 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 162 ".\\mylexer.l"
return LE;
#line 439 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 163 ".\\mylexer.l"
return GT;
#line 446 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 164 ".\\mylexer.l"
return GE;
#line 453 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 165 ".\\mylexer.l"
return LSHIFT;
#line 460 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 166 ".\\mylexer.l"
return RSHIFT;
#line 467 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 167 ".\\mylexer.l"
return ADD;
#line 474 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 168 ".\\mylexer.l"
return SUB;
#line 481 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 169 ".\\mylexer.l"
return MUL;
#line 488 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 170 ".\\mylexer.l"
return DIV;
#line 495 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 171 ".\\mylexer.l"
return MOD;
#line 502 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 172 ".\\mylexer.l"
return PLUSPLUS;
#line 509 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 173 ".\\mylexer.l"
return MINUSMINUS;
#line 516 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 174 ".\\mylexer.l"
return LPAREN;
#line 523 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 175 ".\\mylexer.l"
return RPAREN;
#line 530 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 176 ".\\mylexer.l"
return ASSIGN;
#line 537 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 178 ".\\mylexer.l"
return LBRACE;
#line 544 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 179 ".\\mylexer.l"
return RBRACE;
#line 551 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 180 ".\\mylexer.l"
return LBRACK;
#line 558 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 181 ".\\mylexer.l"
return RBRACK;
#line 565 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 183 ".\\mylexer.l"
cout<<"UNKNOWN\t"<<yytext<<endl;
#line 572 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 220;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 67, 67 },
		{ 4, 4 },
		{ 42, 9 },
		{ 0, 10 },
		{ 58, 30 },
		{ 78, 67 },
		{ 0, 44 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 60, 32 },
		{ 49, 21 },
		{ 50, 21 },
		{ 59, 31 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 4, 4 },
		{ 61, 32 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 66, 44 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 47, 17 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 48, 17 },
		{ 39, 6 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 62, 33 },
		{ 26, 1 },
		{ 27, 1 },
		{ 24, 1 },
		{ 44, 10 },
		{ 24, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 24, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 32, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 33, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 34, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 24, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 52, 23 },
		{ 53, 23 },
		{ 63, 34 },
		{ 64, 36 },
		{ 41, 40 },
		{ 45, 14 },
		{ 67, 47 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 0, 48 },
		{ 68, 54 },
		{ 69, 55 },
		{ 70, 56 },
		{ 24, 91 },
		{ 51, 22 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 24, 91 },
		{ 71, 57 },
		{ 55, 29 },
		{ 56, 29 },
		{ 73, 58 },
		{ 74, 59 },
		{ 75, 61 },
		{ 76, 62 },
		{ 72, 57 },
		{ 57, 29 },
		{ 77, 63 },
		{ 65, 66 },
		{ 46, 16 },
		{ 79, 68 },
		{ 80, 69 },
		{ 81, 71 },
		{ 82, 72 },
		{ 83, 73 },
		{ 84, 76 },
		{ 85, 77 },
		{ 86, 79 },
		{ 87, 81 },
		{ 88, 85 },
		{ 89, 87 },
		{ 90, 89 },
		{ 91, 90 },
		{ 54, 28 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 50 },
		{ 0, -5, 1 },
		{ 0, 0, 2 },
		{ 0, -5, 50 },
		{ 40, 0, 50 },
		{ 0, 0, 40 },
		{ 0, -33, 26 },
		{ -43, -4, 50 },
		{ 0, 0, 43 },
		{ 0, 0, 44 },
		{ 0, 0, 38 },
		{ 0, 91, 36 },
		{ 0, 0, 20 },
		{ 0, 160, 37 },
		{ 0, 8, 39 },
		{ 0, 0, 16 },
		{ 0, -38, 16 },
		{ 0, 0, 21 },
		{ 0, -39, 30 },
		{ 0, 106, 45 },
		{ 0, 68, 32 },
		{ 91, 0, 19 },
		{ 0, 0, 48 },
		{ 0, 0, 49 },
		{ 0, 0, 25 },
		{ 91, 105, 19 },
		{ 91, 91, 19 },
		{ 91, -101, 19 },
		{ 91, -88, 19 },
		{ 91, -82, 19 },
		{ 91, -13, 19 },
		{ 91, 27, 19 },
		{ 0, 0, 46 },
		{ 0, 8, 24 },
		{ 0, 0, 47 },
		{ 0, 0, 27 },
		{ 0, 0, 28 },
		{ -40, 99, 0 },
		{ 0, 0, 18 },
		{ 0, 0, 23 },
		{ 66, 0, 0 },
		{ -43, -1, 0 },
		{ 0, 0, 41 },
		{ 0, 0, 42 },
		{ -47, 93, 0 },
		{ -48, 152, 15 },
		{ 0, 0, 34 },
		{ 0, 0, 31 },
		{ 0, 0, 29 },
		{ 0, 0, 33 },
		{ 0, 0, 35 },
		{ 91, 62, 19 },
		{ 91, 67, 19 },
		{ 91, 55, 19 },
		{ 91, 84, 19 },
		{ 91, 82, 19 },
		{ 91, 84, 19 },
		{ 91, 0, 5 },
		{ 91, 83, 19 },
		{ 91, 95, 19 },
		{ 91, 98, 19 },
		{ 0, 0, 22 },
		{ 0, 0, 17 },
		{ 0, 165, 17 },
		{ -47, -39, 0 },
		{ 91, 109, 19 },
		{ 91, 93, 19 },
		{ 91, 0, 9 },
		{ 91, 92, 19 },
		{ 91, 93, 19 },
		{ 91, 109, 19 },
		{ 91, 0, 8 },
		{ 91, 0, 3 },
		{ 91, 101, 19 },
		{ 91, 104, 19 },
		{ 0, 0, 14 },
		{ 91, 106, 19 },
		{ 91, 0, 4 },
		{ 91, 109, 19 },
		{ 91, 0, 10 },
		{ 91, 0, 6 },
		{ 91, 0, 13 },
		{ 91, 114, 19 },
		{ 91, 0, 11 },
		{ 91, 106, 19 },
		{ 91, 0, 7 },
		{ 91, 100, 19 },
		{ 91, 117, 19 },
		{ 0, 71, 12 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 185 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


