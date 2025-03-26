 #include <stdio.h>
 #include "utility.h"

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
