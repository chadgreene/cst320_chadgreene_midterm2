/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
