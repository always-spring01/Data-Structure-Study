#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;       // Circle Queue Struct

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_full(QueueType *q) {
    if((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        return 1;
    }else {
        return 0;
    }
}

int is_empty(QueueType *q) {
    if(q->front == q->rear) {
        return 1;
    }else {
        return 0;
    }
}

void enqueue(QueueType *q, element item) {
    if (is_full(q) == 1) {
        printf("에러 : 큐가 가득참");
        exit(1);
    }
    q->front = (++q->front) % MAX_QUEUE_SIZE;
    q->data[q->front] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q) == 1) {
        printf("에러 : 큐가 비어있음");
        exit(1);
    }
    q->rear = (++q->rear) % MAX_QUEUE_SIZE;
    return q->data[q->rear];
}

int main(void) {
    QueueType q;
    init_queue(&q);

    srand(time(NULL));
    for(int i = 0; i<100; i++) {
        if (rand() % 5 == 0) {
            enqueue(&q, rand() % 100);
        }else if (rand() % 2 == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}