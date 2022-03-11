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

Node* insertAtPos(Node *head,int pos,int data){
    if(pos==1){
        Node *temp = new Node(data);
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=1;i<=pos-2 && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL){
        return head;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;//order is important 1st line
    curr->next = temp;//2nd line
    return head;
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
    head=insertAtPos(head,2,40);
    PrintListRec(head);
}