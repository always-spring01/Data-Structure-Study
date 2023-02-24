#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_DEQUE_SIZE];
} DequeType;

void init_deque(DequeType *dq) {
    dq->front = 0;
    dq->rear = 0;
}

int is_empty(DequeType *dq) {
    return dq->front == dq->rear;
}

int is_full(DequeType *dq) {
    if ((dq->rear + 1) % MAX_DEQUE_SIZE == dq->front) {
        return 1;
    }else {
        return 0;
    }
}

void add_rear(DequeType *dq, element item) {
    if (is_full(dq)) {
        printf("오류 : 포화상태");
        exit(1);
    }
    dq->rear = (dq->rear + 1) % MAX_DEQUE_SIZE;
    dq->data[dq->rear] = item;
}

element delete_front(DequeType *dq) {
    if (is_empty(dq)) {
        printf("오류 : 비어있음");
        exit(1);
    }
    dq->front = (dq->front + 1) % MAX_DEQUE_SIZE;
    return dq->data[dq->front];
}

void add_front(DequeType *dq, element item) {
    if (is_full(dq)) {
        printf("오류 : 포화상태");
        exit(1);
    }
    dq->data[dq->front] = item;
    dq->front = (dq->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element delete_rear(DequeType *dq) {
    if(is_empty(dq)) {
        printf("오류 : 비어있음");
        exit(1);
    }
    element val = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return val;
}

int main(void) {
    DequeType dq;
    init_deque(&dq);
    add_rear(&dq, 2);
    printf("%d", delete_rear(&dq));

    return 0;
}