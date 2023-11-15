#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <time.h>
struct ArrMinMax{
    int* min;
    int* max;
};

int *printArray(int *array, int len) {
    std::cout << "Array: ";
    for (int *p = array; p < array+len; p++)
        printf("%2d ", *p);
    std::cout << std::endl;
    return array;
}

int* randomArray(int *array, int len) {
    for (int *p = array; p < array+len; p++)
        *p = rand() % 100;
    return array;
}


ArrMinMax minmax(int *array, int* end) {
    int *max = nullptr, *min = nullptr;
    int *p = array;
    while  (p++ < end-1) {
        if (!min || *p <= *min) min = p;
        if (!max || *p >= *max) max = p;
    }
    std:: cout << *min << " " << *p << " " << *max << '\n';
    return {min, max};
}

int main () {
    srand(time(NULL));
    int len = 10;
    ArrMinMax valuesToSwap;
    int *array = randomArray(new int[len], len);
    valuesToSwap = minmax(array, array+len);
    std::cout << " < minmax > " << std::endl;
    if (valuesToSwap.min != nullptr && valuesToSwap.max != nullptr){
        printf(" - indicies: [%2d] <-> [%2d]\n", array + len - valuesToSwap.min, array+ len - valuesToSwap.max);
        printf(" - values  : [%2d] <-> [%2d]\n", *valuesToSwap.min, *valuesToSwap.max);
        printArray(array, len);
        std::swap(*valuesToSwap.min, *valuesToSwap.max);
        printArray(array, len);
    }

    return 0;
}