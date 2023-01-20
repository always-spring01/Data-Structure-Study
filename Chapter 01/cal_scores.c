/*
Title : cal_scores.c
Date : 2023.01.20
Pages : 14
*/

#include <stdio.h>

#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS]; // 자료구조

int get_max_score(int n) {  // 주어진 학생의 숫자를 n으로 설정
    int i, largest;
    largest = scores[0];    // 초반 기본 값으로 0번째 index를 최대값으로 설정
    for (int i = 1; i < n; i++) {
        if (scores[i] > largest) {
            largest = scores[i];    // 갱신
        }
    }
    return largest;
}
