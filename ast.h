typedef enum {
    ADD_EXPR,
    SUB_EXPR,
    MULT_EXPR,
    DIV_EXPR,
    NUM_EXPR,
} expr_type;

struct expr {
    expr_type exprType;
    struct expr *left;
    struct expr *right;
    int value;
};

struct expr *createExpr(expr_type exprType, struct expr *left, struct expr *right, int value){
    struct expr *newExpr = malloc(sizeof *newExpr);
    newExpr->exprType = exprType;
    newExpr->left = left;
    newExpr->right = right;
    newExpr->value = value;

    return newExpr;
}

void printExpr(struct expr *expr){
    if(!expr){
        return;
    }
    switch (expr->exprType)
    {
    case ADD_EXPR:
        printf("Addition: {");
        break;
    case SUB_EXPR:
        printf("Subtraction: {");
        break;
    case DIV_EXPR:
        printf("Division: {");
        break;
    case MULT_EXPR:
        printf("Multiplication: {");
        break;
    case NUM_EXPR:
        printf("Number: { %d ", expr->value);
        break;
    default:
        break;
    }

    if(expr->left){
        printf("left: {");
        printExpr(expr->left);
    }
    if(expr->right){
        printf("right: {");
        printExpr(expr->right);
    }

    printf("}}");
}