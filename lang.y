/*******************************************************************************
 * Author: Chad Greene
 * Lab: Lab 6 Calculate node sizes and offsets
 * Date: 3/4/15
 * 
 * Purpose: Build an abstract syntax tree by using Bison/Lex to parse a source
 * file into appropriate nodes
*******************************************************************************/
%{
#include <iostream>
#include "lex.h"
%}

%locations

%union{
    int             int_val;
    char            op_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    ExprNode*       expr_node;
    
    }

%{
    int yyerror(const char *msg);
    void semantic_error(std::string msg);

    cAstNode *yyast_root;
%}

%start  program

%token <symbol>     IDENTIFIER
%token <int_val>    INT
%token <op_val>     OP

%token PRINT END
%token  JUNK_TOKEN

%type <ast_node> program
%type <block_node> block
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> expression


%%

program: block                   { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  stmts END ';'           {
                                    $$ = new cBlockNode($1);
                                }
stmts:  stmts stmt              {
                                    $$ = $1;
                                    $$->Add($2);
                                }
    |   stmt                    {
                                    $$ = new cStmtsNode();
                                    $$->Add($1);
                                }
stmt:  expression IDENTIFIER ';'
                                {
                                    $2->SetValue($1->GetValue());
                                    $$ = nullptr;
                                }
    |   expression PRINT ';'    {
                                    $$ = new cPrintNode($1);
                                }
    
expression: INT                 {
                                    $$ = new IntExpr($1);
                                }
    |       IDENTIFIER          {
                                    $$ = $1;
                                }
    |       expression expression OP
                                {
                                    $$ = new BinaryExpr($1, $3, $2);
                                }
%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

void semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg <<
                 " on line " << yylineno << std::endl;
    
    yynerrs++;
}