Write a program and execute under the command line.  The output should look like this:

```bash
0 > ./first
1 element 0 is 9,       its square is 81
2 element 1 is 2.9,     its square is 8.41
3 element 2 is 0,       its square is 0
4 element 3 is 7e-05,   its square is 4.9e-09
5 element 4 is 3e+25,   its square is 9e+50
```

### `%zu`
- Used to print a value of type `size_t` (an unsigned integer type, often used for array indices or sizes).
- The `z` modifier tells `printf` to expect a `size_t` argument, and `u` means unsigned decimal.
- Example: If `i` is `size_t i = 3;`, then `printf("%zu", i);` prints `3`.

### `%g`
- Used to print floating-point numbers (`float` or `double`).
- `%g` automatically chooses between fixed-point (`%f`) and exponential (`%e`) notation, depending on the value and precision.
- It also removes unnecessary trailing zeros.
- Example:  
  - `printf("%g", 123.45);` prints `123.45`
  - `printf("%g", 0.00007);` prints `7e-05`
  - `printf("%g", 2.E+25);` prints `2e+25`

---

**Summary:**  
- `%zu` prints an unsigned integer of type `size_t` (for array indices, sizes, etc.).
- `%g` prints a floating-point number in either normal or scientific notation, whichever is shorter and more readable.