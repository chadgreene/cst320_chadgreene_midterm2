/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "ExprNode.h"

class BinaryExpr : public ExprNode
{
    public:
        BinaryExpr(ExprNode* lhs, char oper, ExprNode* rhs);
        string toString();
    private:
        ExprNode* m_rhs;
        char m_oper;
        ExprNode* m_lhs;
        
};