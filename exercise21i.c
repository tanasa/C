#include <stdio.h>

int main() {

    FILE* fptr1, * fptr2;
    char inFile[] = "inputfile.txt";
    char outFile[] = "outputfile.txt";
    char myChar;

    // Open output file for writing
    if (fopen_s(&fptr1, outFile, "w") != 0) {
        printf("Cannot open %s.\n", outFile);
        return 1;
    }
    // Open input file for reading
    else if (fopen_s(&fptr2, inFile, "r") != 0) {
        printf("Cannot open %s.\n", inFile);
        fclose(fptr1);  // Close the first file if the second file cannot be opened
        return 1;
    }
    else {
        // Copy content from input file to output file
        while ((myChar = fgetc(fptr2)) != EOF) {
            fputc(myChar, fptr1);
            putchar(myChar);
        }

        fclose(fptr1);
        fclose(fptr2);
    }

    /* 
    
    The fgetc function reads a single character from the file pointed to by fptr2.
    It returns the read character as an int.
    If the end of the file(EOF) is reached, fgetc returns EOF.
    
    fputc(myChar, fptr1);
    The fputc function writes the character stored in myChar to the file pointed to by fptr1.
    
    Displaying the Character on Screen : 
    putchar(myChar);
    The putchar function outputs the character stored in myChar to the standard output(typically the console).

    */

    /*
    
    int fputc(int character, FILE *stream);  fputc() - Writing to a File
    int putchar(int character); putchar() - Writing to the Console

    */

    /* 
    
    Functions Similar to fputc()
    These functions are used for writing a single character or multiple characters to a file.

    Function	Description
    fputc()	    Writes a single character to a file.
    fputs()	    Writes a string to a file(excluding the null terminator).
    fprintf()	Writes formatted output to a file(similar to printf).
    fwrite()	Writes binary data from a buffer to a file.
    
    */


    /*
    
    Functions Similar to putchar()
    These functions are used for writing a single character or multiple characters to the console.

    Function	Description
    putchar()	Writes a single character to the standard output(console).
    puts()	    Writes a string followed by a newline to the console.
    printf()	Writes formatted output to the standard output.
    putc()	    Can write a character to the console if stdout is used.

    */

    /*
    
    Functions in C :

    Put Functions	                 Get Functions (Opposite)	           Description
    
    putchar(int c)	                 getchar()	                            Writes a single character to the console / Reads a single character from the console.
    puts(const char *s)	/ fputs()    gets(char *s) (deprecated) / fgets()	Writes a string to the console / Reads a string from input.
    fputc(int c, FILE *f)	         fgetc(FILE *f)	                        Writes a single character to a file / Reads a single character from a file.
    putc(int c, FILE *f)	         getc(FILE *f)	                        Similar to fputc() and fgetc(), but may be implemented as macros.
    fprintf(FILE *f, ...)	         fscanf(FILE *f, ...)	                Writes formatted data to a file / Reads formatted data from a file.
    fwrite()	                     fread()	                            Writes binary data from a buffer to a file / Reads binary data into a buffer from a file.
       
    */
    
    return 0;
}

/*

Key Differences : writing functions in C 

Destination:

Console Output : putchar(), puts(), printf().
File Output :    putc(), fputc(), fprintf(), fputs(), fwrite().

Both : putc() can write to both the console and a file depending on the stream used.

Data Type :
Character:       putchar(), putc(), fputc().
String / Line :  puts(), fputs().
Formatted Text : printf(), fprintf().
Binary Data :    fwrite().

*/

/*

Function	Destination	Data Type	Description
putchar()	Console	Single Character	        Writes a single character to the standard output (console).
puts()	    Console	String (Line)	            Writes a string followed by a newline to the console.
putc()	    File/Console	Single Character	Writes a single character to a file (or console if stdout is used).
fputc()	    File	Single Character	        Writes a single character to a file.
fputs()	    File	String (Line)	            Writes a string (without a newline) to a file.
fprintf()	File	Formatted Text	            Writes formatted output (strings, numbers) to a file.
printf()	Console	Formatted Text	            Writes formatted output (strings, numbers) to the console.
fwrite()	File	Binary Data	                Writes binary data from a buffer to a file.

*/

/*

Key Differences : reading functions in C

Function	Source	        Data Type	        Description
getchar()	Console	        Single Character	Reads a single character from the standard input (console).
gets()	    Console	        String (Line)	    Reads a line from the console (deprecated, unsafe).
getc()	    File/Console	Single Character	Reads a single character from a file (or console if stdin is used).
fgetc()	    File	        Single Character	Reads a single character from a file.
fgets()	    File/Console	String (Line)	    Reads a line from a file (or console if stdin is used).
fscanf()	File	        Formatted Data	    Reads formatted data from a file.
scanf()	    Console	        Formatted Data	    Reads formatted input from the standard input (console).
fread()	    File	        Binary Data	        Reads binary data from a file into a buffer.

*/

/*

Key Differences:

Source:
Console Input: getchar(), gets() (deprecated), scanf().
File Input: getc(), fgetc(), fgets(), fscanf(), fread().
Both: getc() and fgets() can read from both console and file if stdin is used.

Data Type:
Character: getchar(), getc(), fgetc().
String/Line: gets() (deprecated), fgets().
Formatted Data: scanf(), fscanf().
Binary Data: fread().

*/