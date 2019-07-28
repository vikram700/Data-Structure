#include<bits/stdc++.h>

using namespace std;

#define int long long

int power(int a, int b, int mod){
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
    int x, al, n, mod;
    while(1){
      cin>>x>>al>>n>>mod;
      if(x == 0 && al == 0 && n == 0 && mod == 0) return 0;
      x--;

      int first = ((x % mod) * (power(al, n, mod) % mod))% mod;
      int second = (al * (power(al, n-1, mod) - 1)) / (al - 1);
      second %= mod;
      int res = first - second;
      if(res < 0) res += mod;
      cout<<res<<"\n";

    }
    return 0;
}