// C++ program to print paths with maximum
// element in the path greater than K

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return (newNode);
}

// A recursive function to print the paths
// whose maximum element is greater than
// or equal to K.
void findPathUtil(Node* root, int k,
				vector<int> path,
				int flag, int& ans)
{
	if (root == NULL)
		return;

	// If the current node value is greater than
	// or equal to k, then all the subtrees
	// following that node will get printed,
	// flag = 1 indicates to print the required path
	if (root->data >= k)
		flag = 1;

	// If the leaf node is encountered, then the path is
	// printed if the size of the path vector is
	// greater than 0
	if (root->left == NULL && root->right == NULL) {
		if (flag == 1) {
			ans = 1;
			cout << "(";
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] << ", ";
			}
			cout << root->data << "), ";
		}
		return;
	}

	// Append the node to the path vector
	path.push_back(root->data);

	// Recur left and right subtrees
	findPathUtil(root->left, k, path, flag, ans);
	findPathUtil(root->right, k, path, flag, ans);

	// Backtracking to return the vector
	// and print the path if the flag is 1
	path.pop_back();
}

// Function to initialize the variables
// and call the utility function to print
// the paths with maximum values greater than
// or equal to K
void findPath(Node* root, int k)
{
	// Initialize flag
	int flag = 0;

	// ans is used to check empty condition
	int ans = 0;

	vector<int> v;

	// Call function that print path
	findPathUtil(root, k, v, flag, ans);

	// If the path doesn't exist
	if (ans == 0)
		cout << "-1";
}

// Driver code
int main(void)
{
	int K = 25;

	/* Constructing the following tree:
				10
			/ \
			5	 8
		/ \ / \
		29 2 1 98
		/			 \	
		20			 50
*/

	struct Node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(29);
	root->left->right = newNode(2);
	root->right->right = newNode(98);
	root->right->left = newNode(1);
	root->right->right->right = newNode(50);
	root->left->left->left = newNode(20);

	findPath(root, K);

	return 0;
}
