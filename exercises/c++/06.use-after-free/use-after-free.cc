// use-after-free.cpp
#include <iostream>

int main()
{
    printf("Testing Use-After-Free (C++)...\n");
    int* ptr = new int;
    if (!ptr) {
        printf("Allocation failed!\n");
        return 0;
    }
    *ptr = 123;
    printf("ptr address: %p, value: %d\n", static_cast<void*>(ptr), *ptr);
    delete ptr;
    printf("Memory has been freed.\n");
    // Use-after-free: UB on normal hardware
    *ptr = 456;
    printf("After writing to freed memory: *ptr = %d\n", *ptr);
    return 0;
}
