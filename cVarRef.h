/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "VarPart.h"
#include "ExprNode.h"
#include "cStructDecl.h"
#include "cSymbolTable.h"

extern cSymbolTable* symbolTableRoot;

class cVarRef : public ExprNode
{
    public:
        cVarRef();
        string toString();
        void Add(VarPart* part = nullptr);
        string GetType();
        cDeclNode* GetTypeRef();
        string GetErrorMsg();
        string Vref();
        bool FindSymbolInParent(VarPart* part);
        string GetBaseType();
        string GetSymbol();
    
    private:
        list<VarPart*> m_parts;
        string m_error;
};