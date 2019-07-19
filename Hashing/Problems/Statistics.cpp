#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    map<string, int > name;
    map<string, int > game;

    for(int i = 0; i <n; i++){
        string a,b;
        cin>>a>>b;

        if(!name[a]){
            name[a]++;
            game[b]++;
        }
    }

    int maxVal = 0;
    string res;

    for(auto it : game){
        if(it.second > maxVal){
            maxVal = it.second;
            res = it.first;
        }
    }

    cout<<res<<"\n";
    cout<<game["football"]<<"\n";
    return 0;
}
