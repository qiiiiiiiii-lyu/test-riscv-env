// oob-pointer-arithmetic.cpp
#include <iostream>
#include <cstdint>

int main()
{
    printf("Testing Out-Of-Bounds Pointer Arithmetic (C++)...\n");
    int arr[4] = {100, 200, 300, 400};
    printf("Array base: %p\n", static_cast<const void*>(arr));
    int* p = arr + 10;
    printf("Pointer moved to arr + 10: %p\n", static_cast<const void*>(p));
    // Dereferencing p is undefined behaviour on normal hardware.
    int val = *p;
    printf("Read value: %d (UB on normal HW)\n", val);
    return 0;
}
