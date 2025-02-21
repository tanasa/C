
// "All 128 ASCII characters including non-printable characters (represented by their abbreviation).
// The 95 ASCII graphic characters are numbered from 0x20 to 0x7E (32 to 126 decimal).
// The space character was initially considered to be a non - printing character.[1]"

// 65 (decimal) = 0x41 (hexadecimal)

// Strings : not a formal data type in C to store texts
// Array of type char[] is used for this purpose
// Each character occupies a byte in memory
// Special array '\0' (null: 0x00) as the last character

// each character occupies 8 byte in the memory

// strings = character arrays

// A char type is typically 1 byte
// You can assign integer type to it(0 to 255)
// Similarly, char values can be assigned to an int

// A = 65 (ASCII value of uppercase 'A')
// a = 97 (ASCII value of lowercase 'a')
// 32 (The difference between 'A' and 'a' in ASCII)
// This suggests a reference to the fact that the ASCII values of uppercase and lowercase letters 
// differ by 32 (i.e., 'a' = 'A' + 32).

#include <stdio.h>
#include <ctype.h>  // Include header for toupper()

void toUpper(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 97 && string[i] <= 122) {  // 'a' to 'z' in ASCII
            string[i] -= 32;                        // Convert to uppercase
        }
        i++;
    }
}

void toUpperStr(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = toupper(string[i]);      // Using toupper() from ctype.h
        i++;
    }
}

void toLower(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'A' && string[i] <= 'Z') {  // 'A' to 'Z' in ASCII
            string[i] += 32;                         // Convert to lowercase
        }
        i++;
    }
}

void toLowerStr(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = tolower(string[i]);      // Using tolower() from ctype.h
        i++;
    }
}


int main() {
    int i = 65;
    char ch = 'A';

    // Printing integer and character values
    printf("The value of integer i is: %d\n", i);
    printf("The value of character ch is: %c\n", ch);

    // Printing integer as a character
    printf("Printing Integer i as a character: %c\n", i);

    // Performing arithmetic on character values
    printf("Adding 32 to i converts to lowercase: %c\n", i + 32);

    // strings : the last chracter must be \0. (null character).
    char firstName[20];
    char lastName[30];
    char instructor[7] = { 'B', 'i', 'n', 'e', 'e', 't', '\0' };

    // Single Quotes versus Double Quotes : 
    // 'A' : character, 1 byte
    // "A" equals 'A', '\0', ie 2 bytes
    // we can not assign : char alphabet ="A"
    // we should do character

    // Using char instructor3[] = "Bineet"; is the best approach for simplicity.
    // String literals always include a null terminator('\0') automatically.
    // Manually defining character arrays requires explicitly adding '\0'.

    // When declaring a character array for a string in C, 
    // the array must be large enough to store all characters plus the null terminator('\0').
    
    char name1[6] = "Alice";  // Correct (5 characters + 1 for '\0')
    char name2[5] = "Alice";  // Incorrect (no space for '\0')
    
    printf("name1: %s\n", name1);
    printf("name2: %s\n", name2);

    char instructor1[7] = { 'B', 'i', 'n', 'e', 'e', 't', '\0' };
    char instructor2[7] = "Bineet";
    char instructor3[] = "Bineet";

    printf("The first instructor's Name is: %s\n", instructor1);
    printf("The second instructor's Name is: %s\n", instructor2);
    printf("The third instructor's Name is: %s\n", instructor3);

    char instructor5[20] = "Bineet";
    printf("a character: %c\n", instructor5[0]);
    printf("a character: %c\n", instructor5[5]);
    printf("a character: %c\n", instructor5[6]);

    printf("a character: %c\n", instructor5[14]);
    printf("a character: %c\n", instructor5[15]);
    printf("a character: %c\n", instructor5[20]);
    printf("a character: %c\n", instructor5[21]);
    printf("a character: %c\n", instructor5[22]);

    char instructor4[50];
    scanf_s("%s", instructor4); // we do not have & operator

    // converting the lower cases into upper cases

    char fname[40];
    // scanf_s("%39s", fname);  // Prevents buffer overflow
                                // Reads a string safely(leaving room for '\0'.

    // the name of the array 
    
    // is an address, we do not have to use &
    fgets(fname, sizeof(fname), stdin);  // Safer input method
    fname[strcspn(fname, "\n")] = '\0'; // Remove newline character

    printf("The original name is %s\n", fname);

    toUpper(fname); // Converts a given string to uppercase by modifying it in place.
    printf("The modified name is %s\n", fname);

    // 

    char alphabet;
    char alphabet1; 
    char alphabet2;

    alphabet = 'a';
    alphabet1 = toupper(alphabet);
    alphabet2 = tolower(alphabet);

    printf("The modified character is %c\n", alphabet1);
    printf("The modified character is %c\n", alphabet2);

    char str1[] = "hello world!";
    char str2[] = "hello world!";

    toUpper(str1);
    toUpperStr(str2);

    printf("Using ASCII conversion: %s\n", str1);
    printf("Using toupper(): %s\n", str2);

    toLower(str1);
    toLowerStr(str2);

    printf("Using ASCII conversion: %s\n", str1);
    printf("Using tolower(): %s\n", str2);

    printf("\n\n\n");

    if (isalpha(alphabet)) {  // Check if it's an alphabet
        printf("This is an alphabet.\n");
    }
    else {
        printf("This is not an alphabet.\n");
    }

    if (isdigit(100)) {      // Check if it's a digit
        printf("This is a digit.\n");
    }
    else {
        printf("This is not a digit.\n");
    }
     
     //        isalnum	Tests for alphanumeric character
     //        isalpha	Tests for alphabetic character
     //        isascii	Tests for ASCII character
     //        iscntrl	Tests for control character
     //        isdigit	Tests for digits(0 to 9)
     //        isgraph	Tests for printable character
     //        islower	Tests for lowercase character
     //        isprint	Tests for printable character
     //        ispunct	Tests for punctuation character
     //        isspace	Tests for space character
     //        isupper	Tests for uppercase character
     //        isxdigit	Tests for hexadecimal character
     //        toascii	Converts character to ASCII code
     //        tolower	Converts character to lowercase
     //        toupper	Converts character to uppercase

     /* String and Pointers
      
        Strings are special arrays(null - terminated at the end).
        Array name is the address, hence it acts as a pointer.
        A string may be assigned to a character array or to a character pointer.
     
        char instructur[7] = "Bineet";
        char* pinstructor = "Bineet";
      
      */
    

     printf("\n\n\n"); 

     // char instructor[7] = "Bineet";  // Modifiable array
     char *pinstructor = "Bimal";       // Pointer to string literal, it can be used as an ARRAY

     instructor[0] = 'D';               // ✅ Allowed: Modifying an array
     // pinstructor[0] = 'D';  ❌ Error: Undefined behavior (modifying a string literal)

     printf("Array String: %s\n", instructor);
     printf("Pointer String: %s\n", pinstructor);

     //    ✔ Use arrays(char instructur[]) when modification is needed.
     //    ✔ Use pointers(char* pinstructor) for read - only strings.
     //    ✔ String literals("Bineet") are stored in read - only memory.

     printf("The third character of instructor is: %c\n", instructor[2]);
     printf("The third character of pinstructor is: %c\n", *(pinstructor + 2)); 

     // pinstructor is a pointer to a string literal (char* pinstructor = "Bimal";).
     // Since strings in C are arrays of characters, pinstructor holds the base address of "Bimal".
     // Pointer arithmetic :
     // pinstructor + 2 → Moves 2 positions forward from the base address.
     // * (pinstructor + 2) → Dereferences the new address, giving the character at that position.

     printf("\nThe third character of instructor is: %c\n", *(instructor + 2));
     printf("The third character of pinstructor is: %c\n", pinstructor[2]);

     printf("Memory address of instructor array: %p\n", instructor);
     printf("Memory address of pinstructor (string literal): %p\n", pinstructor);

     pinstructor = instructor; // ✅ OK

     // pinstructor is a pointer(char*), so assigning it to instructor (which is an array) works 
     // because an array name is a pointer to its first element.
     // After this assignment, pinstructor now points to the same memory location as instructor
    
     // instructor = pinstructor; // ❌ NOT OK

     // instructor is a fixed - size array and cannot be assigned a new address.
     // Arrays in C do not support direct assignment (you cannot reassign an entire array).

     // String handling functions // to be continued

     return 0;  // Ensure main() returns an int
}
 