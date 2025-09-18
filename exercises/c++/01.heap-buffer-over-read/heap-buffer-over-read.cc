// heap-buffer-over-read.cpp
#include <iostream>
#include <cstdint>

int main()
{
    printf("Running Buffer Over-read (C++)...\n");
    int* arr = new int[3];
    if (!arr) {
        printf("Allocation failed!\n");
        return -1;
    }
    printf("Array created, assigning values...\n");
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    printf("Accessing arr[10] (out-of-bounds)...\n");
    // Undefined behaviour on normal hardware (may read garbage or crash).
    int value = arr[10];
    printf("Value read from arr[10]: %d (UB on normal HW)\n", value);
    delete[] arr;
    printf("Finished.\n");
    return 0;
}
