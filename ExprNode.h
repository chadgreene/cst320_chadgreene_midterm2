/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once

#include <string>
#include "cAstNode.h"
#include "cDeclNode.h"
using std::string;

class ExprNode : public cAstNode
{
  public:
    virtual string GetType() = 0;
    virtual string GetBaseType() = 0;
    virtual cDeclNode* GetTypeRef()
    {
      return nullptr;
    }
};