#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void moveLastToFirst(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) return;

    struct Node* last = *head;
    struct Node* secondLast = NULL;

    while (last->next != *head) {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = *head;
    last->next = *head;
    *head = last;
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

    moveLastToFirst(&head);

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return 0;
}
