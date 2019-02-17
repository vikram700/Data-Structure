/*
   Author : Vikram Singh
   About  : This program just create a BST and traverse BST using Inorder Traversing.
   Functions :
              1. newnode() --> this just create a newnode.
              2. inorder() --> this traverse the BST using inorder recursive traversing.


*/

#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

//function for creating a newnode
struct node* newnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == nullptr){
        cout<<"Space not available \n";
        return nullptr;
    }

    newnode->data =data;
    newnode->left = newnode->right = nullptr;
    return newnode;
};

//Function for traversing the BST
void inorder(node *root){
     if(!root)
        return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}

int main(){
    struct node* root = newnode(4);

    root->left = newnode(2);
    root->right = newnode(6);

    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(7);

    cout<<"Inorder traversing of the tree \n";
    inorder(root);
    cout<<"\n";

    return 0;
}
