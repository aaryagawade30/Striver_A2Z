#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int target) 
{
    int low = 0, high = n -1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) /2;
        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid -1;
        }
        else low = mid +1;
    }
    return ans;
}

int upperBound(vector<int> arr, int n, int target) 
{
    int low = 0, high = n -1;
    int ans = n;
    int mid = (low + high) /2;
    if (arr[mid] > target)
    {
        ans = mid;
        // look for small index on left
        high = mid -1;
    }
    else low = mid +1; // look on right
}

pair<int, int> low_up(vector<int> arr, int n, int target)
{
    int lb = lowerBound(arr, n, 5);
    if (lb == n || arr[lb] != target) return {-1, -1};
    return {lb, upperBound(arr, n, target) -1};
}

int main()
{
    vector<int> arr = {2,3, 5, 5, 5, 7, 1};
    int n = 5;
    int target = 5;
    cout << low_up(arr, n, target).first<< " "<< low_up(arr, n, target).second;
    return 0;
}

