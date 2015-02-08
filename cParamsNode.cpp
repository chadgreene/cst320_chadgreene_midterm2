/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cParamsNode.h"

cParamsNode::cParamsNode()
{}

string cParamsNode::toString()
{
    string retVal = "(PARAM:";

    for(auto &param : m_params)
        retVal += param->toString()+" ";
    
    retVal += ")\n";
    return retVal;
}

void cParamsNode::Add(cParamNode* param)
{
    m_params.push_back(param);
}