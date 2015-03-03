/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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

int cWhileNode::CalculateSize(int offset)
{
    m_expr->CalculateSize(offset);
    
    return offset;
}