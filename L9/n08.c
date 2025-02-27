#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _product {
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++) {
        printf("%-20s|%6d|%10.2lf\n",
            stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void reportStock(char *filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        return;
    }
    int count = 0;
    fscanf(file, "%d\n", &count);
    if(count == 0){
        return;
    }

    Product all[count];
    char buffer[100];
    char temp1[50], temp2[50];
    char name[30];
    int amount;
    double price;
    int last = 0;
    int find ;

    while((fgets(buffer, sizeof(buffer), file))){
        sscanf(buffer, "%8[^,],%8[^,],%[^,],%d,%lf", temp1, temp2, name, &amount, &price);
        find = 0;
        for (int i = 0; i < last; i++ ){
            if(strcmp(name,all[i].name) == 0){
                all[i].amount += amount;
                all[i].totalCost += price;
                find = 1;
                break;
            }
        }

        if(find == 0){
            strcpy(all[last].name,name);
            all[last].amount = amount;
            all[last].totalCost = price ;
            last++;
        }

    }

    fclose(file);
    printStock(all,last);

}

int main()
{
    char filename[20];
    scanf("%s", filename);
    reportStock(filename);
}