typedef enum {
    ADD_EXPR,
    SUB_EXPR,
    MULT_EXPR,
    DIV_EXPR,
    NUM_EXPR,
} expr_type;

typedef enum {
    INT_TYPE,
    BOOL_TYPE,
    ARRAY_TYPE,
} typeKind;

struct decl
{
    char *id;
    struct type *type;
    struct expr *expr;
    struct decl *next;
};

struct decl *createDecl(char *id, struct type *type, struct expr *expr, struct decl *next){
    struct decl *newDecl = malloc(sizeof *newDecl);
    newDecl->id = id;
    newDecl->type = type;
    newDecl->expr = expr;
    newDecl->next = next;

    return newDecl;
}

struct type {
    typeKind kind;
    struct type *subtype;
};

struct type *createType(typeKind kind, struct type *subtype){
    struct type *newType = malloc(sizeof *newType);
    newType->kind = kind;
    newType->subtype = subtype;

    return newType;
}
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

char* getType(struct type *type){
    char* arr = malloc(5);

    switch (type->kind)
    {
        case INT_TYPE:
            return "integer";
        case BOOL_TYPE:
            return "boolean";
        case ARRAY_TYPE:
            return strcat(strcat(arr, "array "), getType(type->subtype));
        default:
            break;
    }
}
void printDecl(struct decl *decl){
    if(!decl){
        return;
    }

    char* typeString = getType(decl->type);

    printf("DECLARATION: { ID: %s, Type: %s, EXPRESSION: {", decl->id, typeString);
    printExpr(decl->expr);
    printDecl(decl->next);
}