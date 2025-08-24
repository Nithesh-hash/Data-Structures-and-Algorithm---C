#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack is full. Stack Overflow occurs\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty. Stack underflow occurs\n");
    } else {
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("The Stack is Empty\n");
    } else {
        printf("The top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("The Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Push\t 2. Pop\t 3. Peek\t 4. Display\t 5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.....\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
