/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "ExprNode.h"
using std::string;

class cSymbol : public ExprNode
{
  public:
    cSymbol(string symbol);
    string GetSymbol();
    void SetValue(int val);
    int GetValue();
    
  private:
    string m_symbol;
    int m_sequence;
    static int symbolCount;
    int m_data;
};