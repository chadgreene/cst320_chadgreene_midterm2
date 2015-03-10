/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string symbol)
    :m_symbol(symbol), m_sequence(++symbolCount), m_data(-1)
{}

string cSymbol::GetSymbol()
{
    return m_symbol;
}

void cSymbol::SetValue(int val)
{
    m_data = val;
}

int cSymbol::GetValue()
{
    return m_data;
}
