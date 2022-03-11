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

int SearchNode(Node *head,int data){//iterative
    int pos = 1;
    Node *curr = head;
    while(curr!=NULL){
        if(curr->data==data){
            return pos;
        }
        pos++;
        curr=curr->next;
    }
    return -1;
}

int SearchNodeR(Node *head,int data){//recursive
    if(head==NULL)return -1;
    if(head->data==data)return 1;
    else {
        int res=SearchNode(head->next,data);
        if (res==-1)return -1;
        return res+1;
    }
    // return SearchNode(head->next,data)+1;one liner giving 0 for not present 
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout<<SearchNodeR(head,10);
}