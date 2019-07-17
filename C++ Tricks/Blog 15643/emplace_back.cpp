//uses of emplace back function

#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int >res;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        res.emplace_back(x);
    }

    cout<<"print the complete vector : "<<"\n";
    for(auto it : res) cout<<it<<" ";
    cout<<"\n";

    /* move function in vector */
    vector<int > secondres = move(res);
    cout<<"print the first vector : "<<"\n";
    for(auto it : res) cout<<it<<" ";
    cout<<"\n";

    cout<<"print the second vector : "<<"\n";
    for(auto it : secondres) cout<<it<<" ";
    cout<<"\n";

    return 0;
}
