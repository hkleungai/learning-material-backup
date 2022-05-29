%option noyywrap

%{
#define YYSTYPE int
#include "regex.tab.h"
%}

op  [()*?+]
ws  [ \t]+

%%
[a-z]   return CHAR;
{op}|\n return *yytext;
{ws}    /* eat up white spaces */

%%
