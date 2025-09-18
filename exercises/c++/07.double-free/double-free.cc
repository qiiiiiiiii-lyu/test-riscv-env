// double-free.cpp
#include <iostream>
#include <cstdlib>

int main()
{
    printf("Testing Double Free...\n");
    int *ptr = (int*)std::malloc(sizeof(int));
    if (!ptr) {
        printf("malloc returned NULL\n");
        return 0;
    }
    *ptr = 42;
    printf("Allocated ptr = %p, *ptr = %d\n", static_cast<void*>(ptr), *ptr);

    std::free(ptr);
    printf("First free() done.\n");

    // Double free: undefined behaviour on normal hardware.
    // Some libc implementations will abort, others will corrupt heap silently.
    printf("Calling free(ptr) a second time (double free, UB)...\n");
    std::free(ptr);

    printf("Second free() returned (if program hasn't aborted). This was UB on normal HW.\n");
    return 0;
}
