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

class cWhileNode: public cStmtNode
{
    public:
        cWhileNode(ExprNode* expr, cStmtNode* stmt);
        string toString();
    
    private:
        ExprNode* m_expr;
        cStmtNode* m_stmt;
};