// C++ program for different tree traversals

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	//  deal with the node
	cout << node->data << " ";
}


void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/*  recur on left child */
	printInorder(node->left);

	/* print the data of node */
	cout << node->data << " ";

	/*  recur on right child */
	printInorder(node->right);
}

void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/*  print data of node */
	cout << node->data << " ";

	/* recur on left subtree */
	printPreorder(node->left);

	/* recur on right subtree */
	printPreorder(node->right);
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
