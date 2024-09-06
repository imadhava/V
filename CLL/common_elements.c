#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printCommonElements(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        } else {
            printf("%d ", head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    printf("\n");
}

int main() {
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 10;
    head1->next = NULL;
    head2->data = 10;
    head2->next = NULL;

    printCommonElements(head1, head2);
    return 0;
}
