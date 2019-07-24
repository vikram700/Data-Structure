/*
   This program simple calculate a^n (nth power of a ).
   and it use recursive solution for solving the problem.

   complexity : O(logn)

 */

#include<bits/stdc++.h>

using namespace std;

int power(int a, int n){
    if(n == 0) return 1;

    int res = power(a, n/2);
    if(n%2){
        return res * res * a;
    }
    else{
        return res * res;
    }
}


int main(){
    cout<<"enter two no : "<<"\n";
    int a, n; cin>>a>>n;
    int res = power(a, n);
    cout<<"Output is : "<<res<<"\n";

    return 0;
}