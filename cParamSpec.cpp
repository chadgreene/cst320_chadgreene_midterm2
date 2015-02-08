/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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