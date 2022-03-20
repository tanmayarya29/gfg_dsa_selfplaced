#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

Node * sortedInsert(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        return temp;
    }
    if(head->data>x){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL && curr->next->data<x){
        curr=curr->next;
    }
    temp->next=curr->next;//c-y(y<x)||c-x-y
    curr->next=temp;
    return head;
}



int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    head=sortedInsert(head,5);
    head=sortedInsert(head,21);
    head=sortedInsert(head,51);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}