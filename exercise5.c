#include <stdio.h>

int main() {
    
    int firstNumber;
    int secondNumber;

    printf("Please enter a number of your choice: ");
    scanf_s("%d", &firstNumber);

    printf("Please enter another number of your choice: ");
    scanf_s("%d", &secondNumber);

    if (firstNumber > secondNumber)
        printf("\n%d is bigger than %d. \n\n", firstNumber, secondNumber);
    else
        printf("\n%d is bigger than %d. \n\n", secondNumber, firstNumber);

    //

    int true;
    int false;

    true = (10 > 2);
    false = (10 == 2);

    printf("\n true = %d, \nfalse = %d\n", true, false);

    //

    int yourAge;

    printf("\nWhat is your age? ");
    scanf_s("%d", &yourAge);

    if (yourAge >= 13 && yourAge <= 19) {
        printf("You are a teenager\n");
    }
    else {
        printf("You are not a teenager\n");
    }

    return 0;
}