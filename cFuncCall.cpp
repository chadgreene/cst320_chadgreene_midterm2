/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cFuncCall.h"

cFuncCall::cFuncCall(cSymbol* identifier, cParamsNode* params)
    :m_identifier(identifier), m_params(params)
{}

string cFuncCall::toString()
{
    
    return "(FUNC CALL: " + m_identifier->toString() + m_params->toString() + ")\n";
}