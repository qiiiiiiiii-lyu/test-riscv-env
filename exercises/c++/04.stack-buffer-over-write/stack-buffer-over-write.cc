// stack-buffer-over-write.cpp
#include <iostream>
#include <cstdint>
#include <cassert>

void write_buf(char* buf, size_t ix)
{
    // write exactly at index ix (likely one past the end when called)
    buf[ix] = 'b';
}

int main()
{
    printf("Testing Stack Buffer Over Write (C++)...\n");
    char upper[0x10];
    char lower[0x10];

    printf("upper addr = %p , lower addr = %p\n", static_cast<void*>(upper), static_cast<void*>(lower));
    // Note: stack layout is implementation-dependent; the following assert may fail on some ABIs.
    // We'll not rely on exact layout; show value before and after.
    upper[0] = 'a';
    printf("Before: upper[0] = %c \n", upper[0]);

    // This call writes at lower[sizeof(lower)], which is one past the array -> stack overflow into neighboring data
    write_buf(lower, sizeof(lower));
    printf("After write_buf(lower, sizeof(lower)): upper[0] = %c\n", upper[0]);

    return 0;
}
