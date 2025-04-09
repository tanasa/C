#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function Prototypes
void ReverseString(char* str);
int IsPalindrome(const char* str);
void ToUpperCase(char* str);
void ToLowerCase(char* str);
int CountVowels(const char* str);
void RemoveSpaces(char* str);

int main() {
    char str[100] = "Madam In Eden, I'm Adam";

    printf("Original String: %s\n", str);

    char copy[100];
    strcpy(copy, str);
    ReverseString(copy);
    printf("Reversed: %s\n", copy);

    printf("Is Palindrome: %s\n", IsPalindrome(str) ? "Yes" : "No");

    strcpy(copy, str);
    ToUpperCase(copy);
    printf("Uppercase: %s\n", copy);

    strcpy(copy, str);
    ToLowerCase(copy);
    printf("Lowercase: %s\n", copy);

    printf("Vowel Count: %d\n", CountVowels(str));

    strcpy(copy, str);
    RemoveSpaces(copy);
    printf("Without Spaces: %s\n", copy);

    return 0;
}

void ReverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int IsPalindrome(const char* str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        while (!isalnum(str[left]) && left < right) left++;
        while (!isalnum(str[right]) && left < right) right--;
        if (tolower(str[left]) != tolower(str[right])) return 0;
        left++;
        right--;
    }
    return 1;
}

void ToUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void ToLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int CountVowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

void RemoveSpaces(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}
