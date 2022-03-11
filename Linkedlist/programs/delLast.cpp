#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void PrintList(Node * head){
    if (head == NULL)return ;
    cout<<head->data;
    PrintList(head->next);
}

Node* delLast(Node* head){
    if(head == NULL)return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}

int main(){
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head=delLast(head);
    PrintList(head);
}