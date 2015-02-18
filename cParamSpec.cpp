/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
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