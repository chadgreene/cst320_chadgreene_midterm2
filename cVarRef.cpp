/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include "cVarRef.h"

cVarRef::cVarRef()
    :m_error("")
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
        retVal += "(VarRef: " + (*it)->toString() + " ";
    }
    
        //close all the open varref's
    for(size_t i = 0; i < m_parts.size(); ++i)
        retVal += ")";
    
    return retVal;
}

void cVarRef::Add(VarPart* part)
{
        
        //Ensure semantic error is false
    m_semanticError = false;
    
        //If parts has no other values check current symbol table to see if 
        //vairable is defined
    if(m_parts.size() == 0)
    {
            //If variable has not been defined set error flag
        if(!part->GetIdentifier()->IsDeclared())
        {
            m_error = "Symbol " + part->GetIdentifier()->GetSymbol() + " not defined";
            m_semanticError = true;
        }
    }
    else
        m_semanticError = FindSymbolInParent(part);
    
        //If semantic error set up error message
        //Otherwise push part into list
    if(!m_semanticError)
        m_parts.push_back(part);
    
}

string cVarRef::GetType()
{
    return (*m_parts.rbegin())->GetType();
}

cDeclNode* cVarRef::GetTypeRef()
{
    return (*m_parts.rbegin())->GetTypeRef();
}

string cVarRef::GetErrorMsg()
{
    return m_error;
}

string cVarRef::Vref()
{
    //Setup vref return if needed for errors
    string vref = "";
    int count = m_parts.size() - 1;
    for(list<VarPart*>::iterator i = m_parts.begin(); i != m_parts.end(); ++i, --count)
    {
        if(count == 0)
            vref += (*i)->GetIdentifier()->GetSymbol();
        else
            vref += (*i)->GetIdentifier()->GetSymbol() + ".";
    }
    
    return vref;
}

bool cVarRef::FindSymbolInParent(VarPart* part)
{
    cSymbol* sym = nullptr;
    VarPart* vp = *(m_parts.rbegin());
    cStructDecl* struc = nullptr;
    try
    {
        //Try to downcast parent to struct decl
        struc = dynamic_cast<cStructDecl*>(vp->GetTypeRef());
    }
    catch(int e)
    {}
    
        //Try to find symbol in SymbolTable held by struc
    if(struc != nullptr)
        sym = struc->Find(part->GetIdentifier()->GetSymbol());
    else
    {
            //Catch not a struct reference
        m_error = Vref() + " is not a struct";
        return true;
    }
    
        //If symbol was found set current varpart symbol to found symbol
        //Otherwise set semantic error
    if(sym != nullptr)
    {
        symbolTableRoot->RemoveSymbol(part->GetIdentifier());
        part->SetIdentifier(sym);
    }
    else if(!m_semanticError)
    {
        m_error = part->GetIdentifier()->GetSymbol() + " is not a field of " + Vref();
        return true;
    }
    
    return false;
}

string cVarRef::GetBaseType()
{
    //std::cout << "VarRef returning: " <<  (*m_parts.rbegin())->GetIdentifier()->GetSymbol() << " as "<< (*m_parts.rbegin())->GetBaseType() << std::endl;
    return (*m_parts.rbegin())->GetBaseType();
}

string cVarRef::GetSymbol()
{
    return (*m_parts.rbegin())->GetSymbol();
}