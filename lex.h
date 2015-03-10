/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cSymbolTable.h"
#include "cAstNode.h"
#include "ExprNode.h"
#include "IntExpr.h"
#include "BinaryExpr.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();
extern int yynerrs;

