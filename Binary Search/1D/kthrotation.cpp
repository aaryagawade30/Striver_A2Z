#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0, high = n -1, ans = INT_MAX;
        int index = -1;
        
        while (low <= high) {
            int mid = (low + high) /2;
            
            if(arr[low] <= arr[high]) {
                if(arr[low] < ans) {
                    index = low;
                    ans = arr[low];
                }
                 break;
                
            }
            
            if (arr[low] <= arr[mid]) {
                low = mid +1;
                if (arr[low] < ans) {
                    index = low;
                    ans = min(ans, arr[low]);
                }
                
            
                
            }
            
            else {
                high = mid -1;
                if( arr[mid] < ans) {
                    index = mid;
                    ans = min(ans, arr[mid]);
                }
                
                
            }
        }
        
        //for(int i = 0; i < n; i++) {
         //   if (ans == arr[i]) return i;
        //}
        return index;
    }

int main()
{

    return 0;
}