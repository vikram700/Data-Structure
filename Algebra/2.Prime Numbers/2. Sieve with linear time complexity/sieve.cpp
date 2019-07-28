#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000000;
int lp[MAX+1];
vector<int >pr;

int main(){
    
    for(int i = 2; i <= MAX; ++i){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }

        for(int j = 0; j < pr.size() && j*lp[i] <= MAX && pr[j] <= lp[i]; ++j){
            lp[j*lp[i]] = pr[j];
        }
    }
    return 0;
}