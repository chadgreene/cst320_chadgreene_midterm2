/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "ArrayVal.h"

ArrayVal::ArrayVal()
{}


string ArrayVal::toString()
{
    string retVal = "(ARRAYVAL:";
    
    for(auto &expr : m_val)
        retVal += " " + expr->toString();
    
    retVal += ")";
    
    return retVal;
}

void ArrayVal::Add(ExprNode* val)
{
    m_val.push_back(val);
}