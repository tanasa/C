#include <stdio.h>

// Function prototypes
void printBox1(int width, int height);
void printBox2(int width, int height);
void printBox3(int width, int height);
void printBox4(int height, int width, char vertical, char horizontal);

/**
 * Main function: Demonstrates various loop behaviors and box printing methods
 * @return 0 on successful execution
 */
int main() {
    // 4.1 Loop execution demonstrations

    // a) Demonstrating post-increment loop execution
    int i = 0;
    printf("\n");
    while (i++ < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 1: The loop executes 10 times.\n");

    // b) Demonstrating pre-increment loop execution
    printf("\n");
    i = 0;
    while (++i < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 2: The loop executes 9 times.\n");
    printf("\n++i means i is incremented first before checking the condition.\n");

    // c) Demonstrating loop execution without reinitialization
    printf("\n");
    while (++i < 10) {
        printf("Hello World: %d\n", i);
    }
    printf("\nPoint 3: The loop executes 0 times.\n");

    // 4.2 Box printing demonstrations

    // Printing a box using brute force
    printf("Using brutal force: \n");
    printf("--------------------\n");
    for (int j = 0; j < 8; j++) {
        printf("|      |\n");
    }
    printf("--------------------\n\n");

    // Printing boxes using different loop types
    printf("Using while () loop:\n");
    printBox1(5, 7);

    printf("Using do..while () loop:\n");
    printBox2(5, 7);

    printf("Using for () loop:\n");
    printBox3(5, 7);

    // 4.5 User-defined box with custom characters
    int height, width;
    char verticalC, horizontalC;
    char choice;

    do {
        // Get user input for box parameters
        printf("Enter box height: ");
        scanf_s("%d", &height);
        printf("Enter box width: ");
        scanf_s("%d", &width);
        printf("Enter vertical border character: ");
        scanf_s(" %c", &verticalC);
        printf("Enter horizontal border character: ");
        scanf_s(" %c", &horizontalC);

        // Draw the box with user-defined parameters
        printBox4(height, width, verticalC, horizontalC);

        // Ask if the user wants to draw another box
        printf("Do you want to draw another box? (y/n): ");
        scanf_s(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

/**
 * Prints a box using a while loop
 * @param width The width of the box
 * @param height The height of the box
 */
void printBox1(int width, int height) {
    int i = 0;

    // Print upper border
    while (i < width) {
        printf("-");
        i++;
    }
    printf("\n");

    // Print middle part
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

    // Print bottom border
    i = 0;
    while (i < width) {
        printf("-");
        i++;
    }
    printf("\n");
}

/**
 * Prints a box using a do-while loop
 * @param width The width of the box
 * @param height The height of the box
 */
void printBox2(int width, int height) {
    int i = 0;

    // Print top border
    do {
        printf("-");
        i++;
    } while (i < width);
    printf("\n");

    // Print middle part
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

    // Print bottom border
    i = 0;
    do {
        printf("-");
        i++;
    } while (i < width);
    printf("\n");
}

/**
 * Prints a box using a for loop
 * @param width The width of the box
 * @param height The height of the box
 */
void printBox3(int width, int height) {
    // Print top border
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");

    // Print middle part
    for (int j = 0; j < height - 2; j++) {
        printf("|");
        for (int k = 0; k < width - 2; k++) {
            printf(" ");
        }
        printf("|\n");
    }

    // Print bottom border
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

/**
 * Prints a box using user-defined characters
 * @param height The height of the box
 * @param width The width of the box
 * @param vertical The character for vertical borders
 * @param horizontal The character for horizontal borders
 */
void printBox4(int height, int width, char vertical, char horizontal) {
    // Print top border
    for (int i = 0; i < width; i++) {
        printf("%c", horizontal);
    }
    printf("\n");

    // Print middle part
    for (int i = 0; i < height; i++) {
        printf("%c", vertical);
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("%c\n", vertical);
    }

    // Print bottom border
    for (int i = 0; i < width; i++) {
        printf("%c", horizontal);
    }
    printf("\n");
}