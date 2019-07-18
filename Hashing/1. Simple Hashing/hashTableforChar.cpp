#include<iostream>

using namespace std;

// hash table declaration
int frequency[26];

int hashfunc(char ch){
    return (ch - 'a');
}

void countFrequency(string s){
    for(int i = 0; i < s.length(); i++){
        int index = hashfunc(s[i]);
        frequency[index]++;
    }

    // print the hash table
    cout<<"char "<< " " << "index "<<" "<<"value"<<"\n";
    for(int i = 0; i < 26; i++){
        cout<<(char)(i+'a')<<"     "<<i<<"      "<<frequency[i]<<"\n";
    }
}

int main(){
    string s = "ababcd";
    countFrequency(s);

    return 0;
}
