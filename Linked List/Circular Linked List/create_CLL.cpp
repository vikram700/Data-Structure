/*
    Author : Vikram Singh
    About  : This program create circular linked list,traverse CLL(Circular Linked List),insert at begin in CLL,
             insert at end in CLL,delete from begin of the CLL and delete from the end of the CLL.

    Functions : This specify the functions that are present into the given program with efficient complexity.
               .create_CLL()
               .traverse_CLL(): Time Complexity -->O(n) and Space Complexity-->O(1)
                                traverse function also count the no of element present into
                                the CLL with same complexities as given above.
               .insertNodeAtEnd()   : Time Complexity -->O(n) and Space Complexity -->O(1)
               .insertNodeAtBegin() : Time Complexity -->O(n) and Space Complexity -->O(1)
               .deleteNodeAtEnd()   : Time Complexity -->O(n) and Space Complexity -->O(1)
               .deleteNodeAtBegin() : Time Complexity -->O(n) and Space Complexity -->O(1)

    Note:-- This program is tested on " Code::Blocks 17.12 " ID.
*/

#include<iostream>

using namespace std;

int count_node = 0; //this is used in traverse function to count the no of node in CLL

struct CLLNode{
   int data;
   struct CLLNode *next;
};


//Creating a Circular Linked List
void create_CLL(struct CLLNode **start){

     struct CLLNode *temp,*newnode;
     int enter;
     cout<<"Enter 1 for adding new node in CLL or 0 for note \n";
     cin>>enter;
     while(enter){
        newnode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
        if(!newnode){
            cout<<"Space not empty \n";
            return;
        }
        cout<<"Enter the data for newnode \n";
        cin>>newnode->data;
        newnode->next = nullptr;

        if((*start)==nullptr){
            *start = temp = newnode;
            temp->next = *start;
        }
        else{
            temp->next = newnode;
            temp = newnode;
            temp->next = *start;
        }
        cout<<"Enter 1 for adding new node in CLL or 0 for not \n";
        cin>>enter;

     }
}


//Traversing the CLL and also count the no of element into the CLL
void traverse_CLL(struct CLLNode *start){
     count_node = 0;
     struct CLLNode *current = start;
     if(current==nullptr){
        cout<<"CLL is empty \n";
        return;
     }
     cout<<"The CLL is : \n";
     do{
        cout<<current->data<<" ";
        current = current->next;
        count_node++;
     }while(current!=start);
     cout<<endl;
}


//Insert node at the end of the CLL
void insertNodeAtEnd(struct CLLNode **start,int data){
     struct CLLNode *newnode = nullptr,*current=*start;
     newnode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
     if(!newnode){
        cout<<"Space is not empty \n";
        return;
     }

     newnode->data = data;
     newnode->next = newnode;

     if(*start == nullptr){
        *start = newnode;
     }
     else{
        while(current->next!=*start){
            current = current->next;
        }

        current->next = newnode;
        newnode->next = *start;
     }
}


//Inserting node at the begin of the CLL
void insertNodeAtBegin(struct CLLNode **start,int data){
     struct CLLNode *newnode = nullptr,*current = *start;
     newnode = (struct CLLNode*)malloc(sizeof(struct CLLNode));

     if(!newnode){
        cout<<"Space is not empty \n";
        return;
     }

     newnode->data = data;
     newnode->next = newnode;

     while(current->next!=*start){
        current = current->next;
     }

     if(*start==nullptr){
        *start = newnode;
     }
     else{
        newnode->next = *start;
        current->next = newnode;
        *start = newnode;
     }
}


//Deleting the last node from the CLL
void deleteNodeAtEnd(struct CLLNode **start){
     struct CLLNode *p=nullptr,*q=nullptr;

     if(*start==nullptr){
        cout<<"CLL is empty \n";
        return;
     }
     p = *start;
     if((*start)->next == *start){
        free(p);
        *start = nullptr;
     }
     else{
        while(p->next!=*start){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
     }
}


//Deleting the first node from the CLL
void deleteNodeAtBegin(struct CLLNode **start){
     struct CLLNode *temp=nullptr,*p=nullptr;
     if(*start == nullptr){
        cout<<"CLL is empty \n";
        return;
     }
     p = *start;
     if((*start)->next ==*start){
        free(p);
        *start = nullptr;
     }
     else{
        while(p->next!=*start){
            p = p->next;
        }

        temp = *start;
        *start = (*start)->next;
        p->next = *start;

        free(temp);
     }

}


//Main Function
int main(){
    struct CLLNode *start = nullptr;
    //Creating a Circular Linked List
    create_CLL(&start);

    //Traversing the CLL
    traverse_CLL(start);
    cout<<"No of element into the CLL is : "<<count_node<<endl;

    //Inserting node at the end of the CLL
    int data;
    cout<<"Enter data to be inserted at the end \n";
    cin>>data;
    insertNodeAtEnd(&start,data);
    traverse_CLL(start);
    cout<<"No of element into the CLL is : "<<count_node<<endl;

    //Inserting node at the begin of the CLL
    cout<<"Enter data to be inserted at the begin \n";
    cin>>data;
    insertNodeAtBegin(&start,data);
    traverse_CLL(start);
    cout<<"No of element into the CLL is :"<<count_node<<endl;

    //Deleting the last node from the CLL
    cout<<"Print the CLL after deleting node from last \n";
    deleteNodeAtEnd(&start);
    traverse_CLL(start);
    cout<<"No of element into the CLL is :"<<count_node<<endl;

    //Deleting the first node from the CLL
    cout<<"Print the CLL after deleting node from beginning \n";
    deleteNodeAtBegin(&start);
    traverse_CLL(start);
    cout<<"No of element into the CLL is :"<<count_node<<endl;

    return 0;
}

