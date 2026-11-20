
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t rx_buffer[100] = {
        0x41, 0x42, 0x43, 0x44,
        0x45, 0x46, 0x47
    };

    size_t buffer_capacity = sizeof(rx_buffer);

    size_t received_length = 7;

    uint8_t *ptr = rx_buffer;
    uint8_t *end = rx_buffer + received_length;

    printf("UART Buffer Information:\n");
    printf("Buffer capacity : %zu bytes\n", buffer_capacity);
    printf("Received length : %zu bytes\n\n", received_length);

    printf("Processing received data:\n");

    while (ptr < end)
    {
        printf("Received byte: 0x%02X\n", (unsigned int)*ptr);
        ptr++;
    }

    printf("\nProcessed bytes: %zu\n", received_length);

    return 0;
}
