#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <memory.h>
#include <vector>
#include <atomic>
#include <unordered_map>

typedef bool (*func)(int, int*, int);
typedef int* (*uniquefunc )(int*, int, int*);
typedef std::vector<int> (*uniquefuncVec )(std::vector<int>);

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

int *uniqueFaster(int *begin, int*end) {
    if (begin == end) return end;
    int *result = begin;
    while (++begin != end) {
        if (!(*result, *begin) && ++result != begin)
            *result = std::move(*begin);
    }
    return ++result;
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

double benchmarkUniqueFast(int *array, int len, int times=100) {
    int *end = array + len;
    double *results = new double[times];

    for (int i = 0; i < times; i++) {
        clock_t begin = clock();
        uniqueFaster(array, end);
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

double benchmarkUniqueVec(int *array, int len, int times=100) {
    double *results = new double[times];

    std::vector<int> vec;
    vec.assign(array, array + len);
    int *entry = new int;
    for (int i = 0; i < times; i++) {
        clock_t begin = clock();

        unique(vec.begin(), vec.end());

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
    const int ITERATIONS = 100000;
    const int LENARRAY = 100;
    int *array = new int[LENARRAY];
    randomArray(array, LENARRAY);

    std::cout << "uniqueFaster: " <<  std::setprecision(100)     << benchmarkUniqueFast(array, LENARRAY, ITERATIONS) << std::endl;
    std::cout << "unique vec  : " << std::setprecision(100)          << benchmarkUniqueVec(array, LENARRAY, ITERATIONS) << std::endl;
    std::cout << "unique      : " <<  std::setprecision(100)           << benchmarkUnique(unique, array, LENARRAY, array, ITERATIONS) << std::endl;
    return 0;
}