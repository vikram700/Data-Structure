
#include<bits/stdc++.h>

using namespace std;

void max_heapify(int arr[],int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest;

    if(left <= n && arr[left] > arr[i])
        largest = left;
    else
        largest = i;

    if(right <= n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}

void build_maxheap(int arr[],int n){

    for(int i = n/2 ; i>=1; --i){
        max_heapify(arr,i,n);
    }
}
void heapSort(int arr[],int n){
    int heap_size = n;
    build_maxheap(arr,heap_size);

    for(int i = n;i>=2;i--){

        swap(arr[1],arr[i]);
        heap_size-=1;
        max_heapify(arr,1,heap_size);
    }
}
int main(){
    int n;
    cout<<"Enter the no of element of the arr\n";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the element of the arr \n";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    heapSort(arr,n);

    cout<<"print the array after sorting the arr using heap sort \n";
    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";

    }

    return 0;
}
