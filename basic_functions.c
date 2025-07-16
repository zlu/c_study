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