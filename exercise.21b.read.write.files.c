#include <stdio.h>
#include <stdlib.h>

// Functions to work on files

int main() {

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    }
    else {
        perror("Error getting current directory");
        return 1;
    }

    FILE* infile = fopen("infile.txt", "r");
    FILE* outfile = fopen("outfile.txt", "w");

    if (!infile) {
        perror("Error opening input file");
        return 1;
    }

    if (!outfile) {
        perror("Unable to open output file");
        fclose(infile);
        return 1;
    }

    // Reading the files in C :
    // Method	Function	Description	Use Case	File Type
    // Character - by - character	fgetc()	      Reads one character at a time	Reading text files slowly	Text
    // Line - by - line	            fgets()	      Reads a line or specified number of characters	Reading text line by line	Text
    // Formatted read	            fscanf()	  Reads formatted data from a file	Reading structured text data	Text
    // Block read	                fread()	      Reads a block of data from a file	Efficient binary data read	Binary

    // 1. Reading from the file using fgets() (Line by Line)
    printf("\nReading using fgets():\n");
    char line[256];
    while (fgets(line, sizeof(line), infile)) {
           printf("%s", line);  // Print each line as it is read
    }

    // Rewind to the start of the file for the next reading method
    rewind(infile);

    // 2. Using fgetc() (Character by Character)
    printf("\nReading using fgetc():\n");
    int ch;
    while ((ch = fgetc(infile)) != EOF) {
        putchar(ch);  // Print each character
    }

    // Rewind again before the next reading method
    rewind(infile);

    // 3. Using fscanf() (Formatted Reading)
    printf("\nReading using fscanf():\n");

    char Line[256];  // Buffer to store the entire line
    int count = 0;

    // Reading the entire line as a string using fscanf_s
    while (fscanf_s(infile, "%255[^\n]\n", Line, (unsigned)_countof(Line)) == 1) {
          printf("Line %d: %s\n", ++count, Line);
    }

    // _countof() is a macro provided by Microsoft Visual C++ (MSVC) 
    // and is used to determine the number of elements in a statically allocated array.


    // Printing files in C :
    // Method	Function	Description	Use Case	File Type
    // Character - by - character	 fputc()	Writes a single character to a file	Writing one character at a time	Text
    // Line - by - line	             fputs()	Writes a string(line) to a file	Writing whole lines or strings	Text
    // Formatted write	             fprintf()	Writes formatted data(like printf)	Formatted output to text files	Text
    // Block write	                 fwrite()	Writes a block of data to a file	Efficient binary data output	Binary

    // 1. Character - by - character using fputc()

    // Write characters to the file
    fputc('H',  outfile);
    fputc('e',  outfile);
    fputc('l',  outfile);
    fputc('l',  outfile);
    fputc('o',  outfile);
    fputc('\n', outfile);

    // 2. Line - by - line using fputs()

    // Write a line to the file
    fputs("Hello, world!\n", outfile);
    fputs("This is line two.\n", outfile);

    // 3. Formatted write using fprintf()

    int age = 30;
    double height = 5.9;

    // Write formatted data to the file
    fprintf(outfile, "Name: %s\n", "John Doe");
    fprintf(outfile, "Age: %d\n", age);
    fprintf(outfile, "Height: %.1f feet\n", height);

    // 4. Block write using fwrite()
    // fwrite(): Efficient for writing binary data.

    fclose(infile);
    fclose(outfile);

    return 0;
}
