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
#include "cArraySpec.h"
#include "cSymbol.h"

class cArrayDecl : public cDeclNode
{
    public:
        cArrayDecl(cSymbol* typeId = nullptr, cSymbol* identifier = nullptr, cArraySpec* array = nullptr);
        string toString();
        int CalculateSize(int offset);
        int GetSize();
        
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
        cArraySpec* m_array;
        void SetSize();
};