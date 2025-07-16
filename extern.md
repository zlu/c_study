#### What does `extern` do in C?

- The `extern` keyword in C is used to **declare a variable or function that is defined in another file or scope**.
- It tells the compiler: “This variable/function exists, but its memory will be allocated elsewhere (not here).”
- Most commonly used for **global variables** and **function declarations** across multiple files.

#### Example: Using `extern` for Variables

Suppose you have two files:

**file1.c**
```c
int count = 10;  // Definition and allocation
```

**file2.c**
```c
extern int count;  // Declaration, no allocation

void print_count() {
    printf("%d\n", count);  // Uses the variable defined in file1.c
}
```

- Only one file should actually define the variable (allocate memory), others use `extern` to access it.

#### Example: Using `extern` for Functions

**file1.c**
```c
void hello() {
    printf("Hello!\n");
}
```

**file2.c**
```c
extern void hello();  // Declaration

int main() {
    hello();  // Calls the function defined in file1.c
    return 0;
}
```

#### Summary

- `extern` is for **declaration** (not definition).
- Used to **share variables/functions between files**.
- Prevents multiple definitions and linker errors.

---

### 中文解释

#### C语言中的 `extern` 作用

- `extern` 关键字用于**声明一个在其他文件或作用域中定义的变量或函数**。
- 它告诉编译器：“这个变量/函数在别处已经定义，这里只是声明，不分配内存。”
- 常用于**全局变量**和**跨文件的函数声明**。

#### 变量的 `extern` 示例

假设有两个文件：

**file1.c**
```c
int count = 10;  // 定义并分配内存
```

**file2.c**
```c
extern int count;  // 声明，不分配内存

void print_count() {
    printf("%d\n", count);  // 使用file1.c中定义的变量
}
```

- 只有一个文件真正定义变量（分配内存），其他文件用 `extern` 声明来访问。

#### 函数的 `extern` 示例

**file1.c**
```c
void hello() {
    printf("Hello!\n");
}
```

**file2.c**
```c
extern void hello();  // 声明

int main() {
    hello();  // 调用file1.c中定义的函数
    return 0;
}
```

#### 总结

- `extern` 用于**声明**（不是定义）。
- 用于**在多个文件间共享变量/函数**。
- 防止多重定义和链接错误。
