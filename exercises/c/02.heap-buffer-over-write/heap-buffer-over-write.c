#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Testing Buffer Over-write (C)...\n");
    int* arr = (int*)malloc(3 * sizeof(int));
    if (arr == NULL) { return 0; }

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    printf("Testing Buffer Over-write (C)...\n");

    printf("Attempting to write arr[4]...\n");
    arr[4] = 999; // Writing outside allocated memory
    printf("arr[4]: %d\n", arr[4]);
    free(arr);
    printf("This line may not be reached if the program crashes.\n");

    return 0;
}