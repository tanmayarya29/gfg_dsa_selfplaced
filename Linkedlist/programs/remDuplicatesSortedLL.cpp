#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

//remove duplicates from sorted linked list
Node * remDuplicatesSortedLL(Node *head){
    if(head==NULL||head->next==NULL)return head;
    Node *curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(20);
    head=remDuplicatesSortedLL(head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}