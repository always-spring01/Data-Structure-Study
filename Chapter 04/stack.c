#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// init_stack
void init_stack(StackType *s) {
    s->top = -1;
}

// is_empty
int is_empty(StackType *s) {
    return (s->top == -1);
}

// is_full
int is_full(StackType *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

// push
void push(StackType *s, element data) {
    s->data[++(s->top)] = data;
}

// pop
element pop(StackType *s) {
    return s->data[(s->top)--];
}

// peek
element peek(StackType *s) {
    return s->data[(s->top)];
}

int main(void) {
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}