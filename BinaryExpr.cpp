/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(ExprNode* lhs, char oper, ExprNode* rhs)
    :m_lhs(lhs), m_oper(oper), m_rhs(rhs)
{}

int BinaryExpr::GetValue()
{
    int retVal = 0;
    switch(m_oper)
    {
        case '+':
            retVal = m_lhs->GetValue() + m_rhs->GetValue();
            break;
        case '-':
            retVal = m_lhs->GetValue() - m_rhs->GetValue();
            break;
        case '*':
            retVal = m_lhs->GetValue() * m_rhs->GetValue();
            break;
        case '/':
            if(m_rhs->GetValue() != 0)
                retVal = m_lhs->GetValue() + m_rhs->GetValue();
            break;
    }
    
    return retVal;
}