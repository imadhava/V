#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* result = NULL;

    if (head1->data <= head2->data) {
        result = head1;
        result->next = mergeSortedLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeSortedLists(head1, head2->next);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));

    head1->data = 10;
    head1->next = node1;
    node1->data = 30;
    node1->next = NULL;

    head2->data = 20;
    head2->next = node2;
    node2->data = 40;
    node2->next = NULL;

    struct Node* mergedHead = mergeSortedLists(head1, head2);
    printList(mergedHead);

    return 0;
}
