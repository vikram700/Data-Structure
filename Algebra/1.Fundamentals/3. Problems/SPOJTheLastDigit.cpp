#include<bits/stdc++.h>

using namespace std;

#define int long long

int power(int a, int b, int mod = 10){
    if(a == 0) return 0;
    if(b == 0) return 1;

    a %= mod;
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;

        b >>= 1;

        a = a * a % mod;
    }
    return res;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        int res = power(a, b);
        cout<<res<<"\n";
    }
    return 0;
}