#include<bits/stdc++.h>

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(),_s.end(),',',' '); stringstream _ss(_s); istream_iterator<string > _it(_ss); err(_it, args);}

void err(istream_iterator<string > it) {}
template<typename T, typename... Args>
void err(istream_iterator<string > it, T a, Args... args){
    cerr<<*it<<" = "<<a<<"\n";
    err(++it, args...);
}

int main(){

    int a = 3, b = 4, c = 5,d = 6;
    error(a,b,c,d);

    return 0;
}
