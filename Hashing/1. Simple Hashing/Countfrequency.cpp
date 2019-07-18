// This code is just showing occur of char and next file create an hash table

#include<iostream>

using namespace std;

void countFrequency(string s){
     // time complexity O(N*26) = O(N)

     for(char ch = 'a'; ch <= 'z'; ++ch){
        int frequency = 0;
        for(int i = 0; i < s.length(); i++){
            if(ch == s[i]) frequency++;
        }

        cout<< ch <<" "<<frequency<<"\n";
     }
}

int main(){
    string s = "ababcd";
    countFrequency(s);

    return 0;
}
