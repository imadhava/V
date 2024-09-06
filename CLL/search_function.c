#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
    struct CNode* prev;
};

struct CNode* searchC(struct CNode* head, int key) {
    if (head == NULL) return NULL;
    struct CNode* temp = head;
    do {
        if (temp->data == key) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
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

    struct CNode* found = searchC(head, 20);
    if (found) printf("Found: %d\n", found->data);
    else printf("Not Found\n");
    return 0;
}
