#include <stdio.h>

int main() {

	char myc;

	printf("Please type a character: \n");
	myc = getchar();

	printf("you have typed the character: \n");
	putchar(myc);

	printf("\n");

	char mych1;
	char mych2;

	printf("Please type a character: \n");
	// do not press "enter"
	mych1 = getch();
    printf("you have typed the character %c: \n", mych1);
	printf("\n");

	// getche() is getch() plus echoing the character :)
	printf("Please type a character: \n");
	// do not press "enter"
	mych2 = getche();
    printf("you have typed the character %c: \n", mych2);
	printf("\n");
	
	return 0;
}