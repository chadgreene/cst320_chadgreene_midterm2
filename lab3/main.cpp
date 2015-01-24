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
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "langparse.h"

extern void *yyast_root;
cSymbolTable * symbolTableRoot;

int main(int argc, char **argv)
{
    std::cout << "Chad Greene" << std::endl;
    symbolTableRoot = new cSymbolTable();
    
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
    while (yyast_root != NULL)
    {
        if (result == 0)
        {
            output << "Successful compilation\n";
        } else {
            output << "Errors in compile\n";
            return result;
        }

        result = yyparse();
    }

    output.close();
    std::cout.rdbuf(cout_buf);
    return result;
}
