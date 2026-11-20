# UART Buffer Traversal Using Pointers

## 1. Objective

Understand how pointers can be used to traverse and process UART receive buffers byte by byte.

This example simulates a UART receive buffer containing five received bytes and demonstrates pointer-based data processing.

## 2. Source Code

[`uart_buffer_traversal.c`](uart_buffer_traversal.c)

## 3. UART Receive Buffer

```c
uint8_t rx_buffer[5] = {
    0x41, 0x42, 0x43, 0x44, 0x45
};
```

The buffer contains five bytes.

These hexadecimal values represent ASCII characters:

| Hexadecimal | ASCII |
|---|---|
| 0x41 | A |
| 0x42 | B |
| 0x43 | C |
| 0x44 | D |
| 0x45 | E |

## 4. Pointer Initialization

```c
uint8_t *ptr = rx_buffer;
```

The pointer is initialized with the address of the first buffer element.

Since `uint8_t` occupies one byte, each pointer increment advances by one byte.

## 5. Buffer Boundary Calculation

```c
uint8_t *end = rx_buffer + sizeof(rx_buffer);
```

This calculates the address one position beyond the last buffer element.

For a five-byte buffer:

- `ptr` initially points to byte 0.
- `end` points one position beyond byte 4.

The `end` pointer is used as a boundary and must not be dereferenced.

## 6. Pointer-Based Buffer Traversal

```c
while (ptr < end)
{
    printf("Received byte: 0x%02X\n", (unsigned int)*ptr);

    ptr++;
    received_count++;
}
```

Each loop iteration:

1. Checks whether the pointer is within the buffer.
2. Dereferences the pointer to read the current byte.
3. Advances the pointer to the next byte.
4. Increments the processed-byte counter.

## 7. Memory Traversal

| Iteration | Buffer element | Value |
|---|---|---|
| 1 | `rx_buffer[0]` | 0x41 |
| 2 | `rx_buffer[1]` | 0x42 |
| 3 | `rx_buffer[2]` | 0x43 |
| 4 | `rx_buffer[3]` | 0x44 |
| 5 | `rx_buffer[4]` | 0x45 |

The pointer advances by one byte during each iteration.

## 8. Expected Output

```text
UART Received Data:

Received byte: 0x41
Received byte: 0x42
Received byte: 0x43
Received byte: 0x44
Received byte: 0x45

Total received bytes: 5
```

## 9. Embedded Firmware Applications

Pointer-based UART buffer traversal is useful for:

- UART receive-buffer processing.
- Communication protocol parsing.
- Packet header and payload extraction.
- DMA buffer processing.
- Byte-by-byte command interpretation.
- Sensor communication data processing.

## 10. Engineering Notes

- Use `uint8_t` for byte-oriented communication buffers.
- Keep pointer traversal within the valid buffer boundary.
- Never dereference the one-past-the-end pointer.
- Maintain a valid received-byte count.
- Ensure the buffer is not modified unexpectedly while it is being processed.

In a real STM32 implementation, received data and its valid length may be provided through interrupt-driven or DMA-based UART reception.

## 11. Build and Run

Compile:

```bash
gcc -Wall -Wextra -std=c11 uart_buffer_traversal.c -o uart_buffer_traversal
```

Run:

```bash
./uart_buffer_traversal
```

---

**Learning outcome:** Understand how to process UART receive data sequentially using pointers and buffer boundaries in C.
