/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cStructDecl.h"

cStructDecl::cStructDecl(map<string,cSymbol*>* symTable, cDeclsNode* decls, cSymbol* identifier)
    :m_symTable(symTable), m_decls(decls), m_identifier(identifier)
{}

string cStructDecl::toString()
{
    string retVal = "STRUCT: ";
    
    retVal += m_decls->toString() + " " + m_identifier->toString();
    
    return retVal;
}

void cStructDecl::PrintSymbolTable()
{
    std::cout << "My table for " << m_identifier->GetSymbol() << " holds" << std::endl;
     for(auto &sym : *m_symTable)
        std::cout << sym.second->GetSymbol() << std::endl;
}

cSymbol* cStructDecl::Find(string symbol)
{
    cSymbol* retVal = nullptr;
  
    if(m_symTable != nullptr)
    {
        map<string,cSymbol*>::iterator it = m_symTable->find(symbol);
        if(it != m_symTable->end())
            retVal = it->second;
    }
    
    return retVal;
}