#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <memory.h>
#include <atomic>
#include <unordered_map>

typedef bool (*func)(int, int*, int);
typedef int* (*uniquefunc )(int*, int, int*);

bool numInArray(int num, int *array, int len) {
    for (int *p = array, k = 0; p < array+len; p++)
        if (*p == num) return true;
    return false;
}

bool numInArrayFaster(int num, int *array, int len) {
    int *p = array;
    int *end = array+len;
    while (p++ < end)
        if (*p == num) return true;
    return false;
}

int *unique(int *array, int len, int *entriesLen) {
    int *output = new int[len];
    memset(output, 0, len*sizeof(int));
    *entriesLen = 0;
    for (int i = 0; i < len; i++) {
        if (!numInArrayFaster(array[i], array, i)) {
            output[(*entriesLen)++] = array[i];
        }
    }
    return (int*)realloc(output, *entriesLen*sizeof(int));
}


#include <algorithm>

int *uniqueFaster(int *array, int len, int *entriesLen) {
    int *output = new int[len];
    std::sort(array, array + len);
    output[(*entriesLen)++] = array[0];
    for (int i = 1; i < len; i++) {
        if (array[i] != array[i - 1]) {
            output[(*entriesLen)++] = array[i];
        }
    }
    output = (int*)realloc(output, *entriesLen*sizeof(int));
    return output;
}

void randomArray(int *array, int len) {
    for (int *p = array; p < array+len; p++)
        *p = rand() % 100;
}


double benchmarkNumInArray(func f, int num, int*array, int len, int times=100) {
    double *results = new double[times];

    for (int i = 0; i < times; i++) {
        clock_t begin = clock();
        f(num, array, len);
        clock_t end = clock();
        results[i] = (double)(end - begin) / CLOCKS_PER_SEC;
    }
    double average = 0;
    for (int i = 0; i < times; i++)
        average += results[i];
    double time = average / times;
    delete results;
    return time;
}

double benchmarkUnique(uniquefunc f, int *array, int len, int*entries, int times=100) {
    double *results = new double[times];

    int *entry = new int;
    for (int i = 0; i < times; i++) {
        clock_t begin = clock();
        delete[] f(array, len, entry);
        clock_t end = clock();
        results[i] = (double)(end - begin) / CLOCKS_PER_SEC;
    }
    double average = 0;
    for (int i = 0; i < times; i++)
        average += results[i];
    double time = average / times;
    delete results;
    return time;
}

int main() {
    const int ITERATIONS = 1000;
    const int LENARRAY = 100;
    int *array = new int[LENARRAY];
    randomArray(array, LENARRAY);

    //std::cout << "numInArray: " <<  std::setprecision(100)      << benchmarkNumInArray(numInArray, 5, array, lenarray, iterations) << std::endl;
    //std::cout << "numInArrayFaster: " <<  std::setprecision(100) << benchmarkNumInArray(numInArrayFaster, 5, array, lenarray, iterations) << std::endl;
    std::cout << "uniqueFaster: " <<  std::setprecision(100)     << benchmarkUnique(uniqueFaster, array, LENARRAY, array, ITERATIONS) << std::endl;
    std::cout << "unique: " <<  std::setprecision(100)           << benchmarkUnique(unique, array, LENARRAY, array, ITERATIONS) << std::endl;
    return 0;
}