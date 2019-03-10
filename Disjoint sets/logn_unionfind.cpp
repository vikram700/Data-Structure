#include<bits/stdc++.h>

using namespace std;
vector<int >arr;
vector<int >size;

void initialize(){

    for(int i=0;i<arr.size();i++){
        arr[i] = i;
        size[i] = 1;
    }
}

//optimized root function
int root(int i){
    while(arr[i]!=i){
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

bool find(int A,int B){
    return (root(A) == root(B));
}

void weighted_union(int A,int B){
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B]){
        arr[root_A] = root_B;
        size[root_B]+=size[root_A];
    }
    else{
        arr[root_B] = root_A;
        size[root_A]+=size[root_B];
    }
}

int main(){

    return 0;
}
