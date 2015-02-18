/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
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