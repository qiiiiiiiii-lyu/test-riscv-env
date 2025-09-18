// heap-buffer-over-write.cpp
#include <iostream>

int main()
{
    printf("Testing Heap Buffer Over-write (C++)...\n");
    int* arr = new int[3];
    if (!arr) {
        printf("Allocation failed!\n");
        return 0;
    }
    arr[0]=1; arr[1]=2; arr[2]=3;
    printf("Attempting to write arr[10] (out-of-bounds)...\n");
    // Undefined behaviour: writing outside allocated array
    arr[10] = 999;
    printf("Write completed to arr[10] (this was UB on normal HW).\n");
    printf("arr[10] now reads: %d (UB)\n", arr[10]);
    delete[] arr;
    printf("Finished.\n");
    return 0;
}
