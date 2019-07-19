#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    map<int, int> mp;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    for(int i = 0; i < n && a[i] <= k/2; i++){
        mp[a[i]]--;
        if(mp[k - a[i]]){
            cout<<"YES\n";
            return 0;
        }
        mp[a[i]]++;
    }
    cout<<"NO\n";

    return 0;
}
