/*
Title : polynomial1.c
Date : 2023.01.31
Pages : 77
*/

#include <stdio.h>
#define MAX(a,b) (((a) > (b) ? (a) : (b)))
#define MAX_DEGREE 101
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomical;

polynomical polynomical_add(polynomical A, polynomical B) {
    polynomical C;

    int Apos = 0, Bpos = 0, Cpos = 0;
    int Adegree = A.degree;
    int Bdegree = B.degree;
    C.degree = MAX(Adegree, Bdegree);

    while (Apos <= A.degree && Bpos <= B.degree) {
        if (Adegree > Bdegree) {
            C.coef[Cpos++] = A.coef[Apos++];
            Adegree --;
        }else if (Adegree == Bdegree) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            Adegree --; Bdegree --;
        }else {
            C.coef[Cpos++] = B.coef[Bpos++];
            Bdegree --;
        }
    }

    return C;
}

void print_poly(polynomical a) {
    for (int i = a.degree; i > 0; i--) {
        printf("%3.1fx^%d + ", a.coef[a.degree - i], i);
    }
    printf("%3.1f \n", a.coef[a.degree]);
}

int main(void) {
    polynomical a = {5, {3, 6, 0, 0, 0, 10}};
    polynomical b = {4, {7, 0, 5, 0, 1}};
    polynomical c;

    print_poly(a);
    print_poly(b);
    c = polynomical_add(a, b);
    print_poly(c);

    return 0;
}