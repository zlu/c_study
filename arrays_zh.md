# C语言数组完全指南

数组是C语言编程中的一个基本概念，它能够有效地存储和操作大量数据集合。本指南涵盖了你需要了解的所有关于C语言数组的知识。

## 1. 同类对象的线性集合
C语言中的数组是同类型变量的集合，在内存中连续存储。元素使用从零开始的索引访问（例如，大小为`N`的数组使用`A[0]`到`A[N-1]`）。

使用数组的关键点：
- 使用`#define`来符号化设置数组大小，以提高可维护性
- 过度声明数组大小（例如，分配10,000而不是100）通常是安全的，但会浪费内存
- 访问数组边界之外是一个常见错误，在运行时通常无法检测到，会导致未定义行为

### 数组初始化
数组可以在声明时通过多种方式初始化：
```c
int arr[5] = {1, 2, 3, 4, 5}; // 完全初始化
int arr[5] = {1, 2};          // 部分初始化，其余设置为0
int arr[5] = {0};             // 所有元素设置为0
int arr[] = {1, 2, 3};        // 大小由初始化器决定
```
当数组未显式初始化时，它们包含不确定的值。在赋值前访问未初始化的数组可能导致未定义行为。

## 2. 读取数据到数组中
当向数组读取数据时，边界检查至关重要，以避免缓冲区溢出。使用"伙伴变量"跟踪已读取的元素数量，确保后续处理遵守数组容量。过多的输入应该明确处理，而不是静默丢弃。

**代码示例：**
```c
#include <stdio.h>
#define MAXVALS 100
int main() {
    int A[MAXVALS], next, n = 0, excess = 0;
    printf("最多输入 %d 个值，按^D结束\n", MAXVALS);
    while (scanf("%d", &next) == 1) {
        if (n == MAXVALS) {
            excess++;
        } else {
            A[n++] = next;
        }
    }
    printf("数组中读入了 %d 个值", n);
    if (excess) {
        printf("，丢弃了 %d 个多余的值", excess);
    }
    printf("\n");
    return 0;
}
```

**附加概念：动态内存分配**
为了灵活性，C语言支持使用`malloc`和`free`进行动态分配：

```c
int *arr = malloc(sizeof(int) * size);
if (arr == NULL) {
    // 处理分配失败
}
free(arr); // 释放内存
```
这允许数组在运行时增长或缩小，不像静态数组。

## 3. 数组排序

排序是数组的一个常见操作。这里是一个简单的冒泡排序示例：

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

**标准库排序**
C语言标准库提供了`qsort`函数进行高效排序，它实现了快速排序算法。快速排序是一个高效的原地排序算法，使用分治策略，平均时间复杂度为O(n log n)。

```c
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
qsort(arr, n, sizeof(int), compare);
```

`qsort`函数接受四个参数：
1. 指向要排序数组的指针
2. 数组中的元素数量
3. 每个元素的字节大小
4. 定义排序顺序的比较函数

比较函数必须返回：
- 如果第一个元素应该在第二个元素之前，返回负值
- 如果元素相等，返回零
- 如果第一个元素应该在第二个元素之后，返回正值

`qsort`对大型数据集更有效，并且通过提供适当的比较函数，可以支持任何数据类型的排序。算法选择一个"轴心"元素，并根据其他元素是小于还是大于轴心将它们划分为两个子数组，然后递归地对子数组进行排序。

## 4. 函数与数组
在函数中，数组作为指针传递，允许修改原始数组。这种行为是C语言的基础，通过避免数组复制来实现内存使用效率。

### 向函数传递数组
向函数传递数组时，始终包含数组大小参数以确保边界安全：
```c
void processArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // 示例操作
    }
}
```

## 5. 二维数组
二维数组是数组的数组，通常用于表示矩阵、网格和表格：
```c
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```
使用`matrix[i][j]`访问元素。内存仍然是连续的，采用行主序排列。

**附加概念：动态二维数组**
对于动态大小，分配二维数组：
```c
int **matrix = malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
}
// 释放内存
for (int i = 0; i < rows; i++) {
    free(matrix[i]);
}
free(matrix);
```

## 6. 字符串和字符串数组
C语言中的字符串是以null结尾的`char`数组。标准库提供了`string.h`函数如`strcpy`和`strcmp`用于字符串操作。字符串可以存储在数组中，既可以是矩形矩阵（固定长度字符串）也可以是不规则数组（可变长度字符串）。

**附加概念：字符串分词**
用于解析，使用`strtok`分割字符串：
```c
#include <string.h>
char str[] = "苹果,香蕉,橘子";
char *token = strtok(str, ",");
while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ",");
}
```

## 7. 指针和数组
在C语言中，数组和指针密切相关。数组名实际上是指向其第一个元素的常量指针。理解指针算术对于高效的数组操作至关重要。

**附加概念：指针算术**
通过指针访问数组元素：
```c
int arr[] = {1, 2, 3};
int *p = arr;
printf("%d\n", *(p + 1)); // 打印2
```

## 8. 程序参数
`argc`（参数计数）和`argv`（参数向量），其中`argv[0]`是程序名。使用`atoi`将字符串参数转换为整数。

**附加概念：错误处理**
验证参数以避免错误：
```c
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "用法: %s <数字>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    printf("数字: %d\n", n);
    return 0;
}
```

## 9. 案例研究：不同单词
本案例研究演示了读取文本并列出不同单词，约束条件是每个单词最多10个字符，总共最多1,000个单词。实现使用`ctype.h`函数如`isalpha`和来自`string.h`的字符串操作函数，采用线性搜索算法。

### 使用哈希表优化性能
对于大型单词集，哈希表实现提供更快的查找：
```c
// 使用开放寻址的简化哈希表
#define TABLE_SIZE 1000
struct WordEntry {
    char word[11];
    int count;
};
struct WordEntry table[TABLE_SIZE];
// 实现哈希和插入函数
```

## 10. 练习和解答
### 练习1：阶乘循环
循环设置`A[0] = 1`，然后每个后续`A[i] = i * A[i-1]`，计算阶乘：
- `A[0] = 1`
- `A[1] = 1 * 1 = 1`
- `A[2] = 2 * 1 = 2`
- `A[3] = 3 * 2 = 6`
- 等等

### 练习2：质数
循环实现埃拉托斯特尼筛法来存储质数：
- 从`A[0] = 2`开始，然后检查从3开始的数字
- 如果一个数`n`不能被任何之前的质数整除，它就存储在`A`中

### 练习5：字符串长度
```c
int strlen(char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
```

### 练习6：修改的`getword`
转换大写为小写并允许数字字符串：
```c
#include <ctype.h>
int getword(char *word, int max) {
    int c, i = 0;
    while ((c = getchar()) != EOF && i < max - 1) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        } else if (isdigit(c)) {
            word[i++] = c;
        } else {
            break;
        }
    }
    word[i] = '\0';
    return i > 0 ? i : EOF;
}
```

### 练习7：单词频率
跟踪并按频率排序：
```c
struct WordEntry {
    char word[11];
    int count;
};
struct WordEntry words[1000];
int n = 0;
// 在main中，在getword之后：
for (int i = 0; i < n; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
}
// 按频率排序
qsort(words, n, sizeof(struct WordEntry), compareByCount);
```

## 11. 附加概念：内存对齐
C语言中的数组在内存中对齐以实现高效访问。未对齐的访问可能在某些架构上导致性能问题或错误。使用`alignas`（C11）进行显式对齐：
```c
#include <stdalign.h>
alignas(16) int arr[100];
```

## 12. 结论
C语言中的数组是管理数据集合的强大工具，从简单的线性数组到复杂的字符串数组和程序参数。理解边界检查、指针算术和动态分配可以增强它们的实用性。结合数组与高级技术如`qsort`、动态内存和哈希表，开发者可以构建健壮和高效的C程序。
