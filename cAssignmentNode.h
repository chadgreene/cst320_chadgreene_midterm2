/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cStmtNode.h"
#include "ExprNode.h"
#include "cVarRef.h"
#include "IntExpr.h"

class cAssignmentNode : public cStmtNode
{
    public:
        cAssignmentNode(cVarRef* lhs = nullptr, ExprNode* rhs = nullptr);
        string toString();
        bool CanAssign();
        bool CharInRange(ExprNode* node = nullptr);
    
    private:
        cVarRef* m_lhs;
        ExprNode* m_rhs;
};