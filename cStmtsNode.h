/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <list>
#include "cAstNode.h"
#include "cStmtNode.h"
using std::list;

class cStmtsNode : public cAstNode
{
    public:
        cStmtsNode();
        string toString();
        void Add(cStmtNode* data = nullptr);
        int CalculateSize(int offset);
        
    private:
        list<cStmtNode*> m_stmts;        
};