#include <stdio.h>

void printBox1(int width, int height);
void printBox2(int width, int height);
void printBox3(int width, int height);
void printBox4(int height, int width, char vertical, char horizontal);

int main() {
    // 4.1

    // a) How many times this loop is executed?
    int i = 0;
    printf("\n");
    while (i++ < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 1: The loop executes 10 times.\n");

    // b) How many times this loop is executed if we changed the counter increment to ++i?
    printf("\n");
    i = 0;
    while (++i < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 2: The loop executes 9 times.\n");
    printf("\n++i means i is incremented first before checking the condition.\n");

    // c) How many times this loop is executed, if it is executed immediately after the loop in #b,
    // i.e. i is not reinitialized before the loop?
    printf("\n");
    while (++i < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 3: The loop executes 0 times.\n");

    // 4.2 - Printing a box using brute force
    printf("Using brutal force: \n");
    printf("--------------------\n");
    for (int j = 0; j < 8; j++) {
        printf("|      |\n");
    }
    printf("--------------------\n\n");

    // 4.2 - Printing box using different loops
    printf("Using while () loop:\n");
    printBox1(5, 7);

    printf("Using do..while () loop:\n");
    printBox2(5, 7);

    printf("Using for () loop:\n");
    printBox3(5, 7);

    // 4.5 - User-defined box with characters
    int height, width;
    char verticalC, horizontalC;
    char choice;

    do {
        // Enter the height, width, and characters
        printf("Enter box height: ");
        scanf("%d", &height);
        printf("Enter box width: ");
        scanf("%d", &width);
        printf("Enter vertical border character: ");
        scanf(" %c", &verticalC);
        printf("Enter horizontal border character: ");
        scanf(" %c", &horizontalC);

        // Draw the box with these parameters
        printBox4(height, width, verticalC, horizontalC);

        // Ask the user if they want to continue
        printf("Do you want to draw another box? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to print a box using a while loop
void printBox1(int width, int height) {
    int i = 0;

    // Upper border
    while (i < width) {
        printf("-");
        i++;
    }
    printf("\n");

    // Middle part
    int j = 0;
    while (j < height - 2) {
        printf("|");
        int k = 0;
        while (k < width - 2) {
            printf(" ");
            k++;
        }
        printf("|\n");
        j++;
    }

    // Bottom border
    i = 0;
    while (i < width) {
        printf("-");
        i++;
    }
    printf("\n");
}

// Function to print a box using a do-while loop
void printBox2(int width, int height) {
    int i = 0;

    // Top border
    do {
        printf("-");
        i++;
    } while (i < width);
    printf("\n");

    // Middle part
    int j = 0;
    do {
        printf("|");
        int k = 0;
        do {
            if (width > 2) {
                printf(" ");
            }
            k++;
        } while (k < width - 2);
        printf("|\n");
        j++;
    } while (j < height - 2);

    // Bottom border
    i = 0;
    do {
        printf("-");
        i++;
    } while (i < width);
    printf("\n");
}

// Function to print a box using a for loop
void printBox3(int width, int height) {
    // Top border
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    // Middle part
    for (int j = 0; j < height - 2; j++) {
        printf("|");
        for (int k = 0; k < width - 2; k++) {
            printf(" ");
        }
        printf("|\n");
    }

    // Bottom border
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to print a box using user-defined characters
void printBox4(int height, int width, char vertical, char horizontal) {
    // Top border
    for (int i = 0; i < width; i++) {
        printf("%c", horizontal);
    }
    printf("\n");

    // Middle part
    for (int i = 0; i < height; i++) {
        printf("%c", vertical);
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("%c\n", vertical);
    }

    // Bottom border
    for (int i = 0; i < width; i++) {
        printf("%c", horizontal);
    }
    printf("\n");
}
