/*
     Eucliden algorithms : ax + by = gcd(a, b);
     
 */
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
    int g = gcd(a, b);
    return (a * b)/g;
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<"gcd of these two no is : "<<gcd(a, b);
    cout<<"\n";
    cout<<"lcm of two no is : "<<lcm(a, b);

    return 0;
}