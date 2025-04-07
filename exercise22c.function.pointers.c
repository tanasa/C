#include <stdio.h>

void pintAllNameAge(char** name, int** age, int size);
void pintOneNameAge(char* name, int* age);
void pintOneNameAge2(char* name, int* age);

// passing the name of a function as a POINTER

/* Function pointers in C are pointers that point to the address of a function.
You can use them to call functions dynamically, pass functions as arguments, 
or even store a list of functions. */

// The function pointer functionPointer can point to any function that matches the signature :
// Takes a char* (pointer to a character array, like a string).
// Takes an int(an integer).

int main() {
    printf("Pointing to a function:\n");

    int age1 = 62, age2 = 59, age3 = 56, age4 = 53, count, size;
    int* pointerofIntArray[4] = { &age1, &age2, &age3, &age4 };
    char* strArray[4] = { "Binod", "Bimal", "Binay", "Bineet" };

    pintAllNameAge(strArray, pointerofIntArray, sizeof(pointerofIntArray) / sizeof(pointerofIntArray[0]));

    printf("\n\n");

    size = sizeof(strArray) / sizeof(strArray[0]);

    void (*functionPointer)(char* name, int age); // Function Pointer
    functionPointer = pintOneNameAge;             // Function name is an address

    for (count = 0; count < size; count++) {
        pintOneNameAge(strArray[count], *pointerofIntArray[count]);
        (*functionPointer)(strArray[count], *pointerofIntArray[count]);
        // Both forms are equivalent in functionality.
        functionPointer(strArray[count], *pointerofIntArray[count]);
        // the name pintOneNameAge() is replaced with *functionPointer()
    }

    void (*functionPointer2)(char* name, int *age); // Function Pointer
    functionPointer2 = pintOneNameAge2;             // Function name is an address

    for (count = 0; count < 4; count++) {
        pintOneNameAge2(strArray[count], pointerofIntArray[count]);
        (*functionPointer2)(strArray[count], pointerofIntArray[count]);
        // Both forms are equivalent in functionality.
        functionPointer2(strArray[count], pointerofIntArray[count]);
        // This is correct as long as you dereference inside the function.    
        // Dereferences the pointer and gets the actual integer value(e.g., 62).
    }

    return 0;
}

void pintAllNameAge(char** name, int** age, int size) {
    int count;
    for (count = 0; count < size; count++) {
        printf("Mr. %s is %d old\n", name[count], *age[count]);
        // *age[count]  // Dereferences the pointer to get the integer value
    }
}

void pintOneNameAge(char* name, int age) {
    printf("Mr. %s is %d old\n", name, age);
}

// Prints a single name and age, also prints the pointer address
void pintOneNameAge2(char* name, int* age) {
    printf("Mr. %s is %d old\n", name, *age);
    // The* operator dereferences the pointer, giving the value stored at the address.
    printf("Mr. %s 's age pointer address is %p. \n", name, age);
}

/*
* 
* void (*functionPointer)(char* name, int age); // Function Pointer
This line declares a function pointer named functionPointer.

Syntax Explanation:
void - The return type of the function that the pointer will point to.

(*functionPointer) - Declares functionPointer as a pointer to a function.

(char* name, int age) - Specifies that the pointed-to function takes a char* and an int as parameters.

What This Means:
The function pointer functionPointer can point to any function that matches the signature:

Takes a char* (pointer to a character array, like a string).

Takes an int (an integer).

Returns void.

2. Assigning the Function Pointer:

functionPointer = pintOneNameAge; // Function name is an address

Here:

pintOneNameAge is the name of a function, and in C, the name of a function itself is a pointer to its address.

You do not need to use the & operator because the function name naturally evaluates to a pointer.

Why This Works:
You are essentially saying:

functionPointer = &pintOneNameAge;
But since the function name itself is treated as a pointer, you can simply write:

functionPointer = pintOneNameAge;
This assignment tells the compiler that functionPointer now points to the pintOneNameAge function.

3. Calling the Function via the Pointer:

for (count = 0; count < size; count++) {
    pintOneNameAge(strArray[count], *pointerofIntArray[count]); // Direct call
    (*functionPointer)(strArray[count], *pointerofIntArray[count]); // Indirect call
    // the name pintOneNameAge() is replaced with *functionPointer()
}

Direct Call:

pintOneNameAge(strArray[count], *pointerofIntArray[count]);
This line directly calls the pintOneNameAge function using its name.

Indirect Call Using Function Pointer:

(*functionPointer)(strArray[count], *pointerofIntArray[count]);
This line calls the function indirectly using the function pointer.

The parentheses around *functionPointer are necessary to properly dereference the function pointer before invoking it.

You can also write this line as:

functionPointer(strArray[count], *pointerofIntArray[count]);
Both forms are equivalent in functionality.

*/