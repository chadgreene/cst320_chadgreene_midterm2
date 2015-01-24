/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 3 Bison and Symbol table
 * Date: 1/19/15
 * 
 * Purpose: Populate a symbol table with items from an input file
 * Flex will parse each token from a file when a { is found a new symbol table
 * will be created and items within the enclosing {} will be added to a 
 * hash table along with a unique sequence number.
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
        cSymbolTable();
        void IncreaseScope();
        void DecreaseScope();
        cSymbol* InsertSymbol(string symbol);

    private:
        list<map<string,cSymbol*>*> m_tables;
};