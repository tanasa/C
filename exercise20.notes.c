// Lecture 20

// If a function is defined in file2.c, and you want to use it in file1.c, then :
// You declare the function prototype in file2.h
// And include file2.h in file1.c

// • Header files (.h): Prototypes, global constant and variable declaration.

// 1. utility.h – The Header File

// This contains the function prototype(aka declaration) :
// float getYourTaxBracket();
// It tells the compiler :
// "Hey, there's a function named getYourTaxBracket that returns a float — 
// the body will be defined somewhere else."

// 2. hello.c – The Main File
// Includes :
// #include <stdio.h>      // for standard functions like printf
// #include "utility.h"    // for your custom function prototype
// This is the main program where you :
// Call the function getYourTaxBracket()
// Store its return value in yourTaxBracket

// 3. utility.c – The Source File
// #include "utility.h"
// Defines the actual body of the function :

// float getYourTaxBracket() {
//    // some logic...
//    return yourTaxBracket;
// }

// How These Pieces Work Together :
// File	Role
// utility.h	Declaration(prototype only)
// utility.c	Definition(actual logic)
// hello.c	    Calls the function(uses it)


// #include <stdio.h>    : the header of the system files are < > 
// #include "utility.h"  : the header of non-system files are " " 

// STORAGE CLASS
// VARIABLE SCOPE

// SCOPE : (VISIBILITY)

// BLOCK SCOPE
// FUNCTION SCOPE
// FILE SCOPE
// PROGRAM SCOPE

// STORAGE CLASS : defines life time (duration) (how long it is in the memory)
// AUTO
// STATIC
// EXTERN
// VOLATILE

/*
1. BLOCK SCOPE (LOCAL SCOPE) :

Definition: Variables declared inside{} are only visible within those braces.

float getTaxBracket() {
    ...
        float yourTaxBracket;
    ...
        yourTaxBracket = getYourTaxBracket();
}

*/


/* 
2. PROGRAM SCOPE (GLOBAL SCOPE)

#include "utility.h"   // Includes declarations from another file
int i = 0;             // Global variable
float yourSalary;      // Global variable

void main() {
    ...
    printf("%f", yourSalary);  // Accessing the global variable
    getYourTaxBracket();       // Calls function from another scope
}

OR 

float yourTaxBracket = 0.00;   // Global variable

float getTaxBracket() {
    ...
    printf("What tax bracket %f", yourTaxBracket);  // Accessing global variable
}

*/

/*
FILE SCOPE : use static

static int i = 0;             // File scope: visible only within this file
static float yourTaxBracket;  // Also file-scoped

Declaring a global variable with static limits its visibility to the current file.

This means other.c files cannot access this variable, even if they include a header file.

Explanation :

static int i = 0; is not visible to other files — only accessible within the file it’s declared in.
static float yourTaxBracket; behaves the same way — limited to the file where it's defined.

This is different from regular global variables, which can be shared across files using extern.

*/

/*
STORAGE CLASSES:

auto – default for local variables; memory exists during function execution only.
register – suggests storing the variable in a CPU register.
static – extends the variable's lifetime to the entire program 
         but limits scope if used inside a function.
extern – refers to a global variable defined in another file.


Register storage class in C, which is a request to the compiler to store the variable in a CPU register for faster access.
in REGISTER, not in RAM.

float getTaxBracket() {
    register int i;   // register variable
    auto int j;       // auto variable (default for locals)

    for (i = 0; i < 1000; i++)
        printf("What is i here? %d", i);
}

STATIC VARIABLES : these can be both inside, or outside the functions

static int i = 0;  // File scope, visible only in this file
int jd;

void main() {
    float yourSalary;
    i++;            // Modifies static variable
    getYourTaxBracket();
}

static int i = 0; is a file-scoped static variable — it's not visible outside this .c file.

The variable i retains its value across function calls but cannot be accessed by other files.

Has local scope (only accessible in this function).
Retains its value between function calls.
It's initialized only once, even if the function is called multiple times.

static at global scope → limits visibility to the file (file scope).

Static Local Variable

float howManyCalls() {
    static int i;  // Block scope, permanent storage
    printf("I have been called %d", i);
}

static int i; inside the function: it remembers the last call of the function. 

static at local scope → keeps the value between function calls (permanent storage), but keeps scope local.

EXTERNAL VARIABLE :

#include "utility.h"

static int i = 0;      // File scope: only visible in main.c
extern int j;          // Declared elsewhere, linked at compile time

void main() {
    float yourSalary;
    j = 1;             // Accesses global j from utility.c
    getYourTaxBracket();
}

static int i = 0; → file scope, not visible outside main.c

extern int j; → tells the compiler “j is defined in another file”

utility.c (where j is defined)

int j = 0;  // Global variable with program scope

float howManyCalls() {
    static int i;  // Local scope, static duration
    printf("I have been called %d", i);
}

int j = 0; → global definition of j, accessible across files via extern

static int i; inside howManyCalls() → keeps value across calls, but only visible inside the function

*/

/*

This image discusses storage class modifiers in C, focusing on two key keywords: const and volatile — specifically showcasing const.

CONSTANT (Const Modifiers) :

const float pi = 3.141593;
const char greet[] = "Hello World";
char const *pString = "Hello World";

void main() {
    ...
    greet[0] = 'a';  // ❌ Wrong: attempt to modify a const
}

VOLATILE (Volatile Modifiers) :

volatile int x;
myInt = x;
...
yourInt = x;

volatile int x; tells the compiler:

"Do not assume x stays the same between reads. Always reload it from memory."\

volatile int x can be used from outside of the program.

myInt = x; and yourInt = x; both read from x, but:

Without volatile, the compiler might optimize and reuse the same value.

With volatile, each access to x must go directly to memory, ensuring the most up-to-date value is read.

Why Use volatile?

Used when a variable might be changed:
By hardware (e.g., memory-mapped I/O)
By an interrupt service routine
By another thread in concurrent programming

*/

#include <stdio.h>

int main() {
    return 0;
}
