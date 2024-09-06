#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void findSumOddEven(struct Node* head, int* oddSum, int* evenSum) {
    *oddSum = 0;
    *evenSum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) *evenSum += temp->data;
        else *oddSum += temp->data;
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    head = node1;
    node1->data = 10;
    node1->next = node2;
    node1->prev = NULL;
    node2->data = 15;
    node2->next = node3;
    node2->prev = node1;
    node3->data = 20;
    node3->next = NULL;
    node3->prev = node2;

    int oddSum, evenSum;
    findSumOddEven(head, &oddSum, &evenSum);
    printf("Odd Sum: %d, Even Sum: %d\n", oddSum, evenSum);
    return 0;
}
