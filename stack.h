
typedef struct stack_ {
    struct stack_node *top;
} stack;

typedef struct stack_node {
    char name[256];
    struct stack_node *prev;
} stacknode;

stack * new_stack();
stacknode *build_stacknode();
stacknode *read_stacknode();
void push(stack *stack, stacknode *new_node);
stacknode *pop(stack *stack);
stacknode *peek(stack *stack);
int is_empty(stack *stack);
void print_is_empty(stack *stack);
void print_stacknode(stacknode *n);
void print_stack(stack *stack);
void clear_stack(stack *stack);
