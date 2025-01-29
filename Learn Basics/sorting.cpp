#include <bits/stdc++.h>
using namespace std;


void selection(int n, int a[]){
    int mini, temp;
    for (int i = 0; i <= n -2; i++){
        mini = i;
        for (int j = i; j <= n -1; j++){
            if (a[j] < a[mini]){
                mini = j;
                
            }
        }
        temp = a[mini];
            a[mini] = a[i];
            a[i] = temp;
    }
 
}

void bubble(int n, int a[]){
    int temp;
    for(int i = n -1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j <= i -1; j++){
            if (a[j] > a[j +1]){
                temp = a[j];
                a[j] = a[j +1];
                a[j + 1] = temp;
                int didSwap = 1;
            }
        }
        if (didSwap == 0) break;
    }
}

void insertion(int n,  int a[]){
    int temp;
    for(int i = 0; i <= n -1; i++){
        int j = i;
        while (j > 0 && a[j -1] > a[j]){
            temp = a[j -1];
            a[j -1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

int main(){
    int n = 5;
    int a[n] = {23, 45, 66, 3, 8};
    insertion(n, a);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    

    return 0;
}