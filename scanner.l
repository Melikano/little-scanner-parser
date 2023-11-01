%{
    // C code (will be placed at the begining of the scanner.c)

    // The grammar:
    // Program -> Declaration_List
    // Declaration_List = Declaration_List Declaration | Declaration
    // Declaration -> ID : Type = Expr;
    // Type -> int | bool
    // Expr -> Expr + T | Expr - T | T
    // T -> T * F | T / F | F
    // F -> ( E ) | NUM
    #include "parser.h"
%}

DIGIT   [0-9]
LETTER [a-z|A-Z]

%%
"+"     {return PLUS;}
"*"     {return MULT;}
"-"     {return MINUS;}
"/"     {return DIV;}
"("     {return O_PAREN;}
")"     {return C_PAREN;}
";"     {return SEMICOLON;}
"="     {return EQ;}
":"     {return COLON;}
"int"   {return INT;}
"bool"  {return BOOL;}
"array" {return ARRAY;}
"<"     {return L_ANGLE;}
">"     {return R_ANGLE;}


{DIGIT}+    {yylval.num = atoi(yytext); return NUM;}
{LETTER}+   {yylval.id = strdup(yytext); return ID;}

(" "|\t|\n)     /* skip whitespaces */

.   {return ERROR;}   
%%

// C code
// will be placed at the end of the scanner.c
int yywrap(){
    return 1;
}