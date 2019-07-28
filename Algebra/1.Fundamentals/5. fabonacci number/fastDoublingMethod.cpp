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

int main(){
	int n; cin>>n;
	
	auto it = fab(n);
	cout<<"nth fabonacci is : "<<it.first<<"\n";
	return 0;
}