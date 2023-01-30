/*
Title : point.c
Date : 2023.01.30
Pages : 75
*/

#include <stdio.h>
#include <math.h>

typedef struct pointTag{    // Point 구조체 선언
    int x;
    int y;
}point;

int get_distance(point p1, point p2) {  // Point 상의 거리를 구하는 함수 get_distance
    int x, y;
    if (p1.x > p2.x) {
        x = p1.x - p2.x;
    }else {
        x = p2.x - p1.x;
    }
    if (p1.y > p2.y) {
        y = p1.y - p2.y;
    }else {
        y = p2.y - p1.y;
    }

    return pow(x,2) + pow(y,2);
}

int main(void) {
    point p1 = {1, 2};
    point p2 = {9, 8};

    printf("%d", get_distance(p1, p2));

    return 0;
}