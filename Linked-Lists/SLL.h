#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

typedef struct SLLNode{
    int info;
    SLLNode *next;
    SLLNode(int data){
        this->info=data;
        this->next=NULL;
    }
} SinglyLinkedListNode;

/* Singly Linked List

Consists of:-
1- Head(pointer)
2- Nodes: info(Data)+next(pointer)
3- Tail(pointer)

NOTE 1: Head is the identity of the linked list.

*/

typedef class SLL{
    private:
        SLLNode *head;
        SLLNode *tail;
        SLLNode *temp; // Used to traverse the list
    public:
        // Constructor
        SLL(){
            head=tail=NULL;
        }
        // Getters
        SLLNode *getHead(){
            return head;
        }
        // Emptiness Check
        bool isEmpty(){
            return head==NULL;
        }
        
        // Inserts
        void insertAtHead(int data);
        void insertAtTail(int data);
        void insert(int data,int position);
        // Display
        void display();
        void displayReversed(SLLNode *h);
        // Size
        int size();
        // Remove
        void deleteNode(int position);
        // Reverse
        void reverse();
        // Searches
        int find(int data);
} SinglyLinkedList;

/* Definitions */

// Inserts
void SLL::insertAtHead(int data){
    SLLNode *newNode=new SLLNode(data);
    if(isEmpty()){
        head=tail=newNode;
        return;
    }
    else{
        newNode->next=head;
        head=newNode;
        return;
    }
}
void SLL::insertAtTail(int data){
    SLLNode *newNode=new SLLNode(data);
    if(isEmpty()){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
void SLL::insert(int position,int data){
    SLLNode *newNode=new SLLNode(data);
    if(position>size()){
        cout<<"Out of index insertion\n";
    }
    else if (position==0)
    {
        insertAtHead(data);
    }
    else if((position+1)==size())
    {
        insertAtTail(data);
    }
    else
    {
        temp=head;
        for(int i=0;i<(position-1);i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }  
}

// Display
void SLL::display(){
    if(isEmpty()){
        cout<<"Empty List";
    }
    else
    {
        temp=head;
        while (temp!=NULL)
        {
            cout<<temp->info<<' ';
            temp=temp->next;
        }
    }
    cout<<'\n';
}
void SLL::displayReversed(SLLNode *h){
    if(isEmpty()){
        cout<<"Empty List"<<'\n';
    }
    else if(h==NULL){
        return;
    }
    else{
        displayReversed(h->next);
        cout<<h->info<<' ';  
    }
}

// Size
int SLL::size(){
    if(isEmpty()){
        return 0;
    }
    else
    {
        int i;temp=head;
        for(i=0;temp!=NULL;i++){temp=temp->next;}
        return i;
    }
}

// Remove
void SLL::deleteNode(int position){
    SLLNode *current=head; //For Deletion
    if(isEmpty()){
        cout<<"The list is already empty\n";
    }
    else if((position+1)>size()){
        cout<<"Out of index deletion\n";
    }
    else if(size()==1)
    {
        delete(current);
        head=tail=NULL;
    } // For 1 element list
    else if(position==0)
    {
        head=head->next;
        delete(current);
    } // Deletes head
    else
    {
        SLLNode *temp=head; //For Traversing
        for(int i=0;i<(position-1);i++)
        {
            temp=temp->next;
        }
        if((position+1)==size()){
            current=tail;
            tail=temp;
            temp->next=NULL;
            delete(current);
        } // Deletes tail
        else{
            current=temp->next;
            temp->next=current->next;
            delete(current);
        }
    }  
}

// Reverse
void SLL::reverse(){
    if(isEmpty()){
        cout<<"The list is already empty\n";
    }
    else if(size()>1)
    {
        tail=head;
        temp=head;
        SLLNode *prev=NULL;
        SLLNode *after;
        while (temp!=NULL)
        {
            after=temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        head=prev;  
    }
}

// Searches
int SLL::find(int data){
    temp=head;
    for(int i=0;temp!=NULL;i++){
        if(temp->info==data){
            cout<<i<<'\n';
            return i;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<data<<" does not exist\n";
    return -1;
}