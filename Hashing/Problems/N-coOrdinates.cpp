#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    map<pair<int, int>, int> mp;

    for(int i = 0;i < n; i++){
        int x,y; cin>>x>>y;
        mp[{x,y}]++;
    }

    for(auto it : mp){
        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<"\n";
    }
    return 0;
}
