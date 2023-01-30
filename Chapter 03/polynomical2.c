/*
Title : polynomical2.c
Date : 2023.01.31
Pages : 81
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct
{
    float coef;     // 계수
    int expon;      // 차수
}polynomical2;

polynomical2 terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};
int avail = 6;

char compare(int a, int b) {
    if a > b return '>';
    else if a < b return '<';
    else return '=';
}

void attach(float coef, int expon) {
    if (avail > MAX_TERMS) {
        printf("항의 개수가 너무 큽니다");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail += 1;
    return;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be) {
        switch
    }
}

