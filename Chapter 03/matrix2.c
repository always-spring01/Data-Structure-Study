#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
}elements;          // 하나의 행렬의 1개 항의 Data<row, col, value>를 저장하는 elements 구조체

typedef struct SpareMatrix{
    elements data[MAX_TERMS];
    int rows;       // 열의 갯수
    int columns;    // 행의 갯수
    int terms;      // 0이 아닌 항의 갯수
}SpareMatrix;       // 희소행렬을 정의한 SpareMatrix 구조체

SpareMatrix matrix_transport2(SpareMatrix A) {
    SpareMatrix B;
    B.rows = A.rows;
    B.columns = A.columns;
    B.terms = A.terms;

    int bIndex;
    if (A.terms > 0) {  // A 행렬에 값이 있는 항이 있다면...
        bIndex = 0;
        for(int i = 0; i < A.columns; i++) {    // A 행렬의 columns를 모두 확인
            for (int j = 0; j < A.terms; j++) { // data의 모든 항을 탐색
                if (A.data[j].col == i) {       // 해당 columns 값이 있다면?
                    // 여기서 행/렬을 바꿔준다.
                    B.data[bIndex].row = A.data[j].col;
                    B.data[bIndex].col = A.data[j].row;
                    B.data[bIndex].value = A.data[j].value;

                    bIndex ++;
                }
            }
        }
    }

    return B;
}

void matrix_print2(SpareMatrix a) {
    if (a.terms > 0) {
        for(int i = 0; i < a.terms; i++) {
            printf("%d %d %d \n", a.data[i].row, a.data[i].col, a.data[i].value);
        }
    }
}

int main(void) {
    SpareMatrix m = {
        {
            {0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}
        },
        6,
        6,
        7
    };

    SpareMatrix result = matrix_transport2(m);
    matrix_print2(m);
    printf("\n");
    matrix_print2(result);

    return 0;
}