#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

typedef struct DLLNode{
    int info;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(){
        this->info=0;
        this->next=NULL;
        this->prev=NULL;
    }
    DLLNode(int data){
        this->info=data;
        this->next=NULL;
        this->prev=NULL;
    }
} DoublyLinkedListNode;

/* Doubly Linked List

Consists of:-
1- Head(pointer)
2- Nodes: info(Data)+next(pointer)+prev(pointer)
3- Tail(pointer)

NOTE 1: Head is the identity of the linked list.

*/

typedef class DLL{
    private:
        DLLNode *head;
        DLLNode *tail;
    public:
        //Constructor
        DLL(){
            head=tail=NULL;
        }
        //Getters
        DLLNode *getHead(){
            return head;
        }
        //Emptiness Check
        bool isEmpty(){
            return head==NULL;
        }

        //Inserts
        void insertAtHead(int data);
        void insertAtTail(int data);
        //Display
        void display();
        void displayReversed();
        // Remove
        void deleteTail();

}DoublyLinkedList;

/* Definitions */

//Inserts
void DLL::insertAtHead(int data){
    DLLNode *newNode=new DLLNode(data);
    if(isEmpty()){
        head=tail=newNode;
        return;
    }
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}
void DLL::insertAtTail(int data){
    DLLNode *newNode=new DLLNode(data);
    if(isEmpty()){
        head=tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }
}

//Display
void DLL::display(){
    DLLNode *temp=head;
    if(isEmpty()){
        cout<<"The List is Empty\n";
        return;
    }
    else{
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->next;
        }
    }
    cout<<"\n";
}
void DLL::displayReversed(){
    DLLNode *temp=tail;
    if(isEmpty()){
        cout<<"The list is Empty\n";
        return;
    }
    else{
        while (temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->prev;
        }
    }
    cout<<"\n";
}

//Remove
void DLL::deleteTail(){
    DLLNode *current=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete(current);
}