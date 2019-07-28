/*
   print all fabonacci number below int data type range

*/
#include<bits/stdc++.h>

using namespace std;

const int MAX = (1 << 31 - 1);

int main(){
	//cout<<"value of max is : "<<MAX<<"\n";
    vector<int > f = {0,1};
    
    int i = 2;
    while(1){
         int x = f[i-1] + f[i-2];
         if(x <= MAX) f.push_back(x);
         else break;
         ++i;
    }

    cout<<"print all integer fabonacci numbers \n";
    cout<<"size of the vector is : "<<f.size()<<"\n";
    for(auto i : f) cout<<i<<" ";
    
    return 0;
}