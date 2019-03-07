#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int > v = {12,23,345,56,67,723,34,45,67};

    make_heap(v.begin(),v.end());

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    pop_heap(v.begin(),v.end());
    v.pop_back();

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    pop_heap(v.begin(),v.end());
    v.pop_back();

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    pop_heap(v.begin(),v.end());
    v.pop_back();
    return 0;
}
