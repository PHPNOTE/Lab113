#include <stdio.h>
#include <stdlib.h>

#define SIZE  7

typedef struct nodeType {
    int   item;
    struct nodeType* next;
} Node;

void insert(Node** head, int insdata){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->item = insdata;
    newnode->next = NULL;

    if((*head) == NULL){
        *head = newnode;
        return;
    }

    newnode->next = (*head);
    (*head) = newnode;
}

void printHash(Node* head){
    Node* curr = head;
    for(int i = 0; i < SIZE; i++){
        printf("KEY%3d:", i);
        while(curr != NULL){
            if((curr->item)% SIZE == i){
                printf(" %d", curr->item);
            }
            curr = curr -> next;
        }
        curr = head;
        printf("\n");
    }
}

// int _strlen(char* str){
//     int result = 0;
//     for(int i = 0; str[i] != '\0'; i++){
//         result++;
//     }
//     return result;
// }

int main(){
    char comm[50];
    Node* head = NULL;
    int number;
    
    while(1){
        printf("input> ");
        fgets(comm,50,stdin);
        char tmpcomm;
        int cur_data;

        if (comm[0] == 'p')
            printHash(head);
        else if (comm[0] == 'q') 
            break;
        else if (comm[0] == 'a')
        {
            sscanf(comm + 2, "%d", &number);
            insert(&head,number);
        } 
    }
}
