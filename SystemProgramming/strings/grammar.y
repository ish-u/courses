%{
    #include<stdio.h>
    #include<stdlib.h>
    extern int yylex();
    void yyerror(char *msg);
%}

%token A B

%%
S : A X B { printf("Valid String\n\n"); exit(0); }
    ;

X : A X B
    |
    ;

%%

void yyerror(char *msg){
    printf("Invalid String\n\n");
    exit(1);
}

int main(){
  printf("Enter String for Language - (a^nb^n n>=1) : ");
  yyparse();
}