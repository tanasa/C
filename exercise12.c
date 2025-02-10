#include <stdio.h>
#include <math.h>


/* Formal parameters

These are variables declared in the function header(parameter list).
They act as placeholders for the values passed during a function call.
Defined inside the function and used as local variables.

*/

/* Actual parameters 

These are values (expressions) provided when calling a function.
Passed from the caller (main function) to the function.
The actual parameter values are copied into formal parameters.

*/

/*
The correspondence between Formal and Actual parameters is by POSITION.
*/

// Function Prototype (forward declaration)
void DrawFiveByTenBox(void);

// Forward declaration (function prototype)
void printSquareRoot(long double);

// Design SwapValues function with the use of pointers !
void SwapValues(int* N1, int* N2);

// Swapping without pointers
void swapWithoutPointers(int a, int b);

// Swapping with pointers
void swapWithPointers(int* a, int* b);

// Explaining the pointers
void printPointerInfo();

int main() {

    int myNumber = 0; 

    // Function Call
    DrawFiveByTenBox();

    // Taking input from the user
    printf("Enter a number to find the square root of: ");
    scanf_s("%d", &myNumber);

    // Function call with typecasting to long double
    printSquareRoot((long double)myNumber);

    // For SwapValues function, we have to use POINTERS !

    int yourAge, myAge;
    printf("\nWhat is your age: ");
    scanf_s("%d", &yourAge);
    printf("\nWhat is my age: ");
    scanf_s("%d", &myAge);

    SwapValues(&yourAge, &myAge);

    printf("Your age %d has been swapped with my age %d\n", yourAge, myAge);

    // Swapping values with pointers and without pointers

    int x = 5, y = 10;

    // Swapping without pointers
    printf("Before swapWithoutPointers - x: %d, y: %d\n", x, y);
    swapWithoutPointers(x, y);
    printf("After swapWithoutPointers - x: %d, y: %d (No change outside function)\n\n", x, y);

    // Swapping with pointers
    printf("Before swapWithPointers - x: %d, y: %d\n", x, y);
    swapWithPointers(&x, &y);
    printf("After swapWithPointers - x: %d, y: %d (Values swapped successfully)\n", x, y);

    // Explaining the pointers
    printPointerInfo();

    return 0;
}

// Function Definition
void DrawFiveByTenBox(void)
{
    int height = 5, width = 10;
    int count, count2;

    // Top border
    for (count = 1; count <= width; count++) {
        printf("-");
    }
    printf("\n");

    // Middle part with spaces
    for (count = 1; count <= height - 2; count++) {
        printf("|");
        for (count2 = 1; count2 <= width - 2; count2++) {
            printf(" ");
        }
        printf("|\n");
    }

    // Bottom border
    for (count = 1; count <= width; count++) {
        printf("-");
    }

    printf("\n\n");
}


// Function definition
void printSquareRoot(long double number) {
    printf("The square root of %.2Lf = %.2Lf\n", number, sqrt(number));
    printf("\n\n");
}

// Used &yourAge and &myAge when calling SwapValues, so it modifies the original values.
// Used *N1 and *N2 inside SwapValues to dereference pointers and swap actual values.

void SwapValues(int* N1, int* N2)
{
    int temp;
    temp = *N1;
    *N1 = *N2;
    *N2 = temp;
}

// Function to swap values without pointers
void swapWithoutPointers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapWithoutPointers - a: %d, b: %d\n", a, b);
}

// Function to swap values using pointers
void swapWithPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*

Why Do We Need to Swap Using Pointers?

When a function is called in C, arguments are passed by value by default. 

This means that a function receives copies of the actual arguments, 
and any modifications to these copies do not affect the original variables.

void swapWithPointers(int* a, int* b) {
    int temp = *a;  // Step 1: Store the value at address 'a' in temp
    *a = *b;        // Step 2: Assign value at address 'b' to address 'a'
    *b = temp;      // Step 3: Assign temp value (original *a) to address 'b'
}

a and b are pointers, meaning they store memory addresses of x and y.
*a and *b dereference the pointers, allowing us to modify the original values at those memory addresses.
Since we modify values directly in memory, the changes persist outside the function.

What Does "Dereferencing a Pointer" Mean?
Dereferencing a pointer means accessing the value stored at the memory address the pointer is pointing to. We do this using the * (asterisk) operator.

*/

void printPointerInfo() {
 
    int x = 10;
    int* ptr = &x;  // ptr stores the memory address of x

    printf("Value of x: %d\n", x);
    printf("Memory address of x: %p\n", &x);
    printf("Value stored at ptr: %p\n", ptr);
    printf("Value at address stored in ptr: %d\n", *ptr);
}
