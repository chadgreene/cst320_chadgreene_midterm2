/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cParamNode.h"

cParamNode::cParamNode(ExprNode* expr)
    :m_expr(expr)
{}

string cParamNode::toString()
{
    return m_expr->toString();
}