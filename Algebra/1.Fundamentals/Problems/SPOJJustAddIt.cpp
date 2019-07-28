#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 10000007;

int power(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

signed main(){
	while(1){
		int n, k; cin>>n>>k;
		if(n == 0 && k == 0) return 0;
		
		int s1 = power(n, k);
		int s2 = power(n, n);
		int s3 = 2 * power(n-1, k) % mod;
		int s4 = 2 * power(n-1, n-1) % mod;
		
		cout<<(s1 + s2 + s3 + s4)%mod<<"\n";
	}
	return 0;
}
