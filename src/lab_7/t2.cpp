#include <iostream>
#include <time.h>
#include <stdio.h>

int**randomMatrix(int rows, int cols) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 50;
    }
    return matrix;
}

int**print(int**matrix, int cols, int rows) {
    for (int i = 0; i < cols; i++) {
        printf("\n");
        for (int j = 0; j < rows; j++)
            printf("%3d ", matrix[i][j]);
    }
    return matrix;
}

int sum(int**matrix, int cols, int rows) {
    int sum = 0;
    // bottom and top line sum
    for (int i = 0; i < cols; i++)
        sum += matrix[0][i] + matrix[rows-1][i];
    printf("\n");
    // diagonal sum
    for (int i = 0; i < cols/2; i++)
        sum += matrix[i][i] + matrix[cols-i-1][i];
    return sum + matrix[cols/2][rows/2] - matrix[0][0] - matrix[0][rows-1];
}


int main() {
    srand(time(NULL));
    int cols=5, rows=5;
    int **matrix = randomMatrix(cols, rows);
    print(matrix, cols, rows);
    printf("\n");
    printf("Sum: %d", sum(matrix, cols, rows));

    delete [] matrix;
    return 0;
}