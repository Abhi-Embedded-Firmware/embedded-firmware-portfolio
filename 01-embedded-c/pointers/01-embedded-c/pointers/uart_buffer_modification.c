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
    for (size_t i = 0; i < length; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = buffer[i] - 32;
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

    size_t received_length = 9;

    printf("Before modification:\n");

    for (size_t i = 0; i < received_length; i++)
    {
        printf("0x%2X->", (unsigned int)rx_buffer[i]);
        printf("%C\t", (unsigned int)rx_buffer[i]);
    }
    
    printf("\n");
    
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

