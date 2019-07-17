/* This contain new template feature */
// These features are added into c++17
#include<bits/stdc++.h>

using namespace std;

int sum() { return 0; }
template<typename... Args>
auto sum(Args... args){
    return (args + ...);
}

int main(){
    cout<<"sum of the given values is : "<<sum(1,2,3,4,5)<<"\n";
    return 0;
}


