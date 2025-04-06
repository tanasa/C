#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char names[][100], char grades[], int count);
void calculateMinMaxAverage(float scores[][7], int count);
char computeGrade(float score);
float computeFinalScore(float scores[]);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char names[1000][100];            // Stores student names
    float scores[1000][7] = { 0 };    // 2D array for scores (ensures no garbage values)
    float finalScores[1000] = { 0 };  // Array for final scores
    char grades[1000] = { 0 };        // Grades for each student
    int count = 0;

    // FILE* infile = fopen("exercisefin.txt", "r");
    // FILE* outfile = fopen("exercisefout.txt", "w");
    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = fopen(argv[2], "w");

    if (!infile || !outfile) {
        perror("Error opening files");
        return 1;
    }

    // Reading student data from the input file
    while (fscanf(infile, "%99[^,], %f, %f, %f, %f, %f, %f, %f\n",
        names[count],
        &scores[count][0], &scores[count][1], &scores[count][2],
        &scores[count][3], &scores[count][4],
        &scores[count][5], &scores[count][6]) == 8) {
        finalScores[count] = computeFinalScore(scores[count]);
        grades[count] = computeGrade(finalScores[count]);
        count++;
    }

    // Sorting names and grades
    bubbleSort(names, grades, count);

    // Print the header line to the output file
    fprintf(outfile, "Letter grade for %d students given in input_data.txt file is:\n", count);
    printf("Average score for each student:\n");
    // Print the sorted names and the corresponding grades to the output file
    for (int i = 0; i < count; i++) {
        // Print into the output file
        fprintf(outfile, "%s\t %c\n", names[i], grades[i]);
        // Print to console
        printf("%s\t %.2f\n", names[i], finalScores[i]);
    }

    // Calculating and printing statistics
    calculateMinMaxAverage(scores, count);

    fclose(infile);
    fclose(outfile);
    return 0;
}

void calculateMinMaxAverage(float scores[][7], int count) {
    float sum[7] = { 0 };    // Holds the sums of each score category
    float min[7];            // Minimum values for each category
    float max[7];            // Maximum values for each category

    // Initialize min and max with the first student's scores
    for (int j = 0; j < 7; j++) {
        min[j] = max[j] = scores[0][j];
    }

    // Compute sums, minimums, and maximums for all scores
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 7; j++) {
            sum[j] += scores[i][j];
            if (scores[i][j] < min[j]) min[j] = scores[i][j];
            if (scores[i][j] > max[j]) max[j] = scores[i][j];
        }
    }

    // Print statistics to the console
    printf("Letter grade has been calculated for students listed in input file input_data.txt and written to output file output_data.txt\n");
    printf("Here is the class averages:\n");
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

void bubbleSort(char names[][100], char grades[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char tempName[100];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);

                char tempGrade = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = tempGrade;
            }
        }
    }
}
