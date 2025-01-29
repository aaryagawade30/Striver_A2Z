#include<bits/stdc++.h>
using namespace std;

// numbers
/*
int main(){
    int n;
    cout << "size: ";
    cin>>n;
    cout << "elements: ";
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    //precompute
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;

    }

    int query;
    cout << "query no: ";
    cin>>query;
    cout << "query elements: ";
    while(query --){
        int num; 
        cin >> num;
        //fetch
        cout<< hash[num] <<endl;
    }


    return 0;
}
*/

//string
/*int main(){
    string s;
    cout<<"String: ";
    cin>>s;

    //precompute
    int hash[26] = {0};                  
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a'] += 1;

    }
    //we take size 26 as we know, it is only for small letters s[i] - 'a' and ch - 'a'
    //there are total 256 char, so it includes A  and a  so s[i] and ch is operated


    int q;
    cout<<"total queries: ";
    cin>>q;
    cout << "query elements: ";
    while(q--){
        char ch;
        cin >> ch;

        //fetch
        cout << hash[ch - 'a'] << endl;
    }


    return 0;

}
*/

// hash map

 int main(){
    int n; 
    cout<<"Size: ";
    cin >> n;
    int arr[n];
    cout << "elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i]; 
    
    //precompute
    map <int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // iterate over map
    for(auto it: mpp){
        cout << it.first <<" --> " << it.second << endl;
    }

    int q;
    cout << "Query size: ";
    cin >> q;
    cout << "queries: ";
    while (q--) {
        int num; 
        cin >> num;

        //fetch
        cout << mpp[num] <<endl;
    }


    return 0;
 }

