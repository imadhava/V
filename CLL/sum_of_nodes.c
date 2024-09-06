#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int sumCircularList(struct Node* head) {
    if (head == NULL) return 0;

    int sum = 0;
    struct Node* temp = head;

    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);

    return sum;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node1;
    node1->data = 20;
    node1->next = node2;
    node2->data = 30;
    node2->next = head;

    int sum = sumCircularList(head);
    printf("Sum of Circular List: %d\n", sum);
    return 0;
}
