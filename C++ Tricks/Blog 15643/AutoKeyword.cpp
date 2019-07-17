#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int > v = {1,2,3,4};
    cout<<"print the vector : "<<"\n";
    for(auto i : v) cout<<i<<" ";
    cout<<"\n";

    // make power of each element of the vector
    for(auto &it : v) it = it*it;
    cout<<"print the vector after the power : "<<"\n";
    for(auto it : v) cout<<it<<" ";
    cout<<"\n";

    cout<<"take the input for the matrix : "<<"\n";
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    cout<<"print the matrix : "<<"\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"print the matrix using given method : "<<"\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout<<a[i][j]<<" \n"[j+1 == m];

    return  0;
}
