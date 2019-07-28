#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<ull >even;

void findEven(){
    ull first = 0, second = 1;
    
    while(1){
        ull next = first + second;
        if(next > (1e16 * 4LL)) break;
        else if(next % 2 == 0) even.push_back(next);
        first = second;
        second = next;
    }
    return;
}

int main(){
    findEven();
    
    int t; cin>>t;
    while(t--){
        ull n; cin>>n;
        ull sum = 0;
        for(auto it : even){
            if(it <= n) sum += it;
            else break;
        }
        cout<<sum<<"\n";
    }
    return 0;
}