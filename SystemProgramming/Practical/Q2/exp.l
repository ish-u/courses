%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h" // from yacc -d
%}

%option noyywrap

%%
[0-9]+(\.[0-9]+)? { return TOKEN; }
[a-z]+ {return TOKEN;}
[+|\-|/|*|(|)] { return yytext[0]; }
[ |\t|\n]+ { ; } 
%%
