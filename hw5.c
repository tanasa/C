#include <stdio.h>

int main() {

    // 5.1

    int option;

    printf("Welcome to our program\n");
    printf("1. Title\n");
    printf("2. Rank\n");
    printf("3. Date\n");
    printf("4. Stars\n");
    printf("5. Likes\n");

    // execute until valid input is provided

    do {
    
        printf("\nEnter your choice (1-5): ");

        // Check valid numeric input 
        if (scanf_s("%d", &option) == 0) { 
            printf("Invalid input! Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');   
           // option = 0;
        }
        else if (option < 1 || option > 5) {
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (option < 1 || option > 5); 

    // Output the valid option
    printf("\nYou entered valid choice %d\n", option);
    printf("Thank you for giving your choice\n");

    // 5.2 

    float numb1, numb2;
    int input_check;

    do {
        
        printf("Enter two float values separated by space: ");

        input_check = scanf_s("%f %f", &numb1, &numb2);

        // Returns the number of successfully read values.
        // If the user enters two valid float numbers, scanf() returns 2.
        // If the input is invalid, clear buffer and ask again.
            
        if (input_check != 2) {
           printf("The input is invalid! Please enter two valid numbers.\n");
           // Clear input buffer
           while (getchar() != '\n');
         }

        } while (input_check != 2);  // Repeat until valid input is received

        // Display the float numbers
        printf("\nYou entered: %.2f and %.2f\n", numb1, numb2);


     // 5.3

        int weeklyTemp[] = { 69, 70, 71, 68, 66, 71, 70 }; 
        int i, min, max;
        float sum_temperature = 0; 
        // Since sum_temperature is used in an addition operation before assignment, 
        // it must be initialized to 0.0 to avoid garbage values affecting the sum.
        float average_temperature;
        // Why we don’t need to initialize average_temperature
        // average_temperature only gets a value after sum_temperature is fully computed.
        // It never participates in an operation before being assigned.

        int size = sizeof(weeklyTemp) / sizeof(weeklyTemp[0]); // Compute array size

        min = max = weeklyTemp[0];

        // Print daily temperatures, find min, max, and calculate total

        for (i = 0; i < size; i++) {
            printf("The temperature on day %d was %d\n", i + 1, weeklyTemp[i]);

            // Update min and max values
            if (weeklyTemp[i] > max) {
                max = weeklyTemp[i];
            }
            if (weeklyTemp[i] < min) {
                min = weeklyTemp[i];
            }

            // Add to total for calculating average
            sum_temperature += weeklyTemp[i];
        }

        // Calculate average temperature
        average_temperature = sum_temperature / size;

        // Print min, max, and average temperatures
        printf("\nMinimum temperature of the week: %d\n", min);
        printf("Maximum temperature of the week: %d\n", max);
        printf("Average temperature of the week: %.2f\n", average_temperature);

    return 0;
}