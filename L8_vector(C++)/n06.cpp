#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int birthdayCakeCandles(vector<int> candles){
    int result = 0;
    int max = 0;
    sort(candles.begin(), candles.end());
    max = candles[candles.size() - 1];
    for(int i = 0; i < candles.size(); i++){
        if(candles[i] == max){
            result++;
        }
    }
    return result;
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

    int result = birthdayCakeCandles(ar);
    cout << result << endl;
    return 0;
}