#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1000000007;

void multiply(long long F[2][2],long long M[2][2])
{

    long long x = ((F[0][0]*M[0][0])%MAX + (F[0][1]*M[1][0])%MAX)%MAX;
    long long y =  ((F[0][0]*M[0][1])%MAX + (F[0][1]*M[1][1])%MAX)%MAX;
    long long z =  ((F[1][0]*M[0][0])%MAX + (F[1][1]*M[1][0])%MAX)%MAX;
    long long w =  ((F[1][0]*M[0][1])%MAX + (F[1][1]*M[1][1])%MAX)%MAX;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

long long fab(long long b){
	long long p[2][2] = {{0,1},{1,1}};
	long long res[2][2] = {{1,0},{0,1}};
	while(b){
		if(b&1) multiply(res, p);
		
		b >>= 1;
		
		multiply(p, p);
	}
	
	return res[1][0];
}

int main(){
	int t; cin>>t;
	while(t--){
		long long n; cin>>n;
		if(n == 0) cout<<"0\n";
		else if(n == 1) cout<<"2\n";
		else{
			cout<<fab(n+3)<<"\n";
		}
	}
	return 0;
}