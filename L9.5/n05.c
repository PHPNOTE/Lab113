#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct good {
        char name[20];
        struct good *next;
}Good;

Good *start = NULL;

void add_good(Good *new_good){
        Good *current_good = start;
        Good *previous_good = NULL;
        while(current_good){
                previous_good = current_good;
                current_good = current_good->next;
        }
        if(previous_good != NULL){
                previous_good->next = new_good;
        }else{
                start = new_good;
        }
}
int print_all_goods(){
    Good* curr = start;
    int all = 0;
    while(curr != NULL){
        all +=1;
        printf("%s\n",curr->name);
        curr = curr->next;

    }
    return all;

}
int main(){
        char name[20];
        int price;
        Good *new_node;
        printf("Name: ");
        scanf("%20s",name);

        while(strcmp(name,"done")){
                new_node = (Good *)malloc(sizeof(Good));
                strcpy(new_node->name,name);
                new_node->next = NULL;
                add_good(new_node);

                printf("Name: ");
                scanf("%20s",name);
        }

        printf("total = %d\n",print_all_goods());
}