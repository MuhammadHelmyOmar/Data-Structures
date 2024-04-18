#include <iostream>
#include <string>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;

class stackArray{
    private:
        int A[MAX_SIZE];
        int top=-1;
    public:
        void push(int data){
            if(top==MAX_SIZE-1){
                cout<<"Error: Stack Overflow\n";
                return;
            }
            A[++top]=data;
        }
        void pop(){
            if(top==-1){
                cout<<"Erro: no element to pop\n";
                return;
            }
            top--;
        }
        int Top(){
            return A[top];
        }
        void display(){
            for(int i=0;i<=top;i++){
                cout<<A[i]<<" ";
            }
            cout<<"\n";
        }
};