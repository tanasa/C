#include <stdio.h>

int main() {

    float firstN, secondN;
    char op;
    int age, age2;

    // Prompt user for input
    printf("Type number, operator, number: ");
    scanf_s("%f %c %f", &firstN, &op, &secondN);  // Changed `scanf` to `scanf_s`

    // Using switch statement for operator cases
    switch (op) {
    case '+':
        printf("%.2f + %.2f = %.2f\n", firstN, secondN, firstN + secondN);
        break;

    case '-':
        printf("%.2f - %.2f = %.2f\n", firstN, secondN, firstN - secondN);
        break;

    case '*':
        printf("%.2f * %.2f = %.2f\n", firstN, secondN, firstN * secondN);
        break;

    case '/':
        if (secondN != 0)
            printf("%.2f / %.2f = %.2f\n", firstN, secondN, firstN / secondN);
        else
            printf("Error: Division by zero is not allowed.\n");
        break;

    case '%':  // % operator only works with integers
        if ((int)secondN != 0)
            printf("%d %% %d = %d\n", (int)firstN, (int)secondN, (int)firstN % (int)secondN);
        else
            printf("Error: Modulo by zero is not allowed.\n");
        break;

    default:
        printf("Error: Unknown operator '%c'.\n", op);
    }

    printf("Enter your age: ");
    scanf_s("%d", &age2);

    switch (age2) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            printf("The age %d is between 1 and 13.\n", age2);
            break;

        default:
            printf("The age %d is NOT between 1 and 13.\n", age2);
    }

    // Example of Conditional (Ternary) Operator Usage
    printf("Is first number positive? %s\n", (firstN > 0) ? "Yes" : "No");
    printf("Is second number positive? %s\n", (secondN > 0) ? "Yes" : "No");

    return 0;
}
