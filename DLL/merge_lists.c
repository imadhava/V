#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != NULL) tail->next = head1;
    else tail->next = head2;
    if (tail->next != NULL) tail->next->prev = tail;
    return dummy.next;
}

int main() {
    // Creating two sorted lists manually
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 10; head1->next = NULL; head1->prev = NULL;
    head2->data = 20; head2->next = NULL; head2->prev = NULL;

    struct Node* mergedHead = mergeSortedLists(head1, head2);
    while (mergedHead) {
        printf("%d ", mergedHead->data);
        mergedHead = mergedHead->next;
    }
    printf("\n");
    return 0;
}
