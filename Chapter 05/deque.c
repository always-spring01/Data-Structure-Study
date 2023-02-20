#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void init_deque(DequeType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(DequeType *q) {
    return (q->front == q->rear);
}

int is_full(DequeType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType *q) {
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear) {
                break;
            }
        }while (i != q->front);

        printf("\n");
    }
}

void add_rear(DequeType *q, element item) {
    if (is_full(q)){
        printf("에러 : 가득참");
        exit(1);
    }
    q->rear = (++q->rear) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

void add_front(DequeType *q, element item) {
    if (is_full(q)) {
        printf("에러 : 가득참");
        exit(1);
    }
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void delete_rear(DequeType *q) {
    if (is_empty(q)) {
        printf("에러 : 비어있음");
        exit(1);
    }
    return 
}