#include<bits/stdc++.h>

using namespace std;

long long power(long long a, long long b, long long mod){
	a %= mod;
	long long res = 1LL;
	while(b){
		if(b & 1) res = res * a % mod;
		
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
int main(){
	long long a;
	while( cin>> a){
		 long long  b, mod;
		 cin>>b>>mod;
		 string s; getline(cin, s);
		 
		 long long res = power(a, b, mod);
		 cout<<res<<"\n";
	}
	return 0;
}