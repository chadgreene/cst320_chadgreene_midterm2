/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
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
