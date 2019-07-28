#include<bits/stdc++.h>

using namespace std;

vector<int >primes;

void findPrimes(){
	vector<char > vis(3001, true);
	for(int i = 3; i * i <= 3000; i+=2){
		if(vis[i]){
			for(int j = i*i; j <= 3000; j+=i){
				vis[j] = false;
			}
		}
	}
	
	primes.push_back(2);
	for(int i = 3; i <= 3000; i+=2){
		if(vis[i]) primes.push_back(i);
	}
}

int cnt[3001];

int main(){
    int n; cin>>n;
    
    findPrimes();
    
    for(int i = 2; i <= n; i++){
    	for(int j = 0; j < primes.size(); j++){
    		if(i%primes[j] == 0) cnt[i]++;
    		else if(i < primes[j]) break;
    	}
    }
    
    int res = 0;
    for(int i = 2; i <= n; i++){
    	if(cnt[i] == 2) res++;
    }
    
    cout<<res<<"\n";
	return 0;
}