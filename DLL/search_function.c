#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
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

    struct Node* found = search(head, 20);
    if (found) printf("Found: %d\n", found->data);
    else printf("Not Found\n");
    return 0;
}
