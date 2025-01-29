#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    
    for(int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }
    for(auto it: st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
             while(st.find(x +1) != st.end()) {
                x = x +1;
                cnt = cnt +1;
             }
             longest = max(longest, cnt);
        }
       
    }
    return longest;
}

vector<int> findOccurences(vector<int> &A) {
    vector<int> cnt_arr = {0};
    int cnt = 0;
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
       j++;
       if(A[i] == A[j]) {
           cnt++;
           cnt_arr.push_back(cnt);
       }
       cnt = 0; 
    }
    return cnt_arr;
}

int main() 
{
    vector<int> nums = {1, 2, 3, 2, 2, 3, 3, 2};
    cout << (longestConsecutive(nums));
    return 0;
}