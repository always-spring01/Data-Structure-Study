#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element *data;      // data는 포인터로 정의한다
    int capacity;       // 현재 용량
    int top;
} StackType;

// init_stack
void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc((s->capacity) * sizeof(element));
}

// is_empty
int is_empty(StackType *s) {
    return (s->top == -1);
}

// is_full
int is_full(StackType *s) {
    return (s->top == s->capacity - 1);
}

// push
void push(StackType *s, element data) {
    if (is_full(s)) {
        s->capacity = s->capacity * 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
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