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
#include "ExprNode.h"

class cIfNode: public cStmtNode
{
    public:
        cIfNode(ExprNode* expr, cStmtNode* stmt1, cStmtNode* stmt2 = nullptr);
        string toString();
    
    private:
        ExprNode* m_expr;
        cStmtNode* m_stmt1;
        cStmtNode* m_stmt2;
};