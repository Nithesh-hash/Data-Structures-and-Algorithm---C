#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *new_node = NULL;
int count = 0;

void InsertAtBeginning() {
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

void InsertAtEnd() {
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
    }
}

void InsertAtAnyPosition() {
    int pos;
    temp = head;
    count = 0;
    if (head != NULL) {
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
    } else if (pos == 1) {
        InsertAtBeginning();
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void DeleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        struct node *del = head;
        temp->next = head->next;
        head = head->next;
        free(del);
        printf("Deleted from beginning.\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
    } else {
        struct node *prev = NULL;
        temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
        printf("Deleted from end.\n");
    }
}

void DeleteAtAnyPosition() {
    int pos;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
    } else if (pos == 1) {
        DeleteAtBeginning();
    } else {
        struct node *prev = NULL;
        temp = head;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("Deleted at position %d.\n", pos);
    }
}

void Display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int ch = 1, data, option;

    while (ch) {
        printf("\n1. Insert\n2. Delete\n3. Display\nEnter choice: ");
        scanf("%d", &option);

        if (option == 1) {
            new_node = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &data);
            new_node->data = data;
            new_node->next = NULL;

            printf("Insert at:\n1. Beginning\n2. End\n3. Any Position\nChoice: ");
            scanf("%d", &option);

            switch (option) {
                case 1: InsertAtBeginning(); break;
                case 2: InsertAtEnd(); break;
                case 3: InsertAtAnyPosition(); break;
                default: printf("Invalid choice\n");
            }
        } else if (option == 2) {
            printf("Delete from:\n1. Beginning\n2. End\n3. Any Position\nChoice: ");
            scanf("%d", &option);

            switch (option) {
                case 1: DeleteAtBeginning(); break;
                case 2: DeleteAtEnd(); break;
                case 3: DeleteAtAnyPosition(); break;
                default: printf("Invalid choice\n");
            }
        } else if (option == 3) {
            Display();
        } else {
            printf("Invalid main choice.\n");
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);
    }

    return 0;
}
