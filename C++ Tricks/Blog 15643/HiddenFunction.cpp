/*
  This file contain some useful function that are used for CP.
 */

#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){

    /* 1. Find gcd of two numbers */
    cout<<"value from predefine function : "<<__gcd(20,6)<<"\n";
    cout<<"value of gcd using userdefine function is : "<<gcd(20,6)<<"\n";

    cout<<"==============================================================="<<"\n";
    /* 2. __builtin_ffs() return 1+index of one's from lsb */
    cout<<__builtin_ffs(10)<<"\n";

    cout<<"==============================================================="<<"\n";
    /* 3. __builtin_clz() return leading zeros */
    cout<<__builtin_clz(16)<<"\n";

    cout<<"==============================================================="<<"\n";
    /* 4. __builtin_ctz() return tailing zeros*/
    cout<<__builtin_ctz(16)<<"\n";

    cout<<"==============================================================="<<"\n";
    /* 5. count no of 1's bit into binary representation of number */
    cout<<__builtin_popcount(14)<<"\n";

    
    return 0;
}
