/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cBlockNode.h"

cBlockNode::cBlockNode(map<string,cSymbol*>* symTable, cDeclsNode* decls, cStmtsNode* stmts)
    :m_symTable(symTable), m_decls(decls), m_stmts(stmts)
{}

string cBlockNode::toString()
{
    string retVal = "BLOCK:\n{\n";
    if(m_decls != nullptr)
        retVal += m_decls->toString();
    if(m_stmts != nullptr)
        retVal += m_stmts->toString();
    
    retVal += "\n}";
    return retVal;
}
