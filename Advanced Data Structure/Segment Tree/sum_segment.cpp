/*
   Problem : Segment Tree
   Author : Vikram Singh
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 100001;
int arr[N];
int tree[2*N];

void build(int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
        cout<<"start : "<<start<<" ";
    }
    else{
        int mid = (start + end)/2;

        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

//complexity of this function is log(n)
void update(int node,int start,int end,int idx,int val){
    if(start == end){
        arr[idx]+=val;
        tree[node]+=val;
    }
    else{

        int mid = (start + end)/2;

        if(start <= idx && idx <= mid){
            update(2*node,start,mid,idx,val);
        }
        else{
            update(2*node+1,mid+1,end,idx,val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node,int start,int end,int l,int r){
    //completely outside
    if(r < start || end < l){
        return 0;
    }
    else if(l <= start && end <= r){
        return tree[node];
    }
    else{
        int mid = (start+end)/2;

        int p1 = query(2*node,start,mid,l,r);
        int p2 = query(2*node+1,mid+1,end,l,r);

        return (p1+p2);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //code to build segment tree
    build(1,0,n-1);

    cout<<endl;
    cout<<"print the segment tree \n";
    for(int i=1;i<=2*n+1;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    cout<<"enter no of queries \n";
    int q;
    cin>>q;
    while(q--){
        int a;
        cout<<"enter query no \n";
        cin>>a;
        if(a == 1){
            int l,r;
            cout<<"enter the range \n";
            cin>>l>>r;
            cout<<"Summation is : "<<query(1,0,n-1,l,r)<<"\n";
        }
        else{
            int idx,val;
            cout<<"enter the index and value \n";
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
        }

    }
    return 0;
}
