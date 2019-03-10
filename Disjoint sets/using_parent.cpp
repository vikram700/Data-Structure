#include<bits/stdc++.h>

using namespace std;

vector<int >arr;

//finding the root of the node
int root(int i){
    while(arr[i]!=i)
        i = arr[i];
    return i;
}

// find operation
bool find(int A,int B){
    return (root(A) == root(B));
}

//union operation

void union_insert(int A,int B){
    int root_A = root(A);
    int root_B = root(B);
    arr[root_A] = root_B;
}

int main(){

    return 0;
}
