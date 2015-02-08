/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cDeclNode.h"
#include "cFuncHeader.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"

class cFuncDecl : public cDeclNode
{
    public:
        cFuncDecl(cFuncHeader* header, cDeclsNode* decls = nullptr, cStmtsNode* stmts = nullptr);
        string toString();
    
    private:
        cFuncHeader* m_header;
        cDeclsNode*  m_decls;
        cStmtsNode*  m_stmts;
};