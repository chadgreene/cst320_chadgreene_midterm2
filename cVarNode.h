/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cDeclNode.h"
#include "cSymbol.h"

class cVarNode : public cDeclNode
{
    public:
        cVarNode(cSymbol* typeId = nullptr, cSymbol* identifier = nullptr);
        string toString();
        cSymbol* GetSymbol();
        int CalculateSize(int offset);
        int GetSize();
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
};