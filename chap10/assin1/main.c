#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("memory no\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top; 
    *top = newNode; 
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("empty .\n");
        return -1; 
    }
    struct node *temp = *top; 
    int poppedData = temp->data;
    *top = temp->next; 
    free(temp);
    return poppedData;
}

int main() {
    struct node *stack = NULL; 

    int choice, value;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (scanf("%d", &value) != 1 || value <= 0) {
                    printf("invalid input.\n");
                    while (getchar() != '\n'); 
                    break;
                }
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Pop: %d\n", value);
                }
                break;
            case 4:
                printf("exit.\n");
                return 0;
            default:
                printf("no\n");
        }
    }
    return 0;
}

