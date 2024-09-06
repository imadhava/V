#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteAdjacentDuplicates(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    do {
        if (temp->next != *head && temp->data == temp->next->data) {
            struct Node* dup = temp->next;
            temp->next = dup->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    } while (temp->next != *head);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node1;
    node1->data = 10;
    node1->next = node2;
    node2->data = 20;
    node2->next = head;

    deleteAdjacentDuplicates(&head);

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return 0;
}
