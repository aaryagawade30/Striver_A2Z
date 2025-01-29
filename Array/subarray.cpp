#include<bits/stdc++.h>
using namespace std;

int longestSubArrWithSumK (int k, vector<int> &a) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        if(sum == k) {
            maxLen = max(maxLen, i + 1);

        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//tc = O(2N) sc = O(1)
int longestSubArrWithSumK_positives_zeroes(long long k, vector <int> &a) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}

int main(){
    vector<int> a = {1, 2, 5, 4, 1, 3, 1, 1, 2, 1};
    cout<<longestSubArrWithSumK(4, a);
    cout<<longestSubArrWithSumK_positives_zeroes(4, a);
    return 0;
}