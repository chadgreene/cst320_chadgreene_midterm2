/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "ExprNode.h"

class IntExpr : public ExprNode
{
    public:
        IntExpr(int val = -1);
        int GetValue();
        
    private:
        int m_val;
};