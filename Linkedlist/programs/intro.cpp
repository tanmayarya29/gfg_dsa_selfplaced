#include<bits/stdc++.h>
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


int main(){
    //lengthy implementation
    // Node  *head = new Node(10);
    // Node  *temp1 = new Node(20);
    // Node  *temp2 = new Node(30);

    // head->next = temp1;
    // temp1->next = temp2;
    // temp2->next = NULL;

    //short implementation
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    

}