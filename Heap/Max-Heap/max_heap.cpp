#include<bits/stdc++.h>

using namespace std;

void max_heapify(int arr[],int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest;

    if(left <= n && arr[left] >= arr[i])
          largest = left;
    else
          largest = i;

    if(right <= n && arr[right] >= arr[largest])
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
int main(){
    int arr[10];
    int n;
    cout<<"Enter the no of elements of arr \n";
    cin>>n;

    cout<<"Enter elements of the arr \n";
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }

    build_maxheap(arr,n);

    cout<<"After building the max heap print arr \n";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
