#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[a] = i; //key = a, val = index
        }
        return {0};
    }

// without using map
// 2 pointer approach
string twoSumStr(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (left < right) {
        int sum = nums[left] + nums[right];
        if(sum == target) return "YES";
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}

int main() {
    vector<int> nums = {1, 3, 4, 5, 6, 4};
    int target = 7;
    cout<<twoSumStr(nums = nums, target = target);
    return 0;
}