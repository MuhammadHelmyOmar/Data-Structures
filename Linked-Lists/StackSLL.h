#include <iostream>
#include <string>
#include <algorithm>
#include "SLL.h"
using namespace std;

class stackSLL{
    private:
        SLLNode *top;
    public:
        //Constructor
        stackSLL(){
            top=NULL;
        }
        //Emptiness Check
        bool isEmpty(){
            return top==NULL;
        }

        //Operations
        void push(int data){
            SLLNode *newNode=new SLLNode(data);
            newNode->next=top;
            top=newNode;
        }
        void pop(){
            SLLNode *temp;
            if(top==NULL)return;
            else{
                temp=top;
                top=top->next;
                free(temp);
            }
        }
        void display(){
            SLLNode *temp;
            if(isEmpty()){
                cout<<"Empty Stack\n";
            }
            else{
                temp=top;
                while (temp!=NULL)
                {
                    cout<<temp->info<<' ';
                    temp=temp->next;
                }
            }
            cout<<'\n';
        }
};