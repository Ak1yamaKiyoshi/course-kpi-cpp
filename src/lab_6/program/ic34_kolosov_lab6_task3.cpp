#include <iostream>

void swap(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int partition(int *array, int begin, int end) {
    int pivot = array[end];
    int i = begin - 1;
    for (int j = begin; j < end; j++)
        if (array[j] <= pivot)
            swap(array, j, ++i);
    swap(array, end, ++i);
    return i;
}

int* quick_sort(int *array, int begin, int end) {
    if (begin < end) {
        int i = partition(array, begin, end);
        quick_sort(array, begin, i-1);
        quick_sort(array, i+1, end);
    }
    return array;
}

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
        printf("%2d ", *p);
    std::cout << std::endl;
    return array;
}


int main () {
    int *len = new int;
    int *array = createArray(len);
    delete printArray(quick_sort(printArray(array, *len), 0, *len), *len);
    return 0;
}