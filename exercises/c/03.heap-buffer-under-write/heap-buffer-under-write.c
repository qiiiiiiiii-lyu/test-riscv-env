#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Testing Heap Buffer Under-write (C)...\n");

    int *arr = (int *)malloc(3 * sizeof(int));
    if (arr == NULL) { return 0; }
    arr[0] = 10; arr[1] = 20; arr[2] = 30;

    printf("Attempting under-write arr[-1] = 999 ...\n");
    arr[-1] = 999; // write before start of allocation (under-write)

    printf("arr[-1]: %d.\n", arr[-1]);

    free(arr);
    printf("Freed array.\n");
    return 0;
}