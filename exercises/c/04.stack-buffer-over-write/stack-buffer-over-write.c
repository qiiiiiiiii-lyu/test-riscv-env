#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#pragma weak write_buf

void write_buf(char *buf, size_t ix)
{
    buf[ix] = 'b';
}

int main() {
    printf("Testing Stack Buffer Over Write (C)...\n");

    char upper[0x10];
    char lower[0x10];

    printf("upper = %p, lower = %p, diff = %zx\n",
        upper, lower, (size_t)(upper - lower));

    /* Assert that these get placed how we expect */
    assert((uintptr_t)upper == (uintptr_t)&lower[sizeof(lower)]);

    upper[0] = 'a';
    printf("upper[0] = %c\n", upper[0]);

    write_buf(lower, sizeof(lower));

    printf("upper[0] = %c\n", upper[0]);

    return 0;
}