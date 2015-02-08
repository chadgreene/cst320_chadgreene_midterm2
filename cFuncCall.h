/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
        cFuncCall(cSymbol* identifier, cParamsNode* params);
        string toString();
    
    private:
        cSymbol* m_identifier;
        cParamsNode* m_params;
};