#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteGivenNode(struct Node* node) {
    if (node == NULL || node->next == NULL) return;

    struct Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node;
    node->data = 20;
    node->next = NULL;

    deleteGivenNode(head);  // Attempting to delete head as an example
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
