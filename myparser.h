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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/07/18
* Time: 10:32:53
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 30 ".\\myparser.y"

    // place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 45 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE Node*
#endif

#line 82 "myparser.h"
#define INT 257
#define CHAR 258
#define INTCONST 259
#define CHARCONST 260
#define STRINGCONST 261
#define ID 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define INPUT 267
#define OUTPUT 268
#define BREAK 269
#define CONTINUE 270
#define MAIN 271
#define COMMA 272
#define SEMIC 273
#define ASSIGN 274
#define OR 275
#define AND 276
#define BOR 277
#define BXOR 278
#define BAND 279
#define NE 280
#define EQ 281
#define LT 282
#define LE 283
#define GT 284
#define GE 285
#define LSHIFT 286
#define RSHIFT 287
#define ADD 288
#define SUB 289
#define MUL 290
#define DIV 291
#define MOD 292
#define BNOT 293
#define PLUSPLUS 294
#define MINUSMINUS 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299
#define LBRACK 300
#define RBRACK 301
#define UMINUS 302
#endif
