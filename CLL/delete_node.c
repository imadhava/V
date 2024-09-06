#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
    struct CNode* prev;
};

void deleteCNode(struct CNode** head, int key) {
    if (*head == NULL) return;

    struct CNode* temp = *head;
    struct CNode* toDelete = NULL;

    do {
        if (temp->data == key) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != *head);

    if (toDelete == NULL) return;

    if (toDelete->next == toDelete) {
        *head = NULL;
        free(toDelete);
        return;
    }

    if (toDelete == *head) *head = toDelete->next;

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    free(toDelete);
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

    deleteCNode(&head, 10);

    if (head) {
        struct CNode* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    } else {
        printf("List is empty\n");
    }
    return 0;
}
