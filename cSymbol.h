/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using std::string;

class cSymbol
{
  public:
    cSymbol(string symbol, bool type = false);
    string toString();
    bool IsType();
    string GetSymbol();
    void SetTypeFlag();
    
  protected:
    string m_symbol;
    int m_sequence;
    static int symbolCount;
    bool m_type;
};