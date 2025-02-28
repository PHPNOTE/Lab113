#include <iostream>

using namespace std;

int main(){
    char name[30], output[500];
    double salary, sale[12], sum = 0;

    cin >> name >> salary;
    sum += salary * 12;

    for(int i = 0; i < 12; i++){
        cin >> sale[i];
        sum += (sale[i] * 0.15);
    }

    sprintf(output, "%s %.2lf", name, sum);
    cout << output;
    

}