/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cIfNode.h"

cIfNode::cIfNode(ExprNode* expr, cStmtNode* stmt1, cStmtNode* stmt2)
    :m_expr(expr), m_stmt1(stmt1), m_stmt2(stmt2)
{}

string cIfNode::toString()
{
    string retVal = "(IF: " + m_expr->toString() + "\n" + m_stmt1->toString() + "\n";
    
    if(m_stmt2 != nullptr)
        retVal += "ELSE:\n" + m_stmt2->toString() + "\n";
    
    retVal += ")";
    
    return retVal;
}