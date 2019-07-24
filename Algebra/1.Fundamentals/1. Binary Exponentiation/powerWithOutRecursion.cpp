/*
   This program also calculate the power of a^n with O(logN) time complexity but without using recursion
 */

#include<bits/stdc++.h>

using namespace std;

int power(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res *= a;
        b>>=1;
        a *= a;
    }

    return res;
}

int main(){
    cout<<"enter two no : "<<"\n";
    int a, n; cin>>a>>n;
    int res = power(a, n);
    cout<<res<<"\n";

    return 0;
}