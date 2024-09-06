#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeLoop(struct Node* loopNode, struct Node* head) {
    struct Node* ptr1 = head;
    struct Node* ptr2;

    while (1) {
        ptr2 = loopNode;

        // Find the node which connects back to ptr1
        while (ptr2->next != loopNode && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }

        // If ptr2 reached ptr1, then there's a loop
        if (ptr2->next == ptr1) {
            break;
        }

        ptr1 = ptr1->next;
    }

    // Remove the loop
    ptr2->next = NULL;
}

void detectAndRemoveLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {
            removeLoop(slow, head);
            return;
        }
    }
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
    node2->next = head; // Creating a loop for testing

    detectAndRemoveLoop(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
