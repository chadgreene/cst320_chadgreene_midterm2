/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cFuncPrefix.h"

cFuncPrefix::cFuncPrefix(cSymbol* typeId, cSymbol* identifier)
    :m_typeId(typeId), m_identifier(identifier)
{}

string cFuncPrefix::toString()
{
    return m_identifier->toString();
}