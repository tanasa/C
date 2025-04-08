/*
 * ========================================================================
 * PROGRAM: User Input
 * AUTHOR:  Bogdan Tanasa
 * DATE:    4/8/2025
 * VERSION: 1.1
 * DESCRIPTION:
 *   This program:
 *   1. Displays a menu and prompts the user for a valid choice (1-5).
 *   2. Asks the user for two float inputs and validates them.
 *
 * COMPILATION:
 *   gcc program.c -o program
 * ========================================================================
 */

#include <stdio.h>

 // Function Prototypes
void displayMenu();
int readMenu();
void processOption(int option);
void readTwoFloats(float* num1, float* num2);

/*
 * FUNCTION: main
 * ----------------------
 * Entry point of the program.
 */
int main() {
    // Display menu and get user's choice
    displayMenu();
    int option = readMenu();
    processOption(option);

    // Prompt user for two float values
    float float1, float2;
    readTwoFloats(&float1, &float2);
    printf("\nYou entered: %.2f and %.2f\n", float1, float2);

    return 0;
}

/*
 * FUNCTION: displayMenu
 * ---------------------
 * Prints the sorting options menu.
 */
void displayMenu() {
    printf("\n=====================================\n");
    printf("               MENU                  \n");
    printf("=====================================\n");
    printf("1. Title\n");
    printf("2. Rank\n");
    printf("3. Date\n");
    printf("4. Stars\n");
    printf("5. Likes\n");
}

/*
 * FUNCTION: readMenu
 * -------------------
 * Prompts the user for a valid menu option.
 * RETURNS:
 *   int - Valid user menu choice.
 */
int readMenu() {
    int option;

    while (1) { // Loop until a valid option is entered
        printf("\nEnter your choice (1-5): ");
        if (scanf_s("%d", &option) != 1) {
            printf("ERROR: Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
        }
        else if (option >= 1 && option <= 5) {
            break; // Valid input, exit the loop
        }
        else {
            printf("ERROR: You entered an invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return option;
}

/*
 * FUNCTION: processOption
 * -----------------------
 * Acknowledges the user's valid choice.
 */
void processOption(int option) {
    printf("\nYou selected option %d. Thank you!\n", option);
}

/*
 * FUNCTION: readTwoFloats
 * ----------------------
 * Prompts user for two float numbers and validates input.
 */
void readTwoFloats(float* num1, float* num2) {
    int result = 0; // Initialize result to an invalid state

    while (result != 2) { // Loop until two valid floats are entered
        printf("\nEnter two float numbers separated by space: ");
        result = scanf_s("%f %f", num1, num2);

        if (result != 2) {
            printf("ERROR: Please enter two valid float numbers.\n");
            while (getchar() != '\n'); // Clear buffer
        }
    }
}
