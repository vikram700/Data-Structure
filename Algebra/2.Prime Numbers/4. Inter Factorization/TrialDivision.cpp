/*
         Complexity : O(sqrt(N))
 */

#include<bits/stdc++.h>

using namespace std;

vector<long long > factors(long long n){
    vector<long long > factorization;
    
    while(n%2 == 0){
        factorization.push_back(2);
        n /= 2;
    }

    for(int i = 3; i * i <= n; i+=2){
        while(n%i == 0){
            factorization.push_back(i);
            n /= i;
        }
    }
    
    if(n > 1) factorization.push_back(n);

    return factorization;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        
        vector<long long > res = factors(n);

        cout<<"all prime factors of "<<n<<" are  : "<<"\n";
        for(auto i : res) cout<<i<<" ";
        cout<<"\n";
        
    }
    return 0;
}