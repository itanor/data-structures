#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

stack * new_stack() {
    stack *s = malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

stacknode * build_stacknode() {
    stacknode *new = malloc(sizeof(stacknode));
    new->prev = NULL;
    return new;
}

stacknode * read_stacknode() {
    stacknode *new = build_stacknode();
    printf("Provide a name: ");
    scanf("%[^\n]%*c", new->name);
    return new;
}

void push(stack *stack, stacknode *new) {
    if(is_empty(stack)) {
        stack->top = new;
        return;
    }
    new->prev = stack->top;
    stack->top = new;
}

int raw_pop(stack *stack) {
    if(is_empty(stack)) {
        return 0;
    }
    stacknode *to_free = stack->top;
    stack->top = stack->top->prev;
    free(to_free);
    return 1;
}

stacknode * pop(stack *stack) {
    if(is_empty(stack)) {
        return NULL;
    }
    stacknode *pop = build_stacknode();
    strcpy(pop->name, stack->top->name);

    stacknode *to_free = stack->top;
    stack->top = stack->top->prev;
    free(to_free);
    return pop;
}

void clear_stack(stack *stack) {
    while (raw_pop(stack));
}

stacknode * peek(stack *stack) {
    if (is_empty(stack)) {
        return NULL;
    }
    stacknode *peek = build_stacknode();
    strcpy(peek->name, stack->top->name);
    return peek;
}

int is_empty(stack *stack) {
    return stack->top == NULL ? 1 : 0;
}

void print_is_empty(stack *stack) {
    is_empty(stack) ? printf("empty\n") : printf("not empty\n");
}

void print_stacknode(stacknode *n) {
    printf("Name: %s\n", n->name);
}

void print_stack(stack *stack) {
    printf("\nbegin...\n");
    stacknode *actual = stack->top;
    while(actual != NULL) {
        print_stacknode(actual);
        actual = actual->prev;
    }
    printf("...end\n\n");
}
