#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;       // 괄호를 저장할 문자 element
typedef struct {
    element *data;
    int top;
    int capacity;
}StackType;

void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
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

int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(&s);          // n : 문자열의 길이
    init_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                push(&s, ch);
                break;
            case ')':
            case '}':
            case ']':
                open_ch = pop(&s);
                if (((open_ch == '(') && ch != ')') || ((open_ch =='{') && ch != '}') || ((open_ch == '[') && ch != ']')) {
                    return 0;
                }
        }
    }

    if (!is_empty(&s)) return 0;
    return 1;
}

int main(void) {
    char *p = "{}";
    if (check_matching(p) == 1) {
        printf("Success");
    }else {
        printf("Fail");
    }
    return 0;
}