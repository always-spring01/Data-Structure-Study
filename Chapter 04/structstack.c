#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
    int student_no;
    char name[MAX_STRING];
    float grade;
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

// is_empty
int is_empty() {
    return (top == -1);
}

// is_full
int is_full() {
    return (top == MAX_STACK_SIZE -1);
}

// push
void push(element item) {
    if (is_full()) {
        printf("스택 용량을 초과합니다\n");
    }else {
        stack[++top] = item;
    }
}

// pop
element pop() {
    if (is_full()) {
        printf("스택에 값이 없습니다\n");
        exit(1);
    }else {
        return stack[top--];
    }
}

// peek
element peek() {
    if (is_full()) {
        printf("스택에 값이 없습니다\n");
        exit(1);
    }else {
        return stack[top];
    }
}

int main(void) {
    element a = {
        20203145,
        "CHB",
        4.5
    };

    element b = {
        20203144,
        "CB",
        2.3
    };

    push(a);
    push(b);
    printf("%d\n", pop().student_no);
    printf("%d\n", pop().student_no);
    

    return 0;
}