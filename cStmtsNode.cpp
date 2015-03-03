/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cStmtsNode.h"

cStmtsNode::cStmtsNode()
{
    m_size = -1;
    m_offset = -1;
}

string cStmtsNode::toString()
{
    string retVal = "STMTS:\n{\n";
    for(auto &stmt : m_stmts)
        retVal += stmt->toString()+ "\n";
    retVal += "}\n";
    return retVal;
}

void cStmtsNode::Add(cStmtNode* data)
{
    m_stmts.push_back(data);
}

int cStmtsNode::CalculateSize(int offset)
{
    m_offset = offset;
    for(auto &stmt : m_stmts)
        m_offset = stmt->CalculateSize(m_offset);
    
    return offset;
        
}