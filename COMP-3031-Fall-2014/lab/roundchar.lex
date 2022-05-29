%option noyywrap

%{
#include <stdio.h>
%}
%%
[a-yA-Y] printf("%c", *yytext+1);
[zZ]     printf("%c", *yytext-25);
.        printf("%c", *yytext);
%%

int main(int argc, char **argv)
{
    yylex();
    return 0;
}
