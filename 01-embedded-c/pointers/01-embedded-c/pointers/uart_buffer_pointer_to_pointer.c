#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void get_uart_buffer(uint8_t **buffer, size_t *length)
{
    static uint8_t rx_buffer[100] =
    {
        0x41, 0x42, 0x43, 0x44,
        0x45, 0x46, 0x47
    };

    *buffer = rx_buffer;

    *length = 7;
}

int main(void)
{
    uint8_t *rx_ptr = NULL;
    size_t received_length = 0;

    get_uart_buffer(&rx_ptr, &received_length);

    printf("UART Buffer Address : %p\n", (void *)rx_ptr);
    printf("Received Length     : %zu bytes\n", received_length);

    return 0;
}
