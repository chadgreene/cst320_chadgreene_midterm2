/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
        void Add(cDeclNode* data);
        
    private:
        list<cDeclNode*> m_decls;
};