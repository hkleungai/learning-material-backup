%option noyywrap

%{
#define YYSTYPE char *
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

/* Add your Flex definitions here */
ws [ \t]+
digits [0-9]
nonzero [1-9]
four [0-4]
five [0-5]
letter [A-Za-z]
prefix [/][ \t]*{digits}+
lbrace [{]
rbrace [}]

%%
interface printf("INTERFACE");
pool printf("POOL ");
whitelist printf("WHITELIST");
blacklist printf("BLACKLIST ");
{prefix} printf("PREFIX ");
{lbrace} printf("LBRACE ");
{rbrace} printf("RBRACE ");
{ws} /* eats up white spaces */
[\n] printf("\n");
<<EOF>> return;
%%

int main(int argc, char *argv[])
{
    FILE *fconfig = fopen(argv[1], "r");
    // make sure it is valid
    if (!fconfig)
    {
        printf ("Error reading file!\n");
        return -1;
    }
    // set lex to read from file
    yyin = fconfig;
    yylex();
    return 0;
}
