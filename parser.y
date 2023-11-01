%{
    // C code
    #include<stdio.h>
    #include"scanner.h"
    #include"ast.h"
    struct decl *parser_result = 0;
    int yyerror(char *msg);

    // The grammar:
    // Program -> Declaration_List
    // Declaration_List = Declaration_List Declaration | Declaration
    // Declaration -> ID : Type = Expr;
    // Type -> integer | bool | array Type;
    // Expr -> Expr + T | Expr - T | T
    // T -> T * F | T / F | F
    // F -> ( E ) | NUM
%}

%error-verbose
%token R_ANGLE L_ANGLE ARRAY INT BOOL EQ COLON ID PLUS MINUS ERROR NUM DIV MULT O_PAREN C_PAREN SEMICOLON
%union {
    struct decl *decl;
    struct expr *expr;
    struct type *type;
    char *id;
    int num;
}
%type<decl> prog decl_list decl

%type<id> ID

%type<num> NUM

%type<type> type

%type<expr> expr term factor
 
%%
prog: decl_list    {parser_result = $1;}

decl_list: decl decl_list {$$ = $1; $1->next=$2;} | decl  {$$ = $1;}

decl: ID COLON type EQ expr SEMICOLON     {$$ = createDecl($1, $3, $5, 0);}

type: INT   {$$ = createType(INT_TYPE, 0);}
    | BOOL  {$$ = createType(BOOL_TYPE, 0);}
    | ARRAY L_ANGLE type R_ANGLE {$$ = createType(ARRAY_TYPE, $3);} 

expr: expr PLUS term    {$$ = createExpr(ADD_EXPR, $1, $3, 0);}
    | expr MINUS term   {$$ = createExpr(SUB_EXPR, $1, $3, 0);}
    | term  {$$ = $1;}

term: term DIV factor   {$$ = createExpr(DIV_EXPR, $1, $3, 0);}
    | term MULT factor  {$$ = createExpr(MULT_EXPR, $1, $3, 0);}
    | factor    {$$ = $1}

factor: O_PAREN expr C_PAREN {$$ = $2}
    | NUM   {$$ = createExpr(NUM_EXPR, 0, 0, $1)}

    
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
        printDecl(parser_result);
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
