
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];       // Reasonable length for names
    int scores[7];       // Fixed number of scores per student
} Student;


void printStudent(Student s) {
    printf("Name: %s\nScores: ", s.name);
    for (int i = 0; i < 7; i++) {
        printf("%d ", s.scores[i]);
    }
    printf("\n");
}

int main() {

    FILE *inputFile, *outputFile;

    Student students[50000];  // Assuming a maximum of 50000 students
    int studentCount = 0;

    // Open input file for reading
    
    inputFile = fopen("inputFile.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open output file for writing
    
    outputFile = fopen("outputFile.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Reading data from the file
    char line[256];
    
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        
        Student s;
        
        int items = sscanf(line, "%[^,], %d, %d, %d, %d, %d, %d, %d",
            s.name,
            &s.scores[0], &s.scores[1], &s.scores[2],
            &s.scores[3], &s.scores[4], &s.scores[5], &s.scores[6]);

        if (items == 8) {
            // Store the student record
            students[studentCount++] = s;
            // Print the student record on the screen
            printStudent(s);
            // Write only the name to the output file
            fprintf(outputFile, "%s\n", s.name);
        } else {
            printf("Error processing the line: %s", line);
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("\nData was successfully written to outputFile.txt\n");
    return 0;
}
