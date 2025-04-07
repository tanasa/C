// Advanced Pointers
// 
// A variable that holds the address of another variable is called a POINTER.
// The key point is that a pointer does not directly store the value itself but rather 
// the address where the value is located.

#include <stdio.h>

float getAverageTemp(int weeklyTemp[], int arraySize); 
float getAverageTempWithPointer(int* weeklyTemp, int arraySize);
void swapNumbers(int* N1, int* N2);

int main() {
    int myInt, yourInt;
    int* pmyInt;

    myInt = 5208;
    pmyInt = &myInt; // memory address of myInt

    yourInt = *pmyInt * 1.10;  // *pmyInt dereferences pmyInt

    printf("Value of myInt= %d\n", myInt);
    printf("Address of myInt= %p\n", &myInt);
    printf("Value stored in pmyInt= %p\n", pmyInt);
    
    printf("Address of pmyInt= %p\n", &pmyInt);
    printf("Value pointed to by pmyInt= %d\n", *pmyInt);

    printf("Value yourInt = %d\n", yourInt);

    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");

    // The NAME of an array is an ADDRESS.
    // We can declare an array and use it as a POINTER.
    // We can declare a POINTER and use it as an ARRAY.

    char instructor[7] = "Bineet"; // Stored in stack memory.
    char* pinstructor = "Bineet";  // It stores the pointer to a string literal in read-only memory.
    // Any attempt to modify the string through pinstructor might result in a segmentation fault.

    printf("Instructor Array: %s \n", instructor);
    printf("Instructor Pointer: %s \n\n", pinstructor);

    printf("The third character of instructor is: %c \n", instructor[2]);
    printf("The third character of pinstructor is: %c \n", *(pinstructor + 2));

    // These lines demonstrate that array indexing and pointer arithmetic are interchangeable :
    // ARRAY INDEXING == 
    // POINTER ARITHMETIC
    // instructor[2] is equivalent to *(instructor + 2).
    // pinstructor[2] is equivalent to *(pinstructor + 2).

    printf("\nThe third character of instructor is: %c \n", *(instructor + 2));
    printf("The third character of pinstructor is: %c \n", pinstructor[2]);

    // Although the storage differs, both access methods(array and pointer) work similarly when 
    // it comes to reading characters.

    // *pinstructor++ : de-referencing and post-increment
    // This expression can be broken down into two parts :
    // Dereference: *pinstructor - Access the value at the current pointer position.
    // Post - increment : pinstructor++ - Move the pointer to the next memory location after the current value has been accessed.
    
    // let's make sure
    while (*pinstructor) {
         printf("Printing one character at a time: %c \n", *pinstructor++);
    }

    // pre-increment
    // *++pinstructor:
    // Moves the pointer first and then dereferences the next element.
    // Use case: Skipping the first element or starting from the second element.

    char str[] = "Hello";
    char* p = str;

    printf("Using *(p++): %c\n", *(p++));  // Prints 'H' (then moves to 'e')
    printf("Using *++p: %c\n", *++p);      // Prints 'e' (moves to 'e' first)

    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");

    printf("\nThe memory location of instructor is: %p \n", instructor);
    // instructor (without &) itself is a pointer to the first element of the character array.
    printf("The memory location of pinstructor is: %p \n", pinstructor);

    // These represent different types
    // instructor is of type char* (pointer to the first element).
    // &instructor is of type char (*)[7] (pointer to the entire array).

    // Always cast to (void*) when using the %p format specifier to avoid compiler warnings.
    // printf("\nThe memory location of instructor is: %p \n", (void*)instructor);
    // printf("The memory location of pinstructor is: %p \n", (void*)pinstructor);

    // &instructor:
    // Represents the entire array as a single block of memory.

    // The pointer arithmetic differs :
    // If you increment instructor (as instructor + 1), it moves by 1 byte because it is a pointer to a char.
    // If you increment & instructor (as & instructor + 1), it moves by 7 bytes because it treats the entire array as one unit.

    printf("Address of the first element (instructor): %p\n", instructor);
    printf("Address of the entire array (&instructor): %p\n", &instructor);

    // Pointer arithmetic demonstration
    printf("instructor + 1 (next char): %p\n", instructor + 1);
    printf("&instructor + 1 (next array): %p\n", &instructor + 1);

    // Although both instructor and &instructor often print the same numeric memory address, 
    // they are different in how they are interpreted and used:
    // instructor points to the first byte of the array.
    // & instructor points to the entire array as one unit.
    
    int weeklyTemp[] = { 69, 70, 71, 68, 66, 71, 70 };

    printf("Passing pointers to a function :\n");
    printf("-----------------------------------------\n");

    printf("Average temperature of the week is %.2fF\n",
           getAverageTemp(weeklyTemp, 7));
    printf("Average temperature of the week is %.2fF\n",
           getAverageTempWithPointer(weeklyTemp, 7));

    printf("Passing pointers to a function :\n");
    printf("---- swapping numbers ----\n");

    int myNumber1, myNumber2;

    // Reading two numbers from the user
    scanf_s("%d", &myNumber1);
    scanf_s("%d", &myNumber2);

    // Printing the original numbers
    printf("Original Numbers are %d and %d\n", myNumber1, myNumber2);

    // Calling the swap function
    swapNumbers(&myNumber1, &myNumber2);

    // Printing the swapped numbers
    printf("Swapped Numbers are %d and %d\n", myNumber1, myNumber2);
    printf("\n\n");

    return 0;
}

float getAverageTemp(int weeklyTemp[], int arraySize) {
    int i;
    float total = 0, average;
    for (i = 0; i < arraySize; i++) {
        total += weeklyTemp[i];
    }
    average = total / arraySize;
    return average;
}

float getAverageTempWithPointer(int* weeklyTemp, int arraySize) {
    int i;
    float total = 0, average;
    for (i = 0; i < arraySize; i++) {
        total += *(weeklyTemp + i);
    }
    average = total / arraySize;
    return average;
}

// Function to swap two numbers using pointers
void swapNumbers(int* N1, int* N2) {
    int temp;
    temp = *N2;
    *N2 = *N1;
    *N1 = temp;
}

// 1. The Problem : Passing by Value
// In C, when you pass variables to a function, they are passed by value by default.This means that :
// The function receives a copy of the actual arguments.
// Any changes made to the parameters inside the function do not affect the original variables.

// 2. The Solution : Passing by Reference(Using Pointers)
// To actually swap the variables, we need to pass their addresses(pointers) to the function. 
// This allows the function to directly access and modify the original variables.

// 3. Analogy :
// Think of it as giving someone your home address vs.a photo of your house :
// If you give your address, they can come and rearrange your furniture(change the original).
// If you give a photo, they can only alter the photo, leaving the actual house untouched.

// In the same way :
// Passing variables directly to a function is like giving a copy (photo).
// Passing pointers (addresses) to a function is like giving the actual address, allowing real modifications.

// In Python : In Python, the way variables are passed to functions is often described as "pass by object reference" or "pass by assignment". 
// It’s neither strictly pass by value nor pass by reference, but rather something in between.

/*

Mutable Objects(like lists, dictionaries) :
They behave like pass by reference.

If you modify the object inside the function, the change persists outside the function.

Immutable Objects(like integers, strings, tuples) :
They behave like pass by value.
If you change the value, a new object is created, and the original remains unchanged.

Understanding Immutability :
When you pass an immutable object(like an integer) to a function, Python passes a reference to the object, 
not the object itself. However, because the object is immutable, any operation that changes its value 
will result in the creation of a new object rather than modifying the original.

def modify_number(num) :
    num = num + 1  # Creates a new object
    print(f"Inside function: num = {num}")

    my_number = 10
    modify_number(my_number)
    print(f"Outside function: my_number = {my_number}")
    
Inside function : num = 11
Outside function : my_number = 10
Why Doesn’t the Original Change ?

Initial Assignment :
my_number points to the integer 10.
num inside the function also initially points to the integer 10.

Inside the Function :
When num = num + 1 is executed :
Since integers are immutable, the operation num + 1 does not modify the original object.

Instead, a new integer object with value 11 is created.
The variable num now points to the new object 11.
The original my_number outside the function still points to 10.

No Connection After Reassignment :

The reassignment inside the function breaks the connection to the original variable.
The main program never knows that num was incremented because the original reference was not changed, 
only the local copy inside the function.

To make the main program aware that my_number should change, you have several options, given that integers in Python are immutable. Here are the most common approaches:

1. Use Return Statement:
The most straightforward way is to return the modified value and assign it back to the variable.

def modify_number(num):
    num = num + 1
    return num

my_number = 10
my_number = modify_number(my_number)
print(f"Updated my_number: {my_number}")  # Output: 11

Why it works:
The function returns the new object (11), and the main program explicitly updates my_number.

2. Use a Mutable Container (like a list or dictionary):
Instead of passing an integer, wrap it in a list or a dictionary, which are mutable.

def modify_number(num):
    num[0] = num[0] + 1

my_number = [10]  # Wrapping in a list
modify_number(my_number)
print(f"Updated my_number: {my_number[0]}")  # Output: 11

Why it works:
Lists are mutable, so changing the list inside the function directly affects the original list outside the function.

3. Use a Global Variable:
If you want to change a global variable, you can declare it as global inside the function.

my_number = 10

def modify_number():
    global my_number
    my_number = my_number + 1

modify_number()
print(f"Updated my_number: {my_number}")  # Output: 11
Why it works:

Declaring my_number as global tells Python to use the variable from the global scope.

4. Using an Object (Custom Class):
You can encapsulate the value inside a custom object.

class Number:
    def __init__(self, value):
        self.value = value

def modify_number(num):
    num.value += 1

my_number = Number(10)
modify_number(my_number)
print(f"Updated my_number: {my_number.value}")  # Output: 11

Why it works:
Objects are mutable, and changing an attribute inside the function will affect the original object.

A. Immutable Objects:
Cannot be changed after creation.

Any modification results in the creation of a new object.
Examples in Python:

Integers: x = 5 → x = x + 1 (creates a new integer object)
Strings: s = "hello" → s = s + " world" (creates a new string object)
Tuples: (1, 2, 3) → Any change creates a new tuple

2. Mutable Objects:
Can be changed after creation.

Modifying the object does not change its memory address.
Examples in Python:

Lists: [1, 2, 3] → You can add, remove, or change elements
Dictionaries: {'key': 'value'} → You can add or change key-value pairs
Sets: {1, 2, 3} → You can add or remove elements

my_list = [1, 2, 3]
print(id(my_list))  # Memory address of my_list

my_list.append(4)
print(id(my_list))  # Same memory address, list was modified in place

The ID stays the same because the existing list was modified

*/