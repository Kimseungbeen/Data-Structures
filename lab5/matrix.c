#include <stdio.h>
#include <stdlib.h>

// 행렬을 위한 메모리 할당 함수
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("메모리 할당 실패\n");
            exit(1);
        }
    }
    return matrix;
}

// 행렬에 랜덤 값 채우는 함수
void fillMatrixRandom(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // 0부터 99 사이의 랜덤 값 생성
        }
    }
}

// 행렬에 할당된 메모리를 해제하는 함수
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// 행렬 A와 B의 행(row)과 열(column)의 값을 입력 받는다. scanf 사용
void inputMatrixSize(int *rows, int *cols) {
    printf("행(row)과 열(column)의 값을 입력 하세요 >>");
    scanf("%d %d", rows, cols);
}

// d 행렬을 출력하는 함수
void printMatrix(int** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// e 두 행렬의 덧셈 연산을 수행하는 함수
int** additionMatrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

// f 두 행렬의 뺄셈 연산을 수행하는 함수
int** subtractionMatrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

// g 행렬 A의 전치행렬 T를 구하는 함수
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// h 두 행렬의 곱셈 연산을 수행하는 함수
int** multiplyMatrix(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** result = allocateMatrix(rowsA, colsB); // 결과 행렬의 크기는 rowsA × colsB가 되어야 합니다.
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}


int main() {
    int rowsA, colsA, rowsB, colsB;
    printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
    // 행렬 A와 B의 행(row)과 열(column)의 값을 입력 받는다.
    printf("행렬 A의 ");
    inputMatrixSize(&rowsA, &colsA);
    printf("행렬 B의 ");
    inputMatrixSize(&rowsB, &colsB);

    // 동적 메모리 할당 방식으로 행렬을 생성한다.
    int** matrixA = allocateMatrix(rowsA, colsA);
    int** matrixB = allocateMatrix(rowsB, colsB);

    // random 값으로 행렬의 채운다.
    fillMatrixRandom(matrixA, rowsA, colsA);
    fillMatrixRandom(matrixB, rowsB, colsB);

    // Print Matrix - A와 B 행렬을 출력하는 함수를 구현한다. (print matrix() )
    printf("행렬 A >>\n");
    printMatrix(matrixA, rowsA, colsA);
    printf("행렬 B >>:\n");
    printMatrix(matrixB, rowsB, colsB);

    // Add Matrix - A + B를 구현한다. (addition matrix())
    int** addition = additionMatrix(matrixA, matrixB, rowsA, colsA);
    printf("Add Matrix - A + B:\n");
    printMatrix(addition, rowsA, colsA);

    // Subtract Matrix - A − B를 구현한다. (subtraction matrix())
    int** subtraction = subtractionMatrix(matrixA, matrixB, rowsA, colsA);
    printf("Subract Matrix - A - B:\n");
    printMatrix(subtraction, rowsA, colsA);

    // Transpose matrix a - A의 전치행렬 T를 구현한다. (transpose matrix())
    int** transpose = transposeMatrix(matrixA, rowsA, colsA);
    printf("Transpose matrix_a - A:\n");
    printMatrix(transpose, colsA, rowsA);

    // Multiply Matrix - A × B를 구현한다. (multiply matrix())
    int** multiplication = multiplyMatrix(matrixA, matrixB, rowsA, colsA, colsB);
    printf("Multiply Matrix - A * B:\n");
    printMatrix(multiplication, rowsA, colsB);

    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(addition, rowsA);
    freeMatrix(subtraction, rowsA);
    freeMatrix(transpose, colsA);
    freeMatrix(multiplication, rowsA);

    return 0;
}
