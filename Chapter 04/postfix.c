#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element *data;
    int top;
    int capacity;
}StackType;

// init_stack
void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

// is_full
void is_full(StackType *s) {
    if (s->top == s->capacity -1) {
        s->data = (element *)realloc(s->data, s->capacity * 2 * sizeof(element));
    }
}

// is_empty                     (0: 비워있음, 1: 비워있지않음)
int is_empty(StackType *s) {
    if (s->top == -1) {
        return 0;
    }else {
        return 1;
    }
}

// push
void push(StackType *s, element item) {
    is_full(s);
    s->data[++s->top] = item;
}

// pop
int pop(StackType *s) {
    if (is_empty(s) == 0) {
        return -1;
    }else {
        return s->data[s->top--];
    }
}

// peek
int peek(StackType *s) {
    if (is_empty(s) == 0) {
        return -1;
    }else {
        return s->data[s->top];
    }
}

// prec
int prec(char op) {
    switch (op)
    {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// infix_to_prefix
void infix_to_prefix(char exp[]) {
    int i =0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for (i = 0; i < len; i++){
        ch = exp[i];
        switch (ch) {
            case '+': case '-': case '*': case '/':
                while (is_empty(&s) == 1 && (prec(ch) <= prec(peek(&s)))) {
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }

    }
    while (is_empty(&s) == 1) {
        printf("%c", pop(&s));
    }
}

// eval
int eval(char exp[]) {
    int a1, a2, value, i = 0;
    int len = strlen(exp);
    char c;
    StackType s;

    init_stack(&s);
    for (i = 0; i < len; i++) {
        c = exp[i];
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            value = c - '0';       // 피연산자일 경우, int형으로 변환
            push(&s, value);
        }else {
            a2 = pop(&s);
            a1 = pop(&s);
            switch (c)
            {
                case '+': push(&s, a2 + a1); break;
                case '-': push(&s, a2 - a1); break;
                case '*': push(&s, a2 * a1); break;
                case '/': push(&s, a2 / a1); break;
            }
        }
    }
    return pop(&s);
}

int main(void) {
    /*
    int result;
    result = eval("22+");
    printf("%d\n", result);

    return 0;
    */
    char *s = "(2+3)*4";
    infix_to_prefix(s);

    return 0;
}