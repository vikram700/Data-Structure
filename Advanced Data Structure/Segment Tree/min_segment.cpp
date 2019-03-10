#include<bits/stdc++.h>

using namespace std;
const int N = 100011;
int arr[N];
int tree[3*N];

void build(int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        int mid = start + (end - start)/2;

        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

void update(int node,int start,int end,int index,int value){
    if(start == end){
        tree[node] = value;
        arr[index] = value;
    }
    else{
        int mid = start + (end - start)/2;

        if(start <= index && index <= mid){
            update(2*node,start,mid,index,value);
        }
        else{
            update(2*node+1,mid+1,end,index,value);
        }

        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int start,int end,int l,int r){
    if(r < start || end < l) return INT_MAX;
    else if(l<=start && end<=r) return tree[node];
    else{
        int mid = start + (end - start)/2;

        int p1 = query(2*node,start,mid,l,r);
        int p2 = query(2*node+1,mid+1,end,l,r);
        return min(p1,p2);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1,1,n);

    while(q--){
        char ch;
        cin>>ch;
        int a,b;
        cin>>a>>b;
        if(ch == 'u'){
             update(1,1,n,a,b);
        }
        else{
            cout<<query(1,1,n,a,b)<<"\n";
        }
    }
    return 0;
}
