#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printMiddleN(struct Node* head, int N) {
    if (head == NULL || N <= 0) return;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* start = slow;
    for (int i = 0; i < N && start != NULL; i++) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
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
    node2->next = head;

    printMiddleN(head, 2);
    return 0;
}
