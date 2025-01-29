#include <bits/stdc++.h>
using namespace std;

int largest(int n, int arr[]) {
    int largestNum = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largestNum) largestNum = arr[i];
    }
    return largestNum;
}

int secondLargest (int n, int arr[]) {
    int largest = arr[0];
    int slargest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest) {
            slargest = arr[i];
        }
    }
    return slargest;
}

//check if array is sorted
bool check(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i -1]) {

            }
            else {
                return false;
            }
        }
        return true;
    }


//remove duplicates
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                nums[i +1] = nums[j];
                i++;
            }
            
        }
        return (i +1);
        
    }
};


// rotate array on left by d position

void leftRotate(int n, int d, int arr[]) {
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
}

//brute force
/*
void leftRotBf(int n, int d, int arr[]) {
    int temp;
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    int* j = 0;
    for (int i = n -d; i < n; i++){
        arr[i] = temp[j];
        j++;
    }

    for (int i = n - d; i < d; i++) {
        arr[i] = temp[i - (n - d)];
    }
}
*/

// reverse func
void rev( int start, int end, int arr[]) {
    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//brute force of move zero to end
vector<int> moveZero (int n, vector<int> a) {
    //step1
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if(a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    //s2
    int nz = temp.size();
    for(int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //s3
    for(int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}

//optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // This keeps track of the next position for a non-zero element

        // First loop: place all non-zero elements at the start of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // Second loop: fill the remaining positions with zeros
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};


//brute force for union of 2 arr
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }
        
        for(int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }
        
        vector<int> temp;
        for(auto it: st) {
            temp.push_back(it);
        }
        return temp;
    }
};

//{ Driver Code Starts.
/*
int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
*/

// optimal for intersection of 2 arr
vector<int> arrIntersection(vector<int> &A, int n, vector<int> &B, int m){
    int i = 0;
    int j = 0;

    vector<int> ans;
    while(i < n && j < m) {
        if(A[i] < B[j]){
            i++;
        }
        else if(A[i] > B[j]) {
            j++;
        }
        else {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

//missing num from sorted array
int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = (n *(n + 1)) / 2;
        int add = 0;
        for(int i = 1; i <= n; i++) {
            add += i;
        }
        return sum - add;
    }

int missingNumfromsorted(vector<int> &nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n -1; i++) {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i +1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

// findMaxConsecutiveOnes
int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else cnt = 0;
        }

        return maxi;
        
    }


int main() {
    int n = 6;
    int arr[n] = {1, 4, 54, 3, 7, 5};
    //cout<<secondLargest(n, arr);
    //leftRotate(n, 3, arr);
    vector<int> a = {1, 34, 0, 4, 0, 5, 0, 8};
    vector<int> result = moveZero(8, a);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] <<" ";
    }
    return 0;
}