/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
    
    retVal += ")\n";
    
    return retVal;
}

void ArrayVal::Add(ExprNode* val)
{
    m_val.push_back(val);
}