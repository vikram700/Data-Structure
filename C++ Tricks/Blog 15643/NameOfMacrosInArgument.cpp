#include<bits/stdc++.h>

using namespace std;

#define what_is(x) cerr << #x << " is " <<x<<"\n";
#define Values_of(y) cerr << #y << " is " <<y<<"\n";
/*
 This will give an error

  void display(int x){
      cerr<< #x <<" is "<<x<<"\n";
  }

*/
int main(){
    what_is(2*3);

    Values_of(4+5);
    ///display(3*4);
    return 0;
}
