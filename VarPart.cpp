/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "VarPart.h"

VarPart::VarPart(cSymbol* val, ArrayVal* ary)
    :m_val(val), m_ary(ary)
{}

string VarPart::toString()
{
    string retVal = m_val->toString();
    
    if(m_ary != nullptr)
        retVal += "[" + m_ary->toString() + "]";
    
    return retVal;
}
