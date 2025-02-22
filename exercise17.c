// Multidimensional arrays

#include <stdio.h>

// int weeklyTemp[52][7];
// 52 rows : indexes from 0 to 51 (weeks)
// 7 columns : indexes from 0 to 6 (days)

// Initialize :

/* 
First Declaration(Explicit Size Specification)

int weeklyTemp[52][7] = {
    {69, 70, 71, 68, 66, 71, 70},
    {68, 72, 73, 68, 63, 77, 71},
    {65, 76, 72, 69, 66, 72, 74},
    ...
};

Second Declaration(Implicit Size Determination)

int weeklyTemp[][7] = {
    {69, 70, 71, 68, 66, 71, 70},
    {68, 72, 73, 68, 63, 77, 71},
    {65, 76, 72, 69, 66, 72, 74},
    ...
};
*/

// Nested for loops for initialziation

// int weeklyTemp[52][7];
// int i, j;      // FIX: Missing comma between 'i' and 'j'

// for (i = 0; i < 52; i++)
//    for (j = 0; j < 7; j++)     // FIX: Incorrect condition (should be j < 7)
//        weeklyTemp[i][j] = 0;   // Initialize all elements to 0

// Initialization :

// int weeklyTemp[52][7] = { 0 };

// int weeklyTemp[52][7];

// weeklyTemp[0][0] = 69;
// weeklyTemp[0][1] = 70;
// .. 
// weeklyTemp[0][6] = 69;
// weeklyTemp[1][0] = 70;
// weeklyTemp[1][1] = 70;

/* Function definition */
// float getYearlyAverage(int wt[][], int row, int col)

float getWeeklyAverage(int WT[52][7], int row, int col, int week) {
    int day;
    float total = 0.0, average;

    // Loop through the days of the given week to sum up temperatures
    for (day = 0; day < col; day++)
        total += WT[week][day];

    // Compute the weekly average temperature
    average = total / col;
    return average;

}

float getWeeklyAverageWithPointers(int WT[52][7], int row, int col, int week) {
    int day;
    int* pWT = (int*)WT;  // Pointer to the 2D array
    float total = 0.0, average;

    for (day = 0; day < col; day++) {
        // Accessing elements using pointer arithmetic instead of array indexing
        total += *(pWT + (week * col) + day);
    }

    // Compute the weekly average temperature
    average = total / col;
    return average;
}

int main() {
    int row, col;
    int annualTemp[52][7] = { 0 };  // Initialize all elements to 0

    for (row = 0; row < 52; row++) {
        for (col = 0; col < 7; col++) {
            printf("Week %d, Day %d = %d\n",
                row + 1,  // Week number (1-based index)
                col,      // Day number (0-based index)
                annualTemp[row][col]);  // Temperature value
        }
    }

    int weeklyTemp[3][7] = {
    {69, 70, 71, 68, 66, 71, 70},
    {68, 72, 73, 68, 63, 77, 71},
    {65, 76, 72, 69, 66, 72, 74} 
    };

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 7; col++) {
            printf("Week %d, Day %d = %d\n",
                row + 1,      // Week number (0-based index)
                col + 1 ,      // Day number (1-based index)
                weeklyTemp[row][col]);  // Temperature value
        }
    }

    printf("print a chosen value : Week 3, Day 3 = %d\n\n",
           weeklyTemp[2][2]);   // Temperature value


    int smallArray[2][2];       // Declare a 2x2 array
    int i, j;                   // Loop variables

    // Loop to read values into the array
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf_s("%d", &smallArray[i][j]);  // Read input into the array ; 
            // scanf_s() needs the memory address of the variable where it should store the user input.
        }
    }

    char instructor[7] = "Bineet";  // Character array
    char *pinstructor = "Bimali";   // Pointer to a string literal

    // Correctly accessing the third character (index 2) using POINTER notation
    printf("The third character of instructor is: %c\n", *(instructor + 2));
    printf("The third character of pinstructor is: %c\n", *(pinstructor + 2));

    // Alternative way using ARRAY notation
    printf("The third character of instructor is: %c\n", instructor[2]);
    printf("The third character of pinstructor is: %c\n", pinstructor[2]);

    // 2D ARRAY

    // Define a 2D array to store annual temperature data for 3 sample weeks
    int annualTemp2[52][7] = {
        {69, 70, 71, 68, 66, 71, 70},  // Week 1
        {60, 71, 73, 66, 60, 72, 76},  // Week 2
        {67, 72, 71, 68, 62, 71, 73}   // Week 3
    };

    // Get the weekly average of week #2 (index 1)
    printf("\n\ncompute with arrays : The average temperature of week %d = %.1f\n", 2,
            getWeeklyAverage(annualTemp2, 52, 7, 1));
    
    printf("\ncompute with pointers : The average temperature of week %d = %.1f\n\n", 2,
        getWeeklyAverageWithPointers(annualTemp2, 52, 7, 1));


    return 0;
}

// question bout the use of pointers :
// float getWeeklyAverage(int WT[52][7], int *row, int *col, int *week)

// In the function signature, row, col, and week are passed as pointers(int*), 
// which suggests that the function is meant to modify their values.
// However, for a function that computes a weekly average, modifying these values doesn't seem necessary.
// If the function only needs to read the week index, 
// passing week as an integer(int week) instead of a pointer(int* week) would be cleaner.

// The implementation is straightforward and avoids unnecessary pointer dereferencing.