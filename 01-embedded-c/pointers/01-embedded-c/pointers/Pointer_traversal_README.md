# Pointer Array Traversal in C

## 1. Objective

Understand how to traverse an array using pointers instead of array indexing.

This example demonstrates pointer initialization, dereferencing, and pointer increment to access consecutive array elements.

## 2. Source Code

[`pointer_array_traversal.c`](pointer_array_traversal.c)

## 3. Array Declaration

```c
int data[5] = {10, 20, 30, 40, 50};
```

An integer array containing five elements is created.

Each element occupies `sizeof(int)` bytes.

## 4. Pointer Initialization

```c
int *ptr = data;
```

The array name `data` decays to a pointer to its first element in this expression.

Therefore, `ptr` points to `data[0]`.

## 5. Array Traversal Using a Pointer

```c
for (int i = 0; i < 5; i++)
{
    printf("Element %d = %d\n", i, *ptr);

    ptr++;
}
```

The loop performs two operations:

- `*ptr`: Dereferences the pointer and reads the current array element.
- `ptr++`: Advances the pointer to the next integer element.

The array is traversed without using array indexing to access its elements.

## 6. Memory Traversal

Assuming `sizeof(int) = 4` bytes:

| Iteration | Pointer position | Value | Offset from start |
|---|---|---:|---:|
| 0 | `data[0]` | 10 | 0 bytes |
| 1 | `data[1]` | 20 | 4 bytes |
| 2 | `data[2]` | 30 | 8 bytes |
| 3 | `data[3]` | 40 | 12 bytes |
| 4 | `data[4]` | 50 | 16 bytes |

Pointer increment automatically accounts for the size of the pointed-to data type.

## 7. Expected Output

```text
Array elements using pointer traversal:

Element 0 = 10
Element 1 = 20
Element 2 = 30
Element 3 = 40
Element 4 = 50
```

## 8. Array Indexing vs Pointer Access

These expressions are equivalent for valid array indices:

```c
data[i]
*(data + i)
```

Both access the element at index `i`.

However, pointer traversal provides practice for working directly with memory addresses and buffers.

## 9. Embedded Firmware Applications

Pointer-based array traversal is useful in:

- UART receive and transmit buffers.
- SPI and I2C data buffers.
- DMA buffer processing.
- Packet parsing.
- Sensor data processing.
- Memory block traversal.

For example, a firmware driver may use a pointer to process received communication data sequentially.

## 10. Engineering Notes

- Initialize pointers before using them.
- Keep pointer arithmetic within the array or one position past its end.
- Never dereference a one-past-the-end pointer.
- Ensure the array remains valid throughout pointer usage.
- Use the correct pointer type for the data being accessed.

## 11. Build and Run

Compile using GCC:

```bash
gcc -Wall -Wextra -std=c11 pointer_array_traversal.c -o pointer_array_traversal
```

Run:

```bash
./pointer_array_traversal
```

---

**Learning outcome:** Understand how pointers traverse arrays sequentially and how pointer arithmetic is applied to access consecutive elements in C.
