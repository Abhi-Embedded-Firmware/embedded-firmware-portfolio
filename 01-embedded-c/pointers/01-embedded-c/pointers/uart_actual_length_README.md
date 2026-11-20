# UART Actual Received Length – Buffer Processing in C

## 1. Objective

Understand the difference between UART buffer capacity and the actual number of bytes received.

This example demonstrates how to process only valid received data instead of processing the entire buffer.

## 2. Source Code

[`uart_actual_length.c`](uart_actual_length.c)

## 3. Buffer Configuration

```c
uint8_t rx_buffer[100] = {
    0x41, 0x42, 0x43, 0x44,
    0x45, 0x46, 0x47
};

size_t buffer_capacity = sizeof(rx_buffer);
size_t received_length = 7;
```

Here:

- Buffer capacity = 100 bytes
- Actual received length = 7 bytes
- Valid data = first 7 bytes

The remaining 93 bytes are not part of the received message.

## 4. Pointer Boundary Calculation

```c
uint8_t *ptr = rx_buffer;
uint8_t *end = rx_buffer + received_length;
```

The `ptr` pointer starts at the first received byte.

The `end` pointer identifies the position immediately after the last valid received byte.

The loop must stop at this boundary.

## 5. Processing Received Data

```c
while (ptr < end)
{
    printf("Received byte: 0x%02X\n", (unsigned int)*ptr);
    ptr++;
}
```

The program processes only the seven valid bytes.

It does not process all 100 buffer positions.

## 6. Expected Output

```text
UART Buffer Information:
Buffer capacity : 100 bytes
Received length : 7 bytes

Processing received data:
Received byte: 0x41
Received byte: 0x42
Received byte: 0x43
Received byte: 0x44
Received byte: 0x45
Received byte: 0x46
Received byte: 0x47

Processed bytes: 7
```

## 7. Buffer Capacity vs Actual Received Length

| Parameter | Value |
|---|---:|
| Buffer capacity | 100 bytes |
| Actual received length | 7 bytes |
| Unused capacity | 93 bytes |
| Bytes processed | 7 bytes |

**Important:** Buffer capacity tells us how much data the buffer can hold. Received length tells us how much valid data is available to process.

## 8. Important Firmware Safety Check

Before processing received data, validate the reported length:

```c
if (received_length > sizeof(rx_buffer))
{
    printf("UART buffer length error!\n");
    return;
}
```

Only after validating the length should the firmware process the received data.

This check does not prevent a DMA or driver from overflowing the buffer during reception. The receive operation itself must also be configured with a safe destination buffer size and appropriate transfer limits.

## 9. Real Embedded Firmware Applications

This concept is important in:

- STM32 UART interrupt reception.
- STM32 UART DMA reception.
- Modbus RTU frame processing.
- GPS data parsing.
- AT command processing.
- Sensor communication.
- Binary protocol parsing.

For example, in STM32 HAL-based firmware, the application may obtain received length from the UART receive mechanism or callback, depending on the API and reception mode.

## 10. Engineering Notes

- Never assume the entire buffer contains valid received data.
- Always track the actual received length.
- Validate received length against buffer capacity.
- Do not access data beyond the valid received range.
- Handle zero-length reception correctly.
- Ensure DMA and interrupt-driven reception cannot write beyond the allocated buffer.

## 11. Build and Run

Compile:

```bash
gcc -Wall -Wextra -std=c11 uart_actual_length.c -o uart_actual_length
```

Run:

```bash
./uart_actual_length
```

---

**Learning outcome:** Understand how to distinguish buffer capacity from actual received length and safely process valid UART data using pointers in Embedded C.
