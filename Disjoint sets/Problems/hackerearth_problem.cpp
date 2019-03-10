#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1001];
int size[1001];

void initialize(){
    for(int i=1;i<=n;i++){
        arr[i] = i;
        size[i] = 1;
    }
}

int root(int i){
    while(arr[i]!=i){
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void insert_union(int A,int B){
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] <= size[root_B]){
        arr[root_A] = root_B;
        size[root_B]+=size[root_A];
        size[root_A] = 0;
    }
    else{
        arr[root_B] = root_A;
        size[root_A]+=size[root_B];
        size[root_B] = 0;
    }
}

int main(){
    cin>>n;
    initialize();
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        insert_union(a,b);

        vector<int >arr1(n+1);
        for(int i=1;i<=n;i++){
            arr1[i] = size[i];
        }
        sort(arr1.begin(),arr1.end());
        for(int i=1;i<=n;i++){
            if(arr1[i] != 0){
                cout<<arr1[i]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
