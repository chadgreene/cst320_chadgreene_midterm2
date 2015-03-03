/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cParamSpec.h"

cParamSpec::cParamSpec(cVarNode* node)
    :m_param(node)
{}

string cParamSpec::toString()
{
    return m_param->toString();
}

int cParamSpec::CalculateSize(int offset)
{
    return m_param->CalculateSize(offset);
}