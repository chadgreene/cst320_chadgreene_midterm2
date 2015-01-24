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
#pragma once

#include "cSymbolTable.h"
#include "cSymbol.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();

