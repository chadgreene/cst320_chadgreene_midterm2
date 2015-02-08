/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <string>
#include "cVarNode.h"
using std::string;

class cParamSpec
{
    public:
        cParamSpec(cVarNode* node);
        string toString();
    
    private:
        cVarNode* m_param;
    
};