#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

void push(int x) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct StackNode* temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        struct StackNode* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
