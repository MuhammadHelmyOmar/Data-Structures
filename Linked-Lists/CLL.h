#include <iostream>
#include <string>
#include <algorithm> 
#include "SLL.h"
#include "DLL.h"
using namespace std;

/* Circular Singly Linked List

Consists of:-
2- Nodes: info(Data)+next(pointer)
3- Tail(pointer)

NOTE 1: The next of the last node of the circular singly linked list points to the first node.

*/

typedef class CSLL{
    private:
        SLLNode *tail;
    public:
        //Constructor
        CSLL(){
            tail=NULL;
        }
        //Emptiness Check
        bool isEmpty(){
            return tail==NULL;
        }

        //Inserts
        void insertAtHead(int data){
            SLLNode *newNode=new SLLNode(data);
            if(isEmpty()){
                tail=newNode;
                tail->next=tail;
                return;
            }
            else{
                newNode->next=tail->next;
                tail->next=newNode;
                return;
            }
        }
        void insertAtTail(int data){
            SLLNode *newNode=new SLLNode(data);
            if(isEmpty()){
                tail=newNode;
                tail->next=tail;
                return;
            }
            else{
                newNode->next=tail->next;
                tail->next=newNode;
                tail=tail->next;
                return;
            }
        }

        //Display
        void display(){
            if(isEmpty()){
                cout<<"Empty List";
            }
            else{
                SLLNode *temp=tail->next;
                do{
                    cout<<temp->info<<" ";
                    temp=temp->next;
                }
                while (temp!=tail->next);
            }
        }

}CircularSinglyLinkedList;

/* Circular Doubly Linked List

Consists of:-
2- Nodes: info(Data)+next(pointer)+prev(pointer)
3- Tail(pointer)

NOTE 1: The prev of the first node of a circular doubly linked list points to the last node
        and the next of the last node points to the first node.

*/

typedef class CDLL{
    private:
        DLLNode *tail;
    public:
        //Constructor
        CDLL(){
            tail=NULL;
        }
        //Emptiness Check
        bool isEmpty(){
            return tail==NULL;
        }

        //Inserts
        void insertAtHead(int data){
            DLLNode *newNode=new DLLNode(data);
            if(isEmpty()){
                tail=newNode;
                tail->next=tail;
                tail->prev=tail;
                return;
            }
            else{
                DLLNode *current=tail->next;
                newNode->next=current;
                newNode->prev=tail;
                current->prev=newNode;
                tail->next=newNode;
                return;
            }
        }
        //Display
        void display(){
            if(isEmpty()){
                cout<<"Empty List\n";
            }
            else{
                DLLNode *temp=tail->next;
                do{
                    cout<<temp->info<<" ";
                    temp=temp->next;
                }while(temp!=tail->next);
            }
        }
}CircularDoublyLinkedList;