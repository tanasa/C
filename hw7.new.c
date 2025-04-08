#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * verifyOperator - checks if the input character is a valid arithmetic operator.
 * Params:
 *   operator (char) - the operator to check.
 * Returns:
 *   1 if valid, 0 otherwise.
 */

int isValidOperator(char operator) {
    return operator == '+' || operator == '-' || operator == '*' || operator == '/';
}

// Validates if a string is a properly formatted floating-point number
// Allows digits, one optional dot, and one optional leading minus sign

int verifyNumber(char* numberString) {
    
    int index; 
    char character;
    int length = strlen(numberString);
    
    // Check if the string is empty
    if (length == 0) return 0;
    

    // Loop through the string to validate characters
    for (index = 0; index < length; index++) {
        
        character = numberString[index];
        
        // for negative numbers, "-" is only valid at the start
        if (character == '-') { 
            if (index != 0) return 0; 
            continue;
        }

        // invalid character found
        if (!isdigit(numberString[index])) return 0; 
        
    }

    return 1; // All characters are valid
}



/*
 * calculate - Performs arithmetic operation based on operator.
 * Params:
 *   num1 (double) - first operand.
 *   num2 (double) - second operand.
 *   operator (char) - operator (+, -, *, /).
 * Returns:
 *   Result of the operation (double).
 *   Prints error if dividing by zero.
 */

double calculate(double num1, double num2, char operator) {
    
    switch (operator) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
        if (num2 == 0.0) {
            printf("Error: division by zero is not allowed.\n");
            return 0;
        }
        return num1 / num2;
    default:
        printf("Error: unknown operator.\n");
        return 0; 
    }
}


/*
 * parseInput - Parses a math expression in the format "number1 operator number2".
 * Params:
 *   input (char*) - user input string.
 *   num1 (double*) - output pointer for first number.
 *   num2 (double*) - output pointer for second number.
 *   operator (char*) - output pointer for operator.
 * Returns:
 *   1 if parsing succeeds, 0 otherwise.
 */

int parseInput(char* input, double* num1, double* num2, char* operator) {
    
    // Remove newline if present
    input[strcspn(input, "\n")] = '\0';

    // Parse using sscanf
    if (sscanf(input, "%lf %c %lf", num1, operator, num2) != 3) {
        return 0;
    }

    return 1;
}

/*
 * runCalculator - handles the input/output loop of the calculator.
 */

void runCalculator() {
    
    char userInput[100];
    double operand1, operand2;
    char operator;
    double result;

    printf("Welcome to Bogdan's Advanced Calculator! \n");
    printf("Enter operations in the format: number1 operator number2 (e.g., 7.5*2)\n");
    printf("Press Enter without input to quit.\n\n");

    while (1) {
        
        printf("Enter equation: ");
        fgets(userInput, sizeof(userInput), stdin);

        // Exit on empty input
        if (strlen(userInput) < 2) {
            printf("\n Thank you for using Bogdan's Calculator. Goodbye!\n");
            break;
        }

        // Parse input
        if (!parseInput(userInput, &operand1, &operand2, &operator)) {
            printf("Invalid format. Please use format like 10.0+3.5\n");
            continue;
        }

        // Validate operator
        if (!isValidOperator(operator)) {
            printf("Invalid operator. Please use only +, -, *, or /.\n");
            continue;
        }

        // Perform the calculation and show the result
        result = calculate(operand1, operand2, operator);
        if (!(operator == '/' && operand2 == 0.0)) {
            printf("Result: %.2f%c%.2f = %.2f\n\n", operand1, operator, operand2, result);
        }
    }
}

int main() {
    runCalculator();
    return 0;
}
