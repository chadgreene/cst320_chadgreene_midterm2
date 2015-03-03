/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include "cSymbol.h"
#include "cParamsNode.h"
#include "cStmtNode.h"
#include "ExprNode.h"

class cFuncCall : public cStmtNode, public ExprNode
{
    public:
        cFuncCall(cSymbol* identifier = nullptr, cParamsNode* params = nullptr);
        string toString();
        string GetType();
        string GetBaseType();
        int CalculateSize(int offset);
    
    private:
        cSymbol* m_identifier;
        cParamsNode* m_params;
};