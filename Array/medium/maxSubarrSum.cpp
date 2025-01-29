#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxi = INT_MIN;
        for(auto it: nums) {
            sum += it;
            maxi = max(sum, maxi);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }

int main() {

    return 0;
}