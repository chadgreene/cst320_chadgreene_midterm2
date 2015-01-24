/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 3 Bison and Symbol table
 * Date: 1/19/15
 * 
 * Purpose: Populate a symbol table with items from an input file
 * Flex will parse each token from a file when a { is found a new symbol table
 * will be created and items within the enclosing {} will be added to a 
 * hash table along with a unique sequence number.
*******************************************************************************/
%{

#include "cSymbolTable.h"
#include "langparse.h"
#include "lex.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. period is an example. */
punct           [\.\(\)\[\]\,\;]
digit           [\-]?[0-9]+
oper            [\+\*\/\%\<\!\=\-]
comment         "//".*$
ident           [a-zA-Z][a-zA-Z0-9_]*

%%

    // control scope with curly braces
    // NOTE: This functionality will eventually move to the parser
    // token definitions go here. "if" is an example.
"end"                       RETURN(END);
"if"                        RETURN(IF);
"then"                      RETURN(THEN);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"int"                       RETURN(INT_VAL);
"float"                     RETURN(FLOAT_VAL);
"char"                      RETURN(CHAR);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN_TOK);
"for"                       RETURN(FOR);
"{"                         {
                                symbolTableRoot->IncreaseScope();  
                                return yytext[0];
                            }
"}"                         {
                                symbolTableRoot->DecreaseScope();
                                return yytext[0];
                            }
{ident}                     {
                                yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
                                return IDENTIFIER;
                            }
{digit}                     RETURN(INT_VAL);
{digit}"."{digit}           RETURN(FLOAT_VAL);
{comment}                   /* Skip comments */
{punct}|{oper}              RETURN(yytext[0]);
[ \t\n\r]                   /* Skip whitespace */
.                           RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}