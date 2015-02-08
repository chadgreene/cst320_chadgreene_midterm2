/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once
#include <string>
#include <iostream>
#include "cSymbol.h"
#include <map>
#include <list>

using std::string;
using std::map;
using std::list;

class cSymbolTable 
{
    public:
        static cSymbolTable* GetInstance();
        map<string,cSymbol*>* IncreaseScope();
        void DecreaseScope();
        cSymbol* InsertSymbol(string symbol, bool type = false);
        cSymbol* Lookup(string symbol);

    private:
        cSymbolTable();
        list<map<string,cSymbol*>*> m_tables;
        static cSymbolTable* m_symbols;
};