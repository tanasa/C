#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MYNAME "Bineet"

// Function to dynamically allocate memory and copy a string
char* getString(char* name) {
    char* pInstructor;

    // Allocate memory for the string
    pInstructor = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    if (pInstructor == NULL) {      // Always check for NULL
        printf("Not enough memory to allocate %s\n", MYNAME);
        return NULL;
    }

    // Copy the string into the allocated memory
    strcpy_s(pInstructor, strlen(MYNAME) + 1, MYNAME);
    // strcpy(pInstructor, MYNAME); would also be OK
    return pInstructor;
}

// Returning the Pointer :
// After copying the string into the allocated memory, the function returns the pointer :

int main() {
    char* pstr = getString(MYNAME);
    if (pstr != NULL) {
        printf("Dynamic Allocation Succeeded for %s\n\n", pstr);
        printf("%s\n", MYNAME);
        // Make sure to free the memory
        free(pstr);
        pstr = NULL;
    }
    return 0;
}

/*

pInstructor = (char*)malloc(...);
The pointer pInstructor now holds the address of the first byte of the allocated memory block.

If the allocation fails, malloc returns NULL, and the pointer should be checked to ensure it is not NULL.

Dynamic Memory Allocation :
The memory is not allocated directly to the pointer itself.Instead :

    The pointer stores the memory address of the dynamically allocated block.

    The allocated memory lives in the heap, while the pointer itself is stored in the stack.

    This separation allows the allocated memory to persist even after the function that created 
    the pointer returns.

*/

/* REFERENCE COUNTING :

Reference counting is a memory management technique used to track how many references (or pointers) point 
to a particular resource, such as an object or a block of memory. 

When the reference count drops to zero, it indicates that the resource is no longer needed, 
and the memory can be safely deallocated.

Python uses automatic reference counting for memory management. 

C and C++ do not use automatic reference counting for memory management. 
Instead, they primarily rely on manual memory management, with some automated support available 
in modern C++ through smart pointers. 

*/

/*
SMART POINTERS : AUTOMATIC MEMORY MANAGEMENT (C++)

A smart pointer is a C++ object that acts like a regular pointer but provides automatic memory management. 
Unlike raw pointers, smart pointers automatically manage the lifetime of dynamically allocated objects, 
ensuring that memory is released when no longer needed.

RAII (Resource Acquisition Is Initialization):
Resources are automatically acquired and released as objects are created and destroyed.

*/

/* GARBAGE COLLECTION : 

Garbage Collection (GC) is an automatic memory management technique used by some programming languages 
to identify and reclaim memory that is no longer in use. 

The primary goal of garbage collection is to free up memory occupied by objects that are no longer accessible 
or needed by the application.

In languages without garbage collection (like C and C++), the programmer is responsible for:

Allocating memory (using malloc, new).
Freeing memory (using free, delete).
Forgetting to free memory leads to memory leaks.
Incorrectly freeing memory can cause dangling pointers and segmentation faults.
Garbage collection automates this process, reducing the risk of memory management errors.

*/

/*

Common Garbage Collection Algorithms :

1. Reference Counting
Keeps track of the number of references to each object.
When the reference count drops to zero, the object is deleted.

2. Mark and Sweep (Tracing GC)
3. Mark-Compact (Improvement of Mark and Sweep)
4. Generational Garbage Collection

*/

