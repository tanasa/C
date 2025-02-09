/* Example from C Primer Plus Book */
/* sweetie1.c .. a counting loop */
#include <stdio.h>

#define NUMBER 22

int main(void) {

    int count = 1;  /* initialization */

    while (count <= NUMBER) {  /* test */
        printf("Be my Valentine!\n");  /* action */
        count++;  /* update count */
    }

    /*
    for (InitializeExpression; ControlExpression; UpdateExpression)
    {
    BlockStatement(s);
    }
    */


    for (count = 1; count <= NUMBER; count++)
        printf("Be my Valentine!\n");

    // 1

    int i, k;

    for (i = 1; i < 10; i++) {
        for (k = 1; k <= i; k++)
            printf("%d", i);
        printf("\n");
    }

    // 2
    int sum =0 ; 

    for (int i = 1; i <= 100; i++)
        sum += i;

    printf("The total of 1 to 100 is: %d\n", sum);
    
    // 3 : print the characters from A to Z
    
    printf("The characters from A to Z :\n");

    for (int i = 65; i <= 90; i++)
        printf("%c", i);

    printf("\n");

    // 4 :  shorter expression

    int counta = 1; // Initialize count

    while (counta++ < 21) {
        printf("-");
    }

    printf("\n\n");

    // 5 : shorter expression
   
    int countb = 1;  // Initialize count

    for (; countb++ < 21; ) {
        printf("-");
    }

    printf("\n");

    // 6 : to increment by 2

    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // 7 : summary

    /*
    Control Statements:

    Conditional Statements:

    if
    if .. else
    switch
    ?: (Ternary Operator)

    Looping Statements:

    while
    do while
    for (circled and highlighted in red)
    
    */
    
    return 0;
}
