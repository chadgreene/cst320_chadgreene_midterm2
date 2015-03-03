/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cReturnNode.h"

cReturnNode::cReturnNode(ExprNode* expr)
    :m_expr(expr)
{
    m_size = -1;
    m_offset = -1;
}

string cReturnNode::toString()
{
    return "RETURN: " + m_expr->toString();
}

int cReturnNode::CalculateSize(int offset)
{
    m_expr->CalculateSize(offset);
    return offset;
}