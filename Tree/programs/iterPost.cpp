// A C++ program for iterative postorder traversal using
// stack
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;)
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

// An iterative function to do postorder traversal
// of a given binary tree
vector<int> postOrder(Node* node)
{
	stack<Node*> s;

	// vector to store the postorder traversal
	vector<int> post;

	// Using unordered map as hash table for hashing to mark
	// the visited nodes
	unordered_map<Node*, int> vis;

	// push the root node in the stack to traverse the tree
	s.push(node);

	// stack will be empty when traversal is completed
	while (!s.empty()) {

		// mark the node on the top of stack as visited
		vis[s.top()] = 1;

		// if left child of the top node is not NULL and not
		// visited push it into the stack
		if (s.top()->left != 0) {
			if (!vis[s.top()->left]) {
				s.push(s.top()->left);
				continue;
			}
		}

		// Otherwise if the right child of the top node is
		// not NULL and not visited push it into the stack
		if (s.top()->right != 0) {
			if (!vis[s.top()->right]) {
				s.push(s.top()->right);
				continue;
			}
		}

		// Add the value of the top node in our postorder
		// traversal answer if none of the above two
		// conditions are met
		post.push_back(s.top()->data);

		// Remove the top node from the stack
		s.pop();
	}

	// post will now contain the postorder traversal of the
	// tree
	return post;
}

int main()
{
	// Constructing the tree as shown in above diagram
	string s = "1 2 3 4 5 6 7";
	Node* root = buildTree(s);

	vector<int> ans;

	ans = postOrder(root);

	cout << "Post order traversal of binary tree is :\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}

// This code is contributed by Ishan Khandelwal
