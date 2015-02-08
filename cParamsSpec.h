/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
        void Add(cParamSpec* param);
        
    private:
        list<cParamSpec*> m_params;
};