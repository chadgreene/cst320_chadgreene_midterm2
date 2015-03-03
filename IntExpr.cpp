/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "IntExpr.h"

IntExpr::IntExpr(int val)
    :m_val(val)
{}

string IntExpr::toString()
{
    return "(EXPR: " + std::to_string(m_val) + ")";
}

string IntExpr::GetType()
{
    if(m_val >= -128 && m_val <= 127)
        return "char";
    return "int";
}

string IntExpr::GetBaseType()
{
    return GetType();
}