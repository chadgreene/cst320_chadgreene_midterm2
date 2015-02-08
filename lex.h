/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cSymbolTable.h"
#include "cAstNode.h"
#include "cStmtNode.h"
#include "ExprNode.h"
#include "cDeclNode.h"
#include "cBlockNode.h"
#include "cPrintNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "IntExpr.h"
#include "FloatExpr.h"
#include "BinaryExpr.h"
#include "cVarRef.h"
#include "VarPart.h"
#include "cVarNode.h"
#include "cArraySpec.h"
#include "ArrayVal.h"
#include "cScanNode.h"
#include "cIfNode.h"
#include "cReturnNode.h"
#include "cWhileNode.h"
#include "cAssignmentNode.h"
#include "cStructDecl.h"
#include "cParamNode.h"
#include "cParamSpec.h"
#include "cParamsNode.h"
#include "cParamsSpec.h"
#include "cFuncPrefix.h"
#include "cFuncHeader.h"
#include "cFuncDecl.h"
#include "cFuncCall.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();

