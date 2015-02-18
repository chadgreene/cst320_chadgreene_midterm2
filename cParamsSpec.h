/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cStmtNode.h"
#include "cParamSpec.h"

class cParamsSpec : public cStmtNode
{
    public:
        cParamsSpec();
        string toString();
        void Add(cParamSpec* param = nullptr);
        
    private:
        list<cParamSpec*> m_params;
};