#include <stdio.h>
#define ROWS 3
#define COLUMNS 3

// 행렬 전치 함수
void matrix_transpose(int A[ROWS][COLUMNS], int B[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            B[j][i] = A[i][j];
        }
    }
}

// 행렬 출력 함수
void matrix_print(int A[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int array1[ROWS][COLUMNS] = {{2, 3, 0},
                                 {8, 9, 1},
                                 {7, 0, 5}};
    int array2[ROWS][COLUMNS];

    matrix_transpose(array1, array2);
    matrix_print(array1);
    printf("\n");
    matrix_print(array2);

    return 0;
}