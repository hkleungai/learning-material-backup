%option noyywrap

%{
#include <stdio.h>
%}

op  [()*?+]
ws  [ \t]+

%%
[a-z]   printf("CHAR ");
{op}    printf("OP ");
\n      printf("RET\n");
{ws}    printf("WS ");

%%

int main()
{
    yylex();
    return 0;
}
