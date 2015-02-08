/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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