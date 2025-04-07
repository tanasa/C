#include <stdio.h>

void pintAllNameAge(char** name, int** age, int size);
void pintOneNameAge(char* name, int* age);
void pintOneNameAge2(char* name, int* age);
void printAge(int* age);

// void pintAllNameAge(char** name, int** age, int size);
// char** name - Pointer to an array of strings(names).
// int** age - Pointer to an array of integer pointers(ages).
// int size - Number of elements in the arrays.

// void pintOneNameAge(char* name, int* age);
// pintOneNameAge: Prints a single name and age.
// Takes two parameters :
// char* name - A single name.
// int* age - A single age.

int main() {
    int age1 = 62, age2 = 59, age3 = 56, age4 = 53, count;

    int* pointerofIntArray[4] = { &age1, &age2, &age3, &age4 };
    // An array of integer pointers (pointerofIntArray) is created, 
    // where each element holds the address of one of the age variables.
    
    // int* pointerofIntArray[4]
    // int* -Indicates that each element of the array will be a pointer to an integer.
    // pointerofIntArray[4] - Declares an array of 4 elements.

    // If you wrote : int pointerofIntArray[4] = { age1, age2, age3, age4 };
    // This would store the values directly in the array, not the addresses.
    // printf("%d\n", *pointerofIntArray[0]);  // Outputs the value stored in age1 (62 initially
    // pointerofIntArray[0] gives the pointer(address).
    // * pointerofIntArray[0] dereferences the pointer to get the value(62).

    char* strArray[4] = { "Binod", "Bimal", "Binay", "Bineet" };
     // an array of 4 pointers, where each pointer points to a char (or more specifically, 
     // a string literal in this context);
     // A string literal in C is actually a pointer to the first character of a read-only memory block.
     // The name of a string literal is a pointer to the first character.
     // strArray[0]->Address of "Binod"
     // strArray[1]->Address of "Bimal"
     // strArray[2]->Address of "Binay"
     // strArray[3]->Address of "Bineet"

     // You could also declare an array of strings like this:
     // char strArray[4][10] = { "Binod", "Bimal", "Binay", "Bineet" };
     // Differences:
     // Memory Allocation :
     // char* strArray[4] : Stores pointers to the string literals(read - only).
     // char strArray[4][10] : Allocates contiguous memory for the entire array and stores the strings directly.

    pintAllNameAge(strArray, pointerofIntArray, 4);

    printf("\n\n");
    for (count = 0; count < 4; count++) {
        pintOneNameAge(strArray[count], *pointerofIntArray[count]);
        // *pointerofIntArray[count]:
        // Dereferences the pointer and gets the actual integer value(e.g., 62).
    }

    printf("\na second function: \n");

    for (count = 0; count < 4; count++) {
        pintOneNameAge2(strArray[count], pointerofIntArray[count]);
        // This is correct as long as you dereference inside the function.    
        // Dereferences the pointer and gets the actual integer value(e.g., 62).
    }

    printf("\na third function: \n");
    int age = 30;
    printAge(&age);

    return 0;
}

void pintAllNameAge(char** name, int** age, int size) {
    int count;
    for (count = 0; count < size; count++) {
        printf("Mr. %s is %d old\n", name[count], *age[count]);
        // *age[count]  // Dereferences the pointer to get the integer value
    }
}

// Takes pointers to arrays of names and ages and the number of elements.
// Iterates through the arrays and prints each name and age using printf().
// Uses* age[count] to dereference the pointer to get the integer value.
// Mutability:
// The char* version points to read - only string literals, which should not be modified.
// The char[][] version contains modifiable copies of the strings.

// void pintAllNameAge(char** name, int** age, int size)
// it uses double pointers because we are passing arrays of pointers as arguments to the function. 

void pintOneNameAge(char* name, int age) {
    printf("Mr. %s is %d old\n", name, age);
}

// char* name - A single string (or a pointer to the first character of the string).
// int age - A single integer (the actual age value)
// You pass the dereferenced value to avoid passing a pointer when it's not needed.

/*

Why Not Use Pointers for Age Here ?
You might think of declaring the function as :
void pintOneNameAge(char* name, int* age);

However:
You are not modifying the age inside the function.
Passing the actual value is more straightforward.
Dereferencing the pointer in the function would add unnecessary complexity.

*/

void pintOneNameAge2(char* name, int* age) {
    printf("Mr. %s is %d old\n", name, *age);
    // The* operator dereferences the pointer, giving the value stored at the address.
    printf("Mr. %s 's age pointer address is %p. \n", name, age);
}

void printAge(int* age) {
    printf("Age (pointer): %p\n", age);  // Print the address
    printf("Age (value): %d\n", *age);           // Print the value
}