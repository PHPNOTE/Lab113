#include <iostream>
#include <vector>
using namespace std;

vector<int> compareTriplets(vector<int> arrA, vector<int> arrB){
    vector<int> result(2);
    result[0] = 0;
    result[1] = 0;
    for(int i = 0; i < 3; i++){
        if (arrA[i] > arrB[i]){
            result[0] += 1;
        }else if (arrB[i] > arrA[i]){
            result[1] += 1;
        }
    }
    return result;
}





int main() {
    int n = 3;
    vector<int> arrA(n), arrB(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arrA[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arrB[i] = temp;
    }

    vector<int> result = compareTriplets(arrA, arrB);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
