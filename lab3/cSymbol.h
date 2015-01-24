/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 3 Bison and Symbol table
 * Date: 1/19/15
 * 
 * Purpose: Populate a symbol table with items from an input file
 * Flex will parse each token from a file when a { is found a new symbol table
 * will be created and items within the enclosing {} will be added to a 
 * hash table along with a unique sequence number.
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
    cSymbol(string symbol);
    string toString();
    
  protected:
    string m_symbol;
    int m_sequence;
    static int symbolCount;
};