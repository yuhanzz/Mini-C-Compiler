%{
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
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

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

// place any declarations here

charConstant     '.'|'\\.'
stringConstant   \"[^"]*\"
intConstant      [1-9][0-9]*|0
annotation1      \/\*[^\*]*(\**[^\*\/]+\/*)*[^\/]*\*\/
annotation2      \/\/.*
identifier       [a-zA-Z_]+[a-zA-Z0-9_]*
WS               [ \t]*
newLine          \n

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

{WS}                {}
{newLine}           {lineNumber++;}

"int"                 {return INT;}
"char"                {return CHAR;}
"if"                  {
	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return IF;
	                  }

"else"                {
	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return ELSE;
	                  }
"while"               {
	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return WHILE;
	                  }

"for"                 {
	 		              symTab[nextUnusedSymtab].parentSeq=currentSymtab;
	                      currentSymtab=nextUnusedSymtab;
	                      nextUnusedSymtab++;
	                      return FOR;
	                  }
"cin"                 {return INPUT;}
"cout"                {return OUTPUT;}      
"break"               {return BREAK;}
"continue"            {return CONTINUE;}
"main"                {   
                          symTab[currentSymtab].parentSeq=0;
                          return MAIN;
                      }


{annotation1}       {
                        for(int i=0;i<yyleng;i++)
                        {
                            if(yytext[i]=='\n')
                            	lineNumber++;
                        }
                    }

{annotation2}       {

                    }

{intConstant}       {
	                    yylval=&node;
	                    yylval->nodeAttr.intValue=atoi(yytext);
                        return INTCONST;
                    }
                    
{charConstant}      {
                        yylval=&node;
	                    yylval->nodeAttr.charValue=yytext[1];
	                    return CHARCONST;
	                }


{stringConstant}    {
	                    yylval=&node;
	                    yylval->nodeAttr.stringValue=yytext;
                        return STRINGCONST;
                    }

{identifier}        {
	                  /* if(symTab[currentSymtab].lookup(yytext)==NULL)
	                       symTab[currentSymtab].insert(yytext);
	                    yylval=&node;
	                    yylval->nodeAttr.idEntry=yytext;
	                    return ID;*/
	                    yylval=&node;
	                    yylval->nodeAttr.idEntry=yytext;
	                    return ID;
	                }


","                   {return COMMA;}
";"                   {return SEMIC;}
"||"                  {return OR;}
"&&"                  {return AND;}
"|"                   {return BOR;}
"^"                   {return BXOR;}
"&"                   {return BAND;}
"~"                   {return BNOT;}
"!="                  {return NE;}
"=="                  {return EQ;}
"<"                   {return LT;}
"<="                  {return LE;}
">"                   {return GT;}
">="                  {return GE;}
"<<"                  {return LSHIFT;}
">>"                  {return RSHIFT;}
"+"                   {return ADD;}
"-"                   {return SUB;}
"*"                   {return MUL;}
"/"                   {return DIV;}
"%"                   {return MOD;}
"++"                  {return PLUSPLUS;}
"--"                  {return MINUSMINUS;}
"("                   {return LPAREN;}
")"                   {return RPAREN;}
"="                   {return ASSIGN;}

"{"                   {return LBRACE;}
"}"                   {return RBRACE;}
"["                   {return LBRACK;}
"]"                   {return RBRACK;}

.                     {cout<<"UNKNOWN\t"<<yytext<<endl;}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

