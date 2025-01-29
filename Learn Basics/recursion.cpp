#include<bits/stdc++.h>
using namespace std;

 // print 1 to n
 void num(int i,int n){
    if(i > n){
        return ;
    }

    cout<<i << " ";
    num(i +1, n);   //tc = O(n), sc = O(n)

 }

 //backtracking
 void num_back(int i, int n){
    if (i < 1){
        return ;
    }
    
    num_back(i -1, n);
    cout<<i<<" ";
 }

 //sum of n nums using paramaterized func
 void sum_parameter(int i, int sum){

    if (i < 1){
        cout<<sum;
        return ;
    }

    sum_parameter(i -1, sum + i);
 }

 //functional recursion
 int sum_functional(int n){
    if(n == 0) return 0;
    return n + sum_functional(n - 1);
 }

 int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
 }

 void reverse_arr(int i, int arr[], int n){
   if ( i >= n / 2) return;
   swap(arr[i], arr[n -i -1]);
   reverse_arr(i +1, arr, n);

 }

 bool rev_s(int i, string &s){
   if ( i >= s.size()/2) return true;
   if (s[i] != s[s.size() -i -1]) return false;
   return rev_s(i + 1, s);
 }

 int fib(int n){
   if (n <= 1) return n;
   return fib(n -1) + fib(n -2);
 }




int main(){

    //num(1, 5);
    //num_back(5, 5);
    //sum_parameter(3, 0);
    //cout<<sum_functional(3);
    //cout<<factorial(4);

    /*int n;
    cout<<"size: ";
    cin>>n;
    int arr[n];
    cout<<"elements: ";
    for(int i = 0; i < n; i++) cin>>arr[i];
    reverse_arr(0, arr, n);
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";*/
    
   string s = "madam";
   cout<<rev_s(0, s);
   /*int n;
   cin>>n;
   for(int i = 0; i < n; i++){
      cout<<fib(i)<<" ";
   }
   */
    return 0;
}