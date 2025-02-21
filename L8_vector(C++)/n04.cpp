#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

void signedRatio(vector<int> arr){
    int len = arr.size();
    double plus = 0, minus = 0, zero = 0;
    for (int i = 0; i < len; i++){
        if (arr[i] > 0){
            plus += 1;
        }else if(arr[i] < 0){
            minus += 1;
        }else if(arr[i] == 0){
            zero += 1;
        }
    }
    plus /= len, minus /= len, zero /= len;
    cout << fixed << setprecision(6);
    cout << plus << endl;
    cout << minus << endl;
    cout << zero << endl;
}



int main() {
    int n;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        ar[i] = temp;
    }

    signedRatio(ar);
    return 0;
}