#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <string.h>  // For strcpy_s

typedef struct {
    int ID;
    char name[40];
    float cgpa;
} student;

typedef struct {
    char dept[40];
    student info;
} gstudent;

void print_student(gstudent myStudent) {
    printf("Student Name: %s\n", myStudent.info.name);
}

void print_student2(gstudent* myStudent) {
    printf("Student Name: %s\n", myStudent->info.name);
}

int main() {

    gstudent gst;

    // Example of assigning a value to the nested structure
    strcpy_s(gst.info.name, sizeof(gst.info.name), "John Smith");
    print_student(gst);

    // Dynamically allocate memory for the gstudent structure
    gstudent* pgst = (gstudent*)malloc(sizeof(gstudent));

    if (pgst == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values using strcpy_s
    strcpy_s(pgst->info.name, sizeof(pgst->info.name), "John Smith");
    // Print the student name
    print_student2(pgst);

    // Free allocated memory
    free(pgst);


    return 0;
}
