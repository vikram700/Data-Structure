/*
   this code make the min heap of the pair

*/

#include<bits/stdc++.h>

using namespace std;

struct compare{

    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        if(a.first != b.first){
            return (a.first > b.first);
        }
        else{
            return (a.second > b.second);
        }
    }
};

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, compare > pq;

    for(int i = 0;i<5;i++){
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
