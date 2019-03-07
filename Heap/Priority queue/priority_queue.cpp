#include<bits/stdc++.h>

using namespace std;

void max_heapify(int arr[],int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;

    if(left <=n && arr[left] > arr[i])
        largest = left;
    if(right <= n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i] ,arr[largest]);
        max_heapify(arr,largest,n);
    }
}

int maximum(int arr[]){
    return arr[1];
}

int extract_maximum(int arr[],int length){

    if(length == 0){
        cout<<"Priority queue is empty \n";
        return -1;
    }
    int maxx = arr[1];
    arr[1] = arr[length];
    length-=1;
    max_heapify(arr,1,length);
}

void increase_val(int arr[],int i,int val){

    if(val < arr[i]){
        cout<<"new node can't be inserted \n";
        return;
    }

    arr[i] = val;
    while(i > 1 && arr[i/2] < arr[i]){
        /* code */
        swap(arr[i/2],arr[i]);
        i = i/2;
    }

}

void insert_val(int arr[],int length,int val){

     length++;
     arr[length] = -1;
     increase_val(arr,length,val);
}

int main(){
    int pq[1000];
    int n = 1;

    return 0;
}
