#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge the two sorted subarrays
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy any remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int>& arr, int low, int high) {
    if (low == high) return;
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr, int n) {
    mS(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {14, 4, 0, 6, 8, 12, 56, 3, 4};  // Define the array as a vector
    mergeSort(arr, arr.size());  // Sort the array
    for (int i = 0; i < arr.size(); i++) {  // Print the sorted array
        cout << arr[i] << " ";
    }
    return 0;
}
