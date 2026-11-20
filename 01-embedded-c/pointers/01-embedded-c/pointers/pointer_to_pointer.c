#include <stdio.h>

int main(void)
{
    int data = 100;

    int *ptr = &data;

    int **pptr = &ptr;

    printf("data  = %d\n", data);
    printf("*ptr  = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);

    return 0;
}
