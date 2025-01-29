#include<bits/stdc++.h>
using namespace std;

void divisors(int n){

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cout<< i<< ' ';

            if(n / i != i){
                cout<< n / i<<' ';
            } 
        }
    }
}


void primes(int n){
    int count = 0;
    // ( i <= n / 2)
    for(int i = 2; i * i <= n; i++){    // tc = O(sqrt(n))

        if(n % i == 0) count += 1;break;

    }
    cout<<count<<'\n';
    if(count == 1){
        cout<<n<<" is not prime\n";
    }

    else{
        cout<<n<<" is prime\n";
    }

}

int gcd_euclid(int a, int b){

    while( a > 0 && b > 0){

        if(a > b) a = a % b;
        else      b = b % a;
    }

    if(a == 0) return b;
    else return a;

}

int main(){
    //divisors(36);
    //primes(7);
    cout<<gcd_euclid(12,9);


    return 0;
}