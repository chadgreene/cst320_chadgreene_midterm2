/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cVarNode.h"

cVarNode::cVarNode(cSymbol* typeId, cSymbol* identifier)
    :m_typeId(typeId), m_identifier(identifier)
{}

string cVarNode::toString()
{
    string retVal = "VAR: ";
    
    retVal += m_typeId->toString() + " " + m_identifier->toString();
    
    return retVal;
}
