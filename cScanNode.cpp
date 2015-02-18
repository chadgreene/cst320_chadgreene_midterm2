/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cScanNode.h"

cScanNode::cScanNode(ExprNode* expr)
    :m_expr(expr)
{}

string cScanNode::toString()
{
    return "SCAN: " + m_expr->toString();
}