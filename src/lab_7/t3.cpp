#include <iostream>



int**randomMatrix(int rows, int cols) {
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100 - 50;
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


int minmax_difference(int *array, int len) {
    int min = array[0], max = array[0];
    for (int j = 0; j < len; j++) {
        if (array[j] < min)
            min = array[j];
        if (array[j] > max)
            max = array[j];
    }
    return max-min;
}

void dothething(int **matrix, int cols, int rows) {
    for (int i = 0; i < cols; i++ ) {
        printf("[%d]:  %d \n",i, minmax_difference(matrix[i], rows));
        minmax_difference(matrix[i], rows);
    }
}

int negatives(int**matrix, int cols, int rows ) {
    int n = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            if (matrix[i][j] < 0)
                n++;
    }
    return n;
}

int main() {
    int cols=4, rows=2;
    int **matrix = randomMatrix(cols, rows);
    print(matrix, cols, rows);
    printf("\n");
    dothething(matrix, cols, rows  );
    printf(" negative numbers count: %d", negatives(matrix, cols, rows));


    return 0;
}