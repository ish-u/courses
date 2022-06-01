%{
    int num_lines = 0, num_chars = 0;
%}
%%
\n {++num_lines;}
. ++num_chars;
%%
int main()
{
   yyin = fopen("linesAndLetters.txt","r");
   yylex();
   printf( "# of lines = %d \n# of chars = %d\n",
   num_lines, num_chars );
}
int yywrap()
{
    return 1;
}
