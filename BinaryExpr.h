/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <math.h>
#include "ExprNode.h"

class BinaryExpr : public ExprNode
{
    public:
        BinaryExpr(ExprNode* lhs = nullptr, char oper = '~', ExprNode* rhs = nullptr);
        string toString();
        string GetType();
        string GetBaseType();
    
    private:
        ExprNode* m_rhs;
        char m_oper;
        ExprNode* m_lhs;
        
};