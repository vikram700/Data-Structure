#include<bits/stdc++.h>

using namespace std;

pair<int, int> fab(int n){
	if(n == 0){
		return {0,1};
	}
	
	auto p = fab(n >> 1);
	int c = p.first*(2*p.second - p.first);
	int d = p.first*p.first + p.second*p.second;
	
	if(n&1){
		return {d, (d+c)};
	}
	else{
		return {c, d};
	}
}

int fab2(int n){
    if(n == 0 || n == 1) return n;
    return (fab2(n-2) + fab2(n-1));
}
int main(){
	int n;
	while(cin>>n){
	   int it = fab2(n);
	   cout<<"The Fibonacci number for "<<n<<" is "<<it<<"\n";
    }
	return 0;
}