#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __Point{
    double x;
    double y;
}Point;

int main(){
    int count;
    printf("Number of Points: ");
    scanf("%d", &count);
    Point points[count];

    for(int i = 0; i < count; i++){
        printf("P%d.X: ",i+1);
        scanf("%lf", &points[i].x);
        printf("P%d.Y: ",i+1);
        scanf("%lf", &points[i].y);
    }

    printf("Length:\n");
    for(int i = 0; i < count-1; i++){
        double dX, dY;
        dX = points[i].x - points[i+1].x;
        dY = points[i].y - points[i+1].y;

        double distance = sqrt(pow(dX,2) + pow(dY, 2));

        printf("Length from P%d(%.2lf, %.2lf) to P%d(%.2lf, %.2lf) is %.2lf\n", i+1, points[i].x, points[i].y, i+2, points[i+1].x, points[i+1].y, distance);
    }

}