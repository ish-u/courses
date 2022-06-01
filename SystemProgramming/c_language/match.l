%{
    int number_of_id = 0;
%}
%%
"//".* {fprintf(yyout,"%s - Comment\n",yytext);}
"#include "[<][A-Za-z.]*[>] {fprintf(yyout,"%s - Header File\n",yytext); ;}
"#include "["][A-Za-z.]*["] {fprintf(yyout,"%s - Header File\n",yytext); ;}
int {fprintf(yyout,"%s - int Keyword\n",yytext);}
float {fprintf(yyout,"%s - float Keyword\n",yytext);}
auto|break|case|char|const|continue|default|do|double|else|enum|extern|for|goto|if|long|register {fprintf(yyout,"%s - Keyword\n",yytext);}
return|short|signed|sizeof|static|struct|switch|typdef|union|unsigned|void|volatile|while {fprintf(yyout,"%s - Keyword\n",yytext);}
printf|main {fprintf(yyout,"%s - Common Functions in C\n",yytext);}
[+|\-|*|/|%] {fprintf(yyout,"%s - Arithmetic Operator\n",yytext);}
[=|+=|\-=|*=|/=|%=] {fprintf(yyout,"%s - Assignment Operator\n",yytext);}
[==|>|<|!=|>=|<=] {fprintf(yyout,"%s - Relational Operator\n",yytext);}
[&&|\|\||!] {fprintf(yyout,"%s - Logical Operator\n",yytext);}
[&|\||!|^|"|<<|>>] {fprintf(yyout,"%s - Logical Operator\n",yytext);}
[,|\->|?:|;] {fprintf(yyout,"%s - Other Operator\n",yytext);}
["][A-Za-z0-9 %!,]*["] { ; }
[{|}|(|)|[|]]* { ;}
[0-9]* { ;}
[ |\a|\b|\f|\n|\r|\t|\v|\\|\'|\"|\?\nnn|\xhh|\0]* {;}
[A-Za-z][A-Za-z0-9]* {number_of_id++;fprintf(yyout,"%s - Identifier\n",yytext);}
%%
int main()
{
    yyin = fopen("sample.c","r");
    yylex();
    printf("\n%i Identifiers\n",number_of_id);
    return 1;
}
int yywrap()
{
    return 1;
}
