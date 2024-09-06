#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
    struct CNode* prev;
};

struct CNode* createCNode(int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertC(struct CNode** head, int data) {
    struct CNode* newNode = createCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct CNode* last = (*head)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

int main() {
    struct CNode* head = NULL;
    insertC(&head, 10);
    insertC(&head, 20);
    struct CNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return 0;
}
