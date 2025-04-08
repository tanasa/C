// MULTI-DIMENSIONAL ARRAYS: Store data of the same type organized in multiple dimensions.

// PARALLEL ARRAYS: For example, 40 names, 40 grades, 40 schools, 40 GPAs – each array stores 
// related data of the same size.
// char names[40][50];
// float gpas[40];

// In arrays, elements are accessed using their INDEX.

/*
ADT(Abstract Data Types) : Conceptual models that define data and the operations that can be performed on them.

STRUCTURES : A way to group variables of different data types into a single unit.
             They are collections of variables bundled together.

Individual components of a struct are called FIELDS.
FIELDS within a structure are accessed using their names.

A STRUCT is a data structure that groups variables of various types into a single entity

*/

// defining the structure : DECLARE

/*

a. method 1

struct student {
    int ID;
    char name[40];
    float cgpa;
};
struct student c_student;

b. method 2

struct student {
    int ID;
    char name[40];
    float cgpa;
} c_student, unix_student;

c. method 3

struct student {
    int ID;
    char name[40];
    float cgpa;
};
typedef struct student Student;
//The keyword typedef is used to create an alias or nickname for the struct student type.

d. method 4

typedef struct {
    int ID;
    char name[40];
    float cgpa;
} student;

student c_student;

*/

// INITIALIZE :

/*
Code 1: Using Direct Initialization

typedef struct {
    int ID;
    char name[40];
    float cgpa;
} student;

student c_student = { 1, "John Smith", 3.89 };

Code 2: Using Individual Assignment : using DOT operator

typedef struct {
    int ID;
    char name[40];
    float cgpa;
} student;

student c_student;
c_student.ID = 1;
strcpy(c_student.name, "John Smith"); // we can not do : c_student.name = "John Smith"
c_student.cgpa = 3.89;

*/

// ARRAY of STRUCTURES

#include <stdio.h>
#include <string.h>  // For strcpy function

// Define a student structure using typedef for easier usage
typedef struct {
    int ID;
    char name[50];
    float cgpa;
} Student;

typedef struct {
    char dept[40];
    Student info;
} graduate_student;

// Function prototype
void print_structures(graduate_student gStudent);
void print_structures2(graduate_student* gStudent);

int main() {
    // Declare an array of Student structures
    Student c_student[3];
    // c_student[0];
    // c_student[1];
    // c_student[2];

    printf("\n-------------------------\n");
    printf("\n---ARRAY of STRUCTURES---\n");
    printf("\n-------------------------\n");

    // Initialize student details
    c_student[0].ID = 0;
    strcpy_s(c_student[0].name, sizeof(c_student[0].name), "Cathy");
    c_student[0].cgpa = 3.8;

    c_student[1].ID = 1;
    strcpy_s(c_student[1].name, sizeof(c_student[1].name), "Mary");
    c_student[1].cgpa = 3.75;

    c_student[2].ID = 2;
    strcpy_s(c_student[2].name, sizeof(c_student[2].name), "Louie");
    c_student[2].cgpa = 3.65;

    // Print student details using a loop
    for (int i = 0; i < 3; i++) {
        printf("Hello %s, you have a good GPA: %5.2f\n", c_student[i].name, c_student[i].cgpa);
    }

    printf("\n-------------------------\n");
    printf("\n---NESTED STRUCTURES-----\n");
    printf("\n-------------------------\n");

    // typedef struct {
    //    char dept[40];
    //   Student info;
    // } graduate_student;

    // Structure Variable Declaration :
    graduate_student gStudent;

    // Assigning Values :
    strcpy_s(gStudent.dept, sizeof(gStudent.dept), "Computer Science");
    gStudent.info = c_student[0];

    printf("Hello %s grad student, you have a good GPA: %5.2f\n", gStudent.dept, gStudent.info.cgpa);

    // Accessing Nested Structure Members :
    // To access nested structure members, use the dot operator (.) :
    // gStudent.dept - Accesses the department field.
    // gStudent.info.cgpa - Accesses the CGPA from the nested student structure within graduate_student.

     // Accessing Nested Structure Members
    printf("Graduate Student Department: %s\n", gStudent.dept);
    printf("Student Name: %s\n", gStudent.info.name);
    printf("Student GPA: %5.2f\n", gStudent.info.cgpa);

    printf("\n-------------------------\n");
    printf("\n-STRUCTURES and POINTERS-\n");
    printf("\n-------------------------\n");

    // Declaration of a Structure Pointer :
    graduate_student* pgStudent;

    // This line declares a pointer named pgStudent to a structure of type graduate_student
    /*
    Why Use a Pointer to a Structure ?

        Dynamic Memory Allocation : You can allocate memory during runtime.

        Efficient Data Access : Passing pointers is more memory - efficient than passing the entire structure.

        Direct Access : Accessing members via pointers is common when working with linked lists, trees, or dynamically allocated structures.

        Since pgStudent is a pointer, it needs to be assigned memory before usage.

     */

    pgStudent = (graduate_student*)malloc(sizeof(graduate_student));

    pgStudent = &gStudent;  // Pointing to an existing structure variable

    /*
    3. Using Pointers to Access Structure Members :

       Accessing Members with the Arrow Operator(->) :

       strcpy(pgStudent->dept, "Computer Science");
       pgStudent->info = c_student[0];

       The -> operator is used to access structure members when using a pointer.

       Equivalent to :(*pgStudent).dept

       The -> operator is more readable and preferable when working with structure pointers.

       Why Use->Instead of the Dot Operator(.) ?
       The dot operator is used when you have a structure variable.

       The arrow operator is used when you have a pointer to a structure.

     */

     // Printing the Data Using Pointers :

    printf("Hello %s grad student, using pointers: %5.2f\n",
        pgStudent->dept,
        pgStudent->info.cgpa);

    // Understanding the Pointer Syntax :
    // pgStudent->dept is the same as(*pgStudent).dept
    // pgStudent->info.cgpa is the same as(*pgStudent).info.cgpa

    printf("\n-------------------------\n");
    printf("\nSTRUCTURES and FUNCTIONS:\n");
    printf("\n-------------------------\n");

    print_structures(gStudent);

    print_structures2(pgStudent);
    print_structures2(&gStudent);

    // Free allocated memory
    // free(pgStudent);
    pgStudent = NULL;

    return 0;
}

void print_structures(graduate_student gStudent) {

    const graduate_student* pgStudent;
    // Uses const to indicate that pgStudent points to a read - only structure.
    // Uses const to ensure that the function does not accidentally modify the input.

    printf("This is from a function\n");
    printf("Hello %s grad student, you have a good GPA: %5.2f\n", gStudent.dept, gStudent.info.cgpa);

    pgStudent = &gStudent;
    printf("Hello %s grad student, using pointers: %5.2f\n", pgStudent->dept, pgStudent->info.cgpa);
}

void print_structures2(graduate_student* gStudent) {

    printf("This is from a pointer-based function\n");
    printf("Hello %s grad student, using pointers: %5.2f\n", gStudent->dept, gStudent->info.cgpa);
}

/*

Structures can be passed to functions by value or by reference.

void print_structures(graduate_student gStudent);

Passing by value :
A copy of the structure is passed, which is memory - intensive for large structures.

Passing by reference :
Pass a pointer to the structure to avoid copying.

Using malloc for Dynamic Memory Allocation :

pgStudent = (graduate_student*)malloc(sizeof(graduate_student));
Always check if memory allocation was successful.

*/