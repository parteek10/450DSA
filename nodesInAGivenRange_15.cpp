// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Helper function to create new nodes 
struct Node *CreateNode(int key)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// function to insert in the BST 
struct Node *insertBST(struct Node *root, int key)
{
    if (root == NULL)
    {
        root = CreateNode(key);
    }
    if (root->data < key)
    {
        root->right = insertBST(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = insertBST(root->left, key);
    }
    return root;
}

int getCount(Node *root, int l, int h)
{
    // your code goes here
    int count = 0;
    // if there will be no nodes the function will return 0

    if (root == NULL)
    {
        return 0;
    }

    // if the node value lies in the range then we'll check for both the possibilities of left and right subtree 
    if (root->data >= l && root->data <= h)
    {
        count = 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }

    // a edge case where the node value is less than the low so then we'll jump to right of it 
    if (root->data < l)
    {
        count = getCount(root->right, l, h);
    }

    // a edge case where node value is greater than the upper limit so then we'll not consider the right but only leftpart is considerd
    if (root->data > h)
    {
        count = getCount(root->left, l, h);
    }
    return count;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low, high;
    cin >> low >> high;
    struct Node *root = CreateNode(arr[0]);
    for (int i = 1; i < n; i++)
    {
        root = insertBST(root, arr[i]);
    }
    cout << getCount(root, low, high);
}
