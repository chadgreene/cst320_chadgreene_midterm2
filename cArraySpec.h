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
using std::list;
using std::string;

class cArraySpec
{
    public:
        cArraySpec();
        string toString();
        void Add(int val = -1);
    
    private:
        list<int> m_array;
};