#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
    int data;
    Node *left,*right;
};

class Tree{
  public:

    void preorder(Node *root){
         if(!root) return;

         cout<<root->data<<" ";
         preorder(root->left);
         preorder(root->right);
    }

    Node *insertNode(Node *root, int data){
          Node *new_node = new Node();
          new_node->data = data;
          new_node->left = nullptr;
          new_node->right = nullptr;

          if(!root){
            root = new_node;
          }
          else if(data < root->data){
            root->left = insertNode(root->left,data);
          }
          else{
            root->right = insertNode(root->right,data);
          }
        return root;
    }

};


int main(){

    Tree mytree;
    Node *root = nullptr;

    int t;
    int data;

    cout<<"Enter the no of data to be inserted "<<endl;
    cin>>t;

    while(t--){
        cout<<"Enter the data to be inserted \n";
        cin>>data;

        root = mytree.insertNode(root,data);
    }

    mytree.preorder(root);

    return 0;
}
