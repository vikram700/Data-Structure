#include<bits/stdc++.h>

using namespace std;

void findPrimes(int n){
    vector<char > vis(n, true);
    for(int i = 3; i * i <= n; i+=2){
        if(vis[i]){
            for(int j = i*i; j <= n; j+=i){
                vis[j] = false;
            }
        }
    }

    //print all primes;

    cout<<"2 ";
    for(int i = 3; i <= n; i+=2){
        if(vis[i]) cout<<i<<" ";
    }
}

int main(){
    int n; cin>>n;
    findPrimes(n);

    return 0;
}