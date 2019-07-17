#include<bits/stdc++.h>

using namespace std;

template<typename args >

class BubbleSort{
    private :
       int n;
       args a[100 * 1000 + 11];
    public :
       void readInput(){
           cin>>n;
           for(int i = 0; i < n ; i++) cin>>a[i];
       }

       void displayArray(){
           for(int i = 0; i < n; i++){
               cout<<a[i]<<" ";
            }
            cout<<"\n";

       }

       void sortingArray(){
           for(int i = 0; i < n ; i++){
              for(int j = 0; j < n-i-1; j++){
                  if(a[j] > a[j+1]){
                      swapValues(a[j], a[j+1]);
                  }
              }
           }
       }

       void swapValues(args &x, args &y){
           args temp = x;
           x         = y;
           y         = temp;
       }
};

int main(){

    // Calling sort class for Integer
    cout<<"Apply sorting for integers \n";
    BubbleSort<int > sortInteger;
    sortInteger.readInput();
    cout<<"Display the array before sorting : "<<"\n";
    sortInteger.displayArray();
    sortInteger.sortingArray();
    cout<<"Display the array after sorting : "<<"\n";
    sortInteger.displayArray();

    cout<<"========================================"<<"\n";
    //Calling sorting for flaot
    cout<<"Apply sorting for floating values \n";
    BubbleSort<float > sortFloat;
    sortFloat.readInput();
    cout<<"Display the array before sorting : "<<"\n";
    sortFloat.displayArray();
    sortFloat.sortingArray();
    cout<<"Display the array after sorting : "<<"\n";
    sortFloat.displayArray();

    cout<<"=========================================="<<"\n";
    // Calling sort class for char array
    cout<<"Calling sorting for char values : "<<"\n";
    BubbleSort<char > sortChar;
    sortChar.readInput();
    cout<<"Display the array before sorting : "<<"\n";
    sortChar.displayArray();
    sortChar.sortingArray();
    cout<<"Display the array after sorting : "<<"\n";
    sortChar.displayArray();

    return 0;
}
