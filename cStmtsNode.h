#pragma once

#include <list>
#include "cAstNode.h"
#include "cStmtNode.h"
using std::list;

class cStmtsNode : public cAstNode
{
  public:
    cStmtsNode(){}
    void Add(cStmtNode* node) 
    {
        if(node != nullptr)
            m_stmts.push_back(node);
    }
    
    string Output()
    {
        string retVal = "";
        for(auto &stmt : m_stmts)
            retVal += stmt->Output();
        
        return retVal;
    }
    
    private:
        list<cStmtNode*> m_stmts;
};