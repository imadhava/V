#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteAdjacentDuplicates(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct Node* dup = temp->next;
            temp->next = dup->next;
            if (dup->next != NULL) dup->next->prev = temp;
            free(dup);
        } else {
            temp = temp->next;
        }
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = NULL;
    node2->data = 10;
    node2->next = NULL;
    node2->prev = node1;

    deleteAdjacentDuplicates(&head);
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
