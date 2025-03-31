#include <stdio.h>

int main() {
    float num1;
    float num2;
    char op;
    int c;

    // Prompt and read the first number
    printf("\nPlease enter Number1: ");
    scanf_s("%f", &num1);

    // Prompt and read the second number
    printf("\nPlease enter Number2: ");
    scanf_s("%f", &num2);

    // Clear the input buffer before reading a character
    while ((c = getchar()) != '\n' && c != EOF)
        continue;

    // Prompt and read the operator
    printf("\nPlease enter an Operator: ");
    scanf_s(" %c", &op, 1);  // Space before %c to ignore leftover newline

    // Display the inputs
    printf("\nYou entered Number1 = %.2f", num1);
    printf("\nYou entered Number2 = %.2f", num2);
    printf("\nYou entered Operator = %c", op);
    printf("\n\n");

    // puts() 
    // puts()	Prints a string followed by a newline
    // printf()	Prints formatted output(numbers, strings, etc.)
    // puts() always adds a newline(\n) after the string.
    // printf() does not automatically add a newline — you have to explicitly include \n if needed.

    // Print a greeting using puts()
    char greeting[] = "Hello, World!";
    puts(greeting);   // Prints the string with a newline

    // gets()
    // gets() is deprecated and removed from the C11 standard.
    // Modern compilers (like those in Visual Studio) do not support gets() anymore.

    /* 
    char name[50];
    printf("Enter your name: ");
    gets(name);  // Unsafe function
    printf("Hello, %s!\n", name);
     */

    // Wait for user to press enter to exit
    // printf("\n\nPress Enter to exit...");
    // system("pause");  // This ensures the program pauses at the end

    // Clear the input buffer again before using fgets()
    while ((c = getchar()) != '\n' && c != EOF)
        continue;

    // fgets()
    // It is safer than functions like gets() because 
    // it allows you to specify the maximum number of characters to read, 
    // thus preventing buffer overflow.
    // char *fgets(char *str, int n, FILE *stream);

    char name[50];

    // Prompt the user to enter their name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Remove the newline character if present
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);

    return 0;
}
