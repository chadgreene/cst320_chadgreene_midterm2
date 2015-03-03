/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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

int cParamNode::CalculateSize(int offset)
{
    m_expr->CalculateSize(offset);
    
    return offset;
}