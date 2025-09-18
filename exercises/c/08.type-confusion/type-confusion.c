#include <stdio.h>

const char hello[] = "Hello World!";

union long_ptr {
    long l;
    const char *ptr;
} lp = { .ptr = hello };

void inc_long_ptr(union long_ptr *lpp) {
    lpp->l++;
}

int main() {
    printf("Testing Type confusion (C)...\n");

    printf("Before inc_long_ptr: lp.ptr = %s\n", (char*)lp.ptr);
    inc_long_ptr(&lp);
    printf("After inc_long_ptr: lp.ptr = %s\n", (char*)lp.ptr);

    return 0;
}