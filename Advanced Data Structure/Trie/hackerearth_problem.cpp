#include<bits/stdc++.h>

using namespace std;

struct trienode{
    int data;
    struct trienode* childs[26];
};

struct trienode* getNode(int data){
    struct trienode* temp = new trienode;
    temp->data = data;

    for(int i=0;i<26;i++){
        temp->childs[i] = nullptr;
    }
    return temp;
}

void insert_string(trienode* root, string s,int length){
    //int length = s.length();
    trienode* temp = root;

    for(int i=0;i<s.length();i++){
        int index = s[i] - 'a';
        if(!temp->childs[index])
            temp->childs[index] = getNode(length);

        temp = temp->childs[index];
        if(temp->data < length){
            temp->data = length;
        }
    }
}

int find_prefix(trienode* root, string s){
    trienode* temp = root;

    for(int i=0;i<s.length();i++){

        int index = s[i] - 'a';
        if(!temp->childs[index]){
            //cout<<"\n String printed \n";
            return -1;
        }

        temp = temp->childs[index];
    }
    return temp->data;
}

int main(){
    int n,q,a;
    cin>>n>>q;
    struct trienode* root = getNode(0);

    string s;
    for(int i=0;i<n;i++){
       cin>>s>>a;
       insert_string(root, s,a);
    }
    while(q--){
        cin>>s;
        cout<<find_prefix(root,s)<<"\n";
    }

    return 0;
}
