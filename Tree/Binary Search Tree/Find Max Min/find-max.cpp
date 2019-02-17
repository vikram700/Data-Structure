// This program find max element.

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


// Recursive function for find max element
int find_max(node *root){
    if(root == nullptr)
        return -1;
    if(root->right == nullptr)
        return root->data;
    else return(find_max(root->right));
}

// Non Recursive method for finding max
int find_max_nonr(node *root){
    if(root == nullptr)
        return -1;
    while(root->right != nullptr)
        root = root->right;

    return root->data;
}

int main(){
    struct node* root = newnode(4);

    root->left = newnode(2);
    root->right = newnode(6);

    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(7);

    cout<<"Using recursive method \n";
    cout<<"Maximum element in bst is : "<<find_max(root)<<"\n";

    cout<<"Using non recursive method \n";
    cout<<"Maximum element in bst is : "<<find_max_nonr(root)<<"\n";
    return 0;
}
