/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cStmtsNode.h"

cStmtsNode::cStmtsNode()
{}

string cStmtsNode::toString()
{
    string retVal = "STMTS:\n{\n";
    for(auto &stmt : m_stmts)
        retVal += stmt->toString()+ "\n";
    retVal += "}";
    return retVal;
}

void cStmtsNode::Add(cStmtNode* data)
{
    m_stmts.push_back(data);
}