/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 5 Semantic Error Checking
 * Date: 2/18/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "lex.h"

extern cAstNode *yyast_root;
cSymbolTable * symbolTableRoot;

int main(int argc, char **argv)
{
    symbolTableRoot = cSymbolTable::GetInstance();
   
    std::cout << "Chad Greene" << std::endl;
   
    const char *outfile_name;
    int result = 0;
    
    std::streambuf *cout_buf = std::cout.rdbuf();

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }
    std::cout.rdbuf(output.rdbuf());

    result = yyparse();
    
    if (yyast_root != NULL)
    {
        
        if (result == 0)
        {
            output << yyast_root->toString() << std::endl;
        } else {
            output << std::to_string(yynerrs) <<  " Errors in compile\n";
        }
    }

    output.close();
    std::cout.rdbuf(cout_buf);
    return result;
   
}
