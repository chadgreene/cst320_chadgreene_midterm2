#pragma once

#include "cAstNode.h"
#include "cStmtsNode.h"

class cBlockNode : public cAstNode
{
    public:
        cBlockNode(cStmtsNode* stmts) : m_stmts(stmts) {}
        string Output()
        {
            return m_stmts->Output();
        }
    
    private:
        cStmtsNode* m_stmts;
    
    
};