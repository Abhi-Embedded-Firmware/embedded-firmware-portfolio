# UART Buffer Processing Using Pointer-to-Pointer in C

## Objective

Demonstrate how to:
- Pass a UART buffer address from a function using a pointer-to-pointer.
- Return the actual received data length through a function parameter.
- Pass a buffer pointer and length to another function.
- Process UART data using pointer-based array indexing.
- Validate buffer boundaries before processing received data.

## 1. Concepts Used

| Concept | Application |
|---|---|
| `uint8_t *` | Points to UART buffer data |
| `uint8_t **` | Updates the caller's buffer pointer |
| `size_t` | Stores received data length |
| `static` buffer | Maintains buffer lifetime after function returns |
| `buffer[i]` | Accesses individual received bytes |
| Boundary checking | Rejects invalid received lengths |

## 2. Pointer-to-Pointer Buffer Assignment

```c
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
```

### Explanation

- `buffer` stores the address of the original pointer in `main()`.
- `*buffer = rx_buffer` updates the original pointer.
- `*length = 7` updates the actual received length.
- `static` ensures the buffer remains valid after the function returns.

## 3. UART Data Processing Function

```c
void process_uart_data(uint8_t *buffer, size_t length)
{
    if (length > UART_BUFFER_SIZE)
    {
        printf("ERROR: Invalid UART received length!\n");
        return;
    }

    printf("\nProcessing UART Data:\n");

    for (size_t i = 0; i < length; i++)
    {
        printf("Received byte: 0x%02X\n",
               (unsigned int)buffer[i]);
    }
}
```

### Explanation

The function receives:
- `buffer`: Starting address of UART data.
- `length`: Actual received byte count.

Pointer indexing:

```c
buffer[i]
```

is equivalent to:

```c
*(buffer + i)
```

The loop processes only the received bytes.

## 4. Buffer Boundary Protection

```c
#define UART_BUFFER_SIZE 100

if (length > UART_BUFFER_SIZE)
{
    printf("ERROR: Invalid UART received length!\n");
    return;
}
```

Test results:

| Buffer capacity | Received length | Result |
|---:|---:|---|
| 100 bytes | 7 bytes | Accepted |
| 100 bytes | 120 bytes | Rejected |

**Engineering note:** This check protects the processing function. The UART/DMA receive operation must independently be configured to prevent writing beyond the allocated buffer.

## 5. Function Execution Flow

1. `main()` initializes `rx_ptr` to `NULL`.
2. `get_uart_buffer()` receives `&rx_ptr`.
3. The function assigns the UART buffer address using `*buffer = rx_buffer`.
4. The received length is returned through `*length`.
5. `main()` calls `process_uart_data(rx_ptr, received_length)`.
6. The processing function validates the length and processes valid bytes.

## 6. Compile and Run

Using GCC in Ubuntu / WSL:

```bash
gcc -Wall -Wextra -std=c11 uart_buffer_processing_pointer_to_pointer.c -o uart_processing

./uart_processing
```

## 7. Expected Output

```text
UART Buffer Address : <address>
Received Length     : 7 bytes

Processing UART Data:
Received byte: 0x41
Received byte: 0x42
Received byte: 0x43
Received byte: 0x44
Received byte: 0x45
Received byte: 0x46
Received byte: 0x47
```

Invalid-length test:

```text
UART Buffer Address : <address>
Received Length     : 120 bytes
ERROR: Invalid UART received length!
```

## 8. Embedded Firmware Applications

The concepts demonstrated here are useful in:

- UART receive-buffer handling.
- DMA-based data reception.
- Driver APIs that return buffer addresses.
- Packet parsing and protocol processing.
- Buffer management in embedded applications.

## 9. Key Learning

- `uint8_t **buffer` allows a function to update the caller's pointer.
- `*buffer` accesses the original pointer variable.
- `**buffer` accesses the first byte of the pointed-to data.
- `uint8_t *buffer` is sufficient when a function only needs to read or process buffer contents.
- Always validate received length against buffer capacity.
- Buffer lifetime must be considered when returning pointers from functions.

---

**Project:** Embedded C – UART Buffer Processing Using Pointer-to-Pointer

**Language:** C

**Compiler:** GCC

**Environment:** Ubuntu / WSL2
