#include <stdio.h>
#include <stdint.h>

int main() {
    printf("Testing Out-Of-Bounds Pointer Arithmetic (C)...\n");
    int arr[4] = {100, 200, 300, 400};
    printf("Array base: %p\n", (uintptr_t)arr);

    /* Make a pointer well past the end via arithmetic */
    int *p = arr + 10; // pointer now points far beyond arr
    printf("Pointer moved to arr + 10: %p\n", (uintptr_t)p);

    printf("Dereferencing OOB pointer ...\n");
    int val = *p; // out-of-bounds read (or write) via pointer arithmetic
    printf("Read value: %d\n", val);

    return 0;
}