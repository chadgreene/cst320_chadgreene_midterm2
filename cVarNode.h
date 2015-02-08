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
#include "cArraySpec.h"
#include "cSymbol.h"

class cVarNode : public cDeclNode
{
    public:
        cVarNode(cSymbol* typeId, cSymbol* identifier, cArraySpec* arraySpec);
        string toString();
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
        cArraySpec* m_arraySpec;
};