%%
[ |\t|\n]+ {fprintf(yyout, " ");}
. { fprintf(yyout, "%s", yytext); }
%%
int main()
{
    yyin = fopen("input.txt","r");
    yyout = fopen("output.txt","w");
    yylex();
    return 1;
}
int yywrap()
{
    return 1;
}

