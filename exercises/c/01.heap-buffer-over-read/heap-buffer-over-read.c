#include <stdio.h>
#include <stdlib.h>

int main() {

    int* arr = (int*)malloc(3 * sizeof(int));
    if (arr == NULL) {return 0;} // Always check for malloc failure
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    printf("Testing Buffer Over-read (C)...\n");

    printf("Accessing arr[10]...\n");
    int value = arr[10]; 
    printf("Value: %d\n", value);

    free(arr);
    printf("This line may not be reached if the program crashes.\n");
    
    return 0;
}