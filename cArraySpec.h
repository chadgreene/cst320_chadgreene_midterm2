/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <list>
#include <string>
using std::list;
using std::string;

class cArraySpec
{
    public:
        cArraySpec();
        string toString();
        void Add(int val);
    
    private:
        list<int> m_array;
};