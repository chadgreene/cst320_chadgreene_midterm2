/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cPrintNode.h"

cPrintNode::cPrintNode(ExprNode* expr)
    :m_expr(expr)
{}

string cPrintNode::toString()
{
    return "PRINT: " + m_expr->toString();
}