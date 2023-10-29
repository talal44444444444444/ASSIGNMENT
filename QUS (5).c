#include <stdio.h>
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

// Function to search for a student by name using stack
void searchByName(struct Stack* top, const char* name) {
    struct Stack* temp = top;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Student found! Roll Number: %d\n", temp->data.rollNumber);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Student with name '%s' not found\n", name);
    }
}

int main() {
    // Create sample student records and push them onto the stack
    struct Stack* top = NULL;
    struct Student student1 = {"Elif", 2210213532};
    struct Student student2 = {"Zeynep", 2210213547};
    struct Student student3 = {"Ayşe", 2210213561};
    struct Student student4 = {"Fatma", 2210213579};
    struct Student student5 = {"Esra", 2210213583};
    struct Student student6 = {"Merve", 2210213592};
    struct Student student7 = {"Dilara", 2210213605};
    struct Student student8 = {"Selma", 2210213620};
    struct Student student9 = {"Leyla", 2210213637};
    struct Student student10 = {"Cemre", 2210213654};
    struct Student student11 = {"Aslı", 2210213669};
    struct Student student12 = {"Seda", 2210213682};
    struct Student student13 = {"Melis", 2210213695};
    struct Student student14 = {"İrem", 2210213709};
    struct Student student15 = {"Selin", 2210213723};
    struct Student student16 = {"Gizem", 2210213738};
    struct Student student17 = {"Ezgi", 2210213752};
    struct Student student18 = {"Nazlı", 2210213767};
    struct Student student19 = {"Deniz", 2210213781};
    struct Student student20 = {"Beren", 2210213796};


    push(&top, student1);
    push(&top, student2);
    push(&top, student3);
    push(&top, student4);
    push(&top, student5);
    push(&top, student6);
    push(&top, student7);
    push(&top, student8);
    push(&top, student9);
    push(&top, student10);
    push(&top, student11);
    push(&top, student12);
    push(&top, student13);
    push(&top, student14);
    push(&top, student15);
    push(&top, student16);
    push(&top, student17);
    push(&top, student18);
    push(&top, student19);
    push(&top, student20);
    
    

    // Search for a student by name
    char searchName[50];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);
    searchByName(top, searchName);

    // Pop the stack elements to free the memory
    while (top != NULL) {
        pop(&top);
    }

    return 0;
    
    // Function to delete the next node from the node with the searched student name
void deleteNextNode(struct Stack* top, const char* name) {
    struct Stack* temp = top;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            found = 1;
            if (temp->next != NULL) {
                struct Stack* nodeToDelete = temp->next;
                temp->next = temp->next->next; // Bypass the next node
                free(nodeToDelete); // Free the memory of the deleted node
                printf("Next node deleted successfully.\n");
            } else {
                printf("No next node to delete.\n");
            }
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Student with name '%s' not found\n", name);
    }
}

int main() {
    // ... (rest of the code remains the same) ...

    // Delete the next node from the node with the searched student name
    char searchName[50];
    printf("Enter the name of the student to search and delete the next node: ");
    scanf("%s", searchName);
    deleteNextNode(top, searchName);

    // Pop the stack elements to free the memory
    while (top != NULL) {
        pop(&top);
    }

    return 0;
    
    
}
