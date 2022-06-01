%{ 
    // fails to validate expression like "a a +" as invalid  
    int operators = 0;
    int operands = 0;
    int brackets = 0;
%}
%%
[+|\-|*|/] {operators++; }
[{|}|(|)|\[|\]] {brackets++; }
[A-Za-z0-9]+ {operands++; }
[0-9]+("."[0-9]+)? {operands++; }
.
%%

int main()
{
    yylex();
    printf("Brackets: %i\nOperands: %i\nOperators: %i\n\n", brackets, operands, operators);
    if(operands - operators == 1 && brackets%2 == 0)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    return 0;
}
int yywrap()
{
    return 1;
}

