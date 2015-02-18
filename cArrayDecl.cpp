/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cArrayDecl.h"

cArrayDecl::cArrayDecl(cSymbol* typeId, cSymbol* identifier, cArraySpec* array)
    :m_typeId(typeId), m_identifier(identifier), m_array(array)
{}

string cArrayDecl::toString()
{
    string retVal = "ARRAY: ";
    
    retVal += m_typeId->toString() + " " + m_identifier->toString();
    if(m_array != nullptr)
        retVal += " " + m_array->toString();
    
    return retVal;
}
