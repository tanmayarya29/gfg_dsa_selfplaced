#include <bits/stdc++.h>
using namespace std;
/*
Application of Stack
1. Function calls
2. Checking balanced parenthesis
3. Reversing
4. Infix to prefix/postfix
5. Evaluating postfix/prefix
6. Stack span problem and its variations
7. Undo/Redo or Forward/Backward
*/

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

struct MyStack{
    Node *head;
    int sz;
    MyStack(){
        head=NULL;
        sz=0;
    }
    
    void push(int x){
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    
    int pop(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete(temp);
        sz--;
        return res;
    }
    
    int peek(){
        if(head==NULL){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        return head->data;
    }
    
    int size(){
        return sz;
    }
    
    bool isEmpty(){
        return head==NULL;
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}
