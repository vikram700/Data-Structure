#include<bits/stdc++.h>

using namespace std;

void printPrimes(int n){
    vector<char > prime(n, true);

    for(int i = 2; i*i <= n; i++){
        if(!prime[i]){
            for(int j = i*i; j <= n; j+=i){
                prime[j] = false;
            }
        }
    }

    cout<<"All prime no below "<<n<<" are as :"<<"\n";
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n; cin>>n;
    printPrimes(n);

    return 0;
}