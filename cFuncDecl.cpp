/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cFuncDecl.h"

cFuncDecl::cFuncDecl(cFuncHeader* header, cDeclsNode* decls, cStmtsNode* stmts)
    :m_header(header), m_decls(decls), m_stmts(stmts)
{}

string cFuncDecl::toString()
{
    string retVal = "(FUNC: " + m_header->toString();
    
    // if(m_decls == nullptr && m_stmts == nullptr)
    //     retVal += "()";
    
        
    if(m_decls != nullptr)
        retVal += m_decls->toString();
    
    if(m_stmts != nullptr)
        retVal += m_stmts->toString();
    
    retVal += "\n)";
    
    return retVal;
}