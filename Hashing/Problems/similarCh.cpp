#include<bits/stdc++.h>

using namespace std;

map<int, int> mp;

void divisors(int n){
    int pro = 1;
    int cnt = 0;
    while(n%2 == 0){
        cnt++;
        n/=2;
    }
    pro *= (cnt+1);
    for(int i = 3; i*i <= n; i+=2){
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n/=i;
        }
        pro *= (cnt + 1);
    }

    if(n > 1) pro *= 2;

    mp[pro]++;
}


int main(){
    int n; cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        divisors(a[i]);
    }

    int res = 0;
    for(auto it : mp){
        res += (it.second*(it.second - 1))/2;
    }
    cout<<res<<"\n";
    return 0;
}
