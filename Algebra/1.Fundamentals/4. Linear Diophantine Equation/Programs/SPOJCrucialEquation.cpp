/*
    
      SPOJ Problem : Crucial Equation
*/

#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return (b ? gcd(b, a%b) : a);
}

int main(){
	int t; cin>>t;
	int cnt = 1;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		int g = gcd(a,b);
		cout<<"Case "<<cnt<<": ";
		cout<<(c%g ? "No" : "Yes")<<"\n";
		++cnt;
	}
	return 0;
}