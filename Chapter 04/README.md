## Chapter 04
> 스택<br>
Pages : 102 ~ 142<br>
Study Date : 2023.02.05

### 4.1 스택
>스택의 개념

- 스택은 후입선출(LIFO : Last In First Out)형태의 자료구조이다.
- 스택에서의 입출력은 맨 위에서만 일어나고 스택의 중간에서는 데이터를 삭제할 수 없다.
- 스택의 입출력이 이뤄지는 부분을 스택 상단(stack top)이라 하고 반대쪽인 바닥부분을 스택 하단(stack botttom)이라고 한다.
- 스택의 요소가 하나도 없는 것을 공백 스택(empty stack)이라고 한다.
- 스택은 특히 **자료의 출력순서가 입력순서의 역순으로 진행**되야 할 때 긴요하게 사용된다.
    - 예를 들어, IDE 프로그램의 되돌리기(undo)기능이 이에 해당한다.
        - 입력한 명령어를 순서대로 스택에 담는다.
        - 사용자가 undo 명령어를 입력하면 스택 상단의 값을 복원한다.
        - 스택 알고리즘으로 LIFO 방식으로 해결한다.
    - 프로그램에서 함수를 실행할 때에도 시스템 스택을 활용하여 호출한다.
        - func1() 스택에 저장
        - func2() 스택에 저장
        - LIFO 방식으로 func2() 실행
        - 남은 func1() 실행
        - 결과값 반환
        - 함수 호출이 일어나면 항상 시스템 스택에 동일한 방법으로 저장되므로, 함수가 자기 자신을 호출하여도 동일한 방법으로 활성 레코드가 만들어졌다가 없어지게 된다.
- 스택을 ADT로 구현하면 아래와 같다.
    - 객체 : 0개 이상의 원소를 가지는 유한 선형 리스트
    - 연산 : create, is_full, is_empty, push, pop, peek(맨 위의 원소를 제거하지 않고 반환한다)

### 4.2 스택의 구현
>앞선 추상자료형 스택을 1차원 배열로 구현해보자
- 우선, 1차원 배열을 전역변수로 선언해서 stack으로 구현해보자
    ```C
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
    ```
    - 해당 스택은 int형 값만을 저장할 수 있는 stack이다.
    - 만약, 스택에 저장되어야 하는 값이 정수나 문자가 아니고 조금 더 복잡한 구조를 갖는 요소이면 어떻게 해야 할지 생각해야 한다.
        - 예를 들자면, 학생(학번, 나이, 성적) 과 같은 구조를 가진 값을 스택으로 구현해야 한다면?
    - 위와 같은 경우 스택 값에 구조체를 넣으면 된다.
- 아래 코드는 위 배열로 구현한 스택의 구조를 바꿔서 구조체로 스택을 구현한 예제이다.
    ```C
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
    ```
    - 위 방법은 구조체를 사용하여 정상적으로 학생정보 스택을 구현하였다.
    - 이러한 방법은 이해하기 쉽지만, 스택을 전역변수로 설정하여 하나의 코드에 1개의 스택만 사용가능하다는 단점이 있다.
- C++, Java와 같은 객체지향언어의 경우 객체지향 개념을 이용하여 우아하게 해결하는데 C에서는 다음과 같이 해결할 수 있다.
- **top과 stack 배열을 하나의 구조체로 결합시키고 이 구조체의 포인터를 함수로 전달**한다.
- 즉, StackType이라는 새로운 구조체 타입을 만들고 여기에 stack배열과 top를 넣는다. 그리고 이 구조체에 대한 포인터를 각 함수의 매개변수로 전달하는 것이다.
- 자세한 구현은 아래 코드를 참고하여 이해.
    ```C
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_STACK_SIZE 100
    #define MAX_STRING 100

    typedef int element;
    typedef struct {
        element data[MAX_STACK_SIZE];
        int top;
    } StackType;

    // init_stack
    void init_stack(StackType *s) {
        s->top = -1;
    }

    // is_empty
    int is_empty(StackType *s) {
        return (s->top == -1);
    }

    // is_full
    int is_full(StackType *s) {
        return (s->top == MAX_STACK_SIZE - 1);
    }

    // push
    void push(StackType *s, element data) {
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
    ```
    - 위의 코드에서는 구조체의 포인터를 각 함수로 전달해야해서 약간 복잡하다.
    - **각 함수에서는 구조체의 포인터를 이용하여 스택을 조작한다.** 이것은 C언어에서의 함수 매개변수 전달 방식이 기본저그로 값 전달 방식이기 때문이다.
    - 즉 **구조체 변수 그대로 (포인터 없이) 매개변수로 전달하면 구조체의 원본이 아닌 복사본이 전달되어 구조체를 편집할 수 없어지기 떄문**이다.
    - 위 코드는 앞서 했던 코드와 달리 여러개의 스택을 생성할 수 있다는 장점이 있다.

### 4.3 동적 배열 스택
- 스택에 1차원 배열을 사용하면, **컴파일 시간에 스택의 크기를 알아야 하는데, 실제로는 아주 어렵다**
- C에서는 malloc()를 호출해서 실행 시간에 메모리를 할당 받을 수 있다.
    ```C
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
    ```
    - 포인터를 활용하여 초기 값을 malloc()을 통해 지정했다.
    - **realloc()을 실행하면 동적 메모리의 크기를 변경하는 함수**이기에 현재 내용은 유지하면서 주어진 크기로 동적 메모리를 다시 할당한다.

### 4.4 스택의 응용: 괄호 검사 문제
>괄호의 쌍이 올바르게 짝지어져 있는지 스택을 활용해 구현해보자.
- 괄호의 조건은 아래와 같다.
    - 조건 1) 왼쪽 괄호의 개수와 오른쪽 괄호의 갯수가 같아야 한다.
    - 조건 2) 같은 종류의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
    - 조건 3) 서로 다른 종류의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로 교차하면 안 된다.
    ```C
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
    ```

### 4.5 스택의 응용 : 후위 표기 수식의 계산
>수식을 표현하는 방벙베는 중위(infix), 후위(postfix), 전위(prefix)의 3가지 방법이 있다.
- 연산자가 피연산자 **뒤에**있는 것을 후위 표기법이라 하고, 프로그래밍에서는 후위 표기법을 선호한다.
- 중위 표기법은 우리가 일상생활에서 쓰는 수식인데, 컴파일러 입장에서는 후위 표기법이 더욱 계산하기 편리하다.
- **후위 표기법에서는 괄호를 표기할 필요가 없는 것이 그 이유**이다.
- 후위 표기식 계산은 스택을 이용해 연산자를 만나면, 스택에서 피연산자를 뽑아와 그 계산 값을 다시 스택에 push하는 방식으로 구현 할 수 있다.
    ```C
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
    ```
    - 후위 표기식이 입력되면, 이를 계산해주는 알고리즘이다.
    - 스택을 이용하면 간단하게 구현이 가능하다!
- 이제 중위표기식을 후위표기식으로 변환하기만 한다면, 컴파일러의 일부를 구현할 수 있다.
    ```C
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
    ```
    - prec로 우선순위를 받아내 진행한다.
    - infix_to_prefix를 통해 우선순위가 높은 연산자가 스택에 있다면 먼저 pop하고, 이후 남은 연산자를 pop한다.
    - 만약, 괄호가 들어온다면 괄혿 닫기가 나올 때 까지 값을 pop한다