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
#include "cVarRef.h"

class cAssignmentNode: public cStmtNode
{
    public:
        cAssignmentNode(cVarRef* lhs, ExprNode* rhs);
        string toString();
    
    private:
        cVarRef* m_lhs;
        ExprNode* m_rhs;
};