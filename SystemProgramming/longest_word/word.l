%{ 
    char* longest = NULL;
    int length = 0;
%}
%%
[A-Za-z]+ {
    if(length < yyleng)
    {
        length = yyleng;
        longest = (char *)malloc(length);
        strcpy(longest,yytext);
    }
}
.
%%

int main()
{
    yylex();
    printf("%s - %d\n",longest,length);
    free(longest);
}
int yywrap()
{
    return 1;
}

