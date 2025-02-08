#include <stdio.h>

int main() {

    int count = 1;

    while (count < 5) {
        printf("%d ", count);
        count++;
    }

    printf("\nThe value of count after the loop: %d\n", count);

    int count2 = 1;

    while (count2 < 21) {
        printf("-");    // Prints dashes
        count2++;
    }

    printf("\n");

    // Print pattern using nested loops
    int count3 = 1;
    while (count3 < 11) {

        printf("|");

        int count = 1;
        while (count < 19) {
            printf(" ");
            count++;
        }

        printf("|\n");
        count3++;
    }

    int count4 = 1;

    while (count4 < 21) {
        printf("-");    // Prints dashes
        count4++;
    }

    printf("\n");

    int count5 = 1;
    do {
        printf("%d ", count5);
        count5++;
    } while (count5 < 5);

    printf("\n");

    // very IMPORTANT : do..while loop executes at least ONCE

    printf("\n");
    printf("do..while loop executes at least ONCE :\n");

    int count6 = 5;
    do {
        printf("%d ", count6);
        count6++;
    } while (count6 < 5);

    printf("\n");

    char response;
    do {
        printf("\n\nHello World\n");
        printf("\nContinue? Press 'n' to exit: ");
        response = getch();
    } while (response != 'n');

    printf("\n");

    return 0;
}
