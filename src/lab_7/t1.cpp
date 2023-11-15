#include <iostream>



int**randomMatrix(int len) {
    int **matrix = new int*[len];
    for (int i = 0; i < len; i++) {
        matrix[i] = new int[len];
        for (int j = 0; j < len; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

int**print(int**matrix, int len) {
    for (int i = 0; i < len; i++) {
        printf("\n");
        for (int j = 0; j < len; j++)
            printf("%3d ", matrix[i][j]);
    }
    return matrix;
}

int**swapCols(int**matrix, int len, int col1, int col2) {
    for (int i = 0; i < len; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
    return matrix;
}

int**swap_minmax(int**matrix, int len) {
    int min = matrix[0][0], max = matrix[0][0],
    colMin = 0, colMax = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                colMin = j;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                colMax = j;
            }
        }
    }
    swapCols(matrix, len, colMin, colMax);
    return matrix;
}

int main() {
    int **matrix = randomMatrix(5);
    print(matrix, 5);
    printf("\n");
    matrix = swap_minmax(matrix, 5);
    print(matrix, 5);

    return 0;
}