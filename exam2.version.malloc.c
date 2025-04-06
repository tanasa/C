#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 3 // 3 students

typedef struct {
    char name[100];
    float scores[7];
    float finalScore;
    char grade;
} Student;

void bubbleSort(Student* students, int count);
void calculateMinMaxAverage(Student* students, int count);
char computeGrade(float score);
float computeFinalScore(float scores[]);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int capacity = INITIAL_SIZE;
    int count = 0;

    // Memory allocation for students
    Student* students = (Student*)malloc(capacity * sizeof(Student));
    if (!students) {
        perror("Memory allocation failed");
        return 1;
    }

    // File handling with error checking
    // FILE* infile = fopen("exercisefin.txt", "r");
    // FILE* outfile = fopen("exercisefout.txt", "w");

    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = fopen(argv[2], "w");

    if (!infile) {
        perror("Error opening input file");
        free(students);
        return 1;
    }

    if (!outfile) {
        perror("Error opening output file");
        fclose(infile);
        free(students);
        return 1;
    }

    // Reading student data from the input file
    while (fscanf(infile, "%99[^,], %f, %f, %f, %f, %f, %f, %f\n",
        students[count].name,
        &students[count].scores[0], &students[count].scores[1],
        &students[count].scores[2], &students[count].scores[3],
        &students[count].scores[4], &students[count].scores[5],
        &students[count].scores[6]) == 8) {

        // Compute final score and grade
        students[count].finalScore = computeFinalScore(students[count].scores);
        students[count].grade = computeGrade(students[count].finalScore);
        count++;

        // Check if we need to expand the array
        if (count >= capacity) {
            capacity *= 2;
            students = (Student*)realloc(students, capacity * sizeof(Student));
            if (!students) {
                perror("Memory reallocation failed");
                fclose(infile);
                fclose(outfile);
                return 1;
            }
        }
    }

    // Sorting students by name
    bubbleSort(students, count);

    // Print the header line to the output file
    fprintf(outfile, "Letter grade for %d students given in the input file is:\n", count);
    printf("Average score for each student:\n");

    // Print the sorted names and the corresponding grades to the output file
    for (int i = 0; i < count; i++) {
        fprintf(outfile, "%s\t %c\n", students[i].name, students[i].grade);
        printf("%s\t %.2f\n", students[i].name, students[i].finalScore);
    }

    // Calculating and printing statistics
    calculateMinMaxAverage(students, count);

    // Close the files and free the memory
    fclose(infile);
    fclose(outfile);
    free(students);

    return 0;
}

void calculateMinMaxAverage(Student* students, int count) {
    float sum[7] = { 0 };
    float min[7];
    float max[7];

    // Initialize min and max with the first student's scores
    for (int j = 0; j < 7; j++) {
        min[j] = max[j] = students[0].scores[j];
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 7; j++) {
            sum[j] += students[i].scores[j];
            if (students[i].scores[j] < min[j]) min[j] = students[i].scores[j];
            if (students[i].scores[j] > max[j]) max[j] = students[i].scores[j];
        }
    }

    // Print statistics to the console
    printf("Letter grade has been calculated for students listed in the input file and written to the output file\n");
    printf("Here are the class averages:\n");
    printf("Q1\tQ2\tQ3\tQ4\tMidI\tMidII\tFinal\n");

    printf("Average: ");
    for (int j = 0; j < 7; j++) printf("%.2f\t", sum[j] / count);
    printf("\nMinimum: ");
    for (int j = 0; j < 7; j++) printf("%.2f\t", min[j]);
    printf("\nMaximum: ");
    for (int j = 0; j < 7; j++) printf("%.2f\t", max[j]);
    printf("\n");
}

char computeGrade(float score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

float computeFinalScore(float scores[]) {
    return scores[0] * 0.10 + scores[1] * 0.10 + scores[2] * 0.10 +
           scores[3] * 0.10 + scores[4] * 0.20 + scores[5] * 0.15 + scores[6] * 0.25;
}

// We do not need to swap the grades separately because the Student structure
// already contains the name, scores, finalScore, and grade as a single unit.

void bubbleSort(Student* students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
