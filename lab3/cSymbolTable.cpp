#include "cSymbolTable.h"

cSymbolTable::cSymbolTable()
{}

void cSymbolTable::IncreaseScope()
{
    //Add symbol table to list
    m_tables.push_front(new map<string,cSymbol*>());
}

void cSymbolTable::DecreaseScope()
{
    //Remove symbol table from stack    
    m_tables.pop_front();
}

cSymbol* cSymbolTable::InsertSymbol(string symbol)
{
    //Define return variable
    cSymbol * sym;
    
    //Search for symbol already in table
    map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
    
    //Add symbol if it doesn't already exist
    if(it == m_tables.front()->end())
    {
        sym = new cSymbol(symbol);
        m_tables.front()->insert(std::pair<string,cSymbol*>(symbol, sym));
    }
    //Otherwise get sybol from symbol table
    else
        sym = it->second;
    
    
    return sym;
}