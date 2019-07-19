#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int, int>> res(n);

    for(int i =0; i< n; i++){
        int x,y; cin>>x>>y;
        res[i].first = x+y;
        res[i].second = i+1;
    }

    sort(res.begin(), res.end());

    for(int i =0;i < res.size(); i++){
        cout<<res[i].second<<" ";
    }
    return 0;
}
