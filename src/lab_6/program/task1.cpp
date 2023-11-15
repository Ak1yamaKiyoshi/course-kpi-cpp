#include <iostream>
#include <algorithm>
#include <memory.h>

int *createArray(int *len) {
    std::cout << " > Enter length of array: ";
    std::cin >> *len;
    int *array = new int[*len];
    for (int i = 0; i < *len; i++) {
        std::cout << " > array [" << i << "]:";
        std::cin >> array[i];
    }
    return array;
}

int *printArray(int *array, int len) {
    std::cout << "Array: ";
    for (int *p = array; p < array+len; p++)
        std::cout << *p << " ";
    std::cout << std::endl;
    return array;
}

bool numInArray(int num, int *array, int len) {
    for (int *p = array, k = 0; p < array+len; p++)
        if (*p == num) return true;
    return false;
}


bool numInArrayFaster(int num, int *array, int len) {
    #pragma omp parallel for
    for (int *i=array, *j=array+2; i < array+len; i++, i++, j++, j++)
        if (*i == num || *j == num) return true;
    return false;
}

/* returns output array with unique numbers from array
 * modifies entriesLen to be the length of the output array */
int *unique(int *array, int len, int *entriesLen) {
    int *output = new int[len];
    memset(output, 0, len*sizeof(int));
    *entriesLen = 0;
    for (int i = 0; i < len; i++) {
        if (!numInArray(array[i], array, i)) {
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



int main () {
    int *len = new int, *entries = new int(0); // Initialize entries to 0
    int *array = createArray(len);
    std::cout << " < array > " << std::endl;
    printArray(array, *len);

    std::cout << " < unique > " << std::endl;
    int *uniqueArray = uniqueFaster(array, *len, entries);
    printArray(uniqueArray, *entries);

    delete[] array;
    delete len;
    delete entries;
    delete[] uniqueArray; // Don't forget to delete uniqueArray
    return 0;

}