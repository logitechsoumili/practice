#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(l1 && l2) {
        if(l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1) ? l1 : l2;

    return dummy.next;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(struct Node* head) {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);
    printf("List 1: ");
    printList(l1);

    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);
    printf("List 2: ");
    printList(l2);

    struct Node* merged = mergeSortedLists(l1, l2);
    printf("Merged list: ");
    printList(merged);

    struct Node* reversed = reverseList(merged);
    printf("Reversed merged list: ");
    printList(reversed);

    return 0;
}
