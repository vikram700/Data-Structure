/*
   This program convert natural no into fabonacci encoding

 */

#include<bits/stdc++.h>

using namespace std;

const int MAX = (1 << 31 - 1);
vector<int > f = {0,1};

void generateFabonacciSequence(){
    int i = 2;
    while(1){
        int x = f[i-1] + f[i-2];
        if(x <= MAX) f.push_back(x);
        else break;
        ++i;
    }
    return;
}


int main(){
	
	generateFabonacciSequence();
    int n; cin>>n;
  
    vector<int >encoding = {1};
    
    int ok = false;
    for(int i = f.size()-1; i >= 2; --i){
        if(f[i] <= n){
            encoding.push_back(1);
            n -= f[i];
            ok = true;
        }
        else if(ok){
        	encoding.push_back(0);
        }
    }
    

    cout<<"print the encoding of no : "<<"\n";
    for(int i = encoding.size()-1; i >= 0; --i){
    	cout<<encoding[i];
    }
    return 0;
}