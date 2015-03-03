/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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
        int CalculateSize(int offset);
        int GetSize();
        int FindSymbolOffset(cSymbol* symbol);
    
    private:
        map<string,cSymbol*>* m_symTable;
        cDeclsNode* m_decls;
        cSymbol* m_identifier;
        void SetSize();
};