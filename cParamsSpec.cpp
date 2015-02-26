/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cParamsSpec.h"

cParamsSpec::cParamsSpec()
{
    m_size = -1;
    m_offset = -1;
}

string cParamsSpec::toString()
{
    string retVal = "(PARAMS:";
    
    for(auto &param : m_params)
        retVal += " " +param->toString();
    
    retVal += ")\n";
    
    return retVal;
}

void cParamsSpec::Add(cParamSpec* param)
{
    m_params.push_back(param);
}

int cParamsSpec::CalculateSize(int offset)
{
    m_offset = WordAlign(offset);
    for(auto &param : m_params)
        m_offset = param->CalculateSize(WordAlign(m_offset));
    
    return offset;
}