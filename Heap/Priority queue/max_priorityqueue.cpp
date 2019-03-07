/*
   This code contain max priority queue for pair
*/

#include<bits/stdc++.h>

using namespace std;

struct comp{
   bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first != b.first){
            return (a.first < b.first);
        }
        else{
            return (a.second < b.second);
        }
   }
};

int main(){

    priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;

    for(int i = 1 ;i<=5;i++){
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(a,b));
    }
    cout<<"\n";
    cout<<"\n";
    while(!pq.empty()){
        pair<int,int> p;
        p = pq.top();
        pq.pop();
        cout<<p.first<<" "<<p.second<<"\n";

    }
    return 0;
}
