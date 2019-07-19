#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    map<string, int > mp;

    for(int i = 0; i < n; i++){
        string s; cin>>s;
        mp[s]++;
    }

    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;
}
