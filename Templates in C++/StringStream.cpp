/* A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream */

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    // here we will count no of word into string and put them into a vector
    vector<string > res;
    stringstream _s(s);
    string word;
    int count = 0;
    while(_s >> word){
        count++;
        res.push_back(word);
    }

    cout<<"size of the vector is : "<<count<<"\n";
    cout<<"print the vector of the strings is : "<<"\n";
    for(auto i : res) cout<<i<<" ";
    cout<<"\n";

    return 0;
}
