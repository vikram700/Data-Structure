
/*
   Author :Vikram Singh
   About Program : This program is delete a linked list(completely)

*/
#include<iostream>

using namespace std;

//creating a node
struct Node{
    int data;
    struct Node *ptr;
};

//creating a linked list
void create_list(struct Node **start){
    struct Node *temp=NULL,*newnode = NULL;
    int enter;
    cout<<"Enter 1 if you add element into linked list and 0 for no \n";
    cin>>enter;
    while(enter){
        newnode = (struct Node*)malloc(sizeof(struct Node));
        cout<<"Enter the data of the node \n";
        cin>>newnode->data;
        newnode->ptr = NULL;

        if(*start==NULL){
            *start = temp = newnode;

        }
        else{
            temp->ptr = newnode;
            temp = newnode;
        }
       cout<<"Enter 1 for add element in list and 0 for no \n";
       cin>>enter;
    }
}

//Traversing a linked list
void traverse_list(struct Node *temp){
     cout<<"print the linked list \n";
     if(temp == NULL){
        cout<<"Linked List is empty \n";
     }
     else{
     while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->ptr;
     }
     cout<<endl;
    }
}


//Function to delete a complete Singly Linked List
void delete_LL(struct Node **start){
     struct Node *temp;
     while((*start)!=NULL){
        temp = *start;         //temp is used to storing the initial node of the list
        *start = (*start)->ptr;//update the starting node of the list
        free(temp);            //free the space of the node
     }

}

int main(){
    struct Node *start = NULL;
    //create a linked list
    create_list(&start);

    //Traverse a linked list
    traverse_list(start);

   //Function call of deleting a linked list(completely)
    delete_LL(&start);
    traverse_list(start); //Seeing the linked list after deleting the linked list(Completely)
    return 0;
}
