
#include <stdio.h>

int main() {

	// pre- and post- increment / decrement operators

    int N1, N2; 

    printf("post-increment:");
    N1 = 9;
    printf("%d\n", N1++); // Post-increment: Prints 9, then increments N1 to 10
    printf("%d\n\n", N1);  // Prints updated value of N1 (which is now 10)

    printf("pre-increment:");
    N2 = 9;
    printf("%d\n", ++N2);  // Pre-increment: Increments N2 to 10, then prints 10
    printf("%d\n\n", N2);  // Prints updated value of N2 (which remains 10)

    /*
    Key Differences
        Post - increment(N1++) → Uses the current value first, then increments.
        Pre - increment(++N2) → Increments first, then uses the new value.
     */

    int count, loop;

    count = 9;
    loop = ++count;
    
    /*
        Pre - increment(++count) : count is first incremented to 10, then assigned to loop.
        Final values :
        loop = 10
        count = 10
    */

    count = 9;
    loop = count++;
    /*
        Post - increment(count++) : count is first assigned to loop(loop = 9), then count is incremented.
        Final values :
        loop = 9
        count = 10
     */

    int Num;
    loop = 8; 
    count = 15;

    Num = loop++; // Post-increment: Assigns loop (8), then increments loop to 9
    printf("\nNum = %d, loop = %d\n", Num, loop);

    Num = ++Num; // Pre-increment: Increments Num to 9, then assigns it
    printf("\nNum = %d, loop = %d\n", Num, loop);

    Num = count++ + loop; // Post-increment: Uses count (15) first, then increments count to 16
    printf("\nNum = %d, loop = %d\n", Num, loop);

    Num = --count + --loop; // Pre-decrements: count (15), loop (8) before adding
    printf("\nNum = %d, loop = %d\n", Num, loop);

    Num = loop + --Num; // Pre-decrements Num before addition
    printf("\nNum = %d, loop = %d\n", Num, loop);

    printf("\n\n");

    int A, B = 5, C = 10;
    C++;
    A = ++B + --C;
    printf("The value of A is %d \n", A);
    printf("The value of B is %d \n", B);
    printf("The value of C is %d \n", C);
    printf("\n\n");
    // C = 10, B = 6, A = 16

    A = ++A + B + C--;
    printf("The value of A is %d \n", A);
    printf("The value of B is %d \n", B);
    printf("The value of C is %d \n", C);
    printf("\n\n");
    // A = 33, B = 6, C = 9

    A = C / 2 + B--;
    printf("The value of A is %d \n", ++A);
    printf("The value of B is %d \n", B);
    printf("The value of C is %d \n", C);
    printf("\n\n");
    // A = 11, B = 5, C = 9


	return 0;
}