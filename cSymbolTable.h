/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
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
        cSymbol* InsertSymbol(string symbol);
        cSymbol* Lookup(string symbol);
        bool InCurrentScope(string symbol);
        void RemoveSymbol(cSymbol* symbol);

    private:
        cSymbolTable();
        list<map<string,cSymbol*>*> m_tables;
        static cSymbolTable* m_symbols;
};