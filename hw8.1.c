#include <stdio.h>

#define WEEKDAYS 7

void readTemperatures(float temperatures[]);
float getMax(float temperatures[]);
float getMin(float temperatures[]);
float getAverage(float temperatures[]);
void printStatistics(float temperatures[]);
void printTemperatures(float temperatures[]);

int main() {
    float weeklytemperatures[WEEKDAYS];

    readTemperatures(weeklytemperatures);
    printTemperatures(weeklytemperatures);
    printStatistics(weeklytemperatures);

    return 0;
}

void readTemperatures(float temperatures[]) {
    for (int i = 0; i < WEEKDAYS; i++) {
        printf("Enter temperature for day %d: ", i + 1);
        scanf_s("%f", &temperatures[i]);
    }
}

void printTemperatures(float temperatures[]) {
    printf("\nWeekly temperatures:\n");
    for (int i = 0; i < WEEKDAYS; i++) {
        printf("Day %d: %.2f\n", i + 1, temperatures[i]);
    }
}

float getMax(float temperatures[]) {
    float max = temperatures[0];
    for (int i = 1; i < WEEKDAYS; i++) {
        if (temperatures[i] > max) {
            max = temperatures[i];
        }
    }
    return max;
}

float getMin(float temperatures[]) {
    float min = temperatures[0];
    for (int i = 1; i < WEEKDAYS; i++) {
        if (temperatures[i] < min) {
            min = temperatures[i];
        }
    }
    return min;
}

float getAverage(float temperatures[]) {
    float sum = 0;
    for (int i = 0; i < WEEKDAYS; i++) {
        sum += temperatures[i];
    }
    return sum / WEEKDAYS;
}

void printStatistics(float temperatures[]) {
    float max = getMax(temperatures);
    float min = getMin(temperatures);
    float average = getAverage(temperatures);
    printf("\nStatistics:\n");
    printf("Minimum Temperature: %.2f\n", min);
    printf("Maximum Temperature: %.2f\n", max);
    printf("Average Temperature: %.2f\n", average);
}
