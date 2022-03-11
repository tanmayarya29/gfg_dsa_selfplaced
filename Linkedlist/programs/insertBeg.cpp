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

Node * InsertBeg(Node * head, int data){
    Node *newHead = new Node(data);
    newHead->next = head;
    return newHead;
}

void PrintListRec(Node *head){//recursive
    if(head==NULL)return;
    cout<<head->data<<" ";
    PrintListRec(head->next);
}

int main(){
    Node *head = new Node(10);
    head=InsertBeg(head,20);
    PrintListRec(head);
}