#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500 * 1000 + 11;
bool vis[MAX];
vector<int > primes;

void prime(){
    for(int i = 2; i*i <= 500000; i++){
        if(!vis[i]){
            for(int j = 2*i; j <= 500000; j+= i){
                vis[j] = true;
            }
        }
    }

    for(int i = 2; i <= 500000; i++){
        if(!vis[i]){
            primes.push_back(i);
        }
    }
}

int hashfunc(string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += ((i+1) * (s[i] - 'a' + 97));
    }
    return sum;
}

int main(){
    // generate all primes below 10^5
    prime();

    int n; cin>>n;
    vector<string > res(n);
    vector<int > reshash;

    int minVal = INT_MAX;

    for(int i = 0; i < n; i++){
        cin>>res[i];
        reshash.push_back(hashfunc(res[i]));
        minVal = min(minVal, reshash[i]);
    }

    cout<<"final min value is : "<<minVal<<"\n";
    int mod = *upper_bound(primes.begin(),primes.end(), minVal);
    cout<<"mod value is : "<<mod<<"\n";
    cout<<"print the index values for each string is : "<<"\n";
    for(int i = 0; i < n; i++){
        cout<<res[i]<<" "<<reshash[i]%mod<<"\n";
    }
    return 0;
}
