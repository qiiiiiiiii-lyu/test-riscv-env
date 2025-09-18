#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Testing Use-After-Free (C)...\n");
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {return 0;}
    *ptr = 123;
    printf("ptr points to memory with value: {}\n", *ptr);

    free(ptr);
    printf("Memory has been freed.\n");

    printf("Attempting to dereference dangling pointer...\n");
    *ptr = 456;
    printf("Value is now: %d\n", *ptr);

    return 0;
}