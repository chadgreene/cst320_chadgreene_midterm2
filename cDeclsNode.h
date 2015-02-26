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
#include "cDeclNode.h"
using std::list;

class cDeclsNode : public cAstNode
{
    public:
        cDeclsNode();
        string toString();
        void Add(cDeclNode* data = nullptr);
        int CalculateSize(int offset);
        int GetSize();
        
    private:
        list<cDeclNode*> m_decls;
};