#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define UART_BUFFER_SIZE 100

void modify_uart_data(uint8_t *buffer, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = buffer[i] + 1;
        // buffer = NULL;
    }
}

int main(void)
{
    uint8_t rx_buffer[UART_BUFFER_SIZE] =
    {
        0x41, 0x42, 0x43, 0x44, 0x45
    };

    size_t received_length = 5;

    printf("Before modification:\n");

    for (size_t i = 0; i < received_length; i++)
    {
        printf("0x%02X ", (unsigned int)rx_buffer[i]);
    }
    
    printf("\n");
    
    modify_uart_data(rx_buffer, received_length);
    
    printf("\nAfter modification:\n");
    
    for (size_t i = 0; i < received_length; i++)
    {
        printf("0x%02X ", (unsigned int)rx_buffer[i]);
    }
    
    printf("\n");

    return 0;
}

