# Pointer to Pointer in C (`int **ptr`)

## 1. Objective

Understand pointer-to-pointer concepts in C, including:

- Declaration and initialization of a pointer to pointer.
- Understanding `int *` versus `int **`.
- Dereferencing using `*` and `**`.
- Modifying original variables through pointer-to-pointer.
- Changing a pointer's destination through a function.
- Understanding variable lifetime and `static`.

## 2. Understanding Pointer to Pointer

A pointer stores the address of a variable.

A pointer to pointer stores the address of another pointer.

Example:

```c
int data = 100;

int *ptr = &data;

int **pptr = &ptr;
```

Memory relationship:

```text
pptr
 |
 v
ptr
 |
 v
data = 100
```

### Understanding the expressions

| Expression | Meaning |
|---|---|
| `data` | Value of the original variable |
| `&data` | Address of data |
| `ptr` | Address stored in ptr |
| `*ptr` | Value pointed to by ptr |
| `pptr` | Address of ptr |
| `*pptr` | Value stored in ptr (an address) |
| `**pptr` | Value of the original variable |

## 3. Basic Pointer-to-Pointer Program

Source file: `pointer_to_pointer.c`

```c
#include <stdio.h>

int main(void)
{
    int data = 100;

    int *ptr = &data;

    int **pptr = &ptr;

    printf("data   = %d\n", data);
    printf("*ptr   = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);

    return 0;
}
```

### Expected output

```text
data   = 100
*ptr   = 100
**pptr = 100
```

All three expressions access the same integer, but through different levels of indirection.

## 4. Modifying the Original Variable

Using:

```c
**pptr = 500;
```

The pointer chain is followed twice, and the original variable is modified.

This is effectively equivalent to:

```c
data = 500;
```

### Result

| Expression | Value |
|---|---:|
| `data` | 500 |
| `*ptr` | 500 |
| `**pptr` | 500 |

Important: The data value changes, but the pointer addresses do not change.

## 5. Changing the Pointer's Destination

Consider:

```c
int a = 100;
int b = 500;

int *ptr = &a;
int **pptr = &ptr;

*pptr = &b;
```

Initially:

```text
ptr → a → 100
```

After executing:

```c
*pptr = &b;
```

The pointer is redirected:

```text
ptr → b → 500
```

### Output

```text
a       = 100
b       = 500
*ptr    = 500
**pptr  = 500
```

Important distinction:

- `**pptr = 700;` modifies the value pointed to by `ptr`.
- `*pptr = &a;` changes the address stored in `ptr`.

## 6. Modifying a Pointer Through a Function

A normal pointer parameter receives a copy of the pointer.

For example:

```c
void update_pointer(int *ptr)
{
    // Changing ptr here changes only the local copy.
}
```

To modify the caller's original pointer, pass its address using a pointer-to-pointer.

### Source file: `pointer_to_pointer_function.c`

```c
#include <stdio.h>

void update_pointer(int **ptr, int *new_address)
{
    *ptr = new_address;
}

int main(void)
{
    int a = 100;
    int b = 500;

    int *ptr = &a;

    printf("Before function call:\n");
    printf("Value pointed by ptr = %d\n", *ptr);

    update_pointer(&ptr, &b);

    printf("\nAfter function call:\n");
    printf("Value pointed by ptr = %d\n", *ptr);

    return 0;
}
```

### Expected output

```text
Before function call:
Value pointed by ptr = 100

After function call:
Value pointed by ptr = 500
```

### Understanding the function call

```c
update_pointer(&ptr, &b);
```

- `&ptr` passes the address of the original pointer.
- `int **ptr` receives the address of that pointer.
- `*ptr = new_address` modifies the original pointer in `main()`.

## 7. Pointer to Pointer with Static Variables

Consider:

```c
#include <stdio.h>

void update(int **ptr)
{
    static int value = 900;

    *ptr = &value;
}

int main(void)
{
    int a = 100;
    int *ptr = &a;

    update(&ptr);

    printf("%d\n", *ptr);

    return 0;
}
```

### Expected output

```text
900
```

Why use `static`?

| Variable declaration | Lifetime |
|---|---|
| `int value = 900;` | Until the function returns |
| `static int value = 900;` | Entire program execution |

If a normal local variable's address is assigned to the caller's pointer, that pointer becomes dangling when the function returns.

A static variable remains alive, so its address can safely be used after the function returns.

## 8. Practical Embedded Firmware Applications

Pointer-to-pointer is useful in several embedded C scenarios:

1. **UART buffers:** A function can provide the caller with a receive-buffer address.
2. **DMA buffers:** APIs can update a caller's buffer pointer, subject to the DMA buffer's lifetime and ownership rules.
3. **Driver APIs:** A driver initialization function can return a pointer to a handle.
4. **Memory management:** Functions can update a pointer after allocating or releasing memory.
5. **Linked lists:** Functions can modify the head pointer of a linked list.

Example API declaration:

```c
void get_uart_buffer(uint8_t **buffer, size_t *length);
```

Here, `uint8_t **buffer` allows the function to update the caller's buffer pointer.

## 9. Important Engineering Notes

- Always initialize pointers before dereferencing them.
- Never dereference a NULL or invalid pointer.
- Use `int **` when a function needs to modify the caller's `int *` pointer.
- Remember that `*ptr` modifies the pointed-to data, while `*pptr = new_address` can modify the pointer itself.
- Do not return the address of an ordinary local variable.
- Ensure the pointed-to memory remains valid for as long as the caller uses it.
- In embedded systems, consider static allocation and buffer ownership carefully.

## 10. GCC Compilation and Execution

Compile the basic program:

```bash
gcc -Wall -Wextra -std=c11 pointer_to_pointer.c -o pointer_to_pointer
```

Run:

```bash
./pointer_to_pointer
```

Compile the function example:

```bash
gcc -Wall -Wextra -std=c11 pointer_to_pointer_function.c -o pointer_to_pointer_function
```

Run:

```bash
./pointer_to_pointer_function
```

## 11. Learning Summary

| Concept | Understanding |
|---|---|
| `int *ptr` | Pointer to integer |
| `int **pptr` | Pointer to pointer to integer |
| `*ptr` | Access integer value |
| `*pptr` | Access the pointer stored in `pptr` |
| `**pptr` | Access the original integer value |
| `**pptr = 500` | Modify the original integer |
| `*pptr = &b` | Redirect the original pointer |
| `update(&ptr)` | Allow a function to modify the caller's pointer |

**Learning milestone completed:** Pointer-to-pointer fundamentals, dereferencing, pointer reassignment, function-based pointer modification, and static variable lifetime.
