#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

void printMiddleNaive(Node * head){
    if(head==NULL)return;
    int count=0;
    Node *curr;
    for(curr=head;curr!=NULL;curr=curr->next)
        count++;
    curr=head;
    for(int i=0;i<count/2;i++)
        curr=curr->next;
    cout<<curr->data;
}

void printMiddle(Node * head){
    if(head==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<"Middle of Linked List: ";
	printMiddle(head);
	return 0;
} 
