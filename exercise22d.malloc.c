// Memory segments :
// STACK
// HEAP 

/*
1. Stack Memory :

Definition:
The stack is a region of memory that stores temporary variables created by functions.

Characteristics :
    LIFO(Last In, First Out) : Data is stored and retrieved in the reverse order of insertion.
    Fast Access : Very quick because memory is organized in a contiguous block.
    Automatic Allocation / Deallocation : Managed by the system.
    Limited Size : Can cause stack overflow if too much memory is used.

    Scope :
    Stores local variables, function calls, return addresses, and function parameters.

    Lifespan :
    Variables are destroyed when the function call ends.

//Examples:
main()
int N1, N2,
function1() : int A, B, C;
function2() : int D, E, F;

*/

/*
2. Heap Memory : accessed through the POINTERS

Heap Memory in C :

Heap memory is a region of your computer’s memory used for dynamic memory allocation. 
Unlike stack memory, which is automatically managed and has a fixed size, 
heap memory is more flexible but requires manual management.

Characteristics of Heap Memory :

Dynamic Allocation : You can allocate memory at runtime based on program requirements.
Manual Deallocation : You must explicitly free the allocated memory; otherwise, it leads to memory leaks.
Slower Access : Compared to stack memory, heap access is relatively slower.
Flexible Size : Heap memory can grow or shrink as needed.
Managed via Pointers : You typically access heap memory through pointers.

Memory Allocation Functions:
malloc() (Memory Allocation):

Allocates a specified number of bytes.

Memory Allocation Functions :
1. malloc() (Memory Allocation):

Allocates a specified number of bytes.
Does not initialize the memory (contains garbage values).
Returns a void pointer to the allocated memory or NULL if it fails.
    Allocates a specified number of bytes.
    Does not initialize the memory(contains garbage values).
    Returns a void pointer to the allocated memory or NULL if it fails.
    Syntax: void* malloc(size_t size);

int *arr = (int *)malloc(5 * sizeof(int));  // Allocate space for 5 integers
if (arr == NULL) {
    printf("Memory allocation failed\n");
}

2. calloc() (Contiguous Allocation):

Allocates memory for an array of elements, initializing all bytes to 0.
Useful when you need zero-initialized memory.
void *calloc(size_t nitems, size_t size);

int *arr = (int *)calloc(5, sizeof(int));  // Allocates space for 5 integers, all set to 0
if (arr == NULL) {
    printf("Memory allocation failed\n");
}

3. realloc() (Reallocate Memory):

Resizes a previously allocated memory block.
Can expand or shrink the allocated memory.

Syntax:
void *realloc(void *ptr, size_t size);

Example:
arr = (int *)realloc(arr, 10 * sizeof(int));  // Resize the array to hold 10 integers
if (arr == NULL) {
    printf("Memory reallocation failed\n");
}

4. free() (Deallocate Memory): MEMORY LEAKS

Frees the memory previously allocated by malloc(), calloc(), or realloc().
Failure to free memory leads to memory leaks.

Syntax:
void free(void *ptr);
free(arr);   // Release the allocated memory
arr = NULL;  // Good practice to avoid dangling pointers

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MYNAME "Bineet"

int main() {
    int* arr;
    int n = 5;

    // Allocating memory using malloc
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initializing and printing values
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Reallocating memory to increase size
    int* temp = (int*)realloc(arr, 10 * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(arr); // Free the original memory to avoid leaks
        return 1;
    }
    arr = temp;

    // Adding new values after reallocation
    for (int i = 5; i < 10; i++) {
        arr[i] = (i + 1) * 2;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Freeing memory after usage
    free(arr);
    arr = NULL;

    printf("------------------------------\n");
    printf("------------------------------\n");

    char* pInstructor;

    // Memory allocation and error check for string
    pInstructor = (char*)malloc(strlen(MYNAME) + 1);
    if (pInstructor == NULL) {
        printf("Not enough memory to allocate %s\n", MYNAME);
        return 1;
    }

    // Copy the string into the allocated memory
    strcpy_s(pInstructor, strlen(MYNAME) + 1, MYNAME);
    // pInstructor = MYNAME;
    // Using strcpy instead of strcpy_s for portability
    printf("Dynamic Allocation Succeeded for %s\n\n", pInstructor);

    // Free the allocated memory for the string
    free(pInstructor);
    pInstructor = NULL; // because MYNAME is a constant before main()

    return 0;
}


/*
Common Errors in Heap Memory Usage:

Memory Leaks:

Forgetting to call free() after using malloc() or calloc().
Dangling Pointers: Accessing memory after it has been freed.
Double Free Error: Calling free() on the same pointer more than once.
Using Uninitialized Pointers: If malloc() fails, the returned pointer is NULL.
Accessing Freed Memory: Not setting the pointer to NULL after freeing it can lead to undefined behavior.

Why Use Heap Memory?

Dynamic Data Structures:
Like linked lists, trees, or graphs that grow/shrink during runtime.

Large Data Storage:
Stack memory is limited, while heap memory is more flexible.

Persistent Data:

Data that must survive beyond the function scope.

*/

/*

Hardware-Level Representation:

a. Stack Representation:

Registers Involved:

SP (Stack Pointer): Points to the top of the stack.
BP (Base Pointer) / FP (Frame Pointer): Points to the base of the current stack frame.

Assembly Instructions:

PUSH: Decrements the SP and stores a value at the new top.
POP: Reads the value at SP and increments SP.

Why Downward Growth:

Traditionally chosen to detect stack overflows more easily.
Growing towards unused lower memory space is safer on most systems.

b. Heap Representation:

Registers Involved:
BRK (Break Pointer): Marks the end of the heap.
Heap Pointer: Managed via system calls (e.g., sbrk()).

Allocation:

Uses functions like malloc to request memory.
Internally calls system calls like brk() or mmap() to allocate more heap space.

Fragmentation:
Can suffer from external fragmentation as memory is dynamically allocated and freed.

Example:
int *p = malloc(sizeof(int) * 10);
At the hardware level:

Allocates space by moving the break pointer.

Returns a pointer to the newly allocated space.

*/


/* Best Practice : Proper Memory Management

Check for NULL: Always check the result of malloc to ensure the allocation was successful.
Copy the String: Use strcpy() to copy the string to the allocated memory.
Free Correctly: Set the pointer to NULL after freeing, not before.
Avoid Memory Leaks: Always ensure that dynamically allocated memory is released before the program ends.

pinstructor = (char*)malloc(sizeof(char) * (strlen(myName) + 1));
free(pinstructor);

*/

