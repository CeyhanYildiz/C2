#include <stdio.h>

// Function with the same signature as the function pointer
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Declare a function pointer variable
    int (*operation)(int, int);
    
    // Assign the function pointer variable to the desired function
    operation = add;
    
    // Call the function through the function pointer
    int result = operation(5, 3);
    printf("Result of addition: %d\n", result);
    
    // Assign the function pointer variable to a different function
    operation = subtract;
    
    // Call the function through the function pointer again
    result = operation(5, 3);
    printf("Result of subtraction: %d\n", result);
    
    return 0;
}
