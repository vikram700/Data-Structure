#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
vector<int >allPrimes;
vector<char > vis(MAX, true);

bool notZeroDigit(int n){
	int x = n, cnt = 0;
	while(n){
		if(n%10 == 0) return false;
		n /= 10;
		cnt++;
	}
	
	for(int i = 1; i < cnt; i++){
		int y = x % (int)pow(10, i);
		if(vis[y] == false) return false;
	}
	return true;
}

void findAllPrimes(){
    vis[0] = vis[1] = false;
	for(int i = 2; i*i <= MAX; i++){
		if(vis[i]){
			for(int j = i*i; j<=MAX; j+=i){
				vis[j] = false;
			}
		}
	}
	
	for(int i = 2; i <= MAX; i++){
		if(vis[i] && notZeroDigit(i)){
			allPrimes.push_back(i);
		}
	}
}

int binarySearch(int n){
	if(allPrimes[allPrimes.size() - 1] <= n) return allPrimes.size();
	int res = 0;
	int low = 0, high = allPrimes.size();
	while(low <= high){
		int mid = (low + high) >> 1;
		if(allPrimes[mid] == n) return mid+1;
		else if(allPrimes[mid] < n){
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
	// for(auto i : allPrimes) cout<<i<<" ";
	// cout<<"\n";
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		int res = upper_bound(allPrimes.begin(), allPrimes.end(), n) - allPrimes.begin();
		
		cout<<res<<"\n";
	}
	return 0;
}