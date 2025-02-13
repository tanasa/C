#include <stdio.h>
#define MAX_SIZE 100

// from previous class 13

/* 
void SwapValues(int*, int*);

int main() {
    int yourAge, myAge;

    printf("What is your age? ");
    scanf("%d", &yourAge);

    printf("What is my age? ");
    scanf("%d", &myAge);

    printf("\nOriginally, your age = %d and my age = %d", yourAge, myAge);

    SwapValues(&yourAge, &myAge);

    printf("\nYour age %d has been swapped with my age %d\n\n", yourAge, myAge);

    return 0;
}

void SwapValues(int* pN1, int* pN2) {
    int temp;
    temp = *pN1;
    *pN1 = *pN2;
    *pN2 = temp;
}

*/

// "In most expressions, the name of an array decays into a pointer to its first element."
// The name of the array is the address of the first element (Bineet Sharma). 

// Function to calculate average
float getAverage(int numberArray[], int arraySize)
{
    float sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += numberArray[i];
    }
    return sum / arraySize; // Return the average
}

void getMinMax(int wTemp[], int size, int* min, int* max)
{
    int count;
    for (count = 0; count < size; count++)
    {
        if (count == 0)
            *min = *max = wTemp[count];
        if (wTemp[count] > *max)
            *max = wTemp[count];
        if (wTemp[count] < *min)
            *min = wTemp[count];
    }
}


int main() {

    int weeklyTemp[7];

    weeklyTemp[0] = 69;
    weeklyTemp[1] = 70;
    weeklyTemp[2] = 71;
    weeklyTemp[3] = 68;
    weeklyTemp[4] = 66;
    weeklyTemp[5] = 71;
    weeklyTemp[6] = 70;

    int weeklyTemp2[7] = {69,70,71,68,66,71,70};

    int arr[] = { 10, 20, 30, 40, 50 };
    printf("Prints address of arr[0]: using arr :\n");
    printf("%p\n", arr);    // Prints address of arr[0]
    printf("Prints address of arr[0]: using &arr[0] :\n");
    printf("%p\n", &arr[0]); // Also prints address of arr[0]
    // Here, arr and &arr[0] give the same address, supporting the statement.
    // When an array name is used in an expression, it decays into a pointer to its first element.

    // do not : 
    // int weeklyTemp3[] = { 12, 23, 45, 67, 89, 90, 100 };
    // weeklyTemp3[7] = 112;

    int i;
    int min, max;

    int weeklyTemp3[MAX_SIZE];

    // If weeklyTemp3[] is an array of size 100 (MAX_SIZE), but you only enter 3 values, the rest contain garbage data.
    // The function getMinMax(weeklyTemp3, size3, &minTemp, &maxTemp); might be processing uninitialized elements.
    
    // 3 days :
    for (i = 0; i < 3; i++)
        {
            printf("Enter the temp: ");
            scanf_s("%d", &weeklyTemp3[i]);
        }

    printf("\n\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nThe temperature on day %d was %d ", i + 1, weeklyTemp3[i]);
    }

    // passing an array to a function
    
    int numbers[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // getting the average

    float average = getAverage(numbers, size);
    printf("\n\nThe average of an array is: %.2f\n", average);

    // getting the min and the max

    int minTemp, maxTemp;

    int size3 = sizeof(weeklyTemp3) / sizeof(weeklyTemp3[0]);
    // getMinMax(weeklyTemp3, size3, &minTemp, &maxTemp);
    // The array has 100 elements, however only 3 elements are actually filled.
    // This causes getMinMax() to read garbage values beyond the first 3 inputs.
    size3 = 3;
    // If we do not pass the value 3 of size 3, Why Are You Getting -858993460 as the Min Temperature?
    // The value - 858993460 is a garbage value, meaning the variable minTemp was not initialized properly 
    // before being used.
    getMinMax(weeklyTemp3, size3, &minTemp, &maxTemp);

    printf("The min temperature is %d, and the max temperature is %d\n", minTemp, maxTemp);

    printf("\n\n\n");
    return 0;

}

/*

Why We Do Not Use return in void getMinMax() Function?

The function getMinMax() has a return type of void, meaning it does not return a value. 
Instead, it modifies the values of min and max directly using pointers (int* min, int* max).

Key Concept: Passing by Reference (Using Pointers)

When we pass variables by reference (using pointers), we modify the actual values stored in the calling function, 
rather than returning values.

We modify the values in main() directly via memory addresses !

Since min and max are pointers, the function directly updates the values at the memory addresses of min and max.

Function Parameters Use Pointers (int* min, int* max)

The function takes memory addresses (&minTemp, &maxTemp) from main(), so it modifies the actual variables in main() rather than returning values.

If getMinMax() were to return the min and max values, we would need a different approach, like returning a struct or multiple values.

*/

/*

Alternative Approach Using return (Returning a Struct) 

If we wanted to return both values, we could use a struct:

#include <stdio.h>

// Define a struct to hold both min and max values
typedef struct {
    int min;
    int max;
} MinMax;

// Function that returns a struct instead of using pointers
MinMax getMinMax(int wTemp[], int size)
{
    MinMax result;
    result.min = result.max = wTemp[0];

    for (int count = 1; count < size; count++)
    {
        if (wTemp[count] > result.max)
            result.max = wTemp[count];

        if (wTemp[count] < result.min)
            result.min = wTemp[count];
    }

    return result; // Return struct containing min and max
}

int main()
{
    int weeklyTemp[] = {69, 70, 71, 68, 66, 71, 70};

    MinMax tempData = getMinMax(weeklyTemp, 7);

    printf("Minimum Temperature: %d\n", tempData.min);
    printf("Maximum Temperature: %d\n", tempData.max);

    return 0;
}

*/

/*

void getMinMax(int wTemp[], int size, int* min, int* max)   
     getMinMax(weeklyTemp3, size3, &minTemp, &maxTemp)

Understanding getMinMax() and How minTemp & maxTemp Get Updated :

The function getMinMax() does not return any value explicitly, yet it updates minTemp and maxTemp. 
This is possible due to pass-by-reference using pointers.

int* min → Pointer to store the minimum value	&minTemp (address of minTemp)
int* max → Pointer to store the maximum value	&maxTemp (address of maxTemp)

Step-by-Step Execution :

The function receives the address of minTemp and maxTemp

min points to minTemp
max points to maxTemp

Inside getMinMax()

*min = *max = wTemp[0];
This means minTemp = maxTemp = wTemp[0].

The loop iterates over the array and updates:

*min whenever a smaller value is found (updating minTemp).
*max whenever a larger value is found (updating maxTemp).

After function execution, minTemp and maxTemp are updated.

Because min and max are pointers, they modify minTemp and maxTemp directly in memory.

*/

/*

Memory Representation:

Before Calling getMinMax()

Address     Variable   Value
0x1000      minTemp    (uninitialized)
0x1004      maxTemp    (uninitialized)
0x2000      weeklyTemp3[] {69, 70, 71, 68, 66, 71, 70}

Function call:

getMinMax(weeklyTemp3, 7, &minTemp, &maxTemp);
min now stores 0x1000 (address of minTemp).
max now stores 0x1004 (address of maxTemp).

At the end of the function:

*min = 66 (which updates minTemp at 0x1000).
*max = 71 (which updates maxTemp at 0x1004).

Why getMinMax() Works Without return :

The function does not return a value explicitly.
Instead, it modifies minTemp and maxTemp directly by using pointers (*min and *max).
The memory address of minTemp and maxTemp is passed to getMinMax(), 
so the function can update the values at those addresses.

*/

/*

What is a Buffer Overflow?

A buffer overflow occurs when a program writes more data to a buffer (such as an array or memory allocation) 
than it was allocated, overwriting adjacent memory. 
This can cause unexpected behavior, crashes, and security vulnerabilities.

Safer in C: Use fgets()

fgets(name, sizeof(name), stdin);

Is Buffer Overflow Easier to Handle in C++ Compared to C?

Yes! C++ provides safer and more robust alternatives to raw memory handling, making it easier to prevent buffer overflow. 

While C relies on manual memory management and careful bounds checking, 
C++ offers higher-level abstractions like std::string and std::vector<int>, 
which automatically manage memory and prevent overruns.

*/