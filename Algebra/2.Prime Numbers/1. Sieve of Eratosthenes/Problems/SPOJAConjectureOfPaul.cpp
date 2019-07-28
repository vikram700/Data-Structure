#include<bits/stdc++.h>

using namespace std;

const int MAX = 3200;
vector<int >allPrimes;

bool isPrime(int n){
	if(n >= 10000000) return false;
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

map<int, bool> mp;
void findAllPrimes(){
	for(int i = 0; i <= MAX; i++){
		for(int j = 0; j <= 100; j++){
			int x = pow(i,2) + pow(j,4);
			if(isPrime(x) && mp[x] == false){
				allPrimes.push_back(x);
				mp[x] = true;
			}
		}
	}
}

int binarySearch(int n){
	int res = 0;
	int low = 0, high = allPrimes.size();
	while(low <= high){
	     int mid = (low + high) >> 1;
	     if(allPrimes[mid] == n) return mid+1;
	     else if(allPrimes[mid]  < n){
	     	res = max(res, mid+1);
	     	low = mid+1;
	     }
	     else{
	     	high = mid - 1;
	     }
	}
	return res;
}

int main(){
	findAllPrimes();
	sort(allPrimes.begin(), allPrimes.end());
	
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		int res = min(13175, binarySearch(n));
		
		cout<<res<<"\n";
	}
	return 0;
}