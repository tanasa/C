
// File : open / close
// Streams in C
// Text streams
// Binary streams

// Buffered I / O

// FILE *
// use FILE pointers to : open a disk file
// read / write from / to a disk file

// Understanding Streams and File Pointers

// Streams :
// Abstract representations of I / O devices or files.
// In C, streams are represented by the FILE type.
// stdin - Standard input(keyboard)
// stdout - Standard output(console)
// stderr - Standard error(console)

// File Pointers :
// A pointer to a stream object.
// Declared as FILE * .
// Used to refer to a specific file or stream.

// Streams in C
// Predefined(Standard) Streams
// stdin : Standard input Keyboard(scanf(), getc())
// stdout : Standard output Screen(printf(), putc())
// stderr : Standard error Screen
// stdprn : Standard printer Printer(LPT1 : ) - PC only
// stdaux : Standard auxiliary Serial port(COM1 : ) - PC only

/* File Streams in C :

File handling in C uses the following functions to work with files :

Opening and Closing Files :

fopen() - Opens a file.
fclose() - Closes an opened file.

Reading and Writing:

fscanf() - Reads formatted input from a file.
fprintf() - Writes formatted output to a file.
fgetc() - Reads a character from a file.
fputc() - Writes a character to a file.

*/

/*
Opening a File as a Stream: The syntax for opening a file is:

FILE *fptr;
fptr = fopen("filename", "mode");

FILE: A file pointer that points to the file structure.
fopen(): Opens the file in the specified mode.

Modes:
"r": Read mode (file must exist).
"w": Write mode (creates a new file or truncates an existing file).
"a": Append mode (creates a file if it does not exist).
"r+", "w+", "a+": Read and write modes with the same characteristics as above.

*/

/*

Read / write one character at a time.
Read / write one line of text at a time.
Read / write one block of characters at a time.

*/

/*

Read One Character at a Time :
*fgetc(FILE stream)

Reads a single character from the given file stream.

*/


/* 

1. Reading One Character at a Time
Function	Description	Usage
getchar()	Reads a single character from stdin.	char c = getchar();
fgetc()	    Reads a single character from a file.	char c = fgetc(fp);

2. Reading One Line at a Time
Function	Description	Usage
gets()	    Reads a line from stdin (deprecated, unsafe).	gets(buffer);
fgets()	    Reads a line from a file or stdin safely.	fgets(buffer, sizeof(buffer), fp);

 3. Reading One Block (Chunk) at a Time
Function	Description	Usage
fread()	    Reads a block of data from a file (binary or text)	fread(buffer, size, count, fp);

*/

#include <stdio.h>

int main() {

    FILE* fp = fopen("input.txt", "r");  // Open the file in read mode
    char ch;

    // 1. Reading one character at a time 

    if (fp != NULL) {  // Check if the file was opened successfully
        ch = fgetc(fp);  // Read a single character from the file
        printf("First character from file: %c\n", ch);  // Print the character
        // fclose(fp);  // Close the file
    }
    else {
        printf("Error: Could not open file 'input.txt'.\n");
    }

    // 2. Reading one line at a time, the most commonly used and safest function is fgets()
    // char *fgets(char *str, int n, FILE *stream);

    char line[100];

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("Read line: %s", line);  // Print each line
    }

    // Vendor-specific functions may also be available for reading files, 
    // depending on the compiler or platform.

    // 3. Writing One Character at a Time
    // Function	Description	Usage
    // putc()	Writes a single character to a file stream.putc(ch, fp);
    // fputc()	Similar to putc(), also writes one character.fputc(ch, fp);

    // 4. Writing One Line at a Time
    // Function	Description	Usage
    // fputs()	    Writes a string to a file without a newline.fputs(str, fp);
    // fprintf()	Formats and writes a line(includes newline).fprintf(fp, "%s\n", str);

    FILE* fpo = fopen("output_file.txt", "w");  // Open file in write mode
    char cho;

    if (fpo == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write characters 'A' to 'Z' one at a time
    for (cho = 'A'; cho <= 'Z'; cho++) {
        fputc(cho, fpo);  // Write one character to the file
    }

    // Writing one line at a time using fputs()
    fputs("Hello, World!\n", fpo);
    fputs("This is a sample file.\n", fpo);
    fputs("Writing one line at a time.\n", fpo);

    // Writing a formatted line using fprintf()
    fprintf(fpo, "Formatted line: %d + %d = %d\n", 5, 3, 5 + 3);

    fclose(fp);   // Close the file
    fclose(fpo);  // Close the file

    printf("\n\nCharacters written to output.txt\n");

    // Block Reading / Writing using fread() / fwrite().
    return 0;
}
