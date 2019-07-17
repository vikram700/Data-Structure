#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct point{
    T first;
    T second;
    point(T x, T y){
        first = x;
        second = y;
    }
};

int main(){
    
    vector<point<int > > points = {{1,2},{3,4},{5,6}};
    cout<<"print the points of the vector : "<<"\n";
    for(auto it : points){
        cout<<it.first<<" "<<it.second<<"\n";
    }

    //
    return 0;
}