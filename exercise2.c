#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    printf("Hello, C in Visual Studio!\n");
    
    float num = 9999.99;
    int a = 6;

    printf("\n"
            "%f \n"
            "%.1f \n"      // why does it print 1000 ?
            "%.2f \n"
            "%.3f \n"
            "%.4f \n",
            num, num, num, num, num);

    printf("\n"
        "%1d \n"
        "%2d \n"
        "%1f \n"
        "%2f \n"
        "%9.2f \n"
        "%11.4f \n",
        a, a, num, num, num, num);
    
    // & is the address operator !

    int b; 
    printf("Please type a number:");
    scanf_s("%d", &b);
    printf("You entered %d \n", b);

    
    float weight;

    printf("Please enter the weight: ");

    int result = scanf("%f", &weight);
    if (result != 1) {
            printf("Invalid input!\n");
            return 1;  // Exit with an error code
    }

    printf("The value of Weight is: %.2f \
            and \
            the address of the memory location is : %d\n", weight, &weight);

    // &weight returns the memory address where the variable is stored

    // return 0;

    // an error that we may obtain :
    // please type a number : r
    // you entered : -858993460 <-- Garbage value

    // scanf() Return Value	Meaning
    //    1	Successfully read one value(expected case)
    //    0	Failed to read any valid input(wrong data type entered)

    long int myLongInt;
    unsigned int myUnsignedInt;
    double myDouble;
    long double myLongDouble;
    char characterString[10];

    printf("Please enter a character string: ");
    scanf_s("%9s", characterString);

    while (getchar() != '\n');  // Clear input buffer

    printf("\nPlease enter a long double: ");
    scanf_s("%Lf", &myLongDouble);

    printf("\nYou entered:\nA string: %s\nA Long Double: %Lf\n", characterString, myLongDouble);


    printf("Please enter a character string: ");
    scanf_s("%9s", characterString);  // Limit input to 9 chars to prevent buffer overflow

    /*Why Does the Program Stop Reading long double After the String ?

     When you enter a string using scanf_s("%9s", characterString), 
     it reads the string but leaves the newline character (\n) in the input buffer.
     scanf_s("%Lf", &myLongDouble) then tries to read a floating-point number, 
     but sees the leftover newline (\n) from the previous input and stops immediately.

     */

    while (getchar() != '\n');  // Clear input buffer

    printf("\nPlease enter a long double: ");
    scanf_s(" %Lf", &myLongDouble);   // Store a long double

    printf("\nPlease enter an unsigned integer and then a long int: ");
    scanf_s(" %u %ld", &myUnsignedInt, &myLongInt);
    
    // Store an unsigned int
    // Ignore all whitespace, then store a long int

    // % lf	double
    // % Lf	long double
    
    printf("\n\nYou entered:\n"
            "A string: %s\n"
            "A Long Double: %Lf\n"
            "An Unsigned Integer: %u\n"
            "A Long Integer: %ld\n",
            characterString, myLongDouble, myUnsignedInt, myLongInt);


    // You entered :
    //    A string : "Bineet"
    //    A Long Double : 123.45678
    //    An Unsigned Integer : 255
    //    A Long Integer : 345678

    // Understanding% ld
    //    % l(lowercase L) stands for long.
    //    d stands for decimal integer.

    return 0;
}