#include "cAssignmentNode.h"

cAssignmentNode::cAssignmentNode(cVarRef* lhs, ExprNode* rhs)
    :m_lhs(lhs), m_rhs(rhs)
{
        //When creating new node set semantic error based on wether
        //LHS memory size can hold RHS
    m_semanticError = CanAssign();
}

string cAssignmentNode::toString()
{
    return "(ASSIGN: " + m_lhs->toString() + " = " + m_rhs->toString() + ")" ;
}

bool cAssignmentNode::CanAssign()
{
    bool retVal = true;
    
        //If types do not match check base types
    if(m_lhs->GetType() != m_rhs->GetType())
    {
        
        //If base types match return false otherwise check datatypes
        if(m_lhs->GetBaseType() != m_rhs->GetBaseType())
        {
            switch(m_lhs->GetBaseType()[0])
            {
                case 'c': //char
                    break;
                case 'f': //float
                    if(m_rhs->GetBaseType() == "int" || m_rhs->GetBaseType() == "char")
                        retVal = false;
                    break;
                case 'i': //int
                    if(m_rhs->GetBaseType() == "char")
                        retVal = false;
                    break;
            }
        }
        else
            retVal = false;
    }
    else
        retVal = false;
        
    return retVal;
}

int cAssignmentNode::CalculateSize(int offset)
{
    m_lhs->CalculateSize(offset);
    m_rhs->CalculateSize(offset);
    
    return offset;
}