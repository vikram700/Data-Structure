#include<bits/stdc++.h>

using namespace std;

#define a_macros(args...) sum(args)

int sum(){ return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args){
    return (a + sum(args...));
}

int main(){

    cout<<"sum of the given values is : "<<a_macros(1,2,3,4,5)<<"\n";
    return 0;
}
