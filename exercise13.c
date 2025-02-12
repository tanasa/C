/*

1. Memory Organization

The computer’s memory (RAM) is divided into small units called bytes.
Each byte has a unique address, starting from 0x00000000 up to the maximum addressable memory location.

2. Memory Management by the Operating System (OS)

When a program is executed, the OS loads it into memory.
The OS assigns a virtual memory address to each variable, function, and object.
These addresses are mapped to physical memory using a Memory Management Unit (MMU).

3. How Addresses Are Assigned to Variables

When you declare a variable in C, such as:
int myInt = 208;

The compiler:
Allocates a memory location of 4 bytes (since int is typically 4 bytes).
Assigns an address to myInt (e.g., 0x7ffeefbff5dc).
The address can be accessed using the address-of operator (&):
printf("Address of myInt: %p\n", (void*)&myInt);

4. How the CPU Accesses Memory

The CPU has special registers for handling memory:

Memory Address Register (MAR) → Holds the memory address to be accessed.
Memory Data Register (MDR) → Stores the actual data fetched from that address.

When the CPU needs to access a variable:

It places the address of the variable into the MAR.
It fetches the data and loads it into the MDR.
The CPU then processes the data.

5. Pointer Variables and Addresses

Pointers store memory addresses explicitly:

int a = 10;
int *ptr = &a;  // ptr now holds the address of 'a'
printf("Address stored in ptr: %p\n", (void*)ptr);

6. Stack and Heap Memory Allocation

Stack: Stores local variables and function calls (automatically managed).
Heap: Stores dynamically allocated memory (malloc, calloc).

7. Virtual Memory and Address Translation

Why Virtual Memory?
Physical memory (RAM) is limited.
The OS provides virtual addresses that map to actual physical memory.
The Memory Management Unit (MMU) handles this translation.

Example:

A program thinks variable x is at 0x7ffeefbff5dc (virtual).
The MMU translates it to 0x1A003F20 (physical).
This allows memory protection and enables larger applications than physical RAM allows.

*/

/*

POINTERS : addressability

& is ADDRESS OPERATOR (only for variables, not for constants or for expressions).

Variable addresses are numbers, and these can be also stored in the variables.

POINTER : a variable that holds the address of another variable.

DECLARATION : int * pint;

INITIALIZATION : mint = 50 ; pint = &mint ;

Bineet's class :
  value 50 is recorded at the memory address 24568 ;
  the memory address 30006 stores the value 24568.

int *pmyInt;
char *pmyChar;
float *pmyFloat;
long *pmyLong;

DEREFERENCE OPERATOR : retrieving value pointed to by a pointer

Use * operator – Indirection (Dereference) Operator

& (Address-of)	: Retrieves the memory address of a variable.
* (Indirection/Dereference)	: Retrieves the value stored at a memory address.

*/


/*
L-values → Have memory locations (variables, pointers, arrays).
R-values → Temporary values (constants, expressions).
*/

#include <stdio.h>

void SwapValues(int* N1, int* N2);
void SwapAddresses(int* N1, int* N2);
void swapPointers(int** p1, int** p2);

int main(void) {

    int Int = 208;

    printf("Value of myInt = %d\n", Int);
    printf("Address of myInt = %p\n", &Int);

    int myInt;         // Declare an integer variable
    int* pmyInt;       // Declare a pointer to an integer

    myInt = 5208;      // Assign a value to myInt
    pmyInt = &myInt;   // Assign the address of myInt to pmyInt

    // Printing values and addresses
    printf("Value of myInt= %d\n", myInt);
    printf("Address of myInt= %p\n", &myInt);
    printf("Value stored in pmyInt (Address of myInt)= %p\n", pmyInt);
    printf("Address of pmyInt= %p\n", &pmyInt);
    printf("Dereferencing pmyInt (Value at address stored in pmyInt)= %d\n", *pmyInt);

    // First print
    printf("\n");
    printf("Value of myInt = %d\n", myInt);
    printf("Value pointed to by pmyInt = %d\n\n", *pmyInt);

    // Changing myInt directly
    myInt = 34;
    printf("\n");
    printf("Value of myInt = %d\n", myInt);
    printf("Value pointed to by pmyInt = %d\n\n", *pmyInt);

    // Changing value using pointer dereferencing
    *pmyInt = 15; // equivalent with myInt = 15;
    printf("\n");
    printf("Value of myInt = %d\n", myInt);
    printf("Value pointed to by pmyInt = %d\n\n", *pmyInt);

    printf("Address stored in pmyInt (myInt's address) = %p\n", pmyInt);
    printf("Address of myInt = %p\n\n", &myInt); // Print address of myInt

    printf("Address of pmyInt itself = %p\n", &pmyInt);

    // Pointer Dereferencing(*pmyInt = 15;)
    // The statement* pmyInt = 15; assigns 15 to the memory location that pmyInt is pointing to.
    // This means myInt (which pmyInt is pointing to) now holds 15.

    // Some compilers may generate a warning when using% p with an int* .The correct approach is :
    // printf("Address of myInt = %p\n", (void*)&myInt);
    // (void*)&myInt ensures the address is treated as a generic pointer type(void*), which %p expects.
    
    /*
    
     *pmyInt could have both a R-value and a L-value.
    
     1. L-value (Left Value)

     An L-value represents a memory location that can store data.
     It can appear on the left or right side of an assignment (=) operation.
     It must have an address, meaning it refers to a variable or an object in memory.

     Examples of L-values

     int x = 10;   // x is an L-value
     x = 20;       // Valid: L-value on the left of assignment
     int *ptr = &x; // Valid: x has an address
     x is an L-value because it represents a modifiable storage location.

     Invalid Example (L-value required)

     10 = x;  // ❌ Error: 10 is not an L-value (it has no memory address)
    
    */
    
    /*
    
     2. R-value (Right Value)

     An R-value represents a temporary value or a constant that does not have a specific memory location.
     It cannot appear on the left-hand side of an assignment.
     Typically, it is used for computation and expression evaluation.

     Examples of R-values

     int x = 10;  // 10 is an R-value (temporary value assigned to x)
     int y = x + 5;  // (x + 5) is an R-value
     
     The expression x + 5 produces an R-value because the result is temporary.

     Invalid Example (R-value required)

     int *ptr;
     ptr = &10;  // ❌ Error: Cannot get address of an R-value (10 has no address)

     Conclusion :

     L-value → Has a memory address, can be modified.
     R-value → Temporary value, cannot be assigned to directly.

    */
    
    int yourAge, myAge;

    printf("\nWhat is your age? ");
    scanf_s("%d", &yourAge);

    printf("\nWhat is my age? ");
    scanf_s("%d", &myAge);

    printf("\nOriginally, your age = %d and my age = %d", yourAge, myAge);

    SwapValues(&yourAge, &myAge);

    printf("\nYour age %d has been swapped with my age %d\n\n", yourAge, myAge);

    // Why Swapping Addresses Won’t Work :

    int x = 5, y = 10;
    int* px = &x, * py = &y;

    SwapAddresses(px, py);

    printf("x = %d, y = %d\n", x, y);  // ❌ Values remain the same
    printf("px points to: %d, py points to: %d\n", *px, *py);

    // Explaining double pointers :

    printf("\n\n");

    printf("Explaining double pointers : Before swapping: px points to %d, py points to %d\n", *px, *py);

    swapPointers(&px, &py);  // Passing addresses of pointers

    printf("Explaining double pointers : After swapping: px points to %d, py points to %d\n", *px, *py);

    return 0;
}

// Pass by reference(int* N1, int* N2) ensures the function modifies actual values.
// Using pointers(*N1, *N2) allows direct memory manipulation.
// Swapping logic is implemented correctly with a temporary variable(temp).

void SwapValues(int* N1, int* N2) {
    int temp;

    printf("\nFunction has original your age = %d and my age = %d", *N1, *N2);

    temp = *N1;  // Step 1: Store the value pointed to by N1 in temp
    *N1 = *N2;   // Step 2: Assign the value pointed to by N2 to N1
    *N2 = temp;  // Step 3: Assign temp (original *N1 value) to N2

    // Dereferencing(*N1 and *N2) is required because :
    // N1 and N2 store memory addresses(not values).
    // To get or modify the values at those addresses, we use* N1 and *N2.
    
    printf("\nYour age %d has been swapped with my age %d in the function\n\n", *N1, *N2);
}

// If we mistakenly try to swap the pointers themselves inside the function:
// Swapping addresses (N1 = N2;) inside the function does not work because 
// function arguments in C are passed by value, 
// and N1 and N2 are just local copies of the original pointers.

// Swapping values (*N1 = *N2;) works because it modifies the actual data stored at the memory locations.

void SwapAddresses(int* N1, int* N2) {
    int* temp;

    temp = N1;  // ❌ Swapping addresses, NOT values
    N1 = N2;    // ❌ Changing the local pointer, has no effect outside
    N2 = temp;  // ❌ Only affects local copies, not main() variables
}

// This approach only swaps the local copies of the pointer variables (N1 and N2), 
// but does not affect yourAge and myAge in main().

// Reason : In C, function arguments are passed by value, meaning :
// The addresses stored in N1 and N2 are copied when calling SwapValues().
// Changing N1 or N2 inside the function does not affect the original pointers in main().

// Dereferencing(*) is necessary to access / modify values stored at pointer addresses.
// Swapping logic works correctly only with dereferenced values (*N1, *N2).
// Pointers store addresses, but dereferencing accesses / modifies values at those addresses.

// To swap pointer addresses, we must use double pointers (int **), 
// passing the addresses of the pointers instead of just their values.

// Understanding Double Pointers (int**) in C
// A double pointer (int**) is a pointer that stores the address of another pointer.
// This allows us to modify pointer addresses inside functions, 
// which is useful for swapping pointers or working with dynamically allocated memory.

// Why Do We Need Double Pointers ?
// When we pass a pointer (int* p) to a function, only a copy of the pointer is passed (pass - by - value). 
// If we modify the pointer inside the function, it does not change the original pointer in main().

// To modify the original pointer, we pass the address of the pointer (int**), 
// allowing us to change where the pointer points.

void swapPointers(int** p1, int** p2) {
    int* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}