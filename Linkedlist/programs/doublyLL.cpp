#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;

}