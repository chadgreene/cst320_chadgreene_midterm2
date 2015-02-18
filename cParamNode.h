/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "ExprNode.h"

class cParamNode
{
    public:
        cParamNode(ExprNode* expr = nullptr);
        string toString();
    
    private:
        ExprNode* m_expr;
};