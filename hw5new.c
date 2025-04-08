/*
 * ========================================================================
 * PROGRAM: User Input & Weekly Temperature Analysis
 * AUTHOR:  [Your Name]
 * DATE:    [Current Date]
 * VERSION: 1.0
 * DESCRIPTION:
 *   This program performs the following tasks:
 *   1. Displays a menu and asks the user to select an option (1-5).
 *   2. Ensures valid input is received from the user.
 *   3. Prompts the user to enter two floating-point numbers and validates input.
 *   4. Analyzes weekly temperature data, calculating min, max, and average.
 *
 * COMPILATION: Compile using a C compiler such as GCC:
 *   gcc program.c -o program
 *
 * USAGE:
 *   Run the compiled executable and follow the prompts.
 *
 * ========================================================================
 */

#include <stdio.h>

 // Function prototypes
void displayMenu();
int getUserChoice();
void processUserChoice(int option);
void getFloatValues(float* numb1, float* numb2);
void analyzeWeeklyTemperatures();

/*
 * FUNCTION: main
 * DESCRIPTION:
 *   Entry point of the program. Calls functions for menu selection,
 *   float input validation, and weekly temperature analysis.
 * PARAMETERS:
 *   None
 * RETURNS:
 *   int - Returns 0 upon successful execution.
 */

int main() {
    // Display menu and process user selection
    displayMenu();
    int option = getUserChoice();
    processUserChoice(option);

    // Get two floating-point numbers from user
    float numb1, numb2;
    getFloatValues(&numb1, &numb2);
    printf("\nYou entered: %.2f and %.2f\n", numb1, numb2);

    // Analyze weekly temperatures
    analyzeWeeklyTemperatures();

    return 0;
}

/*
 * FUNCTION: displayMenu
 * DESCRIPTION:
 *   Displays a menu with options for the user to choose from.
 * PARAMETERS:
 *   None
 * RETURNS:
 *   void
 */

void displayMenu() {
    printf("========================================\n");
    printf("       WELCOME TO OUR PROGRAM          \n");
    printf("========================================\n");
    printf("1. Title\n");
    printf("2. Rank\n");
    printf("3. Date\n");
    printf("4. Stars\n");
    printf("5. Likes\n");
}

/*
 * FUNCTION: getUserChoice
 * DESCRIPTION:
 *   Prompts the user to enter a valid choice from the menu (1-5).
 *   Ensures input validation before returning.
 * PARAMETERS:
 *   None
 * RETURNS:
 *   int - The user's valid selection (1-5).
 */

int getUserChoice() {
    int option;

    do {
        printf("\nEnter your choice (1-5): ");

        // Validate user input
        if (scanf_s("%d", &option) != 1) {
            printf("ERROR: Invalid input! Please enter a number.\n");
            while (getchar() != '\n');  // Clear buffer
        }
        else if (option < 1 || option > 5) {
            printf("ERROR: Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (option < 1 || option > 5); // Repeat until valid input

    return option;
}

/*
 * FUNCTION: processUserChoice
 * DESCRIPTION:
 *   Displays a confirmation message for the user's valid choice.
 * PARAMETERS:
 *   int option - The valid menu option selected by the user.
 * RETURNS:
 *   void
 */

void processUserChoice(int option) {
    printf("\nYou entered a valid choice: %d\n", option);
    printf("Thank you for selecting an option!\n");
}

/*
 * FUNCTION: getFloatValues
 * DESCRIPTION:
 *   Prompts the user to enter two floating-point numbers and validates input.
 * PARAMETERS:
 *   float *numb1 - Pointer to store the first float number.
 *   float *numb2 - Pointer to store the second float number.
 * RETURNS:
 *   void
 */

void getFloatValues(float* numb1, float* numb2) {
    int input_check;

    do {
        printf("Enter two floating-point values separated by space: ");
        input_check = scanf_s("%f %f", numb1, numb2);

        // Check if two valid float values were entered
        if (input_check != 2) {
            printf("ERROR: Invalid input! Please enter two valid numbers.\n");
            while (getchar() != '\n'); // Clear buffer
        }
    } while (input_check != 2); // Repeat until valid input is received
}

/*
 * FUNCTION: analyzeWeeklyTemperatures
 * DESCRIPTION:
 *   Analyzes weekly temperature data:
 *   - Prints temperatures for each day.
 *   - Finds and prints minimum and maximum temperatures.
 *   - Computes and prints average temperature.
 * PARAMETERS:
 *   None
 * RETURNS:
 *   void
 */

void analyzeWeeklyTemperatures() {
    int weeklyTemp[] = { 69, 70, 71, 68, 66, 71, 70 };
    int min, max;
    float sum_temperature = 0;
    float average_temperature;
    int size = sizeof(weeklyTemp) / sizeof(weeklyTemp[0]); // Compute array size

    // Initialize min and max with the first element
    min = max = weeklyTemp[0];

    printf("\nWeekly Temperature Analysis\n");
    printf("===========================\n");

    // Iterate through the array to find min, max, and compute sum
    for (int i = 0; i < size; i++) {
        printf("Day %d: %d°F\n", i + 1, weeklyTemp[i]);

        // Update min and max values
        if (weeklyTemp[i] > max) {
            max = weeklyTemp[i];
        }
        if (weeklyTemp[i] < min) {
            min = weeklyTemp[i];
        }

        sum_temperature += weeklyTemp[i]; // Accumulate sum for average calculation
    }

    // Compute average temperature
    average_temperature = sum_temperature / size;

    // Display temperature statistics
    printf("\nSummary:\n");
    printf("Minimum Temperature: %d°F\n", min);
    printf("Maximum Temperature: %d°F\n", max);
    printf("Average Temperature: %.2f°F\n", average_temperature);
}

/*

Improvements in This Version :
✅ Full Documentation & Standard Header :

Author, Date, Version Number at the top.
Program Description including compilation instructions.
✅ Function Documentation with Parameters& Return Values :

Each function clearly states its purpose, parameters, and return value.
✅ Proper Modularization :

Separate functions for :
    Displaying the menu.
    Getting and validating user choice.
    Processing the choice.
    Getting and validating two float values.
    Analyzing weekly temperatures.
    ✅ Improved Readability& Naming Conventions :

Clear function names : displayMenu(), getUserChoice(), etc.
Descriptive variable names : sum_temperature, average_temperature.
✅ Proper Input Validation with Buffer Clearing :

Ensures no invalid input crashes the program.
Properly clears buffer when invalid input is detected.
✅ Better Output Formatting :

Added separators(========== = ) for better readability.
Structured output for menu, temperature analysis, and results.

*/