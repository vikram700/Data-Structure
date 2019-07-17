#include<bits/stdc++.h>

using namespace std;

template<class T >

T largeValue(T x, T y){
    cout<<"value of x and y is : "<<x<<" "<<y<<"\n";
   return ( x > y ? x : y);
}



int main(){

    cout<<"take two integer and find max of them : \n";
    int x = 10,y = 30;
    cout<<"larger from both integer is : " << largeValue(x, y)<<"\n";

    cout<<"Take two float values and find larger of them : "<<"\n";
    float a, b;
    a = 20.3, b = 56.8;
    cout<<"larger from both the floating values is : " << largeValue(a, b)<<"\n";

    cout<<"find the larger value from the char  : " <<"\n";
    char ch1 = 'b', ch2 = 'g';
    cout<<"larger of the both char is : "<<largeValue(ch1, ch2)<<"\n";

    /*
       This will give and error because both are different type

    cout<<"Let's check for the one integer and one float : "<<"\n";
    int oneInteger = 10; float secondFloat = 34.56;
    cout<<"Larger between both of them is : " <<largeValue(oneInteger, secondFloat)<<"\n";
    */
    return 0;
}
