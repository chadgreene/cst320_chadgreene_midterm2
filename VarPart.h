/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "ExprNode.h"
#include "cSymbol.h"
#include "ArrayVal.h"

class VarPart : public ExprNode
{
    public:
        VarPart(cSymbol* val, ArrayVal* ary);
        string toString();
    private:
        cSymbol* m_val;
        ArrayVal* m_ary;
};
