#include <stdio.h>

int main() {
    // Part 1: Age Check
    int yourAge;

    printf("How old are you?: ");

    // Ensure valid input
    int validInput = 0;
    while (validInput != 1) {
        if (scanf("%d", &yourAge) == 1) {
            validInput = 1;  // Exit loop
        }
        else {
            printf("Invalid input. Please re-enter your age: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    if (yourAge < 13)
        printf("You are a child.\n");
    else if (yourAge >= 13 && yourAge <= 19)
        printf("You are a teenager.\n");
    else
        printf("You are an adult.\n");

    // Part 2:

    char option;
    double firstN, secondN;
    char op;
 
    /*
    Let's keep in mind that scanf_s does not handle space - separated input correctly in some cases.
    The best fix is to replace scanf_s() with scanf(), which works correctly across all C compilers.
    */


    do {
   
        printf("Type a number, operator, number -- separated by a space: ");




        // Ensure valid input
        while (scanf("%lf %c %lf", &firstN, &op, &secondN) != 3) {
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
            // Modulo operation using integer conversion
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

        // Should the user want to perform another calculation
        printf("Would you like to perform another calculation? (y/n): ");
        while (getchar() != '\n');       // Clear input buffer
        option = getchar();

    } while (option == 'y' || option == 'Y');

    printf("Ciao Ciao!\n");

    // Part 3

    double max, a, b, c;

    char choice;

    do {
        // Input the numbers
        printf("Enter three numbers separated by spaces: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        // max between a and b
        max = (a > b) ? a : b;

        // compare max with c
        max = (max > c) ? max : c;

        // Print max
        printf("The Max is: %lf \n", max);

        // Input from the user
        printf("Would you like to find the max of another set of three numbers ? (y/n): ");
        while (getchar() != '\n');  // Clear input buffer

        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("La revedere !\n");

    return 0;
}
