/*
Title : structure.c
Date : 2023.01.30
Pages : 75
*/

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