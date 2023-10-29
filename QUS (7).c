#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student records
struct Student {
    char name[50];
    int rollNumber;
    // Add other fields as needed
};

// Define a stack structure to store student records
struct Stack {
    struct Student data;
    struct Stack* next;
};

// Function to push a student record onto the stack
void push(struct Stack** top, struct Student student) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = student;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a student record from the stack
void pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Function to find the record with the longest name in the stack
void printLongestName(struct Stack* top) {
    int maxLength = 0;
    char longestName[50];

    struct Stack* temp = top;
    while (temp != NULL) {
        int currentLength = strlen(temp->data.name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(longestName, temp->data.name);
        }
        temp = temp->next;
    }

    if (maxLength > 0) {
        printf("The longest name in the list: %s\n", longestName);
        printf("Length: %d\n", maxLength);
    } else {
        printf("No names found in the list\n");
    }
}

int main() 
{
    struct Stack* top = NULL; // Initialize an empty stack
    char names[][50] = {
        "Zeynep", "Elif", "Ayşe", "Fatma", "Esra", "Merve", "Dilarah", "Selma", 
        "Leyla", "Cemre", "Aslı", "Seda", "Melis", "İrem", "Selin", "Gizem", 
        "Ezgi", "Deniz", "Beren"
    };

    // Push names onto the stack
    for (int i = 0; i < sizeof(names) / sizeof(names[0]); ++i) {
        struct Student student;
        strcpy(student.name, names[i]);
        student.rollNumber = 2210213532 + i; // Assign a roll number (you can modify this logic)
        push(&top, student);
    }

    // Print the record with the longest name in the list
    printLongestName(top);

    // Pop the stack elements to free the memory
    while (top != NULL) {
        pop(&top);
    }

    return 0;
    
}
