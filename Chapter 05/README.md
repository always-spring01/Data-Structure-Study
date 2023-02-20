## Chapter 05
> 큐<br>
Pages : 146 ~ 176<br>
Study Date : 2023.02.20

### 5.1 큐 추상 데이터 타입
>큐(Queue)는 선입선출(FIFO) 구조를 갖고 있다.

- 선입선출(First In First Out) 구조란, 순서에 들어온 순서로 빠져나가는 형태를 의미한다. 스택(Stack)의 경우, 가장 위에서부터 나가지만, 큐(Queue)는 반대로 쌓인 순서대로 나가는 것이다.
- 큐는 스택과 달리 삽입과 삭제가 같은 쪽에서 일어나는 것이 아니라 각각 다른 쪽에서 일어난다.
- 큐에서 삽입이 일어나는 부분을 후단(rear)이라고 하고, 삭제가 일어나는 부분을 전단(front)라고 한다.
- 추상 자료형 큐의 연산들을 추상 자료형 스택과 아주 유사하다. 
- is_full(), is_empty()는 스택 연산과 동일하다.
- 단, 스택과 달리 Queue에서는 enqueue, dequeue 연산이 아주 중요한데, 1개의 변수만 사용하는 스택과 달리 큐에서는 삽입이 일어나는 rear, 삭제가 일어나는 front 2개의 변수가 사용되어야 한다.
- 큐도 스택과 마찬가지로, "프로그래밍 도구"로서 폭넓게 사용된다. 주로 프로그래밍 과정에서 순서대로 일을 처리할 때 큐 대기열을 적용해서 순서대로 처리한다.
- 큐도 스택과 마찬가지로 **배열과 연결 리스트**를 활용해서 구현할 수 있다.

### 5.2 선형 큐
>1차원 배열로 큐를 구성해보자.

- 먼저 정수의 1차원 배열을 선언하고, rear, front 변수를 차례로 선언한다. front는 큐의 첫 번째 요소 (삭제)를 가르키고 rear는 큐의 마지막 요소 (삽입)을 의미한다.
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX_QUEUE_SIZE 5

    typedef int element;
    typedef struct {
        int front;
        int rear;
        element data[MAX_QUEUE_SIZE];
    } QueueType;        // Queue Type

    void error(char *message) {
        exit(1);
    }

    void init_queue(QueueType *q) {
        q->rear = -1;
        q->front = -1;
    }

    void queue_print(QueueType *q) {
        for (int i =0; i < MAX_QUEUE_SIZE; i++) {
            if (i <= q->front || i > q->rear) {
                printf(" | ");
            }else {
                printf("%d | ", q->data[i]);
            }
        }
        printf("\n");
    }

    int is_full(QueueType *q) {
        if (q->rear == MAX_QUEUE_SIZE - 1) {
            return 1;
        }else {
            return 0;
        }
    }

    int is_empty(QueueType *q) {
        if (q->front == q->rear) {
            return 1;
        }else {
            return 0;
        }
    }

    void enqueue(QueueType *q, int item) {
        if (is_full(q)) {
            printf("큐가 포화상태입니다");
        }else {
            q->data[++(q->rear)] = item;
        }
    }

    int dequeue(QueueType *q) {
        int item = q->data[++(q->front)];

        return item;
    }

    int main(void) {
        int item = 0;
        QueueType q;

        init_queue(&q);

        enqueue(&q, 10);    queue_print(&q);
        enqueue(&q, 20);    queue_print(&q);
        dequeue(&q);        queue_print(&q);
        dequeue(&q);        queue_print(&q);

        return 0;
    }
    ```

### 5.3 원형 큐
>선형 큐는 이해하기는 쉽지만 front와 rear 값이 계속 증가하기에 배열의 앞부분을 재활용할 수 없다는 문제가 있다.

- 원형 큐를 사용하면, 선형 큐와 달리 무한으로 메모리 낭비를 줄이면서 사용가능하다.
- 원형 큐에서는 front와 rear의 개념이 약간 변형되는데, front, rear 모두 초기값은 배열의 0으로 지정한다. 이후 삽입할 때에는 먼저 rear의 값을 증가하고 증가한 배열에 값을 삽입한다. 삭제도 동일하게 front를 먼저 증가시키고 값을 삭제하는 방식으로 진행한다.
- front == rear이면 큐가 비어있음을 의미한다.
- 원형큐에서는 항상 **하나의 자리를 비워둔다**. 왜냐하면 포화 상태와 공백 상태를 구별하기 위함이다. 

    ```C
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
    ```

### 5.4 큐의 응용 : 버퍼
>큐는 주로 서로 다른 속도로 실행되는 프로세스 간의 상호 작용을 조화시키는 버퍼 역할을 담당한다.

- 생산자-소비자 프로세스 : 큐를 버퍼로 사용한다.
- 교통 관리 시스템 : 신호등을 순차적으로 제어하는 과정에서 원형큐가 사용된다.
- CPU 스케줄링 : 운영체제에서 CPU에 프로세스를 할당하는 과정에서 사용된다.
- 큐를 버퍼처럼 일정한 비율로 난수를 생성해서 큐에 입력하고, 일정한 비율로 큐에서 정수로 꺼내는 프로그램을 작성하면 다음과 같다. 생산 비율이 소비 비율보다 높으므로 포화상태가 될 확률이 비약적으로 늘어난다는 점을 유의하자.
    ```C
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
    ```

### 5.5 덱이란?
>덱(deque)는 double-ended queue의 줄임말로서 큐의 front와 rear에서 모두 삽입과 삭제가 가능한 큐를 의미한다.

- 그럼에도 큐와 동일하게 중간에서 값을 삽입하는 것은 허용하지 않는다.
- 덱은 큐와 스택의 연산을 모두 가지고 있는 것이 특징이다. 예를 들자면, add_front와 delete_front 연산은 스택의 push와 pop과 동일하다.
- 또한 delete_front와 add_rear 연산은 큐의 enqueue, dequeue와 동일하다.
- 덱은 원형 큐와 동일한 구조를 지니며 코드화하면 아래와 같다.