
#include <stdio.h>

int main(void)
{
    int data[5] = {10, 20, 30, 40, 50};

    int *ptr = data;

    printf("Array elements using pointer traversal:\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Element %d = %d\n", i, *ptr);

        ptr++;
    }

    return 0;
}
