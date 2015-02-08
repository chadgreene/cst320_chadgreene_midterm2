/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string symbol, bool type)
    :m_symbol(symbol), m_sequence(++symbolCount), m_type(type)
{}

string cSymbol::toString()
{
    return "sym: "+ m_symbol + " " + std::to_string(m_sequence);
}

bool cSymbol::IsType()
{
    return m_type;
}

string cSymbol::GetSymbol()
{
    return m_symbol;
}

void cSymbol::SetTypeFlag()
{
    m_type = true;
}