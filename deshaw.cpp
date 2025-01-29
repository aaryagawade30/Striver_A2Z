#include <bits/stdc++.h>
using namespace std;

int getMinDecrement(vector<int> arr, int max_moves) {
    int n = arr.size();
    int i = 0, dec = 1;
    while(arr[i] > 0) {
        arr[i] - 1;
        i++;
    }
    cout<< arr;
    return 0;
    
    
}
int main() {
    vector<int> arr = {1, 2, 3};
    cout<<getMinDecrement(arr, 4);
    return 0;
}
