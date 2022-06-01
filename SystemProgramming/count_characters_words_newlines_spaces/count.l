%{
    int num_blanks = 0, num_lines = 0, num_chars = 0, num_words = 0;
%}
%%
[ ] { ++num_blanks; }
\n { ++num_lines; }
[A-Za-z]+ { ++num_words; num_chars += yyleng; }
%%
int main()
{
   yyin = fopen("sample.txt","r");
   yylex();
   printf( "# of blanks = %d\n# of lines = %d \n# of chars = %d\n# of words = %d\n",
   num_blanks, num_lines, num_chars, num_words);
}
int yywrap()
{
    return 1;
}
