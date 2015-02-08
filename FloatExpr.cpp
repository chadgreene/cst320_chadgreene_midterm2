/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "FloatExpr.h"

FloatExpr::FloatExpr(double val)
    :m_val(val)
{}

string FloatExpr::toString()
{
    return "(EXPR: " + std::to_string(m_val) + ")";
}
