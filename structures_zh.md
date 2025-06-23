# C语言结构体完全指南

结构体（Structures）在C语言中允许将不同类型的变量组合在一起，为数据抽象和组织提供了强大的工具。本文涵盖了《comp20005 C语言数值计算导论》第8章的关键概念，重点介绍结构体、其操作、与函数的交互、指针和数组。包含代码示例和练习解答以加深理解。

## 1. 声明结构体
结构体是一个可能包含不同类型变量的集合，通过成员名称访问。`typedef`关键字通常用于定义程序范围内使用的结构体类型。

**示例：行星结构体**
```c
#include <string.h>
#define PLANETSTRLEN 20
typedef char pstr_t[PLANETSTRLEN+1];
typedef struct {
    pstr_t name, orbits;
    double distance; /* 百万公里 */
    double mass;     /* 千克 */
    double radius;   /* 千米 */
} planet_t;

planet_t one_planet;
strcpy(one_planet.name, "Earth");
strcpy(one_planet.orbits, "Sun");
one_planet.distance = 149.6;
one_planet.mass = 5.976e+24;
one_planet.radius = 6378.1;
```

**附加概念：结构体初始化**
结构体可以在声明时初始化：
```c
planet_t earth = {"Earth", "Sun", 149.6, 5.976e+24, 6378.1};
```

## 2. 结构体操作
相同类型的结构体可以相互赋值，复制所有成员，包括数组。但是，不支持直接比较（`==`、`<`等）；需要自定义比较函数。

**赋值示例：**
```c
planet_t planet1, planet2;
planet1 = planet2; /* 复制所有成员 */
```

**比较函数：**
```c
int cmp_planet(const planet_t *p1, const planet_t *p2) {
    int name_cmp = strcmp(p1->name, p2->name);
    if (name_cmp != 0) return name_cmp;
    return (p1->mass > p2->mass) - (p1->mass < p2->mass);
}
```

**附加概念：嵌套结构体**
结构体可以包含其他结构体，用于层次化数据：
```c
typedef struct {
    int day, month, year;
} date_t;
typedef struct {
    char reg_num[7];
    date_t first_reg, expiry;
} car_t;
```

## 3. 结构体、指针和函数
结构体传递给函数时是按值传递，会创建副本。推荐使用指针传递以避免复制开销并允许修改。使用`->`运算符通过指针访问成员。

**函数示例：**
```c
void print_planet(const planet_t *p) {
    printf("%s orbits %s, mass: %.2e kg\n", p->name, p->orbits, p->mass);
}
```

**返回结构体：**
```c
planet_t read_planet(void) {
    planet_t p;
    scanf("%s %s %lf %lf %lf", p.name, p.orbits, &p.distance, &p.mass, &p.radius);
    return p;
}
```

**附加概念：动态分配**
动态分配结构体以实现灵活的内存管理：
```c
#include <stdlib.h>
planet_t *p = malloc(sizeof(planet_t));
if (p) {
    strcpy(p->name, "Mars");
    free(p);
}
```

## 4. 结构体和数组
结构体可以作为数组元素，支持复杂数据的集合。指针算术适用于结构体数组。

**数组示例：**
```c
#define MAXBODIES 100
planet_t planets[MAXBODIES];
int nplanets = 0;
planets[nplanets++] = earth;
```

**包含数组的结构体：**
```c
typedef struct {
    int nplanets;
    planet_t planets[MAXBODIES];
} solar_system_t;
solar_system_t solar_system;
solar_system.planets[0] = earth;
solar_system.nplanets = 1;
```

## 5. 练习
### 练习1：汽车结构体
定义一个包含注册号、日期和其他字段的汽车结构体。

**解答：**
```c
typedef struct {
    int day, month, year;
} date_t;

typedef struct {
    char reg_num[7];
    date_t first_reg, expiry;
    char manufacturer[40];
    char make[40];
    char body_type[40];
    char color[40];
    int num_owners;
} car_t;
```

### 练习2：更大的行星
编写一个函数来比较太阳系中行星的质量。

**解答：**
```c
int bigger_planet(solar_system_t *s, int p1, int p2) {
    if (p1 < 0 || p1 >= s->nplanets || p2 < 0 || p2 >= s->nplanets) {
        return -1;
    }
    if (s->planets[p1].mass > s->planets[p2].mass) {
        return 1;
    }
    return 0;
}
```

## 6. 附加概念：内存对齐
结构体可能包含用于对齐的填充。使用`alignas`（C11）进行控制：
```c
#include <stdalign.h>
alignas(16) planet_t aligned_planet;
```

## 7. 结论
C语言中的结构体提供了强大的数据抽象机制，支持层次化组织、函数集成和基于数组的集合。理解它们的操作、指针交互和内存管理对于高效的C语言编程至关重要。提供的练习和解答加强了这些概念的实际应用。
