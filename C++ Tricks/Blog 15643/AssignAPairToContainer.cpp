#include<bits/stdc++.h>

using namespace std;

int main(){

    // vector
    cout<<"Work on vector : "<<"\n";
    vector<int > v = {1,2,3,4,5,6};
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";


    //deque
    cout<<"Work on deque : "<<"\n";
    deque<vector<pair<int, int> > > d;
    d = {{{1,2},{3,4}},{{6,7}, {8,9}}};
    for(auto i : d){
        for(auto j : i){
            cout<<j.first<<" "<<j.second<<"\n";
        }
        cout<<"\n";
    }

    //set
    cout<<"work on set : "<<"\n";
    set<int > s;
    s = {1,2,3,4,5,6,7,8,9};
    for(auto i : s)
        cout<<i<<" ";
    cout<<"\n";

    //list
    cout<<"work on list : "<<"\n";
    list<int > l;
    l = {5,4,3,2,1};
    for(auto i : l)
        cout<<i<<" ";
    cout<<"\n";

    //array
    cout<<"Work on array : "<<"\n";
    array<int, 5> arr;
    arr = {4,5,6,7,8};
    for(auto i : arr)
        cout<<i<<" ";
    cout<<"\n";

    //tuples
    cout<<"work on tuples : "<<"\n";
    tuple<int, int, int> t;
    t = make_tuple(3, 4, 5);
    cout << get<0>(t) << '\n';
    return 0;
}
