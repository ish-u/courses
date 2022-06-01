%{
    int number_of_vowels = 0;
    int number_of_consonants = 0;
%}
%%
a|e|i|o|u|A|E|I|O|U {number_of_vowels++;}
[A-za-z] {number_of_consonants++;}
[ \n] {}
%%
int main()
{
    yyin = fopen("text.txt","r");
    yylex();
    printf("%i - Vowels\n",number_of_vowels);
    printf("%i - Consonants\n\n",number_of_consonants);
    //number_of_vowels = 0; number_of_consonants = 0;
    return 1;
}
int yywrap()
{
    return 1;
}
