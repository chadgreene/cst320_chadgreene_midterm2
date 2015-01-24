#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string symbol)
    :m_symbol(symbol), m_sequence(++symbolCount)
{}

string cSymbol::toString()
{
    char buffer[5];
    sprintf(buffer,"%d", m_sequence);
    return "sym: "+ m_symbol + " " + buffer;
}