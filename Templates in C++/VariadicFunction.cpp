#include<bits/stdc++.h>

using namespace std;

// sum function only for same data types
int sum(){ return 0; }

template<typename T, typename... Args>

T sum(T a, Args... args){
    return (a + sum(args...));
}

// some function for different or mixed data types
int sumOfMixed(){ return 0; }

template<typename T, typename... Args>
auto sumOfMixed(T a, Args... args){
    return (a + sumOfMixed(args...));
}


int main(){
    cout<<"sum of the given no is : "<<sum(1,2,3,4,5) + sum(1.12, 34.34)<<"\n";
    cout<<"sum of mixed no is : "<<sumOfMixed(1,2.34,56.67,12)<<"\n";
    return 0;
}
