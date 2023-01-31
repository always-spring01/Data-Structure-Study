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

polynomical2 terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};// 항 선언 (2개)
int avail = 6;

char compare(int a, int b) {                                                // 두 수의 크기 비교
    if (a > b) return '>';
    else if (a < b) return '<';
    else return '=';
}

void attach(float coef, int expon) {                                        // terms 구조체에 식 추가하는 함수
    if (avail > MAX_TERMS) {
        printf("항의 개수가 너무 큽니다");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail += 1;
    return;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {          // 다항식 연산
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
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);        // Cs와 Ce에는 값을 할당하지 않고, 선언만 하였으므로 포인터를 사용한다
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("Cs : %d, Ce : %d\n", Cs, Ce);
    print_poly(Cs, Ce);
    return 0;
}
