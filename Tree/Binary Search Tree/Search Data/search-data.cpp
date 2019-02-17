
// this program contain function to search data in BST
// this program contain both recursive and non recursive solution 

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

//Function for searching data in BST (non recursive solution )
struct node *find_data(node *root, int data){
       if(root == nullptr)
           return nullptr;
       while(root){
        if(data == root->data)
            return root;
        else if(data < root->data)
            root = root->left;
        else
            root = root->right;
       }
       return nullptr;
}

struct node* find_data_rec(node *root, int data){
     if(root == nullptr)
        return root;
     if(root->data == data)
        return root;
     else if(data < root->data)
        return find_data_rec(root->left, data);
     else return find_data_rec(root->right, data);
}

int main(){
    struct node* root = newnode(4);

    root->left = newnode(2);
    root->right = newnode(6);

    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(7);

    int data;
    cout<<"Enter data to be searched in BST \n";
    cin>>data;

    node *temp = find_data(root, data);

    if(temp == nullptr){
        cout<<"Data is not present in BST \n";
    }
    else{
        cout<<"Data is present in BST \n";
    }

    node *temp1 = find_data_rec(root, data);
    if(temp1 == nullptr)
        cout<<"Data is not present in BST \n";
    else
        cout<<"Data is present in BST \n";

    return 0;
}
