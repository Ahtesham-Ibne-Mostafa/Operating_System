#include <stdio.h>55
#include <stdlib.h>

// Main function: demonstrates variable declaration, initialization, and basic arithmetic operations
int main() {
    // Integer variables
    int x = 10, a;
    a = 20;

    // Floating-point variables
    float b = 5.666464654, f;

    // Double-precision floating-point variables
    double c = 2.3333333, g;

    // Character variables
    char d = 'x', e = 'd';

    // Arithmetic operations
    f = x + b + c + a;        // Sum of int, float, double, and int
    g = x * b / c - a;        // Mixed arithmetic with int, float, double


    // Output the results
    printf("The value of f is %f\n", f);   // Print float result
    printf("The value of g is %lf\n", g);  // Print double result


    int ID;
    char name[100];
    //printf("Enter your ID: ");
    //scanf("%d", &ID); // Input for ID
    printf("Enter your name: " scanf("%s", name) "Enter your id:"scanf("%d", &ID));
    //scanf("%s", name); // Input for name
    printf("Your ID is %d and your name is %s\n",ID, name);

    return 0;
}
