/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
%{

#include "lex.h"


#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. period is an example. */
digit           [\-]?[0-9]+
oper            [\+\*\/\-]
ident           [a-z][a-z]*
comment         "//".*$

%%

    // control scope with curly braces
    // NOTE: This functionality will eventually move to the parser
    // token definitions go here. "if" is an example.
"print"                     RETURN(PRINT);
"end"                       RETURN(END);
"{"                         return yytext[0];
"}"                         return yytext[0];
";"                         return yytext[0];
{ident}                     {
                                
                                yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
                                RETURN(IDENTIFIER);
                            }
{digit}                     {
                                yylval.int_val = atoi(yytext);
                                RETURN(INT);
                            }
{oper}                      {
                                yylval.op_val = yytext[0];
                                RETURN(OP);
                            }
{comment}                   /* Skip comments */
[ \t\n\r]                   /* Skip whitespace */
.                           RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}