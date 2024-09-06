#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int countOddKeys(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 != 0) count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = NULL;
    node2->data = 15;
    node2->next = NULL;
    node2->prev = node1;

    printf("Count of Odd Keys: %d\n", countOddKeys(head));
    return 0;
}
