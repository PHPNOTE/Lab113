#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int count;
    cin >> count;

    vector<int> all(count);

    for(int i = 0; i < count; i++){
        int temp;
        cin >> temp;
        all[i] = temp;
    }

    sort(all.begin(), all.end());

    int last_pri = all[all.size() - 1];
    if(last_pri == all.size()){
        return 0;
    }
    
    vector<int> allMissing;

    for(int i = 1; i <= last_pri; i++){
        if(!binary_search(all.begin(), all.end(),i)){
            allMissing.push_back(i);
        }
    }

    for(int i: allMissing){
        if((i%2)==1){
            cout << i << " ";
        }
    }
    
    cout << endl;

    for(int i: allMissing){
        if((i%2)==0){
            cout << i << " ";
        }
    }

    // for (int i = 0; i < count; ++i) {
    //     cout << all[i];
    // }


}