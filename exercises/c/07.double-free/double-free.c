#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Testing Double Free...\n");

    int *ptr = (int*)malloc(sizeof(int));
    if (!ptr) { printf("malloc returned NULL\n"); return 0; }
    *ptr = 42;

    int *ptr2 = ptr;

    free(ptr);
    printf("Free one complete\n");

    free(ptr2);
    printf("Free two complete\n");

    return 0;
}