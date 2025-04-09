#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure representing a student node
typedef struct student {
    char name[50];
    int ID;
    int visited;  // For traversal
} STUDENT;

// Graph represented as an adjacency matrix
int adjacencyMatrix[MAX_STUDENTS][MAX_STUDENTS];
STUDENT* studentList[MAX_STUDENTS];
int studentCount = 0;

// Function Prototypes
int AddStudent(const char* name, int ID);
void AddEdge(int fromID, int toID);
void PrintGraph();
void DFS(int startID);
void BFS(int startID);
int GetStudentIndexByID(int ID);
void ResetVisited();

int main() {
    int alice = AddStudent("Alice", 101);
    int bob = AddStudent("Bob", 102);
    int zara = AddStudent("Zara", 103);
    int mila = AddStudent("Mila", 104);
    int yan = AddStudent("Yan", 105);

    AddEdge(101, 102);
    AddEdge(101, 103);
    AddEdge(102, 104);
    AddEdge(103, 105);
    AddEdge(104, 105);

    printf("Graph Adjacency Matrix (Directed):\n");
    PrintGraph();

    printf("\nDepth-First Search (from Alice):\n");
    DFS(101);

    printf("\nBreadth-First Search (from Alice):\n");
    ResetVisited();
    BFS(101);

    return 0;
}

int AddStudent(const char* name, int ID) {
    if (studentCount >= MAX_STUDENTS) return -1;
    STUDENT* s = malloc(sizeof(STUDENT));
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    s->ID = ID;
    s->visited = 0;
    studentList[studentCount++] = s;
    return studentCount - 1;
}

int GetStudentIndexByID(int ID) {
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i]->ID == ID) return i;
    }
    return -1;
}

void AddEdge(int fromID, int toID) {
    int i = GetStudentIndexByID(fromID);
    int j = GetStudentIndexByID(toID);
    if (i != -1 && j != -1) {
        adjacencyMatrix[i][j] = 1; // Only one direction for directed graph
    }
}

void PrintGraph() {
    for (int i = 0; i < studentCount; i++) {
        printf("%s (%d): ", studentList[i]->name, studentList[i]->ID);
        for (int j = 0; j < studentCount; j++) {
            if (adjacencyMatrix[i][j]) {
                printf("%s (%d) ", studentList[j]->name, studentList[j]->ID);
            }
        }
        printf("\n");
    }
}

void DFS(int startID) {
    int index = GetStudentIndexByID(startID);
    if (index == -1 || studentList[index]->visited) return;

    studentList[index]->visited = 1;
    printf("%s (%d)\n", studentList[index]->name, studentList[index]->ID);

    for (int i = 0; i < studentCount; i++) {
        if (adjacencyMatrix[index][i] && !studentList[i]->visited) {
            DFS(studentList[i]->ID);
        }
    }
}

void BFS(int startID) {
    int queue[MAX_STUDENTS], front = 0, rear = 0;
    int index = GetStudentIndexByID(startID);
    if (index == -1) return;

    studentList[index]->visited = 1;
    queue[rear++] = index;

    while (front < rear) {
        int curr = queue[front++];
        printf("%s (%d)\n", studentList[curr]->name, studentList[curr]->ID);

        for (int i = 0; i < studentCount; i++) {
            if (adjacencyMatrix[curr][i] && !studentList[i]->visited) {
                studentList[i]->visited = 1;
                queue[rear++] = i;
            }
        }
    }
}

void ResetVisited() {
    for (int i = 0; i < studentCount; i++) {
        studentList[i]->visited = 0;
    }
}
