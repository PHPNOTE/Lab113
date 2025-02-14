#include <stdlib.h>
#include <stdio.h>

struct __student{
    long long id;
    float mid;
    float final;
};

typedef struct __student student;

void calculateGrade(student a){
    if( a.mid + a.final >= 80){
        printf("Student ID %lld receives grade A.\n", a.id);
    }else if(a.mid + a.final >= 70 && a.mid + a.final < 80){
        printf("Student ID %lld receives grade B.\n", a.id);
    }else if(a.mid + a.final >= 60 && a.mid + a.final < 70){
        printf("Student ID %lld receives grade C.\n", a.id);
    }else if(a.mid + a.final >= 50 && a.mid + a.final < 60){
        printf("Student ID %lld receives grade D.\n", a.id);
    }else {
        printf("Student ID %lld receives grade F.\n", a.id);
    }
}

int main(){
    student ls[5];
    for (int i = 0; i < 5; i++){
        printf("Enter Student ID: ");
        scanf("%lld", &ls[i].id);
        printf("Enter Student Midterm: ");
        scanf("%f", &ls[i].mid);
        printf("Enter Student Final: ");
        scanf("%f", &ls[i].final);
    }
    for (int i = 0; i < 5; i++){
        calculateGrade(ls[i]);
    }
}