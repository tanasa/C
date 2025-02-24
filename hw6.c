#include <stdio.h>
#include <stdlib.h>

// Function to get a valid menu choice from the user
int getMenuChoice() {
    int option;

    printf("Welcome to sorting program\n");
    printf("1. Title\n");
    printf("2. Rank\n");
    printf("3. Date\n");
    printf("4. Stars\n");
    printf("5. Likes\n");

    do {
        printf("\nEnter your choice between 1 and 5 only: ");

        // Get user input : a number
        if (scanf_s("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            option = 0; // Reset option to ensure loop continues
        }
        else if (option < 1 || option > 5) {
            printf("Choice out of range. Please enter a number between 1 and 5.\n");
        }
    } while (option < 1 || option > 5);

    return option;
}

// Function to get two valid float numbers from the user
void getTwoFloats(float* num1, float* num2) {
    int input_check;

    do {
        printf("\nPlease enter two float numbers separated by space: ");

        // Get user input as two float numbers
        input_check = scanf_s("%f %f", num1, num2);
        if (input_check != 2) {
            printf("Invalid input. Please enter two valid numbers.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    } while (input_check != 2);
}

int main() {
    // Call getMenuChoice function to get user's choice
    int userChoice = getMenuChoice();

    // Output the valid option
    printf("\nYou entered valid choice %d\n", userChoice);
    printf("Thank you for giving your choice\n");

    // Get two valid float numbers
    float num1, num2;
    getTwoFloats(&num1, &num2);

    // Print the float values
    printf("\nYou entered %.2f and %.2f successfully\n", num1, num2);

    return 0;
}
