#include<bits/stdc++.h>

using namespace std;

using u64  = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 a, u64 b, u64 mod){
	u64 res = 1;
	while(b){
		if(b & 1) res = (u128)(res * a) % mod;
		
		b >>= 1;
		
		a = (u128)(a * a) % mod;
	}
	return res;
}

bool probablyPrimeFermat(u64 n, int iter = 20){
	if(n <= 4){
		return n == 3 || n == 2;
	}
	
	for(int i = 0; i < iter; ++i){
		int a = 2 + (u64)rand % (n - 3);
		if(binpower(a, n-1, n) != 1)
		   return false;
	}
	return true;
}


int main(){
	int t; cin>>t;
	while(t--){
		u64 n; cin>>n;
		cout<<(probablyPrimeFermat(n) ? "YES" : "NO")<<"\n";
	}
	return 0;
}