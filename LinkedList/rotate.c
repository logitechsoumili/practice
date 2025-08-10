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

void printList(struct Node* head) {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* rightRotate(struct Node* head, int k){
    if (head == NULL || head->next == NULL || k == 0) return head;
    
    int len = 1;
    struct Node* curr = head;
    while (curr->next){
        curr = curr->next;
        len++;
    }
    curr->next = head;
    
    k = k % len;
    struct Node* newTail = head;
    for (int i = 1; i < len - k; i++){
        newTail = newTail->next;
    }
    head = newTail->next;
    newTail->next = NULL;
    return head;
}

struct Node* leftRotate(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int len = 1;
    struct Node* curr = head;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    curr->next = head;
    
    k = k % len;
    struct Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }
    head = newTail->next;
    newTail->next = NULL;
    return head;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("List before rotation: ");
    printList(head);
    
    head = rightRotate(head, 2);
    printf("List after right rotation: ");
    printList(head);
    
    head = leftRotate(head, 2);
    printf("List after left rotation: ");
    printList(head);

    return 0;
}
