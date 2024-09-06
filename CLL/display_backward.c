#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
    struct CNode* prev;
};

void displayCBackward(struct CNode* head) {
    if (head == NULL) return;
    struct CNode* temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

int main() {
    struct CNode* head = NULL;
    struct CNode* node1 = (struct CNode*)malloc(sizeof(struct CNode));
    struct CNode* node2 = (struct CNode*)malloc(sizeof(struct CNode));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = node2;
    node2->data = 20;
    node2->next = node1;
    node2->prev = node1;

    displayCBackward(head);
    return 0;
}
