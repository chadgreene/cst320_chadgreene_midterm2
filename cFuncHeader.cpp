/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cFuncHeader.h"

cFuncHeader::cFuncHeader(cFuncPrefix* prefix, cParamsSpec* params)
    :m_prefix(prefix), m_params(params)
{}

string cFuncHeader::toString()
{
    string retVal = m_prefix->toString();
    
    if(m_params != nullptr)
        retVal += " " + m_params->toString();
    else
        retVal += "()";
    
    return retVal;
}