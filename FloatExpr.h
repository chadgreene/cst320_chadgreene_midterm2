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
