/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cWhileNode.h"

cWhileNode::cWhileNode(ExprNode* expr, cStmtNode* stmt)
    :m_expr(expr), m_stmt(stmt)
{}

string cWhileNode::toString()
{
    return "(WHILE: " + m_expr->toString() + "\n" + m_stmt->toString() + "\n)";
}