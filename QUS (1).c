#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

bool isOdd(int num) {
    return num % 2 != 0;
}

int main() {
    int num;

    printf("Enter numbers (-1 to stop):\n");

    while (true) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (isOdd(num)) {
            push(num); // Add odd numbers to the beginning
        } else {
            push(num); // Temporary store even numbers in the stack
        }
    }

    printf("Result: ");

    // Pop and print odd numbers from the stack (in reverse order)
    while (top >= 0 && isOdd(stack[top])) {
        printf("%d ", pop());
    }

    // Pop and print even numbers from the stack (in reverse order)
    while (top >= 0) {
        printf("%d ", pop());
    }

    return 0;
}
