#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};

Node * InsertEnd(Node * head, int data){
    Node *end = new Node(data);
    if (head==NULL){
        return end;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next = end;
    return head;
}

void PrintListRec(Node *head){//recursive
    if(head==NULL)return;
    cout<<head->data<<" ";
    PrintListRec(head->next);
}

int main(){
    Node *head = new Node(10);
    head=InsertEnd(head,20);
    PrintListRec(head);
}