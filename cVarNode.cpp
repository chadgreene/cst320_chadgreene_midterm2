/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cVarNode.h"

cVarNode::cVarNode(cSymbol* typeId, cSymbol* identifier, cArraySpec* arraySpec)
    :m_typeId(typeId), m_identifier(identifier), m_arraySpec(arraySpec)
{}

string cVarNode::toString()
{
    string retVal = "VAR: ";
    
    retVal += m_typeId->toString() + " " + m_identifier->toString();
    if(m_arraySpec != nullptr)
        retVal += " " + m_arraySpec->toString();
    
    return retVal;
}
