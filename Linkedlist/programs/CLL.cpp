#include <bits/stdc++.h> 
using namespace std; 
/*
advantages
1. Traverse head from any node
2. Round robin is implemented
3. We can insert/del in beg and end by just maintaining one tail reference/pointer
disadvantages
1. implementation of operations become complex
*/
struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	return 0;
} 
