## Chapter 06
> 연결 리스트 I<br>
Pages : 176 ~ 222<br>
Study Date : 2023.02.24

### 6.1 리스트 추상 데이터 타입
>리스트는 항목을 차례대로 정리한 생활에서 많이 쓰는 자료구조이다.
- 리스트의 항목들은 순서 또는 위치를 가진다.
- 앞에서 진행한 스택과 큐도 넓게 보면 리스트의 일종이라 할 수 있다.
- 리스트는 기호로 다음과 같이 쓰며, 리스트는 집합과 달리 항목 간의 순서가 있다.
    - L = (item0, item1, item2, ... , itemn-1)
- 리스트를 이용한 연산은 다음과 같다.
    - 삽입 연산 ::= 리스트에 값을 추가한다.
    - 삭제 연산 ::= 리스트에 값을 삭제한다.
    - 탐색 연산 ::= 리스트에서 특정한 항목을 찾는다.
- 리스트 ADT (추상 데이터 타입)
    - 객체 : n개의 element 형으로 구성된 순서 있는 모임
    - 연산
        - insert(list, pos, item) ::= pos 위치에 item 요소를 추가한다.
        - insert_last(list, item) ::= 맨 마지막 위치에 item 요소를 추가한다.
        - insert_first(list, item) ::= 맨 처음 위치에 item 요소를 추가한다.
        - delete(list, pos) ::= pos 위치의 요소를 제거한다.
        - clear(list) ::= 리스트의 모든 요소를 제거한다.
        - get_entry(list, pos) ::= pos 위치의 요소를 반환한다.
        - get_length(list) ::= 리스트의 길이를 구한다.
        - is_empty(list) ::= 리스트가 공백상태인지 반환한다.
        - is_full(list) ::= 리스트가 포화상태인지 반환한다.
        - print_list(list) ::= 리스트의 모든 요소를 표시한다.
- 리스트 구현
    - 배열을 이용하면 간단하게 리스트 ADT를 구현할 수 있지만, 크기가 고정되는 단점이 있다.
    - 다른 방법으로는 포인터를 이용해서 연결 리스트를 만드는 방법이 있다. **연결 리스트**는 필요할 때마다 중간에 속지를 추가해서 사용할 수 있는 바인더 공책과 비슷하다.

### 6.2 배열로 구현된 리스트
- 배열을 이용하면 리스트를 간단하게 구현할 수 있고, 빠르다는 장점이 있지만, 리스트 크기가 고정되어 메모리 공간이 부족할 경우 새로운 리스트를 생성해 모든 요소를 복사해야하는 단점이 있다.
- 배열을 이용하여 리스트를 구현하면 순차적인 메모리 공간이 할당되므로, 이것을 리스트의 순차적 표현(sequential representation)이라고도 한다.
- 배열을 사용하면 리스트의 항목을 아주 자연스럽게 저장할 수 있다.
    ```C
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_LIST_SIZE 10

    typedef int element;
    typedef struct {
        element data[MAX_LIST_SIZE];
        int size;
    }ArrayListType;

    void init_array(ArrayListType *a) {
        a->size = 0;
    }

    int is_empty(ArrayListType *a) {
        return a->size == 0;
    }

    int is_full(ArrayListType *a) {
        return a->size == MAX_LIST_SIZE;
    }

    element get_entry(ArrayListType *a, int pos) {
        if (pos < 0 || pos >= a->size) {
            printf("위치 오류");
            exit(1);
        }
        if (is_empty(a)) {
            printf("비어 있음");
            exit(1);
        }
        return a->data[pos];
    }

    void print_array(ArrayListType *a) {
        if (is_empty(a)) {
            printf("비어있음");
        }

        int i;
        for(i = 0; i < a->size; i++) {
            printf("%d | ", a->data[i]);
        }
        printf("\n");
    }

    void insert_last(ArrayListType *a, element item) {
        if (is_full(a) || a->size >= MAX_LIST_SIZE) {
            printf("포화 상태");
            exit(1);
        }
        a->data[a->size] = item;
        a->size += 1;
    }

    void delete_last(ArrayListType *a, element item) {
        if (is_empty(a)) {
            printf("비워 있음");
            exit(1);
        }
        a->size = a->size - 1;
    }

    void insert(ArrayListType *a, int pos, element item) {
        if (!is_full(a) && (pos >= 0) && (pos <= a->size)) {
            for (int i = (a->size - 1); i >= pos; i--) {
                a->data[i + 1] = a->data[i];
            }
            a->data[pos] = item;
            a->size++;
        }
    }

    void delete(ArrayListType *a, int pos) {
        if (!is_empty(a) && (pos >= 0) && (pos <= a->size)) {
            for (int i = pos; i < a->size -1 ; i++) {
                a->data[i] = a->data[i+1];
            }
            a->size--;
        }
    }

    void clear(ArrayListType *a) {
        if (!is_empty(a)) {
            for (int i = 0; i < a->size; i++) {
                delete(a, i);
            }
            a->size = 0;
        }
    }

    int get_length(ArrayListType *a) {
        return a->size;
    }
    ```

### 6.3 연결 리스트
>연결 리스트를 사용하면 동적으로 크기가 변할 수 있고, 삭제나 삽입 시에 데이터를 이동할 필요가 없는 연결된 표현(linked representation)이다.
- 연결된 표현(연결 리스트)는 포인터를 사용하여 구현할 수 있다.
- 연결된 표현은 널리 사용되며 ADT "리스트" 구현 뿐만 ㅇ나ㅣ라 트리,, 그래프, 스택, 큐 등 다양한 자료구조를 구현하는데 사용된다.
- 배열을 이용한 리스트 구현에서 중간 삽입 혹은 삭제할 때, for 구문으로 전체를 변형하는 작업을 해야해서 실행 시간이 오래 걸린다는 단점이 있었다.
- 연결 리스트는 **상자처럼 item을 다른 메모리 영역에 저장하여 pointer를 사용해 줄로 연겷한다**는 방식으로 접근하면 된다.
- 연결 리스트는 **앞 뒤에 있는 데이터를 이동할 필요 없이 줄만 변경시켜주면 된다.**
- 하나의 프로그램 안에는 여러개의 연결 리스트가 존재할 수 있다.
- 다만, 연결 리스트는 **탐색 연산을 할 시, 맨 앞의 index부터 거슬러 올라가야 한다는 단점**이 있다.
- 앞서 설명한 연결 리스트의 item을 **노드(Node)**라고 한다.
- 연결 리스트는 **노드들의 집합**이라고 표현할 수 있다.
- 각 노드는 **데이터 필드(data field)와 링크 필드(link field)**를 가진 그룹이다.
- 데이터 필드에는 우리가 저장하고 싶은 데이터가 들어간다.
- 링크 필드에는 다음 노드를 가르키는 포인터가 저장된다.
- 연결 리스트는 반드시 **첫 번째 노드의 링크 필드**를 알아야 하는데, 이를 **헤드 포인터**라고 한다.
- 그리고 마지막 노드 링크 필드에는 NULL 값을 저장하여 더 이상 가르키는 노드가 없다는 것을 명시한다.
- 연결 리스트의 노드들은 **필요할 때, malloc()을 사용하여** 동적으로 생성한다.
- 연결 리스트의 종류는 다음과 같이 3종류로 구분할 수 있다.
    - 단순 연결 리스트 : 링크 필드에 다음으로 오는 Node를 저장하고 마지막 Node에는 NULL 값이 저장되어 있는 구조
    - 원형 연결 리스트 : 마지막 Node의 링크 필드에 헤드 포인터를 저장하는 구조
    - 이중 연결 리스트 : 각 Node마다 앞의 Node, 뒤의 Node pointer 2개를 저장하는 구조

### 6.4 단순 연결 리스트
>단순 연결 리스트에서는 노드들이 하나의 링크 필드를 가지며 이 링크 필드를 이용하여 모든 노드를 연결한다.
