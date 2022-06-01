%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h" // from yacc -d
%}


%%
[a] { return A;}
[b] { return B;}
[ |\t|\n]+ { ; } 
%%

int yywrap() 
 { 
  return 1; 
 }