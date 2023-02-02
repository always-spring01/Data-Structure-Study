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