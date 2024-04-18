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
}SinglyLinkedListNode;

typedef class SLL{
    protected:
        SLLNode *head;
    public:
        //Constructor
        SLL(){
            head=NULL;
        }
        //Emptiness Check
        bool isEmpty(){
            return head==NULL;
        }
        //Size
        int size(){
            if(isEmpty()){
                return 0;
            }
            else{
                int i;
                SLLNode *temp=head;
                for(i=0;temp!=NULL;i++){temp=temp->next;}
                return i;
            }
        }

        //Operations
        void deleteNode(int position){
            SLLNode *current=head; //For Deletion
            if(isEmpty()){
                cout<<"Error: The list is already empty\n";
            }
            else if((position+1)>size()){
                cout<<"Error: Out of index deletion\n";
            }
            else if(size()==1){
                delete(current);
                head=NULL;
            } // For 1 element list
            else if(position==0){
                head=head->next;
                delete(current);
            } // Deletes head
            else{
                SLLNode *temp=head; //For Traversing
                for(int i=0;i<(position-1);i++){
                    temp=temp->next;
                }
                current=temp->next;
                temp->next=current->next;
                delete(current);
                }
            } 
            void display(){
                SLLNode* temp=head;
                if(isEmpty()){
                    cout<<"Empty List\n";
                }
                else{
                    temp=head;
                    while (temp!=NULL){
                        cout<<temp->info<<' ';
                        temp=temp->next;
                    }
                }
                cout<<'\n';
            }
}SinglyLinkedList;

/*
****TSortedList****
*/

class TSortedList: public SLL{
    public:
        //Operations
        void insert(int data){
            SLLNode *newNode=new SLLNode(data);
            if(isEmpty()){
                head=newNode;
                return;
            }
            SLLNode *temp=head;
            while(temp->next!=NULL){
                if((head->info)>(newNode->info)){
                    newNode->next=head;
                    head=newNode;
                    return;
                }
                else if((temp->next->info)>(newNode->info)){
                    newNode->next=temp->next;
                    temp->next=newNode;
                    return;
                }
                else{
                    temp=temp->next;
                }
            }
            temp->next=newNode;
        }
};