#pragma once

#include "cStmtNode.h"
#include "ExprNode.h"

class cPrintNode : public cStmtNode
{
    public:
        cPrintNode(ExprNode* expr) : m_expr(expr) {}
        string Output() { return std::to_string(m_expr->GetValue()) + "\n"; }
    
    private:
        ExprNode* m_expr;
};