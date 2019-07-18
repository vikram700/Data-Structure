#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int hashfunc(string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += ((i+1) * (s[i] - 'a' + 97));
    }
    return sum%599;
}

// suppose hashfunc index values does not greater than 10000;
vector<string > hashTable[10000];
int hashTableSize = 10000;


void insertIntoHash(string s){
     int index = hashfunc(s);
     hashTable[index].push_back(s);
}

void searchString(string s){

    int index = hashfunc(s);
    for(int i = 0; i < hashTable[index].size(); ++i){
        if(hashTable[index][i] == s){
            cout<<s<<" is found!"<<"\n";
            return;
        }
    }
    cout<<s<<" is not found!"<<"\n";

    return;
}

int main(){
    int n; cin>>n;
    vector<string > stringInfo(n);
    for(int i = 0; i < n; i++){
        cin>>stringInfo[i];
        insertIntoHash(stringInfo[i]);
    }
    
    cout<<"enter the no of query you want to search : "<<"\n";
    int q; cin >> q;
    while(q--){
        cout<<"enter the string for searching : "<<"\n";
        string s; cin>>s;
        searchString(s);
    }
    return 0;
}