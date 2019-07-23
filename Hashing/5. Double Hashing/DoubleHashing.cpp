#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<string > hashTable(10000);
int hashTableSize = 10000;

int hashfunc(string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += (s[i] - 'a' + 97) * (i+1);
    }

    return sum%599;
}

void insertIntoHash(string s){
     int index = hashfunc(s);
     int h = 1;
     while(hashTable[index] != ""){
          index = (index + h*h)%hashTableSize;
          h++;
     }
     hashTable[index] = s;
     return;
}


void searchString(string s){
     int index = hashfunc(s);
     int h = 1;
     while(hashTable[index] != s && hashTable[index] != ""){
         index = (index + h*h)%hashTableSize;
         h++;
     }

     if(hashTable[index] == s){
         cout<<s<<" is found "<<"\n";
     }
     else{
         cout<<s<<" is not found "<<"\n";
     }
}

int main(){
    vector<string > res = {"abcdef", "bcdefa", "cdefab", "defabc"};
    for(int i = 0; i < 4; i++){
        insertIntoHash(res[i]);
    }

    cout<<"enter the no of query you want to search : "<<"\n";
    int q; cin>>q;
    while(q--){
        cout<<"enter the string that you want to process : "<<"\n";
        string s; cin>>s;
        searchString(s);
    }
    return 0;
}