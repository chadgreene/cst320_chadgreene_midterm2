/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once
#include <map>

#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cSymbol.h"
#include "cStmtNode.h"

using std::map;

class cBlockNode : public cStmtNode
{
    public:
        cBlockNode(map<string,cSymbol*>* symTable = nullptr, cDeclsNode* decls = nullptr, cStmtsNode* stmts = nullptr);
        string toString();
    
    private:
        map<string,cSymbol*>* m_symTable;
        cDeclsNode * m_decls;
        cStmtsNode * m_stmts;
};