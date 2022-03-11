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

Node * DelFirst(Node * head){
    if (head==NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;
}

void PrintListRec(Node *head){//recursive
    if(head==NULL)return;
    cout<<head->data<<" ";
    PrintListRec(head->next);
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head=DelFirst(head);
    PrintListRec(head);
}