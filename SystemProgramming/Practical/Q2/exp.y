%{
    #include<stdio.h>
    #include<stdlib.h>
    extern int yylex();
    int valid = 0;
    void yyerror(char *msg);
%}


%token TOKEN
%type E T F
%%
S : E          { valid = 1;  }
    ;
    
E : E '+' T       
  | E '-' T       
  | T             
  ;

T : T '*' F       
  | T '/' F       
  | F             
  ;

F : '(' E ')'   
  | '-' F       
  | TOKEN         
  ;
%%

void yyerror(char *msg){
    printf("INVALID\n");
    exit(1);
}

int main(){
  yyparse();
  if(valid){
    printf("VALID\n");
  }
  return 0;
}