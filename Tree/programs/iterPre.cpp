#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

void preorderIterative(Node* root)
{
	if (root == NULL)
		return;
	stack<Node*> st;
    st.push(root);
	while (!st.empty()) {
        Node* temp = st.top();
        cout << temp->data << " ";
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
	}
}

void preorderIterative2(Node* root)//space optimized O(h)
{
    if (root == NULL)
        return;
    stack<Node*> st;
    Node* temp = root;
    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            cout << temp->data << " ";
            if (temp->right)
                st.push(temp->right);
            temp = temp->left;
        }
        if (!st.empty()) {
            temp = st.top();
            st.pop();
        }
    }
}
   

// Driver Code
int main()
{
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->left->left = new Node(70);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->left->left->right = new Node(80);

	preorderIterative(root);

	return 0;
}
