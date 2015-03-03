/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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
    string retVal = "(FUNC CALL: " + m_identifier->toString();
    
    if(m_params != nullptr)
        retVal += m_params->toString();
        
    retVal += ")";
    
    return retVal;
}

string cFuncCall::GetType()
{
    return m_identifier->GetType();
}

string cFuncCall::GetBaseType()
{
    return GetType();
}

int cFuncCall::CalculateSize(int offset)
{
    m_params->CalculateSize(offset);
    
    return offset;
}