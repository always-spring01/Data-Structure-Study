#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100          // 스택의 최대 사이즈
typedef int element;                // 데이터의 자료형
element stack[MAX_STACK_SIZE];      // stack 객체를 전역변수로 선언 (1차원 배열)
int top = -1;

// is_empty
int is_empty() {
    return (top == -1);
}

// is_full
int is_full() {
    return (top == (MAX_STACK_SIZE -1));
}

// push
void push(element item) {
    if (is_full()) {
        printf("스택 포화 에러 : 스택 값을 비워주십시오\n");
    }
    stack[++top] = item;
}

// pop
int pop() {
    if (is_empty()) {
        printf("스택 공백 에러 : 스택 값을 push 해주십시오\n");
    }
    return (stack[top--]);
}

// peek
int peek() {
    if (is_empty()) {
        printf("스택 공백 에러 : 스택 값을 push 해주십시오\n");
    }
    return (stack[top]);
}

int main(void) {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}