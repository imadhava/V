#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node1;
    node1->data = 20;
    node1->next = NULL;

    head = reverseRecursive(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
