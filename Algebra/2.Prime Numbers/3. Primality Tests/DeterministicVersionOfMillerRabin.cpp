/*
    This is deterministic version of miller rabin algo and we know that 88% no have a prime divisor below 100 so
    we just check for all prime no below 100 that for these prime no n is composite of not

    so through this our solution become too fase.
    
 */
#include<bits/stdc++.h>
 
using namespace std;
 
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
bool MillerRabin(u64 n, int iter = 10) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;
 
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
 
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}){
        if(a == n)
            return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int main(){
    int t; cin>>t;
    while(t--){
        u64 n; cin>>n;
        cout<<(MillerRabin(n) ? "YES" : "NO")<<"\n";
    }
    return 0;
} 