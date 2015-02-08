#include "cAssignmentNode.h"

cAssignmentNode::cAssignmentNode(cVarRef* lhs, ExprNode* rhs)
    :m_lhs(lhs), m_rhs(rhs)
{}

string cAssignmentNode::toString()
{
    return "(ASSIGN: " + m_lhs->toString() + " = " + m_rhs->toString() + ")" ;
}