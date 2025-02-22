#define _CRT_SECURE_NO_WARNINGS

#include <string.h>  // Required for string handling functions
#include <stdio.h>   // Required for printf()

// Copy Functions
// strcpy, strncpy, strcat
// Comparison Functions
// strcmp, strncmp
// Search Functions
// strstr, strchr, strtok
// Other Functions
// strlen, strerror

int main() {

    char str1[30];  // Corrected type from 'str' to 'char'
    char str2[] = "Hello 5208 class";

    strcpy(str1, str2);  // Copy str2 into str1

    printf("Copied String: %s\n", str1);  // Output: Hello 5208 class

    // char* strcpy(char* str1, const char* str2);
    // Copies the string str2 into the array str1.
    // str1 must have enough space to store str2 plus the null terminator('\0').

    // char* strncpy(char* str1, const char* str2, size_t n);
    // Copies at most n characters of str2 into str1.
    // If str2 is shorter than n, the remaining part of str1 is filled with '\0'.

    // Copy only the first 20 characters of str1 into str2

    strncpy(str1, str2, 10);
    str1[10] = '\0';  // Ensure null termination

    printf("Use strncpy\n");
    printf("This is only 10 characters of second string: %s\n", str1);

        // strcat	Appends a string to another string.
        // strchr	Finds the first occurrence of a given character in a string.
        // strcmp	Compares two strings.
        // strcasecmp	Compares two strings, case-insensitive.
        // strcpy	Copies one string to another.
        // strlen	Finds the length of a string.
        // strlwr	Converts a string to lowercase.
        // strncat	Appends n characters of a string to another string.
        // strncmp	Compares n characters of two strings.
        // strncpy	Copies n characters of one string to another.
        // strrchr	Finds the last occurrence of a given character in a string.
        // strrev	Reverses a string.
        // strset	Sets all characters of a string to a given character.
        // strspn	Finds the first substring from a given character set in a string.
        // strupr	Converts a string to uppercase.

    char instructor[7] = "Bineet";     // Character array
    char *pinstructorp = "Srini";      // Pointer to string literal

    pinstructorp = instructor;         // Assign instructor array to pinstructor pointer

    printf("The third character array: %c\n", instructor[2]);
    printf("The first character pointer: %c\n", *(pinstructorp));
    printf("The second character pointer after increment: %c\n", *(++pinstructorp));

    pinstructorp = instructor;         // Assign instructor array to pinstructor pointer
    // to print the characters in the string 

    printf("The characters in the string :\n");

    while (*pinstructorp) {             // Loop until null terminator '\0' is reached
        printf("%c\n", *pinstructorp);  // Print character-by-character
        pinstructorp++;                 // Move to the next character
    }

    return 0;
}

