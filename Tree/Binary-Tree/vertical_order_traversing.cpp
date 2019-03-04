#include<bits/stdc++.h>

using namespace std;


map<int ,vector<int >> mp;
map<int ,vector<int >> ::iterator it;

struct node{
       int data;
       int f;
       node *left,*right;

};

node *newnode(int data){
     node *new_node = nullptr;
     new_node = (node *)malloc(sizeof(node));
     if(!new_node){
        cout<<"Space not avail \n";
        return nullptr;
     }

     new_node->data = data;
     new_node->f = 0;
     new_node->left = nullptr;
     new_node->right = nullptr;
}

void vertical(node* root, int col){
     if(!root)
        return;

     vertical(root->left,col-1);
     root->f = col;
     mp[col].push_back(root->data);
     vertical(root->right, col+1);
}

int main(){
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);

    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    vertical(root,0);
    // Now print the vertical order traversing
    for(it = mp.begin();it!=mp.end();++it){

        it->second;
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
