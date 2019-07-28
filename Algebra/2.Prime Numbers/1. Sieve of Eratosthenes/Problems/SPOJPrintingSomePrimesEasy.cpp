#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000001;

void solve(){
	
	vector<int >primes = {2};
	vector<char > vis(MAX, true);
	for(int i = 3; i * i <= MAX; i+=2){
		if(vis[i]){
			for(int j = i*i; j <= MAX; j+=i){
				vis[j] = false;
			}
		}
	}
	
	for(int i = 3; i <= MAX; i+=2){
		if(vis[i]) primes.push_back(i);
	}
	
	//print all
	for(int i = 0; i < primes.size(); i+=100){
		cout<<primes[i]<<"\n";
	}
}
int main(){
	solve();
	return 0;
}