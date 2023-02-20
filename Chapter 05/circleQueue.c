#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} QueueType;        // Queue Struct

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q) {
    if (q->front == q->rear) {
        return 1;
    }else {
        return 0;
    }
}

void enqueue(QueueType *q, element item) {
    q->rear = (++q->rear) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q) == 1){
        printf("에러 발생 : 큐가 비어있음");
        exit(0);
    }
    q->front = (++q->front) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
    QueueType q;

    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
}