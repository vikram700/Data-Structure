#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	
	int x1, y1;
	int g = gcd(b, a%b, x1, y1);
	
	x = y1;
	
	y = x1 - y1 * (a/b);
	
	return g;
}

signed main(){
	int a, b; cin>>a>>b;
	int x, y;
	
	int res = gcd(a, b, x, y);
	
	cout<<"gcd is : "<<res<<"\n";
	cout<<"values of x and y is : "<<x<<" "<<y<<"\n";
	return 0;
}