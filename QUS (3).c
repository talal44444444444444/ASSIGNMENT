#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int number;
    char name[50];
    int age;
};

// Structure to represent a node in the stack
struct Node {
    struct Student data;
    struct Node* next;
};

// Function to push a student onto the stack
void push(struct Node** top, struct Student student) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a student from the stack
struct Student pop(struct Node** top) {
    if (*top == NULL) {
        struct Student emptyStudent = {0, "", 0};
        return emptyStudent;
    }
    struct Node* temp = *top;
    struct Student student = temp->data;
    *top = temp->next;
    free(temp);
    return student;
}

// Function to print student information from the stack
void printStudents(struct Node* top) {
    int count = 1;
    while (top != NULL) {
        struct Student student = pop(&top);
        printf("%d- %s %d %d\n", count, student.name, student.age, student.number);
        count++;
    }
}

int main() {
    struct Node* top = NULL; // Initialize an empty stack

    // Read student information and push onto the stack
    struct Student student;
    char choice;
    do {
        printf("Enter student number: ");
        scanf("%d", &student.number);
        printf("Enter student name: ");
        scanf("%s", student.name);
        printf("Enter student age: ");
        scanf("%d", &student.age);

        push(&top, student);

        printf("Do you want to enter another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Print student information from the stack
    printf("Student Information:\n");
    printStudents(top);

    // Free memory used by the stack
    while (top != NULL) {
        pop(&top);
    }

    return 0;
}
