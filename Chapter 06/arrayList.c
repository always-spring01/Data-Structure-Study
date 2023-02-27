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

int main(void) {
    ArrayListType a;
    init_array(&a);
    insert_last(&a, 200);
    insert_last(&a, 250);
    print_array(&a);
    printf("%d\n", get_length(&a));
    return 0;
}