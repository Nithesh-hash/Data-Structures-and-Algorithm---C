#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == front) {
        printf("The Queue is full. Queue Overflow occurs\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("The Queue is empty. Queue Underflow occurs\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("The Queue is empty\n");
    } else {
        printf("The front value is %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("The Queue is empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    do {
        printf("\n1. Enqueue\t2. Dequeue\t3. Peek\t4. Display\t5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
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
                break;
        }
    } while (choice != 5);

    return 0;
}
