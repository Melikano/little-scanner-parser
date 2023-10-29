%{
    // C code
    #include<stdio.h>
    #include"scanner.h"
    #include"ast.h"
    #define YYSTYPE struct expr *
    struct expr *parser_result = 0;
    int yyerror(char *msg);
%}

%error-verbose
%token PLUS MINUS ERROR NUM DIV MULT O_PAREN C_PAREN SEMICOLON

%%
// grammar rules

prog: expr SEMICOLON    {parser_result = $1;}

expr: expr PLUS term    {$$ = createExpr(ADD_EXPR, $1, $3, 0);}
    | expr MINUS term   {$$ = createExpr(SUB_EXPR, $1, $3, 0);}
    | term  {$$ = $1;}

term: term DIV factor   {$$ = createExpr(DIV_EXPR, $1, $3, 0);}
    | term MULT factor  {$$ = createExpr(MULT_EXPR, $1, $3, 0);}
    | factor    {$$ = $1}

factor: O_PAREN expr C_PAREN {$$ = $2}
    | NUM   {$$ = createExpr(NUM_EXPR, 0, 0, atoi(yytext))}
%%

// C code 

int main(int argc, char **argv){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();


    if(result == 0){
        printExpr(parser_result);
        printf("\nparsing successful");
    }else {
        printf("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    printf("parsing failed: %s\n", msg);
    return 1;
}
