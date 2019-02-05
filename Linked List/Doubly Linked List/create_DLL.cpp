/*
    Author : Vikram Singh
    About  : This program contain code for crating Doubly Linked List,and insertion and deletion into DLL
             .Insertion :
                          Time  Complexity : O(n)
                          Space Complexity : O(1)
             .Deletion   :
                          Time  Complexity : O(n)
                          Space Complexity : O(1)
*/

#include<iostream>

using namespace std;

struct DLLNode{
    int data;
    struct DLLNode *pre;
    struct DLLNode *next;
};

//Function for creating Doubly Linked List
void create_DLL(struct DLLNode **start){
     struct DLLNode *newnode = nullptr,*temp=nullptr;
     int enter;
     cout<<"Enter 1 for adding node in DLL(Doubly Linked List) or else 0\n";
     cin>>enter;
     while(enter){
        newnode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
        if(!newnode){
            cout<<"Memory not available for new node \n";
            return;
        }
        else{
            cout<<"Enter data for the newnode\n";
            cin>>newnode->data;
            newnode->pre = nullptr;
            newnode->next = nullptr;

            if((*start)==nullptr){
                *start = temp = newnode;
            }
            else{
                temp->next = newnode;
                newnode->pre = temp;
                temp = newnode;
            }
        }
        cout<<"Enter 1 for adding new node in DLL(Doubly Linked List) or else 0\n";
        cin>>enter;
     }
}


//Function for Traversing a Doubly Linked List
void traverse_DLL(struct DLLNode *temp){
     cout<<"Doubly Linked List is : \n";
     while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
     }
     cout<<endl;
}


//Function for inserting a node into DLL at desired position
void insert_DLLNode(struct DLLNode **start,int data,int position){
     int k=1;
     struct DLLNode *newnode = nullptr,*p=nullptr,*q=nullptr;
     newnode = (struct DLLNode*)malloc(sizeof(struct DLLNode));

     if(!newnode){
        cout<<"Memory is not available \n";
        return;
     }

     newnode->data = data;
     newnode->pre = nullptr;
     newnode->next = nullptr;

     p = *start;
     if(position==1){
         newnode->next = p;
         *start = newnode;
         return;
     }


     while((k<position-1) && (p->next!=nullptr)){
            k++;
            p = p->next;
    }

    if(k!=position-1){
        cout<<"Desired position does not exist \n";
        return;
    }
    newnode->next = p->next;
    p->next = newnode;
    newnode->pre = p;

    if(p->next){
        p->next->pre = newnode;
    }

}


//Function for Deleting a node from DLL at given Location
void delete_DLLNode(struct DLLNode **start,int position){

     int k=1;
     struct DLLNode *p;
     if((*start)==nullptr){             //condition when DLL was empty so we can't delete.
        cout<<"Given DLL is empty \n";
        return;
     }

     p = *start;
     if(position==1){                   //condition to delete node from 1 position

        *start = (*start)->next;

        if(*start)                      //if your list contain only one element then we need to check before updating pre pointer
            (*start)->pre = nullptr;
        free(p);
        return;
    }

    while((k<position) && (p->next!=nullptr)){
        k++;
        p = p->next;
    }

    if(k!=position){
        cout<<"Position does not exist \n";
        return;
    }

    p->pre->next = p->next;
    if(p->next){                 //checking that if next node of pointer p is not null
        p->next->pre = p->pre;   // because here we are using pre pointer of the next pointer of p
    }
    free(p);
}


//Main Function of the Program
int main(){
    struct DLLNode *start = nullptr;
    
  //Function call for creating a Doubly Linked List
    create_DLL(&start);

    //Function call for Traversing the Doubly Linked List
    traverse_DLL(start);

    //Function call for Inserting a node into the DLL
    int data,position;
    cout<<"Enter the data to be inserted \n";
    cin>>data;
    cout<<"Enter the position to be inserted \n";
    cin>>position;
    insert_DLLNode(&start,data,position);
    traverse_DLL(start); //seeing the DLL after inserting the node at the desired position

    //Function call for Deleting a node from DLL
    cout<<"Enter the position to be delete \n";
    cin>>position;
    delete_DLLNode(&start,position);
    traverse_DLL(start); //Seeing the DLL after deleting a node at desired position
    
  return 0;
}

