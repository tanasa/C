#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

        // part of lesson 1: C programming

        double pi = 3.14;
        printf("\nThe value of pi is: %.2f \n", pi);
        printf("\nSofia loves pie ? \n");
        printf("\nPie or pi ? \n");
        printf("\nCareful with your weight ! \n");

        /* 
        a test for scanf_s :

        In C, function arguments are passed by value (i.e., a copy is passed). 
        However, scanf_s() needs to modify the actual variable. 
        To achieve this, we pass the address of the variable using &.

        %f → Tells scanf_s() that we expect a float input.
        &weight → Provides the memory address where the input should be stored.

        */

        float weight;
        printf("\nPlease enter the input weight: "); 
        scanf_s("%f", &weight);
        printf("Weight is: %.2f\n", weight); 

        /*
        In C programming, there are three main ways to pass arguments to functions:

        Pass by Value (Default)
        Pass by Address (Pass by Pointer)
        Pass by Reference (Using Pointers or Structs in C)
        
        */

        /*
        1. Pass by Value (Default in C)
        In pass by value, a copy of the variable is passed to the function.

        Changes made inside the function do not affect the original variable.
        The function only works with a copy of the data.
        */

        /*
        2. Pass by Address (Pass by Pointer)
        In pass by address, a memory address (pointer) is passed to the function instead of the actual value.
        
        The function can directly modify the original variable.
        Used when modifying large data structures like arrays, structs, or linked lists.
        */
        
        /*
        * 3. Pass by Reference (Not Native in C, Simulated Using Pointers or Structs)
         C does not have "true" pass by reference like C++.
         We simulate pass by reference using pointers or structs.
         Changes made inside the function affect the original variable.
        */

        /*
        Pass by Reference in C++
        In C++, you can pass arguments to functions by reference, which allows direct modification of the original variable without using pointers. This is different from C, where "pass by reference" is simulated using pointers.

        1. How Pass by Reference Works
        Instead of passing a copy of the variable (pass by value), C++ allows passing a reference (&).
        Any changes made inside the function directly affect the original variable.
        */

        /*
        3. Why Use Pass by Reference?
        Advantages:

        Modifies the original variable (useful for returning multiple values).
        Avoids copying large objects, making it faster and memory-efficient.
        More readable than passing pointers.
        */

        /*
        In C++, there are three main types of parameter passing used in functions:
        
        1. Pass by Value
        A copy of the actual argument is passed to the function.
        Changes made inside the function do not affect the original variable.

        #include <iostream>
        void modifyValue(int x) {
        x = x + 10;  // Changes local copy, not the original variable
        }
        
        2️. Pass by Reference
        The function gets a reference to the original variable.
        Changes inside the function affect the original variable.

        #include <iostream>
        void modifyValue(int &x) {
        x = x + 10;  // Modifies original variable
        }

        3. Pass by Pointer
        The function gets the memory address of the variable.
        Changes inside the function affect the original variable.

        #include <iostream>
        void modifyValue(int *x) {
        *x = *x + 10;  // Dereferences and modifies original variable
        }

        */
        
        /*
        What is a Reference in "Pass by Reference" in C++?
        A reference (&) in C++ is an alias for an existing variable, meaning it does not create a copy 
        but rather provides another name for the same memory location.

        When a function "passes by reference", it takes the actual variable (not a copy), 
        so any modifications made inside the function directly affect the original variable.
        */
        
        /*
        A pointer : 
        A pointer in C is a variable that stores the memory address of another variable. 
        Instead of holding a direct value, it holds a reference to a memory location.
        */
        
        /*
        Difference Between Pointer and Reference in C++
        Both pointers (*) and references (&) are used to refer to variables indirectly, 
        but they behave quite differently. Here’s a detailed comparison:

        Syntax Difference :
        Pointer (*): Needs explicit dereferencing to access the value.
        Reference (&): Acts as an alias, no need for dereferencing.

        Memory Address & Dereferencing :
        Pointers store memory addresses and require dereferencing (*ptr) to access the actual value.
        References automatically access the value without extra syntax.

        Nullability :
        Pointers can be NULL, meaning they may not point to any valid variable.
        References cannot be NULL, they must always refer to an existing variable.

        Reassignment :
        Pointers can be reassigned to point to different memory locations.
        References cannot be changed once initialized.

        Use in Function Arguments :
        Pass by Pointer: Allows modifying variables but requires explicit dereferencing (*).
        Pass by Reference: Modifies variables directly.

        */
        
        return 0;

}



