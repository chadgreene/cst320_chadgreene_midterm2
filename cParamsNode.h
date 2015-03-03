/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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
        int CalculateSize(int offset);
        
    private:
        list<cParamNode*> m_params;
};
