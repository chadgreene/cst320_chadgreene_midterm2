/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(ExprNode* lhs, char oper, ExprNode* rhs)
    :m_lhs(lhs), m_oper(oper), m_rhs(rhs)
{}

string BinaryExpr::toString()
{
    return "(EXPR: " + m_lhs->toString() + " " + m_oper + " " + m_rhs->toString() + ")";
}

string BinaryExpr::GetType()
{
    if(m_lhs->GetType() == "float" || m_rhs->GetType() == "float")
        return "float";
        
    return m_lhs->GetType();
}

string BinaryExpr::GetBaseType()
{
    return GetType();
}

int BinaryExpr::CalculateSize(int offset)
{
    m_lhs->CalculateSize(offset);
    m_rhs->CalculateSize(offset);
    
    return offset;
}