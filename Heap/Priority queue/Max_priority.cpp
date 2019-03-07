#include<bits/stdc++.h>

using namespace std;
int arr[100011];
int n;

void max_heapify(int arr[],int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;

    if(left <=n && arr[left] > arr[i])
         largest = left;
    if(right <= n && arr[right] > arr[largest])
         largest = right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}

void build_maxheap(int arr[],int n){

    for(int i = n/2;i>=1;--i){
        max_heapify(arr,i,n);
    }
}

int maximum(int arr[]){
    return arr[1];
}

void increase_val(int arr[],int i,int val){

     arr[i] = val;
     while(i>1 && arr[i/2] < arr[i]){
         swap(arr[i],arr[i/2]);

         i = i/2;
     }
}
void insert_maxheap(int arr[],int val,int length){

     n = length+1;
     arr[length] = -1;
     increase_val(arr,n,val)

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build_maxheap(arr,n);

    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==2){
            cout<<maximum(arr)<<"\n";
        }
        else{
            int b;
            cin>>b;
            insert_maxheap(arr,b,n);
        }
    }

    return 0;
}
