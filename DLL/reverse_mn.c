#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void reverseFromMtoN(struct Node** head, int M, int N) {
    if (M >= N) return;
    struct Node* mNode = *head;
    struct Node* nNode = *head;
    for (int i = 1; i < M && mNode != NULL; i++) mNode = mNode->next;
    for (int i = 1; i < N && nNode != NULL; i++) nNode = nNode->next;
    if (mNode == NULL || nNode == NULL) return;

    struct Node* temp = mNode;
    struct Node* nextNode;
    while (temp != nNode->next) {
        nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode;
        temp = nextNode;
    }

    if (mNode->prev != NULL) mNode->prev->next = nNode;
    else *head = nNode;

    if (nNode->next != NULL) nNode->next->prev = mNode;

    struct Node* tempPrev = mNode->prev;
    mNode->prev = nNode->next;
    nNode->next = tempPrev;
}

int main() {
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = NULL;
    node2->data = 20;
    node2->next = node3;
    node2->prev = node1;
    node3->data = 30;
    node3->next = NULL;
    node3->prev = node2;

    reverseFromMtoN(&head, 1, 3);
    return 0;
}
