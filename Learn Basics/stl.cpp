#include <bits/stdc++.h>
using namespace std;

// sort it accord to second elem
// if sec elem is same, then sort
// it accord to first elem but in descending

pair <int, int> a[] = {{1, 2}, {1,2}, {4, 1}};

bool comp(pair <int, int> p1, pair <int, int> p2){
    if (p1.second < p2.second) return true;
    if (p1. second > p2.second) return false;
    // if they are same
    
    if (p1.first > p2.first) return true;
    return false;
}


int main(){
    sort(a, a + 2, comp);


    return 0;
}