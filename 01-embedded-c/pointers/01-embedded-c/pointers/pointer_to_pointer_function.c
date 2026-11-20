#include <stdio.h>

void update_pointer(int **ptr, int *new_address)
{
    *ptr = new_address;
}

int main(void)
{
    int a = 100;
    int b = 500;

    int *ptr = &a;

    printf("Before function call:\n");
    printf("Value pointed by ptr = %d\n", *ptr);

    update_pointer(&ptr, &b);

    printf("\nAfter function call:\n");
    printf("Value pointed by ptr = %d\n", *ptr);

    return 0;
}
