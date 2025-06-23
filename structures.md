# Understanding Structures in C: A Comprehensive Guide

Structures in C enable grouping of variables of different types, providing a powerful tool for data abstraction and organization. This blog post covers key concepts from Chapter 8 of "comp20005 Intro. to Numerical Computation in C," focusing on structures, their operations, interactions with functions, pointers, and arrays. Code examples and solutions to exercises are included to reinforce learning.

## 1. Declaring Structures
A structure is a collection of variables, possibly of different types, accessed via component names. The `typedef` keyword is commonly used to define structure types for program-wide use.

**Example: Planet Structure**
```c
#include <string.h>
#define PLANETSTRLEN 20
typedef char pstr_t[PLANETSTRLEN+1];
typedef struct {
    pstr_t name, orbits;
    double distance; /* million km */
    double mass; /* kilograms */
    double radius; /* kilometers */
} planet_t;

planet_t one_planet;
strcpy(one_planet.name, "Earth");
strcpy(one_planet.orbits, "Sun");
one_planet.distance = 149.6;
one_planet.mass = 5.976e+24;
one_planet.radius = 6378.1;
```

**Additional Concept: Structure Initialization**
Structures can be initialized at declaration:
```c
planet_t earth = {"Earth", "Sun", 149.6, 5.976e+24, 6378.1};
```

## 2. Operations on Structures
Structures of the same type can be assigned, copying all components, including arrays. However, direct comparison (`==`, `<`, etc.) is not supported; custom comparison functions are required.

**Assignment Example:**
```c
planet_t planet1, planet2;
planet1 = planet2; /* Copies all components */
```

**Comparison Function:**
```c
int cmp_planet(const planet_t *p1, const planet_t *p2) {
    int name_cmp = strcmp(p1->name, p2->name);
    if (name_cmp != 0) return name_cmp;
    return (p1->mass > p2->mass) - (p1->mass < p2->mass);
}
```

**Additional Concept: Nested Structures**
Structures can contain other structures for hierarchical data:
```c
typedef struct {
    int day, month, year;
} date_t;
typedef struct {
    char reg_num[7];
    date_t first_reg, expiry;
} car_t;
```

## 3. Structures, Pointers, and Functions
Structures are passed to functions by value, creating a copy. Passing pointers is preferred to avoid copying overhead and allow modifications. The `->` operator accesses members via pointers.

**Function Example:**
```c
void print_planet(const planet_t *p) {
    printf("%s orbits %s, mass: %.2e kg\n", p->name, p->orbits, p->mass);
}
```

**Returning Structures:**
```c
planet_t read_planet(void) {
    planet_t p;
    scanf("%s %s %lf %lf %lf", p.name, p.orbits, &p.distance, &p.mass, &p.radius);
    return p;
}
```

**Additional Concept: Dynamic Allocation**
Dynamically allocate structures for flexible memory management:
```c
#include <stdlib.h>
planet_t *p = malloc(sizeof(planet_t));
if (p) {
    strcpy(p->name, "Mars");
    free(p);
}
```

## 4. Structures and Arrays
Structures can be array elements, enabling collections of complex data. Pointer arithmetic works with structure arrays.

**Array Example:**
```c
#define MAXBODIES 100
planet_t planets[MAXBODIES];
int nplanets = 0;
planets[nplanets++] = earth;
```

**Structure Containing Arrays:**
```c
typedef struct {
    int nplanets;
    planet_t planets[MAXBODIES];
} solar_system_t;
solar_system_t solar_system;
solar_system.planets[0] = earth;
solar_system.nplanets = 1;
```

## 5. Exercises
### Exercise 1: Car Structure
Define a structure for cars with registration number, dates, and other fields.

**Solution:**
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

### Exercise 2: Bigger Planet
Write a function to compare planet masses in a solar system.

**Solution:**
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

## 6. Additional Concept: Memory Alignment
Structures may include padding for alignment. Use `alignas` (C11) for control:
```c
#include <stdalign.h>
alignas(16) planet_t aligned_planet;
```

## 7. Conclusion
Structures in C provide a robust mechanism for data abstraction, supporting hierarchical organization, function integration, and array-based collections. Understanding their operations, pointer interactions, and memory management is crucial for efficient C programming. The provided exercises and solutions enhance practical application of these concepts.