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

class FloatExpr : public ExprNode
{
    public:
        FloatExpr(double val = 0.0);
        string toString();
        string GetType();
        string GetBaseType();
        
    private:
        double m_val;
};
