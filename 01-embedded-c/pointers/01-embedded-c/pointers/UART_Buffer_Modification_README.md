# UART Buffer Modification Using Pointers

## Objective

Demonstrate how to modify UART received data directly using a pointer (`uint8_t *`) in Embedded C.

This example converts lowercase English characters into uppercase characters while preserving numbers and special characters.

## Concepts Covered

- Pointer-based array modification
- Passing an array to a function
- Difference between modifying pointer and pointed-to data
- UART received buffer processing
- ASCII character conversion
- NULL pointer validation
- Buffer-length validation
- Safe data processing practices

## UART Buffer

The example uses a 100-byte buffer:

```c
#define UART_BUFFER_SIZE 100

uint8_t rx_buffer[UART_BUFFER_SIZE] =
{
    'h', 'e', 'l', 'l', 'o', ' ', '1', '2', '3'
};

size_t received_length = 9;
```

## Pointer-Based Modification

```c
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
            buffer[i] = buffer[i] - ('a' - 'A');
        }
    }
}
```

## How It Works

The function receives the address of the original UART buffer.

```c
modify_uart_data(rx_buffer, received_length);
```

The pointer `buffer` refers to the same array as `rx_buffer`.

Therefore:

```c
buffer[i] = buffer[i] - ('a' - 'A');
```

modifies the original array contents.

### Important Pointer Concept

| Operation | Effect |
|---|---|
| `buffer[i] = 0x55;` | Modifies original array data |
| `buffer = NULL;` | Changes only the local pointer |
| `uint8_t *` | Accesses or modifies buffer data |
| `uint8_t **` | Can modify the caller's pointer |

## ASCII Conversion

Lowercase and uppercase English letters differ by 32 in ASCII.

Example:

```text
'a' = 97
'A' = 65

97 - 65 = 32
```

The expression:

```c
buffer[i] - ('a' - 'A')
```

converts a lowercase letter to uppercase.

Numbers and spaces remain unchanged.

## Input and Output

### Before Modification

```text
h e l l o   1 2 3
```

### After Modification

```text
H E L L O   1 2 3
```

## Safety Validation

### 1. NULL Pointer Check

```c
if (buffer == NULL)
{
    printf("ERROR: NULL buffer pointer!\n");
    return;
}
```

Prevents accessing data through a NULL pointer.

### 2. Buffer-Length Check

```c
if (length > UART_BUFFER_SIZE)
{
    printf("ERROR: Invalid UART buffer length!\n");
    return;
}
```

Rejects a processing length greater than the allocated buffer capacity.

**Important:** The actual received length must also be validated by the caller. This processing check does not prevent an earlier UART/DMA receive overflow.

## Test Results

| Test | Input | Result |
|---|---|---|
| Normal processing | 9 bytes | Passed |
| Invalid length | 120 bytes | Rejected |
| NULL pointer | NULL | Rejected |

## Compile and Run

```bash
gcc -Wall -Wextra -std=c11 uart_buffer_modification.c -o uart_modification

./uart_modification
```

## Embedded Firmware Applications

This technique is useful for:

- UART command processing
- ASCII protocol parsing
- Serial communication data handling
- In-place buffer modification
- Firmware data preprocessing

## Key Learning

A function using `uint8_t *` can modify the original array contents without requiring a double pointer.

A double pointer (`uint8_t **`) is needed when the function must modify the caller's pointer itself.
