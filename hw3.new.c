#include <stdio.h>
#include <stdbool.h>

#define CHILD_MAX_AGE 12
#define TEEN_MIN_AGE 13
#define TEEN_MAX_AGE 19

void checkAge();
void calculator();
void findMax();

int main() {
    checkAge();
    calculator();
    findMax();
    return 0;
}

void checkAge() {
    int yourAge;
    printf("How old are you?: ");
    while (scanf_s("%d", &yourAge) != 1) {
        printf("Invalid input. Please re-enter your age: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    if (yourAge <= CHILD_MAX_AGE)
        printf("You are a child.\n");
    else if (yourAge >= TEEN_MIN_AGE && yourAge <= TEEN_MAX_AGE)
        printf("You are a teenager.\n");
    else
        printf("You are an adult.\n");
}

void calculator() {
    char option;
    double firstN, secondN;
    char op;

    do {
        printf("Type a number, operator, number -- separated by a space: ");
        while (scanf_s("%lf %c %lf", &firstN, &op, &secondN) != 3) {
            printf("Invalid input. Please enter in format: number operator number: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        switch (op) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", firstN, secondN, firstN + secondN);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", firstN, secondN, firstN - secondN);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", firstN, secondN, firstN * secondN);
            break;
        case '/':
            if (secondN != 0)
                printf("%.2lf / %.2lf = %.2lf\n", firstN, secondN, firstN / secondN);
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        case '%':
            if (secondN != 0) {
                int intFirst = (int)firstN;
                int intSecond = (int)secondN;
                printf("%d %% %d = %d\n", intFirst, intSecond, intFirst % intSecond);
            }
            else {
                printf("Error: Modulo by zero is not allowed.\n");
            }
            break;
        default:
            printf("Unknown operator.\n");
            break;
        }

        printf("Would you like to perform another calculation? (y/n): ");
        while (getchar() != '\n');
        option = getchar();

    } while (option == 'y' || option == 'Y');

    printf("Ciao Ciao!\n");
}

void findMax() {
    double max, a, b, c;
    char choice;

    do {
        printf("Enter three numbers separated by spaces: ");
        scanf_s("%lf %lf %lf", &a, &b, &c);

        max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

        printf("The Max is: %lf \n", max);

        printf("Would you like to find the max of another set of three numbers? (y/n): ");
        while (getchar() != '\n');
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("La revedere !\n");
}

/*
Here are some comments and suggestions for improvement:

Code Structure:
The code is divided into three main parts. Consider separating these into functions for better readability and maintainability.

Input Validation:
Good use of input validation loops. This helps prevent crashes due to invalid input.

Error Handling:
Proper handling of division and modulo by zero. Good practice!

Consistency:
The code uses both "scanf" and "scanf_s". Stick to "scanf" for consistency across all C compilers.

Magic Numbers:
Consider using constants for age ranges (e.g., #define TEEN_MIN_AGE 13).

*/