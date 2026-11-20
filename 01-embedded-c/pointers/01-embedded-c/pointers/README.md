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
