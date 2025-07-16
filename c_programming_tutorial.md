  # Complete C Programming Tutorial

## Table of Contents
1. [Introduction to C](#introduction-to-c)
2. [Setting Up Your Environment](#setting-up-your-environment)
3. [Basic Syntax and Structure](#basic-syntax-and-structure)
4. [Variables and Data Types](#variables-and-data-types)
5. [Input and Output](#input-and-output)
6. [Operators](#operators)
7. [Control Flow](#control-flow)
8. [Functions](#functions)
9. [Arrays](#arrays)
10. [Strings](#strings)
11. [Pointers](#pointers)
12. [Structures](#structures)
13. [File I/O](#file-io)
14. [Memory Management](#memory-management)
15. [Advanced Topics](#advanced-topics)

## Introduction to C

C is a powerful, low-level programming language developed by Dennis Ritchie at Bell Labs in the early 1970s. It's the foundation for many modern programming languages and operating systems, including Unix and Linux.

### Why Learn C?
- **Performance**: C produces highly efficient code
- **Portability**: C programs can run on various platforms
- **Foundation**: Understanding C helps with other languages
- **System Programming**: Essential for operating systems and embedded systems
- **Control**: Direct memory management and hardware access

## Setting Up Your Environment

### Windows
1. Install a C compiler like GCC (via MinGW or Code::Blocks)
2. Use an IDE like Code::Blocks, Dev-C++, or Visual Studio

### Linux/Mac
1. Install GCC: `sudo apt-get install gcc` (Ubuntu) or `brew install gcc` (Mac)
2. Use any text editor + terminal, or IDEs like VS Code

### Basic Compilation
```bash
gcc filename.c -o outputname
./outputname
```

## Basic Syntax and Structure

Every C program follows this basic structure:

```c
#include <stdio.h>  // Preprocessor directive

int main() {        // Main function
    // Your code here
    return 0;       // Return statement
}
```

### Your First C Program

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

**Key Components:**
- `#include <stdio.h>`: Includes standard input/output library
- `int main()`: Entry point of the program
- `printf()`: Function to display output
- `return 0`: Indicates successful program execution
- `\n`: Newline character

## Variables and Data Types

### Basic Data Types

```c
#include <stdio.h>

int main() {
    // Integer types
    int age = 25;
    short small_num = 100;
    long big_num = 1000000L;
    
    // Floating point types
    float height = 5.9f;
    double precise_pi = 3.14159265359;
    
    // Character type
    char grade = 'A';
    
    // Boolean (requires stdbool.h in C99)
    // bool is_student = true;
    
    printf("Age: %d\n", age);
    printf("Height: %.1f\n", height);
    printf("Pi: %.5f\n", precise_pi);
    printf("Grade: %c\n", grade);
    
    return 0;
}
```

---

#### Scalar Types in C

A **scalar type** is a data type that holds a single value (not a collection or aggregate). In C, the main scalar types are:
- **Integer types**: `char`, `short`, `int`, `long`, `long long`
- **Floating-point types**: `float`, `double`, `long double`
- **Pointer types**: e.g., `int *`
- **Enumeration types**: `enum`

#### Signed and Unsigned

- **Signed types** can represent both positive and negative numbers (e.g., `int`, `signed int`).
  - Example: `int x = -5;`
- **Unsigned types** can only represent zero and positive numbers (e.g., `unsigned int`).
  - Example: `unsigned int y = 10;`
- The difference is in how the bits are interpreted: signed types use one bit for the sign (positive/negative), while unsigned types use all bits for the value, allowing a larger maximum value but no negatives.

| Type           | Range (typical 32-bit)         |
|----------------|-------------------------------|
| int            | -2,147,483,648 to 2,147,483,647|
| unsigned int   | 0 to 4,294,967,295             |

#### size_t

- `size_t` is a special unsigned integer type defined in `<stddef.h>` and `<stdio.h>`.
- It is used to represent the size of objects in bytes and is the type returned by `sizeof`.
- It is always non-negative (unsigned) and large enough to contain the maximum size of any object on the platform.
- Example:
  ```c
  size_t len = sizeof(int);  // len is typically 4 on 32-bit/64-bit systems
  ```

---

#### C语言中的标量类型（Scalar Types）

**标量类型**指的是只能存储单一数值的数据类型（不是数组或结构体等集合类型）。C语言中的主要标量类型有：
- **整数类型**：`char`、`short`、`int`、`long`、`long long`
- **浮点类型**：`float`、`double`、`long double`
- **指针类型**：如 `int *`
- **枚举类型**：`enum`

#### 有符号（signed）与无符号（unsigned）

- **有符号类型（signed）**：可以表示正数和负数（如 `int`、`signed int`）。
  - 例：`int x = -5;`
- **无符号类型（unsigned）**：只能表示零和正数（如 `unsigned int`）。
  - 例：`unsigned int y = 10;`
- 区别在于二进制的解释方式：有符号类型用一个比特位表示正负，无符号类型所有比特位都用来表示数值，因此无符号类型能表示更大的正整数，但不能表示负数。

| 类型           | 取值范围（典型32位系统）         |
|----------------|-------------------------------|
| int            | -2,147,483,648 到 2,147,483,647|
| unsigned int   | 0 到 4,294,967,295             |

#### size_t

- `size_t` 是C标准库中定义的一种特殊无符号整数类型，定义在 `<stddef.h>` 和 `<stdio.h>` 头文件中。
- 用于表示对象的字节大小，是 `sizeof` 运算符的返回类型。
- 只能为非负数（无符号），并且足够大以容纳平台上任何对象的最大可能大小。
- 例子：
  ```c
  size_t len = sizeof(int);  // 在32位或64位系统上通常为4
  ```

---


### Variable Declaration Rules
- Must start with a letter or underscore
- Can contain letters, numbers, and underscores
- Case-sensitive
- Cannot use C keywords

### Constants

```c
#include <stdio.h>

#define PI 3.14159  // Macro constant

int main() {
    const int MAX_SIZE = 100;  // Constant variable
    
    printf("PI: %.5f\n", PI);
    printf("Max size: %d\n", MAX_SIZE);
    
    return 0;
}
```

## Input and Output

### printf() - Formatted Output

```c
#include <stdio.h>

int main() {
    int num = 42;
    float price = 19.99f;
    char name[] = "Alice";
    
    printf("Number: %d\n", num);
    printf("Price: $%.2f\n", price);
    printf("Name: %s\n", name);
    printf("Character: %c\n", name[0]);
    
    // Multiple values
    printf("User: %s, Age: %d, Balance: $%.2f\n", name, num, price);
    
    return 0;
}
```

### scanf() - Formatted Input

```c
#include <stdio.h>

int main() {
    int age;
    float salary;
    char name[50];
    
    printf("Enter your name: ");
    scanf("%s", name);  // Note: no & for strings
    
    printf("Enter your age: ");
    scanf("%d", &age);  // & is address operator
    
    printf("Enter your salary: ");
    scanf("%f", &salary);
    
    printf("\nHello %s!\n", name);
    printf("You are %d years old.\n", age);
    printf("Your salary is $%.2f\n", salary);
    
    return 0;
}
```

I'll explain why `scanf` takes addresses in C, both in English and Chinese as you prefer.

## Why `scanf` Takes Addresses

### English Explanation

In C, `scanf` takes addresses because it needs to **modify the variables** you pass to it. Here's why:

1. **C uses pass-by-value**: When you pass a variable to a function, C passes a **copy** of the variable's value, not the variable itself.

2. **`scanf` needs to modify variables**: `scanf` reads data from input and needs to store that data in your variables.

3. **Address is the solution**: By passing the address (`&variable`), you're telling `scanf` "store the input data at this memory location."

### Example

```c
int age;
char name[50];

// WRONG - scanf can't modify age
scanf("%d", age);  // This won't work!

// CORRECT - scanf gets the address where to store the value
scanf("%d", &age);  // scanf stores input at age's memory location

// For arrays, you don't need & because array name is already an address
scanf("%s", name);  // name is already a pointer to the array
```

### Memory Visualization

```
Memory:
age: [  ]  ← Empty variable
     ↑
     &age points here

After scanf("%d", &age) with input "25":
age: [25]  ← scanf stored 25 at this address
```


## Operators

### Arithmetic Operators

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %d\n", a, b, a / b);
    printf("Modulo: %d %% %d = %d\n", a, b, a % b);
    
    // Increment/Decrement
    printf("a++ = %d\n", a++);  // Post-increment
    printf("++a = %d\n", ++a);  // Pre-increment
    
    return 0;
}
```

### Comparison Operators

```c
#include <stdio.h>

int main() {
    int x = 5, y = 10;
    
    printf("x == y: %d\n", x == y);  // Equal to
    printf("x != y: %d\n", x != y);  // Not equal to
    printf("x < y: %d\n", x < y);    // Less than
    printf("x > y: %d\n", x > y);    // Greater than
    printf("x <= y: %d\n", x <= y);  // Less than or equal
    printf("x >= y: %d\n", x >= y);  // Greater than or equal
    
    return 0;
}
```
And the results are:

```bash
a && b: 0
a || b: 1
!a: 0
```

### Logical Operators

```c
#include <stdio.h>

int main() {
    int a = 1, b = 0;
    
    printf("a && b: %d\n", a && b);  // Logical AND
    printf("a || b: %d\n", a || b);  // Logical OR
    printf("!a: %d\n", !a);          // Logical NOT
    
    return 0;
}
```

## Control Flow

### if-else Statements

```c
#include <stdio.h>

int main() {
    int score;
    
    printf("Enter your score: ");
    scanf("%d", &score);
    
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }
    
    return 0;
}
```

### switch Statement

```c
#include <stdio.h>

int main() {
    int day;
    
    printf("Enter day number (1-7): ");
    scanf("%d", &day);
    
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
    }
    
    return 0;
}
```

### Loops

#### for Loop

```c
#include <stdio.h>

int main() {
    // Basic for loop
    for (int i = 1; i <= 5; i++) {
        printf("Count: %d\n", i);
    }
    
    // Multiplication table
    int num = 5;
    printf("\nMultiplication table for %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    
    return 0;
}
```

#### while Loop

```c
#include <stdio.h>

int main() {
    int count = 1;
    
    while (count <= 5) {
        printf("Count: %d\n", count);
        count++;
    }
    
    // Input validation
    int number;
    printf("Enter a positive number: ");
    scanf("%d", &number);
    
    while (number <= 0) {
        printf("Invalid! Enter a positive number: ");
        scanf("%d", &number);
    }
    
    printf("You entered: %d\n", number);
    
    return 0;
}
```

#### do-while Loop

```c
#include <stdio.h>

int main() {
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You selected Option 1\n");
                break;
            case 2:
                printf("You selected Option 2\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    
    return 0;
}
```

## Functions

### Basic Function Syntax

```c
#include <stdio.h>

// Function declaration
int add(int a, int b);
void greet(char name[]);
int factorial(int n);

int main() {
    int result = add(5, 3);
    printf("5 + 3 = %d\n", result);
    
    greet("Alice");
    
    int fact = factorial(5);
    printf("5! = %d\n", fact);
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

### Function with Local Variables

```c
#include <stdio.h>

int global_var = 100;  // Global variable

void demonstrate_scope() {
    int local_var = 50;  // Local variable
    printf("Local variable: %d\n", local_var);
    printf("Global variable: %d\n", global_var);
}

int main() {
    demonstrate_scope();
    printf("Global variable in main: %d\n", global_var);
    // printf("Local variable: %d\n", local_var);  // Error!
    
    return 0;
}
```

## Arrays

### Basic Arrays

```c
#include <stdio.h>

int main() {
    // Array declaration and initialization
    int numbers[5] = {10, 20, 30, 40, 50};
    int scores[] = {85, 92, 78, 96, 88};  // Size inferred
    
    // Accessing elements
    printf("First number: %d\n", numbers[0]);
    printf("Last number: %d\n", numbers[4]);
    
    // Modifying elements
    numbers[0] = 15;
    printf("Modified first number: %d\n", numbers[0]);
    
    // Array size
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array size: %d\n", size);
    
    // Printing all elements
    printf("All numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

### Multidimensional Arrays

```c
#include <stdio.h>

int main() {
    // 2D array (matrix)
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Print matrix
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Array Functions

```c
#include <stdio.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numbers[] = {45, 23, 78, 56, 89, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array: ");
    print_array(numbers, size);
    
    int max = find_max(numbers, size);
    printf("Maximum value: %d\n", max);
    
    return 0;
}
```

## Strings

### String Basics

```c
#include <stdio.h>
#include <string.h>

int main() {
    // String declaration
    char name1[] = "Alice";
    char name2[20] = "Bob";
    char name3[20];
    
    // String input
    printf("Enter your name: ");
    scanf("%s", name3);
    
    // String length
    printf("Length of '%s': %zu\n", name1, strlen(name1));
    
    // String copy
    strcpy(name2, name1);
    printf("After copying: %s\n", name2);
    
    // String concatenation
    strcat(name2, " Smith");
    printf("After concatenation: %s\n", name2);
    
    // String comparison
    if (strcmp(name1, "Alice") == 0) {
        printf("Names match!\n");
    }
    
    return 0;
}
```

### String Functions

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_uppercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int count_vowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char text[] = "Hello World";
    
    printf("Original: %s\n", text);
    printf("Vowels: %d\n", count_vowels(text));
    
    to_uppercase(text);
    printf("Uppercase: %s\n", text);
    
    return 0;
}
```

## Pointers

### Pointer Basics

```c
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;  // Pointer to num
    
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    // Modify through pointer
    *ptr = 100;
    printf("New value of num: %d\n", num);
    
    return 0;
}
```

### Pointers and Arrays

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    // Access array elements using pointer
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(ptr + %d) = %d\n", 
               i, arr[i], i, *(ptr + i));
    }
    
    // Pointer arithmetic
    printf("\nUsing pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    
    return 0;
}
```

### Pointers and Functions

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void modify_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int x = 10, y = 20;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Before modification: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    modify_array(numbers, size);
    
    printf("After modification: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Structures

### Basic Structures

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Create and initialize struct
    struct Student student1 = {"Alice", 20, 3.8};
    
    // Alternative initialization
    struct Student student2;
    strcpy(student2.name, "Bob");
    student2.age = 22;
    student2.gpa = 3.5;
    
    // Access struct members
    printf("Student 1:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);
    
    printf("\nStudent 2:\n");
    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("GPA: %.2f\n", student2.gpa);
    
    return 0;
}
```

### Arrays of Structures

```c
#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int pages;
    float price;
};

void print_book(struct Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Price: $%.2f\n", book.price);
    printf("---\n");
}

int main() {
    struct Book library[3] = {
        {"The C Programming Language", "Kernighan & Ritchie", 272, 45.99},
        {"Data Structures and Algorithms", "Cormen", 1312, 89.99},
        {"Operating Systems", "Tanenbaum", 976, 79.99}
    };
    
    printf("Library Books:\n");
    for (int i = 0; i < 3; i++) {
        print_book(library[i]);
    }
    
    return 0;
}
```

### Pointers to Structures

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

void print_person(struct Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    struct Person person = {"John", 30};
    struct Person *ptr = &person;
    
    // Access using pointer
    printf("Using pointer: %s, %d\n", ptr->name, ptr->age);
    
    // Modify using pointer
    ptr->age = 31;
    printf("After modification: %s, %d\n", person.name, person.age);
    
    print_person(ptr);
    
    return 0;
}
```

## File I/O

### Basic File Operations

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char text[] = "Hello, File I/O!";
    char buffer[100];
    
    // Write to file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    fprintf(file, "%s\n", text);
    fprintf(file, "This is line 2\n");
    fprintf(file, "Number: %d\n", 42);
    fclose(file);
    
    // Read from file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("Reading from file:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
    
    return 0;
}
```

### File I/O with Structures

```c
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee employees[] = {
        {1, "Alice", 50000.0},
        {2, "Bob", 55000.0},
        {3, "Charlie", 60000.0}
    };
    
    FILE *file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Write binary data
    fwrite(employees, sizeof(struct Employee), 3, file);
    fclose(file);
    
    // Read binary data
    struct Employee read_employees[3];
    file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fread(read_employees, sizeof(struct Employee), 3, file);
    fclose(file);
    
    printf("Employees read from file:\n");
    for (int i = 0; i < 3; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", 
               read_employees[i].id, 
               read_employees[i].name, 
               read_employees[i].salary);
    }
    
    return 0;
}
```

## Memory Management

### Dynamic Memory Allocation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display elements
    printf("Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Reallocate memory
    arr = (int*)realloc(arr, (n + 2) * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    
    // Add two more elements
    arr[n] = 100;
    arr[n + 1] = 200;
    
    printf("After reallocation: ");
    for (int i = 0; i < n + 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free memory
    free(arr);
    
    return 0;
}
```

### Memory Functions

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc - allocates uninitialized memory
    int *ptr1 = (int*)malloc(5 * sizeof(int));
    
    // calloc - allocates zero-initialized memory
    int *ptr2 = (int*)calloc(5, sizeof(int));
    
    if (ptr1 == NULL || ptr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("malloc array (uninitialized): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    
    printf("calloc array (zero-initialized): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");
    
    // Initialize malloc array
    for (int i = 0; i < 5; i++) {
        ptr1[i] = (i + 1) * 10;
    }
    
    printf("After initialization: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    
    free(ptr1);
    free(ptr2);
    
    return 0;
}
```

## Advanced Topics

### Function Pointers

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int calculate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

int main() {
    int (*func_ptr)(int, int);
    
    func_ptr = add;
    printf("5 + 3 = %d\n", func_ptr(5, 3));
    
    func_ptr = multiply;
    printf("5 * 3 = %d\n", func_ptr(5, 3));
    
    // Using function pointer as parameter
    printf("Using calculate function:\n");
    printf("Add: %d\n", calculate(10, 5, add));
    printf("Multiply: %d\n", calculate(10, 5, multiply));
    
    return 0;
}
```

### Typedef and Enums

```c
#include <stdio.h>

// typedef for custom types
typedef unsigned int uint;
typedef struct {
    char name[50];
    int age;
} Person;

// enum for constants
enum Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum Status {
    SUCCESS = 0,
    ERROR = -1,
    PENDING = 1
};

int main() {
    uint number = 42;
    Person person = {"Alice", 25};
    
    enum Day today = WEDNESDAY;
    enum Status result = SUCCESS;
    
    printf("Number: %u\n", number);
    printf("Person: %s, %d years old\n", person.name, person.age);
    printf("Today is day %d\n", today);
    printf("Status: %d\n", result);
    
    return 0;
}
```

### Preprocessor Directives

```c
#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Conditional compilation
#define DEBUG 1

int main() {
    printf("PI = %.5f\n", PI);
    printf("Square of 5 = %d\n", SQUARE(5));
    printf("Max of 10 and 20 = %d\n", MAX(10, 20));
    
#if DEBUG
    printf("Debug mode is ON\n");
#endif
    
#ifdef DEBUG
    printf("DEBUG is defined\n");
#endif
    
    return 0;
}
```

## Best Practices

1. **Always initialize variables** before using them
2. **Check return values** of functions like `malloc()`, `fopen()`
3. **Free allocated memory** to prevent memory leaks
4. **Use meaningful variable names** for better code readability
5. **Comment your code** to explain complex logic
6. **Use const** for values that shouldn't change
7. **Validate input** from users
8. **Follow consistent indentation** and formatting
9. **Break large functions** into smaller, manageable pieces
10. **Use header files** for function declarations and constants

## Common Pitfalls to Avoid

1. **Array bounds checking** - Always ensure array indices are within bounds
2. **Uninitialized pointers** - Initialize pointers before use
3. **Memory leaks** - Free dynamically allocated memory
4. **Buffer overflows** - Use safe string functions like `strncpy()`
5. **Integer overflow** - Be aware of data type limits
6. **Dangling pointers** - Don't use pointers after freeing memory
7. **