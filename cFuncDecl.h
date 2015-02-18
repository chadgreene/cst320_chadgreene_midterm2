/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cSymbol.h"
#include "cParamsSpec.h"
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"

class cFuncDecl : public cDeclNode
{
    public:
        cFuncDecl(cSymbol* header = nullptr, cParamsSpec* params = nullptr);
        string toString();
        void SetStmts(cStmtsNode* stmts = nullptr);
        void SetDecls(cDeclsNode* decls = nullptr);
    
    private:
        cSymbol* m_header;
        cParamsSpec* m_params;
        cDeclsNode*  m_decls;
        cStmtsNode*  m_stmts;
};