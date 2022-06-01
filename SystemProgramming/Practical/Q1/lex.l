%{
    #include<stdio.h>
    #include<stdlib.h>
    #include <math.h>
    int length = 0;
    char *lexeme = NULL;
%}


%%
[1|0]{1,4} {length = yyleng; lexeme = (char*)malloc(length); strcpy(lexeme,yytext);}
[ |\t|\n]+ { ; } 
. {;}
%%


int main()
{
    yylex();
    int decimal = 0;
    for(int i = 0; i < length; i++)
    {
        int digit = (int)(lexeme[i]) - 48;
        decimal += pow(2,length-1-i)*digit;
    }
    printf("Decimal of %s - %d\n",lexeme,decimal);
}
int yywrap()
{
    return 1;
}
