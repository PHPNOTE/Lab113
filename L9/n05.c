#include <stdio.h>
#include <stdlib.h>

typedef struct __Node{
    int value;
    struct __Node* next;
} node;

void printList(node *pList) {
    node* curr = pList;

    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
}

void insertNode(node** head, int data){
    node* newnode = (node*)malloc(sizeof(node));
    node* curr = *head;
    node* prev = NULL;
    newnode->value = data;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
        return; 
    }

    while (curr != NULL){
        if(curr->value > data && prev == NULL){
            newnode->next = curr;
            *head = newnode;
            return;
        }

        if(curr->value > data){
            prev->next = newnode;
            newnode->next = curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = newnode;
}

int main() {
    int i, value;
    node *pList=NULL;
    
    for (i = 0; i < 10; i++) {
        scanf(" %d", &value);
        insertNode(&pList, value);
    }

    printList(pList);
    }