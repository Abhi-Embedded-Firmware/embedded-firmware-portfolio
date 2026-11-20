# Pointer Basics in C

## 1. Objective

Understand how pointers store memory addresses, access variables indirectly, and modify variable values through dereferencing.

## 2. Source Code

Refer to [`pointer_basics.c`](pointer_basics.c).

## 3. Key Concepts

### Variable declaration

```c
int data = 100;
```

An integer variable named `data` is created and initialized with the value `100`.

### Pointer declaration and initialization

```c
int *ptr = &data;
```

- `int *ptr`: Declares a pointer to an integer.
- `&data`: Returns the memory address of `data`.
- `ptr`: Stores the address of `data`.

### Pointer dereferencing

```c
printf("%d\n", *ptr);
```

The `*` operator dereferences the pointer and accesses the value stored at the memory address held by `ptr`.

### Modifying a variable through a pointer

```c
*ptr = 200;
```

This writes `200` to the memory location pointed to by `ptr`.

Since `ptr` points to `data`, the original variable is modified.

## 4. Expected Output

```text
Value of data       : 100
Address of data     : <memory address>
Value of ptr        : <same memory address>
Value pointed by ptr: 100

After modifying through pointer:
Value of data       : 200
Value pointed by ptr: 200
```

The actual memory address varies between program executions and systems.

## 5. Important Observations

1. `&data` returns the address of the variable.
2. `ptr` stores that address.
3. `*ptr` accesses the value at that address.
4. Modifying `*ptr` modifies the original variable.
5. The address printed for `&data` and `ptr` should match.

## 6. Embedded Firmware Relevance

Pointers are fundamental in embedded firmware development.

Common applications include:

- Accessing memory-mapped peripheral registers.
- Passing buffers to device drivers.
- Handling communication data buffers.
- Sharing data between functions.
- Working with DMA buffers.
- Implementing linked data structures.

## 7. Engineering Notes

- Always initialize pointers before dereferencing them.
- Avoid dereferencing NULL or invalid pointers.
- Ensure the pointed-to object's lifetime is valid.
- Use the correct pointer type for the object being accessed.
- Use `%p` with a `(void *)` cast when printing addresses.

## 8. Build and Run

Compile using GCC:

```bash
gcc -Wall -Wextra -std=c11 pointer_basics.c -o pointer_basics
```

Run:

```bash
./pointer_basics
```

---

**Learning outcome:** Understand the relationship between a variable, its memory address, a pointer, and pointer dereferencing.

----------------------------------------------------------------------------------------------------------------------------------

## 9. Pointer Arithmetic in C

### Objective

Understand how pointer arithmetic works and how pointer increments depend on the data type.

### Source Code

Refer to [`pointer_arithmetic.c`](pointer_arithmetic.c).

### 1. Array and Pointer Initialization

```c
int data[4] = {10, 20, 30, 40};

int *ptr = data;
```

- `data` is an integer array containing four elements.
- In this expression, `data` points to the first element, `data[0]`.
- `ptr` stores the address of the first element.

### 2. Pointer Increment

```c
ptr++;
```

Pointer increment advances the pointer by the size of its data type.

For an integer pointer:

```c
sizeof(int) = 4
```

On the tested system, each increment advances the address by 4 bytes.

### 3. Actual Execution Results

| Operation | Address movement | Value |
|---|---:|---:|
| Initial pointer | 0 bytes | 10 |
| First `ptr++` | +4 bytes | 20 |
| Second `ptr++` | +8 bytes total | 30 |

### 4. Pointer Arithmetic Formula

Conceptually:

```text
New address = Old address + sizeof(data type)
```

For example:

- `uint8_t *ptr`: advances by 1 byte.
- `uint16_t *ptr`: advances by 2 bytes.
- `uint32_t *ptr`: advances by 4 bytes.

The actual sizes are determined by the implementation's type definitions.

### 5. Pointer Subtraction

```c
ptr - data
```

Pointer subtraction between elements of the same array returns the difference in number of elements, not bytes.

In this example:

- `data` points to `data[0]`.
- `ptr` points to `data[2]`.
- `ptr - data` returns `2`.

The result type is `ptrdiff_t`, printed using `%td`.

### 6. Expected Output

```text
Size of int: 4 bytes

Initial pointer:
Address stored in ptr : <address>
Value pointed by ptr  : 10

After ptr++:
Address stored in ptr : <address + 4 bytes>
Value pointed by ptr  : 20

After another ptr++:
Address stored in ptr : <address + 8 bytes>
Value pointed by ptr  : 30

Elements moved from start: 2
```

Actual addresses vary between executions.

### 7. Embedded Firmware Applications

Pointer arithmetic is useful for:

- UART and SPI communication buffers.
- DMA data buffers.
- Array and packet parsing.
- Memory block traversal.
- Accessing memory-mapped data structures.

### 8. Important Engineering Notes

- Pointer arithmetic must remain within the same array or one position past its end.
- Do not dereference a one-past-the-end pointer.
- Pointer subtraction is valid only for pointers into the same array (or one past it).
- Pointer arithmetic is scaled according to the pointed-to type.
- Avoid assuming every integer type has the same size on every platform.

**Learning outcome:** Understand scaled pointer arithmetic, pointer increments, and pointer subtraction, with practical relevance to embedded firmware buffers and memory access.
