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
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"
using std::map;

class cStructDecl : public cDeclNode
{
    public:
        cStructDecl(map<string,cSymbol*>* symTable = nullptr, cDeclsNode* decls = nullptr, cSymbol* identifier = nullptr);
        string toString();
        void PrintSymbolTable();
        cSymbol* Find(string symbol);
    
    private:
        map<string,cSymbol*>* m_symTable;
        cDeclsNode* m_decls;
        cSymbol* m_identifier;
        
};