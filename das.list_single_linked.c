#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a student in a singly linked list
typedef struct student {
    char name[50];
    int ID;
    struct student* next;
} STUDENT;

// Global pointer to the head of the list
STUDENT* head = NULL;

// Function Prototypes
void InsertStudentAtPosition(const char* name, int ID, int position);
void RemoveStudentAtPosition(int position);
void RemoveStudentByName(const char* name);
void PrintAllStudents();
void DeleteAllStudents();
STUDENT* FindStudentByID(int ID);
STUDENT* FindStudentByName(const char* name);
void UpdateStudent(int position, const char* newName, int newID);
void SortByID();
void SortByName();
int CountStudents();

int main() {
    InsertStudentAtPosition("Alice", 101, 0);
    InsertStudentAtPosition("Bob", 102, 1);
    InsertStudentAtPosition("Zara", 99, 0);
    InsertStudentAtPosition("Mila", 100, 2);
    InsertStudentAtPosition("Yan", 98, 10);

    printf("\nInitial student list:\n");
    PrintAllStudents();

    printf("\nTotal students: %d\n", CountStudents());

    printf("\nSorted by ID:\n");
    SortByID();
    PrintAllStudents();

    printf("\nSorted by Name:\n");
    SortByName();
    PrintAllStudents();

    STUDENT* found = FindStudentByID(102);
    if (found) printf("\nFound by ID: %s\n", found->name);

    found = FindStudentByName("Zara");
    if (found) printf("Found by Name: %s with ID %d\n", found->name, found->ID);

    UpdateStudent(1, "Bobby", 202);
    printf("\nAfter update:\n");
    PrintAllStudents();

    RemoveStudentAtPosition(2);
    printf("\nAfter removal at position 2:\n");
    PrintAllStudents();

    RemoveStudentByName("Bobby");
    printf("\nAfter removal by name 'Bobby':\n");
    PrintAllStudents();

    printf("\nDeleting all students...\n");
    DeleteAllStudents();
    printf("All students deleted.\n");

    return 0;
}

void InsertStudentAtPosition(const char* name, int ID, int position) {
    STUDENT* newStudent = malloc(sizeof(STUDENT));
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';
    newStudent->ID = ID;
    newStudent->next = NULL;

    if (head == NULL || position <= 0) {
        newStudent->next = head;
        head = newStudent;
        return;
    }

    STUDENT* current = head;
    int index = 0;
    while (current->next && index < position - 1) {
        current = current->next;
        index++;
    }

    newStudent->next = current->next;
    current->next = newStudent;
}

void RemoveStudentAtPosition(int position) {
    if (!head || position < 0) return;
    STUDENT* current = head;

    if (position == 0) {
        head = head->next;
        free(current);
        return;
    }

    STUDENT* prev = NULL;
    int index = 0;
    while (current && index < position) {
        prev = current;
        current = current->next;
        index++;
    }
    if (!current) return;
    prev->next = current->next;
    free(current);
}

void RemoveStudentByName(const char* name) {
    STUDENT* current = head;
    STUDENT* prev = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) prev->next = current->next;
            else head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void PrintAllStudents() {
    STUDENT* current = head;
    while (current) {
        printf("Name: %s, ID: %d\n", current->name, current->ID);
        current = current->next;
    }
}

void DeleteAllStudents() {
    while (head) {
        RemoveStudentAtPosition(0);
    }
}

int CountStudents() {
    int count = 0;
    STUDENT* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

STUDENT* FindStudentByID(int ID) {
    STUDENT* current = head;
    while (current) {
        if (current->ID == ID) return current;
        current = current->next;
    }
    return NULL;
}

STUDENT* FindStudentByName(const char* name) {
    STUDENT* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) return current;
        current = current->next;
    }
    return NULL;
}

void UpdateStudent(int position, const char* newName, int newID) {
    STUDENT* current = head;
    int index = 0;
    while (current && index < position) {
        current = current->next;
        index++;
    }
    if (current) {
        strncpy(current->name, newName, sizeof(current->name) - 1);
        current->name[sizeof(current->name) - 1] = '\0';
        current->ID = newID;
    }
}

void SortByID() {
    if (!head) return;
    int swapped;
    STUDENT* ptr1;
    STUDENT* ptr2 = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2) {
            if (ptr1->ID > ptr1->next->ID) {
                int tempID = ptr1->ID;
                char tempName[50];
                strcpy(tempName, ptr1->name);

                ptr1->ID = ptr1->next->ID;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->ID = tempID;
                strcpy(ptr1->next->name, tempName);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

void SortByName() {
    if (!head) return;
    int swapped;
    STUDENT* ptr1;
    STUDENT* ptr2 = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2) {
            if (strcmp(ptr1->name, ptr1->next->name) > 0) {
                int tempID = ptr1->ID;
                char tempName[50];
                strcpy(tempName, ptr1->name);

                ptr1->ID = ptr1->next->ID;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->ID = tempID;
                strcpy(ptr1->next->name, tempName);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}
