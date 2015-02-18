/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <list>
#include <string>
#include "ExprNode.h"
using std::list;
using std::string;

class ArrayVal
{
    public:
        ArrayVal();
        void Add(ExprNode* val = nullptr);
        string toString();
        
    private:
        list<ExprNode*> m_val;
};