## Chapter 03
> 배열, 구조체, 포인터<br>
Pages : 70 ~ 102<br>
Study Date : 2023.01.31

### 3.1 배열
>배열의 개념

- 배열(array)는 거의 모든 프로그래밍 언어에서 기본적으로 제공하는 자료형이다.
- 배열은 **동일한 타입의 데이터를 한 번에 여러 개 만들 때** 사용된다.
- 배열을 사용하면 **연속적인 메모리 공간**에 할당되고 **인덱스(index)** 번호를 사용하여 쉽게 접근이 가능하기 때문에 반복 루프를 사용하여 여러 가지 작업을 손쉽게 할 수 있다.

>배열 ADT(추상자료형)

- 배열을 단순히 **연속적인 메모리 공간**으로 보지 말고, 배열의 핵심적인 내용을 추상적으로 살펴보면 다음과 같다.
- 배열은 <인덱스, 값> 쌍으로 이루어진 집합으로 정의할 수 있다.
- 즉, **index가 주어지면 해당하는 값(value)이 대응되는 자료 구조**이다.
- 배열의 경우, create / get / set 연산을 수행할 수 있어야 한다.

>1차원 배열

- C언어에서 1차원 배열은 다음과 같이 선언한다.
        
        int list[n];

- 컴파일러는 배열에 메모리의 연속된 주소를 할당하여 해석한다.
- list[0] (첫번째 요소)의 주소가 기본 주소가 되고, 이후 인덱스의 값의 주소는 기본 주소 + n * (배열 자료형의 크기)가 된다.

>2차원 배열

- C언어에서 2차원 배열은 다음과 같이 선언한다.

        int list[n][m];

- 위와 같은 경우에 n개의 배열에 각 항마다 m개의 항을 가진 배열의 주소값을 할당하는 방식으로 컴파일러는 구현한다.

### 3.2 구조체
>구조체의 개념

- 복잡한 객체에는 다양한 타입의 데이터들이 모여있다. 이때 **다른 타입의 데이터를 묶는 방법을 구조체(structure)**이라고 한다.
- 특정 자료구조와 관련된 데이터를 묶기 위해 구조체를 사용하는 만큼, 구조체에 대한 이해가 필수적이다.
- 구조체의 형식은 다음과 같이 정의한다.
    ```C
    struct 구조체이름 {
        항목1;
        항목2;
        ...
    };
    ```

- 구조체 형식을 위와 같이 정의했다면, 구조체 변수는 다음과 같이 생성한다.
    ```C
    struct 구조체이름 구조체변수;
    ```

- C언어에서는 typedef를 사용하여 구조체를 새로운 타입으로 선언하는 것이 가능하다.
    ```C
    typedef studentTag {
        char name[10];
        int age;
        double gpa;
    }student;
    ```

- 위 경우에는 다음과 같이 구조체 변수를 선언할 수 있다.
    ```C
    student s = {"kim", 20, 4.3};
    ```

- 구조체를 이용해 간단한 프로그램을 작성하면 다음과 같다.
    ```C
    #include <stdio.h>

    typedef struct studentTag {
        char name[10];
        int age;
        double gpa;
    } student;

    int main(void) {
        student a = {
            "Kim", 20, 4.3
        };
        student b = {
            "Park", 21, 4.5
        };

        printf("%s", a.name);

        return 0;
    }
    ```

### 3.3 배열의 응용 : 다항식
>수학에서 나오는 다항식을 배열을 응용한 자료구조로 표현해보자

- 다항식의 일반적인 형태는 다음과 같다.
    - p(x) = a*x^n + ... + b*x^1 + c (a, b, c = 상수)
- 위와 같은 다항식을 프로그래밍 언어에서 특정한 자료구조로 만들어 다항식의 덧셈, 뺄셈, 나눗셈, 곱셈 연산을 편리하게 하고 메모리의 낭비를 줄여보자.
- 첫 번째 방법으로 **모든 차수의 계수값을 배열에 저장하는 방법**이 있다.
    ```C
    #include <stdio.h>
    #define MAX(a, b) ((a > b) ? a : b)
    #define MAX_DEGREE 101

    typedef struct {
        int degree;                 // 차수
        float coef[MAX_DEGREE]      // 다항식의 계수를 모아놓은 float형 배열
    }polynomical                    // 다항식 자료구조를 구현한 구조체 선언

    polynomical poly_add1(polynomical A, polynomical B) {   // 다항식 덧셈 결과 다항식을 반환하는 함수
        polynomical C;
        int Apos = 0, Bpos = 0, Cpos = 0    // 계수 배열 인덱스 변수
        int degree_a = A.degree;
        int degree_b = B.degree;
        C.degree = MAX(degree_a, degree_b); // 결과 다항식 차수 결정

        while (Apos <= A.degree && Bpos <= B.degree) {
            if (degree_a > degree_b) {
                C.coef[Cpos++] = A.coef[Apos++];
                degree_a--;
            }else if (degree_a == degree_b) {
                C.coef[Cpos++] = A.ceof[Apos++] + B.coef[Bpos++];
                degree_a--; degree_b--;
            }else {
                C.coef[Cpos++] = B.coef[Bpos++];
                degree_b--;
            }
        }

        return C
    }

    void print_poly(polynomical P){
        for (int i = p.degree; i > 0; i--) {
            printf("%3.1fx^%d + ", p.coef[p.degree-i], i);   // coef[0] = 상수항, coef[p.degree] = 최고차항
        }
        printf("%3.1fx^%d\n", p.coef[0], 0);                 // 상수항 출력
    }

    int main(void) {
        /*
        메인 함수는 생략
        */
    }
    ```
    - 다만 다항식에 계수가 0인 차수가 많을 경우 비정상적으로 많은 메모리를 차지한다는 한계가 있다.
- 두 번째 방법으로 **다항식에서 0이 아닌 항만을 하나의 전역 배열에 저장하는 방법**이 있다.
    ```C
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_TERMS 101
    typedef struct
    {
        float coef;     // 계수
        int expon;      // 차수
    }polynomical2;

    polynomical2 terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};    // 항 선언 (2개의 다항식)
    int avail = 6;

    char compare(int a, int b) {                                                    // 두 수의 크기 비교
        if (a > b) return '>';
        else if (a < b) return '<';
        else return '=';
    }

    void attach(float coef, int expon) {                                            // terms 구조체에 식 추가하는 함수
        if (avail > MAX_TERMS) {
            printf("항의 개수가 너무 큽니다");
            exit(1);
        }
        terms[avail].coef = coef;
        terms[avail].expon = expon;
        avail += 1;
        return;
    }

    void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {              // 다항식 연산
        float tempcoef;
        *Cs = avail;
        while (As <= Ae && Bs <= Be) {
            switch (compare(terms[As].expon, terms[Bs].expon)) {
                case '>':   // A항이 B항보다 계수가 큰 경우
                    attach(terms[As].coef, terms[As].expon);
                    As++;
                    break;
                case '=':   // A항이 B항과 계수가 같을 경우
                    tempcoef = terms[As].coef + terms[Bs].coef;
                    if (tempcoef) {
                        attach(tempcoef, terms[As].expon);
                    }
                    As ++; Bs ++; break;
                case '<':   // B항이 A항보다 계수가 큰 경우
                    attach(terms[Bs].coef, terms[Bs].expon);
                    Bs++;
                    break;
            }
        }
        for (; As <= Ae; As++) {
            attach(terms[As].coef, terms[As].expon);
        }

        for (; Bs <= Be; Bs++) {
            attach(terms[Bs].coef, terms[Bs].expon);
        }

        *Ce = avail - 1;
    }

    void print_poly(int s, int e) {
        for (int i = s; i < e; i++) {
            printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
        }
        printf("%3.fx^%d\n", terms[e].coef, terms[e].expon);
    }

    int main(void) {
        /*
        메인 함수는 생략
        */
    }
    ```
    - 앞서 만든 polynomical 구조체에 비해 메모리를 효율적으로 사용한다는 장점이 있다.
    - 하지만, **하나의 다항식이 시작하고 끝나는 위치를 기록하는 인덱스를 관리해야 하는 단점**이 공존한다. 또한 **차수를 저장해야 하기 때문에, 일부 형태의 다항식에 따라서는 계수만을 저장하는 첫 번째 방식보다 비효율적**일 수도 있다.

### 3.4 배열의 응용 : 희소행렬
>행렬(matrix)는 자연과학에서 많은 문제를 해결하는데 사용된다.
- 일반적으로 행렬은 **2차원 배열**을 활용해서 행/렬을 구분한다.
- 2차원 배열 표기법은 **희소행렬과 같이 많은 항들이 0으로 되어 있는 행렬에서 메모리의 낭비**가 심해진다는 한계가 있다.
- 만약 앞서 다항식 계산 구조체와 동일하게 0이 아닌 항들만 **<행, 열, 값>** 의 형태로 구현한다면, **전치 행렬과 같은 응용하는 문제에서 큰 프로그래밍적 부하가 온다.**
- 먼저 2차원 배열 표기법의 전치 행렬을 구하는 방법은 아래와 같다.
    - 전치 행렬 : a[i][j] ➡️ a[j][i]
    ```C
    #include <stdio.h>
    #define ROWS 3
    #define COLUMNS 3

    // 행렬 전치 함수
    void matrix_transpose(int A[ROWS][COLUMNS], int B[ROWS][COLUMNS]) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                B[j][i] = A[i][j];
            }
        }
    }

    // 행렬 출력 함수
    void matrix_print(int A[ROWS][COLUMNS]) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
    }

    int main(void) {
        /*
        메인 함수는 생략
        */
    }
    ```
    - matrix_transpose 매개변수 중 A 배열이 원 행렬이고, B 배열이 전치행렬이 된다.
    - **C언어에서 함수의 배열을 전달하면 항상 원본이 전달된다는 점에 유의**해야 한다. 배열의 이름은 포인터의 역할을 하기 때문이다.
- 희소행렬을 효율적으로 표기하기 위한 구조체를 통해 전치행렬을 구하는 방법은 아래와 같다.
    ```C
    #include <stdio.h>
    #define MAX_TERMS 100

    typedef struct {
        int row;
        int col;
        int value;
    }elements;          // 하나의 행렬의 1개 항의 Data<row, col, value>를 저장하는 elements 구조체

    typedef struct SpareMatrix{
        elements data[MAX_TERMS];
        int rows;       // 열의 갯수
        int columns;    // 행의 갯수
        int terms;      // 0이 아닌 항의 갯수
    }SpareMatrix;       // 희소행렬을 정의한 SpareMatrix 구조체

    SpareMatrix matrix_transport2(SpareMatrix A) {
        SpareMatrix B;
        B.rows = A.rows;
        B.columns = A.columns;
        B.terms = A.terms;

        int bIndex;
        if (A.terms > 0) {  // A 행렬에 값이 있는 항이 있다면...
            bIndex = 0;
            for(int i = 0; i < A.columns; i++) {    // A 행렬의 columns를 모두 확인
                for (int j = 0; j < A.terms; j++) { // data의 모든 항을 탐색
                    if (A.data[j].col == i) {       // 해당 columns 값이 있다면?
                        // 여기서 행/렬을 바꿔준다.
                        B.data[bIndex].row = A.data[j].col;
                        B.data[bIndex].col = A.data[j].row;
                        B.data[bIndex].value = A.data[j].value;

                        bIndex ++;
                    }
                }
            }
        }

        return B;
    }

    void matrix_print2(SpareMatrix a) {
        if (a.terms > 0) {
            for(int i = 0; i < a.terms; i++) {
                printf("%d %d %d \n", a.data[i].row, a.data[i].col, a.data[i].value);
            }
        }
    }

    int main(void) {
        /*
        메인 함수는 생략
        */
    }
    ```
    - 0인 항이 많은 희소행렬도 메모리의 낭비 없이 전치 행렬을 구할 수 있게 되었다.
    
### 3.5 포인터
>포인터(pointer)는 다른 변수의 주소를 가지고 있는 변수이다.
- 복잡한 자료구조를 표현하기 위해서는 **Pointer(포인터) 개념**을 확실히 알고 넘어가야 한다.
- 모든 변수는 **메모리 공간에 저장**되고, 메모리의 **각 바이트에는 주소**가 매겨져 있다. 이 주소를 **포인터**에 저장하는 것이다.
- 주소는 동일한 하드웨어이더라도 실시간으로 변할 수 있으므로 포인터 변수는 정확한 숫자로 표현할 수 없다.
- **모든 변수는 각 값에 해당하는 주소를 갖고 있다.**
- 포인터와 관련된 중요한 2가지 연산자는 다음과 같다.
    - & 연산자 : 주소 연산자
        - **변수의 주소를 추출하는 연산자**이다. 앞에서 선언한 포인터가 특정한 변수를 가리키게 설정하려면 해당 연산자를 사용하여 변수의 주소를 추출한다.
    - \* 연산자 : 간접참조 연산자 (역참조 연산자)
        - **포인터가 가르키는 장소에 값을 저장하는 연산자**이다.
- 포인터는 다음과 같이 **여러가지 자료형**에 대하여 선언될 수 있다.
    ```C
    int *p;          // p는 int형 변수의 주소를 의미한다.
    float *pf;       // pf는 float형 변수의 주소를 의미한다.
    char *pc;        // pc는 char형 변수의 주소를 의미한다.
    ```
- **널 포인터**는 **어떤 객체도 가리키지 않는 포인터**이다.
    - 일반적으로 C언어에서 널 포인터는 **NULL**이라는 매크로로 표시한다. 따라서 포인터를 사용하기 전에는 반드시 해당 포인터가 널 포인터인지 확인해야 한다.
    - 포인터가 아무것도 의미하지 않을 때는 항상 **널 포인터로 만들어 두는 것**이 좋다. 널 포인터를 간접참조하려고 하면 시스템에서 오류로 반환되어 쉽게 확인할 수 있기 때문이다.
    - **잘못된 포인터를 가지고 메모리를 변경하는 것**은 치명적인 결과를 가져올 수 있다.
- 포인터는 **함수의 매개변수로 전달**될 수 있다.
    - 특정한 변수를 가리키는 포인터가 함수의 매개변수로 전달되면, **해당 포인터를 통해 함수 내부에서 외부의 값을 변경할 수** 있다.
    - 예시는 다음 swap 함수를 통해 알 수 있다.
    ```C
    #include <stdio.h>

    void swap(int *px, int *py) {
        int tmp;
        tmp = *px;
        *px = *py;
        *py = tmp;
    }

    int main(void) {
        /*
        메인 함수는 생략
        */
    }
    ```
    - 포인터를 사용하지 않으면 **swap 함수 내부에서 외부 변수의 값을 변경할 수 없지만**, 포인터를 활용하면 이가 가능해진다.
- 배열의 경우 배열의 이름이 있는 곳을 **배열의 첫 번째 요소와 대치**시킨다. 즉, 배열에서는 & 연산자 없이 배열의 이름만 써도 포인터의 역할을 수행한다.

### 3.6 동적 메모리 할당
>고정된 크기는 많은 문제를 가져오기에, 동적 메모리 할당이 필요한 것이다.
- C언어에서는 **필요한 만큼의 메모리를 운영체제로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리를 반납하는 기능**을 제공한다. 이 것을 **동적 메모리 할당 (dynamic memory allocation)**이라고 한다.
- 동적 메모리가 할당되는 공간을 **히프(heap)**라고 한다. 히프는 **운영체제가 사용되지 않은 메모리 공간을 모아 놓은 곳**이다.
- 히프에서는 필요한 만큼만 할당을 받고, 반납하기 때문에 메모리를 매우 효율적으로 사용할 수 있다.
- 전형적인 동적 메모리 할당 코드는 다음과 같다.
    ```C
    int *p;
    p = (int *)malloc(sizeof(int));     // 동적 메모리를 p에 할당받는다.
    *p = 1000;                          // 동적 메모리를 사용한다.
    free(p)                             // 동적 메모리를 반납한다.
    ```
    - malloc() 함수는 **size 바이트 만큼의 메모리 블록을 생성하고 시작 주소를 void * 형태로 반환**하므로, 사용자가 사용할 포인터 형태에 따라 형변환이 필요하다.
    - 동적 메모리는 **포인터로만** 사용할 수 있다.
    - free() 함수는 운영체제 할당된 메모리 블록을 **반환**한다. 반드시 malloc() 함수가 제공한 포인터 값은 코딩 도중에 유실되면 안된다.
    - malloc() 함수는 메모리 여유 공간이 없으면 **NULL**을 반환하므로 **항상 NULL 값 인지 확인해야 한다.**
- 동적 메모리를 사용해 다음과 같이 구조체의 메모리도 동적으로 만들 수 있다.
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct Student{
        char name[10];
        int age;
    }Student;

    int main(void) {
        Student *s;

        s = (Student *)malloc(sizeof(Student));
        if (s==NULL) {
            printf("메모리가 부족해서 할당할 수 없습니다.");
            return 0;
        }else {
            strcpy((*s).name, "Park");
            (*s).age = 13;              // s->age 라고도 표현 가능하다.

            printf("%d\n", s->age);
            free(s);                    // 메모리를 반환하기 때문에 Student s의 내용은 초기화된다.
            printf("%d", s->age);

            return 0;
        }
    }
    ```