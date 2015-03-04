/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "ExprNode.h"
#include "ArrayVal.h"
#include "cSymbol.h"

class VarPart : public ExprNode
{
    public:
        VarPart(cSymbol* identifier = nullptr, ArrayVal* ary = nullptr);
        string toString();
        string GetType();
        cSymbol* GetIdentifier();
        cDeclNode* GetTypeRef();
        void SetIdentifier(cSymbol* identifier);
        string GetBaseType();
        string GetSymbol();
        
    private:
        cSymbol* m_identifier;
        ArrayVal* m_ary;
};
