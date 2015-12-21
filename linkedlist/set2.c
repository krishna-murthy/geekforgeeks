#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node* list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
}

void pushFirst(struct node** list, int newVal) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = newVal;
    new_node->next = *list;

    *list = new_node;
}

void insertAfter(struct node* prevNode, int newVal) {

    if(prevNode == NULL) {
        return;
     }

     struct node* new_node = (struct node*)malloc(sizeof(struct node));
     new_node->data = newVal;
     new_node->next = prevNode->next;
     prevNode->next = new_node;
}

void append(struct node* head, int newVal) {
    while(head->next != NULL) {
        head = head->next;
    }
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = newVal;
    new_node->next = NULL;

    head->next = new_node;
}

int main() {

    struct node *head = NULL;
    pushFirst(&head, 1);
    append(head,2); 
    insertAfter(head->next, 5);
    printList(head);

    return 0;

}
