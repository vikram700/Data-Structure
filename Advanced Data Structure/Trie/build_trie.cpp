#include<bits/stdc++.h>

using namespace std;

struct trienode{
    struct trienode* childern[26];
    bool endofstring;
};

//function for creating a new node
struct trienode* getNode(){
       struct trienode *node = new trienode;

       node->endofstring  = false;
       for(int i=0;i<26;i++){
           node->childern[i] = nullptr;
       }
    return node;
}
void insert_new_string(struct trienode *root, string s){

    struct trienode *temp = root;
    for(int i=0;i<s.length();i++){

        int index = s[i] - 'a';
        if(!temp->childern[index])
             temp->childern[index] = getNode();
        temp = temp->childern[index];
    }
    temp->endofstring = true;
}

bool search_string(struct trienode *root,string s){
    struct trienode *temp = root;

    for(int i=0;i<s.length();i++){

         int index = s[i] - 'a';
         if(!temp->childern[index])
               return false;
         temp = temp->childern[index];
    }
    return (temp->endofstring);
}


int main(){
    int n;
    cin>>n;
    vector<string > v;
    v.resize(n);

    struct trienode *root = getNode();

    for(int i=0;i<n;i++){
        cin>>v[i];
        insert_new_string(root,v[i]);
    }

    cout<<"Now search the string  into the trie \n";
    cout<<"Enter no of string we want to search \n";
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;

        search_string(root, s) ? cout<<"string is found \n" : cout<<"String is not found \n";
    }
    return 0;
}


