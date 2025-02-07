#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main() {

	// 2.1

	int radius = 2;
	double area;
	const double pi = 3.142;

    area = pi * radius * radius;

	printf("The area is %5.2f \n", area);

	// 2.2

	double radius2, pi2, area2; 

	printf("\n");
	printf("Enter the radius2: ");
	scanf_s("%lf", &radius2);

	printf("\n");
	printf("Enter the value of pi2: ");
	scanf_s("%lf", &pi2);

	area2 = pi2 * radius2 * radius2;

	printf("The area is: ");
	printf("%5.2lf\n", area2);

	// 2.3

	/* 
	
	On a 64 - bit system, the short data type is typically still 16 - bit(2 bytes).
	The bitness of the CPU(32 - bit vs. 64 - bit) primarily affects pointers and addressable memory, 
	but integer types like short remain the same across most architectures.

	Even on a 64 - bit system :

	short is 2 bytes(16 bits)
	int is typically 4 bytes(32 bits)
	long is usually 4 or 8 bytes, depending on the system
	long long is 8 bytes(64 bits)

	%hd is the format specifier used in printf and scanf for the short (short integer) data type in C.

	*/

	double area3;

	printf("\n");
	printf("Enter the radius3: ");
	short newRadius;

	scanf_s("%hd", &newRadius);

	area3 = pi * newRadius * newRadius;

	printf("The area is: ");
	printf("%5.2f\n", area3);

	// input the Last Name

	printf("\n");
	char lastName[20];
	char yourInitial;

	printf("\n");
	printf("Please enter your last name: ");
	scanf_s("%19s", lastName, (unsigned)_countof(lastName));  // Secure input

	// scanf leaves new line character inserted by enter key
    // You nee clean the input buffer by repeatedly calling getchar()
    // until you get the new line character. You will learn following
    // when you read about lops

	while (getchar() != '\n')
		continue;
	printf("What is your first name?: ");

	// yourInitial = getchar(); //user may enter more than one char
	//but, getchar() returns only one char and leaves rest of the
	//characters including enter (new line '\n') character
	//in the input buffer, which may effect your next scanf.

	scanf_s(" %c", &yourInitial, 1);  // Space before %c to ignore any leftover newline
	
	while (getchar() != '\n')
		continue;

	printf("\n Hello Mr. %c. %s\n", yourInitial, lastName);

	// the next section :

	/* 
	printf("\n");
	printf("\n5185 is fun course.\n\n");

	printf("First Name \tLast Name\tCity\n");
	printf("----------- \t---------\t----\n");
	printf("Bill \tClinton \tHarlem\n");

	printf("\n");

	printf("\n");
	printf("How do you print double quotes?\n");
	printf("Who said\"Test Scores Can Be Used ....\"\n");
	*/ 

	// scanf_s should be used without & when reading strings(char arrays), as arrays are already pointers

	char FirstName[20];
	char LastName[20];
	char City[50] ;
	int  ZipCode;

	// printf("\n");
	printf("\n5185 is fun course.\n\n");

    printf("Please enter a First Name: ");
	scanf_s("%19s", FirstName, (unsigned)_countof(FirstName)); //  Buffer size 19 + null terminator
	printf("Please enter a Last Name: ");
	scanf_s("%19s", LastName, (unsigned)_countof(LastName));   //  Buffer size 19 + null terminator
	printf("Please enter a City: ");
	scanf_s("%49s", City, (unsigned)_countof(City));           //  Buffer size 49 + null terminator
	printf("Please enter a Zip Code: ");
	scanf_s("%d", &ZipCode);

	printf("First Name \tLast Name\tCity\t Zip Code\n");
	printf("------ \t------\t------\t------\n");
	printf(" %s %s %s %d\n", FirstName, LastName, City, ZipCode);

	printf("\n");

	printf("\n");
	printf("How do you print double quotes?\n");
	printf("Who said\"Test Scores Can Be Used ....\"\n");

	// 2.4

	int choice;

	// The menu to choose from
	printf("The menu to choose from is :\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Exit\n");

	// Ask the user for input
	printf("\nWhat would be your choice ?\n");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		printf("\nYou selected Addition\n");
		break;
	case 2:
		printf("\nYou selected Subtraction\n");
		break;
	case 3:
		printf("\nYou selected Multiplication\n");
		break;
	case 4:
		printf("\nYou selected Division\n");
		break;
	case 5:
		printf("\nYou selected Exit\n");
		break;
	default:
		printf("\nInvalid choice. Please select a valid option.\n");
	}

	printf("\nThank you for using my program.\n");

	return 0;
}