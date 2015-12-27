#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node** list, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *list;
    (*list) = new_node;
}

void printList(struct node *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
}

void deleteNodeWithKey(struct node** head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    if(temp != NULL && temp->data == key) {
        (*head_ref) = temp->next;
        free(temp);
        return;    
    }
    while ( temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteWithPosition(struct node** head_ref, int pos) {
    struct node* temp = *head_ref;

    if(temp == NULL) {
        return;
    }

    if(pos == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for(int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        return;
    }

    struct node* next = temp->next->next;

    free(temp->next);
    temp->next = next;
    return;
}
int main() {
    struct node *head = NULL;
    push (&head, 2);
    push (&head, 3);
    push (&head, 1);
    push (&head, 7);
    printf("The list before deletion:\n");
    printList(head);
    deleteNodeWithKey(&head, 2);
    printf("The list after deleting 2:\n");
    printList(head);
    deleteWithPosition(&head, 2);
    printf("The list after deleting node in postion 2: \n");
    printList(head);
    return 0;
}
