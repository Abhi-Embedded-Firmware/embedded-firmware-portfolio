
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t rx_buffer[5] = {
        0x41, 0x42, 0x43, 0x44, 0x45
    };

    uint8_t *ptr = rx_buffer;

    uint8_t *end = rx_buffer + sizeof(rx_buffer);

    size_t received_count = 0;

    printf("UART Received Data:\n\n");

    while (ptr < end)
    {
        printf("Received byte: 0x%02X\n", (unsigned int)*ptr);

        ptr++;
        received_count++;
    }

    printf("\nTotal received bytes: %zu\n", received_count);

    return 0;
}
