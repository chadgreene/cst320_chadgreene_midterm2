/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cReturnNode.h"

cReturnNode::cReturnNode(ExprNode* expr)
    :m_expr(expr)
{}

string cReturnNode::toString()
{
    return "RETURN: " + m_expr->toString();
}