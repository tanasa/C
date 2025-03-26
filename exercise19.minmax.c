#include <stdio.h>

void SwapValues(int *pN1, int *pN2)
{
    int temp;
    temp = *pN1;
    *pN1 = *pN2;
    *pN2 = temp;
}


float getAverage(int vTemp[], int size)
{
    float average, total=0.0;
    int i;

    for (i=0; i < size; i++)
        total += vTemp[i];

    return total/size;
}

void getMinMax(int vTemp[], int size, int *min, int *max)
{
    int count;
    for (count=0; count < size; count++)
    {
        if (count == 0)
        {
            *min = *max = vTemp[count];
        }
        if (vTemp[count] < *min)
            *min = vTemp[count];
        if (vTemp[count] > *max)
            *max = vTemp[count];
    }
}

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
