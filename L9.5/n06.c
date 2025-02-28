#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct __node{
    int data;
    struct __node *next;
}node;

void print(node* head){
    if(head == NULL){
        printf("[ ]\n");
        return;
    }

    node *curr = head;
    printf("[ ");
    while( curr != NULL ){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("]\n");
}

void insert(node** head,int insdata){
    node* newnode = (node*)malloc(sizeof(node));
    node* curr = *head;
    node* prev = NULL;
    newnode->data = insdata;
    newnode->next = NULL;

    if((*head) == NULL){
        *head = newnode;
        return;
    }

    while (curr != NULL){
        if(curr->data > insdata && prev == NULL){
            newnode->next = curr;
            *head = newnode;
            return;
        }

        if(curr->data > insdata){
            prev->next = newnode;
            newnode->next = curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = newnode;

}

void delete(node** head, int deldata){
    if (*head == NULL){
        return;
    }

    node* newnode = (node*)malloc(sizeof(node));
    node* curr = *head;
    node* prev = NULL;

    while (curr != NULL && curr->data == deldata) {
        *head = curr->next; 
        curr = *head;
    }


    while(curr != NULL){
        if(curr->data == deldata){
            prev->next = curr->next;
            curr = prev->next;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

int main(){
    char comm[50];
    node* head = NULL;
    
    while(1){
        printf("input> ");
        fgets(comm,50,stdin);
        char tmpcomm;
        int cur_data;

        if(strlen(comm) == 2){
            sscanf(comm, "%c\n", &tmpcomm);
            if(tmpcomm == 'p'){
                //printf("called printlinklist\n");
                print(head);
            }else if(tmpcomm == 'q'){
                //printf("break");
                break;
            }
        }else if(strlen(comm) != 2){
            sscanf(comm,"%c %d\n", &tmpcomm, &cur_data);
            if(tmpcomm == 'i'){
                //printf("called insert\n");
                insert(&head, cur_data);
            }else if(tmpcomm == 'd'){
                //printf("called delete\n");
                delete(&head, cur_data);
            }
        }
    }
}