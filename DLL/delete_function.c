#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else *head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = NULL;
    node2->data = 20;
    node2->next = NULL;
    node2->prev = node1;

    deleteNode(&head, 20);
    return 0;
}
