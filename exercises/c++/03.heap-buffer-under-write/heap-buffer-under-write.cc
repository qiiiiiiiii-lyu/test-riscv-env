// heap-buffer-under-write.cpp
#include <iostream>

int main()
{
    printf("Testing Heap Buffer Under-write (C++)...\n");
    int* arr = new int[3];
    if (!arr) {
        printf("Allocation failed!\n");
        return 0;
    }
    arr[0]=10; arr[1]=20; arr[2]=30;
    printf("Attempting under-write arr[-1] = 999 ...\n");
    // Undefined behaviour: writing before the start of the array
    arr[-1] = 999;
    printf("arr[-1] now reads: %d (UB)\n", arr[-1]);
    delete[] arr;
    printf("Finished.\n");
    return 0;
}
