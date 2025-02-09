/*

PREDEFINED FUNCTIONS : 

Highlighted C Header Files& Their Functions
<math.h> → Mathematical Functions

Provides mathematical operations like sqrt(), pow(), sin(), cos(), etc.
<stdio.h> → Input and Output

Used for standard I / O operations like printf(), scanf(), fopen(), etc.
<stdlib.h> → Utility Functions

Includes functions for memory allocation(malloc()), process control(exit()), conversions(atoi()), etc.
<string.h> → String Functions

Provides string manipulation functions like strcpy(), strlen(), strcmp(), strcat(), etc.
<time.h> → Time and Date Functions

Used for handling date and time, with functions like time(), difftime(), strftime().
<signal.h> → Signals

Defines functions and macros for handling signals like SIGINT, SIGKILL, and signal() function.
<setjmp.h> → Non - local Jumps

Provides functions like setjmp() and longjmp() for handling program flow in unusual conditions.
<ctype.h> → Character Class Tests

Includes functions like isdigit(), isalpha(), tolower(), toupper() to check character types.
*/

/* Function Prototype : Allows Function Calls Before Definition

Without a prototype, C requires that functions be defined before they are used.
Helps Catch Errors at Compile Time

If a function is called with the wrong number / type of arguments, the compiler will generate an error.
Improves Code Readability& Modularity

Prototypes allow breaking code into multiple files(e.g., header files with function declarations).

*/

/*

FUNCTION PROTOTYPE : 

A forward declaration (also called a function prototype) tells the compiler about a function before it is used, 
ensuring type checking and correctness.

*/

#include <stdio.h>
#include <math.h>

// Function Prototype (Declaration)
int add(int, int);

// Function Prototype (Declaration)
int multiply(int, int);

int main() {

float PI = 3.14159265;

printf("3 to the power of 4 = %.2f\n", pow(3, 4));
printf("The square root of 9 = %.2f\n", sqrt(9));
printf("The absolute value of -234 = %d\n", abs(-234));

printf("The sine of PI / 2 = %.2f\n", sin(PI / 2));
printf("The cosine of PI = %.2f\n", cos(PI));
printf("The arcsine of 0.5 = %.2f degrees\n", asin(0.5) * 180 / PI);
printf("The arccosine of 0.5 = %.2f degrees\n", acos(0.5) * 180 / PI);
printf("The arctangent of 0.5 = %.2f degrees\n", atan(0.5) * 180 / PI);

printf("Log base 10 of 100 = %.2f\n", log10(100));
printf("The ceiling of 65.789 = %.2f\n", ceil(65.789));
printf("The floor of 65.789 = %.2f\n", floor(65.789));

// Function call 
int result1 = add(5, 3); 
printf("Sum: %d\n", result1);

int result2 = multiply(4, 5); 
printf("Product: %d\n", result2);

return 0;
}

// Function Definition
int add(int a, int b) {
    return a + b;
}

// Function Definition
int multiply(int x, int y) {
    return x * y;
}


/*
Key Points to Remember : Function Prototype :

✅ Parameter names are optional in the prototype (only data types are required).
✅ Function prototypes are usually placed at the top of the file or in a header file (.h) for modularity.

When to Use a Function Prototype?
✔ When functions are defined after main().
✔ When using multiple files, such as .h header files.
✔ When writing modular and reusable code.

*/

/*

HEADER FILES : 

In C, a header file is a file with a .h extension that contains function prototypes, macro definitions, 
structure definitions, and other declarations that can be shared among multiple source files (.c files). 
It helps organize code and promote reusability.

Best Practices :

Use header files for function prototypes (void myFunction();), NOT definitions.
Use inline or static inline for very small utility functions.
Implement functions in .c files to prevent multiple definition issues.

*/