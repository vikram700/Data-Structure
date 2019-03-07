#include<bits/stdc++.h>

using namespace std;
struct compare{
    bool operator()(pair<int,int> const& a, pair<int, int> const& b){
        return((a.first > b.first) && (a.second > b.second));
    }
}

priority_queue<pair<int,int>,
               vector<pair<int,int> >,
               compare> pq;


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(b,a));
    }
    cout<<pq.top().first<<" "<<pq.top().second<<"\n";
    pq.pop();
    cout<<pq.top().first<<" "<<pq.top().second<<"\n";
    pq.pop();
    cout<<pq.top().first<<" "<<pq.top().second<<"\n";
    pq.pop();
    return 0;
}
