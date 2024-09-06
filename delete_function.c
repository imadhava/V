#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void delete(Node **head, int key) {
    Node *temp = *head;
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}
