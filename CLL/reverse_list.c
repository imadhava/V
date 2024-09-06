#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct StackNode {
    struct Node* node;
    struct StackNode* next;
};

void push(struct StackNode** stack, struct Node* node) {
    struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newStackNode->node = node;
    newStackNode->next = *stack;
    *stack = newStackNode;
}

struct Node* pop(struct StackNode** stack) {
    if (*stack == NULL) return NULL;
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    struct Node* node = temp->node;
    free(temp);
    return node;
}

void reverseListUsingStack(struct Node** head) {
    struct StackNode* stack = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        push(&stack, current);
        current = current->next;
    }

    *head = pop(&stack);
    current = *head;

    while (stack != NULL) {
        current->next = pop(&stack);
        current = current->next;
    }

    current->next = NULL;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    reverseListUsingStack(&head);
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
