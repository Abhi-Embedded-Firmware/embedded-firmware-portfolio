
#include <stdio.h>

int main(void)
{
    int data[4] = {10, 20, 30, 40};

    int *ptr = data;

    printf("Size of int: %zu bytes\n\n", sizeof(int));

    printf("Initial pointer:\n");
    printf("Address stored in ptr : %p\n", (void *)ptr);
    printf("Value pointed by ptr  : %d\n\n", *ptr);

    // Move pointer to the next integer
    ptr++;

    printf("After ptr++:\n");
    printf("Address stored in ptr : %p\n", (void *)ptr);
    printf("Value pointed by ptr  : %d\n\n", *ptr);

    // Move pointer to the next integer
    ptr++;

    printf("After another ptr++:\n");
    printf("Address stored in ptr : %p\n", (void *)ptr);
    printf("Value pointed by ptr  : %d\n\n", *ptr);

    // Pointer difference gives the number of elements
    printf("Elements moved from start: %td\n", ptr - data);

    return 0;
}
