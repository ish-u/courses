%%
[A-Za-z]+ {
    for(int i = 0; i < yyleng;i++)
    {
        char c = yytext[i];
        int letter = (int)c - (int)'A';
        int cipheredLetter = ((int)'A' + ((letter + 3)%26));
        if((int) c >= (int)'A' && (int) c <= (int)'Z')
        {
            letter = (int)c - (int)'A';
            cipheredLetter = ((int)'A' + ((letter + 23)%26));
        }
        else
        {
            letter = (int)c - (int)'a';
            cipheredLetter = ((int)'a' + ((letter + 23)%26));
        }
        printf("%c",(char)cipheredLetter);
    }
}
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

