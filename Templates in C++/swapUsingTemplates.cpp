
// This code use pointer values for swaping values

#include<bits/stdc++.h>

using namespace std;

template<typename T >

void swap(T *x, T *y){
    T temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    // swaping for integer values
    int firstInteger = 10, secondInteger = 20;
    cout<<"values before swaping  : " <<firstInteger<<" "<<secondInteger<<"\n";
    swap(&firstInteger, &secondInteger);
    cout<<"values after swaping : "<<firstInteger<<" "<<secondInteger<<"\n";

    // swaping for floating values
    float firstFloat = 45.45, secondFloat = 56.56;
    cout<<"values before swaping : "<<firstFloat<<" "<<secondFloat<<"\n";
    swap(&firstFloat, &secondFloat);
    cout<<"values after swaping : "<<firstFloat<<" "<<secondFloat<<"\n";

    // swaping for char
    char firstChar = 'g', secondChar = 'a';
    cout<<"values before swaping : "<<firstChar<<" "<<secondChar<<"\n";
    swap(&firstChar, &secondChar);
    cout<<"values after swaping : "<<firstChar<<" "<<secondChar<<"\n";

    return 0;
}

