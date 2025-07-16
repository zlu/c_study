
`size_t` is an unsigned integer type defined in the C standard library. It is used to represent the size of objects in bytes and is the type returned by the `sizeof` operator.  Always use `%zu` in `printf` to print `size_t` values.

### Technical definition

- `size_t` is defined in the headers `<stddef.h>`, `<stdio.h>`, and `<stdlib.h>`.
- Its actual underlying type depends on the platform and compiler, but it is always an unsigned type large enough to contain the size of the largest possible object.

**Typical definition (implementation-dependent):**
```c
typedef unsigned long size_t; // On many 64-bit systems
// or
typedef unsigned int size_t;  // On many 32-bit systems
```

### Usage example

```c
#include <stdio.h>

int main(void) {
    size_t n = sizeof(int); // n will be 4 on most systems
    printf("Size of int: %zu\n", n);
    return 0;
}
```

### When to use `size_t` vs `int` for loop indices

#### Use `size_t` when:
- You are indexing or counting elements in arrays, strings, or memory blocks.
- You are using values returned by `sizeof`, `strlen`, or similar functions (these return `size_t`).
- You want to ensure your code is portable and can handle very large arrays (on 64-bit systems, `size_t` can be much larger than `int`).

**Example:**
```c
size_t len = sizeof(array) / sizeof(array[0]);
for (size_t i = 0; i < len; ++i) {
    // Safe, matches the type of len
}
```

#### Use `int` when:
- You need to count up or down and might use negative values (e.g., reverse loops, error codes).
- The range of values is guaranteed to be small and non-negative (e.g., small fixed-size loops).
- You are working with APIs or libraries that expect `int` indices.

**Example:**
```c
for (int i = 10; i >= 0; --i) {
    // Counting down, negative values possible
}
```

---

### Summary Table

| Use case                | Recommended type |
|-------------------------|-----------------|
| Array/memory indexing   | `size_t`        |
| Looping with negatives  | `int`           |
| Counting elements       | `size_t`        |
| Small, fixed loops      | `int`           |

---

**Rule of thumb:**  
- Use `size_t` for array indices and sizes (especially when interacting with standard library functions).
- Use `int` when negative values are needed or for general-purpose counting where negatives are possible.
