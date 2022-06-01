%{
    // Matchhing Axuiliary Verb (eg. - is,am,are etc. )
    // Ref :- https://en.wikipedia.org/wiki/Auxiliary_verb

%}
%%
[\t| |\n|,|.|"|'|;]+ // Punctuation, Line Break, White Space
be|being|been|is|am|are|was|were|has|have|having|had|can|could|may|might|will|would|shall|should|do|does|doing|did|must|dare|ought { printf("- %s : Verb\n",yytext);}
[A-Za-z0-9]+ { printf("- %s : Not Verb\n",yytext);}
%%
int main()
{
    yylex();
    return 1;
}
int yywrap()
{
    return 1;
}
