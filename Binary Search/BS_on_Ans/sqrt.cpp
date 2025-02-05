#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int low = 1, high = n;
        long long int ans = 1;
        
        while (low <= high) {
            long long int mid = (low + high) /2;
            if (mid *  mid <= n) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid -1;
        }
        return high;
    }

int main()
{

    return 0;
}