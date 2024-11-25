#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*tail) {
        (*tail)->next = newNode;
    }
    *tail = newNode;

    if (*head == NULL) {
        *head = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("queue is empty\n");
        return -1;
    }

    struct node *temp = *head;
    int deletedData = temp->data;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);
    return deletedData;
}

void printQueue(struct node *head) {
    if (head == NULL) {
        printf("empty\n");
        return;
    }

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *tail = NULL;
    int choice, value;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (scanf("%d", &value) != 1 || value <= 0) {
                    printf("invalid input\n");
                    printQueue(head);
                    while (getchar() != '\n');
                    break;
                }
                addq(&head, &tail, value);
                break;
            case 2:
                value = delete(&head, &tail);
                if (value != -1) {
                    printf("deleted: %d\n", value);
                }
                break;
            case 3:
                printQueue(head);
                break;
            case 4:
                printf("exit.\n");
                return 0;
            default:
                printf("no choice\n");
        }
    }
    return 0;
}

