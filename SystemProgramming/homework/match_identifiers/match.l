%{
    int number_of_id = 0;
%}
%%
"//"[A-Za-z0-9 ()!,.'';]* {;}
[<][A-Za-z.]*[>] {;}
include|main|printf|int|float|char|return|args|argv|break|switch|if|else|printf {;}
["][A-Za-z0-9 %!,]*["] {;}
[+|\-|*|^|<|>|=|==|>=|<=|#|\->|~] {;}
[!|&&|||] {;}
[;|.|%|"||'|/|\|,|:|?] {;}
[{|}|(|)|[|]]* {;}
[0-9]* {;}
[ |\n|\t]* {;}
[A-Za-z][A-Za-z]* {number_of_id++;fprintf(yyout,"%s - Identifier\n",yytext);}
%%
int main()
{
    yyin = fopen("sample.c","r");
    yylex();
    printf("\n%i Identifiers\n",number_of_id);
    return 1;
}
int yywrap()
{
    return 1;
}
