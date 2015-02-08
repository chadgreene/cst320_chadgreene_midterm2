/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 4 Abstract Syntax Tree
 * Date: 2/8/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cVarRef.h"

cVarRef::cVarRef()
{}

string cVarRef::toString()
{
    //In order to get my output to match the test7.correct file I had to do 
    //some funky manipulation, which may just be due to my implementation of
    //the varparts
    string retVal = "";
    
        //Iterator for the list of varparts
    list<VarPart*>::iterator it;
    
        //Loop thought varparts
    for(it = m_parts.begin(); it != m_parts.end(); ++it )
    {
            //Each varpart is assigned '(VarRef:' open tag
        retVal += "(VarRef: " + (*it)->toString();
        
            //If varpart is not the beginning of the list add a closing ')
            //otherwise if the list is greater than 1 skp the closing ')' and add a '\n'
        if(it != m_parts.begin())
            retVal += ")";
        else if(m_parts.size() > 1)
            retVal += "\n";
    }
    
        //finally close the varparts with ')' 
    retVal += ")";
    return retVal;
}

void cVarRef::Add(VarPart* part)
{
    m_parts.push_back(part);   
}