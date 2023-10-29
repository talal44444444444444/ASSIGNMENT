#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void push(struct Stack *s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = item;
    } else {
        printf("Stack is full!\n");
    }
}

int pop(struct Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty!\n");
        return -1;
    }
}

void sortStack(struct Stack *s) {
    int tempStack[MAX_SIZE];
    int tempTop = -1;

    while (s->top >= 0) {
        int item = pop(s);

        while (tempTop >= 0 && item > tempStack[tempTop]) {
            push(s, tempStack[tempTop--]);
        }

        tempStack[++tempTop] = item;
    }

    while (tempTop >= 0) {
        push(s, tempStack[tempTop--]);
    }
}

int main() {
    srand(time(0));
    struct Stack stack;
    stack.top = -1;

    // Push 100 randomly generated numbers into the stack
    for (int i = 0; i < 100; ++i) {
        int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
        push(&stack, randomNumber);
    }

    printf("Original Stack: ");
    for (int i = 0; i <= stack.top; ++i) {
        printf("%d", stack.items[i]);
        if (i < stack.top) {
            printf("->");
        }
    }
    printf("\n");

    // Sort the stack
    sortStack(&stack);

    printf("Sorted Stack (Largest to Smallest): ");
    for (int i = 0; i <= stack.top; ++i) {
        printf("%d", stack.items[i]);
        if (i < stack.top) {
            printf("->");
        }
    }
    printf("\n");

    return 0;
}
