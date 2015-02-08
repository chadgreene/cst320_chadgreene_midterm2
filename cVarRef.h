/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "VarPart.h"
#include "ExprNode.h"

class cVarRef : public ExprNode
{
    public:
        cVarRef();
        string toString();
        void Add(VarPart* part);
    
    private:
        list<VarPart*> m_parts;
};