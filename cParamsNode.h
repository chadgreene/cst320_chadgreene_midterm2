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
#include "cParamNode.h"

class cParamsNode : public cStmtNode
{
    public:
        cParamsNode();
        string toString();
        void Add(cParamNode* param);
        
    private:
        list<cParamNode*> m_params;
};
