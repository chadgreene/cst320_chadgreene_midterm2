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

const int WORD_ALIGN = 4;

class cAstNode
{
    public:
        virtual string toString() = 0;
        virtual int CalculateSize(int offset)
        {
            return offset;
        }
        
        virtual bool SemanticError()
        {
            return m_semanticError;
        }
        
        int WordAlign(int offset)
        {
            while((offset % WORD_ALIGN) != 0)
                offset++;
            return offset;
        }
        
        
    protected:
        bool m_semanticError;
        int m_offset;
        int m_size;
};