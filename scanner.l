%{
    // C code (will be placed at the begining of the scanner.c)

    // The grammar:
    // E -> E + T | E - T | T
    // T -> T * F | T / F | F
    // F -> ( E ) | NUM
    #include "parser.h"
%}

DIGIT   [0-9]

%%
"+"     {return PLUS;}
"*"     {return MULT;}
"-"     {return MINUS;}
"/"     {return DIV;}
"("     {return O_PAREN;}
")"     {return C_PAREN;}
";"     {return SEMICOLON;}

{DIGIT}+    {return NUM;}

(" "|\t|\n)     /* skip whitespaces */

.   {return ERROR;}   
%%

// C code
// will be placed at the end of the scanner.c
int yywrap(){
    return 1;
}