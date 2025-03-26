#include <stdio.h>
#include "utility.h"

int main()
{
    int minTemp, maxTemp;

    int weeklyTemp[] = {23, 12, 45, 90, 100, 67, 89};
    float average = getAverage(weeklyTemp, 7);

    getMinMax(weeklyTemp, 7, &minTemp, &maxTemp);

    printf("The min temperature is %d, and the max temperature is %d\n", minTemp, maxTemp);
    printf("The average temperature of this week is %.2f\n", average);

    return 0; 
}

// gcc main.file.c utility.c -o main.file
