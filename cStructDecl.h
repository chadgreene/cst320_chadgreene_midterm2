/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
        cStructDecl(map<string,cSymbol*>* symTable, cDeclsNode* decls, cSymbol* identifier);
        string toString();
    
    private:
        map<string,cSymbol*>* m_symTable;
        cDeclsNode* m_decls;
        cSymbol* m_identifier;
        
};