/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once
#include <iostream>
#include <string>
using std::string;

class cAstNode
{
    public:
        virtual string toString() = 0;
        virtual bool SemanticError()
        {
            return m_semanticError;
        }
        
        
    protected:
        bool m_semanticError;
};