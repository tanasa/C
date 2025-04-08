// ENUMERATED TYPES
// LINK LISTS
// SINGLE LINK LIST
// DOUBLE LINK LIST

/*
enum gender {
    MALE,
    FEMALE
};
*/

/*

enum is the keyword.

gender is the name of the enumeration.

MALE and FEMALE are the enumeration constants.

By default:
MALE is assigned the integer value 0.
FEMALE is assigned the integer value 1.

*/


/* 

Why Use Enums:

Readability: Replace magic numbers with meaningful names.

Code Maintenance: Centralize the management of related constants.

Type Safety: Prevents assigning values outside the defined range.

Debugging: Easy to print or compare symbolic names rather than raw numbers.

*/

#include <stdio.h>

enum gender {
    MALE,
    FEMALE
};

enum week {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum status {
    SUCCESS = 1,
    FAILURE = -1,
    PENDING = 0
};

enum traffic_light {
    RED,
    YELLOW,
    GREEN
};

enum season {
    SPRING = 1,
    SUMMER,
    FALL,
    WINTER
};

typedef enum {
    OFF,
    ON
} state;

typedef enum {
    MON, TUE, WED, THU, FRI, SAT, SUN
} day;

const char* weekdays[] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

enum grade {
    A, B, C, D, F
};

typedef struct {
    char name[50];
    enum grade letter;
} Student;

enum network_status {
    DISCONNECTED,
    CONNECTING,
    CONNECTED,
    ERROR
};

void print_grade(Student s) {
    printf("Student: %s - Grade: ", s.name);
    switch (s.letter) {
    case A: printf("A\n"); break;
    case B: printf("B\n"); break;
    case C: printf("C\n"); break;
    case D: printf("D\n"); break;
    case F: printf("F\n"); break;
    }
}

void print_status(enum network_status status) {
    switch (status) {
    case DISCONNECTED: printf("Status: Disconnected\n"); break;
    case CONNECTING: printf("Status: Connecting...\n"); break;
    case CONNECTED: printf("Status: Connected!\n"); break;
    case ERROR: printf("Status: Error occurred!\n"); break;
    }
}

int main() {
    
    // ********************************
    // ********************************

    enum gender person1 = MALE;
    enum gender person2 = FEMALE;

    if (person1 == MALE) {
        printf("Person 1 is male.\n");
    }
    else {
        printf("Person 1 is female.\n");
    }

    if (person2 == FEMALE) {
        printf("Person 2 is female.\n");
    }
    else {
        printf("Person 2 is male.\n");
    }

    // ********************************
    // ********************************

    enum week today = FRIDAY;

    if (today == FRIDAY) {
        printf("Today is Friday!\n");
    }

    // Printing the enum value
    printf("The numeric value of FRIDAY is: %d\n", today);


    // ********************************
    // ********************************

    enum status taskStatus = FAILURE;

    if (taskStatus == FAILURE) {
        printf("Task failed!\n");
    }

    // Printing the assigned enum value
    printf("The numeric value of FAILURE is: %d\n", taskStatus);


    // ********************************
    // ********************************

    enum traffic_light signal = GREEN;

    switch (signal) {
    case RED:
        printf("Stop!\n");
        break;
    case YELLOW:
        printf("Get Ready!\n");
        break;
    case GREEN:
        printf("Go!\n");
        break;
    default:
        printf("Invalid signal!\n");
    }


    // ********************************
    // ********************************

    for (enum season s = SPRING; s <= WINTER; s++) {
        printf("Season number: %d\n", s);
    }

    // ********************************
    // ********************************

    state light = ON;

    if (light == ON) {
        printf("The light is ON.\n");
    }
    else {
        printf("The light is OFF.\n");
    }

    // ********************************
    // ********************************

    for (enum day d = MON; d <= SUN; d++) {
        printf("Day %d: %s\n", d, weekdays[d]);
    }


    // ********************************
    // ********************************

    Student s1 = { "Alice", A };
    Student s2 = { "Bob", C };

    print_grade(s1);
    print_grade(s2);

    // ********************************
    // ********************************
    
    enum network_status current = CONNECTING;
    print_status(current);

    current = CONNECTED;
    print_status(current);

    return 0;
}
