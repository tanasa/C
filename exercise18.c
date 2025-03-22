// spaghetti code

// procedural programming : 
// structured programming is a sub category of procedural programming

// SEQUENCE
// SELECTION
// REPETITION

// JUMP STATEMENTS 
// goto
// continue 
// break

// for (i = 0; i < 10; i++)
// {
//    ...
//        if ()
//            continue; // it brings the execution to the begining of the loop
//
//    if ()
//        break;
//    ...
// }

// it defines an array of strings (i.e., an array of character pointers) with 3 student names. 
// 
// Let me know if you’d like to manipulate or display them in a loop!

// It declares an array of 3 pointers to char, meaning:
// students[0] points to the first character of the string "Binet"
// students[1] points to the first character of "Elizabeth"
// students[2] points to "George"

// Each entry in the students array is a pointer to the first character of 
// each of those string literals.

// We could also store all strings in a contiguous 2D array : 
// char students[3][10] = { "Binet", "Elizabeth", "George" };
// But that has a downside :
// You must predefine a fixed length(e.g., [10]) for each string.
// If a name is longer than 9 characters(1 reserved for \0), it will be truncated.
// Using char* students[3] allows variable - length strings because each string is independently stored

// C Doesn’t Have a Native String Type
// Unlike languages like Python or Java, C doesn't have a built-in string type. In C:
// A string is just an array of characters terminated by a null character('\0).
// So when you write :
// char* str = "Hello";

// What’s really happening is :
// "Hello" is stored as : ['H', 'e', 'l', 'l', 'o', '\0']
// str is a pointer to the first character — 'H'
// That’s why str is of type char*, i.e., character pointer.

// A "string" in C = pointer to char : POINTER to CHAR
// char* students[3] = { "Binet", "Elizabeth", "George" };
// Each element like "Binet" is a string literal, but what C stores is a pointer to its first character — 
// which means :

// "Binet" → pointer to 'B' → char*
// So students[0] is of type char*

// Why Not string* ?
// Because C doesn’t define string as a type. 
// It's not like C++ (which has std::string) or Python (where str is a class).

// In C :
// "Strings" are just arrays of characters(char[])
// So the pointer to a string is a char*, not a string*


// Summary :
// String literal : char* Pointer to first char of null - terminated char array
// Array of strings	char* [N] : Each element is a pointer to a char(i.e., a string)
// No string type	:	C doesn't define a string type natively.

// int strcmp(const char *str1, const char *str2);
// strcmp is a function in C from the string.h library that compares two strings lexicographically (i.e., like in a dictionary).

#include <stdio.h>
#include <string.h>

#define SIZE 5

int main() {
    // Initial student list
    char* students[3] = {
        "Biinee",
        "Elizabeth",
        "George"
    };

    // Print the initial students
    for (int i = 0; i < 3; i++) {
        printf("Student %d: %s\n", i + 1, students[i]);
    }

    // Compare two names
    char* name1 = "Alice";
    char* name2 = "Bob";

    int result = strcmp(name1, name2);

    if (result == 0) {
        printf("The names are equal.\n");
    }
    else if (result < 0) {
        printf("%s comes before %s\n", name1, name2);
    }
    else {
        printf("%s comes after %s\n", name1, name2);
    }

    // Student name lookup
    char* studentList[SIZE] = { "Elisabeth", "George", "John", "Natasha", "Rodriguez" };
    char whichName[21];  // 20 characters + null terminator
    int found_it = 0;

    printf("Please enter your name (20 chars or less): ");
    fgets(whichName, sizeof(whichName), stdin);

    whichName[strcspn(whichName, "\n")] = '\0'; // remove newline

    for (int i = 0; i < SIZE; i++) {
        int cmp = strcmp(studentList[i], whichName);

        if (cmp == 0) {
            found_it = 1;
            break;
        }
        else if (cmp > 0) {
            break;  // Name not found, and list is sorted
        }
    }

    if (found_it) {
        printf("Welcome, %s!\n", whichName);
    }
    else {
        printf("Name not found.\n");
    }

    return 0;
}
