
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
     while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->ptr;
     }
}

//inserting a node into the linked list
void insert_list(struct Node **start,int data,int position){

     struct Node *newnode,*q,*p;
     newnode = (struct Node*)malloc(sizeof(struct Node));
     int k=1;
     if(newnode==NULL){
        cout<<"Sapce is not available \n";
     }
     else{
        newnode->data = data;
        newnode->ptr = NULL;
        p = *start;
        if(position == 1){
             newnode->ptr = p;
             *start = newnode;
        }
        else{
            while((k<position) && (p!=NULL)){
                q=p;
                k++;
                p = p->ptr;
            }
            q->ptr = newnode;
            newnode->ptr = p;
        }
     }
}


//deleting a node in linked list
void delete_list(struct Node **start,int position){
     int k=1;
     struct Node *p,*q;
     if(*start == NULL){
        cout<<"Linked list is empty \n";
        return;
     }
     else{
        p = *start;
        if(position == 1){

            *start = (*start)->ptr;
            free(p);
        }
        else{
            while((k<position) && (p!=NULL)){
                k++;
                q = p;
                p = p->ptr;
            }

            q->ptr = p->ptr;
            free(p);
        }

     }
}

int main(){
    struct Node *start = NULL;
    //create a linked list
    create_list(&start);

    //Traverse a linked list
    traverse_list(start);

    //Insertion into linked list
    cout<<"Enter data to be inserted \n";
    int data;
    cin>>data;
    cout<<"Enter the position to be inserted \n";
    int position;
    cin>>position;
    insert_list(&start,data,position);

    traverse_list(start); //Traverse list after insertion

    //deletion a node in linked list
    cout<<"Enter the position of node to be delete \n";
    cin>>position;
    delete_list(&start,position);
    traverse_list(start); //traverse list after deletion
    return 0;
}
