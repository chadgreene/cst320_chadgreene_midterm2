/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cSymbolTable.h"

cSymbolTable* cSymbolTable::m_symbols = nullptr;

cSymbolTable::cSymbolTable()
{
        //Push global map onto table
    m_tables.push_front(new map<string,cSymbol*>());
    
        //Add typedefs into global namespace
    m_tables.front()->insert(std::pair<string,cSymbol*>("char", new cSymbol("char", true)));
    m_tables.front()->insert(std::pair<string,cSymbol*>("int", new cSymbol("int", true)));
    m_tables.front()->insert(std::pair<string,cSymbol*>("float", new cSymbol("float", true)));
}

cSymbolTable* cSymbolTable::GetInstance()
{
        //Gets singleton instance of symboltable
    if(m_symbols == nullptr)
        m_symbols = new cSymbolTable();
    
    return m_symbols;
}

map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
    //Add symbol table to list
    m_tables.push_front(new map<string,cSymbol*>());
    return m_tables.front();
}

void cSymbolTable::DecreaseScope()
{
    //Remove symbol table from stack    
    m_tables.pop_front();
}

cSymbol* cSymbolTable::InsertSymbol(string symbol, bool type)
{
    //Define return variable
    cSymbol * sym;
    
    //Search for symbol already in table
    map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
    
    //Add symbol if it doesn't already exist
    if(it == m_tables.front()->end())
    {
        sym = new cSymbol(symbol, type);
        m_tables.front()->insert(std::pair<string,cSymbol*>(symbol, sym));
    }
    //Otherwise get symbol from symbol table
    else
        sym = it->second;
    
    return sym;
}

cSymbol* cSymbolTable::Lookup(string symbol)
{
        //Iterator for list of maps
    list<map<string,cSymbol*>*>::iterator tbl;
    for(tbl = m_tables.begin(); tbl != m_tables.end(); ++tbl)
    {
            //Search map for symbol
        map<string,cSymbol*>::iterator sym = (*tbl)->find(symbol);
        
            //If found return symbol
        if(sym != (*tbl)->end())
            return sym->second;
    }
    
        //return nothing
    return nullptr;
}