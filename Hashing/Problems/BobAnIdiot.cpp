#include<bits/stdc++.h>

using namespace std;

map<char, char> mp;

int main(){
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        char x, y;
        cin>>x>>y;
        mp[x] = y;
        mp[y] = x;
    }
    string res;
    cin>>res;
    for(int i = 0; i < res.length(); i++){
        if(mp[res[i]]){
            res[i] = mp[res[i]];
        }
    }
    cout<<res<<"\n";
    return 0;
}
