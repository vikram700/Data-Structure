//insert data in BST using both recursive and non recursive method

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

//Function for inserting data into BST(recursive )
struct node* insert_data(node *root, int data){
    if(root == nullptr){
        root = newnode(data);
        return root;
    }

    if(data < root->data)
        root->left = insert_data(root->left, data);
    else if(data > root->data)
        root->right = insert_data(root->right, data);

    return root;
}

//Function for inserting data into BST(non recursive )
struct node* insert_data_nonr(node *root, int data){
       if(root == nullptr){
           root = newnode(data);
       }
       node *temp = root;
       while(temp != nullptr){
         if(data == temp->data){
            cout<<"Data is already present so no need of inserting \n";
            return root;
         }
         else if(data < temp->data){
            if(temp->left == nullptr){
                temp->left = newnode(data);
                return root;
            }
            else {
                temp = temp->left;
            }
         }
         else{
            if(temp->right == nullptr){
                temp->right = newnode(data);
                return root;
            }
            else{
                temp = temp->right;
            }
         }
      }
}

//Function for traversing the BST using inorder
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

    cout<<"Traverse the BST before the insertion \n";
    inorder(root);
    cout<<"\n";

    int data;
    cout<<"enter data to be insert into BST \n";
    cin>>data;
    root = insert_data(root,data);

    cout<<"Traverse the BST after the insertion \n";
    inorder(root);
    cout<<"\n";

    cout<<"Enter data to be inserting using non recursive technique \n";
    cin>>data;

    root = insert_data_nonr(root ,data);

    cout<<"Traverse the BST after insertion using non recursive technique \n";
    inorder(root);
    cout<<"\n";

    return 0;
}
