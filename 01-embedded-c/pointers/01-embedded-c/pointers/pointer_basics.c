
#include <stdio.h>

int main(void)
{
    int data = 100;

    // Store the address of data in a pointer
    int *ptr = &data;

    printf("Value of data       : %d\n", data);
    printf("Address of data     : %p\n", (void *)&data);
    printf("Value of ptr        : %p\n", (void *)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    // Modify data through the pointer
    *ptr = 200;

    printf("\nAfter modifying through pointer:\n");
    printf("Value of data       : %d\n", data);
    printf("Value pointed by ptr: %d\n", *ptr);

    return 0;
}
