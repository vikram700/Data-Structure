// problem 1

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    priority_queue<int , vector<int >, greater<int > > pq;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        pq.push(a);
    }

    int count = 0;
    while(1){

         int x;
         if((x = pq.top())<k){
             pq.pop();
             if(pq.empty()){
                 cout<<"-1";
                 break;
             }

            int  y = 2*pq.top();pq.pop();
             pq.push(x+y);
             count++;
         }
         else{
             cout<<count;
             break;
         }

    }

    return 0;

}
