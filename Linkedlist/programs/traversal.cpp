#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;//self-referential structure
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void PrintList(Node *head){//iterative
//in cpp we can skip curr as head of main and head of printList are different variable pointing to same node
    Node* curr=head;
    if(curr==NULL) return;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
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
    
    PrintList(head);
    PrintListRec(head);
}