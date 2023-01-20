/*
Title : cal_time.c
Date : 2023.01.20
Pages : 23
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t start, end;
    double duration;
    int tmp = 0;

    start = clock();
    for (int i = 0; i < 1000000; i++) {
        tmp += i;
    }
    end = clock();
    printf("소모된 시간 : %f", (double) (end - start) / CLOCKS_PER_SEC);
}