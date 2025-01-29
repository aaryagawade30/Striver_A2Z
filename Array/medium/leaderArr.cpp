#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i = n -1; i >= 0; i--) {
            if(arr[i] > maxi) {
                ans.push_back(arr[i]);
            }
                // keep track of right max
                maxi = max(maxi, arr[i]);
            
        }
        
        // sort in descending order
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
}

int main() {

    return 0;
}