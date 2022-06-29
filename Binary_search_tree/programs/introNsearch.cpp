#include<iostream>
using namespace std;

/*
Binary search tree
1. For every node, keys in left side are smaller and keys on right are greater
2. All keys are typically kept distict
3. Like, linked list, it is a lined data structure
4. implemented in c++ as map, set, multimap, multiset
*/

struct node
{
    int key;
    node *left,*right;
    node(int x){
        key=x;
        left=right=NULL;
    }
};
//recursive search
bool searchR(node *bst,int key){
    if(bst==NULL)return 0;
    else if(bst->key==key)return 1;
    else if(bst->key>key)searchR(bst->left,key);
    else searchR(bst->right,key);
}

//iterative search
bool searchI(node *bst,int key){
    while(bst!=NULL){
        if(bst->key==key)return 1;
        else if(bst->key>key)bst=bst->left;
        else bst=bst->right;
    }
    return 0;
}
int main(){
    node *root=new node(15);
	root->left=new node(5);
	root->left->left=new node(3);
	root->right=new node(20);
	root->right->left=new node(18);
	root->right->left->left=new node(16);
	root->right->right=new node(80);
	int x=16;
	
	if(searchR(root,x) && searchI(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";
}