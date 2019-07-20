#include<bits/stdc++.h>


using namespace std;

int main(){
    int tt; cin>>tt;
    while(tt--){
        string s; cin>>s;
        map<char, int> mp;
        for(int i = 0;i < s.length(); i++){
            mp[s[i]]++;
        }

        int cnt = 0;
        for(auto it : mp){
            if(it.second%2) cnt++;
        }

        cout<<(cnt <= 1 ? 0 : cnt - 1)<<"\n";
    }
    return 0;
}
