/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cFuncDecl.h"

cFuncDecl::cFuncDecl(cSymbol* header, cParamsSpec* params)
    :m_header(header), m_params(params), m_decls(nullptr), m_stmts(nullptr)
{}

string cFuncDecl::toString()
{
    string retVal = "(FUNC: " + m_header->toString();
    
    if(m_params != nullptr)
        retVal += " " + m_params->toString();
    else
        retVal += "()";
        
    if(m_decls != nullptr)
        retVal += "\n" + m_decls->toString();
    
    if(m_stmts != nullptr)
        retVal += "\n" + m_stmts->toString();
    
    retVal += "\n)";
    
    return retVal;
}

void cFuncDecl::SetStmts(cStmtsNode* stmts)
{
    m_stmts = stmts;
}

void cFuncDecl::SetDecls(cDeclsNode* decls)
{
    m_decls = decls;
}