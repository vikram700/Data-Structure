

/* 
   First Application : Effective computation of large exponents modulo a number
   
   This code simply find the a^n mod m when a and n is too large with O(logN) complexity.
   
   Problem: Compute x^n mod m. This is a very common operation. For instance it is used in computing the modular           multiplicative inverse.
 */

#include<bits/stdc++.h>

using namespace std;

long long power(long long a, long long b, long long mod){
    a%=mod;
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % mod;

        a = a * a % mod;

        b >>= 1;
    }
    return res;
}

int main(){
    cout<<"enter two no : "<<"\n";
    long long a, n; cin>>a>>n;
    long long mod = (long long)1e9 + 7;
    long long res = power(a, n, mod);

    cout<<"result is : "<<res<<"\n";

    return 0;
}
