#include<bits/stdc++.h>

using namespace std;

vector<long long > fab = {0,1};

const long long MAX = 10000000000;

void fillall(){
    int i = 2;
    while(1){
        long long x = fab[i-1] + fab[i-2];
        if(x <= MAX) fab.push_back(x);
        else break;
        ++i;
    }
}

bool isFib(long long n){
    long long low = 0, high = fab.size();
    while(low <= high){
        long long mid = (low + high) >> 1;
        
        if(fab[mid] == n) return true;
        else if(fab[mid] < n){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}
int main(){
    fillall();
    long long t; cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        bool ok = isFib(n);
        
        if(ok == true)cout<<"IsFibo\n";
        else cout<<"IsNotFibo\n";
    }
    return 0;
}