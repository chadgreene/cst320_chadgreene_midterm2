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
#include "cParamNode.h"

class cParamsNode : public cStmtNode
{
    public:
        cParamsNode();
        string toString();
        void Add(cParamNode* param = nullptr);
        
    private:
        list<cParamNode*> m_params;
};
