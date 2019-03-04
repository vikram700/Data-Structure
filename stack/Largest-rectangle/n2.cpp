#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int >v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int sum = 0;
    for(int i=0;i<v.size();i++){
        int count=0;
        int maxx = INT_MAX;
        for(int j = i;j<v.size();j++){
            count++;
            maxx = min(maxx,v[j]);
            sum = max(sum,(count*maxx));
        }
    }
    cout<<sum<<"\n";
    return 0;
}
