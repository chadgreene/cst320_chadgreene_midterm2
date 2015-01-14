%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu

#include "tokens.h"
#include "parse.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
punct           [\.\{\}\(\)\[\]\,\;]
digit           [\-]?[0-9]+
oper            [\+\*\/\%\<\!\=\-]
comment         "//".*$
ident           [a-zA-Z][a-zA-Z0-9_]*
%%

    // token definitions go here. "if" is an example.
"end"                       RETURN(END);
"if"                        RETURN(IF);
"then"                      RETURN(THEN);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"int"                       RETURN(INT);
"float"                     RETURN(FLOAT);
"char"                      RETURN(CHAR);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN_TOK);
"for"                       RETURN(FOR);
{digit}                     RETURN(INT_VAL);
{digit}"."{digit}           RETURN(FLOAT_VAL);
{ident}                     RETURN(IDENTIFIER);
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