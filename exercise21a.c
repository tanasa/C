#include <stdio.h>
#include <string.h>

int main() {
    float firstN, secondN;
    char op;
    char myChar;

    printf("Type number, operator, number: ");
    scanf("%f %c %f", &firstN, &op, &secondN);

//    myChar = getch();
//    putchar(myChar);

//    myChar = getche();
//    putchar(myChar);

    myChar = getchar();
    putchar(myChar);

    myChar = getc(stdin);
    putc(myChar, stdout);

// putchar()	int char	     stdout only : Simple printing to console
// putc()	    int char, FILE*	 Any file stream : Print to console, file, or stderr

    char Str[81];

    puts("Please enter a line of text and press enter");
    puts("Enter a blank line when finished\n");

    while (fgets(Str, sizeof(Str), stdin)) {
        // Check for blank line (just "\n")
        if (strcmp(Str, "\n") == 0)
            break;

        printf("You entered: \"%s\"\n", Str);
    }

    puts("Thank you for testing fgets(), puts(), and printf()\n");

    char *pStr;

    puts("Please enter a line of text and press enter");
    puts("Enter a blank line when finished\n");

    
    while ((pStr = fgets(Str, sizeof(Str), stdin)) != NULL) {
        Str[strcspn(Str, "\n")] = '\0';     // remove newline

        if (strcmp(Str, "exit") == 0) {
            printf("Exiting the loop.\n");
            break;
        }

        printf("You entered: \"%s\"\n\n", Str);
    }

    return 0;
}

// getchar()	stdin	                    Simple console input
// getc()	    Any stream	FILE *stream	Input from files or stdin

// putchar()	stdout	int char	                Simple console output
// putc()	    Any FILE *	int char, FILE *stream	Output to files or other streams