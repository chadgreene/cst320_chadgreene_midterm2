/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <string>
#include "cVarNode.h"
#include "cStmtNode.h"
using std::string;

class cParamSpec : public cStmtNode
{
    public:
        cParamSpec(cVarNode* node = nullptr);
        string toString();
        int CalculateSize(int offset);
        
    private:
        cVarNode* m_param;
    
};