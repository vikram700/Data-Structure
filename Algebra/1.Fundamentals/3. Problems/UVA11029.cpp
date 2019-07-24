#include<bits/stdc++.h>

using namespace std;

int power(int a, int b, int mod){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;

        b >>= 1;

        a = a * a % mod;
    }
    return res%mod;
}

int main(){
    int t; cin>>t;
    while(t--){
      int n, k; cin>>n>>k;

      double x = k * log10(n);
      x = x - (int)x;
      double ans = pow(10, x);
      ans *= 100;
      cout<<(int)ans<<"...";

      printf("%03d",power(n, k, 1000));
      cout<<"\n";
    }
    return 0;
}