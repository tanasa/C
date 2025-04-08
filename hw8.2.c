#include <stdio.h>

void drawHorizontalLine(int width, char hChar);
void drawVerticalLine(int height, int width, char vChar);
void drawBox(int height, int width, char hChar, char vChar);

int main() {

    int height, width;
    char hChar, vChar;
    char userinput = 'y';

    while (userinput == 'y') {

        // Input box dimensions
        printf("\nEnter the height of the box (>1): ");
        scanf("%d", &height);
        while (getchar() != '\n'); // Clear the input buffer

        printf("Enter the width of the box (>1): ");
        scanf("%d", &width);
        while (getchar() != '\n'); // Clear the input buffer

        // Input characters for the box
        printf("Enter the vertical character for the box: ");
        scanf(" %c", &vChar); // Space before %c to consume newline
        while (getchar() != '\n'); // Clear the input buffer

        printf("Enter the horizontal character for the box: ");
        scanf(" %c", &hChar); // Space before %c to consume newline
        while (getchar() != '\n'); // Clear the input buffer

        // Draw the box
        drawBox(height, width, hChar, vChar);

        // Prompt user to continue
        printf("\nDo you want to draw another box? Type 'y' to continue: ");
        scanf(" %c", &userinput);
    }

    printf("\nThank you for using the box drawing program!\n");
    return 0;
}

// Function to draw a horizontal line
void drawHorizontalLine(int width, char hChar) {
    for (int i = 0; i < width; i++) {
        printf("%c", hChar);
    }
    printf("\n");
}

// Function to draw vertical lines
void drawVerticalLine(int height, int width, char vChar) {
    for (int i = 0; i < height - 2; i++) {
        printf("%c", vChar);   // Left vertical character
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("%c\n", vChar); // Right vertical character
    }
}

// Function to draw a box
void drawBox(int height, int width, char hChar, char vChar) {
    drawHorizontalLine(width, hChar);           // Top line
    if (height > 1) {
        drawVerticalLine(height, width, vChar); // Sides
        drawHorizontalLine(width, hChar);       // Bottom line
    }
}
