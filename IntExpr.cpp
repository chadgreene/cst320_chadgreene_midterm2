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

int IntExpr::GetValue()
{
    return m_val;
}