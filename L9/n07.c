#include <stdio.h>

double findAverage(char *filename)
{
    FILE* file = fopen(filename, "r");
    if(!file){
        perror("Cannot open file to read");
        return 0;
    }

    double sum = 0,num;
    int count = 0;

    while (fscanf(file, "%lf", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(file);

    return sum / count;

}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    average = findAverage(filename);
    printf("Average score is %.4lf\n", average);
}