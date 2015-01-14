#include <iostream>
#include "lex.h"
#include "parse.h"
#include "tokens.h"

int yylval = 0;
int token = -1;
int oldToken = -1;
int workingtoken = 0;
int t = -1;
//*******************************************
void UnGetToken()
{
    token = oldToken;
}
//*******************************************
int GetToken()
{
    if (token > 0)
    {
        oldToken = token;
        token = -1;
    } else {
        oldToken = yylex();
    }

    return oldToken;
}
//*******************************************
bool Error(std::string expecting)
{
    std::cout << "Found " << yytext << " when expecting a " << expecting;
    std::cout << " in line " << yylineno << std::endl;
    int token = GetToken();
    while (token != ';' &&  token != END)
    {
        token = GetToken();
    }
    return false;
}
//*******************************************
bool FindPROG()
{
    t  = GetToken();
    if (t != END)
    {
        UnGetToken();
        if (FindSTMTS())
        {
            t = GetToken(); 
            if (t == END) 
                return true;
            else 
                return Error("End");
        }
        else
            return Error("Program");
    }
    return true;  
}
//*******************************************
bool FindSTMTS()
{
    if (!FindSTMT())
    {
        t = GetToken();
        if (t == END)
        {
            UnGetToken();
            return true;
        }
        UnGetToken();
        if (!FindSTMTS()) 
            return true;
    }     
    else if (!FindSTMTS()) 
        return false;

    return true;
}
//******************************************
bool FindSTMT()
{      
    if(FindEXPR())
    {
        t = GetToken();
        if(t != ';')
            return Error("';'");
    }
    else
        return false;
        
    std::cout << "Found a statement" << std::endl;
    return true;
}
//*******************************************
bool FindEXPR()
{
   
    t = GetToken();
    if (t == '(')
    {
	    if (FindEXPR())
    	{
    	    t = GetToken();
            if (t == ')')
    	        return FindEXPR_P();
    	    else 
    		    return Error("')'");
    	}
    	else
    	    return false;
    }
    else
    {
        UnGetToken();
        return FindTERM();
    }
    return true;
}
//*******************************************
bool FindEXPR_P()
{
    if(FindPLUSOP())
    {
        t = GetToken();
        if (t == '(')
        {
            if (FindEXPR()) 
            {
                t = GetToken();
                if (t == ')')
                    return FindEXPR_P();
                else
                    return Error("')'");
            }  
            else
              return false;
        }
        else
            return Error("'('");
    }
    
    return true;
}
//*******************************************
bool FindTERM()
{
    t = GetToken();
    if (t == '[')
    {
        if (FindEXPR())
        {
            t = GetToken();
            if (t == ']')
                return FindTERM_P();
            else
                return Error("']'");
        }
        else
            return false;
    }
    else if (t == END || t != INT_VAL)
    {
        UnGetToken();
        return false;
    }
    
    return true;
}
//*******************************************
bool FindTERM_P()
{
    if (FindTIMESOP()) 
    {
        t = GetToken();
        if (t == '[')
        {
            if(FindEXPR()) 
            {
                t = GetToken();
                if (t == ']')
                    return FindTERM_P(); 
                else
                    return Error("']'");
            }
            else
                return false;
        }
        else
            return Error("'['");
    }
    
    return true;
}
//*******************************************
bool FindPLUSOP()
{
    t = GetToken();
    if (t == '+' || t == '-') 
        return true;
    
    UnGetToken();
    return false;
}
//*******************************************
bool FindTIMESOP()
{
    t = GetToken();
    if (t == '*' || t == '/') 
        return true;
    
    UnGetToken(); 
    return false;
}