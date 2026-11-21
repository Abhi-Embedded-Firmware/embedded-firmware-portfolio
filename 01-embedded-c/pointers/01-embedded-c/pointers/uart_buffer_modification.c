#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define UART_BUFFER_SIZE 100

/* Commented just for test purpose
void modify_uart_data(uint8_t *buffer, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = buffer[i] + 1;
        // buffer = NULL;
    }
}
*/

void modify_uart_data(uint8_t *buffer, size_t length)
{
    if (buffer == NULL)
    {
        printf("ERROR: NULL buffer pointer!\n");
        return;
    }
    
    if (length > UART_BUFFER_SIZE)
    {
        printf("ERROR: Invalid UART buffer length!\n");
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = buffer[i] - ('a' - 'A'); // ('a' - 'A') = 32;
        }
    }
}

int main(void)
{
    /* Commented for test purpose
    uint8_t rx_buffer[UART_BUFFER_SIZE] =
    {
        0x41, 0x42, 0x43, 0x44, 0x45
    };

    size_t received_length = 5;
    */

    uint8_t rx_buffer[UART_BUFFER_SIZE] =
    {
        'h', 'e', 'l', 'l', 'o', ' ', '1', '2', '3'
    };

    size_t received_length = 9; // = 120; // for boundry test commented

    printf("Before modification:\n");

    for (size_t i = 0; i < received_length; i++)
    {
        printf("0x%2X->", (unsigned int)rx_buffer[i]);
        printf("%C\t", (unsigned int)rx_buffer[i]);
    }
    
    printf("\n");
    
    //modify_uart_data(NULL, received_length);// for NULL Pointer test commented
    modify_uart_data(rx_buffer, received_length);
    
    printf("\nAfter modification:\n");
    
    for (size_t i = 0; i < received_length; i++)
    {
        printf("0x%2X->", (unsigned int)rx_buffer[i]);
        printf("%C\t", (unsigned int)rx_buffer[i]);
    }
    
    printf("\n");

    return 0;
}

