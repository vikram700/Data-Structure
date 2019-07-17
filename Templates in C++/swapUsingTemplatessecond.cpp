
// This code use referencing for swaping values

#include<bits/stdc++.h>

using namespace std;

template<class T >

void swapValues(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

int main(){

    // swaping for integer values
    int firstInteger = 10, secondInteger = 20;
    cout<<"values before swaping  : " <<firstInteger<<" "<<secondInteger<<"\n";
    swapValues(firstInteger, secondInteger);
    cout<<"values after swaping : "<<firstInteger<<" "<<secondInteger<<"\n";

    // swaping for floating values
    float firstFloat = 45.45, secondFloat = 56.56;
    cout<<"values before swaping : "<<firstFloat<<" "<<secondFloat<<"\n";
    swapValues(firstFloat, secondFloat);
    cout<<"values after swaping : "<<firstFloat<<" "<<secondFloat<<"\n";

    // swaping for char
    char firstChar = 'g', secondChar = 'a';
    cout<<"values before swaping : "<<firstChar<<" "<<secondChar<<"\n";
    swapValues(firstChar, secondChar);
    cout<<"values after swaping : "<<firstChar<<" "<<secondChar<<"\n";

    return 0;
}

