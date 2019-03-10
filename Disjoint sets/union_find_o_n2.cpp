#include<bits/stdc++.h>

using namespace std;
vector<int >arr;

void initialize(){
    for(int i=0;i<arr.size();i++){
        arr[i] = i;
    }
}

bool find(int A,int B){
    return (arr[A]==arr[B]);
}

void union_insert(int A,int B){

    int temp = arr[A];
    for(int i=0;i<arr.size();i++){
        if(arr[i] == temp)
           arr[i] = arr[B];
    }
}

int main(){
   // vector<int >arr;
    arr.resize(10);

    initialize();
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    cout<<"find if 1 and 2 are connected or not \n";
    find(1,2)?cout<<"YES \n" : cout<<"NO \n";

    union_insert(2,1);
    union_insert(4,3);
    union_insert(8,4);
    union_insert(9,3);
    union_insert(6,5);
    union_insert(5,2);

    cout<<"Print the vector \n";
    for(auto c : arr){
        cout<<c<<"\n";
    }
    return 0;
}
