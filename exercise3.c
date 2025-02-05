#include <stdio.h>
#include <limits.h> // Required for INT_MIN, INT_MAX, LONG_MIN, LONG_MAX
#include <float.h> // Required for FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX

#define _CRT_SECURE_NO_WARNINGS

int main() {

    /*
        A byte consists of 8 bits, and each bit can be either 0 or 1.
        This means the total number of unique values that a byte can represent is:

        If a byte is unsigned, it represents values from 0 to 255.
        Example:
        00000000 (binary) = 0 (decimal)
        11111111 (binary) = 255 (decimal)

        Signed Byte (-128 to 127)

        If a byte is signed (using two’s complement representation),
        it represents values from -128 to 127.

        Example:

        10000000 (binary) = -128 (decimal)
        01111111 (binary) = 127 (decimal)

    */

    /*

    If you have 8 bytes, and each byte consists of 8 bits, the total number of bits is:

    8 × 8 = 64 bits

    Each bit can be 0 or 1, so the total number of unique values that can be represented
    in 8 bytes (64 bits) is:

    2^64 = 18,446,744,073,709,551,616
    (18.45 trillion billions)

    Signed (using Two’s Complement)

    Range:
    −9,223,372,036,854,775,808
    to
    9,223,372,036,854,775,807
    */

    /*
    Key Takeaways on 64-bit Systems:

    int is still 4 bytes.
    long int is 8 bytes, same as long long int.
    long int and long long int have the same range on most 64-bit systems.
    */

    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of long long int: %zu bytes\n", sizeof(long long int));

    printf("int long int float double")

    printf("\nSize of int: %zu bytes\n", sizeof(int));
    printf("Minimum int value: %d\n", INT_MIN);
    printf("Maximum int value: %d\n", INT_MAX);

    printf("\nSize of long int: %zu bytes\n", sizeof(long int));
    printf("Minimum long int value: %ld\n", LONG_MIN);
    printf("Maximum long int value: %ld\n", LONG_MAX);

    printf("\nSize of long long int: %zu bytes\n", sizeof(long long int));
    printf("Minimum long long int value: %lld\n", LLONG_MIN);
    printf("Maximum long long int value: %lld\n", LLONG_MAX);

    printf("\nSize of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));

    // float is 4 bytes and is usually single-precision.
    // double is 8 bytes and is double - precision, 
    // preferred for most floating - point calculations.

    printf("\nSize of float: %zu bytes\n", sizeof(float));
    printf("Minimum float value: %e\n", FLT_MIN);
    printf("Maximum float value: %e\n", FLT_MAX);

    printf("\nSize of double: %zu bytes\n", sizeof(double));
    printf("Minimum double value: %e\n", DBL_MIN);
    printf("Maximum double value: %e\n", DBL_MAX);

    // FLT_MIN(float min) = Smallest positive nonzero float value(~1.17 × 10⁻³⁸)
    // FLT_MAX(float max) = Largest float(~3.4 × 10³⁸)
    // DBL_MIN(double min) = Smallest positive nonzero double(~2.2 × 10⁻³⁰⁸)
    // DBL_MAX(double max) = Largest double(~1.8 × 10³⁰⁸)

    return 0; // Ensuring proper program termination
}