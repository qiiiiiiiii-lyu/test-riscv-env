// heap-buffer-over-read.cpp
#include <iostream>
#include <cstdint>

int main()
{
    std::cout << "Running Buffer Over-read (C++)...\n";
    int* arr = new int[3];
    if (!arr) {
        std::cout << "Allocation failed!\n";
        return -1;
    }
    std::cout << "Array created, assigning values...\n";
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    std::cout << "Accessing arr[10] (out-of-bounds)...\n";
    // Undefined behaviour on normal hardware (may read garbage or crash).
    int value = arr[10];
    std::cout << "Value read from arr[10]: " << value << " (UB on normal HW)\n";
    delete[] arr;
    std::cout << "Finished.\n";
    return 0;
}
