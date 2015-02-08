/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cDeclsNode.h"

cDeclsNode::cDeclsNode()
{}

string cDeclsNode::toString()
{
    string retVal = "DECLS:\n{\n";
    
    for(auto &decl : m_decls)
        retVal += decl->toString()+ "\n";
    
    retVal += "}\n";
    
    return retVal;
}

void cDeclsNode::Add(cDeclNode* data)
{
    m_decls.push_back(data);
}