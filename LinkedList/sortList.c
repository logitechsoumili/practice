#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head){
    struct Node* ptr = head;
    while (ptr){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* sortList(struct Node* head){
    struct Node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1){
        ptr2 = ptr1->next;
        while (ptr2){
            if (ptr1->data > ptr2->data){
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
}

int main(){
    struct Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    
    display(head);
    head = sortList(head);
    display(head);
    
    return 0;
}
