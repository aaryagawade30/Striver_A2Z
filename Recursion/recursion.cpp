#include <bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n){
    if (ind == n) {
        for(auto it: ds) {
            cout << it << " ";
        }
        if (ds.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    printF(ind +1, ds, arr, n); // not take index in subseq condn
    ds.push_back(arr[ind]);
    printF(ind +1, ds, arr, n); // take conds
    ds.pop_back();
    
}

void printSum(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if(ind == n) {
        if(s == sum) {
            for(auto it: ds) cout << it << " ";
            cout<< endl;
        }
        
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];
    printSum(ind +1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();

    printSum(ind +1, ds, s, sum, arr, n);
}


bool printSumOnce(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if(ind == n) {
        if(s == sum) {
            for(auto it: ds) cout << it << " ";
                cout<< endl;
                return true;
        }
        
        return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printSumOnce(ind +1, ds, s, sum, arr, n)== true) return true;
    s -= arr[ind];
    ds.pop_back();

    if(printSumOnce(ind +1, ds, s, sum, arr, n)== true) return true;
    return false;
}

int printSumCount(int ind, int s, int sum, int arr[], int n) {
    if(ind == n) {
        if(s == sum) {
            return 1;
        }
        else return  0;
    }

    s += arr[ind];
    int l = printSumCount(ind +1, s, sum, arr, n);
    s -= arr[ind];

    int r = printSumCount(ind +1, s, sum, arr, n);

    return l + r
}


int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    //printF(0, ds, arr, n);
    printSumOnce(0, ds, 0, sum, arr, n);
    printSumCount(0, 0, sum, arr, n);
    return 0;
}