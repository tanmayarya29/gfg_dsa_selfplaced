/** tree data structure
 * 1. node - each component of the tree
 * 2. root - the root of the tree
 * 3. leaf - a node with no children or degree 0
 * 4. child - a node with a parent
 * 5. parent - a node with a child
 * 6. sibling - nodes at the same level
 * 7. ancestor - all nodes above a node
 * 8. descendant - subtree with the node as root
 * 9. degree - the number of children a node has
 * 10. Internal node - a node with degree > 0
 */

/** Application of tree data structure
 * 1. To represent hierarchical data
 *     a. Organizational structure
 *     b. Folder structure
 *     c. html/xml/json
 *     d. OOPs inheritance
 * 2. Binary Search Tree
 * 3. Binary Heap or Priority Queue
 * 4. B and B+ Tree in DBMS
 * 5. Spanning and Shortest Path Tree in Computer Network
 * 6. Parse Tree and Expression Tree in Compilers
 * 7. Trie - used to search words in a dictionary or prefix search
 * 8. Suffix Tree - used to fast search in a string
 * 9. Binary Indexed Tree - used for range query search
 * 10. Segment Tree - used for range query search
 */

//Binary tree - each node has at most 2 children
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};
    
int main() {
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
}
