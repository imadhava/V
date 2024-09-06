#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
    struct CNode* prev;
};

void deleteNodesGreaterThan(struct CNode** head, int value) {
    if (*head == NULL) return;

    struct CNode* current = *head;
    struct CNode* nextNode;

    do {
        nextNode = current->next;
        if (current->data > value) {
            if (current->next == current) {
                free(current);
                *head = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == *head) *head = current->next;

            free(current);
        }
        current = nextNode;
    } while (current != *head);
}

int main() {
    struct CNode* head = (struct CNode*)malloc(sizeof(struct CNode));
    struct CNode* node1 = (struct CNode*)malloc(sizeof(struct CNode));
    struct CNode* node2 = (struct CNode*)malloc(sizeof(struct CNode));
    head->data = 10;
    head->next = node1;
    head->prev = node2;
    node1->data = 25;
    node1->next = node2;
    node1->prev = head;
    node2->data = 20;
    node2->next = head;
    node2->prev = node1;

    deleteNodesGreaterThan(&head, 15);

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
