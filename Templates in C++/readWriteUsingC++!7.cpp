// supported only by c++17

#include<bits/stdc++.h>

using namespace std;

// sum function for adding data
int sum(){ return 0; }

template<typename... Args>
auto sum(Args... args){
    return (args + ...);
}

//read data
template<typename... Args>
void readln(Args&... args){
    ((cin >> args), ...);
}

//write data
template<typename... Args>
void writeln(Args... args){
    ((cout<<args<<" "), ...);
}

int main(){
    int x;
    double y;
    readln(x,y);
    writeln(x,y);

    // sum of both no is
    double Total = sum(x,y);
    writeln(Total);
    return 0;
}