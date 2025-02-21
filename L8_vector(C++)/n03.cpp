#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr){
    int len = arr.size();
    int sum_down = 0, sum_up = 0;
    for(int i = 0, j = len -1; i < len; i++, j--){
        sum_down += arr[i][i];
        sum_up += arr[i][j];
    }
    int result = abs(sum_down - sum_up);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i].resize(n);
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int result = diagonalDifference(arr);
    cout << result << endl;
    return 0;
}