// type-confusion.cpp
#include <iostream>

const char Hello[] = "Hello World!";

union long_ptr {
    long l;
    const char* ptr;
} lp = { .ptr = Hello };

void inc_long_ptr(long_ptr* lpp) {
    // increment the integer member, which will reinterpret the pointer bits as integer and add 1.
    lpp->l++;
}

int main()
{
    printf("Testing Type confusion (C++)...\n");
    printf("Before inc_long_ptr: lp.ptr = %s\n", lp.ptr);
    inc_long_ptr(&lp);
    // After the increment the pointer bits have been changed as integer arithmetic: result is UB when interpreted as pointer.
    printf("After inc_long_ptr: lp.ptr = %s\n", lp.ptr);
    return 0;
}
