/**
 * @file midterm.calculator.c
 * @brief A simple calculator program supporting addition, subtraction, multiplication, and division.
 * @author Bogdan Tanasa
 * @date 2025-02-23
 * @version 1.3
 */

#include <stdio.h>   // Standard Input/Output library for printf() and scanf()
#include <stdlib.h>  // Standard Library for general functions

 // --------------------------- FUNCTION DECLARATIONS ---------------------------

void displayMenu();
int getUserChoice();
double getUserNumber();
void performOperation(int choice, double num1, double num2);

// ---------------------------- FUNCTION DEFINITIONS ---------------------------

/**
 * @brief Displays the menu options for the calculator.
 */

void displayMenu() {
    printf("\n\n Welcome to Bogdan Tanasa's Handy Calculator : \n\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
}

/**
 * @brief Gets the user's choice from the menu, ensuring valid input.
 * @return The valid menu selection (integer between 1 and 5).
 */

int getUserChoice() {
    int choice;  // Variable to store user selection

    while (1) {  // Loop until a valid choice is entered
        printf("Make a selection (1-5): ");
        if (scanf_s("%d", &choice) == 1 && choice >= 1 && choice <= 5) {
            return choice;  // Return valid choice
        }
        else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');  // Clear input buffer to prevent infinite loops
        }
    }
}

/**
 * @brief Gets a valid numerical input from the user.
 * @return A valid double number entered by the user.
 */

double getUserNumber() {
    double num;  // Variable to store user input

    while (1) {  // Loop until a valid number is entered
        printf("Enter a number: ");
        if (scanf_s("%lf", &num) == 1) {
            return num;  // Return the valid number
        }
        else {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');  // Clear input buffer
        }
    }
}

/**
 * @brief Performs the selected arithmetic operation.
 * @param choice The user's selected operation (1: Add, 2: Subtract, 3: Multiply, 4: Divide).
 * @param num1 The first number.
 * @param num2 The second number.
 */

void performOperation(int choice, double num1, double num2) {
    switch (choice) {
    case 1:  // Addition
        printf("Result: %.2lf\n", num1 + num2);
        break;
    case 2:  // Subtraction
        printf("Result: %.2lf\n", num1 - num2);
        break;
    case 3:  // Multiplication
        printf("Result: %.2lf\n", num1 * num2);
        break;
    case 4:  // Division
        if (num2 == 0) {  // Prevent division by zero
            printf("Error: Cannot divide by zero.\n");
        }
        else {
            printf("Result: %.2lf\n", num1 / num2);
        }
        break;
    default:
        printf("Invalid operation.\n");  // Should never be reached
        break;
    }
}

// ---------------------------- MAIN FUNCTION ----------------------------------

/**
 * @brief Main function to control the calculator's execution.
 * @return Exit status of the program.
 */

int main() {
    int choice;        // Stores user's menu selection
    double num1, num2; // Stores numbers entered by the user

    while (1) {  // Loop until the user chooses to exit
        displayMenu();       // Show menu options
        choice = getUserChoice();  // Get user selection

        if (choice == 5) {  // Exit condition
            printf("\n\n Thank you for using Bogdan Tanasa's Handy Calculator! \n\n");
            printf("Goodbye!\n");
            break;  // Exit loop and terminate program
        }

        // Get two numbers from the user
        num1 = getUserNumber();
        num2 = getUserNumber();

        // Perform the selected operation
        performOperation(choice, num1, num2);
    }

    return 0;  // Indicate successful execution
}