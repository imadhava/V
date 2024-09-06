#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reversePairsIterative(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct Node* prev = NULL;
    struct Node* current = head;

    head = head->next;

    while (current != NULL && current->next != NULL) {
        struct Node* nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = current;

        if (prev != NULL) prev->next = nextNode;
        prev = current;
        current = current->next;
    }

    return head;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node1;
    node1->data = 20;
    node1->next = node2;
    node2->data = 30;
    node2->next = NULL;

    head = reversePairsIterative(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
