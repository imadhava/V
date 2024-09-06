#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) return 1;

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prevSlow = NULL;

    while (fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow;
    prevSlow->next = NULL;
    secondHalf = reverseList(secondHalf);

    struct Node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = node1;
    node1->data = 10;
    node1->next = NULL;

    int result = isPalindrome(head);
    printf("Is Palindrome: %s\n", result ? "Yes" : "No");
    return 0;
}
